#ifndef FUNCTIONMODULEASM_H
#define FUNCTIONMODULEASM_H

#pragma once
#include"ASM_TRANSLATE.h"
#include "StdAfx.h"
#include "FunctionForest.h"
#include "SEM_GLOBAL_INF.H"
#include "RegDisattribute.h"

//函数块的完整翻译


class Fun_ASM
{
public:
	vector<string> ASM;
	string Name;
	Fun_ASM()
	{
		Name="";
		ASM.clear();
	}
	Fun_ASM(const Fun_ASM &copy)
	{
		ASM=copy.ASM;
		Name=copy.Name;
	}
};

//全局用于保存函数模块的代码
vector<Fun_ASM>  FA_ASM;
//函数块
bool FindRegInASM(string reg,vector<string> asm_c)
{
	bool exist=false;
	for(int i=0;i<asm_c.size();i++)
	{
		if(asm_c[i].find(reg)>=0&&asm_c[i].find(reg)<asm_c[i].length())
		{
			return true;
		}
	}
	return exist;
}

void PreFunAsmTrans(Forest_REG &FR,Fun_ASM &FA)//进行函数体中间代码的翻译，确定寄存器使用，生成特定的恢复代码
{
	string OneRow="";//一行内容
	FA.ASM.clear();
	FA.Name=FR.Fun_Name;
	//保存reg代码
	vector<string> sav_reg;
	//恢复reg代码
	vector<string> lod_reg;
	//获得函数表
	Function_Table *FT=MST.GetFunction_Table(FR.Fun_Name);
	//原来的top
	int top=FT->top;//进行reg保存的分配
	//地址-reg的映射
	map<int,string> ADD_REG;
	if(FT==0)
	{
		return;
	}
	//开始函数体的翻译
	//先翻译一个返回模块，不带返回值的
	vector<string> ret_stmt;
	if(FR.Fun_Name.compare("interuptServer0")==0||FR.Fun_Name.compare("interuptServer1")==0)
	{
	}
	else
	{
		OneRow="";OneRow="LW $at,0004H($sp)";ret_stmt.push_back(OneRow);//加载返回地址
	}
	OneRow="";OneRow="LW $s9,0008H($sp)";ret_stmt.push_back(OneRow);//加载原来的top
	OneRow="";OneRow="LW $sp,0000H($sp)";ret_stmt.push_back(OneRow);//加载原来的SP
	if(FR.Fun_Name.compare("interuptServer0")==0)
	{
		OneRow="";OneRow="JR $i0";ret_stmt.push_back(OneRow);//返回
	}
	else if(FR.Fun_Name.compare("interuptServer1")==0)
	{
		OneRow="";OneRow="JR $i1";ret_stmt.push_back(OneRow);//返回
	}
	else
	{
		OneRow="";OneRow="JR $at";ret_stmt.push_back(OneRow);//返回
	}
	//体翻译
	//返回代码减少法优化
	vector<QER_ASM> &SEM=FR.SC.CODE;//建立引用
	bool add_new_ret_lab=false;
	string RETURN_LABEL="";
	if(SEM.size()>0)
	{
		if(SEM[SEM.size()-1].OP.compare("LABEL")==0)
		{
			RETURN_LABEL=SEM[SEM.size()-1].RS.ON.label;//返回的下标
		}
		else
		{
			RETURN_LABEL=Gen_New_Label();
			add_new_ret_lab=true;
		}
	}
	//
	for(int i=0;i<SEM.size();i++)
	{
		vector<string> t_sec;//中间的缓存
		if(SEM[i].OP.compare("LABEL")==0)
		{
			LABEL_Translate(SEM[i],t_sec);
			MergeAsm(FA.ASM,t_sec);
		}
		else if(SEM[i].OP.compare("ADD")==0)
		{
			ADD_Translate(SEM[i],t_sec);
			MergeAsm(FA.ASM,t_sec);
		}
		else if(SEM[i].OP.compare("SUB")==0)
		{
			SUB_Translate(SEM[i],t_sec);
			MergeAsm(FA.ASM,t_sec);
		}
		else if(SEM[i].OP.compare("MUL")==0)
		{
			MLT_Translate(SEM[i],t_sec);
			MergeAsm(FA.ASM,t_sec);
		}
		else if(SEM[i].OP.compare("DIV")==0)
		{
			DIV_Translate(SEM[i],t_sec);
			MergeAsm(FA.ASM,t_sec);
		}
		else if(SEM[i].OP.compare("MOD")==0)
		{
			MOD_Translate(SEM[i],t_sec);
			MergeAsm(FA.ASM,t_sec);
		}
		else if(SEM[i].OP.compare("MOV")==0)
		{
			MOV_Translate(SEM[i],t_sec);
			MergeAsm(FA.ASM,t_sec);
		}
		else if(SEM[i].OP.compare("SLLV")==0)
		{
			LSHIFT_Translate(SEM[i],t_sec);
			MergeAsm(FA.ASM,t_sec);
		}
		else if(SEM[i].OP.compare("SRLV")==0)
		{
			RSHIFT_Translate(SEM[i],t_sec);
			MergeAsm(FA.ASM,t_sec);
		}
		else if(SEM[i].OP.compare("SLT")==0)
		{
			SLT_Translate(SEM[i],t_sec);
			MergeAsm(FA.ASM,t_sec);
		}
		else if(SEM[i].OP.compare("BEQ")==0)
		{
			BEQ_Translate(SEM[i],t_sec);
			MergeAsm(FA.ASM,t_sec);
		}
		else if(SEM[i].OP.compare("GOTO")==0)
		{
			GOTO_Translate(SEM[i],t_sec);
			MergeAsm(FA.ASM,t_sec);
		}
		else if(SEM[i].OP.compare("BNE")==0)
		{
			BNE_Translate(SEM[i],t_sec);
			MergeAsm(FA.ASM,t_sec);
		}
		else if(SEM[i].OP.compare("LDA")==0)
		{
			LDA_Translate(SEM[i],t_sec);
			MergeAsm(FA.ASM,t_sec);
		}
		else if(SEM[i].OP.compare("CALL")==0)
		{
			CALL_Translate(SEM[i],t_sec);
			MergeAsm(FA.ASM,t_sec);
		}
		else if(SEM[i].OP.compare("LOD")==0)
		{
			LOD_Translate(SEM[i],t_sec);
			MergeAsm(FA.ASM,t_sec);
		}
		else if(SEM[i].OP.compare("SAV")==0)
		{
			SAV_Translate(SEM[i],t_sec);
			MergeAsm(FA.ASM,t_sec);
		}
		else if(SEM[i].OP.compare("OR")==0)
		{
			OR_Translate(SEM[i],t_sec);
			MergeAsm(FA.ASM,t_sec);
		}
		else if(SEM[i].OP.compare("AND")==0)
		{
			AND_Translate(SEM[i],t_sec);
			MergeAsm(FA.ASM,t_sec);
		}
		else if(SEM[i].OP.compare("NOT")==0)
		{
			NOT_Translate(SEM[i],t_sec);
			MergeAsm(FA.ASM,t_sec);
		}
		else if(SEM[i].OP.compare("XOR")==0)
		{
			XOR_Translate(SEM[i],t_sec);
			MergeAsm(FA.ASM,t_sec);
		}
		else if(SEM[i].OP.compare("PARAM")==0)
		{
			PARAM_Translate(SEM[i],t_sec);
			MergeAsm(FA.ASM,t_sec);
		}
		else if(SEM[i].OP.compare("RET")==0)
		{
			OpNumRM RD;//
			vector<string> mov_tr;//mov翻译的代码
			QER_ASM t_QA;//临时作为传送翻译用
			t_QA.OP="MOV";
			RD.isReg=true;
			RD.REG="$v0";
			t_QA.RD=RD;
			t_QA.RS=SEM[i].RD;
			MOV_Translate(t_QA,mov_tr);//MOV RD,$v0
			MergeAsm(FA.ASM,mov_tr);
			//跳到返回区
			string J_R="J ";J_R+=RETURN_LABEL;
			FA.ASM.push_back(J_R);
		}
		else if(SEM[i].OP.compare("RETN")==0)
		{
			//跳到返回区
			string J_R="J ";J_R+=RETURN_LABEL;
			FA.ASM.push_back(J_R);
		}
		else
		{
		}
	}
	//函数体翻译完毕
	//统计寄存器使用，建立寄存器映射
	for(int i=0;i<10;i++)
	{
		char a[10];_itoa_s(i,a,10);
		string s="$s";s+=a;
		if(FindRegInASM(s,FA.ASM)&&i!=9)
		{
			ADD_REG[top]=s;
			FT->top=top+4;
			top=FT->top;
		}
		s="$t";s+=a;
		if(FindRegInASM(s,FA.ASM)&&i!=9)
		{
			ADD_REG[top]=s;
			FT->top=top+4;
			top=FT->top;
		}
	}
	//中断函数可能通过调用其他函数破环$at,要保护$at//中断函数可能通过调用其他函数破环$v0,要保护$v0
	if(FR.Fun_Name.compare("interuptServer0")==0||FR.Fun_Name.compare("interuptServer1")==0)
	{
		string s="$at";
		ADD_REG[top]=s;
		FT->top=top+4;
		top=FT->top;
		s="$v0";
		ADD_REG[top]=s;
		FT->top=top+4;
		top=FT->top;
	}
	//产生保存/恢复寄存器代码
	map<int,string>::iterator irg=ADD_REG.begin();
	for(irg=ADD_REG.begin();irg!=ADD_REG.end();irg++)
	{
		int add=(*irg).first;
		string rn=(*irg).second;
		string add_hex=HexTrans(add);
		string code="SW ";code+=rn;code+=",";code+=add_hex;code+="($sp)";//保存
		sav_reg.push_back(code);
		code="LW ";code+=rn;code+=",";code+=add_hex;code+="($sp)";//恢复
		lod_reg.push_back(code);
	}
	//最后再加一个返回，并初始化
	//优化返回代码，减少代码冗余
	//返回恢复活动记录
	if(add_new_ret_lab==true)
	{
		string RT_L=RETURN_LABEL;
		RT_L+=":";
		FA.ASM.push_back(RT_L);
	}
	MergeAsm(FA.ASM,lod_reg);//恢复寄存器
	MergeAsm(FA.ASM,ret_stmt);
	MergeAsm(sav_reg,FA.ASM);//保存寄存器
	FA.ASM=sav_reg;//一切OK
}

void TransForest_REGToFunASM(Forest_REG &FR,Fun_ASM &FA)//进行函数中间代码到汇编的翻译
{
	string OneRow="";//一行内容
	FA.ASM.clear();
	FA.Name=FR.Fun_Name;
	//先分析寄存器使用
	Fun_ASM temp;
	PreFunAsmTrans(FR,temp);
	//先生成头部数据,SP,TOP等的初始化,两大类，普通和中断
	OneRow="SW $sp,0000H($s9)";FA.ASM.push_back(OneRow);//保存老SP->0[top]
	//保存返回地址
	if(FA.Name.compare("interuptServer0")==0)
	{
		//OneRow="";
		//OneRow="SW $i0,0004H($s9)";FA.ASM.push_back(OneRow);
	}
	else if(FA.Name.compare("interuptServer1")==0)
	{
		//OneRow="";
		//OneRow="SW $i1,0004H($s9)";FA.ASM.push_back(OneRow);
	}
	else
	{
		OneRow="";
		OneRow="SW $ra,0004H($s9)";FA.ASM.push_back(OneRow);
	}
	//保存TOP指针
	OneRow="";
	OneRow="SW $s9,0008H($s9)";FA.ASM.push_back(OneRow);
	//重新初始化sp,top指针
	OneRow="";
	OneRow="OR $sp,$zero,$s9";FA.ASM.push_back(OneRow);//sp初始化
	//top
	OneRow="";
	Function_Table *FT=MST.GetFunction_Table(FA.Name);
	char top[10];
	if(FT!=0)
	{
		HexTrans(FT->top,top);//
		//itoa(FT->top,top,10);
	}
	else
	{
		if(!isDebug) {
			cout<<"内部错误，函数居然不存在!"<<"\r\n";
		} else {
			err_lst<<"内部错误，函数居然不存在!"<<"\r\n";
		}
		return;
	}
	OneRow="ADDI $s9,$sp,";
	OneRow+=top;
	FA.ASM.push_back(OneRow);//top初始化
	OneRow="";//OneRow=";sp,top,返回地址初始化";FA.ASM.push_back(OneRow);
	//加入体代码
	MergeAsm(FA.ASM,temp.ASM);
}

#endif //FUNCTIONMODULEASM_H
