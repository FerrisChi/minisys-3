`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////

module Idecode32 (
	input			reset,
    input			clock,
    output	[31:0]	read_data_1,	// 输出的第一操作数
    output	[31:0]	read_data_2,	// 输出的第二操作数
    input	[31:0]	Instruction,	// 取指单元来的指令
    input	[31:0]	read_data,		// 从DATA RAM or I/O port取出的数据
    input	[31:0]	ALU_result,		// 从执行单元来的运算的结果，需要扩展立即数到32位
    input			Jal,			// 来自控制单元，说明是JAL指令 
    input			RegWrite,		// 来自控制单元
    input			MemtoReg,		// 来自控制单元
    input			RegDst,			// 来自控制单元
    output	[31:0]	Sign_extend,	// 译码单元输出的扩展后的32位立即数
    input	[31:0]	opcplus4		// 来自取指单元，JAL中用
);
    
    reg[31:0] register[0:31];			   //寄存器组共32个32位寄存器
    reg[4:0] write_register_address;        // 要写的寄存器的号
    reg[31:0] write_data;                   // 要写寄存器的数据放这里

    wire[4:0] read_register_1_address;    // 要读的第一个寄存器的号（rs）
    wire[4:0] read_register_2_address;     // 要读的第二个寄存器的号（rt）
    wire[4:0] write_register_address_1;   // r-form指令要写的寄存器的号（rd）
    wire[4:0] write_register_address_0;    // i-form指令要写的寄存器的号(rt)
    wire[15:0] Instruction_immediate_value;  // 指令中的立即数
    wire[5:0] opcode;                       // 指令码
    
    assign opcode = Instruction[31:26];	//OP
    assign read_register_1_address = ？？？//rs 
    assign read_register_2_address = ？？？//rt 
    assign write_register_address_1 = ？？？// rd(r-form)
    assign write_register_address_0 = ？？？//rt(i-form)
    assign Instruction_immediate_value = ？？？//data,rladr(i-form)


    wire sign;                                            // 取符号位的值

    assign sign = ？？？
    assign Sign_extend[31:0] = ？？？
    
    assign read_data_1 = ？？？
    assign read_data_2 = ？？？
    
    always @* begin                                            //这个进程指定不同指令下的目标寄存器

    end
    
    always @* begin  //这个进程基本上是实现结构图中右下的多路选择器,准备要写的数据
 
     end
    
    integer i;
    always @(posedge clock) begin       // 本进程写目标寄存器
        if(reset==1) begin              // 初始化寄存器组
            for(i=0;i<32;i=i+1) register[i] <= 0;
        end else if(RegWrite==1) begin  // 注意寄存器0恒等于0


        end
    end
endmodule
