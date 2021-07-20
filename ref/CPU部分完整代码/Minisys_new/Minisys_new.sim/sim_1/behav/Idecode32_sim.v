`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2014/11/19 16:58:02
// Design Name: 
// Module Name: Idecode32_sim
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


module Idecode32_sim(
    );    
    //input
    reg[31:0]     Instruction;
    reg[31:0]     read_data;
    reg[31:0]     ALU_result;
    reg[31:0]     ALU_result_HI;    
    reg[31:0]     ALU_result_LO;
    reg[16:0]     opcplus4;   //来自取指单元，JAL,Jalr,bgezal,bltzal中用,注意位数
    
    reg   Jal=0;
    reg   Jalr=0;
    reg   bgezal=0;
    reg   bltzal=0;
    reg   mfhi=0;
    reg   mflo=0;
    reg   mtlo=0;
    reg   mthi=0;
    reg   MD=0;
    reg   Lw=0;
    reg   Lb=0;
    reg   Lbu=0;
    reg   Lh=0;
    reg   Lhu=0;
    reg   Sw=0;
    reg   Sb=0;
    reg   Sh=0;
    reg   RegWrite=0;
    reg   MemtoReg=0;
    reg   RegDst=0;
    reg   clock=1;
    reg   reset=1;
    
    //output
    wire[31:0] read_data_1;
    wire[31:0] read_data_2;
    wire[31:0] Sign_extend;
    wire[4:0]  write_register_address_out;
    wire[31:0] write_data_out;
  
    
    //实例化
    Idecode32 idecode(
     .read_data_1(read_data_1),
     .read_data_2(read_data_2),
     .Instruction(Instruction),
     .read_data(read_data),
     .ALU_result(ALU_result),
     .ALU_result_HI(ALU_result_HI),
     .ALU_result_LO(ALU_result_LO),
     .Jal(Jal),
     .Jalr(Jalr),
     .bgezal(bgezal),
     .bltzal(bltzal),
     .mfhi(mfhi),
     .mflo(mflo),
     .mthi(mthi),
     .mtlo(mtlo),
     .Lw(Lw),
     .Lb(Lb),
     .Lbu(Lbu),
     .Lh(Lh),
     .Lhu(Lhu),
     .Sw(Sw),
     .Sb(Sb),
     .Sh(Sh),
     .MD(MD),
     .RegWrite(RegWrite),
     .MemtoReg(MemtoReg),
     .RegDst(RegDst),
     .Sign_extend(Sign_extend),
     .clock(clock),
     .reset(reset),
     .opcplus4(opcplus4),
     .write_data_out(write_data_out),
     .write_register_address_out(write_register_address_out)
    );
    
     initial begin
        #10 reset = 0;  //为1复位过一段时间拉低
        #10 Instruction[31:0]=32'b00000000000000000001100000010000;
        
              // #0   ALU_result[31:0]=31'b00000000000000000000000000000001;
               #0  mfhi=1;
               #0  mtlo=0;
               #0  mthi=0;
               #0 RegDst=1;
               #0 RegWrite=1;
               
                #10 Instruction[31:0]=32'b00000000000000000010000000010010;
                //#0   ALU_result[31:0]=31'b00000000000000000000000000000001;
                #0  mfhi=0;
                #0  mflo=1;
                  
                
                #10 Instruction[31:0]=32'b00000000011001000010100000100000;
               // #0  ALU_result[31:0]=31'b00000000000000000000000000000001;
                #0  mfhi=0;
                #0  mflo=0;
                
        #10 Instruction[31:0]=32'b00000000010000000000000000010011;
       
               // #0   ALU_result[31:0]=31'b00000000000000100000000000000000;
        #0  mthi=0;
        #0  mtlo=1;
        #0 RegWrite=1;
        #0 RegDst=0; 
                
        #10 Instruction[31:0]=32'b00000000111000000000000000010001;
        //#0  ALU_result[31:0]=31'b00000000000000001000000000000001;
        #0  mthi=1;
        #0  mtlo=0;
           
        
       #10 Instruction[31:0]=32'b00000000000000000001100000010000;
      // #0   ALU_result[31:0]=31'b00000000000000000000000000000001;
       #0  mfhi=1;
       #0  mtlo=0;
       #0  mthi=0;
       #0 RegDst=1;
       
        #10 Instruction[31:0]=32'b00000000000000000010000000010010;
        //#0   ALU_result[31:0]=31'b00000000000000000000000000000001;
        #0  mfhi=0;
        #0  mflo=1;
          
        
        #10 Instruction[31:0]=32'b00000000011001000010100000100000;
       // #0  ALU_result[31:0]=31'b00000000000000000000000000000001;
        #0  mfhi=0;
        #0  mflo=0;
         
       // #10 Instruction[31:0]=32'b00000000001000100001100000100011;
        // #0  ALU_result[31:0]=31'b00000000000000000000000000000100;
     end 
           
      always begin 
          #5 clock=~clock;
          Jal=0;
          Jalr=0;           
          RegWrite=1;
          MemtoReg=0;
     end
endmodule
