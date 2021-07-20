`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2014/11/16 16:20:05
// Design Name: 
// Module Name: control32_sim
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


module control32_sim(
    );
    //����
    reg[5:0] Opcode;//ָ�������λ
    reg[5:0] Funtion_opcode;//ָ�������λ
    reg[4:0] rs;//bgez�Ǽ���ָ���õ�
    
    //���
    wire Jrn;  //Jr
    wire RegDST;//Ŀ�ļĴ���ѡ�� 1��rd  2:rt
    wire ALUSrc;//�ڶ���������������������Beq,Bne��    
    wire MemtoReg;//�洢�����鵽�Ĵ���(lw)
    wire Lw;
    wire Lb;
    wire Lbu;
    wire Lh;
    wire Lhu;   
    wire MemWrite;//д�洢��
    wire Sw;
    wire Sb;
    wire Sh; 
    wire RegWrite;//д�Ĵ���
    wire Branch;//Beq
    wire nBranch;//Bne
    wire bgez;
    wire bgtz;
    wire blez;
    wire bltz;
    wire bgezal; 
    wire bltzal;
    wire Jmp;//J
    wire Jal;//Jal
    wire Jalr;//Jalr  
    wire Sftmd;//��λָ��
    wire MD;//�˳���
    wire I_format;//��beq,bne,LW,SW֮���I-��ָ��
    wire[1:0] ALUOp; 
    //��ȡHI��LO
    wire Mfhi;//ȡ
    wire Mflo;
    wire Mthi;//��
    wire Mtlo;   
    wire break1;
    wire syscall;
    wire eret;
    //C0�Ĵ������ָ��
    wire Mfc0;
    wire Mtc0;
    
    control32 control(
        .Opcode(Opcode),
        .Funtion_opcode(Funtion_opcode),
        .rs(rs),
        .Jrn(Jrn),
        .RegDST(RegDST),
        .ALUSrc(ALUSrc),
        .MemtoReg(MemtoReg),
        .Lw(Lw),
        .Lb(Lb),
        .Lbu(Lbu),
        .Lh(Lh),
        .Lhu(Lhu),
        .MemWrite(MemWrite),
        .Sw(Sw),
        .Sb(Sb),
        .Sh(Sh),
        .RegWrite(RegWrite),
        .Branch(Branch),
        .nBranch(nBranch),
        .bgez(bgez),
        .bgtz(bgtz),
        .blez(blez),
        .bltz(bltz),
        .bgezal(bgezal),
        .bltzal(bltzal),
        .Jmp(Jmp),
        .Jal(Jal),
        .Jalr(Jalr),
        .Sftmd(Sftmd),
        .MD(MD),
        .I_format(I_format),
        .ALUOp(ALUOp),
        .Mfhi(Mfhi),
        .Mflo(Mflo),
        .Mthi(Mthi),
        .Mtlo(Mtlo),
        .break1(break1),
        .syscall(syscall),
        .eret(eret),
        .Mfc0(Mfc0),
        .Mtc0(Mtc0)
        );
        
         always begin 
             #5 Opcode[5:0]=6'b000100;
             #0 Funtion_opcode[5:0]=6'b000000;//ָ�������λ
             #0 rs[4:0]=5'b00000;//bgez�Ǽ���ָ���õ�
         end
         
endmodule
