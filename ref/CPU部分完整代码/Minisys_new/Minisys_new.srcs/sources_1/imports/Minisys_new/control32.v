`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2014/11/03 16:04:34
// Design Name: 
// Module Name: control32
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


module control32(Opcode,Funtion_opcode,rs,Alu_result,Jrn,RegDST,ALUSrc,MemtoReg,Lw,Lb,Lbu,Lh,Lhu,MemWrite,Sw,Sb,Sh,RegWrite,Branch,nBranch,bgez,bgtz,blez,bltz,
                 bgezal, bltzal,Jmp,Jal,Jalr,Sftmd,MD,ALUOp, Mfhi, Mflo,Mthi,Mtlo,break1,syscall,eret,Mfc0,Mtc0,I_format,Mult,Multu,Div,Divu,MemorIOtoReg,IOWrite,IORead
                );
    input[5:0] Opcode;//ָ�������λ
    input[5:0] Funtion_opcode;//ָ�������λ
    input[4:0] rs;//bgez�Ǽ���ָ���õ�
    input[31:0] Alu_result;//����ִ�е�Ԫ
    
    output Jrn;  //Jr
    output RegDST;//Ŀ�ļĴ���ѡ�� 1��rd  2:rt
    output ALUSrc;//�ڶ���������������������Beq,Bne��
    
    output MemtoReg;//�洢���������Ĵ���(lw)
    output Lw;
    output Lb;
    output Lbu;
    output Lh;
    output Lhu;  
    
    output MemWrite;//д�洢��
    output Sw;
    output Sb;
    output Sh;
          
    output RegWrite;//д�Ĵ���
  
    output Branch;//Beq
    output nBranch;//Bne
    output bgez;
    output bgtz;
    output blez;
    output bltz;
    output bgezal; 
    output bltzal;
    
    output Jmp;//J
    output Jal;//Jal
    output Jalr;//Jalr
    
    output Sftmd;//��λָ��
    output MD;//�˳���
    output Mult;
    output Multu;
    output Div;
    output Divu;
    output I_format;//��beq,bne,LW,SW֮���I-��ָ��
    output[1:0] ALUOp;
     
    //��ȡHI��LO
    output Mfhi;//ȡ
    output Mflo;
    output Mthi;//��
    output Mtlo;
    
    output break1;
    output syscall;
    output eret;
    
    //C0�Ĵ������ָ��
    output Mfc0;
    output Mtc0;
    
    //I/O��ص��ź�
    output MemorIOtoReg;
    output IOWrite;
    output IORead;
        
    wire I_format;
    wire R_format;
    wire Sftmd;
      
     //ALUSrc�ڶ���������������������Beq��bne��bgew-bltzal��
     assign ALUSrc=((MemtoReg==1)||(MemWrite==1)||(I_format==1))?1:0;
     
      //R-�� ��λ��
     assign Sftmd=(Opcode==6'b000000&&Funtion_opcode[5:3]==3'b000)?1:0;    //ʶ���������λָ��
          
     //RegDST
      assign RegDST=((Jalr==1)||(Sftmd==1)||((Opcode==6'b000000)&&((Funtion_opcode[5:3]==3'b100)||(Funtion_opcode[5:3]==3'b101)||(Mfhi==1)||(Mflo==1))))?1:0;
     
     //RegWrite
     assign RegWrite=((bgezal==1)||(bltzal)||(Jal==1)||(Jalr==1)||(MemorIOtoReg==1)||(MemtoReg==1)||(Sftmd==1)||(I_format==1)||((Opcode==6'b000000)&&(Funtion_opcode[5:3]==3'b100))||(MD==1)||(Mfhi==1)||(Mflo==1)||(Mfc0==1)||(Mthi==1)||(Mtlo==1))?1:0;
   
      //R��ָ��
     assign R_format=(Opcode==6'b000000||Opcode==6'b010000)?1:0;//R��ָ��
     
     //Jmp
      assign Jmp=(Opcode==6'b000010)?1:0;      //ֻ��Jָ�� Jmp=1

      //Jal
      assign Jal=(Opcode==6'b000011)?1:0;      //ֻ��Jָ�� Jal=1
      
      //ֻ��JALrָ�� Jalr=1
      assign Jalr=(Opcode==6'b000000&&Funtion_opcode==6'b001001)?1:0;  //ֻ��JALRָ�� Jalr=1
      
      //JRָ��
      assign Jrn=(Opcode==6'b000000&&Funtion_opcode==6'b001000)?1:0;   //ֻ��JRָ�� Jrn=1
    
     //bne beq��ָ��
     assign Branch=(Opcode==6'b000100)?1:0;
     assign nBranch=(Opcode==6'b000101)?1:0;
     assign bgez=((Opcode==6'b000001)&&(rs==5'b00001))?1:0;
     assign bgtz=((Opcode==6'b000111)&&(rs==5'b00000))?1:0;
     assign blez=((Opcode==6'b000110)&&(rs==5'b00000))?1:0;
     assign bltz=((Opcode==6'b000001)&&(rs==5'b0000))?1:0;
     assign bgezal=((Opcode==6'b000001)&&(rs==5'b10001))?1:0; 
     assign bltzal=((Opcode==6'b000001)&&(rs==5'b10000))?1:0;
     
     //�洢����
     assign MemtoReg=((Opcode[5:3]==3'b100)&&(Alu_result[31:10]!=22'b1111111111111111111111))?1:0;//˵���Ƕ��洢����ָ��
     assign Lw=(Opcode==6'b100011)?1:0;
     assign Lb=(Opcode==6'b100000)?1:0;
     assign Lbu=(Opcode==6'b100100)?1:0;
     assign Lh=(Opcode==6'b100001)?1:0;
     assign Lhu=(Opcode==6'b100101)?1:0;
     
     //�洢��д
     assign MemWrite=((Opcode[5:3]==3'b101)&&(Alu_result[31:10]!=22'b1111111111111111111111))?1:0;
     assign Sw=(Opcode==6'b101011)?1:0;//д�洢��
     assign Sb=(Opcode==6'b101000)?1:0;
     assign Sh=(Opcode==6'b101001)?1:0;
     
    //I_format==1
    assign I_format=((Opcode[5:3]==3'b001))?1:0;
    
    //�˳�
    assign MD=((Opcode==6'b000000)&&(Funtion_opcode[5:3]==3'b011))?1:0;
    assign Mult=((Opcode==6'b000000)&&(Funtion_opcode==6'b011000))?1:0;
    assign Multu=((Opcode==6'b000000)&&(Funtion_opcode==6'b011001))?1:0;
    assign Div=((Opcode==6'b000000)&&(Funtion_opcode==6'b011010))?1:0;
    assign Divu=((Opcode==6'b000000)&&(Funtion_opcode==6'b011011))?1:0;
     
  
   //��ȡHI��LO
   assign Mfhi=((Opcode==6'b000000)&&(Funtion_opcode==6'b010000))?1:0;//ȡ
   assign Mflo=((Opcode==6'b000000)&&(Funtion_opcode==6'b010010))?1:0;
   assign Mthi=((Opcode==6'b000000)&&(Funtion_opcode==6'b010001))?1:0;//��
   assign Mtlo=((Opcode==6'b000000)&&(Funtion_opcode==6'b010011))?1:0;
   
   //MFC0��MFT0;
   assign Mfc0=((Opcode==6'b010000)&&(rs==5'b00000))?1:0;
   assign Mtc0=((Opcode==6'b010000)&&(rs==5'b00100)&&(Funtion_opcode!=011000))?1:0;
   
   //break;syscall;erer;
    assign break1=((Opcode==6'b000000)&&(Funtion_opcode==6'b001101))?1:0;
    assign syscall=((Opcode==6'b000000)&&(Funtion_opcode==6'b001100))?1:0;
    assign eret=((Opcode==6'b010000)&&(Funtion_opcode==6'b011000)&&(rs==5'b10000))?1:0;
    
    //ALUOp
    assign ALUOp[1]=((R_format==1)||(I_format==1))?1:0;
    assign ALUOp[0]=((Branch==1)||(nBranch==1)||(bgez==1)||(bgtz==1)||(blez==1)||(bgezal==1)||(bltzal==1))?1:0;          
    //IO���,ALU������ĵ�ַ�����22λ��Ϊ1������IO������IO��ַ�ռ�FFFFFC00H �� FFFFFFFFH
    assign MemorIOtoReg=IORead||MemtoReg;
    assign IOWrite=((Opcode[5:3]==3'b101)&&(Alu_result[31:10]==22'b1111111111111111111111))?1'b1:1'b0;
    assign IORead=((Opcode[5:3]==3'b100)&&(Alu_result[31:10]==22'b1111111111111111111111))?1'b1:1'b0;
   
  endmodule