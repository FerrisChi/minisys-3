`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2014/11/21 14:22:03
// Design Name: 
// Module Name: dememory32_sim
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


module dememory32_sim(
    );
    //output
    wire[31:0] read_data;//�洢���������������
    //input00000010000100011001000000100000,
    reg[16:0] address=17'b00000000000000000;
    reg[31:0] write_data=32'b10000000000000000000000000000000;//�������뵥Ԫ�����->�浽�洢����
    reg MemWrite=0;//д�洢�����Կ��Ƶ�Ԫ
    reg clock=1;
   
    dmemory32 dmemory( 
        .read_data(read_data),
        .address(address),
        .write_data(write_data),
        .MemWrite(MemWrite),
        .clock(clock)
        );
        
        initial begin
           #0 MemWrite=0;//��
           #5 clock=~clock;
           #5 clock=~clock;
          
           #0 MemWrite=1;//д
           #5 clock=~clock;
           #5 clock=~clock;
  
           #0 MemWrite=0;//��
           #5 clock=~clock;
           #5 clock=~clock;

         end
endmodule
