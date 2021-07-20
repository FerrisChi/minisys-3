// Copyright 1986-1999, 2001-2013 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2013.4 (win64) Build 353583 Mon Dec  9 17:49:19 MST 2013
// Date        : Sat Jan 10 15:26:48 2015
// Host        : running 64-bit Service Pack 1  (build 7601)
// Command     : write_verilog -force -mode synth_stub D:/512/Minisys_new/Minisys_new.srcs/sources_1/ip/ram/ram_stub.v
// Design      : ram
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7a100tcsg324-1
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
module ram(clka, wea, addra, dina, douta)
/* synthesis syn_black_box black_box_pad_pin="clka,wea[0:0],addra[14:0],dina[31:0],douta[31:0]" */;
  input clka;
  input [0:0]wea;
  input [14:0]addra;
  input [31:0]dina;
  output [31:0]douta;
endmodule
