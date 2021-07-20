`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2014/11/07 15:26:00
// Design Name: 
// Module Name: Execute32
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


module Execute32(
    read_data_1,
    read_data_2,
    Sign_extend,
    Function_opcode,
    Exe_opcode,
    ALUOp,
    Shamt,
    ALUSrc,
    I_format,
    Sftmd,
    MD,
    Mult,
    Multu,
    Div,
    Divu,
    Zero,
    EtZero,
    GtZero,
    LtZero,
    ALU_Result,
    Add_Result,
    ALU_Result_HI,
    ALU_Result_LO,
    PC_plus_4
    );
    
    input[31:0] read_data_1;
    input[31:0] read_data_2;
    input[31:0] Sign_extend;
    input[5:0]  Function_opcode;
    input[5:0]  Exe_opcode;
    input[1:0]  ALUOp; //暂时两位
    input[4:0]  Shamt;
    input       Sftmd;
    input       ALUSrc;
    input       I_format;
    input       MD;//乘除法相关信号
    input       Mult;
    input       Multu;
    input       Div;
    input       Divu;
    input[16:0] PC_plus_4;//地址位数待考量
   
    output          Zero;
    output          EtZero; //等于0
    output          GtZero; //大于0
    output          LtZero; //小于0
    
    output[31:0]    ALU_Result; 
    output[31:0]    ALU_Result_HI; //乘除法计算结果
    output[31:0]    ALU_Result_LO; 
    output[16:0]    Add_Result; //地址计算结果，位数待修改
    //待添加三个输出信号，=0，> 0，< 0
    
    reg[31:0]   ALU_Result;
    reg[31:0]   ALU_Result_HI;
    reg[31:0]   ALU_Result_LO;
    wire[31:0]  Ainput,Binput;
    reg[31:0]   Cinput,Dinput;  //六种移位指令的结果暂存器sll,srl
    reg[31:0]   Einput,Finput;  //sllv,srlv
    reg[31:0]   Ginput,Hinput;  //sra,srav
    reg[31:0]   Sinput;         //六种移位指令的最后结果
    reg[63:0]   MD_Result;
    reg[31:0]   ALU_output_mux; //除移位之外的结果暂存
    wire[17:0]  Branch_Add;     //算地址，位数待修改
    wire[2:0]   ALU_ctl;
    wire[5:0]   Exe_code;
    wire[2:0]   Sftm;           //移位指令的功能码，
    reg s;                      //算数移位时候用到
    
    assign  Sftm = Function_opcode[2:0];    //移位指令的功能码，实际上有用的只有低三位
    
    //为bne,beq等指令算地址,地址位数要注意
    assign  Branch_Add = PC_plus_4[16:2]+Sign_extend[16:0];
    assign  Add_Result = Branch_Add[16:0];
    //判断计算结果是否为0
    assign  Zero = (ALU_output_mux[31:0]==32'h00000000) ? 1'b1 : 1'b0;
    //赋值新添加的三个输出变量，不一定准确
    assign  EtZero = (Ainput[31:0]==32'h00000000) ?  1'b1 : 1'b0;
    assign  GtZero = ((Ainput[31]==1'b0)&(EtZero==0)) ?  1'b1 : 1'b0;
    assign  LtZero = (Ainput[31]==1'b1) ?  1'b1 : 1'b0;     //符号位为1，负数
    //待赋值三个输出信号
    
    //A B端口赋值
    assign  Ainput = read_data_1;
    assign  Binput = (ALUSrc==0) ? read_data_2 : Sign_extend[31:0];
    
    //Sll逻辑左移指令
    always @(Ainput or Binput or Shamt)
    begin
        case(Shamt)
        5'd0: Cinput[31:0] = Binput[31:0]; 
        5'd1: Cinput[31:0] = {Binput[30:0],1'b0};
        5'd2: Cinput[31:0] = {Binput[29:0],2'b00};
        5'd3: Cinput[31:0] = {Binput[28:0],3'b000}; 
        5'd4: Cinput[31:0] = {Binput[27:0],4'b0000};
        5'd5: Cinput[31:0] = {Binput[26:0],5'b00000};
        5'd6: Cinput[31:0] = {Binput[25:0],6'b000000};
        5'd7: Cinput[31:0] = {Binput[24:0],7'b0000000};
        5'd8: Cinput[31:0] = {Binput[23:0],8'b00000000};
        5'd9: Cinput[31:0] = {Binput[22:0],9'b000000000};
        5'd10: Cinput[31:0] = {Binput[21:0],10'b0000000000};
        5'd11: Cinput[31:0] = {Binput[20:0],11'b00000000000};
        5'd12: Cinput[31:0] = {Binput[19:0],12'b000000000000};
        5'd13: Cinput[31:0] = {Binput[18:0],13'b0000000000000};
        5'd14: Cinput[31:0] = {Binput[17:0],14'b00000000000000};
        5'd15: Cinput[31:0] = {Binput[16:0],15'b000000000000000};
        5'd16: Cinput[31:0] = {Binput[15:0],16'b0000000000000000};
        5'd17: Cinput[31:0] = {Binput[14:0],17'b00000000000000000};
        5'd18: Cinput[31:0] = {Binput[13:0],18'b000000000000000000};
        5'd19: Cinput[31:0] = {Binput[12:0],19'b0000000000000000000};
        5'd20: Cinput[31:0] = {Binput[11:0],20'b00000000000000000000};
        5'd21: Cinput[31:0] = {Binput[10:0],21'b000000000000000000000};
        5'd22: Cinput[31:0] = {Binput[9:0],22'b0000000000000000000000};
        5'd23: Cinput[31:0] = {Binput[8:0],23'b00000000000000000000000};
        5'd24: Cinput[31:0] = {Binput[7:0],24'b000000000000000000000000};
        5'd25: Cinput[31:0] = {Binput[6:0],25'b0000000000000000000000000};
        5'd26: Cinput[31:0] = {Binput[5:0],26'b00000000000000000000000000};
        5'd27: Cinput[31:0] = {Binput[4:0],27'b000000000000000000000000000};
        5'd28: Cinput[31:0] = {Binput[3:0],28'b0000000000000000000000000000};
        5'd29: Cinput[31:0] = {Binput[2:0],29'b00000000000000000000000000000};
        5'd30: Cinput[31:0] = {Binput[1:0],30'b000000000000000000000000000000};
        5'd31: Cinput[31:0] = {Binput[0],31'b0000000000000000000000000000000};
        default: Cinput[31:0] = Binput[31:0];
        endcase
    end
    
    //srl逻辑右移指令
    always @(Ainput or Binput or Shamt)
    begin
        case(Shamt)
        5'd0: Dinput[31:0] = Binput[31:0]; 
        5'd1: Dinput[31:0] = {1'b0,Binput[31:1]};
        5'd2: Dinput[31:0] = {2'b00,Binput[31:2]};
        5'd3: Dinput[31:0] = {3'b000,Binput[31:3]}; 
        5'd4: Dinput[31:0] = {4'b0000,Binput[31:4]};
        5'd5: Dinput[31:0] = {5'b00000,Binput[31:5]};
        5'd6: Dinput[31:0] = {6'b000000,Binput[31:6]};
        5'd7: Dinput[31:0] = {7'b0000000,Binput[31:7]};
        5'd8: Dinput[31:0] = {8'b00000000,Binput[31:8]};
        5'd9: Dinput[31:0] = {9'b000000000,Binput[31:9]};
        5'd10: Dinput[31:0] = {10'b0000000000,Binput[31:10]};
        5'd11: Dinput[31:0] = {11'b00000000000,Binput[31:11]};
        5'd12: Dinput[31:0] = {12'b000000000000,Binput[31:12]};
        5'd13: Dinput[31:0] = {13'b0000000000000,Binput[31:13]};
        5'd14: Dinput[31:0] = {14'b00000000000000,Binput[31:14]};
        5'd15: Dinput[31:0] = {15'b000000000000000,Binput[31:15]};
        5'd16: Dinput[31:0] = {16'b0000000000000000,Binput[31:16]};
        5'd17: Dinput[31:0] = {17'b00000000000000000,Binput[31:17]};
        5'd18: Dinput[31:0] = {18'b000000000000000000,Binput[31:18]};
        5'd19: Dinput[31:0] = {19'b0000000000000000000,Binput[31:19]};
        5'd20: Dinput[31:0] = {20'b00000000000000000000,Binput[31:20]};
        5'd21: Dinput[31:0] = {21'b000000000000000000000,Binput[31:21]};
        5'd22: Dinput[31:0] = {22'b0000000000000000000000,Binput[31:22]};
        5'd23: Dinput[31:0] = {23'b00000000000000000000000,Binput[31:23]};
        5'd24: Dinput[31:0] = {24'b000000000000000000000000,Binput[31:24]};
        5'd25: Dinput[31:0] = {25'b0000000000000000000000000,Binput[31:25]};
        5'd26: Dinput[31:0] = {26'b00000000000000000000000000,Binput[31:26]};
        5'd27: Dinput[31:0] = {27'b000000000000000000000000000,Binput[31:27]};
        5'd28: Dinput[31:0] = {28'b0000000000000000000000000000,Binput[31:28]};
        5'd29: Dinput[31:0] = {29'b00000000000000000000000000000,Binput[31:29]};
        5'd30: Dinput[31:0] = {30'b000000000000000000000000000000,Binput[31:30]};
        5'd31: Dinput[31:0] = {31'b0000000000000000000000000000000,Binput[31]};
        default: Dinput[31:0] = Binput[31:0];
        endcase
    end
    
    //Sllv逻辑左移指令
    always  @(Ainput or Binput or Shamt)
    begin
        case(Ainput[4:0])
        5'd0: Einput[31:0] = Binput[31:0]; 
        5'd1: Einput[31:0] = {Binput[30:0],1'b0};
        5'd2: Einput[31:0] = {Binput[29:0],2'b00};
        5'd3: Einput[31:0] = {Binput[28:0],3'b000}; 
        5'd4: Einput[31:0] = {Binput[27:0],4'b0000};
        5'd5: Einput[31:0] = {Binput[26:0],5'b00000};
        5'd6: Einput[31:0] = {Binput[25:0],6'b000000};
        5'd7: Einput[31:0] = {Binput[24:0],7'b0000000};
        5'd8: Einput[31:0] = {Binput[23:0],8'b00000000};
        5'd9: Einput[31:0] = {Binput[22:0],9'b000000000};
        5'd10: Einput[31:0] = {Binput[21:0],10'b0000000000};
        5'd11: Einput[31:0] = {Binput[20:0],11'b00000000000};
        5'd12: Einput[31:0] = {Binput[19:0],12'b000000000000};
        5'd13: Einput[31:0] = {Binput[18:0],13'b0000000000000};
        5'd14: Einput[31:0] = {Binput[17:0],14'b00000000000000};
        5'd15: Einput[31:0] = {Binput[16:0],15'b000000000000000};
        5'd16: Einput[31:0] = {Binput[15:0],16'b0000000000000000};
        5'd17: Einput[31:0] = {Binput[14:0],17'b00000000000000000};
        5'd18: Einput[31:0] = {Binput[13:0],18'b000000000000000000};
        5'd19: Einput[31:0] = {Binput[12:0],19'b0000000000000000000};
        5'd20: Einput[31:0] = {Binput[11:0],20'b00000000000000000000};
        5'd21: Einput[31:0] = {Binput[10:0],21'b000000000000000000000};
        5'd22: Einput[31:0] = {Binput[9:0],22'b0000000000000000000000};
        5'd23: Einput[31:0] = {Binput[8:0],23'b00000000000000000000000};
        5'd24: Einput[31:0] = {Binput[7:0],24'b000000000000000000000000};
        5'd25: Einput[31:0] = {Binput[6:0],25'b0000000000000000000000000};
        5'd26: Einput[31:0] = {Binput[5:0],26'b00000000000000000000000000};
        5'd27: Einput[31:0] = {Binput[4:0],27'b000000000000000000000000000};
        5'd28: Einput[31:0] = {Binput[3:0],28'b0000000000000000000000000000};
        5'd29: Einput[31:0] = {Binput[2:0],29'b00000000000000000000000000000};
        5'd30: Einput[31:0] = {Binput[1:0],30'b000000000000000000000000000000};
        5'd31: Einput[31:0] = {Binput[0],31'b0000000000000000000000000000000};
        default: Einput[31:0] = Binput[31:0];
        endcase
    end
    
    //srlv逻辑右移指令
    always  @(Ainput or Binput or Shamt)
    begin
        case(Ainput[4:0])
        5'd0: Finput[31:0] = Binput[31:0]; 
        5'd1: Finput[31:0] = {1'b0,Binput[31:1]};
        5'd2: Finput[31:0] = {2'b00,Binput[31:2]};
        5'd3: Finput[31:0] = {3'b000,Binput[31:3]}; 
        5'd4: Finput[31:0] = {4'b0000,Binput[31:4]};
        5'd5: Finput[31:0] = {5'b00000,Binput[31:5]};
        5'd6: Finput[31:0] = {6'b000000,Binput[31:6]};
        5'd7: Finput[31:0] = {7'b0000000,Binput[31:7]};
        5'd8: Finput[31:0] = {8'b00000000,Binput[31:8]};
        5'd9: Finput[31:0] = {9'b000000000,Binput[31:9]};
        5'd10: Finput[31:0] = {10'b0000000000,Binput[31:10]};
        5'd11: Finput[31:0] = {11'b00000000000,Binput[31:11]};
        5'd12: Finput[31:0] = {12'b000000000000,Binput[31:12]};
        5'd13: Finput[31:0] = {13'b0000000000000,Binput[31:13]};
        5'd14: Finput[31:0] = {14'b00000000000000,Binput[31:14]};
        5'd15: Finput[31:0] = {15'b000000000000000,Binput[31:15]};
        5'd16: Finput[31:0] = {16'b0000000000000000,Binput[31:16]};
        5'd17: Finput[31:0] = {17'b00000000000000000,Binput[31:17]};
        5'd18: Finput[31:0] = {18'b000000000000000000,Binput[31:18]};
        5'd19: Finput[31:0] = {19'b0000000000000000000,Binput[31:19]};
        5'd20: Finput[31:0] = {20'b00000000000000000000,Binput[31:20]};
        5'd21: Finput[31:0] = {21'b000000000000000000000,Binput[31:21]};
        5'd22: Finput[31:0] = {22'b0000000000000000000000,Binput[31:22]};
        5'd23: Finput[31:0] = {23'b00000000000000000000000,Binput[31:23]};
        5'd24: Finput[31:0] = {24'b000000000000000000000000,Binput[31:24]};
        5'd25: Finput[31:0] = {25'b0000000000000000000000000,Binput[31:25]};
        5'd26: Finput[31:0] = {26'b00000000000000000000000000,Binput[31:26]};
        5'd27: Finput[31:0] = {27'b000000000000000000000000000,Binput[31:27]};
        5'd28: Finput[31:0] = {28'b0000000000000000000000000000,Binput[31:28]};
        5'd29: Finput[31:0] = {29'b00000000000000000000000000000,Binput[31:29]};
        5'd30: Finput[31:0] = {30'b000000000000000000000000000000,Binput[31:30]};
        5'd31: Finput[31:0] = {31'b0000000000000000000000000000000,Binput[31]};
        default: Finput[31:0] = Binput[31:0];
        endcase
    end  
    
    //sra算数右移指令的执行
    always  @(Ainput or Binput or Shamt)
       begin
        s = Binput[31];
           case(Shamt)
           5'd0: Ginput[31:0] = Binput[31:0]; 
           5'd1: Ginput[31:0] = {s,Binput[31:1]};
           5'd2: Ginput[31:0] = {s,s,Binput[31:2]};
           5'd3: Ginput[31:0] = {s,s,s,Binput[31:3]}; 
           5'd4: Ginput[31:0] = {s,s,s,s,Binput[31:4]};
           5'd5: Ginput[31:0] = {s,s,s,s,s,Binput[31:5]};
           5'd6: Ginput[31:0] = {s,s,s,s,s,s,Binput[31:6]};
           5'd7: Ginput[31:0] = {s,s,s,s,s,s,s,Binput[31:7]};
           5'd8: Ginput[31:0] = {s,s,s,s,s,s,s,s,Binput[31:8]};
           5'd9: Ginput[31:0] = {s,s,s,s,s,s,s,s,s,Binput[31:9]};
           5'd10: Ginput[31:0] = {s,s,s,s,s,s,s,s,s,s,Binput[31:10]};
           5'd11: Ginput[31:0] = {s,s,s,s,s,s,s,s,s,s,s,Binput[31:11]};
           5'd12: Ginput[31:0] = {s,s,s,s,s,s,s,s,s,s,s,s,Binput[31:12]};
           5'd13: Ginput[31:0] = {s,s,s,s,s,s,s,s,s,s,s,s,s,Binput[31:13]};
           5'd14: Ginput[31:0] = {s,s,s,s,s,s,s,s,s,s,s,s,s,s,Binput[31:14]};
           5'd15: Ginput[31:0] = {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,Binput[31:15]};
           5'd16: Ginput[31:0] = {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,Binput[31:16]};
           5'd17: Ginput[31:0] = {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,Binput[31:17]};
           5'd18: Ginput[31:0] = {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,Binput[31:18]};
           5'd19: Ginput[31:0] = {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,Binput[31:19]};
           5'd20: Ginput[31:0] = {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,Binput[31:20]};
           5'd21: Ginput[31:0] = {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,Binput[31:21]};
           5'd22: Ginput[31:0] = {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,Binput[31:22]};
           5'd23: Ginput[31:0] = {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,Binput[31:23]};
           5'd24: Ginput[31:0] = {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,Binput[31:24]};
           5'd25: Ginput[31:0] = {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,Binput[31:25]};
           5'd26: Ginput[31:0] = {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,Binput[31:26]};
           5'd27: Ginput[31:0] = {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,Binput[31:27]};
           5'd28: Ginput[31:0] = {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,Binput[31:28]};
           5'd29: Ginput[31:0] = {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,Binput[31:29]};
           5'd30: Ginput[31:0] = {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,Binput[31:30]};
           5'd31: Ginput[31:0] = {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,Binput[31]};
           default: Ginput[31:0] = Binput[31:0];
           endcase
       end     

    //srav算数右移指令的执行
    always @(Ainput or Binput or Shamt)
       begin
           s = Binput[31];
           case(Ainput[4:0])
           5'd0: Hinput[31:0] = Binput[31:0]; 
           5'd1: Hinput[31:0] = {s,Binput[31:1]};
           5'd2: Hinput[31:0] = {s,s,Binput[31:2]};
           5'd3: Hinput[31:0] = {s,s,s,Binput[31:3]}; 
           5'd4: Hinput[31:0] = {s,s,s,s,Binput[31:4]};
           5'd5: Hinput[31:0] = {s,s,s,s,s,Binput[31:5]};
           5'd6: Hinput[31:0] = {s,s,s,s,s,s,Binput[31:6]};
           5'd7: Hinput[31:0] = {s,s,s,s,s,s,s,Binput[31:7]};
           5'd8: Hinput[31:0] = {s,s,s,s,s,s,s,s,Binput[31:8]};
           5'd9: Hinput[31:0] = {s,s,s,s,s,s,s,s,s,Binput[31:9]};
           5'd10: Hinput[31:0] = {s,s,s,s,s,s,s,s,s,s,Binput[31:10]};
           5'd11: Hinput[31:0] = {s,s,s,s,s,s,s,s,s,s,s,Binput[31:11]};
           5'd12: Hinput[31:0] = {s,s,s,s,s,s,s,s,s,s,s,s,Binput[31:12]};
           5'd13: Hinput[31:0] = {s,s,s,s,s,s,s,s,s,s,s,s,s,Binput[31:13]};
           5'd14: Hinput[31:0] = {s,s,s,s,s,s,s,s,s,s,s,s,s,s,Binput[31:14]};
           5'd15: Hinput[31:0] = {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,Binput[31:15]};
           5'd16: Hinput[31:0] = {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,Binput[31:16]};
           5'd17: Hinput[31:0] = {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,Binput[31:17]};
           5'd18: Hinput[31:0] = {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,Binput[31:18]};
           5'd19: Hinput[31:0] = {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,Binput[31:19]};
           5'd20: Hinput[31:0] = {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,Binput[31:20]};
           5'd21: Hinput[31:0] = {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,Binput[31:21]};
           5'd22: Hinput[31:0] = {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,Binput[31:22]};
           5'd23: Hinput[31:0] = {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,Binput[31:23]};
           5'd24: Hinput[31:0] = {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,Binput[31:24]};
           5'd25: Hinput[31:0] = {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,Binput[31:25]};
           5'd26: Hinput[31:0] = {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,Binput[31:26]};
           5'd27: Hinput[31:0] = {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,Binput[31:27]};
           5'd28: Hinput[31:0] = {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,Binput[31:28]};
           5'd29: Hinput[31:0] = {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,Binput[31:29]};
           5'd30: Hinput[31:0] = {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,Binput[31:30]};
           5'd31: Hinput[31:0] = {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,Binput[31]};
           default: Hinput[31:0] = Binput[31:0];
           endcase
    end  
 
    //根据移位指令的功能码，最终决定移位结果取上述六个中的一个
    always  @(*)
    begin
        case(Sftm[2:0])
        3'b000 : Sinput = Cinput;
        3'b010 : Sinput = Dinput;
        3'b100 : Sinput = Einput;
        3'b110 : Sinput = Finput;
        3'b011 : Sinput = Ginput;
        3'b111 : Sinput = Hinput;
        default: Sinput = Binput;
        endcase
    end
    
    //算指令组合码，待修改
    assign  Exe_code = (I_format==0) ? Function_opcode : {3'b000,Exe_opcode[2:0]};
    assign  ALU_ctl[0] = (Exe_code[0]|Exe_code[3]) & ALUOp[1]; 
    assign  ALU_ctl[1] = ((!Exe_code[2])|(!ALUOp[1])); 
    assign  ALU_ctl[2] = (Exe_code[1] & ALUOp[1]) | ALUOp[0]; 
    
    //处理各类运算,乘除法还未添加
    always @ (ALU_ctl or Ainput or Binput or Exe_code)
    begin
        case(ALU_ctl)//还会需要修改的
        3'b000: ALU_output_mux = Ainput & Binput;
        3'b001: ALU_output_mux = Ainput | Binput;
        3'b010: ALU_output_mux = Ainput + Binput;
        3'b011: ALU_output_mux = Ainput + Binput;
        3'b100: ALU_output_mux = Ainput ^ Binput;
        3'b101: ALU_output_mux = ~(Ainput | Binput);
        3'b110: ALU_output_mux = Ainput - Binput;
        3'b111: ALU_output_mux = Ainput - Binput;
        default: ALU_output_mux = 32'h00000000;
        endcase
    end
    
    always  @(Ainput or Binput or Function_opcode or Exe_code) //乘除法操作，暂时写为如此,有错误（illegal expression in target），有符号数需要进一步改进
    begin
        if(Mult==1) 
            MD_Result[63:0] = Ainput*Binput;
        else if(Multu==1) 
            MD_Result[63:0] = Ainput*Binput;
        else if(Div==1) 
            begin
            MD_Result[63:32] = Ainput%Binput;
            MD_Result[31:0] = Ainput/Binput;
            end
        else if(Divu==1) 
            begin
            MD_Result[63:32] = Ainput%Binput;        
            MD_Result[31:0] = Ainput/Binput;
            end
    end
    //给最终结果赋值，判断条件还需要再修改
    always  @(Ainput or Binput or MD_Result or ALU_output_mux or Sinput)
    begin 
        ALU_Result_HI[31:0] = MD_Result[63:32];
        ALU_Result_LO[31:0] = MD_Result[31:0];
        if(((ALU_ctl == 3'b111)&&(Exe_code[3]==1))||((ALU_ctl[2:1]==2'b11)&&(I_format==1))) //处理slt类指令
            ALU_Result = {31'b0000000000000000000000000000000,ALU_output_mux[31]};
        else if((ALU_ctl == 3'b101) && (I_format==1))   //处理lui指令
            ALU_Result = {Binput[15:0],16'b0000000000000000};
        else if(Sftmd == 1) //移位指令
            ALU_Result = Sinput;
        else    //其他情况下结果就是运算得值
            ALU_Result = ALU_output_mux[31:0];
    end
       
endmodule
