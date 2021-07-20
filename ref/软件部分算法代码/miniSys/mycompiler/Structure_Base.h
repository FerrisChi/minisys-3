/**----------符号表管理程序----------------------------
VarList 符号表的一行
VarPlace 变量的信息
Function_Table 函数表的一项
ManageSymbolTable 符号表管理程序
------VarList------------
	string ID_Name;//符号名
	int Type;//符号类型
	int Array_Len;//是否数组长度
	int offset;//偏移量,采用相对寻址offset[SP]
	bool isArray;//是否是数组
----------------------
------Function_Table--------
	string Fun_Name;//函数名
	int param_num;//参数个数
	int return_type;//返回类型
	vector<VarList> param_VarList;//参数名字表
	int top;//活动记录顶部相对位移
	SymbolTable Local_ST;//据局部符号表,class
	bool FULLC;//是否完成体
	int DECLR;//声明计数，避免重复,而且参数填写一次，计数一次
----------------------------
---VarPlace-----------------
	string VarName;//变量名字
	bool GlobalVar;//是否全局变量
	string FunName;//隶属函数名
	int type;//类型
	int offset;//偏移量
	int Array_Len;//数组长度
	bool isArray;//是否是数组
----------------------------
------------------------------------------------------**/
#ifndef STRUCTURE_BASE_H
#define STRUCTURE_BASE_H
#pragma once
#include "stdafx.h"
#include "yytab.h"



//#define NULL_TYPE 0 //不可用
//#define VOID_TYPE 1 //VOID型
//#define INT_TYPE 2  //INT型
//#define INT_ADDRESS_TYPE 3 //整数地址型

int GetTypeWidth(int type)//得到类型宽度
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

long Hash_String(string s) //字符Hash函数
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
/*数组翻译注意事项
由于默认数组名是数组地址
1.定义数组变量时:
isArray=true
Type属性
Array_Len按用户给的大小
offset的计算为offset+=Type.width*Array_Len

2.作为函数参数申明时:
isArray=false
Type属性=INT__ADDRESS_TYPE
offset的计算为offset+=32位地址宽度*1(只保存数组的地址)

3.传递的地址是调用函数的SP+数组的Offset
*/

class VarList{
public:
	string ID_Name;//符号名
	int Type;//符号类型
	bool isArray;//是否是数组
	int Array_Len;//数组长度
	int offset;//偏移量,采用相对寻址offset[SP]
public:
    VarList();
    VarList(const VarList &copy);
};//符号表的一行

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
	vector<VarList> Buckets[256];//Hash表项目
public:
	bool Lookup(string name,VarList &r);//查找符号表
	VarList * Lookup(string name);//查找符号表
	bool insert(VarList e);//插入一项
	bool GetMaxiumOffsetVar(string name,VarList &r);//得到最大偏移量的变量信息
	SymbolTable(SymbolTable &copy);//拷贝构造函数
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
bool SymbolTable::GetMaxiumOffsetVar(string name,VarList &r)//得到最大偏移量的变量信息
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
bool SymbolTable::Lookup(string name,VarList &r)//查找符号表
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
VarList * SymbolTable::Lookup(string name)//查找符号表
{
	int hash_val=Hash_String(name);
	vector<VarList> &vct=Buckets[hash_val];//
	VarList * r=0;
	for(int i=0;i<vct.size();i++)
	{
		if(vct[i].ID_Name.compare(name)==0)
		{
			r=&(vct[i]);//求地址
			return r;
		}
	}
	r=0;
	return r;
}
bool SymbolTable::insert(VarList e)//插入一项
{
	int hash_val=Hash_String(e.ID_Name);
	VarList temp;
	if(Lookup(e.ID_Name,temp)){
		return false;//已经存在，不能插入
	}
	else
	{
		Buckets[hash_val].push_back(e);//插入
		return true;
	}
}
SymbolTable::SymbolTable(SymbolTable &copy)//拷贝构造函数
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
	Function_Table(const Function_Table &copy);//拷贝构造函数
	Function_Table();
public:
	string Fun_Name;//函数名
	int param_num;//参数个数
	int return_type;//返回类型
	vector<VarList> param_VarList;//参数名字表
	int top;//活动记录顶部相对位移
	SymbolTable Local_ST;//据局部符号表,class
	bool FULLC;//是否完成体
	int DECLR;//声明计数，避免重复,而且参数填写一次，计数一次
	void Reset();
};//函数表
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
Function_Table::Function_Table(const Function_Table &copy)//拷贝构造函数
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
	vector<Function_Table> Buckets[256];//函数和局部符号表
public:
	bool Lookup(string name,Function_Table &r);//查找符号表
	Function_Table *Lookup(string name);//查找符号表
	bool insert(Function_Table e);//插入一项
	bool insert_var(string fun_name,VarList &e);//插入一项到局部函数符号表
	void Reset();
	bool update(string fun_name, string var_name, int val);//更新函数的信息
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

bool FunctionTableManager::Lookup(string name,Function_Table &r)//查找符号表
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
Function_Table *FunctionTableManager::Lookup(string name)//查找符号表
{
	int hash_val=Hash_String(name);
	vector<Function_Table> &vct=Buckets[hash_val];//
	Function_Table *r=0;
	for(int i=0;i<vct.size();i++)
	{
		if(vct[i].Fun_Name.compare(name)==0)
		{
			r=&(vct[i]);//求地址
			return r;
		}
	}
	r=0;
	return r;
}
bool FunctionTableManager::insert(Function_Table e)//插入一项
{
	int hash_val=Hash_String(e.Fun_Name);
	Function_Table temp;
	if(Lookup(e.Fun_Name,temp)){
		return false;//已经存在，不能插入
	}
	else
	{
		Buckets[hash_val].push_back(e);//插入
		return true;
	}
}
bool FunctionTableManager::insert_var(string fun_name,VarList &e)//插入一项到局部函数符号表
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
//返回的变量信息
class VarPlace
{
public:
	string VarName;//变量名字
	bool GlobalVar;//是否全局变量
	string FunName;//隶属函数名
	int type;//类型
	int offset;//偏移量
	bool isArray;//是否是数组
	int Array_Len;//数组长度
	bool flags; //标记是否已被赋值函数名
	VarPlace();
	VarPlace(const VarPlace &);
};
VarPlace::VarPlace()
{
	VarName="";//空表示不可用
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
	FunctionTableManager FTM;//函数局部符号表
	SymbolTable GST;//全局符号表
	//数据
public:
	//操作
	bool Lookup(string var_name,string fun_name,VarPlace &VP);//查找变量的信息,fun_name=""表示查global var
	bool insert(VarList &var,string fun_name);//插入到函数表中
	bool insert_function(Function_Table &e);//插入新定义的函数
	bool GetFunction_Table(string name,Function_Table &FT);//得到函数符号表
	bool GetMaxiumOffsetVar(string var_name,string fun_name,VarPlace &VP);//得到最大偏移量的变量属性
	Function_Table * ManageSymbolTable::GetFunction_Table(string name);//得到函数符号表
	VarList * Lookup(string var_name,string fun_name);//查找变量的信息,fun_name=""表示查global var
	void Reset();
	bool update(string fun_name, string var_name, int val);//修改函数表中某一函数的信息
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

bool ManageSymbolTable::GetMaxiumOffsetVar(string var_name,string fun_name,VarPlace &VP)//得到最大偏移量的变量属性
{
	if(fun_name.length()==0)//全局符号表
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
VarList * ManageSymbolTable::Lookup(string var_name,string fun_name)//查找变量的信息,fun_name=""表示查global var
{
	if(fun_name.length()==0)//查global
	{
		VarList *temp=0;
		temp=GST.Lookup(var_name);//查表
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
bool ManageSymbolTable::Lookup(string var_name,string fun_name,VarPlace &VP)//查找变量的信息,fun_name=""表示查global var
{
	if(fun_name.length()==0)//查global
	{
		VarList temp;
		bool found=GST.Lookup(var_name,temp);//查表
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
bool ManageSymbolTable::insert(VarList &var,string fun_name)//插入到函数表中
{
	if(fun_name.length()==0)//全局var插入
	{
		VarList temp;
		if(GST.Lookup(var.ID_Name,temp))
		{
			//已经存在了，不准插入
		}
		else
		{
			return GST.insert(var);
		}
	}
	else//函数局部var插入
	{
		Function_Table temp;
		bool found_fun=FTM.Lookup(fun_name,temp);
		if(found_fun)//函数存在
		{
			return FTM.insert_var(fun_name,var);
		}
	}
	return false;
}
bool ManageSymbolTable::insert_function(Function_Table &e)//插入新定义的函数
{
	Function_Table temp;
	if(FTM.Lookup(e.Fun_Name,temp))
	{
		//重复的函数插入
	}
	else
	{
		return FTM.insert(e);//插入函数定义
	}
	return false;
}
bool ManageSymbolTable::GetFunction_Table(string name,Function_Table &FT)//得到函数符号表
{
	return FTM.Lookup(name,FT);
}

Function_Table * ManageSymbolTable::GetFunction_Table(string name)//得到函数符号表
{
	return FTM.Lookup(name);
}



/////////////////////////////////////////////////////////////////////////////////////////////////////
#endif //STRUCTURE_BASE_H
