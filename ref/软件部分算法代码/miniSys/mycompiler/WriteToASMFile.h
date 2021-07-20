#ifndef WRITETOASMFILE_H
#define WRITETOASMFILE_H
#pragma once

#include "FunctionModuleASM.h"
#include "TestSemCode.h"
//#include "FunctionForest.h"
//#include "SEM_GLOBAL_INF.H"
//#include "RegDisattribute.h"

//�������յ�ASM�ļ�

/*
//ȫ�����ڱ��溯��ģ��Ĵ���
vector<Fun_ASM>  FA_ASM;
//������
void TransForest_REGToFunASM(Forest_REG &FR,Fun_ASM &FA)//���к����м���뵽���ķ���
*/


/*
//����ɭ��
vector<Forest>  Fun_Sem_Forest;
vector<Forest_REG>  Fun_Sem_Forest_REG;//���Ĵ��������REG
//�����м䷭���ɭ��Ⱥ
*/
//�Ƚ��мĴ�������

void AssReg()
{
	for(int i=0;i<Fun_Sem_Forest.size();i++)
	{
		Forest_REG FR;FR.SC.CODE.clear();
		DisattributeReg(Fun_Sem_Forest[i],FR);//Reg����
		Fun_Sem_Forest_REG.push_back(FR);//����Ĵ���������ɭ��
	}
	/*for(int j=0;j<Fun_Sem_Forest_REG.size();j++)//���ԼĴ�������
	{
		fstream fgp;
		fgp.open(GenPathName(),std::ios::out|std::ios::binary);
		Forest_REG &FR=Fun_Sem_Forest_REG[j];
		for(int i=0;i<FR.SC.CODE.size();i++)
		{
			fgp<<ConvertString(ConvertQuadCode(FR.SC.CODE[i]))<<"\r\n";//���ԼĴ�������
		}
	}*/
}


//���������ı��
void EleminateContLable()//�����������,���������м����
{
	int i=0;
	for(i=0;i<Fun_Sem_Forest_REG.size();i++)//����ÿһ��������
	{
		Forest_REG &FR=Fun_Sem_Forest_REG[i];
		SEM_CODE_REG &SC=FR.SC;//�м����
		//vector<QER_ASM> CODE;
		vector<QER_ASM> &CODE=SC.CODE;
		for(int j=0;j<CODE.size();j++)//ɨ���м����
		{
			if(j<CODE.size()-1)
			{
				if(CODE[j].OP.compare("LABEL")==0&&CODE[j+1].OP.compare("LABEL")==0)
				{
					//��ʼ����ɨ�裬���������ظ����
					string L1=CODE[j].RS.ON.label;
					string L2=CODE[j+1].RS.ON.label; 
					//�滻��һ���±꣬���������������
					CODE[j].OP="NOP";//�ÿ�ָ���滻(ֻҪû�е�ָ�����,���ǲ�����)
					for(int x=0;x<CODE.size();x++)//�滻�㷨��ʼ
					{
						if(CODE[x].OP.compare("BEQ")==0)
						{
							if(CODE[x].RD.ON.label.compare(L1)==0)
							{
								CODE[x].RD.ON.label=L2;
							}
						}
						else if(CODE[x].OP.compare("BNE")==0)
						{
							if(CODE[x].RD.ON.label.compare(L1)==0)
							{
								CODE[x].RD.ON.label=L2;
							}
						}
						else if(CODE[x].OP.compare("GOTO")==0)
						{
							if(CODE[x].RD.ON.label.compare(L1)==0)
							{
								CODE[x].RD.ON.label=L2;
							}
						}
						else if(CODE[x].OP.compare("CALL")==0)
						{
							if(CODE[x].RS.ON.label.compare(L1)==0)
							{
								CODE[x].RS.ON.label=L2;
							}
						}
						else if(CODE[x].OP.compare("LABEL")==0)
						{
							if(CODE[x].RS.ON.label.compare(L1)==0)
							{
								CODE[x].RS.ON.label=L2;
							}
						}
						else
						{
						}
					}
				}
			}
		}
	}
}

//�ٲ������������
void GenFunBlockASM()
{
	for(int i=0;i<Fun_Sem_Forest_REG.size();i++)
	{
		Fun_ASM FA;//���溯������
		TransForest_REGToFunASM(Fun_Sem_Forest_REG[i],FA);//�������������
		FA_ASM.push_back(FA);FA.ASM.clear();
	}
}

//char* ConvertString(string s)
//{
//	int len=s.length();
//	if(len==0) return 0;
//	char *ret=new char[len+1];
//	int i;
//	for(i=0;i<len;i++) {
//		ret[i]=s[i];
//		//cout<<s[i]<<endl;
//	}
//	ret[i]='\0';
//	return ret;
//}

//����д��ģ��
void Write_ASM_File(const char *path)
{
	//�����ļ���
	fstream fs;
	fs.open(path,std::ios::out|std::ios::binary|std::ios::trunc);
	if(!fs)
	{
		if(!isDebug) {
			cout<<"�����ļ�ʧ��.asm"<<"\r\n";
		} else {
			err_lst<<"�����ļ�ʧ��.asm"<<"\r\n";
		}
		
		return;
	}
	//���棬��д�����ݶζ���
	fs<<"DATA SEG"<<"\r\n";
	fs<<"      "<<"\r\n";
	fs<<"DATA ENDS"<<"\r\n";
	//����ο�ʼ
	fs<<"CODE SEG"<<"\r\n";
	fs<<"ORG_CODE 0000H"<<"\r\n";
	fs<<"start:"<<"\r\n";
	//��ʼ��sp,$s9(top)Ϊȫ�����ݺ���
	//fs<<";��ʼ��sp,$s9(top)Ϊȫ�����ݺ���\r\n";
	char gl_off[10];
	HexTrans(global_offset,gl_off);//itoa(global_offset,gl_off,10);
	fs<<"ORI $sp,$zero,"<<gl_off<<"\r\n";
	fs<<"ORI $s9,$zero,"<<gl_off<<"\r\n";
	//fs<<";��ʼ��sp,$s9(top)���\r\n";
	//
	//�������main����
	int i=0;
	bool ismain=false;//main
	vector<string> main_code;
	for(i=0;i<FA_ASM.size();i++)
	{
		if(FA_ASM[i].Name.compare("main")==0)
		{
			main_code=FA_ASM[i].ASM;//ȡmain��������
			ismain=true;
			break;
		}
	}
	if(ismain)//main��������
	{
		fs<<"JAL main"<<"\r\n";
	}
	char *nlb=ConvertString(Gen_New_Label());
	fs<<nlb<<":\r\n";//����һ���±��
	fs<<"J "<<nlb<<"\r\n";
	//��̬ͣ��
	if(ismain)//main���
	{
		fs<<"main:"<<"\r\n";
		//���������
		for(int i=0;i<main_code.size();i++)
		{
			fs<<ConvertString(main_code[i])<<"\r\n";
		}
	}
	//main�����������
	//���������ӳ���Ĵ���
	for(i=0;i<FA_ASM.size();i++)
	{
		if(FA_ASM[i].Name.compare("main")!=0)//���ٷ���main����
		{
			fs<<ConvertString(FA_ASM[i].Name)<<":\r\n";//�������
			vector<string> &sub_code=FA_ASM[i].ASM;
			for(int j=0;j<sub_code.size();j++)//������
			{
				fs<<ConvertString(sub_code[j])<<"\r\n";
			}
		}
	}
	//�Ӻ�����������
	//����Ƿ����ж�INT0,INT 1
	bool isINT0=false;
	bool isINT1=false;
	for(i=0;i<FA_ASM.size();i++)
	{
		if(FA_ASM[i].Name.compare("interuptServer0")==0)
		{
			isINT0=true;
		}
		else if(FA_ASM[i].Name.compare("interuptServer1")==0)
		{
			isINT1=true;
		}
	}
	fs<<"ORG_CODE 07F8H"<<"\r\n";//INT0
	if(isINT0)
	{
		fs<<"J interuptServer0"<<"\r\n";
	}
	else
	{
		fs<<"JR $i0"<<"\r\n";
	}
	fs<<"ORG_CODE 07FCH"<<"\r\n";//INT1
	if(isINT1)
	{
		fs<<"J interuptServer1"<<"\r\n";
	}
	else
	{
		fs<<"JR $i1"<<"\r\n";
	}
	//�������
	fs<<"end start"<<"\r\n";
	fs<<"CODE ENDS"<<"\r\n";
	fs.flush();
	fs.close();
}

void Global_Reset(string srcFile)//ȫ�ָ�λ
{
	while(!while_stack.empty()){while_stack.pop();}
	//if(!(!err_lst)) err_lst.close();
	FA_ASM.clear();
    FC_=Function_Compound_();
	file_num=0;
	Fun_Sem_Forest.clear();
	Fun_Sem_Forest_REG.clear();
	Global_Fun_type=VOID;
	global_offset=0;
	Label_num=0;
	local_offset=0;
	MST.Reset();
	Temp_Var_num=0;
	WC_=While_Compound_();
	while(!yysymbol.empty()){yysymbol.pop();}
	//cc=0;//��ͷλ��
	//yytext=0;//�ַ�
	yylineno=1;//�����к�

    isDebug = false; //�Ƿ�Ϊ�������

	if(!isDebug) {
        //const char* errLogFile = "error.log";
        int index = srcFile.find_last_of('/');
        srcFile.replace(index+1, srcFile.size()-index-1, "error.log");

        err_lst.open(srcFile.c_str(), ios::out);
		if(err_lst.fail()) {
			cout<<"can not open error log file!"<<endl;
		}
	}
}
#endif //WRITETOASMFILE_H
