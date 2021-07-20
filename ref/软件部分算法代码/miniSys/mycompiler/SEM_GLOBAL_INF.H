#ifndef SEM_GLOBAL_INF_H
#define SEM_GLOBAL_INF_H

#pragma once
#include "stdafx.h"
#include "Structure_Base.h"//符号表
#include "SEM_CODE.H"
#include "FunctionForest.h"//函数森林


/*
中间翻译时候保存一些中间的变量和符号表信息
*/

/*一些结构声明*/
class While_Compound_
{
public:
	While_Compound_()
	{
		isInWhileStmt=false;
		entry="";
		exit="";
	}
	bool isInWhileStmt;//是否目前在while体内
	string entry;//入口
	string exit;//出口
};//while翻译时候的入口信息

class Function_Compound_
{
public:
	Function_Compound_()
	{
		IDENT_NAME="";
		isBegFunDecl=false;
		exitLabel = "";
	}
	string IDENT_NAME;
	bool isBegFunDecl;//是否开始了函数声明

	string exitLabel;
};//函数翻译时候的相关信息

class Postfix_Exp_ {
public:
	Postfix_Exp_() {
		postfix_map.clear();
		isPostfixExp = false;
	}
	bool isPostfixExp;
	map<string, Operator_NUM> postfix_map;
	void reset() {
		isPostfixExp = false;
		postfix_map.clear();
	}
};// 后缀表达式的延迟处理，使用map记录

/*重要全局数据*/

ManageSymbolTable MST;//符号表管理函数

While_Compound_ WC_;//while翻译中间的全局信息

stack<While_Compound_> while_stack;//可能有while嵌套

Function_Compound_ FC_;//函数翻译时的是否在函数体内的翻译

Postfix_Exp_ PE_;

int global_offset=0;//全局数据的偏移计数

int local_offset=0;//局部变量声明的偏移计数

int Label_num=0;//标号计数

int Temp_Var_num=0;//临时变量计数

string Gen_New_Label() //产生新标号
{
	Label_num++;
	return new_label(Label_num);
}

string Gen_New_Temp_Var_Label() //产生临时变量的名字
{
	Temp_Var_num++;
	return new_temp_var_label(Temp_Var_num);
}

Operator_NUM GenTemp(int type) //产生临时变量
{
	Operator_NUM ON;
	ON.isLabel=false;
	ON.Var.IsTempVar=true;
	ON.Var.IsImmNum=false;
	ON.Var.VT.TempVar_ID=Gen_New_Temp_Var_Label();
	ON.Var.VT.type=type;
	return ON;
}

//临时的决定
static int Global_Fun_type = VOID;
//全局当前得到的类型（提供函数声明返回类型的初始化)

//函数森林
static vector<Forest>  Fun_Sem_Forest;
static vector<Forest_REG>  Fun_Sem_Forest_REG;//带寄存器分配的REG
//函数中间翻译的森林群

//输出日志
static fstream err_lst;

#endif //SEM_GLOBAL_INF_H
