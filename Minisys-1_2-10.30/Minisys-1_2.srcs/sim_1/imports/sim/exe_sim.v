`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/08/07 21:58:34
// Design Name: 
// Module Name: exe_sim
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


module exe_sim ();

	// input
	reg[31:0]  Read_data_1 = 32'h00000005;		//r-form rs
	reg[31:0]  Read_data_2 = 32'h00000006;        //r-form rt
	reg[31:0]  Sign_extend = 32'hffffff40;        //i-form
	reg[5:0]   Function_opcode = 6'b100000;      //add 
	reg[5:0]   Exe_opcode = 6'b000000;          //op code
	reg[1:0]   ALUOp = 2'b10;
	reg[4:0]   Shamt = 5'b00000;
	reg        Sftmd = 1'b0;
	reg        ALUSrc = 1'b0;
	reg        I_format = 1'b0;
	reg         Jrn = 1'b0;
	reg[31:0]  PC_plus_4 = 32'h00000004;
	// output
	wire       Zero;
	wire[31:0] ALU_Result;
	wire[31:0] Add_Result;        //pc op        
	
	Executs32 Uexe (
		.Read_data_1		(Read_data_1),		// 从译码单元的Read_data_1中来
		.Read_data_2		(Read_data_2),		// 从译码单元的Read_data_2中来
		.Sign_extend		(Sign_extend),		// 从译码单元来的扩展后的立即数
		.Function_opcode	(Function_opcode),	// 取指单元来的r-类型指令功能码,r-form instructions[5:0]
		.Exe_opcode			(Exe_opcode),		// 取指单元来的操作码
		.ALUOp				(ALUOp),			// 来自控制单元的运算指令控制编码
		.Shamt				(Shamt),			// 来自取指单元的instruction[10:6]，指定移位次数
		.Sftmd				(Sftmd),			// 来自控制单元的，表明是移位指令
		.ALUSrc				(ALUSrc),			// 来自控制单元，表明第二个操作数是立即数（beq，bne除外）
		.I_format			(I_format),			// 来自控制单元，表明是除beq, bne, LW, SW之外的I-类型指令
		.Jrn				(Jrn),				// 来自控制单元，书名是JR指令
		.Zero				(Zero),				// 为1表明计算值为0 
		.ALU_Result			(ALU_Result),		// 计算的数据结果
		.Add_Result			(Add_Result),		// 计算的地址结果        
		.PC_plus_4			(PC_plus_4)			// 来自取指单元的PC+4
	);
	
	initial begin
		#200 begin
			Exe_opcode = 6'b001000;  //addi 
			Read_data_1 = 32'h00000003;		//r-form rs
			Read_data_2 = 32'h00000006;        //r-form rt
			Sign_extend = 32'hffffff40;  
			Function_opcode = 6'b100000;      //addi 
			ALUOp = 2'b10;
			Shamt = 5'b00000;
			Sftmd = 1'b0;
			ALUSrc = 1'b1;
			I_format = 1'b1;
			PC_plus_4 = 32'h00000008;
		end 
		#200 begin
			Exe_opcode = 6'b000000;  //and
			Read_data_1 = 32'h000000ff;        //r-form rs
			Read_data_2 = 32'h00000ff0;        //r-form rt
			Sign_extend = 32'hffffff40;  
			Function_opcode = 6'b100100;      //and 
			ALUOp = 2'b10;
			Shamt = 5'b00000;
			Sftmd = 1'b0;
			ALUSrc = 1'b0;
			I_format = 1'b0;
			PC_plus_4 = 32'h0000000c;
		end 
		#200 begin
			Exe_opcode = 6'b000000;  //sll
			Read_data_1 = 32'h00000001;        //r-form rs
			Read_data_2 = 32'h00000002;        //r-form rt
			Sign_extend = 32'hffffff40;  
			Function_opcode = 6'b000000;      //sll
			ALUOp = 2'b10;
			Shamt = 5'b00011;
			Sftmd = 1'b1;
			ALUSrc = 1'b0;
			I_format = 1'b0;
			PC_plus_4 = 32'h00000010;
		end 
		#200 begin
			Exe_opcode = 6'b001111;  // LUI
			Read_data_1 = 32'h00000001;        //r-form rs
			Read_data_2 = 32'h00000002;        //r-form rt
			Sign_extend = 32'h00000040;  
			Function_opcode = 6'b000000;      //LUI
			ALUOp = 2'b10;
			Shamt = 5'b00001;
			Sftmd = 1'b0;
			ALUSrc = 1'b1;
			I_format = 1'b1;
			PC_plus_4 = 32'h00000014;
		end 
		#200 begin
			Exe_opcode = 6'b000100;  // BEQ
			Read_data_1 = 32'h00000001;        //r-form rs
			Read_data_2 = 32'h00000001;        //r-form rt
			Sign_extend = 32'h00000004;  
			Function_opcode = 6'b000100;      //LUI
			ALUOp = 2'b01;
			Shamt = 5'b00000;
			Sftmd = 1'b0;
			ALUSrc = 1'b0;
			I_format = 1'b0;
			PC_plus_4 = 32'h00000018;
		end 
	end
	
endmodule
