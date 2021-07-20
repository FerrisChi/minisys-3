#ifndef _GLOBAL_VAR_H
#define _GLOBAL_VAR_H

#pragma once

#include "CONNECT_YACC.H"

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
}YYTYPE;/*关联的变量*/

static YYTYPE yyval;

stack<YYTYPE> yysymbol;

static int yylineno=1;//跟踪行号

stack<int> typeStack;  //用于存放所有已经定义的类型

bool isDebug;

#endif
