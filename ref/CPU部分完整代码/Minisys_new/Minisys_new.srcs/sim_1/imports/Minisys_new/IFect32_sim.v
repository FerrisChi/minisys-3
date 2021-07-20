`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2014/11/14 15:53:18
// Design Name: 
// Module Name: IFect32_sim
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
// 
//////////////////////////////////////////////////////////////////////////////////


module IFect32_sim(
    );
       //output
       wire[31:0]  Instrution;     //32位指令输出供查验
       wire[16:0]  PC_plus_4_out;  //PC+4输出，送执行单元
       wire[16:0]  PC_out;    //PC值输出验证的时候使用
       wire[16:0]  opcplus4;  //pc+4(送到31号寄存器) 
       
       //input
       reg[16:0]  Add_result;     //beq bne 等指令的跳转地址
       reg[31:0]  read_data_1=32'b00000000000000000000000000000001; //跳转到第四条;    //jr,jalr指令  pc<=rs；
   
       reg    nBranch=0;     //来自控制单元
       reg    Branch=0;
       reg    bgez=0;
       reg    bgtz=0;
       reg    blez=0;
       reg    bltz=0;
       reg    bgezal=0; 
       reg    bltzal=0;
       
       reg    Jmp=0;
       reg    Jal=0;
       reg    Jrn=0;
       reg    Jalr=0; 
       
       reg    Zero=0;      //以下几个来自执行单元
       reg    EtZero=0;    //$1与0大小关系判断的结果
       reg    GtZero=0;
       reg    LtZero=0;   
       
       reg    clock=1;
       reg    reset=1;
       
       //实例化
       Ifect32 ifetch(
          .Instrution(Instrution),
          .PC_plus_4_out(PC_plus_4_out),
          .Add_result(Add_result),
          .read_data_1(read_data_1),
          .clock(clock),
          .reset(reset),
          .opcplus4(opcplus4),
          .nBranch(nBranch),
          .Branch(Branch),
          .bgez(bgez),
          .bgtz(bgtz),
          .blez(blez),
          .bltz(bltz),
          .bgezal(bgezal), 
          .bltzal(bltzal),
          .Jmp(Jmp),
          .Jal(Jal),
          .Jrn(Jrn),
          .Zero(Zero),
          .EtZero(EtZero),
          .GtZero(GtZero),
          .LtZero(LtZero),
          .PC_out(PC_out),
          .Jalr(Jalr)
        );
        
        //设置输入信号
          initial begin
                #40 reset=1;
                #40 reset =0;
                #40 bgezal=1;
                end
                
          always begin
               #20 clock=~clock;
               end

endmodule
