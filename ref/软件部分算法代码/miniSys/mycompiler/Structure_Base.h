/**----------���ű�������----------------------------
VarList ���ű��һ��
VarPlace ��������Ϣ
Function_Table �������һ��
ManageSymbolTable ���ű�������
------VarList------------
	string ID_Name;//������
	int Type;//��������
	int Array_Len;//�Ƿ����鳤��
	int offset;//ƫ����,�������Ѱַoffset[SP]
	bool isArray;//�Ƿ�������
----------------------
------Function_Table--------
	string Fun_Name;//������
	int param_num;//��������
	int return_type;//��������
	vector<VarList> param_VarList;//�������ֱ�
	int top;//���¼�������λ��
	SymbolTable Local_ST;//�ݾֲ����ű�,class
	bool FULLC;//�Ƿ������
	int DECLR;//���������������ظ�,���Ҳ�����дһ�Σ�����һ��
----------------------------
---VarPlace-----------------
	string VarName;//��������
	bool GlobalVar;//�Ƿ�ȫ�ֱ���
	string FunName;//����������
	int type;//����
	int offset;//ƫ����
	int Array_Len;//���鳤��
	bool isArray;//�Ƿ�������
----------------------------
------------------------------------------------------**/
#ifndef STRUCTURE_BASE_H
#define STRUCTURE_BASE_H
#pragma once
#include "stdafx.h"
#include "yytab.h"



//#define NULL_TYPE 0 //������
//#define VOID_TYPE 1 //VOID��
//#define INT_TYPE 2  //INT��
//#define INT_ADDRESS_TYPE 3 //������ַ��

int GetTypeWidth(int type)//�õ����Ϳ��
{
	switch(type)
	{
	case CHAR:
		return 1;
	case SHORT: 	
		return 2;
	case INT:	
		return 4;
	case LONG: 	
		return 8;
	case VOID:	
		return 0;
	case BOOL:
		return 1;
	default:
		return 0;
	}
}

long Hash_String(string s) //�ַ�Hash����
{
	if(s.length()==0) return 0;
	else
	{
		long sum=0;
		for(int i=0;i<s.length();i++)
		{
			sum=(int)s[i]*i*26;
		}
		sum=sum%256;
		return sum;
	}
}
/*���鷭��ע������
����Ĭ���������������ַ
1.�����������ʱ:
isArray=true
Type����
Array_Len���û����Ĵ�С
offset�ļ���Ϊoffset+=Type.width*Array_Len

2.��Ϊ������������ʱ:
isArray=false
Type����=INT__ADDRESS_TYPE
offset�ļ���Ϊoffset+=32λ��ַ���*1(ֻ��������ĵ�ַ)

3.���ݵĵ�ַ�ǵ��ú�����SP+�����Offset
*/

class VarList{
public:
	string ID_Name;//������
	int Type;//��������
	bool isArray;//�Ƿ�������
	int Array_Len;//���鳤��
	int offset;//ƫ����,�������Ѱַoffset[SP]
public:
    VarList();
    VarList(const VarList &copy);
};//���ű��һ��

VarList::VarList()
{
	ID_Name="";
	Type=VOID;//init
	Array_Len=0;
	offset=-1;//init
	isArray=false;
}
VarList::VarList(const VarList &copy)
{
	this->ID_Name=copy.ID_Name;
	this->Array_Len=copy.Array_Len;
	this->offset=copy.offset;
	this->Type=copy.Type;
	this->isArray=copy.isArray;
}

class SymbolTable
{
protected:
	vector<VarList> Buckets[256];//Hash����Ŀ
public:
	bool Lookup(string name,VarList &r);//���ҷ��ű�
	VarList * Lookup(string name);//���ҷ��ű�
	bool insert(VarList e);//����һ��
	bool GetMaxiumOffsetVar(string name,VarList &r);//�õ����ƫ�����ı�����Ϣ
	SymbolTable(SymbolTable &copy);//�������캯��
	SymbolTable();
	void Reset();
};
void SymbolTable::Reset()
{
	for(int i=0;i<256;i++)
	{
		Buckets[i].clear();
	}
}
bool SymbolTable::GetMaxiumOffsetVar(string name,VarList &r)//�õ����ƫ�����ı�����Ϣ
{
	int of=0;
	VarList LST;
	for(int i=0;i<256;i++)
	{
		vector<VarList> &VL=Buckets[i];
		for(int j=0;j<VL.size();j++)
		{
			if(VL[j].ID_Name.length()!=0)
			{
				if(VL[j].offset>of)
				{
					LST=VL[j];
					of=LST.offset;
				}
			}
		}
	}
	if(LST.ID_Name.length()==0) return false;
	else
	{
		r=LST;
		return true;
	}
}
bool SymbolTable::Lookup(string name,VarList &r)//���ҷ��ű�
{
	int hash_val=Hash_String(name);
	vector<VarList> &vct=Buckets[hash_val];//
	for(int i=0;i<vct.size();i++)
	{
		if(vct[i].ID_Name.compare(name)==0)
		{
			r=vct[i];
			return true;
		}
	}
	return false;
}
VarList * SymbolTable::Lookup(string name)//���ҷ��ű�
{
	int hash_val=Hash_String(name);
	vector<VarList> &vct=Buckets[hash_val];//
	VarList * r=0;
	for(int i=0;i<vct.size();i++)
	{
		if(vct[i].ID_Name.compare(name)==0)
		{
			r=&(vct[i]);//���ַ
			return r;
		}
	}
	r=0;
	return r;
}
bool SymbolTable::insert(VarList e)//����һ��
{
	int hash_val=Hash_String(e.ID_Name);
	VarList temp;
	if(Lookup(e.ID_Name,temp)){
		return false;//�Ѿ����ڣ����ܲ���
	}
	else
	{
		Buckets[hash_val].push_back(e);//����
		return true;
	}
}
SymbolTable::SymbolTable(SymbolTable &copy)//�������캯��
{
	for(int i=0;i<256;i++)
	{
		this->Buckets[i]=copy.Buckets[i];
	}
}
SymbolTable::SymbolTable()
{
	/*for(int i=0;i<256;i++)
	{
		Buckets[i].clear();
	}*/
}

/////////////////////////////////////////////////////////////////////////////////////

class Function_Table{
public:
	Function_Table(const Function_Table &copy);//�������캯��
	Function_Table();
public:
	string Fun_Name;//������
	int param_num;//��������
	int return_type;//��������
	vector<VarList> param_VarList;//�������ֱ�
	int top;//���¼�������λ��
	SymbolTable Local_ST;//�ݾֲ����ű�,class
	bool FULLC;//�Ƿ������
	int DECLR;//���������������ظ�,���Ҳ�����дһ�Σ�����һ��
	void Reset();
};//������
void Function_Table::Reset()
{
	Local_ST.Reset();
}
Function_Table::Function_Table()
{
	Fun_Name="";
	param_num=0;
	return_type = VOID;
	param_VarList.clear();
	top=0;
	FULLC=false;//pr h
	DECLR=0;//pr l
}
Function_Table::Function_Table(const Function_Table &copy)//�������캯��
{
	this->param_num=copy.param_num;
	this->Fun_Name=copy.Fun_Name;
	this->param_VarList=copy.param_VarList;
	this->Local_ST=copy.Local_ST;
	this->return_type=copy.return_type;
	this->top=copy.top;
	this->FULLC=copy.FULLC;
	this->DECLR=copy.DECLR;
}
/////////////////////////////////////////////////////////////////////////////////////

class FunctionTableManager
{
protected:
	vector<Function_Table> Buckets[256];//�����;ֲ����ű�
public:
	bool Lookup(string name,Function_Table &r);//���ҷ��ű�
	Function_Table *Lookup(string name);//���ҷ��ű�
	bool insert(Function_Table e);//����һ��
	bool insert_var(string fun_name,VarList &e);//����һ��ֲ��������ű�
	void Reset();
	bool update(string fun_name, string var_name, int val);//���º�������Ϣ
};
void FunctionTableManager::Reset()
{
	for(int i=0;i<256;i++)
	{
		Buckets[i].clear();
	}
}

bool FunctionTableManager::update(string fun_name, string var_name, int val) {
	int hash_val = Hash_String(fun_name);
	vector<Function_Table> &vct = Buckets[hash_val];
	for(int i = 0; i < vct.size(); i++) {
		if(vct[i].Fun_Name.compare(fun_name) == 0) {
			if(var_name.compare("top") == 0)
				vct[i].top = val;
			else if(var_name.compare("return_type") == 0)
				vct[i].return_type = val;
			return true;
		}
	}
	return false;
}

bool FunctionTableManager::Lookup(string name,Function_Table &r)//���ҷ��ű�
{
	int hash_val=Hash_String(name);
	vector<Function_Table> &vct=Buckets[hash_val];//
	for(int i=0;i<vct.size();i++)
	{
		if(vct[i].Fun_Name.compare(name)==0)
		{
			r=vct[i];
			return true;
		}
	}
	return false;
}
Function_Table *FunctionTableManager::Lookup(string name)//���ҷ��ű�
{
	int hash_val=Hash_String(name);
	vector<Function_Table> &vct=Buckets[hash_val];//
	Function_Table *r=0;
	for(int i=0;i<vct.size();i++)
	{
		if(vct[i].Fun_Name.compare(name)==0)
		{
			r=&(vct[i]);//���ַ
			return r;
		}
	}
	r=0;
	return r;
}
bool FunctionTableManager::insert(Function_Table e)//����һ��
{
	int hash_val=Hash_String(e.Fun_Name);
	Function_Table temp;
	if(Lookup(e.Fun_Name,temp)){
		return false;//�Ѿ����ڣ����ܲ���
	}
	else
	{
		Buckets[hash_val].push_back(e);//����
		return true;
	}
}
bool FunctionTableManager::insert_var(string fun_name,VarList &e)//����һ��ֲ��������ű�
{
	int hash_val=Hash_String(fun_name);
	Function_Table temp;
	vector<Function_Table> &FT=Buckets[hash_val];
	for(int i=0;i<FT.size();i++)
	{
		if(FT[i].Fun_Name.compare(fun_name)==0)
		{
			return FT[i].Local_ST.insert(e);
		}
	}
	return false;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//���صı�����Ϣ
class VarPlace
{
public:
	string VarName;//��������
	bool GlobalVar;//�Ƿ�ȫ�ֱ���
	string FunName;//����������
	int type;//����
	int offset;//ƫ����
	bool isArray;//�Ƿ�������
	int Array_Len;//���鳤��
	bool flags; //����Ƿ��ѱ���ֵ������
	VarPlace();
	VarPlace(const VarPlace &);
};
VarPlace::VarPlace()
{
	VarName="";//�ձ�ʾ������
	GlobalVar=false;
	Array_Len=0;
	FunName="";
	type=VOID;//init
	offset=-1;//init
	isArray=false;//init
}
VarPlace::VarPlace(const VarPlace &copy)
{
	VarName=copy.VarName;
	GlobalVar=copy.GlobalVar;
	FunName=copy.FunName;
	type=copy.type;
	offset=copy.offset;
	Array_Len=copy.Array_Len;
	isArray=copy.isArray;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
class ManageSymbolTable
{
protected:
	FunctionTableManager FTM;//�����ֲ����ű�
	SymbolTable GST;//ȫ�ַ��ű�
	//����
public:
	//����
	bool Lookup(string var_name,string fun_name,VarPlace &VP);//���ұ�������Ϣ,fun_name=""��ʾ��global var
	bool insert(VarList &var,string fun_name);//���뵽��������
	bool insert_function(Function_Table &e);//�����¶���ĺ���
	bool GetFunction_Table(string name,Function_Table &FT);//�õ��������ű�
	bool GetMaxiumOffsetVar(string var_name,string fun_name,VarPlace &VP);//�õ����ƫ�����ı�������
	Function_Table * ManageSymbolTable::GetFunction_Table(string name);//�õ��������ű�
	VarList * Lookup(string var_name,string fun_name);//���ұ�������Ϣ,fun_name=""��ʾ��global var
	void Reset();
	bool update(string fun_name, string var_name, int val);//�޸ĺ�������ĳһ��������Ϣ
};
void ManageSymbolTable::Reset()
{
	FTM.Reset();
	GST.Reset();
}

bool ManageSymbolTable::update(string fun_name, string var_name, int val) {
	if(fun_name.length() == 0) {
		// do nothing
	} else {
		return FTM.update(fun_name, var_name, val);
	}
}

bool ManageSymbolTable::GetMaxiumOffsetVar(string var_name,string fun_name,VarPlace &VP)//�õ����ƫ�����ı�������
{
	if(fun_name.length()==0)//ȫ�ַ��ű�
	{
		VarList temp;
		bool isEst=GST.GetMaxiumOffsetVar(var_name,temp);
		if(isEst)
		{
			VP.FunName="";
			VP.GlobalVar=true;
			VP.isArray=temp.isArray;
			VP.Array_Len=temp.Array_Len;
			VP.offset=temp.offset;
			VP.VarName=var_name;
			VP.type=temp.Type;
			return true;
		}
		else return false;
	}
	else
	{
		Function_Table FT;
		if(FTM.Lookup(fun_name,FT))
		{
			VarList temp;
			if(FT.Local_ST.GetMaxiumOffsetVar(var_name,temp))
			{
				VP.FunName=fun_name;
				VP.GlobalVar=false;
				VP.isArray=temp.isArray;
				VP.Array_Len=temp.Array_Len;
				VP.offset=temp.offset;
				VP.VarName=var_name;
				VP.type=temp.Type;
				return true;
			}
			else return false;
		}
		else return false;
	}
}
VarList * ManageSymbolTable::Lookup(string var_name,string fun_name)//���ұ�������Ϣ,fun_name=""��ʾ��global var
{
	if(fun_name.length()==0)//��global
	{
		VarList *temp=0;
		temp=GST.Lookup(var_name);//���
		if(temp!=0)
		{
			return temp;
		}
		else 
		{
			return 0;
		}
	}
	else
	{
		Function_Table *temp=0;
		VarList *temp2=0;
		temp=FTM.Lookup(fun_name);
		if(temp!=0)
		{
			SymbolTable &ST=temp->Local_ST;
			temp2=ST.Lookup(var_name);
			if(temp2!=0)
			{
				return temp2;
			}
		}
	}
	return 0;
}
bool ManageSymbolTable::Lookup(string var_name,string fun_name,VarPlace &VP)//���ұ�������Ϣ,fun_name=""��ʾ��global var
{
	if(fun_name.length()==0)//��global
	{
		VarList temp;
		bool found=GST.Lookup(var_name,temp);//���
		if(found)
		{
			VP.FunName="";
			VP.GlobalVar=true;
			VP.offset=temp.offset;
			VP.type=temp.Type;
			VP.VarName=var_name;
			VP.Array_Len=temp.Array_Len;
			VP.isArray=temp.isArray;
			return true;
		}
	}
	else
	{
		Function_Table temp;
		VarList temp2;
		bool found_fun=FTM.Lookup(fun_name,temp);
		if(found_fun)
		{
			SymbolTable &ST=temp.Local_ST;
			bool found_var=ST.Lookup(var_name,temp2);
			if(found_var)
			{
				VP.FunName=fun_name;
				VP.GlobalVar=false;
				VP.offset=temp2.offset;
				VP.type=temp2.Type;
				VP.VarName=var_name;
				VP.Array_Len=temp2.Array_Len;
				VP.isArray=temp2.isArray;
				return true;
			}
		}
	}
	return false;
}
bool ManageSymbolTable::insert(VarList &var,string fun_name)//���뵽��������
{
	if(fun_name.length()==0)//ȫ��var����
	{
		VarList temp;
		if(GST.Lookup(var.ID_Name,temp))
		{
			//�Ѿ������ˣ���׼����
		}
		else
		{
			return GST.insert(var);
		}
	}
	else//�����ֲ�var����
	{
		Function_Table temp;
		bool found_fun=FTM.Lookup(fun_name,temp);
		if(found_fun)//��������
		{
			return FTM.insert_var(fun_name,var);
		}
	}
	return false;
}
bool ManageSymbolTable::insert_function(Function_Table &e)//�����¶���ĺ���
{
	Function_Table temp;
	if(FTM.Lookup(e.Fun_Name,temp))
	{
		//�ظ��ĺ�������
	}
	else
	{
		return FTM.insert(e);//���뺯������
	}
	return false;
}
bool ManageSymbolTable::GetFunction_Table(string name,Function_Table &FT)//�õ��������ű�
{
	return FTM.Lookup(name,FT);
}

Function_Table * ManageSymbolTable::GetFunction_Table(string name)//�õ��������ű�
{
	return FTM.Lookup(name);
}



/////////////////////////////////////////////////////////////////////////////////////////////////////
#endif //STRUCTURE_BASE_H
