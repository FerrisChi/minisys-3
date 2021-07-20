`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
module control32 (
    // multicycle
    input           clock,
    input           reset,
    inout           Zero,
    output[1:0]     Wpc,                // 需要修改PC
    output          Wir,
    output          Waluresult,
    
    input	[5:0]   Opcode,				// 来自取指单元instruction[31..26]
    input	[5:0]   Function_opcode,	// 来自取指单元r-类型 instructions[5..0]
    input	[21:0]	Alu_resultHigh,
    output			Jrn,				// 为1表明当前指令是jr
    output			RegDST,				// 为1表明目的寄存器是rd，否则目的寄存器是rt
    output			ALUSrc,				// 为1表明第二个操作数是立即数（beq，bne除外）
    output			MemorIOtoReg,			// 为1表明需要从存储器读数据到寄存器
    output			RegWrite,			// 为1表明该指令需要写寄存器
    output			MemRead,
	output			MemWrite,			// 为1表明该指令需要写存储器
    output			IORead,
	output			IOWrite,
    output			Branch,				// 为1表明是Beq指令
    output			nBranch,			// 为1表明是Bne指令
    output			Jmp,				// 为1表明是J指令
    output			Jal,				// 为1表明是Jal指令
    output			I_format,			// 为1表明该指令是除beq，bne，LW，SW之外的其他I-类型指令
    output			Sftmd,				// 为1表明是移位指令
    output	[1:0]	ALUOp				// 是R-类型或I_format=1时位1为1, beq、bne指令则位0为1
);
   
    wire R_format;		// 为1表示是R-类型指令
    wire Lw;			// 为1表示是lw指令
    wire Sw;			// 为1表示是sw指令
    
    reg[1:0] wpc_reg;
    reg[2:0] state;
    reg[2:0] next_state;
    parameter [2:0] sinit = 3'b000, sif = 3'b001, sid = 3'b010, sexe = 3'b011, smem = 3'b100, swb = 3'b101;
   
    assign Wpc = wpc_reg;
   
    assign R_format = (Opcode==6'b000000)? 1'b1:1'b0;    	//--00h 
    assign RegDST = (state == swb && R_format == 1) ? 1'b1 : 1'b0;                               //说明目标是rd，否则是rt

    assign I_format = (Opcode[5:3]==3'b001)? 1'b1: 1'b0;
    assign Lw = (Opcode==6'b100011)? 1'b1:1'b0;
    assign Jal = (Opcode==6'b000011)? 1'b1:1'b0;
    assign Jrn = (R_format==1'b1 & Function_opcode==6'b001000)? 1'b1:1'b0;   
    assign RegWrite = ((state == sid && Jal == 1) || state == swb) ? 1'b1 : 1'b0;

    assign Sw = (Opcode==6'b101011)? 1'b1:1'b0;
    assign ALUSrc = I_format | Lw | Sw;
    assign Branch = (Opcode==6'b000100)? 1'b1:1'b0;
    assign nBranch = (Opcode==6'b000101)? 1'b1:1'b0;
    assign Jmp = (Opcode==6'b000010)? 1'b1:1'b0;		//????????????
    
    assign MemWrite = ((state == smem) && Sw == 1 && (Alu_resultHigh!=22'b1111111111111111111111))?1'b1:1'b0;
    assign MemorIOtoReg = (state == swb && Lw==1) ? 1'b1 : 1'b0;
	assign MemRead = ((Lw==1) && (Alu_resultHigh!=22'b1111111111111111111111))?1'b1:1'b0;
	assign IOWrite = ((state == smem) && (Alu_resultHigh==22'b1111111111111111111111))?1'b1:1'b0;
	assign IORead = ((Lw==1) && (Alu_resultHigh==22'b1111111111111111111111))?1'b1:1'b0;
	
	assign Sftmd = (R_format && Function_opcode[5:3] == 3'b000)? 1'b1: 1'b0;
	
    assign ALUOp = {(R_format || I_format),(Branch || nBranch)};  // 是R－type或需要立即数作32位扩展的指令1位为1,beq、bne指令则0位为1
    
    assign Wir = (state == sif);
    assign Waluresult = (state == sexe);
    
    always @* begin
        if(state == sif)
            wpc_reg <= 2'b01;
        else if(state == sid && (Jmp || Jal || Jrn))
            wpc_reg <= 2'b10;
        else if(state == sexe && ((Branch && Zero) || (nBranch && (!Zero))))
            wpc_reg <= 2'b11;
        else
            wpc_reg <= 2'b00;
    end
    
    always @ (posedge clock or posedge reset) begin
        if (reset) begin
            state <= sinit;
        end else begin
            state <= next_state;
        end
    end
    
    always @ * begin
       case(state) 
         sinit:begin  next_state = sif; end            
         sif:begin next_state = sid; end          
         sid:begin
             if(Jmp || Jrn || Jal)   //J型指令
                 next_state = sif;//下一状态变为取指
              else
                 next_state = sexe; //其他指令改为执行状态
         end
         sexe:begin
            if(Sw || Lw)
                next_state = smem;
            else if (Branch || nBranch)
                next_state = sif;
            else
                next_state = swb;            
         end
         smem: begin
            if(Lw)
                next_state = swb;
            else
                next_state = sif;
         end
         swb: begin next_state = sif; end
         default: begin next_state = sinit; end
        endcase
    end
endmodule
