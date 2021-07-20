`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2014/11/06 17:10:47
// Design Name: 
// Module Name: Idecode32
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
// 11.23修改
/////////////////////////////////////////////////////////////////////////////////

module Idecode32(
    read_data_1,
    read_data_2,
    Instruction,
    read_data,
    ALU_result,
    ALU_result_HI,
    ALU_result_LO,
    Jal,
    Jalr,
    bgezal,
    bltzal,
    mfhi,
    mflo,
    mthi,
    mtlo,
    Lw,
    Lb,
    Lbu,
    Lh,
    Lhu,
    Sw,
    Sb,
    Sh,
    MD,
    RegWrite,
    MemtoReg,
    RegDst,
    Sign_extend,
    clock,
    reset,
    opcplus4,
    write_data_out,
    write_register_address_out,
    int0,int1,imask,intPC,read_register_1_address,  //中断
    registerq_out,
    registerr_out
    );
    output[31:0]    write_data_out;
    output[4:0]     write_register_address_out;
    output[31:0]    read_data_1;
    output[31:0]    read_data_2;
    output[31:0]    Sign_extend;
    input[31:0]     Instruction;
    input[31:0]     read_data;
    input[31:0]     ALU_result;
    input[31:0]     ALU_result_HI;    
    input[31:0]     ALU_result_LO;
    input[16:0]     opcplus4;   //来自取指单元，JAL,Jalr,bgezal,bltzal中用,注意位数
    input   Jal;
    input   Jalr;
    input   bgezal;
    input   bltzal;
    input   mfhi;
    input   mflo;
    input   mtlo;
    input   mthi;
    input   MD;
    input   Lw;
    input   Lb;
    input   Lbu;
    input   Lh;
    input   Lhu;
    input   Sw;
    input   Sb;
    input   Sh;
    input   RegWrite;
    input   MemtoReg;
    input   RegDst;
    input   clock;
    input   reset;
    //中断
    input         int0,int1;				//从外设中过来的2个中断信号
    input[1:0]     imask;                    //从取指单元来的中断屏蔽寄存器的值
    input[16:0]    intPC;                    //从取指单元来的中断返回地址
    output[4:0]    read_register_1_address;    //输出到取指单元的jr指令的寄存器号
    output[31:0]   registerq_out;
    output[31:0]   registerr_out;
    
    reg[31:0] read_data_1;
    reg[31:0] read_data_2;
    
    reg[31:0] register0,register1,register2,register3;
    reg[31:0] register4,register5,register6,register7;
    reg[31:0] register8,register9,registera,registerb;
    reg[31:0] registerc,registerd,registere,registerf;
    reg[31:0] registerg,registerh,registeri,registerj;
    reg[31:0] registerk,registerl,registerm,registern;
    reg[31:0] registero,registerp,registerq,registerr;
    reg[31:0] registers,registert,registeru,registerv;
    reg[31:0] registerHI;
    reg[31:0] registerLO;
   
    //乘除法寄存器添加
    
    reg[4:0] write_register_address;
    reg[31:0] write_data;
    wire[4:0] /*read_register_1_address,*/ read_register_2_address;
    wire[4:0] write_register_address_1, write_register_address_0;
    wire[15:0] Instruction_immedaite_value;
    wire[5:0] opcode;
    wire sign;
    
    //各种信号从指令中分离
    assign opcode = Instruction[31:26];
    assign read_register_1_address = Instruction[25:21];
    assign read_register_2_address = Instruction[20:16];
    assign write_register_address_1 = Instruction[15:11];//rd
    assign write_register_address_0 = Instruction[20:16];//rt
    assign Instruction_immedaite_value = Instruction[15:0];
    assign write_data_out=write_data[31:0];
    assign write_register_address_out=write_register_address[4:0];
    assign registerq_out=registerq;
    assign registerr_out=registerr;
    
    //16位立即数扩展到32位
    assign sign = Instruction_immedaite_value[15];
    assign Sign_extend[31:0] = ((opcode == 6'b001100)||(opcode == 6'b001101)||(opcode == 6'b001110)||(opcode == 6'b001011))?
    {16'h0000,Instruction_immedaite_value[15:0]}:{sign,sign,sign,sign,sign,sign,sign,sign,sign,sign,sign,sign,sign,sign,sign,sign,Instruction_immedaite_value[15:0]};
    
    //寄存器中的数分别读到数据口1和2
    always @ (read_register_1_address)
        begin 
            case(read_register_1_address[4:0])
                5'd0: read_data_1 <= register0;
                5'd1: read_data_1 <= register1;
                5'd2: read_data_1 <= register2;
                5'd3: read_data_1 <= register3;
                5'd4: read_data_1 <= register4;
                5'd5: read_data_1 <= register5;
                5'd6: read_data_1 <= register6;
                5'd7: read_data_1 <= register7;
                5'd8: read_data_1 <= register8;
                5'd9: read_data_1 <= register9;
                5'd10: read_data_1 <= registera;
                5'd11: read_data_1 <= registerb;
                5'd12: read_data_1 <= registerc;
                5'd13: read_data_1 <= registerd;
                5'd14: read_data_1 <= registere;
                5'd15: read_data_1 <= registerf;
                5'd16: read_data_1 <= registerg;
                5'd17: read_data_1 <= registerh;
                5'd18: read_data_1 <= registeri;
                5'd19: read_data_1 <= registerj;
                5'd20: read_data_1 <= registerk;
                5'd21: read_data_1 <= registerl;
                5'd22: read_data_1 <= registerm;
                5'd23: read_data_1 <= registern;
                5'd24: read_data_1 <= registero;
                5'd25: read_data_1 <= registerp;
                5'd26: read_data_1 <= registerq;
                5'd27: read_data_1 <= registerr;
                5'd28: read_data_1 <= registers;
                5'd29: read_data_1 <= registert;
                5'd30: read_data_1 <= registeru;
                5'd31: read_data_1 <= registerv;
                default: read_data_1 <= 32'bx;
             endcase
    end
           
     always @ (read_register_2_address)
     if (Sb==1) //读出去给存储器只要低八位
          begin 
             case(read_register_2_address[4:0])
                 5'd0: read_data_2 ={24'h000000, register0[7:0]};
                 5'd1: read_data_2 ={24'h000000, register1[7:0]};
                 5'd2: read_data_2 ={24'h000000, register2[7:0]};
                 5'd3: read_data_2 ={24'h000000, register3[7:0]};
                 5'd4: read_data_2 ={24'h000000, register4[7:0]};
                 5'd5: read_data_2 ={24'h000000, register5[7:0]};
                 5'd6: read_data_2 ={24'h000000, register6[7:0]};
                 5'd7: read_data_2 ={24'h000000, register7[7:0]};
                 5'd8: read_data_2 ={24'h000000, register8[7:0]};
                 5'd9: read_data_2 ={24'h000000, register9[7:0]};
                 5'd10: read_data_2 ={24'h000000, registera[7:0]};
                 5'd11: read_data_2 = {24'h000000, registerb[7:0]};
                 5'd12: read_data_2 = {24'h000000, registerc[7:0]};
                 5'd13: read_data_2 = {24'h000000, registerd[7:0]};
                 5'd14: read_data_2 = {24'h000000, registere[7:0]};
                 5'd15: read_data_2 = {24'h000000, registerf[7:0]};
                 5'd16: read_data_2 = {24'h000000, registerg[7:0]};
                 5'd17: read_data_2 = {24'h000000, registerh[7:0]};
                 5'd18: read_data_2 = {24'h000000, registeri[7:0]};
                 5'd19: read_data_2 = {24'h000000, registerj[7:0]};
                 5'd20: read_data_2 = {24'h000000, registerk[7:0]};
                 5'd21: read_data_2 = {24'h000000, registerl[7:0]};
                 5'd22: read_data_2 = {24'h000000, registerm[7:0]};
                 5'd23: read_data_2 = {24'h000000, registern[7:0]};
                 5'd24: read_data_2 = {24'h000000, registero[7:0]};
                 5'd25: read_data_2 = {24'h000000, registerp[7:0]};
                 5'd26: read_data_2 = {24'h000000, registerq[7:0]};
                 5'd27: read_data_2 = {24'h000000, registerr[7:0]};
                 5'd28: read_data_2 = {24'h000000, registers[7:0]};
                 5'd29: read_data_2 = {24'h000000, registert[7:0]};
                 5'd30: read_data_2 = {24'h000000, registeru[7:0]};
                 5'd31: read_data_2 = {24'h000000, registerv[7:0]};
                 default: read_data_2 = 32'bx;
             endcase
             end
     else if (Sh==1)//读出去给存储器只要低16位
     begin 
           case(read_register_2_address[4:0])
                 5'd0: read_data_2 ={16'h0000, register0[15:0]};
                 5'd1: read_data_2 ={16'h0000, register1[15:0]};
                 5'd2: read_data_2 ={16'h0000, register2[15:0]};
                 5'd3: read_data_2 ={16'h0000, register3[15:0]};
                 5'd4: read_data_2 ={16'h0000, register4[15:0]};
                 5'd5: read_data_2 ={16'h0000, register5[15:0]};
                 5'd6: read_data_2 ={16'h0000, register6[15:0]};
                 5'd7: read_data_2 ={16'h0000, register7[15:0]};
                 5'd8: read_data_2 ={16'h0000, register8[15:0]};
                 5'd9: read_data_2 ={16'h0000, register9[15:0]};
                 5'd10: read_data_2 ={16'h0000, registera[15:0]};
                 5'd11: read_data_2 ={16'h0000, registerb[15:0]};
                 5'd12: read_data_2 ={16'h0000, registerc[15:0]};
                 5'd13: read_data_2 ={16'h0000, registerd[15:0]};
                 5'd14: read_data_2 ={16'h0000, registere[15:0]};
                 5'd15: read_data_2 ={16'h0000, registerf[15:0]};
                 5'd16: read_data_2 ={16'h0000, registerg[15:0]};
                 5'd17: read_data_2 ={16'h0000, registerh[15:0]};
                 5'd18: read_data_2 ={16'h0000, registeri[15:0]};
                 5'd19: read_data_2 ={16'h0000, registerj[15:0]};
                 5'd20: read_data_2 ={16'h0000, registerk[15:0]};
                 5'd21: read_data_2 ={16'h0000, registerl[15:0]};
                 5'd22: read_data_2 ={16'h0000, registerm[15:0]};
                 5'd23: read_data_2 ={16'h0000, registern[15:0]};
                 5'd24: read_data_2 ={16'h0000, registero[15:0]};
                 5'd25: read_data_2 ={16'h0000, registerp[15:0]};
                 5'd26: read_data_2 ={16'h0000, registerq[15:0]};
                 5'd27: read_data_2 ={16'h0000, registerr[15:0]};
                 5'd28: read_data_2 ={16'h0000, registers[15:0]};
                 5'd29: read_data_2 ={16'h0000, registert[15:0]};
                 5'd30: read_data_2 ={16'h0000, registeru[15:0]};
                 5'd31: read_data_2 ={16'h0000, registerv[15:0]};
                 default: read_data_2 = 32'bx;
            endcase 
         end      
     else 
     begin 
        case(read_register_2_address[4:0])
            5'd0: read_data_2 = register0;
            5'd1: read_data_2 = register1;
            5'd2: read_data_2 = register2;
            5'd3: read_data_2 = register3;
            5'd4: read_data_2 = register4;
            5'd5: read_data_2 = register5;
            5'd6: read_data_2 = register6;
            5'd7: read_data_2 = register7;
            5'd8: read_data_2 = register8;
            5'd9: read_data_2 = register9;
            5'd10: read_data_2 = registera;
            5'd11: read_data_2 = registerb;
            5'd12: read_data_2 = registerc;
            5'd13: read_data_2 = registerd;
            5'd14: read_data_2 = registere;
            5'd15: read_data_2 = registerf;
            5'd16: read_data_2 = registerg;
            5'd17: read_data_2 = registerh;
            5'd18: read_data_2 = registeri;
            5'd19: read_data_2 = registerj;
            5'd20: read_data_2 = registerk;
            5'd21: read_data_2 = registerl;
            5'd22: read_data_2 = registerm;
            5'd23: read_data_2 = registern;
            5'd24: read_data_2 = registero;
            5'd25: read_data_2 = registerp;
            5'd26: read_data_2 = registerq;
            5'd27: read_data_2 = registerr;
            5'd28: read_data_2 = registers;
            5'd29: read_data_2 = registert;
            5'd30: read_data_2 = registeru;
            5'd31: read_data_2 = registerv;
            default: read_data_2 = 32'bx;
            endcase
    end
    
    //根据不同的指令决定目的寄存器的寄存器号
    always @(*)
    begin
        if(RegDst==1)
            write_register_address[4:0] <= write_register_address_1[4:0];//R类型的目的寄存器是rd寄存器
        else if((RegDst==0)&&((Jal==1)||(bgezal==1)||(bltzal==1)))
            write_register_address[4:0] = 5'b11111; //Jal指令将下个指令地址存到31号寄存器
        else
            write_register_address[4:0] = write_register_address_0[4:0];
    end
    
    //写入寄存器的数据的准备
    always @(*)//(negedge clock or Instruction or read_data or ALU_result or opcplus4 or registerHI or registerLO)
    begin
        if((MemtoReg==0)&&((Jal==0)&&(Jalr==0)&&(bgezal==0)&&(bltzal==0))&&((mflo==0)&&(mfhi==0)))
            write_data[31:0] <= ALU_result[31:0];
            
        else if((MemtoReg==0)&&((Jal==1)||(Jalr==1)||(bgezal==1)||(bltzal==1)))
                write_data <= {15'b000000000000000,opcplus4[16:0]};
                
        else if(mflo==1)
            //write_data[31:0] <= registeradd;
            write_data[31:0] <= registerLO;
        else if(mfhi==1)
             write_data[31:0] <= registerHI;
        else if(Lb==1)  
        write_data <= {read_data[31],read_data[31],read_data[31],read_data[31],read_data[31],read_data[31],read_data[31],read_data[31],
        read_data[31],read_data[31],read_data[31],read_data[31],read_data[31],read_data[31],read_data[31],read_data[31],read_data[31],read_data[31],
        read_data[31],read_data[31],read_data[31],read_data[31],read_data[31],read_data[31],read_data[31:24]};
        
        else if(Lh==1)  
        write_data <= {read_data[31],read_data[31],read_data[31],read_data[31],read_data[31],read_data[31],
        read_data[31],read_data[31],read_data[31],read_data[31],read_data[31],read_data[31],read_data[31],read_data[31],
        read_data[31],read_data[31],read_data[31:16]};
        
        else if(Lbu==1) write_data <= {24'h000000,read_data[31:24]};
        else if(Lhu==1) write_data <= {16'h0000,read_data[31:16]};
        else  write_data <= read_data[31:0];
    end
    
    //目的寄存器的写操作
    always @ (negedge clock)
    begin
        if(reset==1)//复位时候，寄存器初始化为寄存器号
        begin
            register0<=32'd0; 
            register1<=32'd1;
            register2<=32'd2;
            register3<=32'd3;
            register4<=32'd4;
            register5<=32'd5;
            register6<=32'd6;
            register7<=32'd7;
            register8<=32'd8;
            register9<=32'd9;
            registera<=32'd10; 
            registerb<=32'd11; 
            registerc<=32'd12; 
            registerd<=32'd13; 
            registere<=32'd14; 
            registerf<=32'd15; 
            registerg<=32'd16; 
            registerh<=32'd17; 
            registeri<=32'd18; 
            registerj<=32'd19; 
            registerk<=32'd20; 
            registerl<=32'd21; 
            registerm<=32'd22; 
            registern<=32'd23; 
            registero<=32'd24; 
            registerp<=32'd25; 
            registerq<=32'd0;//中断26
            registerr<=32'd0;//中断27
            registers<=32'd28; 
            registert<=32'd29; 
            registeru<=32'd30; 
            registerv<=32'd31;
            registerHI<=32'd20;
            registerLO<=32'd10;
        end
        if((int0==1)&&(imask[0]==0))		//存INT0返回地址
           registerq[31:0]<={15'b000000000000000,intPC};
         else if((int1==1)&&(imask[1]==0)&&(imask[0]==0))    //    存INT1返回地址
           registerr[31:0]<={15'b000000000000000,intPC};
    end
        
   always @(*)//(write_data or read_data_1 or write_register_address or ALU_result_HI or ALU_result_LO)
   begin
        if((RegWrite == 1)&&(mthi==0)&&(mtlo==0)&&(MD==0))
        begin
            case(write_register_address[4:0])
                5'd0:register0<=32'd0;
                5'd1:register1<=write_data;
                5'd2:register2<=write_data;
                5'd3:register3<=write_data;
                5'd4:register4<=write_data;
                5'd5:register5<=write_data;
                5'd6:register6<=write_data;
                5'd7:register7<=write_data;
                5'd8:register8<=write_data;
                5'd9:register9<=write_data;
                5'd10:registera<=write_data;
                5'd11:registerb<=write_data;
                5'd12:registerc<=write_data;
                5'd13:registerd<=write_data;
                5'd14:registere<=write_data;
                5'd15:registerf<=write_data;
                5'd16:registerg<=write_data;
                5'd17:registerh<=write_data;
                5'd18:registeri<=write_data;
                5'd19:registerj<=write_data;
                5'd20:registerk<=write_data;
                5'd21:registerl<=write_data;
                5'd22:registerm<=write_data;
                5'd23:registern<=write_data;
                5'd24:registero<=write_data;
                5'd25:registerp<=write_data;
                5'd26:registerq<=write_data;
                5'd27:registerr<=write_data;
                5'd28:registers<=write_data;
                5'd29:registert<=write_data;
                5'd30:registeru<=write_data;
                5'd31:registerv<=write_data; 
                default:register0<=32'd0;
             endcase
        end
    else if((MD==0)&&(mtlo==1))
       registerLO<=read_data_1[31:0];
      // registeradd<=read_data_1[31:0];  
    else if((mthi==1)&&(MD==0))
        //registerLL<=read_data_1[31:0];
      registerHI<=read_data_1[31:0];
    
    else if(MD==1&&mtlo==0&&mthi==0&&mfhi==0&&mflo==0)
     begin
        registerHI <= ALU_result_HI;
        registerLO <= ALU_result_LO;
      end
    end
 
endmodule
