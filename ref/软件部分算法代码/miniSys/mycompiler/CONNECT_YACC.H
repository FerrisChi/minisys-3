#ifndef CONNECT_YACC_H
#define CONNECT_YACC_H


#pragma once
#include"SEM_CODE.h"
#include "Structure_Base.h"


/*
符号的语义属性定义
*/

class _params_rec//参数定义描述
{
public:
	vector<VarList> params_list;//先不计算offset
	_params_rec()
	{
		params_list.clear();
	}
	_params_rec(const _params_rec &copy)
	{
		params_list=copy.params_list;//
	}
	void append_back(VarList &lis)//添加参数定义
	{
		params_list.push_back(lis);
	}
	void append_back(_params_rec &mo)//添加参数定义
	{
		for(int i=0;i<mo.params_list.size();i++)
		{
			params_list.push_back(mo.params_list[i]);
		}
	}
};

class _args_rec //函数参数队列
{
public:
	vector<Operator_NUM> args_place;//参数信息
	_args_rec()
	{
		args_place.clear();
	}
	_args_rec(const _args_rec &copy)
	{
		args_place=copy.args_place;//
	}
	void append_back(Operator_NUM &opn)//添加参数定义
	{
		args_place.push_back(opn);
	}
	void append_back(_args_rec &mo)//添加参数定义
	{
		for(int i=0;i<mo.args_place.size();i++)
		{
			args_place.push_back(mo.args_place[i]);
		}
	}
};

typedef struct
{
	int type;
	int width;
}type_spec_;//类型结构

typedef struct
{
	string ID_NAME;
}IDENT_;//ID结构


typedef struct
{
	int int_val;
}int_literal_;//十进制常数


typedef struct
{
	Operator_NUM place;//计算结果存放的变量信息
	SEM_CODE code;//生成的中间代码
}expr_;//expr的值

typedef struct
{
	SEM_CODE code;//生成的中间代码
}stmt_;//内部一些相关的语句


typedef struct
{
	string fun_name;//函数名
	SEM_CODE code;//生成的中间代码
}fun_decl_;//函数的翻译

typedef struct
{
	_params_rec param_lst;//参数定义描述
}param_;//参数定义信息

typedef struct
{
	_args_rec args_lst;//函数参数队列
}args_;




typedef struct
{
	type_spec_   type_spec_v;//类型结构
	IDENT_ IDENT_v;//ID结构
	int_literal_ int_literal_v;//十进制常数
	expr_ expr_v;//expr的值 place,code
	stmt_ stmt_v;//内部一些相关的语句 code
	fun_decl_ fun_decl_v;//函数的翻译
	param_ param_list_v;//参数定义信息
	args_ args_list_v;//参数传递信息
}_yytype;

#endif //CONNECT_YACC_H
