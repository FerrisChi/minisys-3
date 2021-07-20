`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2014/12/02 14:18:00
// Design Name: 
// Module Name: led16
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
    //8λ7������ܿ�����
    module disp16(
    reset,
    address,
    data,
    cs,
    iow,
    led0,led1,led2,led3,led4,led5,led6,led7,
    enable8,
    point8
    );
    input reset;            //ϵͳ��λ�ź�
    input[31:0] address;    //��ַ�ź�
    input[15:0] data;        //ϵͳ�����е�������
    input cs;                //Ƭѡ�źţ���LEDCtrl
    input iow;                //I/Oд�ź�
    output[6:0] led0;        //led0����ź�
    output[6:0] led1;        //led1����ź�
    output[6:0] led2;        //led2����ź�
    output[6:0] led3;        //led3����ź�
    output[6:0] led4;       //����
    output[6:0] led5; 
    output[6:0] led6; 
    output[6:0] led7; 
    output[7:0] enable8;    //ѡͨ�ź�
    output[8:0] point8;    //8��С�������ʾ�ź�
    
    reg[6:0] led0,led1,led2,led3;
    reg[6:0] led4,led5,led6,led7;
    reg[15:0] Ldata,Hdata,ctrl;        //����������,�ֱ��FFFFFC00��FFFFFC02��FFFFFC04��������
    reg[7:0] enable8;
    reg[8:0] point8;
    
    
    always@(posedge cs or posedge reset)
    begin
        if(reset ==1)
        begin
            Ldata <=16'h0000;
            Hdata <=16'h0000;
            ctrl <=16'h0000;
        end
        else if(cs==1&&iow==1)
        begin
            if(address==32'hFFFFFC00)begin
                Ldata <= data[15:0];
            end
            else if(address==32'hFFFFFC02)begin
                Hdata <= data[15:0];
            end
            else if(address==32'hFFFFFC04)begin
                ctrl <= data[15:0];
            end
        end
    end
    
    assign enable8=ctrl[15:8];
    assign point8=ctrl[7:0];
    
    always@(Ldata or Hdata)
    begin
    case(Ldata[3:0])
        4'b0000:led0=7'b1000000;    //0
        4'b0001:led0=7'b1111001;    //1
        4'b0010:led0=7'b0100100;    //2
        4'b0011:led0=7'b0110000;    //3
        4'b0100:led0=7'b0011001;    //4
        4'b0101:led0=7'b0010010;    //5
        4'b0110:led0=7'b0000010;    //6
        4'b0111:led0=7'b1111000;    //7
        4'b1000:led0=7'b0000000;    //8
        4'b1001:led0=7'b0010000;    //9
        4'b1010:led0=7'b0001000;    //a
        4'b1011:led0=7'b0000011;    //b
        4'b1100:led0=7'b1000110;    //c
        4'b1101:led0=7'b0100001;    //d
        4'b1110:led0=7'b0000110;    //e
        4'b1111:led0=7'b0001110;    //f
        default:led0=7'b1111111;
    endcase
    case(Ldata[7:4])                //led1�ĸ�ֵ
        4'b0000:led1=7'b1000000;    //0
        4'b0001:led1=7'b1111001;    //1
        4'b0010:led1=7'b0100100;    //2
        4'b0011:led1=7'b0110000;    //3
        4'b0100:led1=7'b0011001;    //4
        4'b0101:led1=7'b0010010;    //5
        4'b0110:led1=7'b0000010;    //6
        4'b0111:led1=7'b1111000;    //7
        4'b1000:led1=7'b0000000;    //8
        4'b1001:led1=7'b0010000;    //9
        4'b1010:led1=7'b0001000;    //a
        4'b1011:led1=7'b0000011;    //b
        4'b1100:led1=7'b1000110;    //c
        4'b1101:led1=7'b0100001;    //d
        4'b1110:led1=7'b0000110;    //e
        4'b1111:led1=7'b0001110;    //f
        default:led1=7'b1111111;
    endcase
    case(Ldata[11:8])                //led2�ĸ�ֵ
        4'b0000:led2=7'b1000000;    //0
        4'b0001:led2=7'b1111001;    //1
        4'b0010:led2=7'b0100100;    //2
        4'b0011:led2=7'b0110000;    //3
        4'b0100:led2=7'b0011001;    //4
        4'b0101:led2=7'b0010010;    //5
        4'b0110:led2=7'b0000010;    //6
        4'b0111:led2=7'b1111000;    //7
        4'b1000:led2=7'b0000000;    //8
        4'b1001:led2=7'b0010000;    //9
        4'b1010:led2=7'b0001000;    //a
        4'b1011:led2=7'b0000011;    //b
        4'b1100:led2=7'b1000110;    //c
        4'b1101:led2=7'b0100001;    //d
        4'b1110:led2=7'b0000110;    //e
        4'b1111:led2=7'b0001110;    //f
        default:led2=7'b1111111;
    endcase
    case(Ldata[15:12])                //led3�ĸ�ֵ
        4'b0000:led3=7'b1000000;    //0
        4'b0001:led3=7'b1111001;    //1
        4'b0010:led3=7'b0100100;    //2
        4'b0011:led3=7'b0110000;    //3
        4'b0100:led3=7'b0011001;    //4
        4'b0101:led3=7'b0010010;    //5
        4'b0110:led3=7'b0000010;    //6
        4'b0111:led3=7'b1111000;    //7
        4'b1000:led3=7'b0000000;    //8
        4'b1001:led3=7'b0010000;    //9
        4'b1010:led3=7'b0001000;    //a
        4'b1011:led3=7'b0000011;    //b
        4'b1100:led3=7'b1000110;    //c
        4'b1101:led3=7'b0100001;    //d
        4'b1110:led3=7'b0000110;    //e
        4'b1111:led3=7'b0001110;    //f
        default:led3=7'b1111111;
    endcase
        case(Hdata[3:0])
           4'b0000:led4=7'b1000000;    //0
           4'b0001:led4=7'b1111001;    //1
           4'b0010:led4=7'b0100100;    //2
           4'b0011:led4=7'b0110000;    //3
           4'b0100:led4=7'b0011001;    //4
           4'b0101:led4=7'b0010010;    //5
           4'b0110:led4=7'b0000010;    //6
           4'b0111:led4=7'b1111000;    //7
           4'b1000:led4=7'b0000000;    //8
           4'b1001:led4=7'b0010000;    //9
           4'b1010:led4=7'b0001000;    //a
           4'b1011:led4=7'b0000011;    //b
           4'b1100:led4=7'b1000110;    //c
           4'b1101:led4=7'b0100001;    //d
           4'b1110:led4=7'b0000110;    //e
           4'b1111:led4=7'b0001110;    //f
           default:led4=7'b1111111;
       endcase
       case(Hdata[7:4])                //
           4'b0000:led5=7'b1000000;    //0
           4'b0001:led5=7'b1111001;    //1
           4'b0010:led5=7'b0100100;    //2
           4'b0011:led5=7'b0110000;    //3
           4'b0100:led5=7'b0011001;    //4
           4'b0101:led5=7'b0010010;    //5
           4'b0110:led5=7'b0000010;    //6
           4'b0111:led5=7'b1111000;    //7
           4'b1000:led5=7'b0000000;    //8
           4'b1001:led5=7'b0010000;    //9
           4'b1010:led5=7'b0001000;    //a
           4'b1011:led5=7'b0000011;    //b
           4'b1100:led5=7'b1000110;    //c
           4'b1101:led5=7'b0100001;    //d
           4'b1110:led5=7'b0000110;    //e
           4'b1111:led5=7'b0001110;    //f
           default:led5=7'b1111111;
       endcase
       case(Hdata[11:8])                //
           4'b0000:led6=7'b1000000;    //0
           4'b0001:led6=7'b1111001;    //1
           4'b0010:led6=7'b0100100;    //2
           4'b0011:led6=7'b0110000;    //3
           4'b0100:led6=7'b0011001;    //4
           4'b0101:led6=7'b0010010;    //5
           4'b0110:led6=7'b0000010;    //6
           4'b0111:led6=7'b1111000;    //7
           4'b1000:led6=7'b0000000;    //8
           4'b1001:led6=7'b0010000;    //9
           4'b1010:led6=7'b0001000;    //a
           4'b1011:led6=7'b0000011;    //b
           4'b1100:led6=7'b1000110;    //c
           4'b1101:led6=7'b0100001;    //d
           4'b1110:led6=7'b0000110;    //e
           4'b1111:led6=7'b0001110;    //f
           default:led6=7'b1111111;
       endcase
       case(Hdata[15:12])                //
           4'b0000:led7=7'b1000000;    //0
           4'b0001:led7=7'b1111001;    //1
           4'b0010:led7=7'b0100100;    //2
           4'b0011:led7=7'b0110000;    //3
           4'b0100:led7=7'b0011001;    //4
           4'b0101:led7=7'b0010010;    //5
           4'b0110:led7=7'b0000010;    //6
           4'b0111:led7=7'b1111000;    //7
           4'b1000:led7=7'b0000000;    //8
           4'b1001:led7=7'b0010000;    //9
           4'b1010:led7=7'b0001000;    //a
           4'b1011:led7=7'b0000011;    //b
           4'b1100:led7=7'b1000110;    //c
           4'b1101:led7=7'b0100001;    //d
           4'b1110:led7=7'b0000110;    //e
           4'b1111:led7=7'b0001110;    //f
           default:led7=7'b1111111;
       endcase
    end 
endmodule
