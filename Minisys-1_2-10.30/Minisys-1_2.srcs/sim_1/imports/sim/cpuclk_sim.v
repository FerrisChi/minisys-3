`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/07/28 23:51:45
// Design Name: 
// Module Name: cpuclk_sim
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


module cpuclk_sim ();

    //  INPUT
    reg pclk = 0;
    //output
    wire clock, uclk;
    
    cpuclk Uclk (
        .clk_in1	(pclk),		// 100MHz
        .clk_out1	(clock),	// CPU Clock
		.clk_out2	(uclk)		// UART Programmer Clock
    );
    
    always #5 pclk = ~pclk;
	
endmodule
