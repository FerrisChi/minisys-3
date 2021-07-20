`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
module programrom (
	// Program ROM Pinouts
	input			rom_clk_i,		// ROM clock
	input	[13:0]	rom_adr_i,		// 来源于取指单元的取指地址（PC�?
	output	[31:0]	Jpadr,			    // 给取指单元的读出的数据（指令�?
	// UART Programmer Pinouts
	input           upg_rst_i,      // UPG reset (Active High)
	input           upg_clk_i,      // UPG clock (10MHz)
	input           upg_wen_i,		// UPG write enable
	input	[13:0]	upg_adr_i,		// UPG write address
	input	[31:0]	upg_dat_i,		// UPG write data
	input           upg_done_i      // 1 if programming is finished
);

	// kickOff = 1的时候CPU 正常工作，否则就是串口下载程序�??
    wire kickOff = upg_rst_i | (~upg_rst_i & upg_done_i);
	
	// 分配64KB ROM, 编译器实际只�? 64KB ROM
    prgrom instmem (
        .clka	(kickOff ?	rom_clk_i	: upg_clk_i),
		.wea	(kickOff ?	1'b0			: upg_wen_i),
        .addra	(kickOff ?	rom_adr_i	: upg_adr_i),
		.dina	(kickOff ?	32'h00000000			: upg_dat_i),
        .douta	(Jpadr)
    );
	
endmodule
