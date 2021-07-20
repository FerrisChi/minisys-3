`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2014/11/27 12:30:41
// Design Name: 
// Module Name: Minisys_sim
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


module all_sim(
    );
        //input
           reg reset=0;
           reg clock=1;//��λ ʱ���ź�
           reg int0,int1;
           reg[3:0] col;
           wire[3:0] line;
           reg prst;		//��ť��λ�ź�
           
        //output
             wire [31:0]instruction_out;
             wire [16:0]PC_plus_4_out;
             wire [16:0]PC_out;
             wire [16:0]opcplus4_out;
             
             wire Jrn_out;
             wire RegDST_out;//Ŀ�ļĴ���ѡ�� 1��rd  2:rt
             wire ALUSrc_out;//�ڶ���������������������Beq,Bne��    
             wire MemtoReg_out;//�洢�����鵽�Ĵ���(lw)
             wire Lw_out;
             wire Lb_out;
             wire Lbu_out;
             wire Lh_out;
             wire Lhu_out;   
             wire MemWrite_out;//д�洢��
             wire Sw_out;
             wire Sb_out;
             wire Sh_out; 
             wire RegWrite_out;//д�Ĵ���
             wire Branch_out;//Beq
             wire nBranch_out;//Bne
             wire bgez_out;
             wire bgtz_out;
             wire blez_out;
             wire bltz_out;
             wire bgezal_out; 
             wire bltzal_out;
             wire Jmp_out;//J
             wire Jal_out;//Jal
             wire Jalr_out;//Jalr  
             wire Sftmd_out;//��λָ��
             wire MD_out;//�˳���
             wire Mult_out;
             wire Multu_out;
             wire Div_out;
             wire Divu_out;
             wire I_format_out;//��beq,bne,LW,SW֮���I-��ָ��
             wire[1:0] ALUOp_out; 
             //��ȡHI��LO
             wire Mfhi_out;//ȡ
             wire Mflo_out;
             wire Mthi_out;//��
             wire Mtlo_out;   
             wire break1_out;
             wire syscall_out;
             wire eret_out;
             //C0�Ĵ������ָ��
             wire Mfc0_out;
             wire Mtc0_out;
             //IO
             wire MemorIOtoReg_out;
             wire IOWrite_out;
             wire IORead_out;
             
             //���뵥Ԫ
              wire[31:0] read_data_1_out;
              wire[31:0] read_data_2_out;
              wire[31:0] Sign_extend_out;
              wire[31:0] read_data_out;
              wire[31:0] write_data_out_idcode;
              wire[4:0] write_register_address_out;
             
             //ִ��
             wire[31:0]  ALU_result_out;
             wire[31:0]  ALU_result_HI_out;    
             wire[31:0]  ALU_result_LO_out;
             wire Zero_out;
             wire EtZero_out;
             wire GtZero_out;
             wire LtZero_out;
             
             //�ж�
             wire[15:0]ioread_data_out;
             wire[15:0] ioread_data_key_out;
             wire[15:0] ioread_data_ctc_out;
             wire[15:0] ioread_data_uart_out; 
         
             //led16
             wire[6:0]      led0;
             wire[6:0]      led1;
             wire[6:0]      led2;
             wire[6:0]      led3;
             
             //pmw16
            wire pwm;        //��������ź�
            //uart16
                reg xtal;
                reg rxd;
                wire txd;
            //kanmengou
            wire rst;
                                     
          //ʵ����
            minisys minisys1(
                 .clock(clock),
                 .reset(reset),
                 .prst(prst),		//��ť��λ�ź�
                 .int0(int0),
                 .int1(int1),
                 .instruction_out(instruction_out),
                 .PC_plus_4_out(PC_plus_4_out),
                 .PC_out(PC_out),
                 .Jrn_out(Jrn_out),
                 .RegDST_out(RegDST_out),
                 .ALUSrc_out(ALUSrc_out),
                 .MemtoReg_out(MemtoReg_out),
                 .Lw_out(Lw_out),
                 .Lb_out(Lb_out),
                 .Lbu_out(Lbu_out),
                 .Lh_out(Lh_out),
                 .Lhu_out(Lhu_out),
                 .MemWrite_out(MemWrite_out),
                 .Sw_out(Sw_out),
                 .Sb_out(Sb_out),
                 .Sh_out(Sh_out),
                 .RegWrite_out(RegWrite_out),
                 .Branch_out(Branch_out),
                 .nBranch_out(nBranch_out),
                 .bgez_out(bgez_out),
                 .bgtz_out(bgtz_out),
                 .blez_out(blez_out),
                 .bltz_out(bltz_out),
                 .bgezal_out(bgezal_out),
                 .bltzal_out(bltzal_out),
                 .Jmp_out(Jmp_out),
                 .Jal_out(Jal_out),
                 .Jalr_out(Jalr_out),
                 .Sftmd_out(Sftmd_out),
                  .MD_out(MD_out),
                  .Mult_out(Mult_out),
                  .Multu_out(Multu_out),
                  .Div_out(Div_out),
                  .Divu_out(Divu_out),
                 .I_format_out(I_format_out),
                 .ALUOp_out(ALUOp_out),
                 .Mfhi_out(Mfhi_out),
                 .Mflo_out(Mflo_out),
                 .Mthi_out(Mthi_out),
                 .Mtlo_out(Mtlo_out),
                 .break1_out(break1_out),
                 .syscall_out(syscall_out),
                 .eret_out(eret_out),
                 .Mfc0_out(Mfc0_out),
                 .Mtc0_out(Mtc0_out),
                 .MemorIOtoReg_out(MemorIOtoReg_out),
                 .IOWrite_out(IOWrite_out),
                 .IORead_out(IORead_out),           
                 .read_data_1_out(read_data_1_out),
                 .read_data_2_out(read_data_2_out),
                 .Sign_extend_out(Sign_extend_out),
                 .read_data_out(read_data_out),
                 .ALU_result_out(ALU_result_out),
                 .ALU_result_HI_out(ALU_result_HI_out),    
                 .ALU_result_LO_out(ALU_result_LO_out),
                 .Zero_out(Zero_out),
                 .EtZero_out(EtZero_out),
                 .GtZero_out(GtZero_out),
                 .LtZero_out(LtZero_out),
                 .write_data_out_idcode(write_data_out_idcode),
                 .write_register_address_out(write_register_address_out),
                 .opcplus4_out(opcplus4_out),
                 .ioread_data_out(ioread_data_out),
                 .ioread_data_key_out(ioread_data_key_out),
                 .ioread_data_ctc_out(ioread_data_ctc_out),
                 .ioread_data_uart_out(ioread_data_uart_out),
                 .col(col),
                 .line(line),
                 .pwm(pwm),
                 .xtal(xtal),
                 .rxd(rxd),
                 .txd(txd),
                 .rst(rst),
                 .led0(led0),
                 .led1(led1),
                 .led2(led2),
                 .led3(led3)
                 );

          
        //�źų�ʼ��
        initial begin
         #40 reset=1;
         #40 reset =0;
         //# int0
         //# int1;
         end
         
       always begin
        #20 clock=~clock;
        end
        
endmodule
