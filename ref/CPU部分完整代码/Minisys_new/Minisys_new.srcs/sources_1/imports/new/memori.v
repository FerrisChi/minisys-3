`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2014/12/04 14:03:42
// Design Name: 
// Module Name: memori
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

// Change by Zhangyalin 12/6/2014 
//////////////////////////////////////////////////////////////////////////////////

//总线控制模块-1：MEMorIO模块，完成地址译码、数据转换和输入数据选择器
module memorio(caddress,address,memread,memwrite,ioread,iowrite,mread_data,ioread_data,wdata,rdata,write_data,
        LEDCtrl,KEYCtrl,CTCCtrl,PWMCtrl,UARTCtrl,WDTCtrl,DISPCtrl,SWCtrl);
     input[16:0] caddress;	//从执行单元来的alu_resullt[16:0]          //杨云改过
     input memread;			//从控制单元来的存储器读控制信号
     input memwrite;			//从控制单元来的存储器写控制信号
     input ioread;			//从控制单元来的I/O读控制信号
     input iowrite;			//从控制单元来的I/O写控制信号
     input[31:0] mread_data;	//从存储器来的数据
     input[15:0] ioread_data;	//从I/O端口来的数据
     input[31:0] wdata;			//从译码单元来的输出到存储器或I/O端口中去的数据
     output[31:0] rdata;			//从存储器或I/O端口读入的准备写到寄存器中去的数据
     output[31:0] write_data;	//准备写到存储器或I/O端口的输出数据
     output[16:0] address;		//总线上的地址（去存储器，低4位做访问端口的端口号） //杨云改过
     output DISPCtrl;           //数码管片选cs
     output KEYCtrl;			//key（键盘）接口部件的片选cs
     output CTCCtrl;			//counter(计数器)接口不见的片选cs
     output PWMCtrl;			//pwm（脉宽调制）接口部件的片选cs
     output UARTCtrl;		    //UART（异步串行通信）接口部件的片选cs
     output WDTCtrl;			//watch dog（看门狗）接口部件的片选cs
     output LEDCtrl;			//LED接口部件的片选cs
     output SWCtrl;             //拨码开关片选信号cs
     
reg[31:0] write_data;
wire iorw;

assign address=caddress[16:0];
assign rdata=(memread==1)? mread_data:{16'h0000,ioread_data[15:0]};
assign iorw=(iowrite||ioread);

//changed by zhangyalin
assign DISPCtrl = ((iorw==1)&&(caddress[16:4]==13'b1111111000000))?1'b1:1'b0;
assign KEYCtrl = ((iorw==1)&&(caddress[16:4]==13'b1111111000001))?1'b1:1'b0;
assign CTCCtrl = ((iorw==1)&&(caddress[16:4]==13'b1111111000010))?1'b1:1'b0;
assign PWMCtrl = ((iorw==1)&&(caddress[16:4]==13'b1111111000011))?1'b1:1'b0;
assign UARTCtrl = ((iorw==1)&&(caddress[16:4]==13'b1111111000100))?1'b1:1'b0;
assign WDTCtrl = ((iorw==1)&&(caddress[16:4]==13'b1111111000101))?1'b1:1'b0;
assign LEDCtrl = ((iorw==1)&&(caddress[16:4]==13'b1111111000110))?1'b1:1'b0;
assign SWCtrl = ((iorw==1)&&(caddress[16:4]==13'b1111111000111))?1'b1:1'b0;

always@(*)
begin
	if((memwrite==1)||(iowrite==1))
	begin
		write_data=wdata;
	end
	else
		begin
			write_data=32'hzzzzzzzz;
		end
	end
endmodule

