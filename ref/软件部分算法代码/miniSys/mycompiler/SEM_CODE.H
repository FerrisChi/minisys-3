#ifndef SEM_CODE_H
#define SEM_CODE_H
#pragma once

#include "Structure_Base.h"

//
//临时变量
/*
	string TempVar_ID;//临时变量标号
	int type;//临时变量类型
*/
//Place结构
/*
	bool IsImmNum;//是否立即数
	bool IsTempVar;//是否是临时变量     //先判断是否立即数，在判断是否临时变量
	VarPlace VP;//用户定义的变量
	Var_Temp VT;//临时变量
	int imm_num;//立即数
*/
//中间代码的place结构
class Var_Temp
{
public:
	string TempVar_ID;//临时变量标号
	int type;//临时变量类型
	Var_Temp()
	{
		TempVar_ID="";//表示不可用
		type=VOID;//init
	}
	Var_Temp(const Var_Temp &copy)
	{
		TempVar_ID=copy.TempVar_ID;
		type=copy.type;
	}
};//临时变量信息

class Place
{
public:
	bool IsImmNum;//是否立即数
	bool IsTempVar;//是否是临时变量     //先判断是否立即数，在判断是否临时变量
	VarPlace VP;//用户定义的变量
	Var_Temp VT;//临时变量
	int imm_num;//立即数
	Place()
	{
		IsTempVar=false;
		IsImmNum=false;
		imm_num=0;
	}
	Place(const Place &copy)
	{
		IsTempVar=copy.IsTempVar;
		IsImmNum=copy.IsImmNum;
		imm_num=copy.imm_num;
		VP=copy.VP;
		VT=copy.VT;
	}
};//变量信息


/////////////////////////中间代码的结构/////////////////////////////////////
string new_label(int n)//生成新下标_label_n
{
	string s="label";
	char a[10];
	_itoa_s(n,a,10,10);
	s+=a;
	return s;
}
string new_temp_var_label(int n)//生成新临时变量_temp_n
{
	string s="_temp_";
	char a[10];
	_itoa_s(n,a,10,10);
	s+=a;
	return s;
}
Place newTemp(int type,int n)//产生临时变量
{
	Place SD;
	SD.IsTempVar=true;
	SD.VT.TempVar_ID=new_temp_var_label(n);
	SD.VT.type=type;
	return SD;
}
/*函数返回值传递
被调函数写返回值REG,调用函数再从返回值REG写自己的对应的活动记录

调用函数判断被调函数有返回值就建立临时变量
*/
/////////////////////////////////////////////////////////////////////////////
//四元线性结构(op,des,src1,src2)
typedef struct//四元式的操作数
{
	bool isLabel;//函数标号或转移标号,否则是变量或立即数
	string label;
	Place Var;//变量或立即数
}Operator_NUM;
//OP结构
typedef struct
{
	bool IsLabel;//是否是标签，否则是实际的运算操作
	string Label;//标签
	//OP
}OP_SEM;//中间表示的操作
//
typedef struct
{
	string OP;
	//OP
	Operator_NUM RD;//目标操作数
	Operator_NUM RS;//源操作数RS
	Operator_NUM RT;//源操作数RT
}QUAD_EXP_ROW;//四元式基本结构
//SEM_CODE
class SEM_CODE
{
public:
	vector<QUAD_EXP_ROW> CODE;
	SEM_CODE()
	{
		CODE.clear();
	}
	SEM_CODE(const SEM_CODE &copy)
	{
		CODE=copy.CODE;
	}
	void AppendTail(const SEM_CODE &OP)
	{
		for(int i=0;i<OP.CODE.size();i++)
		{
			CODE.push_back(OP.CODE[i]);
		}
	}
	void AppendTail(const QUAD_EXP_ROW &OP)
	{
		CODE.push_back(OP);
	}
};

#endif //SEM_CODE_H
