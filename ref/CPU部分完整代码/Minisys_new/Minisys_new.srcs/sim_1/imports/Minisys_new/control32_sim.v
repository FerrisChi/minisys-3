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
    //输入
    reg[5:0] Opcode;//指令最高六位
    reg[5:0] Funtion_opcode;//指令最低六位
    reg[4:0] rs;//bgez那几条指令用到
    
    //输出
    wire Jrn;  //Jr
    wire RegDST;//目的寄存器选择 1：rd  2:rt
    wire ALUSrc;//第二操作数是立即数（除了Beq,Bne）    
    wire MemtoReg;//存储器读书到寄存器(lw)
    wire Lw;
    wire Lb;
    wire Lbu;
    wire Lh;
    wire Lhu;   
    wire MemWrite;//写存储器
    wire Sw;
    wire Sb;
    wire Sh; 
    wire RegWrite;//写寄存器
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
    wire Sftmd;//移位指令
    wire MD;//乘除法
    wire I_format;//除beq,bne,LW,SW之外的I-型指令
    wire[1:0] ALUOp; 
    //存取HI、LO
    wire Mfhi;//取
    wire Mflo;
    wire Mthi;//存
    wire Mtlo;   
    wire break1;
    wire syscall;
    wire eret;
    //C0寄存器相关指令
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
             #0 Funtion_opcode[5:0]=6'b000000;//指令最低六位
             #0 rs[4:0]=5'b00000;//bgez那几条指令用到
         end
         
endmodule
