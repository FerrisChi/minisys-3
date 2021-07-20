`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2014/11/13 13:24:41
// Design Name: 
// Module Name: minisys
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

module minisys(
       clock,
       reset,
       instruction_out,
       PC_plus_4_out,
       PC_out,
       Jrn_out,
       RegDST_out,
       ALUSrc_out,
       MemtoReg_out,
       Lw_out,
       Lb_out,
       Lbu_out,
       Lh_out,
       Lhu_out,
       MemWrite_out,
       Sw_out,
       Sb_out,
       Sh_out,
       RegWrite_out,
       Branch_out,
       nBranch_out,
       bgez_out,
       bgtz_out,
       blez_out,
       bltz_out,
       bgezal_out,
       bltzal_out,
       Jmp_out,
       Jal_out,
       Jalr_out,
       Sftmd_out,
       MD_out,
       I_format_out,
       ALUOp_out,
       Mfhi_out,
       Mflo_out,
       Mthi_out,
       Mtlo_out,
       break1_out,
       syscall_out,
       eret_out,
       Mfc0_out,
       Mtc0_out,
       Mult_out,
       Multu_out,
       Div_out,
       Divu_out,
       read_data_1_out,
       read_data_2_out,
       Sign_extend_out,
       read_data_out,
       Zero_out,
       EtZero_out,
       GtZero_out,
       LtZero_out,
       ALU_result_out,
       ALU_result_HI_out,    
       ALU_result_LO_out,
       write_data_out_idcode,
       write_register_address_out,
       opcplus4_out,
       MemorIOtoReg_out,
       IOWrite_out,
       IORead_out,
       int0,
       int1,
       ioread_data_out,
       ioread_data_key_out,
       ioread_data_ctc_out,
       ioread_data_uart_out,
       led0,
       led1,
       led2,
       led3,
       col,
       pulse0,
       pulse1,
       cout0,
       cout1,
       line,
       xtal,
       rxd,
       txd,
       rst,
       pwm,
       prst,	//按钮复位信号
       registerq_out,
       registerr_out,
       intPC_out
       );
       
       //输入
       input clock;
       input reset;
       input prst;
       input int0,int1;
       input[3:0] col;
       output[3:0]line;
       
       //输出
       //取指
       output[31:0] instruction_out;
       output[16:0] PC_plus_4_out;
       output[16:0] PC_out;
       output[16:0]opcplus4_out;
       
       //控制单元
       output Jrn_out;
       output RegDST_out;
       output ALUSrc_out;
       output MemtoReg_out;
       output Lw_out;
       output Lb_out;
       output Lbu_out;
       output Lh_out;
       output Lhu_out;
       output MemWrite_out;
       output Sw_out;
       output Sb_out;
       output Sh_out;
       output RegWrite_out;
       output Branch_out;
       output nBranch_out;
       output bgez_out;
       output bgtz_out;
       output blez_out;
       output bltz_out;
       output bgezal_out;
       output bltzal_out;
       output Jmp_out;
       output Jal_out;
       output Jalr_out;
       output Sftmd_out;
       output MD_out;
       output I_format_out;
       output[1:0] ALUOp_out;
       output Mfhi_out;
       output Mflo_out;
       output Mthi_out;
       output Mtlo_out;
       output break1_out;
       output syscall_out;
       output eret_out;
       output Mfc0_out;
       output Mtc0_out;
       output Mult_out;
       output Multu_out;
       output Div_out;
       output Divu_out;
       output MemorIOtoReg_out;
       output IOWrite_out;
       output IORead_out;
       //译码单元
       output[31:0] read_data_1_out; 
       output[31:0] read_data_2_out;
       output[31:0] Sign_extend_out;
       output[31:0] read_data_out;
       output[31:0] write_data_out_idcode;
       output[4:0] write_register_address_out;
       
       //执行单元
       output[31:0]  ALU_result_out;
       output[31:0]  ALU_result_HI_out;    
       output[31:0]  ALU_result_LO_out;
       output Zero_out;
       output EtZero_out;
       output GtZero_out;
       output LtZero_out;
       
       //中断
       output[15:0]ioread_data_out;
       output[15:0] ioread_data_key_out;
       output[15:0] ioread_data_ctc_out;
       output[15:0] ioread_data_uart_out; 
       output[31:0] registerq_out;
       output[31:0] registerr_out;
       output[16:0] intPC_out;
       //LED16
       output[6:0] led0;//LG
       output[6:0] led1;
       output[6:0] led2;
       output[6:0] led3;
       //ctc16
       input pulse0;
       input pulse1;
       output cout0;
       output cout1;
       //pmw16
       output pwm;        //输出方波信号
       //uart16
       input xtal;
       input rxd;
       output txd;
       //看门狗
       output  rst;        //输出的复位信号
       
       //中间线
       //取指令
       wire[31:0] instruction;
       wire[16:0] pc_plus_4;
       wire[16:0] pc;
       wire[16:0] opcplus4;   //JAL的跳转地址
       //控制单元
       wire Jrn;
       wire RegDST;
       wire ALUSrc;
       wire MemtoReg;
       wire Lw;
       wire Lb;
       wire Lbu;
       wire Lh;
       wire Lhu;
       wire MemWrite;
       wire Sw;
       wire Sb;
       wire Sh;
       wire RegWrite;
       wire Branch;
       wire nBranch;
       wire bgez;
       wire bgtz;
       wire blez;
       wire bltz;
       wire bgezal;
       wire bltzal;
       wire Jmp;
       wire Jal;
       wire Jalr;
       wire Sftmd;
       wire MD;
       wire I_format;
       wire[1:0] ALUOp;
       wire Mfhi;
       wire Mflo;
       wire Mthi;
       wire Mtlo;
       wire break1;
       wire syscall;
       wire eret;
       wire Mfc0;
       wire Mtc0;
       wire Mult;
       wire Multu;
       wire Div;
       wire Divu;
       wire MemorIOtoReg;
       wire IOWrite;
       wire IORead;
    
       //译码单元
       wire[31:0] read_data_1;
       wire[31:0] read_data_2;
       wire[31:0] Sign_extend;
       wire[31:0] read_data;
       wire[31:0] write_data_out1;
       wire[4:0]  write_register_address;
       
       //执行单元
        wire[31:0]  alu_result;
        wire[31:0]  alu_result_hi;    
        wire[31:0]  alu_result_lo;
        wire[16:0]  add_result;
        wire Zero;
        wire EtZero;
        wire GtZero;
        wire LtZero;
        
        //接口部分的wire
       wire[15:0] ioread_data;//IO来的数据。
       wire[31:0] rdata;//来自存储器或者IO->寄存器
       wire[31:0] write_data;//写到IO或者存储器
       wire[15:0] ioread_data_key;
       wire[15:0] ioread_data_ctc;
       wire[15:0] ioread_data_uart;  
       wire[16:0] address;
              wire ledctrl;
              wire keyctrl;
              wire ctcctrl;
              wire pwmctrl;
              wire uartctrl;
              wire wdtctrl;
              wire swctrl;
              wire dispctrl;
       //中断
       wire int0,int1;
       wire[1:0] imask;
       wire[16:0] intPC;
       wire[4:0]  read_register_1_address;
       
       
      //output 赋值
       assign instruction_out=instruction;
       assign PC_plus_4_out=pc_plus_4;
       assign PC_out=pc;
       assign opcplus4_out=opcplus4;
       
       assign Jrn_out=Jrn;
       assign RegDST_out=RegDST;
       assign ALUSrc_out=ALUSrc;
       assign MemtoReg_out=MemtoReg;
       assign Lw_out=Lw;
       assign Lb_out=Lb;
       assign Lbu_out=Lbu;
       assign Lh_out=Lh;
       assign Lhu_out=Lhu;
       assign MemWrite_out=MemWrite;
       assign Sw_out=Sw;
       assign Sb_out=Sb;
       assign Sh_out=Sh;
       assign RegWrite_out=RegWrite;
       assign Branch_out=Branch;
       assign nBranch_out=nBranch;
       assign bgez_out=bgez;
       assign bgtz_out=bgtz;
       assign blez_out=blez;
       assign bltz_out=bltz;
       assign bgezal_out=bgezal;
       assign bltzal_out=bltzal;    
       assign Jmp_out=Jmp;
       assign Jal_out=Jal;
       assign Jalr_out=Jalr;
       assign Sftmd_out=Sftmd;
       assign MD_out=MD;
       assign I_format_out=I_format;
       assign ALUOp_out=ALUOp;
       assign Mfhi_out=Mfhi;
       assign Mflo_out=Mflo;
       assign Mthi_out=Mthi;
       assign Mtlo_out=Mtlo;
       assign break1_out=break1;
       assign syscall_out=syscall;
       assign eret_out=eret;
       assign Mfc0_out=Mfc0;
       assign Mtc0_out=Mtc0;
       assign Mult_out=Mult;
       assign Multu_out=Multu;
       assign Div_out=Div;
       assign Divu_out=Divu;
       assign MemorIOtoReg_out=MemorIOtoReg;
       assign IOWrite_out=IOWrite;
       assign IORead_out=IORead;
       
       //译码单元
       assign read_data_1_out=read_data_1;
       assign read_data_2_out=read_data_2;
       assign Sign_extend_out=Sign_extend;
       assign read_data_out=read_data;
       assign write_data_out_idcode=write_data_out1;
       assign write_register_address_out=write_register_address;
            
         
       //执行单元
       assign ALU_result_out=alu_result;
       assign ALU_result_HI_out=alu_result_hi;    
       assign ALU_result_LO_out=alu_result_lo;
       assign Zero_out=Zero;
       assign EtZero_out=EtZero;
       assign GtZero_out=GtZero;
       assign LtZero_out=LtZero;
       
       //RAM
       assign write_data_out=(MemtoReg==1)?read_data:alu_result;
       //中断接口
       assign ioread_data_out=ioread_data;
       assign ioread_data_key_out=ioread_data_key;
       assign ioread_data_ctc_out=ioread_data_ctc;
       assign ioread_data_uart_out=ioread_data_uart; 
       assign intPC_out=intPC;


//取指单元
       Ifect32 ifetch(
          .Instrution(instruction),
          .PC_plus_4_out(pc_plus_4),
          .Add_result(add_result),     //来自执行单元
          .read_data_1(read_data_1),   //rs->pc
          .nBranch(nBranch),
          .Branch(Branch),
          .bgez(bgez),
          .bgtz(bgtz),
          .blez(blez),
          .bltz(bltz),
          .bgezal(bgezal), 
          .bltzal(bltzal),
          .Jmp(Jmp),
          .Jal(Jal),
          .Jrn(Jrn),
          .Zero(Zero),
          .EtZero(EtZero),
          .GtZero(GtZero),
          .LtZero(LtZero),
          .PC_out(pc),
          .clock(clock),
          .reset(reset),
          .opcplus4(opcplus4),
          .Jalr(Jalr),
         .int0(int0),
         .int1(int1),
          .intPC(intPC),
          .imask(imask),
          .read_register_1_address(read_register_1_address)
        );

//控制单元 
       control32 control(
            .Opcode(instruction[31:26]),
            .Funtion_opcode(instruction[5:0]),
            .rs(instruction[20:16]),
            .Alu_result(alu_result),
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
            .Mtc0(Mtc0),
            .Mult(Mult),
            .Multu(Multu),
            .Div(Div),
            .Divu(Divu),
            .MemorIOtoReg(MemorIOtoReg),
            .IOWrite(IOWrite),
            .IORead(IORead)
            );
            
//译码单元
          Idecode32 idecode(
               .read_data_1(read_data_1),
               .read_data_2(read_data_2),
               .Instruction(instruction),
               .read_data(read_data),
               .ALU_result(alu_result),
               .ALU_result_HI(alu_result_hi),
               .ALU_result_LO(alu_result_lo),
               .Jal(Jal),
               .Jalr(Jalr),
               .bgezal(bgezal),
               .bltzal(bltzal),
               .mfhi(Mfhi),
               .mflo(Mflo),
               .mthi(Mthi),
               .mtlo(Mtlo),
               .Lw(Lw),
               .Lb(Lb),
               .Lbu(Lbu),
               .Lh(Lh),
               .Lhu(Lhu),
               .Sw(Sw),
               .Sb(Sb), 
               .Sh(Sh),
               .MD(MD),
               .RegWrite(RegWrite),
               .MemtoReg(MemtoReg),
               .RegDst(RegDST),
               .Sign_extend(Sign_extend),
               .clock(clock),
               .reset(reset),
               .opcplus4(opcplus4),
               .write_data_out(write_data_out1),
               .write_register_address_out(write_register_address),
               .int0(int0),
               .int1(int1),
               .intPC(intPC),
               .imask(imask),
               .read_register_1_address(read_register_1_address),
               .registerq_out(registerq_out),
               .registerr_out(registerr_out)
            );
 //执行单元
       Execute32 execute(
                     .read_data_1(read_data_1),
                     .read_data_2(read_data_2),
                     .Sign_extend(Sign_extend),
                     .Function_opcode(instruction[5:0]),
                     .Exe_opcode(instruction[31:26]),
                     .ALUOp(ALUOp),
                     .Shamt(instruction[10:6]),
                     .ALUSrc(ALUSrc),
                      .I_format(I_format),
                      .Sftmd(Sftmd),
                      .MD(MD),
                      .Mult(Mult),
                      .Multu(Multu),
                      .Div(Div),
                      .Divu(Divu),
                     .Zero(Zero),
                     .EtZero(EtZero),
                     .GtZero(GtZero),
                     .LtZero(LtZero),
                     .ALU_Result(alu_result),
                     .Add_Result(add_result),
                     .ALU_Result_HI(alu_result_hi),
                     .ALU_Result_LO(alu_result_lo),
                     .PC_plus_4(pc_plus_4)
                     );
           
 /*RAm(添加接口之前的RAMyy|zyl)
     dmemory32 dmemory( 
     .read_data(read_data),
     .address(alu_result[16:0]),
     .write_data(read_data_2),
     .MemWrite(MemWrite),
     .clock(clock)
     );*/
      //RAM
         dmemory32 dmemory( 
         .read_data(read_data),
         .address(address),
         .write_data(read_data_2),
         .MemWrite(MemWrite),
         .clock(clock)
         );
         
         memorio memio(.caddress(alu_result[16:0]),
                       .address(address),
                       .memread(MemtoReg),
                       .memwrite(MemWrite),
                       .ioread(IORead), 
                       .iowrite(IOWrite),
                       .mread_data(read_data),
                       .ioread_data(ioread_data),
                       .wdata(read_data_2),
                       .rdata(rdata),
                       .write_data(write_data),
                       .LEDCtrl(ledctrl),
                       .KEYCtrl(keyctrl),
                       .CTCCtrl(ctcctrl),
                       .PWMCtrl(pwmctrl),
                       .UARTCtrl(uartctrl),
                       .WDTCtrl(wdtctrl),
                       .DISPCtrl(dispctrl),
                       .SWCtrl(swctrl));
                       
ioread multiioread(.reset(reset),
                   .clk(clock),
                   .ior(ioread),
                   .keyctrl(keyctrl),
                   .ctcctrl(ctcctrl),
                   .uartctrl(uartctrl),
                   .ioread_data(ioread_data),
                   .ioread_data_key(ioread_data_key),
                   .ioread_data_ctc(ioread_data_ctc),
                   .ioread_data_uart(ioread_data_uart));   
/*                 
disp16 disp(.reset(reset),
          .data(write_data[15:0]),
          .cs(dispctrl),
           .iow(iowrite),
           .led0(led0),
           .led1(led1),
           .led2(led2),
           .led3(led3));
   */        
 /*       
 key16 key(.reset(reset),
             .cs(keyctrl),
             .clk(clock),
             .ior(ioread),
             .address(address[1:0]),
             .col(col),
             .line(line),
             .ioread_data(ioread_data_key));*/
  /*           
ctc16 ctc(             .reset(reset),
                       .clk(clock),
                       .cs(ctcctrl),
                       .iow(iowrite),
                       .ior(ioread),
                       .pulse0(pulse0),
                       .pulse1(pulse1),
                       .address(address[3:0]),
                       .iowrite_data(write_data[15:0]),
                       .ioread_data(ioread_data_ctc),
                       .cout0(cout0),
                       .cout1(cout1));    
                       
                       
 pwm16 pwmcontrol(.reset(reset),
                                        .address(address[2:0]),
                                        .data(write_data[15:0]),
                                        .cs(pwmctrl),
                                        .clk(clock),
                                        .iow(iowrite),
                                        .pwm(pwm));  
                                        
 uart16 uart(.reset(reset),
                                                  .clk(clock),
                                                  .cs(uartctrl),
                                                  .iow(iowrite),
                                                  .ior(ioread),
                                                  .xtal(xtal),
                                                  .address(address[1:0]),
                                                  .iowrite_data(write_data[7:0]),
                                                  .ioread_data(ioread_data_uart),
                                                  .txd(txd),
                                                  .rxd(rxd));

wtd16 wtd(.reset(reset),
          .clk(clock),
          .cs(wdtctrl),
          .iow(iowrite),
          .data(write_data[15:0]),
          .rst(rst));
          
          
init32 init(.prst(prst),
            .rst(rst),
            .clk(clock),
            .reset(reset));  */  
                           
endmodule
















































