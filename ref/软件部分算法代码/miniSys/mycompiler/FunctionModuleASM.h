#ifndef FUNCTIONMODULEASM_H
#define FUNCTIONMODULEASM_H

#pragma once
#include"ASM_TRANSLATE.h"
#include "StdAfx.h"
#include "FunctionForest.h"
#include "SEM_GLOBAL_INF.H"
#include "RegDisattribute.h"

//���������������


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

//ȫ�����ڱ��溯��ģ��Ĵ���
vector<Fun_ASM>  FA_ASM;
//������
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

void PreFunAsmTrans(Forest_REG &FR,Fun_ASM &FA)//���к������м����ķ��룬ȷ���Ĵ���ʹ�ã������ض��Ļָ�����
{
	string OneRow="";//һ������
	FA.ASM.clear();
	FA.Name=FR.Fun_Name;
	//����reg����
	vector<string> sav_reg;
	//�ָ�reg����
	vector<string> lod_reg;
	//��ú�����
	Function_Table *FT=MST.GetFunction_Table(FR.Fun_Name);
	//ԭ����top
	int top=FT->top;//����reg����ķ���
	//��ַ-reg��ӳ��
	map<int,string> ADD_REG;
	if(FT==0)
	{
		return;
	}
	//��ʼ������ķ���
	//�ȷ���һ������ģ�飬��������ֵ��
	vector<string> ret_stmt;
	if(FR.Fun_Name.compare("interuptServer0")==0||FR.Fun_Name.compare("interuptServer1")==0)
	{
	}
	else
	{
		OneRow="";OneRow="LW $at,0004H($sp)";ret_stmt.push_back(OneRow);//���ط��ص�ַ
	}
	OneRow="";OneRow="LW $s9,0008H($sp)";ret_stmt.push_back(OneRow);//����ԭ����top
	OneRow="";OneRow="LW $sp,0000H($sp)";ret_stmt.push_back(OneRow);//����ԭ����SP
	if(FR.Fun_Name.compare("interuptServer0")==0)
	{
		OneRow="";OneRow="JR $i0";ret_stmt.push_back(OneRow);//����
	}
	else if(FR.Fun_Name.compare("interuptServer1")==0)
	{
		OneRow="";OneRow="JR $i1";ret_stmt.push_back(OneRow);//����
	}
	else
	{
		OneRow="";OneRow="JR $at";ret_stmt.push_back(OneRow);//����
	}
	//�巭��
	//���ش�����ٷ��Ż�
	vector<QER_ASM> &SEM=FR.SC.CODE;//��������
	bool add_new_ret_lab=false;
	string RETURN_LABEL="";
	if(SEM.size()>0)
	{
		if(SEM[SEM.size()-1].OP.compare("LABEL")==0)
		{
			RETURN_LABEL=SEM[SEM.size()-1].RS.ON.label;//���ص��±�
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
		vector<string> t_sec;//�м�Ļ���
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
			vector<string> mov_tr;//mov����Ĵ���
			QER_ASM t_QA;//��ʱ��Ϊ���ͷ�����
			t_QA.OP="MOV";
			RD.isReg=true;
			RD.REG="$v0";
			t_QA.RD=RD;
			t_QA.RS=SEM[i].RD;
			MOV_Translate(t_QA,mov_tr);//MOV RD,$v0
			MergeAsm(FA.ASM,mov_tr);
			//����������
			string J_R="J ";J_R+=RETURN_LABEL;
			FA.ASM.push_back(J_R);
		}
		else if(SEM[i].OP.compare("RETN")==0)
		{
			//����������
			string J_R="J ";J_R+=RETURN_LABEL;
			FA.ASM.push_back(J_R);
		}
		else
		{
		}
	}
	//�����巭�����
	//ͳ�ƼĴ���ʹ�ã������Ĵ���ӳ��
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
	//�жϺ�������ͨ���������������ƻ�$at,Ҫ����$at//�жϺ�������ͨ���������������ƻ�$v0,Ҫ����$v0
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
	//��������/�ָ��Ĵ�������
	map<int,string>::iterator irg=ADD_REG.begin();
	for(irg=ADD_REG.begin();irg!=ADD_REG.end();irg++)
	{
		int add=(*irg).first;
		string rn=(*irg).second;
		string add_hex=HexTrans(add);
		string code="SW ";code+=rn;code+=",";code+=add_hex;code+="($sp)";//����
		sav_reg.push_back(code);
		code="LW ";code+=rn;code+=",";code+=add_hex;code+="($sp)";//�ָ�
		lod_reg.push_back(code);
	}
	//����ټ�һ�����أ�����ʼ��
	//�Ż����ش��룬���ٴ�������
	//���ػָ����¼
	if(add_new_ret_lab==true)
	{
		string RT_L=RETURN_LABEL;
		RT_L+=":";
		FA.ASM.push_back(RT_L);
	}
	MergeAsm(FA.ASM,lod_reg);//�ָ��Ĵ���
	MergeAsm(FA.ASM,ret_stmt);
	MergeAsm(sav_reg,FA.ASM);//����Ĵ���
	FA.ASM=sav_reg;//һ��OK
}

void TransForest_REGToFunASM(Forest_REG &FR,Fun_ASM &FA)//���к����м���뵽���ķ���
{
	string OneRow="";//һ������
	FA.ASM.clear();
	FA.Name=FR.Fun_Name;
	//�ȷ����Ĵ���ʹ��
	Fun_ASM temp;
	PreFunAsmTrans(FR,temp);
	//������ͷ������,SP,TOP�ȵĳ�ʼ��,�����࣬��ͨ���ж�
	OneRow="SW $sp,0000H($s9)";FA.ASM.push_back(OneRow);//������SP->0[top]
	//���淵�ص�ַ
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
	//����TOPָ��
	OneRow="";
	OneRow="SW $s9,0008H($s9)";FA.ASM.push_back(OneRow);
	//���³�ʼ��sp,topָ��
	OneRow="";
	OneRow="OR $sp,$zero,$s9";FA.ASM.push_back(OneRow);//sp��ʼ��
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
			cout<<"�ڲ����󣬺�����Ȼ������!"<<"\r\n";
		} else {
			err_lst<<"�ڲ����󣬺�����Ȼ������!"<<"\r\n";
		}
		return;
	}
	OneRow="ADDI $s9,$sp,";
	OneRow+=top;
	FA.ASM.push_back(OneRow);//top��ʼ��
	OneRow="";//OneRow=";sp,top,���ص�ַ��ʼ��";FA.ASM.push_back(OneRow);
	//���������
	MergeAsm(FA.ASM,temp.ASM);
}

#endif //FUNCTIONMODULEASM_H
