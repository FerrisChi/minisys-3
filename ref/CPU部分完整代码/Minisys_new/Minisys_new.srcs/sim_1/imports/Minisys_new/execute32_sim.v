`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2014/11/26 17:23:51
// Design Name: 
// Module Name: execute32_sim
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


module execute32_sim(
    );   
        reg[31:0] read_data_1;
        reg[31:0] read_data_2;
        reg[31:0] Sign_extend;
        reg[5:0]  Function_opcode=0;
        reg[5:0]  Exe_opcode=0;
        reg[1:0]  ALUOp=2'b10; //暂时两位
        reg[4:0]  Shamt=4'b0000;
        reg       Sftmd=1;
        reg       ALUSrc=0;
        reg       I_format=0;
        reg       MD=0;//乘除法相关信号
        reg       Mult=0;
        reg       Multu=0;
        reg       Div=0;
        reg       Divu=0;
        reg[16:0] PC_plus_4;//地址位数待考量
       
        wire          Zero;
        wire          EtZero; //等于0
        wire          GtZero; //大于0
        wire          LtZero; //小于0
        wire[31:0]    ALU_Result; 
        wire[31:0]    ALU_Result_HI; //乘除法计算结果
        wire[31:0]    ALU_Result_LO; 
        wire[16:0]    Add_Result; //地址计算结果，位数待修改
        
       Execute32 execute(
            .read_data_1(read_data_1),
            .read_data_2(read_data_2),
            .Sign_extend(Sign_extend),
            .Function_opcode(Function_opcode),
            .Exe_opcode(Exe_opcode),
            .ALUOp(ALUOp),
            .Shamt(Shamt),
            .ALUSrc(ALUSrc),
            .I_format(I_format),
            .Sftmd(Sftmd),
            .MD(MD),
            .Mult(Mult),
            .Multu(Multu),
            .Div(Div),
            .Divu(Divu),
            .Zero(Zero),
            .EtZero(EtZero),
            .GtZero(GtZero),
            .LtZero(LtZero),
            .ALU_Result(ALU_Result),
            .Add_Result(Add_Result),
            .ALU_Result_HI(ALU_Result_HI),
            .ALU_Result_LO(ALU_Result_LO),
            .PC_plus_4(PC_plus_4)
            );
        
        initial begin
        //sll
             #10 read_data_1=32'b00000000000000000000000000000000;
             #0  read_data_2=32'b00000000000000000000000000001101;
             #0  Function_opcode[5:0]=6'b000000;
             #0  Exe_opcode[5:0]=6'b000000;
             #0  Shamt=5'b00010;
             #0  ALUOp[1:0]=2'b10; //暂时两位
             
             #10 read_data_1=32'b00000000000000000000000000000000;
             #0  read_data_2=32'b00000000000000000000000000110100;
             #0  Function_opcode[5:0]=6'b000010;
             #0  Exe_opcode[5:0]=6'b000000;
             #0  ALUOp[1:0]=2'b10; //暂时两位
             
             #10 read_data_1=32'b0;
             #0  read_data_2=32'b00000000000000000001000000000010;
             #0  Function_opcode[5:0]=6'b100000;
             #0  Exe_opcode[5:0]=6'b000000;
             #0  ALUOp[1:0]=2'b10; //暂时两
             
             #10 read_data_1=32'b00000000000000000000000000000000;
             #0  read_data_2=32'b00000000000000000000000000001101;
             #0  Function_opcode[5:0]=6'b000000;
             #0  Exe_opcode[5:0]=6'b000000;
              
        end 
        
endmodule
