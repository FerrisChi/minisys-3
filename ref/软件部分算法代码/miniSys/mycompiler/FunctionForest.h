#ifndef FUNCTIONFOREST_H
#define FUNCTIONFOREST_H

#pragma once
#include "stdafx.h"
#include "SEM_CODE.h"
/*函数森林*/


class Forest{
public:
	Forest(const Forest &copy);//拷贝构造函数
	Forest();
public:
	string Fun_Name;//函数名
	SEM_CODE SC;//中间代码
};//函数表

Forest::Forest(const Forest &copy)
{
	this->Fun_Name=copy.Fun_Name;
	this->SC=copy.SC;
}

Forest::Forest()
{
	Fun_Name="";
}
////////////////////////////////////////////////////////////////////////////////////////////////////
//Operator_NUM

class OpNumRM//包含寄存器分配的操作数,目前只对临时变量做寄存器分配
{
public:
	bool isReg;//是否是寄存器
	Operator_NUM ON;
	string REG;//寄存器名字
	OpNumRM &operator=(const Operator_NUM &cp)
	{
		isReg=false;
		ON=cp;
		return *this;
	}
	OpNumRM(const OpNumRM &copy)
	{
		isReg=copy.isReg;
		ON=copy.ON;
		REG=copy.REG;
	}
	OpNumRM()
	{
		isReg=false;
		REG="";
	}
};

typedef struct
{
	string OP;
	//OP
	OpNumRM RD;//目标操作数
	OpNumRM RS;//源操作数RS
	OpNumRM RT;//源操作数RT
}QER_ASM;//四元式基本结构,带寄存器分配

class SEM_CODE_REG //已经分配了寄存器的中间代码
{
public:
	vector<QER_ASM> CODE;
	SEM_CODE_REG()
	{
		CODE.clear();
	}
	SEM_CODE_REG(const SEM_CODE_REG &copy)
	{
		CODE=copy.CODE;
	}
	void AppendTail(const SEM_CODE_REG &OP)
	{
		for(int i=0;i<OP.CODE.size();i++)
		{
			CODE.push_back(OP.CODE[i]);
		}
	}
	void AppendTail(const QER_ASM &OP)
	{
		CODE.push_back(OP);
	}
};

class Forest_REG{
public:
	Forest_REG(const Forest_REG &copy);//拷贝构造函数
	Forest_REG();
public:
	string Fun_Name;//函数名
	SEM_CODE_REG SC;//中间代码
};//函数表

Forest_REG::Forest_REG(const Forest_REG &copy)
{
	this->Fun_Name=copy.Fun_Name;
	this->SC=copy.SC;
}

Forest_REG::Forest_REG()
{
	Fun_Name="";
}
/////////////////////////////////////////////////////////////////////////////////
////////函数森林的保存类//////
class BinaryKindForest
{
public:
	vector<Forest>  Fun_Sem_Forest;
	vector<Forest_REG>  Fun_Sem_Forest_REG;//带寄存器分配的REG
	BinaryKindForest()
	{
		Fun_Sem_Forest.clear();
		Fun_Sem_Forest_REG.clear();
	}
};

#endif  //FUNCTIONFOREST_H
