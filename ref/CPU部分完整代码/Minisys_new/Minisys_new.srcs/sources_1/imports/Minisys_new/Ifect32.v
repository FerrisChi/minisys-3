`timescale 1ns / 1ps
//�õ�Ԫ�Ĺ���
//1��ȡָ��
//2������pc
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2014/10/22 14:48:50
// Design Name: 
// Module Name: Ifect32
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
// 11/9�޸İ�
//////////////////////////////////////////////////////////////////////////////////
module Ifect32(
    Instrution,
    PC_plus_4_out,
    Add_result,
    read_data_1,
    nBranch,
    Branch,
    bgez,
    bgtz,
    blez,
    bltz,
    bgezal, 
    bltzal,
    Jmp,
    Jal,
    Jrn,
    Zero,
    EtZero,
    GtZero,
    LtZero,
    PC_out,
    clock,
    reset,
    opcplus4,
    Jalr,
    int0,int1,imask,intPC,read_register_1_address
    );
    
    output[31:0]  Instrution;     //32λָ�����������
    output[16:0]  PC_plus_4_out;  //PC+4�������ִ�е�Ԫ
    output[16:0]  PC_out;    //PCֵ�����֤��ʱ��ʹ��
    output[16:0]  opcplus4;  //pc+4(�͵�31�żĴ���) 
    
    input[16:0]  Add_result;     //beq bne ��ָ�����ת��ַ
    input[31:0]  read_data_1;    //jr,jalrָ��  pc<=rs��
    
    input    nBranch;     //���Կ��Ƶ�Ԫ
    input    Branch;
    input    bgez;
    input    bgtz;
    input    blez;
    input    bltz;
    input    bgezal; 
    input    bltzal;
    
    input    Jmp;
    input    Jal;
    input    Jrn;
    input    Jalr; 
    
    input    Zero;      //���¼�������ִ�е�Ԫ
    input    EtZero;    //$1��0��С��ϵ�жϵĽ��
    input    GtZero;
    input    LtZero;   
    
    input    clock;
    input    reset;
    
    //�ж����
    input int0,int1;						//CPU���ӵĴ������й����������ж�
    output[1:0]   imask;                    //��������뵥Ԫ���ж����μĴ���imaskR��ֵ,����λR[1]Ϊ1������INT1��R[0]Ϊ1������INT0��
    output[16:0]  intPC;                    //�����뵥Ԫ���жϷ��ص�ַ
    input[4:0]     read_register_1_address;    //�����뵥Ԫ����jrָ��ļĴ�����
    
    //�м���
    wire[18:0] PC_plus_4;    //������PC+4��
    reg[16:0] opcplus4; //Jal,jalr,bgezal,bltzalר��PC+4
    reg[16:0] next_PC; //��һ��ָ��PC���������մ��������������ֵ
    reg[18:0] PC;    //��ʼ����PC
    wire[31:0] Jpadr;  //ָ�ֵ��
    //�ж�
    assign intPC[16:0]=((Jmp==1)||(Jal==1))?Jpadr[16:0]:next_PC[16:0];//�жϷ��ص�ַ��������PC+4(��next_PC),������жϵ�����ת���Ļ�����Ӧ������ת��Ŀ���ַ

    //�ж����
    reg[1:0]     imask;					//�ж����μĴ���
    reg         rubbish;                 //����˿ںŵ�data����
  
    //ROM����
     program Rom(
            .clka(clock),            // input wire clka
            .addra(PC[16:2]),      // input wire [16 : 2] addra
            .douta(Jpadr[31:0]));        // output wire [31 : 0] douta
        
     assign PC_out=PC[16:0];    //���ڲ���PCֵ�͵�CPU�ⲿ������Ϲ���֤��
     assign PC_plus_4[1:0]=2'b00;
     assign PC_plus_4[18:2]=PC[18:2]+1;//pc+4      
     assign  PC_plus_4_out=PC_plus_4[16:0];
     assign  Instrution = Jpadr;
         
     always@ (*)
          begin                                                                        
           if(((Branch==1)&&(Zero==1))||((nBranch==1)&&(Zero==0))||
           (((bgez==1)||(bgezal==1))&&((EtZero==1)||(GtZero==1)))||
           ((bgtz==1)&&(GtZero==1))||((blez==1)&&((EtZero==1)||(LtZero==1)))||
           (((bltz==1)||(bltzal==1))&&(LtZero==1)))
                next_PC[16:0]=Add_result[16:0];
           else if(Jrn==1||Jalr==1)
               next_PC=read_data_1[16:0];//JR��Jalrָ��ת�Ƶ�ַ
           else next_PC= PC_plus_4[18:2];       //��Ϊ�˱�֤λ��һ�£���ѡ18λ�ġ�
      end
  
     always @ (negedge clock)//PC��ֵ
     begin 
         if(reset==1)//��ʼ��
          begin
           PC<=19'b0000000000000000000;
           imask=2'b00;
           end
         else if((int0==1)&&(imask[0]==0))					//��ӦINT0
            begin
             imask[0]=1;
             PC<=18'b000000111111111000;    //    PC�ĵ�ַ����0ff8H
            end
         else if((int1==1)&&(imask[1]==0)&&(imask[0]==0))    //��ӦINT1
             begin
              imask[1]=1;
              PC<=18'b000000111111111100;        //PC�ĵ�ַ����0ffcH
            end
         else if((Jmp==1)||(Jal==1))
            begin //JALָ��ִ��ǰ��Ҫ��PC+4���浽$31         
            opcplus4= PC_plus_4[18:2];    //�浽31�żĴ���
            PC[18:0]={Jpadr[16:0],2'b00};  //˳�����������λ
            end
         else if((bgezal==1)||(bltzal==1)||(Jalr==1))  //bgezal��bltzalҲ��Ҫ�ݴ浽31�żĴ���
            begin
            opcplus4= PC_plus_4[18:2];
            PC[18:0]={next_PC[16:0],2'b00};
            end
        else
            PC[18:0]={next_PC[16:0],2'b00};
        if(Jrn==1)			//�����жϷ���ʱ���μĴ����ĸ�λ
               begin
                if(read_register_1_address==5'b11010)  //$26
                     imask[0]=0;
                 else if(read_register_1_address==5'b11011)  //$27
                      imask[1]=0;
                 else  rubbish=0;
               end
     end  
endmodule
