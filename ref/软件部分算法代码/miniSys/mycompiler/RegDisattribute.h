#ifndef REGDISATTRIBUTE_H
#define REGDISATTRIBUTE_H
#pragma once

#include "StdAfx.h"
#include "FunctionForest.h"

//����Ĵ����㷨��ת��ɭ��
/*
//����ɭ��
vector<Forest>  Fun_Sem_Forest;
vector<Forest_REG>  Fun_Sem_Forest_REG;//���Ĵ��������REG
//�����м䷭���ɭ��Ⱥ
*/

//what?How?


struct str_cmp
{
	bool operator()(string s1,string s2) const//ƫ��<
	{
		if(s1.compare(s2)<0) return true;
		else return false;
	}
};
void GetQuadExpTempVar(QUAD_EXP_ROW QER,vector<Operator_NUM> &t_var)//����ȡ�ø�����Ԫʽ����ʱ����
{
	vector<Operator_NUM> RS,RD,RT;
	t_var.clear();
	if(QER.RS.Var.IsImmNum|QER.RS.isLabel)
	{
		//err_lst<<"ϵͳ�ڲ�����Inner:1"<<"\r\n";
	}
	else
	{
		if(QER.RS.Var.IsTempVar)
		{
			RS.push_back(QER.RS);
		}
	}
	if(QER.RT.Var.IsImmNum|QER.RT.isLabel)
	{
		//err_lst<<"ϵͳ�ڲ�����Inner:2"<<"\r\n";
	}
	else
	{
		if(QER.RT.Var.IsTempVar)
		{
			RT.push_back(QER.RT);
		}
	}
	if(QER.RD.Var.IsImmNum|QER.RD.isLabel)
	{
		//err_lst<<"ϵͳ�ڲ�����Inner:3"<<"\r\n";
	}
	else
	{
		if(QER.RD.Var.IsTempVar)
		{
			RD.push_back(QER.RD);
		}
	}
	//��ȫ�����㣬��ѡ��
	if(QER.OP.compare("ADD")==0)
	{
		//ȫ��������ѡ��
		if(RS.size()!=0) t_var.push_back(RS[0]);
		if(RT.size()!=0) t_var.push_back(RT[0]);
		if(RD.size()!=0) t_var.push_back(RD[0]);
	}
	if(QER.OP.compare("SUB")==0)
	{
		//ȫ��������ѡ��
		if(RS.size()!=0) t_var.push_back(RS[0]);
		if(RT.size()!=0) t_var.push_back(RT[0]);
		if(RD.size()!=0) t_var.push_back(RD[0]);
	}
	if(QER.OP.compare("MLT")==0)
	{
		//ȫ��������ѡ��
		if(RS.size()!=0) t_var.push_back(RS[0]);
		if(RT.size()!=0) t_var.push_back(RT[0]);
		if(RD.size()!=0) t_var.push_back(RD[0]);
	}
	if(QER.OP.compare("DIV")==0)
	{
		//ȫ��������ѡ��
		if(RS.size()!=0) t_var.push_back(RS[0]);
		if(RT.size()!=0) t_var.push_back(RT[0]);
		if(RD.size()!=0) t_var.push_back(RD[0]);
	}
	if(QER.OP.compare("MOD")==0)
	{
		//ȫ��������ѡ��
		if(RS.size()!=0) t_var.push_back(RS[0]);
		if(RT.size()!=0) t_var.push_back(RT[0]);
		if(RD.size()!=0) t_var.push_back(RD[0]);
	}
	if(QER.OP.compare("MOV")==0)
	{
		//ȫ��������ѡ��
		if(RS.size()!=0) t_var.push_back(RS[0]);
		if(RD.size()!=0) t_var.push_back(RD[0]);
	}
	if(QER.OP.compare("SLT")==0)
	{
		//ȫ��������ѡ��
		if(RS.size()!=0) t_var.push_back(RS[0]);
		if(RT.size()!=0) t_var.push_back(RT[0]);
		if(RD.size()!=0) t_var.push_back(RD[0]);
	}
	if(QER.OP.compare("LSHIFT")==0)
	{
		//ȫ��������ѡ��
		if(RS.size()!=0) t_var.push_back(RS[0]);
		if(RT.size()!=0) t_var.push_back(RT[0]);
		if(RD.size()!=0) t_var.push_back(RD[0]);
	}
	if(QER.OP.compare("RSHIFT")==0)
	{
		//ȫ��������ѡ��
		if(RS.size()!=0) t_var.push_back(RS[0]);
		if(RT.size()!=0) t_var.push_back(RT[0]);
		if(RD.size()!=0) t_var.push_back(RD[0]);
	}
	if(QER.OP.compare("BEQ")==0)
	{
		//ȫ��������ѡ��
		if(RS.size()!=0) t_var.push_back(RS[0]);
		if(RT.size()!=0) t_var.push_back(RT[0]);
	}
	if(QER.OP.compare("BNE")==0)
	{
		//ȫ��������ѡ��
		if(RS.size()!=0) t_var.push_back(RS[0]);
		if(RT.size()!=0) t_var.push_back(RT[0]);
	}
	if(QER.OP.compare("LDA")==0)
	{
		//ȫ��������ѡ��
		if(RS.size()!=0) t_var.push_back(RS[0]);
		if(RT.size()!=0) t_var.push_back(RT[0]);
		if(RD.size()!=0) t_var.push_back(RD[0]);
	}
	if(QER.OP.compare("CALL")==0)
	{
		//ȫ��������ѡ��
		if(RD.size()!=0) t_var.push_back(RD[0]);
	}
	if(QER.OP.compare("LOD")==0)
	{
		//ȫ��������ѡ��
		if(RS.size()!=0) t_var.push_back(RS[0]);
		if(RD.size()!=0) t_var.push_back(RD[0]);
	}
	if(QER.OP.compare("SAV")==0)
	{
		//ȫ��������ѡ��
		if(RS.size()!=0) t_var.push_back(RS[0]);
		if(RD.size()!=0) t_var.push_back(RD[0]);
	}
	if(QER.OP.compare("OR")==0)
	{
		//ȫ��������ѡ��
		if(RS.size()!=0) t_var.push_back(RS[0]);
		if(RT.size()!=0) t_var.push_back(RT[0]);
		if(RD.size()!=0) t_var.push_back(RD[0]);
	}
	if(QER.OP.compare("AND")==0)
	{
		//ȫ��������ѡ��
		if(RS.size()!=0) t_var.push_back(RS[0]);
		if(RT.size()!=0) t_var.push_back(RT[0]);
		if(RD.size()!=0) t_var.push_back(RD[0]);
	}
	if(QER.OP.compare("NOT")==0)
	{
		//ȫ��������ѡ��
		if(RS.size()!=0) t_var.push_back(RS[0]);
		if(RD.size()!=0) t_var.push_back(RD[0]);
	}
	if(QER.OP.compare("XOR")==0)
	{
		//ȫ��������ѡ��
		if(RS.size()!=0) t_var.push_back(RS[0]);
		if(RT.size()!=0) t_var.push_back(RT[0]);
		if(RD.size()!=0) t_var.push_back(RD[0]);
	}
	if(QER.OP.compare("PARAM")==0)
	{
		//ȫ��������ѡ��
		if(RS.size()!=0) t_var.push_back(RS[0]);
		if(RD.size()!=0) t_var.push_back(RD[0]);
	}
	if(QER.OP.compare("RET")==0)
	{
		//ȫ��������ѡ��
		if(RD.size()!=0) t_var.push_back(RD[0]);
	}
}

typedef struct
{
	string Name;
	int cnt;
}MyPair;

bool DisattributeReg(Forest &F,Forest_REG &FR)//�Ĵ�������
{
	map<string,int,str_cmp> RegCnt;//(/*str_cmp()*/);//ͳ�Ƽ����������ʹ���ʷ�����ʱReg($t0~$t9)
	//��һ��ɨ�裬ͳ��������
	//vector<QUAD_EXP_ROW> CODE;
	//GetQuadExpTempVar(QUAD_EXP_ROW QER,vector<Operator_NUM> &t_var)//����ȡ�ø�����Ԫʽ����ʱ����
	FR.SC.CODE.clear();
	vector<QUAD_EXP_ROW> &LQE=F.SC.CODE;//������������
	int i=0;
	int count_tvar=0;//ͳ����ʱ������Ŀ
	for(i=0;i<LQE.size();i++)
	{
		vector<Operator_NUM> t_var;
		GetQuadExpTempVar(LQE[i],t_var);
		for(int j=0;j<t_var.size();j++) //����ͳ�Ƽ���
		{
			string t_name=t_var[j].Var.VT.TempVar_ID;
			if(RegCnt.find(t_name)!=RegCnt.end())
			{
				RegCnt[t_name]++;//����
			}
			else//����֮
			{
				RegCnt[t_name]=1;//��ʼ��Ϊ1
				count_tvar++;//
			}
		}
	}
	//���Լ������
	map<string,int,str_cmp>::iterator it=RegCnt.begin();
	/*for(it=RegCnt.begin();it!=RegCnt.end();it++)
	{
		err_lst<<ConvertString((*it).first)<<":"<<(*it).second<<"\r\n";
	}*/
	//�ܼĴ�����9��,$t0~$t8
	//err_lst<<"temp:"<<count_tvar<<"\r\n";
	vector<MyPair> RegSort;
	map<string,string,str_cmp>  TVar_Reg;//����ƻ�
	if(count_tvar<=9) //ֱ�ӷ���
	{
		if(count_tvar!=0)
		{
			int index=0;char a[10];
			for(it=RegCnt.begin();it!=RegCnt.end();it++)
			{
				_itoa_s(index,a,10);
				string s="$t";s+=a;//����Ĵ�����
				TVar_Reg[(*it).first]=s;//����ӳ��
				index++;
			}
		}
	}
	else //������
	{
		//1.װ����������
		for(it=RegCnt.begin();it!=RegCnt.end();it++)
		{
			MyPair MP;
			MP.cnt=(*it).second;
			MP.Name=(*it).first;
			RegSort.push_back(MP);
		}
		//2.����,�Ƚ�����
		for(int i=0;i<RegSort.size();i++)
		{
			MyPair temp=RegSort[i];//��������
			for(int j=i;j<RegSort.size();j++)
			{
				if(RegSort[j].cnt>RegSort[i].cnt)
				{
					temp=RegSort[i];
					RegSort[i]=RegSort[j];
					RegSort[j]=temp;
				}
				else if(RegSort[j].cnt==RegSort[i].cnt)
				{
					if(RegSort[j].Name.compare(RegSort[i].Name)>0)//�����ʹ��,��������
					{
						temp=RegSort[i];
						RegSort[i]=RegSort[j];
						RegSort[j]=temp;
					}
				}
				else
				{
					//������
				}
			}
		}
		//3.ȡǰ����
		//�Ȳ�����
		/*for(i=0;i<RegSort.size();i++)
		{
			err_lst<<ConvertString(RegSort[i].Name)<<":"<<RegSort[i].cnt<<"\r\n";
		}*/
		if(RegSort.size()>9)
		{
			char a[10];
			for(int i=0;i<9;i++)
			{
				_itoa_s(i,a,10);
				string s="$t";s+=a;//����Ĵ�����
				TVar_Reg[RegSort[i].Name]=s;//����ӳ��
			}
		}
		//
	}
	//ת���м����
	FR.Fun_Name=F.Fun_Name;
	vector<QER_ASM> &SEM_REG=FR.SC.CODE;
	vector<QUAD_EXP_ROW> &SEM=F.SC.CODE;
	for(int r=0;r<SEM.size();r++)
	{
		OpNumRM RS,RT,RD;
		QER_ASM QA;
		QA.OP=SEM[r].OP;
		//RS
		if(SEM[r].RS.isLabel||SEM[r].RS.Var.IsImmNum)
		{
			QA.RS=SEM[r].RS;
		}
		else
		{
			if(SEM[r].RS.Var.IsTempVar)
			{
				//�Ȳ����ǲ���ΪReg����
				string name=SEM[r].RS.Var.VT.TempVar_ID;
				int kind=SEM[r].RS.Var.VT.type;
				if(TVar_Reg.find(name)!=TVar_Reg.end())
				{
					//����ΪReg����
					RS.isReg=true;
					RS.REG=TVar_Reg[name];//Reg����
					QA.RS=RS;
				}
				else
				{
					//Ϊ֮����Ϊ�ڴ����
					string Fun=F.Fun_Name;//��������
					VarPlace VP;
					Function_Table *FT=MST.GetFunction_Table(Fun);
					if(FT!=0)//�õ����ƫ��
					{
						int offset=FT->top;
						VarList lst;
						lst.ID_Name=name;
						lst.isArray=false;
						lst.Type=kind;
						lst.Array_Len=0;
						lst.offset=offset;
						if(MST.insert(lst,Fun))
						{
							FT->top+=GetTypeWidth(kind);
							//err_lst<<"insert temp var to mem suc!"<<"\r\n";
						}
						else
						{
							//err_lst<<"insert temp var to mem err!"<<"\r\n";
							//return false;
						}
						if(GetTypeWidth(kind)==0)
						{
							if(!isDebug) {
								cout<<"ϵͳ����:DisattributReg:2"<<"\r\n";
							} else {
								err_lst<<"ϵͳ����:DisattributReg:2"<<"\r\n";
							}
							return false;
						}
						//��������Ϣ
						if(MST.Lookup(name,Fun,VP))
						{
							QA.RS.isReg=false;
							QA.RS.ON.isLabel=false;
							QA.RS.ON.Var.IsImmNum=false;
							QA.RS.ON.Var.IsTempVar=false;
							QA.RS.ON.Var.VP=VP;
						}
						else
						{
							if(!isDebug) {
								cout<<"�鲻������ı���,ϵͳ����:DisattributReg:3"<<"\r\n";
							} else {
								err_lst<<"�鲻������ı���,ϵͳ����:DisattributReg:3"<<"\r\n";
							}
							return false;
						}
					}
					else
					{
						if(!isDebug) {
							cout<<"ϵͳ����:DisattributReg:1"<<"\r\n";
						} else {
							err_lst<<"ϵͳ����:DisattributReg:1"<<"\r\n";
						}
						return false;
					}

				}
			}
			else
			{
				QA.RS=SEM[r].RS;
			}
		}
		//RD
		if(SEM[r].RD.isLabel||SEM[r].RD.Var.IsImmNum)
		{
			QA.RD=SEM[r].RD;
		}
		else
		{
			if(SEM[r].RD.Var.IsTempVar)
			{
				//�Ȳ����ǲ���ΪReg����
				string name=SEM[r].RD.Var.VT.TempVar_ID;
				int kind=SEM[r].RD.Var.VT.type;
				if(TVar_Reg.find(name)!=TVar_Reg.end())
				{
					//����ΪReg����
					RD.isReg=true;
					RD.REG=TVar_Reg[name];//Reg����
					QA.RD=RD;
				}
				else
				{
					//Ϊ֮����Ϊ�ڴ����
					string Fun=F.Fun_Name;//��������
					VarPlace VP;
					Function_Table *FT=MST.GetFunction_Table(Fun);
					if(FT!=0)//�õ����ƫ��
					{
						int offset=FT->top;
						VarList lst;
						lst.ID_Name=name;
						lst.isArray=false;
						lst.Type=kind;
						lst.Array_Len=0;
						lst.offset=offset;
						if(MST.insert(lst,Fun))
						{
							FT->top+=GetTypeWidth(kind);
							//err_lst<<"insert temp var to mem suc!"<<"\r\n";
						}
						else
						{
							//err_lst<<"insert temp var to mem err!"<<"\r\n";
							//return false;
						}
						if(GetTypeWidth(kind)==0)
						{
							if(!isDebug) {
								cout<<"ϵͳ����:DisattributReg:2"<<"\r\n";
							} else {
								err_lst<<"ϵͳ����:DisattributReg:2"<<"\r\n";
							}
							
							return false;
						}
						//��������Ϣ
						if(MST.Lookup(name,Fun,VP))
						{
							QA.RD.isReg=false;
							QA.RD.ON.isLabel=false;
							QA.RD.ON.Var.IsImmNum=false;
							QA.RD.ON.Var.IsTempVar=false;
							QA.RD.ON.Var.VP=VP;
						}
						else
						{
							if(!isDebug) {
								cout<<"�鲻������ı���,ϵͳ����:DisattributReg:3"<<"\r\n";
							} else {
								err_lst<<"�鲻������ı���,ϵͳ����:DisattributReg:3"<<"\r\n";
							}
							
							return false;
						}
					}
					else
					{
						if(!isDebug) {
							cout<<"ϵͳ����:DisattributReg:1"<<"\r\n";
						} else {
							err_lst<<"ϵͳ����:DisattributReg:1"<<"\r\n";
						}
						return false;
					}

				}
			}
			else
			{
				QA.RD=SEM[r].RD;
			}
		}
		//RT
		if(SEM[r].RT.isLabel||SEM[r].RT.Var.IsImmNum)
		{
			QA.RT=SEM[r].RT;
		}
		else
		{
			if(SEM[r].RT.Var.IsTempVar)
			{
				//�Ȳ����ǲ���ΪReg����
				string name=SEM[r].RT.Var.VT.TempVar_ID;
				int kind=SEM[r].RT.Var.VT.type;
				if(TVar_Reg.find(name)!=TVar_Reg.end())
				{
					//����ΪReg����
					RT.isReg=true;
					RT.REG=TVar_Reg[name];//Reg����
					QA.RT=RT;
				}
				else
				{
					//Ϊ֮����Ϊ�ڴ����
					string Fun=F.Fun_Name;//��������
					VarPlace VP;
					Function_Table *FT=MST.GetFunction_Table(Fun);
					if(FT!=0)//�õ����ƫ��
					{
						int offset=FT->top;
						VarList lst;
						lst.ID_Name=name;
						lst.isArray=false;
						lst.Type=kind;
						lst.Array_Len=0;
						lst.offset=offset;
						if(MST.insert(lst,Fun))
						{
							FT->top+=GetTypeWidth(kind);
							//err_lst<<"insert temp var to mem suc!"<<"\r\n";
						}
						else
						{
							//err_lst<<"insert temp var to mem err!"<<"\r\n";
							//return false;
						}
						if(GetTypeWidth(kind)==0)
						{
							if(!isDebug) {
								cout<<"ϵͳ����:DisattributReg:2"<<"\r\n";
							} else {
								err_lst<<"ϵͳ����:DisattributReg:2"<<"\r\n";
							}
							return false;
						}
						//��������Ϣ
						if(MST.Lookup(name,Fun,VP))
						{
							QA.RT.isReg=false;
							QA.RT.ON.isLabel=false;
							QA.RT.ON.Var.IsImmNum=false;
							QA.RT.ON.Var.IsTempVar=false;
							QA.RT.ON.Var.VP=VP;
						}
						else
						{
							if(!isDebug) {
								cout<<"�鲻������ı���,ϵͳ����:DisattributReg:3"<<"\r\n";
							} else {
								err_lst<<"�鲻������ı���,ϵͳ����:DisattributReg:3"<<"\r\n";
							}

							return false;
						}
					}
					else
					{
						if(!isDebug) {
							cout<<"ϵͳ����:DisattributReg:1"<<"\r\n";
						} else {
							err_lst<<"ϵͳ����:DisattributReg:1"<<"\r\n";
						}
						return false;
					}

				}
			}
			else
			{
				QA.RT=SEM[r].RT;
			}
		}
		//
		SEM_REG.push_back(QA);
	}
	//
	return true;
}

#endif //REGDISATTRIBUTE_H
