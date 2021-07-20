#ifndef ASM_TRANSLATE_H
#define ASM_TRANSLATE_H

#pragma once
#include "ASM_TRANSLATE.h"
//#include "TestSemCodeReg.h"
#include "StdAfx.h"



/*ASM代码翻译*/

/*一些宏*/
#define ON_REG 0
#define ON_MEM 1
#define ON_IMM 2 //取得变量信息类型
#define ON_LAB 3 //标签
#define ON_ERR 4 //不能使用
typedef struct
{
	int H16;
	int L16;
}IMM_INT;//拆分的整数


class INF_VAR //新信息变量
{
public:
	int type;
	VarPlace VP;//MEM变量
	string REG;//寄存器
	IMM_INT IMM;//立即数
	string LAB;//标签
	INF_VAR()
	{
		type=ON_ERR;
		IMM.H16=0;
		IMM.L16=0;
		REG="";
		LAB="";
	}
	INF_VAR(const INF_VAR & IV)
	{
		type=IV.type;
		REG=IV.REG;
		IMM=IV.IMM;
		VP=IV.VP;
		LAB=IV.LAB;
	}
};
IMM_INT SplitImmInt32(unsigned int i32) //32位整数分解
{
	IMM_INT IM;IM.H16=0;IM.L16=0;
	IM.L16=i32&0x0000FFFF;
	IM.H16=i32>>16;
	return IM;
}

int CombineIMMINT(IMM_INT II)
{
	int a=II.H16;
	a<<=16;
	a+=II.L16;
	return a;
}

string HexTrans(int n)//16位有效
{
	string s="";
	if(n>=-32768&&n<=65535)
	{
		IMM_INT II=SplitImmInt32(n);
		char a[10];
		_itoa_s(II.L16,a,16);
		//修改0x为后加H
		//a[0]='0';
		//a[1]='0';
		s="0";s+=a;s+="H";
	}
	else
	{
		s="0FFFFH";
	}
	return s;
}
void HexTrans(int n,char b[10])
{
	string s="";
	if(n>=-32768&&n<=65535)
	{
		IMM_INT II=SplitImmInt32(n);
		char a[10];
		_itoa_s(II.L16,a,16);
		//修改0x为后加H
		//a[0]='0';
		//a[1]='0';
		s="0";s+=a;s+="H";
	}
	else
	{
		s="0FFFFH";
	}
	int len=s.length();
	if(len<10)
	{
		b[len]='\0';
		for(int i=0;i<len;i++)
		{
			b[i]=s[i];
		}
	}
	else
	{
		b[0]='0';
		b[1]=b[2]=b[3]=b[4]=b[5]='F';
		b[6]='\0';
	}
}

INF_VAR Convert_OpNumRM_INF_VAR(const OpNumRM &ONR)//转换为更好读的方式
{
	INF_VAR IV;
	if(ONR.isReg)
	{
		IV.type=ON_REG;
		IV.REG=ONR.REG;
		return IV;
	}
	else
	{
		if(ONR.ON.isLabel)
		{
			IV.type=ON_LAB;
			IV.LAB=ONR.ON.label;
			return IV;
		}
		else
		{
			if(ONR.ON.Var.IsImmNum)
			{
				//拆解立即数
				IV.type=ON_IMM;
				IV.IMM=SplitImmInt32(ONR.ON.Var.imm_num);//分解32位整数
				return IV;
			}
			else
			{
				if(ONR.ON.Var.IsTempVar)
				{
					err_lst<<"转换操作数错误!"<<"\r\n";
				}
				else
				{
					IV.type=ON_MEM;
					IV.VP=ONR.ON.Var.VP;
					return IV;
				}
			}
		}
	}
	return IV;
}




void MOV_Translate(QER_ASM &QEA,vector<string> &asm_row) //MOV翻译 1
{
	asm_row.clear();//先清除
	string s;//=";";
	//s+=ConvertQuadCode(QEA);asm_row.push_back(s);
	s="";
	INF_VAR I_RS,I_RD;
	I_RS=Convert_OpNumRM_INF_VAR(QEA.RS);
	I_RD=Convert_OpNumRM_INF_VAR(QEA.RD);
	if(I_RS.type==ON_ERR||I_RD.type==ON_ERR)
	{
		err_lst<<"Unexpected Err eccured in MOV translate"<<"\r\n";
		return;
	}
	//继续，分类讨论
	//I.reg->reg
	if(I_RS.type==ON_REG&&I_RD.type==ON_REG)
	{
		//ORI RD,RS,$zero
		s="";s="OR ";s+=I_RD.REG;s+=",";s+=I_RS.REG;s+=",$zero";
		asm_row.push_back(s);
	}
	else if(I_RS.type==ON_IMM&&I_RD.type==ON_REG)//II.IMM->REG
	{
		char H16[10],L16[10];
		if(I_RS.IMM.H16==0)
		{
			HexTrans(I_RS.IMM.L16,L16);
			s="";s="ORI ";s+=I_RD.REG;s+=",$zero,";s+=L16;asm_row.push_back(s);//ORI RD,$zero,L16
		}
		else
		{
			//itoa(I_RS.IMM.H16,H16,10);itoa(I_RS.IMM.L16,L16,10);
			HexTrans(I_RS.IMM.H16,H16);HexTrans(I_RS.IMM.L16,L16);
			s="";s="LUI ";s+="$s0,";s+=H16;asm_row.push_back(s);//LUI $s0,H16
			s="";s="ORI $s1,$zero,";s+=L16;asm_row.push_back(s);//ORI $s1,$zero,L16
			s="";s="OR ";s+=I_RD.REG;s+=",$s1,$s0";asm_row.push_back(s);//OR RD,$s1,$s0
		}
	}
	else if(I_RS.type==ON_MEM&&I_RD.type==ON_REG)//III.MEM->REG
	{
		//数组无法传递，只有地址和INT可以
		if(I_RS.VP.type==INT&&I_RS.VP.isArray==true)
		{
			if(!isDebug) {
				cout<<"分析器内部异常,MOV翻译中，数组名不能传给寄存器!"<<"\r\n";
			} else {
				err_lst<<"分析器内部异常,MOV翻译中，数组名不能传给寄存器!"<<"\r\n";
			}
			return;
		}
		if(I_RS.VP.type==VOID||I_RS.VP.type==VOID)
		{
			if(!isDebug) {
				cout<<"分析器内部异常,MOV翻译中，void或非法的类型传递!"<<"\r\n";
			} else {
				err_lst<<"分析器内部异常,MOV翻译中，void或非法的类型传递!"<<"\r\n";
			}
			
			return;
		}
		//继续,分两类，全局和局部，全局采取从0开始编址
		if(I_RS.VP.FunName.length()==0)//全局型，绝对地址==offset
		{
			char off[10];HexTrans(I_RS.VP.offset,off);//itoa(I_RS.VP.offset,off,10);
			s="";s="LW $s0,";s+=off;s+="($zero)";asm_row.push_back(s);//LW $s0,offset($zero)
			s="";s="OR ";s+=I_RD.REG;s+=",$s0,$zero";asm_row.push_back(s);//OR RD,$s0,$zero
		}
		else//局部型,绝对地址==sp+offset,(offset[sp])
		{
			char off[10];HexTrans(I_RS.VP.offset,off);//itoa(I_RS.VP.offset,off,10);
			s="";s="LW $s0,";s+=off;s+="($sp)";asm_row.push_back(s);//LW $s0,offset($sp)
			s="";s="OR ";s+=I_RD.REG;s+=",$s0,$zero";asm_row.push_back(s);//OR RD,$s0,$zero
		}
	}
	else if(I_RS.type==ON_MEM&&I_RD.type==ON_MEM)//III.MEM->MEM
	{
		//RS
		if(I_RS.VP.FunName.length()==0)//全局型，绝对地址==offset
		{
			char off[10];HexTrans(I_RS.VP.offset,off);//itoa(I_RS.VP.offset,off,10);
			s="";s="LW $s0,";s+=off;s+="($zero)";asm_row.push_back(s);//LW $s0,offset($zero)
		}
		else//局部型,绝对地址==sp+offset,(offset[sp])
		{
			char off[10];HexTrans(I_RS.VP.offset,off);//itoa(I_RS.VP.offset,off,10);
			s="";s="LW $s0,";s+=off;s+="($sp)";asm_row.push_back(s);//LW $s0,offset($sp)
		}
		//RD
		if(I_RD.VP.FunName.length()==0)//全局型，绝对地址==offset
		{
			char off[10];HexTrans(I_RD.VP.offset,off);//itoa(I_RD.VP.offset,off,10);
			s="";s="SW $s0,";s+=off;s+="($zero)";asm_row.push_back(s);//SW $s0,offset($zero)
		}
		else//局部型,绝对地址==sp+offset,(offset[sp])
		{
			char off[10];HexTrans(I_RD.VP.offset,off);//itoa(I_RD.VP.offset,off,10);
			s="";s="SW $s0,";s+=off;s+="($sp)";asm_row.push_back(s);//SW $s0,offset($sp)
		}
	}
	else if(I_RS.type==ON_REG&&I_RD.type==ON_MEM)//III.REG->MEM
	{
		//RD
		if(I_RD.VP.FunName.length()==0)//全局型，绝对地址==offset
		{
			char off[10];HexTrans(I_RD.VP.offset,off);//itoa(I_RD.VP.offset,off,10);
			s="";s="SW ";s+=I_RS.REG;s+=",";s+=off;s+="($zero)";asm_row.push_back(s);//SW RS,offset($zero)
		}
		else//局部型,绝对地址==sp+offset,(offset[sp])
		{
			char off[10];HexTrans(I_RD.VP.offset,off);//itoa(I_RD.VP.offset,off,10);
			s="";s="SW ";s+=I_RS.REG;s+=",";s+=off;s+="($sp)";asm_row.push_back(s);//SW RS,offset($sp)
		}
	}
    else if(I_RS.type==ON_IMM&&I_RD.type==ON_MEM)//III.IMM->MEM
	{
		char H16[10],L16[10];
        if(I_RS.IMM.H16==0)
		{
			HexTrans(I_RS.IMM.L16,L16);
			s="";s="ORI $s2,$zero,";s+=L16;asm_row.push_back(s);//ORI $s2,$zero,L16
		}
		else
		{
			HexTrans(I_RS.IMM.H16,H16);HexTrans(I_RS.IMM.L16,L16);////itoa(I_RS.IMM.H16,H16,10);itoa(I_RS.IMM.L16,L16,10);
			s="";s="LUI ";s+="$s0,";s+=H16;asm_row.push_back(s);//LUI $s0,H16
			s="";s="ORI $s1,$zero,";s+=L16;asm_row.push_back(s);//ORI $s1,$zero,L16
			s="";s="OR $s2,$s1,$s0";asm_row.push_back(s);//OR $s2,$s1,$s0
		}
		//RD
		if(I_RD.VP.FunName.length()==0)//全局型，绝对地址==offset
		{
			char off[10];HexTrans(I_RD.VP.offset,off);//itoa(I_RD.VP.offset,off,10);
			s="";s="SW $s2,";s+=off;s+="($zero)";asm_row.push_back(s);//SW RS,offset($zero)
		}
		else//局部型,绝对地址==sp+offset,(offset[sp])
		{
			char off[10];HexTrans(I_RD.VP.offset,off);//itoa(I_RD.VP.offset,off,10);
			s="";s="SW $s2,";s+=off;s+="($sp)";asm_row.push_back(s);//SW RS,offset($sp)
		}
	}
	else
	{
		if(!isDebug) {
			cout<<"不支持的传送方式!"<<"\r\n";
		} else {
			err_lst<<"不支持的传送方式!"<<"\r\n";
		}
		return;
	}
}


//小函数，用来合并代码

void MergeAsm(vector<string> &s1,const vector<string> &s2)
{
	for(int i=0;i<s2.size();i++)
	{
		s1.push_back(s2[i]);
	}
}

//下面利用传送MOV的翻译成果，翻译众多表达式


//MOV_Translate(QER_ASM &QEA,vector<string> &asm_row),最多可用掉3个REG,故应该从$s3~$s8中选择使用
void ADD_Translate(QER_ASM &QEA,vector<string> &asm_row) //ADD的翻译,优化reg传送
{
	asm_row.clear();
	string s;
	//s+=ConvertQuadCode(QEA);asm_row.push_back(s);
	s="";
	OpNumRM RS,RT,RD;//临时创造2+1个寄存器$s3,$s4,$s5
	RS.isReg=true;RS.REG="$s3";
	RT.isReg=true;RT.REG="$s4";
	RD.isReg=true;RD.REG="$s5";
	vector<string> mov_tr;//mov翻译的代码
	QER_ASM t_QA;//临时作为传送翻译用
	//
	INF_VAR IV_RS=Convert_OpNumRM_INF_VAR(QEA.RS);
	INF_VAR IV_RT=Convert_OpNumRM_INF_VAR(QEA.RT);
	INF_VAR IV_RD=Convert_OpNumRM_INF_VAR(QEA.RD);
	//
	bool isReWR=true;//当RD为非REG时是否回写
	//
	if(IV_RS.type==ON_IMM&&CombineIMMINT(IV_RS.IMM)>=-32768&&CombineIMMINT(IV_RS.IMM)<=65535)//ADDI
	{
		if(IV_RT.type==ON_REG)//寄存器型优化
		{
			int rs_imm=CombineIMMINT(IV_RS.IMM);
			char rs16[10];HexTrans(rs_imm,rs16);
			if(IV_RD.type==ON_REG)//返回结果也是REG
			{
				s="";s="ADDI ";s+=IV_RD.REG;s+=",";s+=IV_RT.REG;s+=",";s+=rs16;asm_row.push_back(s);//ADDI RD_REG,RT_REG,IMM
				isReWR=false;
			}
			else
			{
				s="";s="ADDI $s5,";s+=IV_RT.REG;s+=",";s+=rs16;asm_row.push_back(s);//ADDI $s5,RT_REG,IMM
			}
		}
		else
		{
			//传送RT
			t_QA.RS=QEA.RT;t_QA.RD=RT;t_QA.OP="MOV";//mov rt,$s4
			MOV_Translate(t_QA,mov_tr);
			MergeAsm(asm_row,mov_tr);
			//
			int rs_imm=CombineIMMINT(IV_RS.IMM);
			char rs16[10];HexTrans(rs_imm,rs16);
			if(IV_RD.type==ON_REG)//返回结果也是REG
			{
				s="";s="ADDI ";s+=IV_RD.REG;s+=",$s4";s+=rs16;asm_row.push_back(s);//ADDI RD_REG,$s4,IMM
				isReWR=false;
			}
			else
			{
				s="";s="ADDI $s5,$s4,";s+=rs16;asm_row.push_back(s);//ADDI $s5,$s4,IMM
			}

		}
	}
	else if(IV_RT.type==ON_IMM&&CombineIMMINT(IV_RT.IMM)>=-32768&&CombineIMMINT(IV_RT.IMM)<=65535)//ADDI
	{
		if(IV_RS.type==ON_REG)
		{
			int rs_imm=CombineIMMINT(IV_RT.IMM);
			char rs16[10];HexTrans(rs_imm,rs16);
			if(IV_RD.type==ON_REG)//返回结果也是REG
			{
				s="";s="ADDI ";s+=IV_RD.REG;s+=",";s+=IV_RS.REG;s+=",";s+=rs16;asm_row.push_back(s);//ADDI RD_REG,RS_REG,IMM
				isReWR=false;
			}
			else
			{
				s="";s="ADDI $s5,";s+=IV_RS.REG;s+=",";s+=rs16;asm_row.push_back(s);//ADDI $s5,RS_REG,IMM
			}
		}
		else
		{
			//传送RS
			t_QA.RS=QEA.RS;t_QA.RD=RS;t_QA.OP="MOV";//mov rt,$s3
			MOV_Translate(t_QA,mov_tr);
			MergeAsm(asm_row,mov_tr);
			//
			int rt_imm=CombineIMMINT(IV_RT.IMM);
			char rt16[10];HexTrans(rt_imm,rt16);
			if(IV_RD.type==ON_REG)//返回结果也是REG
			{
				s="";s="ADDI ";s+=IV_RD.REG;s+=",$s3,";s+=rt16;asm_row.push_back(s);//ADDI RD_REG,$s3,IMM
				isReWR=false;
			}
			else
			{
				s="";s="ADDI $s5,$s3,";s+=rt16;asm_row.push_back(s);//ADDI $s5,$s3,IMM
			}
		}
	}
	else
	{
		s="";
		if(IV_RD.type==ON_REG)
		{
			s="ADD ";s+=IV_RD.REG;s+=",";
			isReWR=false;
		}
		else
		{
			s="ADD $s5,";
		}
		if(IV_RS.type==ON_REG)
		{
			s+=IV_RS.REG;s+=",";
		}
		else
		{
			//传送RS
			t_QA.RS=QEA.RS;t_QA.RD=RS;t_QA.OP="MOV";//mov rs,$s3
			MOV_Translate(t_QA,mov_tr);
			MergeAsm(asm_row,mov_tr);
			s+="$s3,";
		}
		if(IV_RT.type==ON_REG)
		{
			s+=IV_RT.REG;
		}
		else
		{
			//传送RT
			t_QA.RS=QEA.RT;t_QA.RD=RT;t_QA.OP="MOV";//mov rt,$s4
			MOV_Translate(t_QA,mov_tr);
			MergeAsm(asm_row,mov_tr);
			s+="$s4";
		}
		asm_row.push_back(s);
		//计算代码
	}
	if(isReWR==true)
	{
		//结果回写,$s5->RD
		t_QA.RS=RD;t_QA.RD=QEA.RD;t_QA.OP="MOV";//mov $s5,rd
		MOV_Translate(t_QA,mov_tr);
		MergeAsm(asm_row,mov_tr);
	}
	//计算完毕，有MOV就是方便
}

void LSHIFT_Translate(QER_ASM &QEA,vector<string> &asm_row) //lshift的翻译,优化REG传送
{
	asm_row.clear();
	string s;
	//s+=ConvertQuadCode(QEA);asm_row.push_back(s);
	s="";
	OpNumRM RS,RT,RD;//临时创造2+1个寄存器$s3,$s4,$s5
	RS.isReg=true;RS.REG="$s3";
	RT.isReg=true;RT.REG="$s4";
	RD.isReg=true;RD.REG="$s5";
	vector<string> mov_tr;//mov翻译的代码
	QER_ASM t_QA;//临时作为传送翻译用
	//
	INF_VAR IV_RS=Convert_OpNumRM_INF_VAR(QEA.RS);
	INF_VAR IV_RT=Convert_OpNumRM_INF_VAR(QEA.RT);
	INF_VAR IV_RD=Convert_OpNumRM_INF_VAR(QEA.RD);
	//
	bool isReWR=true;//当RD为非REG时是否回写
	//
	if(IV_RT.type==ON_IMM)//使用立即数移位
	{
		if(IV_RT.IMM.H16!=0||IV_RT.IMM.L16>32)
		{
			if(!isDebug) {
				cout<<"左移动范围不对!"<<"\r\n";
			} else {
				err_lst<<"左移动范围不对!"<<"\r\n";
			}
			
			return;
		}
		else
		{
			if(IV_RS.type==ON_REG)
			{
				int rs_imm=CombineIMMINT(IV_RT.IMM);
				char rs16[10];HexTrans(rs_imm,rs16);
				if(IV_RD.type==ON_REG)//返回结果也是REG
				{
					s="";s="SLL ";s+=IV_RD.REG;s+=",";s+=IV_RS.REG;s+=",";s+=rs16;asm_row.push_back(s);//SLL RD_REG,RS_REG,IMM
					isReWR=false;
				}
				else
				{
					s="";s="SLL $s5,";s+=IV_RS.REG;s+=",";s+=rs16;asm_row.push_back(s);//SLL $s5,RS_REG,IMM
				}
			}
			else
			{
				//传送RS
				t_QA.RS=QEA.RS;t_QA.RD=RS;t_QA.OP="MOV";//mov rt,$s3
				MOV_Translate(t_QA,mov_tr);
				MergeAsm(asm_row,mov_tr);
				//
				int rt_imm=CombineIMMINT(IV_RT.IMM);
				char rt16[10];HexTrans(rt_imm,rt16);
				if(IV_RD.type==ON_REG)//返回结果也是REG
				{
					s="";s="SLL ";s+=IV_RD.REG;s+=",$s3,";s+=rt16;asm_row.push_back(s);//SLL RD_REG,$s3,IMM
					isReWR=false;
				}
				else
				{
					s="";s="SLL $s5,$s3,";s+=rt16;asm_row.push_back(s);//SLL $s5,$s3,IMM
				}
			}
		}
	}
	else
	{
		s="";
		if(IV_RD.type==ON_REG)
		{
			s="SLLV ";s+=IV_RD.REG;s+=",";
			isReWR=false;
		}
		else
		{
			s="SLLV $s5,";
		}
		if(IV_RS.type==ON_REG)
		{
			s+=IV_RS.REG;s+=",";
		}
		else
		{
			//传送RS
			t_QA.RS=QEA.RS;t_QA.RD=RS;t_QA.OP="MOV";//mov rs,$s3
			MOV_Translate(t_QA,mov_tr);
			MergeAsm(asm_row,mov_tr);
			s+="$s3,";
		}
		if(IV_RT.type==ON_REG)
		{
			s+=IV_RT.REG;
		}
		else
		{
			//传送RT
			t_QA.RS=QEA.RT;t_QA.RD=RT;t_QA.OP="MOV";//mov rt,$s4
			MOV_Translate(t_QA,mov_tr);
			MergeAsm(asm_row,mov_tr);
			s+="$s4";
		}
		asm_row.push_back(s);
		//计算代码
	}
	if(isReWR==true)
	{
		//结果回写,$s5->RD
		t_QA.RS=RD;t_QA.RD=QEA.RD;t_QA.OP="MOV";//mov $s5,rd
		MOV_Translate(t_QA,mov_tr);
		MergeAsm(asm_row,mov_tr);
	}
	//计算完毕，有MOV就是方便
}

void RSHIFT_Translate(QER_ASM &QEA,vector<string> &asm_row) //lshift的翻译,优化REG传送
{
	asm_row.clear();
	string s;
	//s+=ConvertQuadCode(QEA);asm_row.push_back(s);
	s="";
	OpNumRM RS,RT,RD;//临时创造2+1个寄存器$s3,$s4,$s5
	RS.isReg=true;RS.REG="$s3";
	RT.isReg=true;RT.REG="$s4";
	RD.isReg=true;RD.REG="$s5";
	vector<string> mov_tr;//mov翻译的代码
	QER_ASM t_QA;//临时作为传送翻译用
	//
	INF_VAR IV_RS=Convert_OpNumRM_INF_VAR(QEA.RS);
	INF_VAR IV_RT=Convert_OpNumRM_INF_VAR(QEA.RT);
	INF_VAR IV_RD=Convert_OpNumRM_INF_VAR(QEA.RD);
	//
	bool isReWR=true;//当RD为非REG时是否回写
	//
	if(IV_RT.type==ON_IMM)//使用立即数移位
	{
		if(IV_RT.IMM.H16!=0||IV_RT.IMM.L16>32)
		{
			if(!isDebug) {
				cout<<"左移动范围不对!"<<"\r\n";
			} else {
				err_lst<<"左移动范围不对!"<<"\r\n";
			}
			
			return;
		}
		else
		{
			if(IV_RS.type==ON_REG)
			{
				int rs_imm=CombineIMMINT(IV_RT.IMM);
				char rs16[10];HexTrans(rs_imm,rs16);
				if(IV_RD.type==ON_REG)//返回结果也是REG
				{
					s="";s="SRA ";s+=IV_RD.REG;s+=",";s+=IV_RS.REG;s+=",";s+=rs16;asm_row.push_back(s);//SLL RD_REG,RS_REG,IMM
					isReWR=false;
				}
				else
				{
					s="";s="SRA $s5,";s+=IV_RS.REG;s+=",";s+=rs16;asm_row.push_back(s);//SLL $s5,RS_REG,IMM
				}
			}
			else
			{
				//传送RS
				t_QA.RS=QEA.RS;t_QA.RD=RS;t_QA.OP="MOV";//mov rt,$s3
				MOV_Translate(t_QA,mov_tr);
				MergeAsm(asm_row,mov_tr);
				//
				int rt_imm=CombineIMMINT(IV_RT.IMM);
				char rt16[10];HexTrans(rt_imm,rt16);
				if(IV_RD.type==ON_REG)//返回结果也是REG
				{
					s="";s="SRA ";s+=IV_RD.REG;s+=",$s3,";s+=rt16;asm_row.push_back(s);//SLL RD_REG,$s3,IMM
					isReWR=false;
				}
				else
				{
					s="";s="SRA $s5,$s3,";s+=rt16;asm_row.push_back(s);//SLL $s5,$s3,IMM
				}
			}
		}
	}
	else
	{
		s="";
		if(IV_RD.type==ON_REG)
		{
			s="SRAV ";s+=IV_RD.REG;s+=",";
			isReWR=false;
		}
		else
		{
			s="SRAV $s5,";
		}
		if(IV_RS.type==ON_REG)
		{
			s+=IV_RS.REG;s+=",";
		}
		else
		{
			//传送RS
			t_QA.RS=QEA.RS;t_QA.RD=RS;t_QA.OP="MOV";//mov rs,$s3
			MOV_Translate(t_QA,mov_tr);
			MergeAsm(asm_row,mov_tr);
			s+="$s3,";
		}
		if(IV_RT.type==ON_REG)
		{
			s+=IV_RT.REG;
		}
		else
		{
			//传送RT
			t_QA.RS=QEA.RT;t_QA.RD=RT;t_QA.OP="MOV";//mov rt,$s4
			MOV_Translate(t_QA,mov_tr);
			MergeAsm(asm_row,mov_tr);
			s+="$s4";
		}
		asm_row.push_back(s);
		//计算代码
	}
	if(isReWR==true)
	{
		//结果回写,$s5->RD
		t_QA.RS=RD;t_QA.RD=QEA.RD;t_QA.OP="MOV";//mov $s5,rd
		MOV_Translate(t_QA,mov_tr);
		MergeAsm(asm_row,mov_tr);
	}
	//计算完毕，有MOV就是方便
}

void SUB_Translate(QER_ASM &QEA,vector<string> &asm_row) //SUB的翻译,2
{
	asm_row.clear();
	string s;
	//s+=ConvertQuadCode(QEA);asm_row.push_back(s);
	s="";
	OpNumRM RS,RT,RD;//临时创造2+1个寄存器$s3,$s4,$s5
	RS.isReg=true;RS.REG="$s3";
	RT.isReg=true;RT.REG="$s4";
	RD.isReg=true;RD.REG="$s5";
	vector<string> mov_tr;//mov翻译的代码
	QER_ASM t_QA;//临时作为传送翻译用
	//
	INF_VAR IV_RS=Convert_OpNumRM_INF_VAR(QEA.RS);
	INF_VAR IV_RT=Convert_OpNumRM_INF_VAR(QEA.RT);
	INF_VAR IV_RD=Convert_OpNumRM_INF_VAR(QEA.RD);
	//
	bool isReWR=true;//当RD为非REG时是否回写
	//
	s="";
	if(IV_RD.type==ON_REG)
	{
		s="SUB ";s+=IV_RD.REG;s+=",";
		isReWR=false;
	}
	else
	{
		s="SUB $s5,";
	}
	if(IV_RS.type==ON_REG)
	{
		s+=IV_RS.REG;s+=",";
	}
	else
	{
		//传送RS
		t_QA.RS=QEA.RS;t_QA.RD=RS;t_QA.OP="MOV";//mov rs,$s3
		MOV_Translate(t_QA,mov_tr);
		MergeAsm(asm_row,mov_tr);
		s+="$s3,";
	}
	if(IV_RT.type==ON_REG)
	{
		s+=IV_RT.REG;
	}
	else
	{
		//传送RT
		t_QA.RS=QEA.RT;t_QA.RD=RT;t_QA.OP="MOV";//mov rt,$s4
		MOV_Translate(t_QA,mov_tr);
		MergeAsm(asm_row,mov_tr);
		s+="$s4";
	}
	asm_row.push_back(s);
	//计算代码
	if(isReWR==true)
	{
		//结果回写,$s5->RD
		t_QA.RS=RD;t_QA.RD=QEA.RD;t_QA.OP="MOV";//mov $s5,rd
		MOV_Translate(t_QA,mov_tr);
		MergeAsm(asm_row,mov_tr);
	}
	//计算完毕，有MOV就是方便
}

void OR_Translate(QER_ASM &QEA,vector<string> &asm_row) //OR的翻译,优化reg传送
{
	asm_row.clear();
	string s;
	//s+=ConvertQuadCode(QEA);asm_row.push_back(s);
	s="";
	OpNumRM RS,RT,RD;//临时创造2+1个寄存器$s3,$s4,$s5
	RS.isReg=true;RS.REG="$s3";
	RT.isReg=true;RT.REG="$s4";
	RD.isReg=true;RD.REG="$s5";
	vector<string> mov_tr;//mov翻译的代码
	QER_ASM t_QA;//临时作为传送翻译用
	//
	INF_VAR IV_RS=Convert_OpNumRM_INF_VAR(QEA.RS);
	INF_VAR IV_RT=Convert_OpNumRM_INF_VAR(QEA.RT);
	INF_VAR IV_RD=Convert_OpNumRM_INF_VAR(QEA.RD);
	//
	bool isReWR=true;//当RD为非REG时是否回写
	//
	if(IV_RS.type==ON_IMM&&CombineIMMINT(IV_RS.IMM)>=-32768&&CombineIMMINT(IV_RS.IMM)<=65535)//ORI
	{
		if(IV_RT.type==ON_REG)//寄存器型优化
		{
			int rs_imm=CombineIMMINT(IV_RS.IMM);
			char rs16[10];HexTrans(rs_imm,rs16);
			if(IV_RD.type==ON_REG)//返回结果也是REG
			{
				s="";s="ORI ";s+=IV_RD.REG;s+=",";s+=IV_RT.REG;s+=",";s+=rs16;asm_row.push_back(s);//ORI RD_REG,RT_REG,IMM
				isReWR=false;
			}
			else
			{
				s="";s="ORI $s5,";s+=IV_RT.REG;s+=",";s+=rs16;asm_row.push_back(s);//ORI $s5,RT_REG,IMM
			}
		}
		else
		{
			//传送RT
			t_QA.RS=QEA.RT;t_QA.RD=RT;t_QA.OP="MOV";//mov rt,$s4
			MOV_Translate(t_QA,mov_tr);
			MergeAsm(asm_row,mov_tr);
			//
			int rs_imm=CombineIMMINT(IV_RS.IMM);
			char rs16[10];HexTrans(rs_imm,rs16);
			if(IV_RD.type==ON_REG)//返回结果也是REG
			{
				s="";s="ORI ";s+=IV_RD.REG;s+=",$s4";s+=rs16;asm_row.push_back(s);//ORI RD_REG,$s4,IMM
				isReWR=false;
			}
			else
			{
				s="";s="ORI $s5,$s4,";s+=rs16;asm_row.push_back(s);//ORI $s5,$s4,IMM
			}

		}
	}
	else if(IV_RT.type==ON_IMM&&CombineIMMINT(IV_RT.IMM)>=-32768&&CombineIMMINT(IV_RT.IMM)<=65535)//ORI
	{
		if(IV_RS.type==ON_REG)
		{
			int rs_imm=CombineIMMINT(IV_RT.IMM);
			char rs16[10];HexTrans(rs_imm,rs16);
			if(IV_RD.type==ON_REG)//返回结果也是REG
			{
				s="";s="ORI ";s+=IV_RD.REG;s+=",";s+=IV_RS.REG;s+=",";s+=rs16;asm_row.push_back(s);//ORI RD_REG,RS_REG,IMM
				isReWR=false;
			}
			else
			{
				s="";s="ORI $s5,";s+=IV_RS.REG;s+=",";s+=rs16;asm_row.push_back(s);//ADDI $s5,RS_REG,IMM
			}
		}
		else
		{
			//传送RS
			t_QA.RS=QEA.RS;t_QA.RD=RS;t_QA.OP="MOV";//mov rt,$s3
			MOV_Translate(t_QA,mov_tr);
			MergeAsm(asm_row,mov_tr);
			//
			int rt_imm=CombineIMMINT(IV_RT.IMM);
			char rt16[10];HexTrans(rt_imm,rt16);
			if(IV_RD.type==ON_REG)//返回结果也是REG
			{
				s="";s="ORI ";s+=IV_RD.REG;s+=",$s3";s+=rt16;asm_row.push_back(s);//ORI RD_REG,$s3,IMM
				isReWR=false;
			}
			else
			{
				s="";s="ORI $s5,$s3,";s+=rt16;asm_row.push_back(s);//ORI $s5,$s3,IMM
			}
		}
	}
	else
	{
		s="";
		if(IV_RD.type==ON_REG)
		{
			s="OR ";s+=IV_RD.REG;s+=",";
			isReWR=false;
		}
		else
		{
			s="OR $s5,";
		}
		if(IV_RS.type==ON_REG)
		{
			s+=IV_RS.REG;s+=",";
		}
		else
		{
			//传送RS
			t_QA.RS=QEA.RS;t_QA.RD=RS;t_QA.OP="MOV";//mov rs,$s3
			MOV_Translate(t_QA,mov_tr);
			MergeAsm(asm_row,mov_tr);
			s+="$s3,";
		}
		if(IV_RT.type==ON_REG)
		{
			s+=IV_RT.REG;
		}
		else
		{
			//传送RT
			t_QA.RS=QEA.RT;t_QA.RD=RT;t_QA.OP="MOV";//mov rt,$s4
			MOV_Translate(t_QA,mov_tr);
			MergeAsm(asm_row,mov_tr);
			s+="$s4";
		}
		asm_row.push_back(s);
		//计算代码
	}
	if(isReWR==true)
	{
		//结果回写,$s5->RD
		t_QA.RS=RD;t_QA.RD=QEA.RD;t_QA.OP="MOV";//mov $s5,rd
		MOV_Translate(t_QA,mov_tr);
		MergeAsm(asm_row,mov_tr);
	}
	//计算完毕，有MOV就是方便
}



void AND_Translate(QER_ASM &QEA,vector<string> &asm_row) //OR的翻译,优化reg传送
{
	asm_row.clear();
	string s;
	//s+=ConvertQuadCode(QEA);asm_row.push_back(s);
	s="";
	OpNumRM RS,RT,RD;//临时创造2+1个寄存器$s3,$s4,$s5
	RS.isReg=true;RS.REG="$s3";
	RT.isReg=true;RT.REG="$s4";
	RD.isReg=true;RD.REG="$s5";
	vector<string> mov_tr;//mov翻译的代码
	QER_ASM t_QA;//临时作为传送翻译用
	//
	INF_VAR IV_RS=Convert_OpNumRM_INF_VAR(QEA.RS);
	INF_VAR IV_RT=Convert_OpNumRM_INF_VAR(QEA.RT);
	INF_VAR IV_RD=Convert_OpNumRM_INF_VAR(QEA.RD);
	//
	bool isReWR=true;//当RD为非REG时是否回写
	//
	if(IV_RS.type==ON_IMM&&CombineIMMINT(IV_RS.IMM)>=-32768&&CombineIMMINT(IV_RS.IMM)<=65535)//ANDI
	{
		if(IV_RT.type==ON_REG)//寄存器型优化
		{
			int rs_imm=CombineIMMINT(IV_RS.IMM);
			char rs16[10];HexTrans(rs_imm,rs16);
			if(IV_RD.type==ON_REG)//返回结果也是REG
			{
				s="";s="ANDI ";s+=IV_RD.REG;s+=",";s+=IV_RT.REG;s+=",";s+=rs16;asm_row.push_back(s);//ANDI RD_REG,RT_REG,IMM
				isReWR=false;
			}
			else
			{
				s="";s="ANDI $s5,";s+=IV_RT.REG;s+=",";s+=rs16;asm_row.push_back(s);//ANDI $s5,RT_REG,IMM
			}
		}
		else
		{
			//传送RT
			t_QA.RS=QEA.RT;t_QA.RD=RT;t_QA.OP="MOV";//mov rt,$s4
			MOV_Translate(t_QA,mov_tr);
			MergeAsm(asm_row,mov_tr);
			//
			int rs_imm=CombineIMMINT(IV_RS.IMM);
			char rs16[10];HexTrans(rs_imm,rs16);
			if(IV_RD.type==ON_REG)//返回结果也是REG
			{
				s="";s="ANDI ";s+=IV_RD.REG;s+=",$s4,";s+=rs16;asm_row.push_back(s);//ANDI RD_REG,$s4,IMM
				isReWR=false;
			}
			else
			{
				s="";s="ANDI $s5,$s4,";s+=rs16;asm_row.push_back(s);//ANDI $s5,$s4,IMM
			}

		}
	}
	else if(IV_RT.type==ON_IMM&&CombineIMMINT(IV_RT.IMM)>=-32768&&CombineIMMINT(IV_RT.IMM)<=65535)//ANDI
	{
		if(IV_RS.type==ON_REG)
		{
			int rs_imm=CombineIMMINT(IV_RT.IMM);
			char rs16[10];HexTrans(rs_imm,rs16);
			if(IV_RD.type==ON_REG)//返回结果也是REG
			{
				s="";s="ANDI ";s+=IV_RD.REG;s+=",";s+=IV_RS.REG;s+=",";s+=rs16;asm_row.push_back(s);//ANDI RD_REG,RS_REG,IMM
				isReWR=false;
			}
			else
			{
				s="";s="ANDI $s5,";s+=IV_RS.REG;s+=",";s+=rs16;asm_row.push_back(s);//ANDI $s5,RS_REG,IMM
			}
		}
		else
		{
			//传送RS
			t_QA.RS=QEA.RS;t_QA.RD=RS;t_QA.OP="MOV";//mov rt,$s3
			MOV_Translate(t_QA,mov_tr);
			MergeAsm(asm_row,mov_tr);
			//
			int rt_imm=CombineIMMINT(IV_RT.IMM);
			char rt16[10];HexTrans(rt_imm,rt16);
			if(IV_RD.type==ON_REG)//返回结果也是REG
			{
				s="";s="ANDI ";s+=IV_RD.REG;s+=",$s3,";s+=rt16;asm_row.push_back(s);//ANDI RD_REG,$s3,IMM
				isReWR=false;
			}
			else
			{
				s="";s="ANDI $s5,$s3,";s+=rt16;asm_row.push_back(s);//ANDI $s5,$s3,IMM
			}
		}
	}
	else
	{
		s="";
		if(IV_RD.type==ON_REG)
		{
			s="AND ";s+=IV_RD.REG;s+=",";
			isReWR=false;
		}
		else
		{
			s="AND $s5,";
		}
		if(IV_RS.type==ON_REG)
		{
			s+=IV_RS.REG;s+=",";
		}
		else
		{
			//传送RS
			t_QA.RS=QEA.RS;t_QA.RD=RS;t_QA.OP="MOV";//mov rs,$s3
			MOV_Translate(t_QA,mov_tr);
			MergeAsm(asm_row,mov_tr);
			s+="$s3,";
		}
		if(IV_RT.type==ON_REG)
		{
			s+=IV_RT.REG;
		}
		else
		{
			//传送RT
			t_QA.RS=QEA.RT;t_QA.RD=RT;t_QA.OP="MOV";//mov rt,$s4
			MOV_Translate(t_QA,mov_tr);
			MergeAsm(asm_row,mov_tr);
			s+="$s4";
		}
		asm_row.push_back(s);
		//计算代码
	}
	if(isReWR==true)
	{
		//结果回写,$s5->RD
		t_QA.RS=RD;t_QA.RD=QEA.RD;t_QA.OP="MOV";//mov $s5,rd
		MOV_Translate(t_QA,mov_tr);
		MergeAsm(asm_row,mov_tr);
	}
	//计算完毕，有MOV就是方便
}

void XOR_Translate(QER_ASM &QEA,vector<string> &asm_row) //OR的翻译,优化reg传送
{
	asm_row.clear();
	string s;
	//s+=ConvertQuadCode(QEA);asm_row.push_back(s);
	s="";
	OpNumRM RS,RT,RD;//临时创造2+1个寄存器$s3,$s4,$s5
	RS.isReg=true;RS.REG="$s3";
	RT.isReg=true;RT.REG="$s4";
	RD.isReg=true;RD.REG="$s5";
	vector<string> mov_tr;//mov翻译的代码
	QER_ASM t_QA;//临时作为传送翻译用
	//
	INF_VAR IV_RS=Convert_OpNumRM_INF_VAR(QEA.RS);
	INF_VAR IV_RT=Convert_OpNumRM_INF_VAR(QEA.RT);
	INF_VAR IV_RD=Convert_OpNumRM_INF_VAR(QEA.RD);
	//
	bool isReWR=true;//当RD为非REG时是否回写
	//
	if(IV_RS.type==ON_IMM&&CombineIMMINT(IV_RS.IMM)>=-32768&&CombineIMMINT(IV_RS.IMM)<=65535)//XORI
	{
		if(IV_RT.type==ON_REG)//寄存器型优化
		{
			int rs_imm=CombineIMMINT(IV_RS.IMM);
			char rs16[10];HexTrans(rs_imm,rs16);
			if(IV_RD.type==ON_REG)//返回结果也是REG
			{
				s="";s="XORI ";s+=IV_RD.REG;s+=",";s+=IV_RT.REG;s+=",";s+=rs16;asm_row.push_back(s);//XORI RD_REG,RT_REG,IMM
				isReWR=false;
			}
			else
			{
				s="";s="XORI $s5,";s+=IV_RT.REG;s+=",";s+=rs16;asm_row.push_back(s);//XORI $s5,RT_REG,IMM
			}
		}
		else
		{
			//传送RT
			t_QA.RS=QEA.RT;t_QA.RD=RT;t_QA.OP="MOV";//mov rt,$s4
			MOV_Translate(t_QA,mov_tr);
			MergeAsm(asm_row,mov_tr);
			//
			int rs_imm=CombineIMMINT(IV_RS.IMM);
			char rs16[10];HexTrans(rs_imm,rs16);
			if(IV_RD.type==ON_REG)//返回结果也是REG
			{
				s="";s="XORI ";s+=IV_RD.REG;s+=",$s4";s+=rs16;asm_row.push_back(s);//XORI RD_REG,$s4,IMM
				isReWR=false;
			}
			else
			{
				s="";s="XORI $s5,$s4,";s+=rs16;asm_row.push_back(s);//XORI $s5,$s4,IMM
			}

		}
	}
	else if(IV_RT.type==ON_IMM&&CombineIMMINT(IV_RT.IMM)>=-32768&&CombineIMMINT(IV_RT.IMM)<=65535)//XORI
	{
		if(IV_RS.type==ON_REG)
		{
			int rs_imm=CombineIMMINT(IV_RT.IMM);
			char rs16[10];HexTrans(rs_imm,rs16);
			if(IV_RD.type==ON_REG)//返回结果也是REG
			{
				s="";s="XORI ";s+=IV_RD.REG;s+=",";s+=IV_RS.REG;s+=",";s+=rs16;asm_row.push_back(s);//XORI RD_REG,RS_REG,IMM
				isReWR=false;
			}
			else
			{
				s="";s="XORI $s5,";s+=IV_RS.REG;s+=",";s+=rs16;asm_row.push_back(s);//ANDI $s5,RS_REG,IMM
			}
		}
		else
		{
			//传送RS
			t_QA.RS=QEA.RS;t_QA.RD=RS;t_QA.OP="MOV";//mov rt,$s3
			MOV_Translate(t_QA,mov_tr);
			MergeAsm(asm_row,mov_tr);
			//
			int rt_imm=CombineIMMINT(IV_RT.IMM);
			char rt16[10];HexTrans(rt_imm,rt16);
			if(IV_RD.type==ON_REG)//返回结果也是REG
			{
				s="";s="XORI ";s+=IV_RD.REG;s+=",$s3";s+=rt16;asm_row.push_back(s);//XORI RD_REG,$s3,IMM
				isReWR=false;
			}
			else
			{
				s="";s="XORI $s5,$s3,";s+=rt16;asm_row.push_back(s);//XORI $s5,$s3,IMM
			}
		}
	}
	else
	{
		s="";
		if(IV_RD.type==ON_REG)
		{
			s="XOR ";s+=IV_RD.REG;s+=",";
			isReWR=false;
		}
		else
		{
			s="XOR $s5,";
		}
		if(IV_RS.type==ON_REG)
		{
			s+=IV_RS.REG;s+=",";
		}
		else
		{
			//传送RS
			t_QA.RS=QEA.RS;t_QA.RD=RS;t_QA.OP="MOV";//mov rs,$s3
			MOV_Translate(t_QA,mov_tr);
			MergeAsm(asm_row,mov_tr);
			s+="$s3,";
		}
		if(IV_RT.type==ON_REG)
		{
			s+=IV_RT.REG;
		}
		else
		{
			//传送RT
			t_QA.RS=QEA.RT;t_QA.RD=RT;t_QA.OP="MOV";//mov rt,$s4
			MOV_Translate(t_QA,mov_tr);
			MergeAsm(asm_row,mov_tr);
			s+="$s4";
		}
		asm_row.push_back(s);
		//计算代码
	}
	if(isReWR==true)
	{
		//结果回写,$s5->RD
		t_QA.RS=RD;t_QA.RD=QEA.RD;t_QA.OP="MOV";//mov $s5,rd
		MOV_Translate(t_QA,mov_tr);
		MergeAsm(asm_row,mov_tr);
	}
	//计算完毕，有MOV就是方便
}

void SLT_Translate(QER_ASM &QEA,vector<string> &asm_row) //SLT的翻译,2
{
	asm_row.clear();
	string s;
	//s+=ConvertQuadCode(QEA);asm_row.push_back(s);
	s="";
	OpNumRM RS,RT,RD;//临时创造2+1个寄存器$s3,$s4,$s5
	RS.isReg=true;RS.REG="$s3";
	RT.isReg=true;RT.REG="$s4";
	RD.isReg=true;RD.REG="$s5";
	vector<string> mov_tr;//mov翻译的代码
	QER_ASM t_QA;//临时作为传送翻译用
	//
	INF_VAR IV_RS=Convert_OpNumRM_INF_VAR(QEA.RS);
	INF_VAR IV_RT=Convert_OpNumRM_INF_VAR(QEA.RT);
	INF_VAR IV_RD=Convert_OpNumRM_INF_VAR(QEA.RD);
	//
	bool isReWR=true;//当RD为非REG时是否回写
	//
	if(IV_RT.type==ON_IMM&&CombineIMMINT(IV_RT.IMM)>=-32768&&CombineIMMINT(IV_RT.IMM)<=65535)//SLTI
	{
		if(IV_RS.type==ON_REG)
		{
			int rs_imm=CombineIMMINT(IV_RT.IMM);
			char rs16[10];HexTrans(rs_imm,rs16);
			if(IV_RD.type==ON_REG)//返回结果也是REG
			{
				s="";s="SLTI ";s+=IV_RD.REG;s+=",";s+=IV_RS.REG;s+=",";s+=rs16;asm_row.push_back(s);//SLTI RD_REG,RS_REG,IMM
				isReWR=false;
			}
			else
			{
				s="";s="SLTI $s5,";s+=IV_RS.REG;s+=",";s+=rs16;asm_row.push_back(s);//SLTI $s5,RS_REG,IMM
			}
		}
		else
		{
			//传送RS
			t_QA.RS=QEA.RS;t_QA.RD=RS;t_QA.OP="MOV";//mov rt,$s3
			MOV_Translate(t_QA,mov_tr);
			MergeAsm(asm_row,mov_tr);
			//
			int rt_imm=CombineIMMINT(IV_RT.IMM);
			char rt16[10];HexTrans(rt_imm,rt16);
			if(IV_RD.type==ON_REG)//返回结果也是REG
			{
				s="";s="SLTI ";s+=IV_RD.REG;s+=",$s3,";s+=rt16;asm_row.push_back(s);//ADDI RD_REG,$s3,IMM
				isReWR=false;
			}
			else
			{
				s="";s="SLTI $s5,$s3,";s+=rt16;asm_row.push_back(s);//ADDI $s5,$s3,IMM
			}
		}
	}
	else
	{
		s="";
		if(IV_RD.type==ON_REG)
		{
			s="SLT ";s+=IV_RD.REG;s+=",";
			isReWR=false;
		}
		else
		{
			s="SLT $s5,";
		}
		if(IV_RS.type==ON_REG)
		{
			s+=IV_RS.REG;s+=",";
		}
		else
		{
			//传送RS
			t_QA.RS=QEA.RS;t_QA.RD=RS;t_QA.OP="MOV";//mov rs,$s3
			MOV_Translate(t_QA,mov_tr);
			MergeAsm(asm_row,mov_tr);
			s+="$s3,";
		}
		if(IV_RT.type==ON_REG)
		{
			s+=IV_RT.REG;
		}
		else
		{
			//传送RT
			t_QA.RS=QEA.RT;t_QA.RD=RT;t_QA.OP="MOV";//mov rt,$s4
			MOV_Translate(t_QA,mov_tr);
			MergeAsm(asm_row,mov_tr);
			s+="$s4";
		}
		asm_row.push_back(s);
		//计算代码
	}
	if(isReWR==true)
	{
		//结果回写,$s5->RD
		t_QA.RS=RD;t_QA.RD=QEA.RD;t_QA.OP="MOV";//mov $s5,rd
		MOV_Translate(t_QA,mov_tr);
		MergeAsm(asm_row,mov_tr);
	}
	//计算完毕，有MOV就是方便
}

void NOT_Translate(QER_ASM &QEA,vector<string> &asm_row) //NOT的翻译,2
{
	asm_row.clear();
	string s;
	//s+=ConvertQuadCode(QEA);asm_row.push_back(s);
	s="";
	OpNumRM RS,RT,RD;//临时创造2+1个寄存器$s3,$s4,$s5
	RS.isReg=true;RS.REG="$s3";
	//RT.isReg=true;RT.REG="$s4";
	RD.isReg=true;RD.REG="$s5";
	vector<string> mov_tr;//mov翻译的代码
	QER_ASM t_QA;//临时作为传送翻译用
	//
	INF_VAR IV_RS=Convert_OpNumRM_INF_VAR(QEA.RS);
	//INF_VAR IV_RT=Convert_OpNumRM_INF_VAR(QEA.RT);
	INF_VAR IV_RD=Convert_OpNumRM_INF_VAR(QEA.RD);
	//
	bool isReWR=true;//当RD为非REG时是否回写
	//
		s="";
	if(IV_RD.type==ON_REG)
	{
		s="NOR ";s+=IV_RD.REG;s+=",";
		isReWR=false;
	}
	else
	{
		s="NOR $s5,";
	}
	if(IV_RS.type==ON_REG)
	{
		s+=IV_RS.REG;s+=",";
	}
	else
	{
		//传送RS
		t_QA.RS=QEA.RS;t_QA.RD=RS;t_QA.OP="MOV";//mov rs,$s3
		MOV_Translate(t_QA,mov_tr);
		MergeAsm(asm_row,mov_tr);
		s+="$s3,";
	}
	//asm_row.push_back(s);
	//计算代码
	s+="$zero";asm_row.push_back(s);//nor $s5,$s3,$zero
	if(isReWR==true)
	{
		//结果回写,$s5->RD
		t_QA.RS=RD;t_QA.RD=QEA.RD;t_QA.OP="MOV";//mov $s5,rd
		MOV_Translate(t_QA,mov_tr);
		MergeAsm(asm_row,mov_tr);
	}
	//计算完毕，有MOV就是方便
}

void GOTO_Translate(QER_ASM &QEA,vector<string> &asm_row) //GOTO的翻译,2
{
	asm_row.clear();
	string s;
	//s+=ConvertQuadCode(QEA);asm_row.push_back(s);
	s="";
	s="";s="J ";s+=QEA.RD.ON.label;asm_row.push_back(s);//可以检测标号是否存在
}

void BEQ_Translate(QER_ASM &QEA,vector<string> &asm_row) //NOT的翻译,2
{
	asm_row.clear();
	string s;
	//s+=ConvertQuadCode(QEA);asm_row.push_back(s);
	s="";
	OpNumRM RS,RT;//临时创造2个寄存器$s3,$s4
	RS.isReg=true;RS.REG="$s3";
	RT.isReg=true;RT.REG="$s4";
	vector<string> mov_tr;//mov翻译的代码
	QER_ASM t_QA;//临时作为传送翻译用
	//
	INF_VAR IV_RS=Convert_OpNumRM_INF_VAR(QEA.RS);
	INF_VAR IV_RT=Convert_OpNumRM_INF_VAR(QEA.RT);
	INF_VAR IV_RD=Convert_OpNumRM_INF_VAR(QEA.RD);
	//
	s="";s="BEQ ";
	if(IV_RS.type==ON_REG)
	{
		s+=IV_RS.REG;s+=",";
	}
	else
	{
		//传送RS
		t_QA.RS=QEA.RS;t_QA.RD=RS;t_QA.OP="MOV";//mov rs,$s3
		MOV_Translate(t_QA,mov_tr);
		MergeAsm(asm_row,mov_tr);
		s+="$s3,";
	}
	if(IV_RT.type==ON_REG)
	{
		s+=IV_RT.REG;s+=",";
	}
	else
	{
		//传送RT
		t_QA.RS=QEA.RT;t_QA.RD=RT;t_QA.OP="MOV";//mov rs,$s4
		MOV_Translate(t_QA,mov_tr);
		MergeAsm(asm_row,mov_tr);
		s+="$s4,";
	}
	if(IV_RD.type==ON_LAB)
	{
		s+=IV_RD.LAB;
	}
	else
	{
		s+="ERROR";
	}
	asm_row.push_back(s);
	//计算代码
	//计算完毕，有MOV就是方便
}

void BNE_Translate(QER_ASM &QEA,vector<string> &asm_row) //NOT的翻译,2
{
	asm_row.clear();
	string s;
	//s+=ConvertQuadCode(QEA);asm_row.push_back(s);
	s="";
	OpNumRM RS,RT;//临时创造2个寄存器$s3,$s4
	RS.isReg=true;RS.REG="$s3";
	RT.isReg=true;RT.REG="$s4";
	vector<string> mov_tr;//mov翻译的代码
	QER_ASM t_QA;//临时作为传送翻译用
	//
	INF_VAR IV_RS=Convert_OpNumRM_INF_VAR(QEA.RS);
	INF_VAR IV_RT=Convert_OpNumRM_INF_VAR(QEA.RT);
	INF_VAR IV_RD=Convert_OpNumRM_INF_VAR(QEA.RD);
	//
	s="";s="BNE ";
	if(IV_RS.type==ON_REG)
	{
		s+=IV_RS.REG;s+=",";
	}
	else
	{
		//传送RS
		t_QA.RS=QEA.RS;t_QA.RD=RS;t_QA.OP="MOV";//mov rs,$s3
		MOV_Translate(t_QA,mov_tr);
		MergeAsm(asm_row,mov_tr);
		s+="$s3,";
	}
	if(IV_RT.type==ON_REG)
	{
		s+=IV_RS.REG;s+=",";
	}
	else
	{
		//传送RT
		t_QA.RS=QEA.RT;t_QA.RD=RT;t_QA.OP="MOV";//mov rs,$s4
		MOV_Translate(t_QA,mov_tr);
		MergeAsm(asm_row,mov_tr);
		s+="$s4,";
	}
	if(IV_RD.type==ON_LAB)
	{
		s+=IV_RD.LAB;
	}
	else
	{
		s+="ERROR";
	}
	asm_row.push_back(s);
	//计算代码
	//计算完毕，有MOV就是方便
}

void LOD_Translate(QER_ASM &QEA,vector<string> &asm_row) //LOD的翻译,2
{
	asm_row.clear();
	string s;
	//s+=ConvertQuadCode(QEA);asm_row.push_back(s);
	s="";
	OpNumRM RS,RD;//临时创造1个寄存器$s3
	RS.isReg=true;RS.REG="$s3";
	RD.isReg=true;RD.REG="$s4";
	vector<string> mov_tr;//mov翻译的代码
	QER_ASM t_QA;//临时作为传送翻译用
	//
	INF_VAR IV_RS=Convert_OpNumRM_INF_VAR(QEA.RS);
	//INF_VAR IV_RT=Convert_OpNumRM_INF_VAR(QEA.RT);
	INF_VAR IV_RD=Convert_OpNumRM_INF_VAR(QEA.RD);
	//
	if(IV_RS.type==ON_REG&&IV_RD.type==ON_REG)
	{
		s="";s="LW ";s+=IV_RD.REG;s+=",";s+="0000H(";
		s+=IV_RS.REG;s+=")";
		asm_row.push_back(s);//LW rd,(rs)
	}
	else if(IV_RS.type==ON_REG)
	{
		s="";s="LW $s4,";s+="0000H(";
		s+=IV_RS.REG;s+=")";
		asm_row.push_back(s);//LW $S4,(rs)
		//回写RD
		t_QA.OP="MOV";t_QA.RS=RD;t_QA.RD=QEA.RD;//MOV $s4,rd
		MOV_Translate(t_QA,mov_tr);
		MergeAsm(asm_row,mov_tr);
	}
	else if(IV_RD.type==ON_REG)
	{
		//传送RS
		t_QA.RS=QEA.RS;t_QA.RD=RS;t_QA.OP="MOV";//mov rs,$s3
		MOV_Translate(t_QA,mov_tr);
		MergeAsm(asm_row,mov_tr);
		//计算代码
		s="";s="LW ";s+=IV_RD.REG;s+=",0000H($s3)";asm_row.push_back(s);//LW $s4,(RS)
	}
	else
	{
		//传送RS
		t_QA.RS=QEA.RS;t_QA.RD=RS;t_QA.OP="MOV";//mov rs,$s3
		MOV_Translate(t_QA,mov_tr);
		MergeAsm(asm_row,mov_tr);
		//计算代码
		s="";s="LW $s4,0000H($s3)";asm_row.push_back(s);//LW $s4,(RS)
		//回写RD
		t_QA.OP="MOV";t_QA.RS=RD;t_QA.RD=QEA.RD;//MOV $s4,rd
		MOV_Translate(t_QA,mov_tr);
		MergeAsm(asm_row,mov_tr);
	}
	//计算完毕，有MOV就是方便
}

void SAV_Translate(QER_ASM &QEA,vector<string> &asm_row) //SAV的翻译,2
{
	asm_row.clear();
	string s;
	//s+=ConvertQuadCode(QEA);asm_row.push_back(s);
	s="";
	OpNumRM RS,RD;//临时创造1个寄存器$s3
	RS.isReg=true;RS.REG="$s3";
	RD.isReg=true;RD.REG="$s4";
	vector<string> mov_tr;//mov翻译的代码
	QER_ASM t_QA;//临时作为传送翻译用
	//
	INF_VAR IV_RS=Convert_OpNumRM_INF_VAR(QEA.RS);
	//INF_VAR IV_RT=Convert_OpNumRM_INF_VAR(QEA.RT);
	INF_VAR IV_RD=Convert_OpNumRM_INF_VAR(QEA.RD);
	//
	if(IV_RS.type==ON_REG&&IV_RD.type==ON_REG)
	{
		s="";s="SW ";s+=IV_RS.REG;s+=",";s+="0000H(";
		s+=IV_RD.REG;s+=")";
		asm_row.push_back(s);//SW rs,(rd)
	}
	else if(IV_RS.type==ON_REG)
	{
		//传送RD
		t_QA.OP="MOV";t_QA.RS=QEA.RD;t_QA.RD=RD;//MOV rd,$s4
		MOV_Translate(t_QA,mov_tr);
		MergeAsm(asm_row,mov_tr);
		s="";s="SW ";s+=IV_RS.REG;s+=",";s+="0000H($s4)";
		asm_row.push_back(s);//SW rs,(rd)
	}
	else if(IV_RD.type==ON_REG)
	{
		//传送RS
		t_QA.RS=QEA.RS;t_QA.RD=RS;t_QA.OP="MOV";//mov rs,$s3
		MOV_Translate(t_QA,mov_tr);
		MergeAsm(asm_row,mov_tr);
		//计算代码
		s="";s="SW $s3,0000H(";s+=IV_RD.REG;s+=")";asm_row.push_back(s);//SW rs,(Rd)
	}
	else
	{
		//传送RS
		t_QA.RS=QEA.RS;t_QA.RD=RS;t_QA.OP="MOV";//mov rs,$s3
		MOV_Translate(t_QA,mov_tr);
		MergeAsm(asm_row,mov_tr);
		//传送RD
		t_QA.OP="MOV";t_QA.RS=QEA.RD;t_QA.RD=RD;//MOV rd,$s4
		MOV_Translate(t_QA,mov_tr);
		MergeAsm(asm_row,mov_tr);
		//计算代码
		s="";s="SW $s3,0000H($s4)";asm_row.push_back(s);//SW $ss,(rd)
	}
	//计算代码
	//计算完毕，有MOV就是方便
}

void LDA_Translate(QER_ASM &QEA,vector<string> &asm_row) //LDA的翻译,2
{
	asm_row.clear();
	string s;
	//s+=ConvertQuadCode(QEA);asm_row.push_back(s);
	s="";
	OpNumRM RD;//临时创造1个寄存器
	RD.isReg=true;RD.REG="$s3";
	vector<string> mov_tr;//mov翻译的代码
	QER_ASM t_QA;//临时作为传送翻译用
	//
	INF_VAR IV=Convert_OpNumRM_INF_VAR(QEA.RS);//得到RS信息
	if(IV.type!=ON_MEM)
	{
		if(!isDebug) {
			cout<<"翻译LDA中,RS不是数组名字!"<<"\r\n";
		} else {
			err_lst<<"翻译LDA中,RS不是数组名字!"<<"\r\n";
		}
		
		return;
	}
	else
	{
		if(IV.VP.type==INT&&IV.VP.isArray==true)
		{
			//计算数组的地址，传给$s3
			char off[10];HexTrans(IV.VP.offset,off);//itoa(IV.VP.offset,off,10);//转换偏移量
			//1.全局数组
			if(IV.VP.FunName.length()==0)
			{
				s="";s="ORI $s3,$zero,";s+=off;asm_row.push_back(s);
			}
			else
			{
				s="";s="ORI $s4,$zero,";s+=off;asm_row.push_back(s);
				//加上$sp的值
				s="ADD $s3,$s4,$sp";asm_row.push_back(s);
			}
			//传送到RD;
			t_QA.OP="MOV";t_QA.RS=RD;t_QA.RD=QEA.RD;
			MOV_Translate(t_QA,mov_tr);
			MergeAsm(asm_row,mov_tr);
		}
		else
		{
			if(!isDebug) {
				cout<<"翻译LDA中,RS不是数组名字!"<<"\r\n";
			} else {
				err_lst<<"翻译LDA中,RS不是数组名字!"<<"\r\n";
			}
			return;
		}
	}
	//计算完毕，有MOV就是方便
}

void PARAM_Translate(QER_ASM &QEA,vector<string> &asm_row) //PARAM的翻译,2
{
	asm_row.clear();
	string s;
	//s+=ConvertQuadCode(QEA);asm_row.push_back(s);
	s="";
	INF_VAR RS=Convert_OpNumRM_INF_VAR(QEA.RS);
	INF_VAR RD=Convert_OpNumRM_INF_VAR(QEA.RD);
	OpNumRM temp;temp.isReg=true;temp.REG="$s3";//作为传递中间寄存器
	QER_ASM t_QA;//临时作为传送翻译用
	vector<string> mov_tr;//mov翻译的代码

	t_QA.OP="MOV";
	t_QA.RS=QEA.RS;
	t_QA.RD=temp;
	MOV_Translate(t_QA,mov_tr);
	MergeAsm(asm_row,mov_tr); //mov rs,$s3

	//计算RD偏移量
	if(RD.type!=ON_MEM)
	{
		if(!isDebug) {
			cout<<"参数传递中，目标形参不是内存数类型!"<<"\r\n";
		} else {
			err_lst<<"参数传递中，目标形参不是内存数类型!"<<"\r\n";
		}
		
		return;
	}
	char off[10];HexTrans(RD.VP.offset,off);//itoa(RD.VP.offset,off,10);
	s="";
	s="SW $s3,";s+=off;s+="($s9)";asm_row.push_back(s);//top==$s9

}

void LABEL_Translate(QER_ASM &QEA,vector<string> &asm_row) //LABEL的翻译,2
{
	asm_row.clear();
	string s;
	//s+=ConvertQuadCode(QEA);asm_row.push_back(s);
	s="";
	s="";s+=QEA.RS.ON.label;s+=":";asm_row.push_back(s);
}

void CALL_Translate(QER_ASM &QEA,vector<string> &asm_row) //CALL的翻译,2
{
	asm_row.clear();
	string s;
	//s+=ConvertQuadCode(QEA);asm_row.push_back(s);
	s="";
	//
	s="";s="JAL ";s+=QEA.RS.ON.label;asm_row.push_back(s);//JAL fun
	//
	OpNumRM RD;//
	RD.isReg=true;RD.REG="$v0";//返回值
	vector<string> mov_tr;//mov翻译的代码
	QER_ASM t_QA;//临时作为传送翻译用
	//传送RD
	t_QA.RS=RD;t_QA.RD=QEA.RD;t_QA.OP="MOV";//mov $v0,rd
	MOV_Translate(t_QA,mov_tr);
	MergeAsm(asm_row,mov_tr);
	//计算完毕，有MOV就是方便
}
////////MLT,DIV,MOD/////////////////////////

//MOV_Translate(QER_ASM &QEA,vector<string> &asm_row),最多可用掉3个REG,故应该从$s3~$s8中选择使用
void MLT_Translate(QER_ASM &QEA,vector<string> &asm_row) //ADD的翻译,2
{
	asm_row.clear();
	string s;
	//s+=ConvertQuadCode(QEA);asm_row.push_back(s);
	s="";
	OpNumRM RS,RT,RD;//临时创造2+1个寄存器$s3,$s4,$s5
	RS.isReg=true;RS.REG="$s3";
	RT.isReg=true;RT.REG="$s4";
	RD.isReg=true;RD.REG="$s5";
	vector<string> mov_tr;//mov翻译的代码
	QER_ASM t_QA;//临时作为传送翻译用
	//
	INF_VAR IV_RS=Convert_OpNumRM_INF_VAR(QEA.RS);
	INF_VAR IV_RT=Convert_OpNumRM_INF_VAR(QEA.RT);
	//
	//传送RS
	t_QA.RS=QEA.RS;t_QA.RD=RS;t_QA.OP="MOV";//mov rs,$s3
	MOV_Translate(t_QA,mov_tr);
	MergeAsm(asm_row,mov_tr);
	//传送RT
	t_QA.RS=QEA.RT;t_QA.RD=RT;t_QA.OP="MOV";//mov rt,$s4
	MOV_Translate(t_QA,mov_tr);
	MergeAsm(asm_row,mov_tr);
    s="";s="mult $s3,$s4";asm_row.push_back(s);
    s="";s="mflo $s5";asm_row.push_back(s);
	//计算代码
//	string exits3=Gen_New_Label();
//	string exits4=Gen_New_Label();
//	string beg=Gen_New_Label();
//	string next=Gen_New_Label();
//	string exit=Gen_New_Label();
//	string okresult=Gen_New_Label();
//	//先生成标签
//	//计算代码
//	s="";s="lui $s0,8000H";asm_row.push_back(s);
//	s="";s="ori $s2,$zero,0000H";asm_row.push_back(s);
//	s="";s="and $s1,$s3,$s0";asm_row.push_back(s);
//    s="";s="beq $s1,$zero,";s+=exits3;asm_row.push_back(s);
//	s="";s="nor $s3,$zero,$s3";asm_row.push_back(s);
//	s="";s="addi $s3,$s3,0001H";asm_row.push_back(s);
//	s="";s="ori $s2,$zero,0001H";asm_row.push_back(s);
//	s="";s="J ";s+=exits3;asm_row.push_back(s);
//	s="";s=exits3;s+=":";asm_row.push_back(s);
//	//=======================================
//	s="";s="and $s1,$s4,$s0";asm_row.push_back(s);
//    s="";s="beq $s1,$zero,";s+=exits4;asm_row.push_back(s);
//	s="";s="nor $s4,$zero,$s4";asm_row.push_back(s);
//	s="";s="addi $s4,$s4,0001H";asm_row.push_back(s);
//	s="";s="xori $s2,$zero,0001H";asm_row.push_back(s);
//	s="";s="J ";s+=exits4;asm_row.push_back(s);
//	s="";s=exits4;s+=":";asm_row.push_back(s);
//	//=========================================
//	s="";s="ori $s5,$zero,0000H";asm_row.push_back(s);
//	s="";s="ori $s7,$zero,0001H";asm_row.push_back(s);
//	s="";s=beg;s+=":";asm_row.push_back(s);
//	s="";s="and $s6,$s7,$s4";asm_row.push_back(s);
//	s="";s="srl $s4,$s4,1";asm_row.push_back(s);
//	s="";s="beq $s6,$zero,";s+=next;asm_row.push_back(s);
//	s="";s="add $s5,$s5,$s3";asm_row.push_back(s);
//	s="";s=next;s+=":";asm_row.push_back(s);
//    s="";s="sll $s3,$s3,1";asm_row.push_back(s);
//	s="";s="beq $s4,$zero,";s+=exit;asm_row.push_back(s);
//	s="";s="J ";s+=beg;asm_row.push_back(s);
//	s="";s=exit;s+=":";asm_row.push_back(s);
//	//=========================================
//	s="";s="beq $s2,$zero,";s+=okresult;asm_row.push_back(s);
//	s="";s="nor $s5,$zero,$s5";asm_row.push_back(s);
//	s="";s="addi $s5,$s5,0001H";asm_row.push_back(s);
//	s="";s=okresult;s+=":";asm_row.push_back(s);
//	//=========================================
//	//只传送低32位
//	s="";s+="or $s5,$zero,$s5";asm_row.push_back(s);
//	//
	//结果回写,$s5->RD
	t_QA.RS=RD;t_QA.RD=QEA.RD;t_QA.OP="MOV";//mov $s5,rd
	MOV_Translate(t_QA,mov_tr);
	MergeAsm(asm_row,mov_tr);
	//计算完毕，有MOV就是方便
}

void DIV_Translate(QER_ASM &QEA,vector<string> &asm_row) //ADD的翻译,2
{
	asm_row.clear();
	string s;
	//s+=ConvertQuadCode(QEA);asm_row.push_back(s);
	s="";
	OpNumRM RS,RT,RD;//临时创造2+1个寄存器$s3,$s4,$s5
	RS.isReg=true;RS.REG="$s3";
	RT.isReg=true;RT.REG="$s4";
	RD.isReg=true;RD.REG="$s5";
	vector<string> mov_tr;//mov翻译的代码
	QER_ASM t_QA;//临时作为传送翻译用
	//
	INF_VAR IV_RS=Convert_OpNumRM_INF_VAR(QEA.RS);
	INF_VAR IV_RT=Convert_OpNumRM_INF_VAR(QEA.RT);
	//
	//传送RS
	t_QA.RS=QEA.RS;t_QA.RD=RS;t_QA.OP="MOV";//mov rs,$s3
	MOV_Translate(t_QA,mov_tr);
	MergeAsm(asm_row,mov_tr);
	//传送RT
	t_QA.RS=QEA.RT;t_QA.RD=RT;t_QA.OP="MOV";//mov rt,$s4
	MOV_Translate(t_QA,mov_tr);
	MergeAsm(asm_row,mov_tr);
	//计算代码
	//先加入标号
	string exits3=Gen_New_Label();
	string exits4=Gen_New_Label();
	string bk=Gen_New_Label();
	string result=Gen_New_Label();
	string okresult=Gen_New_Label();
	string FINISH=Gen_New_Label();
	//计算代码
	s="";s="ORI $s5,$zero,0000H";asm_row.push_back(s);
	s="";s="BEQ $4,$s5,";s+=FINISH;asm_row.push_back(s);//判断除数0
	//正式计算
	s="";s="lui $s0,8000H";asm_row.push_back(s);
	s="";s="ori $s2,$zero,0000H";asm_row.push_back(s);
	s="";s="and $s1,$s3,$s0";asm_row.push_back(s);
    s="";s="beq $s1,$zero,";s+=exits3;asm_row.push_back(s);
	s="";s="nor $s3,$zero,$s3";asm_row.push_back(s);
	s="";s="addi $s3,$s3,0001H";asm_row.push_back(s);
	s="";s="ori $s2,$zero,0001H";asm_row.push_back(s);
	s="";s="J ";s+=exits3;asm_row.push_back(s);
	s="";s=exits3;s+=":";asm_row.push_back(s);
	//=======================================
	s="";s="and $s1,$s4,$s0";asm_row.push_back(s);
    s="";s="beq $s1,$zero,";s+=exits4;asm_row.push_back(s);
	s="";s="nor $s4,$zero,$s4";asm_row.push_back(s);
	s="";s="addi $s4,$s4,0001H";asm_row.push_back(s);
	s="";s="xori $s2,$zero,0001H";asm_row.push_back(s);
	s="";s="J ";s+=exits4;asm_row.push_back(s);
	s="";s=exits4;s+=":";asm_row.push_back(s);
	//=========================================
	s="";s="ori $s5,$zero,0000H";asm_row.push_back(s);
	s="";s=bk;s+=":";asm_row.push_back(s);
	s="";s="slt $s8,$s3,$s4";asm_row.push_back(s);
	s="";s="bne $s8,$zero,";s+=result;asm_row.push_back(s);
	s="";s="addi $s5,$s5,0001H";asm_row.push_back(s);
	s="";s="sub $s3,$s3,$s4";asm_row.push_back(s);
	s="";s="J ";s+=bk;asm_row.push_back(s);
	s="";s=result;s+=":";asm_row.push_back(s);
	//=========================================
	s="";s="beq $s2,$zero,";s+=okresult;asm_row.push_back(s);
	s="";s="nor $s5,$zero,$s5";asm_row.push_back(s);
	s="";s="addi $s5,$s5,0001H";asm_row.push_back(s);
	s="";s=okresult;s+=":";asm_row.push_back(s);
	//=========================================
	//传送商给结果
	s="";s="OR $s5,$zero,$s5";asm_row.push_back(s);
	s="";s=FINISH;s+=":";asm_row.push_back(s);
	//结果回写,$s5->RD
	t_QA.RS=RD;t_QA.RD=QEA.RD;t_QA.OP="MOV";//mov $s5,rd
	MOV_Translate(t_QA,mov_tr);
	MergeAsm(asm_row,mov_tr);
	//计算完毕，有MOV就是方便
}

void MOD_Translate(QER_ASM &QEA,vector<string> &asm_row) //ADD的翻译,2
{
	asm_row.clear();
	string s;
	//s+=ConvertQuadCode(QEA);asm_row.push_back(s);
	s="";
	OpNumRM RS,RT,RD;//临时创造2+1个寄存器$s3,$s4,$s5
	RS.isReg=true;RS.REG="$s3";
	RT.isReg=true;RT.REG="$s4";
	RD.isReg=true;RD.REG="$s5";
	vector<string> mov_tr;//mov翻译的代码
	QER_ASM t_QA;//临时作为传送翻译用
	//
	INF_VAR IV_RS=Convert_OpNumRM_INF_VAR(QEA.RS);
	INF_VAR IV_RT=Convert_OpNumRM_INF_VAR(QEA.RT);
	//
	//传送RS
	t_QA.RS=QEA.RS;t_QA.RD=RS;t_QA.OP="MOV";//mov rs,$s3
	MOV_Translate(t_QA,mov_tr);
	MergeAsm(asm_row,mov_tr);
	//传送RT
	t_QA.RS=QEA.RT;t_QA.RD=RT;t_QA.OP="MOV";//mov rt,$s4
	MOV_Translate(t_QA,mov_tr);
	MergeAsm(asm_row,mov_tr);
	//计算代码
	//先加入标号
	string exits3=Gen_New_Label();
	string exits4=Gen_New_Label();
	string bk=Gen_New_Label();
	string result=Gen_New_Label();
	string okresult=Gen_New_Label();
	string FINISH=Gen_New_Label();
	//计算代码
	s="";s="ORI $s5,$zero,0000H";asm_row.push_back(s);
	s="";s="BEQ $4,$s5,";s+=FINISH;asm_row.push_back(s);//判断除数0
	//正式计算
	s="";s="lui $s0,8000H";asm_row.push_back(s);
	s="";s="ori $s2,$zero,0000H";asm_row.push_back(s);
	s="";s="and $s1,$s3,$s0";asm_row.push_back(s);
    s="";s="beq $s1,$zero,";s+=exits3;asm_row.push_back(s);
	s="";s="nor $s3,$zero,$s3";asm_row.push_back(s);
	s="";s="addi $s3,$s3,0001H";asm_row.push_back(s);
	s="";s="ori $s2,$zero,0001H";asm_row.push_back(s);
	s="";s="J ";s+=exits3;asm_row.push_back(s);
	s="";s=exits3;s+=":";asm_row.push_back(s);
	//=======================================
	s="";s="and $s1,$s4,$s0";asm_row.push_back(s);
    s="";s="beq $s1,$zero,";s+=exits4;asm_row.push_back(s);
	s="";s="nor $s4,$zero,$s4";asm_row.push_back(s);
	s="";s="addi $s4,$s4,0001H";asm_row.push_back(s);
	s="";s="xori $s2,$zero,0001H";asm_row.push_back(s);
	s="";s="J ";s+=exits4;asm_row.push_back(s);
	s="";s=exits4;s+=":";asm_row.push_back(s);
	//=========================================
	s="";s="ori $s5,$zero,0000H";asm_row.push_back(s);
	s="";s=bk;s+=":";asm_row.push_back(s);
	s="";s="slt $s8,$s3,$s4";asm_row.push_back(s);
	s="";s="bne $s8,$zero,";s+=result;asm_row.push_back(s);
	s="";s="addi $s5,$s5,0001H";asm_row.push_back(s);
	s="";s="sub $s3,$s3,$s4";asm_row.push_back(s);
	s="";s="J ";s+=bk;asm_row.push_back(s);
	s="";s=result;s+=":";asm_row.push_back(s);
	//=========================================
	s="";s="beq $s2,$zero,";s+=okresult;asm_row.push_back(s);
	s="";s="nor $s3,$zero,$s3";asm_row.push_back(s);
	s="";s="addi $s3,$s3,0001H";asm_row.push_back(s);
	s="";s=okresult;s+=":";asm_row.push_back(s);
	//=========================================
	//传送余数给结果
	s="";s="OR $s5,$zero,$s3";asm_row.push_back(s);
	s="";s=FINISH;s+=":";asm_row.push_back(s);
	//结果回写,$s5->RD
	t_QA.RS=RD;t_QA.RD=QEA.RD;t_QA.OP="MOV";//mov $s5,rd
	MOV_Translate(t_QA,mov_tr);
	MergeAsm(asm_row,mov_tr);
	//计算完毕，有MOV就是方便
}

#endif  //ASM_TRANSLATE_H

