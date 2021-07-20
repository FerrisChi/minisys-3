`timescale 1ns / 1ps
//该单元的工作
//1、取指令
//2、计算pc
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2014/10/22 14:48:50
// Design Name: 
// Module Name: Ifect32
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 11/9修改版
//////////////////////////////////////////////////////////////////////////////////
module Ifect32(
    Instrution,
    PC_plus_4_out,
    Add_result,
    read_data_1,
    nBranch,
    Branch,
    bgez,
    bgtz,
    blez,
    bltz,
    bgezal, 
    bltzal,
    Jmp,
    Jal,
    Jrn,
    Zero,
    EtZero,
    GtZero,
    LtZero,
    PC_out,
    clock,
    reset,
    opcplus4,
    Jalr,
    int0,int1,imask,intPC,read_register_1_address
    );
    
    output[31:0]  Instrution;     //32位指令输出供查验
    output[16:0]  PC_plus_4_out;  //PC+4输出，送执行单元
    output[16:0]  PC_out;    //PC值输出验证的时候使用
    output[16:0]  opcplus4;  //pc+4(送到31号寄存器) 
    
    input[16:0]  Add_result;     //beq bne 等指令的跳转地址
    input[31:0]  read_data_1;    //jr,jalr指令  pc<=rs；
    
    input    nBranch;     //来自控制单元
    input    Branch;
    input    bgez;
    input    bgtz;
    input    blez;
    input    bltz;
    input    bgezal; 
    input    bltzal;
    
    input    Jmp;
    input    Jal;
    input    Jrn;
    input    Jalr; 
    
    input    Zero;      //以下几个来自执行单元
    input    EtZero;    //$1与0大小关系判断的结果
    input    GtZero;
    input    LtZero;   
    
    input    clock;
    input    reset;
    
    //中断相关
    input int0,int1;						//CPU增加的从外设中过来的两个中断
    output[1:0]   imask;                    //输出到译码单元的中断屏蔽寄存器imaskR的值,低两位R[1]为1，屏蔽INT1，R[0]为1，屏蔽INT0；
    output[16:0]  intPC;                    //给译码单元的中断返回地址
    input[4:0]     read_register_1_address;    //从译码单元来的jr指令的寄存器号
    
    //中间线
    wire[18:0] PC_plus_4;    //用来算PC+4的
    reg[16:0] opcplus4; //Jal,jalr,bgezal,bltzal专用PC+4
    reg[16:0] next_PC; //下一条指令PC，并非最终传到程序计数器的值
    reg[18:0] PC;    //初始化的PC
    wire[31:0] Jpadr;  //指令赋值给
    //中断
    assign intPC[16:0]=((Jmp==1)||(Jal==1))?Jpadr[16:0]:next_PC[16:0];//中断返回地址，正常是PC+4(即next_PC),但如果中断的是跳转语句的话，则应该是跳转的目标地址

    //中断相关
    reg[1:0]     imask;					//中断屏蔽寄存器
    reg         rubbish;                 //错误端口号的data处理
  
    //ROM例化
     program Rom(
            .clka(clock),            // input wire clka
            .addra(PC[16:2]),      // input wire [16 : 2] addra
            .douta(Jpadr[31:0]));        // output wire [31 : 0] douta
        
     assign PC_out=PC[16:0];    //将内部的PC值送到CPU外部输出脚上供验证用
     assign PC_plus_4[1:0]=2'b00;
     assign PC_plus_4[18:2]=PC[18:2]+1;//pc+4      
     assign  PC_plus_4_out=PC_plus_4[16:0];
     assign  Instrution = Jpadr;
         
     always@ (*)
          begin                                                                        
           if(((Branch==1)&&(Zero==1))||((nBranch==1)&&(Zero==0))||
           (((bgez==1)||(bgezal==1))&&((EtZero==1)||(GtZero==1)))||
           ((bgtz==1)&&(GtZero==1))||((blez==1)&&((EtZero==1)||(LtZero==1)))||
           (((bltz==1)||(bltzal==1))&&(LtZero==1)))
                next_PC[16:0]=Add_result[16:0];
           else if(Jrn==1||Jalr==1)
               next_PC=read_data_1[16:0];//JR，Jalr指令转移地址
           else next_PC= PC_plus_4[18:2];       //（为了保证位数一致）才选18位的。
      end
  
     always @ (negedge clock)//PC赋值
     begin 
         if(reset==1)//初始化
          begin
           PC<=19'b0000000000000000000;
           imask=2'b00;
           end
         else if((int0==1)&&(imask[0]==0))					//响应INT0
            begin
             imask[0]=1;
             PC<=18'b000000111111111000;    //    PC的地址跳到0ff8H
            end
         else if((int1==1)&&(imask[1]==0)&&(imask[0]==0))    //响应INT1
             begin
              imask[1]=1;
              PC<=18'b000000111111111100;        //PC的地址跳到0ffcH
            end
         else if((Jmp==1)||(Jal==1))
            begin //JAL指令执行前，要将PC+4保存到$31         
            opcplus4= PC_plus_4[18:2];    //存到31号寄存器
            PC[18:0]={Jpadr[16:0],2'b00};  //顺便完成左移俩位
            end
         else if((bgezal==1)||(bltzal==1)||(Jalr==1))  //bgezal和bltzal也需要暂存到31号寄存器
            begin
            opcplus4= PC_plus_4[18:2];
            PC[18:0]={next_PC[16:0],2'b00};
            end
        else
            PC[18:0]={next_PC[16:0],2'b00};
        if(Jrn==1)			//处理中断返回时屏蔽寄存器的复位
               begin
                if(read_register_1_address==5'b11010)  //$26
                     imask[0]=0;
                 else if(read_register_1_address==5'b11011)  //$27
                      imask[1]=0;
                 else  rubbish=0;
               end
     end  
endmodule
