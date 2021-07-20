`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2014/11/12 13:33:13
// Design Name: 
// Module Name: dmemory32
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

module dmemory32( 
    read_data,
    address,
    write_data,
    MemWrite,
    clock
    );
    output[31:0] read_data;//�洢���������������
    input[16:0] address;//����ִ�е�Ԫ
    input[31:0] write_data;//�������뵥Ԫ�����->�浽�洢����
    input MemWrite;//д�洢�����Կ��Ƶ�Ԫ
    input clock;
   
    
    wire clk; // wire lpm_write;       
    assign clk=!clock;                     //assign lpm_write=MemWrite&&(clk);
    
    ram ram1 (
        .clka(clk),                 // input wire clka(�½�����Ч)
        .wea(MemWrite),             // input wire [0 : 0] wea
        .addra(address[16:2]),      // input wire [14 : 0] addra
        .dina(write_data),          // input wire [31 : 0] dina
        .douta(read_data)           // output wire [31 : 0] douta
    ); 
endmodule
