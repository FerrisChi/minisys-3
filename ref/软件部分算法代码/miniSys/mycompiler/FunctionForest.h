#ifndef FUNCTIONFOREST_H
#define FUNCTIONFOREST_H

#pragma once
#include "stdafx.h"
#include "SEM_CODE.h"
/*����ɭ��*/


class Forest{
public:
	Forest(const Forest &copy);//�������캯��
	Forest();
public:
	string Fun_Name;//������
	SEM_CODE SC;//�м����
};//������

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

class OpNumRM//�����Ĵ�������Ĳ�����,Ŀǰֻ����ʱ�������Ĵ�������
{
public:
	bool isReg;//�Ƿ��ǼĴ���
	Operator_NUM ON;
	string REG;//�Ĵ�������
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
	OpNumRM RD;//Ŀ�������
	OpNumRM RS;//Դ������RS
	OpNumRM RT;//Դ������RT
}QER_ASM;//��Ԫʽ�����ṹ,���Ĵ�������

class SEM_CODE_REG //�Ѿ������˼Ĵ������м����
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
	Forest_REG(const Forest_REG &copy);//�������캯��
	Forest_REG();
public:
	string Fun_Name;//������
	SEM_CODE_REG SC;//�м����
};//������

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
////////����ɭ�ֵı�����//////
class BinaryKindForest
{
public:
	vector<Forest>  Fun_Sem_Forest;
	vector<Forest_REG>  Fun_Sem_Forest_REG;//���Ĵ��������REG
	BinaryKindForest()
	{
		Fun_Sem_Forest.clear();
		Fun_Sem_Forest_REG.clear();
	}
};

#endif  //FUNCTIONFOREST_H
