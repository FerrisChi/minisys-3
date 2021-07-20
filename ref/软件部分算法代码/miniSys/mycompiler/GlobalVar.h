#ifndef _GLOBAL_VAR_H
#define _GLOBAL_VAR_H

#pragma once

#include "CONNECT_YACC.H"

typedef struct
{
	type_spec_   type_spec_v;//���ͽṹ
	IDENT_ IDENT_v;//ID�ṹ
	int_literal_ int_literal_v;//ʮ���Ƴ���
	expr_ expr_v;//expr��ֵ place,code
	stmt_ stmt_v;//�ڲ�һЩ��ص���� code
	fun_decl_ fun_decl_v;//�����ķ���
	param_ param_list_v;//����������Ϣ
	args_ args_list_v;//����������Ϣ
}YYTYPE;/*�����ı���*/

static YYTYPE yyval;

stack<YYTYPE> yysymbol;

static int yylineno=1;//�����к�

stack<int> typeStack;  //���ڴ�������Ѿ����������

bool isDebug;

#endif
