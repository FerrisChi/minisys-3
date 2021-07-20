#ifndef YYACTION_H
#define YYACTION_H
#pragma once
#include "GlobalVar.h"
#include "SEM_GLOBAL_INF.H"
#include "FunctionForest.h"


//判断二元运算符两侧的类型是否相同，返回两侧的类型，如果已经有错，返回false
//适用符号：==  ！=  + -  *  /  %  
bool isTwoTypeSame(vector<YYTYPE>YYV, int &expType1, int &expType2, VarPlace &VP);


//produceID---产生式ID，  reduceDepth---规约深度---产生式长度
bool checkAction(int produceID, int reduceDepth) {
	vector<YYTYPE> YYV;
	YYV.clear();
	YYTYPE nextItem;
	
	for(int i = 0; i < reduceDepth; i++) {
		if(yysymbol.empty()){
			cout<<"语义处理出错"<<"\r\n";
			return false;
		}

		YYV.push_back(yysymbol.top());
		yysymbol.pop();
	}

	//变量定义
	SEM_CODE SC;      //中间代码
	QUAD_EXP_ROW QER;//产生四元式
    Operator_NUM ON;//操作数
    static Operator_NUM DOLLAR_ON;//操作数
	VarPlace VP;    //变量定义

	string id;     //名字
	string lentry;  //跳转入口标号
	string lexit;   //跳转出口标号

	Function_Table *finFT; //用于查找函数
	Function_Table newFT;  //注册新函数

	int i_count;  //for循环用计数器
	int count_num; //for循环用计数上限值
	bool isError = false;  //是否出错

	int expType1;  //记录条件判断语句符号两侧的值的类型
	int expType2;

	VarList newParam;  //新的参数定义
	Forest fst;


	switch (produceID) {
	case 1:   //   start			: translation_unit	
		nextItem.type_spec_v = YYV[0].type_spec_v;
		//nextItem.expr_v.place = YYV[0].expr_v.place;
		nextItem.fun_decl_v = YYV[0].fun_decl_v;

		nextItem.stmt_v.code = YYV[0].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 2:   //   translation_unit	: external_declaration	
		nextItem.type_spec_v = YYV[0].type_spec_v;
		//nextItem.expr_v.place = YYV[0].expr_v.place;
		nextItem.fun_decl_v = YYV[0].fun_decl_v;

		nextItem.stmt_v.code = YYV[0].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 3:  //    translation_unit	| translation_unit external_declaration	
		YYV[1].stmt_v.code.AppendTail(YYV[0].stmt_v.code);
		nextItem.stmt_v.code = YYV[1].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 4:  //  external_declaration : function_definition	
		nextItem.type_spec_v = YYV[0].type_spec_v;
		nextItem.fun_decl_v = YYV[0].fun_decl_v;

		nextItem.stmt_v.code = YYV[0].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 5:  //  external_declaration | declaration
		nextItem.type_spec_v = YYV[0].type_spec_v;
		//nextItem.expr_v.place = YYV[0].expr_v.place;

		nextItem.stmt_v.code = YYV[0].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 6:  //  function_definition  : declaration_specifiers declarator declaration_list compound_statement	
		YYV[1].stmt_v.code.AppendTail(YYV[0].stmt_v.code);
		YYV[2].stmt_v.code.AppendTail(YYV[1].stmt_v.code);
		YYV[3].stmt_v.code.AppendTail(YYV[2].stmt_v.code);
		nextItem.stmt_v.code = YYV[3].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 7:  //  function_definition | declaration_specifiers declarator compound_statement	
		/*QER.OP = "LABEL";    //函数入口标签，已经不需要
		QER.RS.isLabel = true;
		QER.RS.label = FC_.IDENT_NAME;
		SC.AppendTail(QER);*/
		SC.AppendTail(YYV[0].stmt_v.code);   //压入函数体内的三地址码

		//填充函数的返回类型
		finFT = MST.GetFunction_Table(FC_.IDENT_NAME);

		if(NULL != finFT) {
			//finFT->return_type = YYV[2].type_spec_v.type;
			//MST.update(FC_.IDENT_NAME, "return_type", YYV[2].type_spec_v.type);
			MST.update(FC_.IDENT_NAME, "top", local_offset);
		} else {
			if(isDebug) {  //输出到控制台
				cout<<"Error Line-"<<yylineno<<":  产生式7错误：无法找到需要填充返回类型的函数！"<<endl;
			} else {  //写入到错误日志
				err_lst<<"Error Line-"<<yylineno<<":  产生式7错误：无法找到需要填充返回类型的函数！"<<endl;
			}
		}

		//函数结束
		FC_.isBegFunDecl = false;

		//建立函数森林
		fst.Fun_Name = FC_.IDENT_NAME;
		fst.SC=YYV[0].stmt_v.code;
		
		Fun_Sem_Forest.push_back(fst);//加入森林

		//生成函数结束的标号
		/*QER.OP = "LABEL";
		QER.RS.isLabel = true;
		QER.RS.label = FC_.exitLabel;
		SC.AppendTail(QER);*/
		nextItem.stmt_v.code = SC;

		yysymbol.push(nextItem);
		return true;
	case 8:  //  declaration_specifiers	: STATIC	
		yysymbol.push(nextItem);
		return true;
	case 9:  //  declaration_specifiers	| STATIC declaration_specifiers	
		YYV[1].stmt_v.code.AppendTail(YYV[0].stmt_v.code);
		nextItem.stmt_v.code = YYV[1].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 10: //  declaration_specifiers	| type_specifier
		nextItem.type_spec_v = YYV[0].type_spec_v;
		nextItem.stmt_v.code = YYV[0].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 11: //  declaration_specifiers	| type_specifier declaration_specifiers	
		// plpan: here adds unsigned and signed
		if(YYV[1].type_spec_v.type != UNSIGNED || YYV[1].type_spec_v.type != SIGNED) {
			if(isDebug) {  //输出到控制台
				cout<<"Error Line-"<<yylineno<<":  产生式11错误：类型'" << YYV[1].type_spec_v.type << "'申明错误" << endl;
			} else {  //写入到错误日志
				err_lst<<"Error Line-"<<yylineno<<":  产生式11错误：类型'" << YYV[1].type_spec_v.type << "'申明错误" << endl;
			}
			isError = true;
		}
		if(YYV[0].type_spec_v.type == VOID || YYV[0].type_spec_v.type == BOOL) {
			if(isDebug) {  //输出到控制台
				cout<<"Error Line-"<<yylineno<<":  产生式11错误：类型'" << YYV[0].type_spec_v.type << "'申明错误" << endl;
			} else {  //写入到错误日志
				err_lst<<"Error Line-"<<yylineno<<":  产生式11错误：类型'" << YYV[0].type_spec_v.type << "'申明错误" << endl;
			}
			isError = true;
		}
		//YYV[1].stmt_v.code.AppendTail(YYV[0].stmt_v.code);

		if(!isError) {
			typeStack.pop();   //将int,char,short等换为unsigned int

			switch (YYV[0].type_spec_v.type)
			{
			case CHAR:
				nextItem.type_spec_v.type = U_CHAR;
				typeStack.push(U_CHAR);
				break;
			case SHORT:
				nextItem.type_spec_v.type = U_SHORT;
				typeStack.push(U_SHORT);
				break;
			case INT:
				nextItem.type_spec_v.type = U_INT;
				typeStack.push(U_INT);
				break;
			case LONG:
				nextItem.type_spec_v.type = U_LONG;
				typeStack.push(U_LONG);
				break;
			default:
				break;
			}
			nextItem.type_spec_v.width = YYV[0].type_spec_v.width;
		}
		//nextItem.stmt_v.code = YYV[1].stmt_v.code;
		yysymbol.push(nextItem);
		return !isError;
	case 12: //  declaration_specifiers	| CONST	--无三地址码
		yysymbol.push(nextItem);
		return true;
	case 13: // declaration_specifiers	| CONST declaration_specifiers	
		YYV[1].stmt_v.code.AppendTail(YYV[0].stmt_v.code);
		nextItem.stmt_v.code = YYV[1].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 14: // type_specifier : VOID	
		nextItem.type_spec_v.type = VOID;
		nextItem.type_spec_v.width = 0;
		yysymbol.push(nextItem);
		typeStack.push(VOID);
		return true;
	case 15: // type_specifier | CHAR	
		nextItem.type_spec_v.type = CHAR;
		nextItem.type_spec_v.width = 1;  
		yysymbol.push(nextItem);
		typeStack.push(CHAR);
		return true;
	case 16: //type_specifier| SHORT	
		nextItem.type_spec_v.type = SHORT;
		nextItem.type_spec_v.width = 2;
		yysymbol.push(nextItem);
		typeStack.push(SHORT);
		return true;
	case 17: //type_specifier| INT
		nextItem.type_spec_v.type = INT;
		typeStack.push(INT);
		nextItem.type_spec_v.width = 4;
		yysymbol.push(nextItem);
		return true;
	case 18: //type_specifier| LONG
		nextItem.type_spec_v.type = LONG;
		typeStack.push(LONG);
		nextItem.type_spec_v.width = 8;
		yysymbol.push(nextItem);
		return true;
	case 19: //type_specifier| SIGNED	
		nextItem.type_spec_v.type = SIGNED;
		yysymbol.push(nextItem);
		return true;
	case 20: //type_specifier| UNSIGNED	
		nextItem.type_spec_v.type = UNSIGNED;
		yysymbol.push(nextItem);
		return true;
	case 21: //type_specifier| BOOL	
		nextItem.type_spec_v.type = BOOL;
		typeStack.push(BOOL);
		nextItem.type_spec_v.width = 1;
		yysymbol.push(nextItem);
		return true;
	case 22: //declarator : direct_declarator	
		nextItem.expr_v.place = YYV[0].expr_v.place;
		nextItem.fun_decl_v = YYV[0].fun_decl_v;

		nextItem.stmt_v.code = YYV[0].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 23: //direct_declarator : IDENTIFIER	
		//统一插入place中
		nextItem.expr_v.place.isLabel = false;
		nextItem.expr_v.place.Var.IsImmNum = false;
		nextItem.expr_v.place.Var.IsTempVar = false;
		nextItem.expr_v.place.Var.VP.VarName = YYV[0].IDENT_v.ID_NAME;
		nextItem.expr_v.place.Var.VP.isArray = false;

		yysymbol.push(nextItem);
		return true;
	case 24: //direct_declarator | LPAR declarator RPAR	
		// plpan: ?
		YYV[2].stmt_v.code.AppendTail(YYV[1].stmt_v.code);
		nextItem.stmt_v.code = YYV[2].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 25: //	direct_declarator	| direct_declarator LBRACKET CONST assignment_expression RBRACKET	
		YYV[2].stmt_v.code.AppendTail(YYV[1].stmt_v.code);
		YYV[3].stmt_v.code.AppendTail(YYV[2].stmt_v.code);
		YYV[4].stmt_v.code.AppendTail(YYV[3].stmt_v.code);
		nextItem.stmt_v.code = YYV[4].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 26: //	direct_declarator	| direct_declarator LBRACKET CONST RBRACKET	
		nextItem.stmt_v.code = YYV[3].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 27: //	direct_declarator	| direct_declarator LBRACKET assignment_expression RBRACKET	
		// declare for array
		YYV[3].stmt_v.code.AppendTail(YYV[1].stmt_v.code);
		nextItem.stmt_v.code = YYV[3].stmt_v.code;

		id = YYV[3].expr_v.place.Var.VP.VarName;
		if(FC_.isBegFunDecl) {
			// local array
			if(MST.Lookup(id, FC_.IDENT_NAME, VP)) {
				if(isDebug) {  //输出到控制台
					cout<<"Error Line-"<<yylineno<<":  产生式27错误：变量'" << id << "'重定义" << endl;
				} else {  //写入到错误日志
					err_lst<<"Error Line-"<<yylineno<<":  产生式27错误：变量'" << id << "'重定义" << endl;
				}
				isError = true;
			}
		} else {
			// global array
			if(MST.Lookup(id, "", VP)) {
				if(isDebug) {  //输出到控制台
					cout<<"Error Line-"<<yylineno<<":  产生式27错误：变量'" << id << "'重定义" << endl;
				} else {  //写入到错误日志
					err_lst<<"Error Line-"<<yylineno<<":  产生式27错误：变量'" << id << "'重定义" << endl;
				}
				isError = true;
			}
		}

		if(id.length() == 0) {
			if(isDebug) {  //输出到控制台
				cout<<"Error Line-"<<yylineno<<":  产生式27错误：编译器内部出错" << endl;
			} else {  //写入到错误日志
				err_lst<<"Error Line-"<<yylineno<<":  产生式27错误：编译器内部出错" << endl;
			}
			isError = true;
		}
		if(!YYV[1].expr_v.place.Var.imm_num) {
			if(isDebug) {  //输出到控制台
				cout<<"Error Line-"<<yylineno<<":  产生式27错误：数组长度只能说立即数类型" << endl;
			} else {  //写入到错误日志
				err_lst<<"Error Line-"<<yylineno<<":  产生式27错误：数组长度只能说立即数类型" << endl;
			}
			isError = true;
		}
		if(YYV[1].expr_v.place.Var.imm_num <= 0) {
			if(isDebug) {  //输出到控制台
				cout<<"Error Line-"<<yylineno<<":  产生式27错误：数组长度必须是大于0的数" << endl;
			} else {  //写入到错误日志
				err_lst<<"Error Line-"<<yylineno<<":  产生式27错误：数组长度必须是大于0的数" << endl;
			}
			isError = true;
		}

		YYV[3].expr_v.place.Var.VP.isArray = true;
		YYV[3].expr_v.place.Var.VP.VarName = id;
		YYV[3].expr_v.place.Var.VP.Array_Len = YYV[1].expr_v.place.Var.imm_num;
		nextItem.expr_v.place = YYV[3].expr_v.place;
		yysymbol.push(nextItem);
		return !isError;
	case 28: //	direct_declarator	| direct_declarator LBRACKET STATIC CONST assignment_expression RBRACKET
		YYV[2].stmt_v.code.AppendTail(YYV[1].stmt_v.code);
		YYV[3].stmt_v.code.AppendTail(YYV[2].stmt_v.code);
		YYV[4].stmt_v.code.AppendTail(YYV[3].stmt_v.code);
		YYV[5].stmt_v.code.AppendTail(YYV[4].stmt_v.code);
		nextItem.stmt_v.code = YYV[5].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 29: //	direct_declarator	| direct_declarator LBRACKET CONST STATIC assignment_expression RBRACKET
		YYV[2].stmt_v.code.AppendTail(YYV[1].stmt_v.code);
		YYV[3].stmt_v.code.AppendTail(YYV[2].stmt_v.code);
		YYV[4].stmt_v.code.AppendTail(YYV[3].stmt_v.code);
		YYV[5].stmt_v.code.AppendTail(YYV[4].stmt_v.code);
		nextItem.stmt_v.code = YYV[5].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 30: //	direct_declarator	| direct_declarator LBRACKET RBRACKET	
		nextItem.stmt_v.code = YYV[2].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 31: //	direct_declarator	| direct_declarator LPAR parameter_list RPAR
		//标记为进入函数体，更改标记，注册函数
		isError = false;
		if(!FC_.isBegFunDecl) {
			FC_.isBegFunDecl = true;
			FC_.IDENT_NAME = YYV[3].expr_v.place.Var.VP.VarName;
		} else {
			if(isDebug) {  //输出到控制台
				cout<<"Error Line-"<<yylineno<<":  产生式31错误：函数内部不可以定义函数！"<<endl;
			} else {  //写入到错误日志
				err_lst<<"Error Line-"<<yylineno<<":  产生式31错误：函数内部不可以定义函数！"<<endl;
			}
			isError = true;
		}

		if(!isError) {
			//查找是否已有同名函数定义，此处目前只考虑函数重名，没有考虑函数签名
			finFT = MST.GetFunction_Table(FC_.IDENT_NAME); 

			if(finFT != NULL) {  //已存在该函数，需要报错
				if(isDebug) {  //输出到控制台
					cout<<"Error Line-"<<yylineno<<":  产生式31错误：函数定义: \'"<<FC_.IDENT_NAME<<"\' 已经被定义"<<endl;
				} else {  //写入到错误日志
					err_lst<<"Error Line-"<<yylineno<<":  产生式31错误：函数定义: \'"<<FC_.IDENT_NAME<<"\' 已经被定义"<<endl;
				}

				FC_.isBegFunDecl = false;   // 标记出函数体
				isError = true;

			} 
			
			if(!isError) { //函数不存在，注册函数
				newFT.Fun_Name = FC_.IDENT_NAME;   //函数名
				//此处无法填充函数返回类型
				newFT.param_VarList = YYV[1].param_list_v.param_lst.params_list;  // 参数列表
				newFT.param_num = YYV[1].param_list_v.param_lst.params_list.size();  //参数个数
				newFT.top = local_offset;

				count_num = YYV[1].param_list_v.param_lst.params_list.size();
				//弹栈获取函数类型定义
				for(i_count = 0; i_count < count_num; i_count++) {
					typeStack.pop();
				}

				newFT.return_type = typeStack.top();   //函数返回类型
				MST.insert_function(newFT);  // 插入到符号表管理程序
				
				if(isDebug){
					cout<<"注册函数： "<<newFT.Fun_Name<<endl;
				}
				
				//注册函数参数列表，压入到函数的局部符号表里
				for(i_count = 0; i_count < count_num; i_count++) {
					newParam = YYV[1].param_list_v.param_lst.params_list[i_count];
					newParam.offset = local_offset;
					local_offset += GetTypeWidth(newParam.Type);
					MST.insert(newParam, newFT.Fun_Name);
					
					if(isDebug){
						cout<<"注册函数\'"<<newFT.Fun_Name<<"\' 参数: "<<newParam.ID_Name<<endl;
					}
				}

			}

		}

		//清空栈
		while(!typeStack.empty()) {
			typeStack.pop();
		}

		//压入参数定义表
		nextItem.param_list_v.param_lst = YYV[1].param_list_v.param_lst;
		nextItem.IDENT_v.ID_NAME = FC_.IDENT_NAME; // 感觉也不需要

		nextItem.fun_decl_v.fun_name = YYV[3].expr_v.place.Var.VP.VarName;
		nextItem.fun_decl_v.code = YYV[1].stmt_v.code;

		//不确定，觉得不需要赋值place
		nextItem.expr_v.place = YYV[3].expr_v.place;

		YYV[2].stmt_v.code.AppendTail(YYV[1].stmt_v.code);
		YYV[3].stmt_v.code.AppendTail(YYV[2].stmt_v.code);
		nextItem.stmt_v.code = YYV[3].stmt_v.code;
		
		yysymbol.push(nextItem);
		return !isError;
	case 32: //	direct_declarator	| direct_declarator LPAR identifier_list RPAR
		//标记为进入函数体， 存在问题，此处应为函数调用后面不该是进入函数体
		//FC_.isBegFunDecl = true;
		//FC_.IDENT_NAME = YYV[3].expr_v.place.Var.VP.VarName;

		//压入传递参数列表
		nextItem.args_list_v.args_lst = YYV[1].args_list_v.args_lst;
		nextItem.IDENT_v.ID_NAME = FC_.IDENT_NAME;

		nextItem.fun_decl_v.fun_name = YYV[3].expr_v.place.Var.VP.VarName;
		nextItem.fun_decl_v.code = YYV[1].stmt_v.code;

		//不确定，觉得不需要赋值place
		nextItem.expr_v.place = YYV[3].expr_v.place;

		YYV[2].stmt_v.code.AppendTail(YYV[1].stmt_v.code);
		YYV[3].stmt_v.code.AppendTail(YYV[2].stmt_v.code);
		nextItem.stmt_v.code = YYV[3].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 33: //	direct_declarator	| direct_declarator LPAR RPAR	
		isError = false;
		if(!FC_.isBegFunDecl) {
			FC_.isBegFunDecl = true;
			FC_.IDENT_NAME = YYV[2].expr_v.place.Var.VP.VarName;
		} else {
			if(isDebug) {  //输出到控制台
				cout<<"Error Line-"<<yylineno<<":  产生式33错误：函数内部不可以定义函数！"<<endl;
			} else {  //写入到错误日志
				err_lst<<"Error Line-"<<yylineno<<":  产生式33错误：函数内部不可以定义函数！"<<endl;
			}
			isError = true;
		}
		
		if(!isError) {
			//查找是否已有同名函数定义，此处目前只考虑函数重名，没有考虑函数签名
			finFT = MST.GetFunction_Table(FC_.IDENT_NAME); 

			if(finFT != NULL) {  //已存在该函数，需要报错
				if(isDebug) {  //输出到控制台
					cout<<"Error Line-"<<yylineno<<":  产生式33错误：函数定义: \'"<<FC_.IDENT_NAME<<"\' 已经被定义"<<endl;
				} else {  //写入到错误日志
					err_lst<<"Error Line-"<<yylineno<<":  产生式33错误：函数定义: \'"<<FC_.IDENT_NAME<<"\' 已经被定义"<<endl;
				}

				FC_.isBegFunDecl = false;   //标记出函数体
				isError = true;
			} 
			if(!isError) {    //未重复定义，注册函数
				newFT.Fun_Name = FC_.IDENT_NAME;   //函数名
				//此处无法填充函数返回类型
				//无参数列表
				newFT.param_num = 0;  //参数个数
				newFT.top = local_offset;
				newFT.return_type = typeStack.top();   //函数返回类型
				MST.insert_function(newFT);  // 插入到符号表管理程序
				//FC_.exitLabel = Gen_New_Label();   //生成函数结束符
				if(isDebug) {
					cout<<"注册函数： "<<newFT.Fun_Name<<endl;
				}
			}
		}

		//清空栈
		while(!typeStack.empty()) {
			typeStack.pop();
		}

		nextItem.fun_decl_v.fun_name = YYV[2].expr_v.place.Var.VP.VarName;
		nextItem.fun_decl_v.code = YYV[2].stmt_v.code;
		
		nextItem.stmt_v.code = YYV[2].stmt_v.code;
		yysymbol.push(nextItem);
		return !isError;
	case 34: //	unary_expression	: postfix_expression	
		nextItem.expr_v.place = YYV[0].expr_v.place;
		nextItem.stmt_v.code = YYV[0].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 35: //	unary_expression	| INC_OP unary_expression		
		// plpan: the variable for INC_OP must be user defined
		nextItem.stmt_v.code = YYV[0].stmt_v.code;

		if(YYV[0].expr_v.place.isLabel || YYV[0].expr_v.place.Var.IsImmNum || YYV[0].expr_v.place.Var.IsTempVar) {
			if(isDebug) {  //输出到控制台
				cout<<"Error Line-"<<yylineno<<":  产生式35错误：表达式必须是一个可以修改的左值" << endl;
			} else {  //写入到错误日志
				err_lst<<"Error Line-"<<yylineno<<":  产生式35错误：表达式必须是一个可以修改的左值" << endl;
			}
			
			isError = true;
		}
		id = YYV[0].expr_v.place.Var.VP.VarName;
		if(id == "") {
			if(isDebug) {  //输出到控制台
				cout<<"Error Line-"<<yylineno<<":  产生式35错误：你是什么东东？" << endl;
			} else {  //写入到错误日志
				err_lst<<"Error Line-"<<yylineno<<":  产生式35错误：你是什么东东？" << endl;
			}
		} else if(!(FC_.isBegFunDecl && MST.Lookup(id, FC_.IDENT_NAME, VP)) || !MST.Lookup(id, "", VP)) {
			if(isDebug) {  //输出到控制台
				cout<<"Error Line-"<<yylineno<<":  产生式35错误：未定义变量\'"<<id<<"\'"<<endl;
			} else {  //写入到错误日志
				err_lst<<"Error Line-"<<yylineno<<":  产生式35错误：未定义变量\'"<<id<<"\'"<<endl;
			}

			isError = true;
		}

		ON = GenTemp(YYV[0].expr_v.place.Var.VP.type);
		// add one instruction
		QER.OP = "ADD";
		QER.RS = YYV[0].expr_v.place;
		QER.RT.isLabel = false;
		QER.RT.Var.IsImmNum = true;
		QER.RT.Var.imm_num = 1;
		QER.RD = ON;
		nextItem.stmt_v.code.AppendTail(QER);

		// write back
		QER.OP = "MOV";
		QER.RS = ON;
		QER.RD = YYV[0].expr_v.place;
		nextItem.stmt_v.code.AppendTail(QER);
		
		nextItem.expr_v.place = YYV[0].expr_v.place;
		yysymbol.push(nextItem);
		return !isError;

	case 36: //	unary_expression	| DEC_OP unary_expression		
	  nextItem.stmt_v.code = YYV[0].stmt_v.code;
		if(YYV[0].expr_v.place.isLabel || YYV[0].expr_v.place.Var.IsImmNum || YYV[0].expr_v.place.Var.IsTempVar) {
			if(isDebug) {  //输出到控制台
				cout<<"Error Line-"<<yylineno<<":  产生式36错误：表达式必须是一个可以修改的左值" << endl;
			} else {  //写入到错误日志
				err_lst<<"Error Line-"<<yylineno<<":  产生式36错误：表达式必须是一个可以修改的左值" << endl;
			}
			isError = true;
		}
		id = YYV[0].expr_v.place.Var.VP.VarName;
		if(id == "") {
			if(isDebug) {  //输出到控制台
				cout<<"Error Line-"<<yylineno<<":  产生式36错误：你是什么东东？" << endl;
			} else {  //写入到错误日志
				err_lst<<"Error Line-"<<yylineno<<":  产生式36错误：你是什么东东？" << endl;
			}
		} else if(!(FC_.isBegFunDecl && MST.Lookup(id, FC_.IDENT_NAME, VP)) && !MST.Lookup(id, "", VP)) {
			if(isDebug) {  //输出到控制台
				cout<<"Error Line-"<<yylineno<<":  产生式36错误：未定义变量\'"<<id<<"\'"<<endl;
			} else {  //写入到错误日志
				err_lst<<"Error Line-"<<yylineno<<":  产生式36错误：未定义变量\'"<<id<<"\'"<<endl;
			}
			isError = true;
		}

		ON = GenTemp(YYV[0].expr_v.place.Var.VP.type);
		QER.OP = "SUB";
		QER.RS = YYV[0].expr_v.place;
		QER.RT.isLabel = false;
		QER.RT.Var.IsImmNum = true;
		QER.RT.Var.imm_num = 1;
		QER.RD = ON;
		nextItem.stmt_v.code.AppendTail(SC);

		QER.OP = "MOV";
		QER.RS = ON;
		QER.RD = YYV[0].expr_v.place;
		nextItem.stmt_v.code.AppendTail(QER);

		nextItem.expr_v.place = YYV[0].expr_v.place;
		yysymbol.push(nextItem);
        return !isError;
	case 37: //	unary_expression	| unary_operator cast_expression	
		isError = false;
		SC.AppendTail(YYV[0].stmt_v.code); //先压入符号右侧表达式的三地址码
		
		if(YYV[0].expr_v.place.isLabel) {
			if(isDebug) {  //输出到控制台
				cout<<"Error Line-"<<yylineno<<":  产生式37错误：运算符右侧出现非法操作数"<<endl;
			} else {  //写入到错误日志
				err_lst<<"Error Line-"<<yylineno<<":  产生式37错误：运算符右侧出现非法操作数"<<endl;
			}

			isError = true;
		}

		//判断操作数类型
		if(!isError) {
			//立即数优化
			if(YYV[0].expr_v.place.Var.IsImmNum) {   
				if(YYV[1].type_spec_v.type == SUB_OP) {  // '-expr'
					ON.isLabel = false;
					ON.Var.IsImmNum = true;
					ON.Var.imm_num = 0 - YYV[0].expr_v.place.Var.imm_num;   
				} else if(YYV[1].type_spec_v.type == ADD_OP) {   //'+expr'
					ON.isLabel = false;
					ON.Var.IsImmNum = true;
					ON.Var.imm_num = YYV[0].expr_v.place.Var.imm_num;   
				} else if(YYV[1].type_spec_v.type == BIT_NOT) {   //'!expr'
					ON.isLabel = false;
					ON.Var.IsImmNum = true;
					if(YYV[0].expr_v.place.Var.imm_num == 0) {
						ON.Var.imm_num = 1;
					} else {
						ON.Var.imm_num = 0;
					}
                } else if(YYV[1].type_spec_v.type == DOLLAR) {   //'$expr'
                    ON.isLabel = false;
                    ON.Var.IsImmNum = true;
                    ON.Var.imm_num = YYV[0].expr_v.place.Var.imm_num;
                }

				nextItem.stmt_v.code = SC;
				nextItem.expr_v.place = ON;
				yysymbol.push(nextItem);
				return true;
			} else if(YYV[0].expr_v.place.Var.IsTempVar) {
				expType1 = YYV[0].expr_v.place.Var.VT.type;
			} else {
				id = YYV[0].expr_v.place.Var.VP.VarName;
				if(FC_.isBegFunDecl && !MST.Lookup(id, FC_.IDENT_NAME, VP) && !MST.Lookup(id, "", VP)) {
					if(isDebug) {  //输出到控制台
						cout<<"Error Line-"<<yylineno<<":  产生式37错误：未定义变量\'"<<id<<"\'请检查定义！"<<endl;
					} else {  //写入到错误日志
						err_lst<<"Error Line-"<<yylineno<<":  产生式37错误：未定义变量\'"<<id<<"\'请检查定义！"<<endl;
					}
					isError = true;
				} else if(!FC_.isBegFunDecl && !MST.Lookup(id, "", VP)) {
					if(isDebug) {  //输出到控制台
						cout<<"Error Line-"<<yylineno<<":  产生式37错误：未定义变量\'"<<id<<"\'请检查定义！"<<endl;
					} else {  //写入到错误日志
						err_lst<<"Error Line-"<<yylineno<<":  产生式37错误：未定义变量\'"<<id<<"\'请检查定义！"<<endl;
					}
					isError = true;
				} else {
					expType1 = VP.type;
				}
			}	

			if(expType1 != INT && expType1 != LONG && expType1 != SHORT) {
				if(isDebug) {  //输出到控制台
					cout<<"Error Line-"<<yylineno<<":  产生式37错误：运算符右侧操作数类型不合法"<<endl;
				} else {  //写入到错误日志
					err_lst<<"Error Line-"<<yylineno<<":  产生式37错误：运算符右侧操作数类型不合法"<<endl;
				}

				isError = true;
			}
		}

		if(!isError) {
			if(YYV[1].type_spec_v.type == ADD_OP) {   // '+ expr'
				nextItem.expr_v.place = YYV[0].expr_v.place;
			} else if (YYV[1].type_spec_v.type == SUB_OP) {
				ON = GenTemp(expType1);
				QER.OP = "SUB";
				QER.RS.isLabel = false;
				QER.RS.Var.imm_num = true;
				QER.RS.Var.imm_num = 0;
				QER.RT = YYV[0].expr_v.place;
				QER.RD = ON;
				SC.AppendTail(QER);
				nextItem.expr_v.place = ON;
			} else if (YYV[1].type_spec_v.type == BIT_NOT) {  //'!expr'
				lentry = Gen_New_Label();  //将临时变量赋值的入口标号
				lexit = Gen_New_Label();   //离开此段的标号
				ON = GenTemp(expType1);

				//检查是否等于0，等于跳转且赋值为1，不等于继续且赋值为0
				QER.OP = "BEQ";
				QER.RS.isLabel = false;
				QER.RS.Var.IsImmNum = true;
				QER.RS.Var.imm_num = 0;
				QER.RT = YYV[0].expr_v.place;
				QER.RD.isLabel = true;
				QER.RD.label = lentry;
				SC.AppendTail(QER);

				//将临时结果变量赋值为0
				QER.OP = "MOV";
				QER.RS.isLabel = false;
				QER.RS.Var.IsImmNum = true;
				QER.RS.Var.imm_num = 0;
				QER.RD = ON;
				SC.AppendTail(QER); //MOV 1,ON

				//跳转至此段结束
				QER.OP = "GOTO";
				QER.RD.isLabel = true;
				QER.RD.label = lexit;
				SC.AppendTail(QER); //goto exit

				//赋值入口标号
				QER.OP="LABEL";
				QER.RS.isLabel = true;
				QER.RS.label = lentry;
				SC.AppendTail(QER);  

				//将临时变量结果赋值为1
				QER.OP = "MOV";
				QER.RS.isLabel = false;
				QER.RS.Var.IsImmNum = true;
				QER.RS.Var.imm_num = 1;
				QER.RD = ON;
				SC.AppendTail(QER); //MOV 1,ON

				//此段结束
				QER.OP="LABEL";
				QER.RS.isLabel = true;
				QER.RS.label = lexit;
                SC.AppendTail(QER);

				nextItem.expr_v.place = ON;  //结果传递
            } else if (YYV[1].type_spec_v.type == DOLLAR) {  //'$expr'
                ON = GenTemp(expType1);
                QER.OP = "LOD";
                QER.RS = YYV[0].expr_v.place;
                QER.RD = ON;
                DOLLAR_ON = YYV[0].expr_v.place;
                SC.AppendTail(QER);
                nextItem.expr_v.place = ON;
            }
		}

		nextItem.stmt_v.code = SC;
		yysymbol.push(nextItem);
		return !isError;
	case 38: //	unary_expression	| SIZEOF unary_expression				
	case 39: //	unary_expression	| SIZEOF LPAR specifier_qualifier_list RPAR	
	case 40: //	unary_operator	: BIT_AND
		// plpan: here I make a mistake, bit_and is not a unary operator, otherwise it means getting its address or reference
		nextItem.type_spec_v.type = BIT_AND;
		yysymbol.push(nextItem);
		return true;
	case 41: //	unary_operator	| ADD_OP
		nextItem.type_spec_v.type = ADD_OP;
		yysymbol.push(nextItem);
		return true;
	case 42: //	unary_operator	| SUB_OP
		nextItem.type_spec_v.type = SUB_OP;
		yysymbol.push(nextItem);
		return true;
	case 43: //	unary_operator	| BIT_NOT
		nextItem.type_spec_v.type = BIT_NOT;
		yysymbol.push(nextItem);
		return true;
    case 152: //	unary_operator	| DOLLAR
        nextItem.type_spec_v.type = DOLLAR;
        yysymbol.push(nextItem);
        return true;
	case 44: //	postfix_expression	: primary_expression	
		nextItem.expr_v.place = YYV[0].expr_v.place;
		nextItem.stmt_v.code = YYV[0].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 45: //	postfix_expression	| postfix_expression LBRACKET expression RBRACKET		
				// usage of array
		YYV[3].stmt_v.code.AppendTail(YYV[1].stmt_v.code);
		nextItem.stmt_v.code = YYV[3].stmt_v.code;

		id = YYV[3].expr_v.place.Var.VP.VarName;
		if(!(FC_.isBegFunDecl && MST.Lookup(id, FC_.IDENT_NAME, VP)) && !MST.Lookup(id, "", VP)) {
			if(isDebug) {  //输出到控制台
				cout<<"Error Line-"<<yylineno<<":  产生式45错误：数组变量'" << id << "'未定义" << endl;
			} else {  //写入到错误日志
				err_lst<<"Error Line-"<<yylineno<<":  产生式45错误：数组变量'" << id << "'未定义" << endl;
			}

			isError = true;
		}
		if(VP.isArray == false) {
			if(isDebug) {  //输出到控制台
				cout<<"Error Line-"<<yylineno<<":  产生式45错误：变量'" << id << "'不是数组类型" << endl;
			} else {  //写入到错误日志
				err_lst<<"Error Line-"<<yylineno<<":  产生式45错误：变量'" << id << "'不是数组类型" << endl;
			}
			isError = true;
		}
		nextItem.expr_v.place.Var.VP.isArray = true;
		if(YYV[1].expr_v.place.Var.IsImmNum)
			nextItem.expr_v.place.Var.VP.offset = YYV[1].expr_v.place.Var.imm_num;
		else if(!YYV[1].expr_v.place.Var.IsTempVar) {
		//	nextItem.expr_v.place.Var.VP.offset = YYV[1]
		}
		
		yysymbol.push(nextItem);
		return !isError;
	case 46: //	postfix_expression	| postfix_expression LPAR RPAR		
		//无参数函数调用
		if(YYV[2].expr_v.place.isLabel || YYV[2].expr_v.place.Var.IsImmNum || YYV[2].expr_v.place.Var.IsTempVar) {
			if(isDebug) {  //输出到控制台
				cout<<"Error Line-"<<yylineno<<":  产生式46错误：函数调用使用错误！"<<endl;
			} else {  //写入到错误日志
				err_lst<<"Error Line-"<<yylineno<<":  产生式46错误：函数调用使用错误！"<<endl;
			}

			isError = true;
		} else {
			id = YYV[2].expr_v.place.Var.VP.VarName;
		}

		if(!isError) {
			finFT = MST.GetFunction_Table(id);  //寻找函数定义
			if(finFT == NULL) {   //未找到函数定义
				if(isDebug) {  //输出到控制台
					cout<<"Error Line-"<<yylineno<<":  产生式46错误：未找到函数\'"<<id<<"\'定义，请检查函数定义！"<<endl;
				} else {  //写入到错误日志
					err_lst<<"Error Line-"<<yylineno<<":  产生式46错误：未找到函数\'"<<id<<"\'定义，请检查函数定义！"<<endl;
				}
				isError = true;
			} else if(finFT->param_num != 0) {   //参数数量不匹配
				if(isDebug) {  //输出到控制台
					cout<<"Error Line-"<<yylineno<<":  产生式46错误：函数调用参数列表不匹配！"<<endl;
				} else {  //写入到错误日志
					err_lst<<"Error Line-"<<yylineno<<":  产生式46错误：函数调用参数列表不匹配！"<<endl;
				}
				isError = true;
			} else {
				QER.OP = "CALL";
				QER.RS.isLabel = true;
				QER.RS.label = id;
				ON = GenTemp(finFT->return_type);  //根据函数返回值声明存储结果的临时变量
				QER.RD = ON;
				SC.AppendTail(QER);
				nextItem.expr_v.place = ON;   //传递结果
			}
		} 

		nextItem.stmt_v.code = SC;
		yysymbol.push(nextItem);
		return !isError;
	case 47: //	postfix_expression	| postfix_expression LPAR argument_expression_list RPAR	
		SC.AppendTail(YYV[1].stmt_v.code);  //先压入参数列表中涉及到的三地址码

		if(YYV[3].expr_v.place.isLabel || YYV[3].expr_v.place.Var.IsImmNum || YYV[3].expr_v.place.Var.IsTempVar) {
			if(isDebug) {  //输出到控制台
				cout<<"Error Line-"<<yylineno<<":  产生式47错误：函数调用使用错误！"<<endl;
			} else {  //写入到错误日志
				err_lst<<"Error Line-"<<yylineno<<":  产生式47错误：函数调用使用错误！"<<endl;
			}
			isError = true;
		} else {
			id = YYV[3].expr_v.place.Var.VP.VarName;
		}

		if(!isError) {
			finFT = MST.GetFunction_Table(id);  //寻找函数定义
			if(finFT == NULL) {   //未找到函数定义
				if(isDebug) {  //输出到控制台
					cout<<"Error Line-"<<yylineno<<":  产生式47错误：未找到函数\'"<<id<<"\'定义，请检查函数定义！"<<endl;
				} else {  //写入到错误日志
					err_lst<<"Error Line-"<<yylineno<<":  产生式47错误：未找到函数\'"<<id<<"\'定义，请检查函数定义！"<<endl;
				}
				isError = true;
			} else if(finFT->param_num != YYV[1].args_list_v.args_lst.args_place.size()) {   //参数数量不匹配
				if(isDebug) {  //输出到控制台
					cout<<"Error Line-"<<yylineno<<":  产生式47错误：函数调用参数列表不匹配！"<<endl;
				} else {  //写入到错误日志
					err_lst<<"Error Line-"<<yylineno<<":  产生式47错误：函数调用参数列表不匹配！"<<endl;
				}
				isError = true;
			} else {   //比较每个参数的类型
				count_num = finFT->param_VarList.size();
				for(i_count = 0; i_count < count_num; i_count++) {
					expType1 = finFT->param_VarList[i_count].Type;
					ON = YYV[1].args_list_v.args_lst.args_place[i_count];
					if(ON.isLabel) {
						if(isDebug) {  //输出到控制台
							cout<<"Error Line-"<<yylineno<<":  产生式47错误：函数参数列表存在非法变量！"<<endl;
						} else {  //写入到错误日志
							err_lst<<"Error Line-"<<yylineno<<":  产生式47错误：函数参数列表存在非法变量！"<<endl;
						}
						isError = true;
						break;
					} else if (ON.Var.IsImmNum) {
						expType2 = INT;
					}else if (ON.Var.IsTempVar) {
						expType2 = ON.Var.VT.type;
					} else {
						if(	FC_.isBegFunDecl 
							&& MST.Lookup(YYV[1].args_list_v.args_lst.args_place[i_count].Var.VP.VarName, FC_.IDENT_NAME, VP)) {
							expType2 = VP.type;		
						} else if(MST.Lookup(YYV[1].args_list_v.args_lst.args_place[i_count].Var.VP.VarName, "", VP)) {
							expType2 = VP.type;	
						} else {
							if(isDebug) {  //输出到控制台
								cout<<"Error Line-"<<yylineno<<":  产生式47错误：变量\'"<<YYV[1].args_list_v.args_lst.args_place[i_count].Var.VP.VarName<<"\'未找到定义"<<endl;
							} else {  //写入到错误日志
								err_lst<<"Error Line-"<<yylineno<<":  产生式47错误：变量\'"<<YYV[1].args_list_v.args_lst.args_place[i_count].Var.VP.VarName<<"\'未找到定义"<<endl;
							}
							
							isError = true;
							break;
						}
					}
					if( expType1 != expType2 ) {
						if(isDebug) {  //输出到控制台
							cout<<"Error Line-"<<yylineno<<":  产生式47错误：函数调用参数列表有误！第"<<i_count+1<<"个参数类型不匹配"<<endl;
						} else {  //写入到错误日志
							err_lst<<"Error Line-"<<yylineno<<":  产生式47错误：函数调用参数列表有误！第"<<i_count+1<<"个参数类型不匹配"<<endl;
						}
						isError = true;
						break;
					} else {   //压入参数伪三地址代码
						QER.OP = "PARAM";
						QER.RS = YYV[1].args_list_v.args_lst.args_place[i_count];  //实参
						//存在些问题
						SC.AppendTail(QER);
					}
				}
			}

			if(!isError) {   //全部正确可以调用了
				QER.OP = "CALL";
				QER.RS.isLabel = true;
				QER.RS.label = id;
				ON = GenTemp(finFT->return_type);  //根据函数返回值声明存储结果的临时变量
				QER.RD = ON;
				SC.AppendTail(QER);
				nextItem.expr_v.place = ON;   //传递结果
			}
		}

		nextItem.stmt_v.code = SC;
		yysymbol.push(nextItem);
		return true;
	case 48: //	postfix_expression	| postfix_expression INC_OP	
    if(YYV[1].expr_v.place.isLabel || YYV[1].expr_v.place.Var.IsImmNum || YYV[1].expr_v.place.Var.IsTempVar) {
			if(isDebug) {  //输出到控制台
				cout<<"Error Line-"<<yylineno<<":  产生式48错误：表达式必须是一个可以修改的左值" << endl;
			} else {  //写入到错误日志
				err_lst<<"Error Line-"<<yylineno<<":  产生式48错误：表达式必须是一个可以修改的左值" << endl;
			}

			isError = true;
		}
		id = YYV[1].expr_v.place.Var.VP.VarName;
		if(!(FC_.isBegFunDecl && MST.Lookup(id, FC_.IDENT_NAME, VP)) && !MST.Lookup(id, "", VP)) {
			if(isDebug) {  //输出到控制台
				cout<<"Error Line-"<<yylineno<<":  产生式48错误：未定义变量\'"<<id<<"\'"<<endl;
			} else {  //写入到错误日志
				err_lst<<"Error Line-"<<yylineno<<":  产生式48错误：未定义变量\'"<<id<<"\'"<<endl;
			}
			isError = true;
		}
		PE_.isPostfixExp = true;
		PE_.postfix_map.insert(map<string, Operator_NUM>::value_type("INC_OP", YYV[1].expr_v.place));
		nextItem.stmt_v.code = YYV[1].stmt_v.code;
		nextItem.expr_v.place = YYV[1].expr_v.place;
		yysymbol.push(nextItem);
		return !isError;
	case 49: //	postfix_expression	| postfix_expression DEC_OP	
    if(YYV[1].expr_v.place.isLabel || YYV[1].expr_v.place.Var.IsImmNum || YYV[1].expr_v.place.Var.IsTempVar) {
			if(isDebug) {  //输出到控制台
				cout<<"Error Line-"<<yylineno<<":  产生式49错误：表达式必须是一个可以修改的左值" << endl;
			} else {  //写入到错误日志
				err_lst<<"Error Line-"<<yylineno<<":  产生式49错误：表达式必须是一个可以修改的左值" << endl;
			}
			isError = true;
		}
		id = YYV[1].expr_v.place.Var.VP.VarName;
		if(!(FC_.isBegFunDecl && MST.Lookup(id, FC_.IDENT_NAME, VP)) && !MST.Lookup(id, "", VP)) {
			if(isDebug) {  //输出到控制台
				cout<<"Error Line-"<<yylineno<<":  产生式49错误：未定义变量\'"<<id<<"\'"<<endl;
			} else {  //写入到错误日志
				err_lst<<"Error Line-"<<yylineno<<":  产生式49错误：未定义变量\'"<<id<<"\'"<<endl;
			}
			isError = true;
		}
		PE_.isPostfixExp = true;
		PE_.postfix_map.insert(map<string, Operator_NUM>::value_type("DEC_OP", YYV[1].expr_v.place));
		nextItem.stmt_v.code = YYV[1].stmt_v.code;
		nextItem.expr_v.place = YYV[1].expr_v.place;
		yysymbol.push(nextItem);
		return !isError;
	case 50: //	primary_expression	: IDENTIFIER	
		nextItem.expr_v.place.isLabel = false;
		nextItem.expr_v.place.Var.IsImmNum = false;
		nextItem.expr_v.place.Var.IsTempVar = false;
		nextItem.expr_v.place.Var.VP.VarName = YYV[0].IDENT_v.ID_NAME;
		nextItem.expr_v.place.Var.VP.isArray = false;

		if((FC_.isBegFunDecl && MST.Lookup(YYV[0].IDENT_v.ID_NAME, FC_.IDENT_NAME, VP)) || MST.Lookup(YYV[0].IDENT_v.ID_NAME, "", VP)) {
			nextItem.expr_v.place.Var.VP = VP;
		}

		yysymbol.push(nextItem);
		return true;
	case 51: //	primary_expression	| CONSTANT	
		nextItem.expr_v.place.isLabel = false;
		nextItem.expr_v.place.Var.IsImmNum = true;
		nextItem.expr_v.place.Var.imm_num = YYV[0].int_literal_v.int_val;
		yysymbol.push(nextItem);
		return true;
	case 52: //	primary_expression	| LPAR expression RPAR	
		nextItem.stmt_v.code = YYV[1].stmt_v.code;
		nextItem.expr_v.place = YYV[1].expr_v.place;
		yysymbol.push(nextItem);
		return true;
	case 53: //	expression	: assignment_expression		
		nextItem.expr_v = YYV[0].expr_v;
		nextItem.stmt_v.code = YYV[0].stmt_v.code;
		
		// when a expression is ended, checking whether there is any postfix expression need to deal with
		if(PE_.isPostfixExp) {
			map<string, Operator_NUM>::iterator tmp;
			for(tmp = PE_.postfix_map.begin(); tmp != PE_.postfix_map.end(); tmp++) {
				if(tmp->first == "INC_OP") {
					ON = GenTemp(tmp->second.Var.VP.type);
					QER.OP = "ADD";
					QER.RS = tmp->second;
					QER.RT.isLabel = false;
					QER.RT.Var.IsImmNum = true;
					QER.RT.Var.imm_num = 1;
					QER.RD = ON;
					nextItem.stmt_v.code.AppendTail(QER);

					QER.OP = "MOV";
					QER.RS = ON;
					QER.RD = tmp->second;
					nextItem.stmt_v.code.AppendTail(QER);
				} else if(tmp->first == "DEC_OP") {
					ON = GenTemp(tmp->second.Var.VP.type);
					QER.OP = "SUB";
					QER.RS = tmp->second;
					QER.RT.isLabel = false;
					QER.RT.Var.IsImmNum = true;
					QER.RT.Var.imm_num = 1;
					QER.RD = ON;
					nextItem.stmt_v.code.AppendTail(QER);

					QER.OP = "MOV";
					QER.RS = ON;
					QER.RD = tmp->second;
					nextItem.stmt_v.code.AppendTail(QER);
				}
			}
		}
		PE_.reset();

		yysymbol.push(nextItem);
		return true;
	case 54: //	expression	| expression COMMA assignment_expression

	case 55: //	argument_expression_list	: assignment_expression	
		//函数调用参数列表
		SC.AppendTail(YYV[0].stmt_v.code);   //压入右侧表达式的三地址码

		nextItem.args_list_v.args_lst.append_back(YYV[0].expr_v.place);   //将变量的压入参数列表

		nextItem.stmt_v.code = SC;
		yysymbol.push(nextItem);
		return true;
	case 56: //	argument_expression_list	| argument_expression_list COMMA assignment_expression	
		//函数调用参数列表
		SC.AppendTail(YYV[0].stmt_v.code);   //压入右侧两个表达式的三地址码
		SC.AppendTail(YYV[2].stmt_v.code);   //压入右侧两个表达式的三地址码

		YYV[2].args_list_v.args_lst.append_back(YYV[0].expr_v.place);  //压入右侧的参数
		nextItem.args_list_v.args_lst.append_back(YYV[2].args_list_v.args_lst);   //将全部参数压入列表

		nextItem.stmt_v.code = SC;
		yysymbol.push(nextItem);
		return true;
	case 57: //	assignment_expression	: conditional_expression
		nextItem.expr_v.place = YYV[0].expr_v.place;
		nextItem.stmt_v.code = YYV[0].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 58: //	assignment_expression	| unary_expression assignment_operator assignment_expression	
		SC.AppendTail(YYV[2].stmt_v.code);   //压入运算符左侧的三地址码
		SC.AppendTail(YYV[0].stmt_v.code);    //压入运算符右侧的三地址码

		//立即数优化
		if(YYV[0].expr_v.place.Var.IsImmNum && YYV[2].expr_v.place.Var.IsImmNum) {
			ON.isLabel = false;
			ON.Var.IsImmNum = true;

			switch(YYV[1].type_spec_v.type) {  //判断赋值符号类型
				case ASSIGN:   //等于赋值
					ON.Var.imm_num = YYV[0].expr_v.place.Var.IsImmNum;
					break;
				case MUL_ASSIGN:  //‘*=’赋值
					ON.Var.imm_num = (YYV[2].expr_v.place.Var.imm_num * YYV[0].expr_v.place.Var.imm_num);
					break;
				case DIV_ASSIGN:
					ON.Var.imm_num = (YYV[2].expr_v.place.Var.imm_num / YYV[0].expr_v.place.Var.imm_num);
					break;
				case MOD_ASSIGN:
					ON.Var.imm_num = (YYV[2].expr_v.place.Var.imm_num % YYV[0].expr_v.place.Var.imm_num);
					break;
				case ADD_ASSIGN:
					ON.Var.imm_num = (YYV[2].expr_v.place.Var.imm_num + YYV[0].expr_v.place.Var.imm_num);
					break;
				case SUB_ASSIGN:
					ON.Var.imm_num = (YYV[2].expr_v.place.Var.imm_num - YYV[0].expr_v.place.Var.imm_num);
					break;
				case LEFT_ASSIGN:
					ON.Var.imm_num = (YYV[2].expr_v.place.Var.imm_num << YYV[0].expr_v.place.Var.imm_num);
					break;
				case RIGHT_ASSIGN:
					ON.Var.imm_num = (YYV[2].expr_v.place.Var.imm_num >> YYV[0].expr_v.place.Var.imm_num);
					break;
				case AND_ASSIGN:
					ON.Var.imm_num = (YYV[2].expr_v.place.Var.imm_num & YYV[0].expr_v.place.Var.imm_num);
					break;
				case XOR_ASSIGN:
					ON.Var.imm_num = (YYV[2].expr_v.place.Var.imm_num ^ YYV[0].expr_v.place.Var.imm_num);
					break;
				case OR_ASSIGN:
					ON.Var.imm_num = (YYV[2].expr_v.place.Var.imm_num | YYV[0].expr_v.place.Var.imm_num);
					break;
				default:
					break;
				}
            nextItem.expr_v.place = ON;
		} else {
		
			isError = isTwoTypeSame(YYV, expType1, expType2, VP);

			if(!isError && expType1 != expType2) {
				if(isDebug) {  //输出到控制台
					cout<<"Error Line-"<<yylineno<<":  产生式58错误：二元运算符左右两侧类型不同，不可以进行运算！"<<endl;
				} else {  //写入到错误日志
					err_lst<<"Error Line-"<<yylineno<<":  产生式58错误：二元运算符左右两侧类型不同，不可以进行运算！"<<endl;
				}
				isError = true;
			} else if(isError) {
			} else {
 				switch(YYV[1].type_spec_v.type) {  //判断赋值符号类型
				case ASSIGN:   //等于赋值
					QER.RS = YYV[0].expr_v.place;  //赋值的源操作数
					break;
				case MUL_ASSIGN:  //‘*=’赋值
					QER.OP = "MUL";
					break;
				case DIV_ASSIGN:
					QER.OP = "DIV";
					break;
				case MOD_ASSIGN:
					QER.OP = "MOD";
					break;
				case ADD_ASSIGN:
					QER.OP = "ADD";
					break;
				case SUB_ASSIGN:
					QER.OP = "SUB";
					break;
				case LEFT_ASSIGN:
					QER.OP = "SLLV";
					break;
				case RIGHT_ASSIGN:
					QER.OP = "SRLV";
					break;
				case AND_ASSIGN:
					QER.OP = "AND";
					break;
				case XOR_ASSIGN:
					QER.OP = "XOR";
					break;
				case OR_ASSIGN:
					QER.OP = "OR";
					break;
				default:
					break;
				}
				if(ASSIGN != YYV[1].type_spec_v.type) {   //对于‘=’不做此运算
					QER.RS = YYV[2].expr_v.place;
					QER.RT = YYV[0].expr_v.place;
					//移位操作有点特别
					if(LEFT_ASSIGN == YYV[1].type_spec_v.type || RIGHT_ASSIGN == YYV[1].type_spec_v.type) {  
						ON = QER.RS;
						QER.RS = QER.RT;
						QER.RT = ON;
					}
					ON = GenTemp(expType1);  //存储临时运算结果的变量
					QER.RD = ON;
					SC.AppendTail(QER);   //加入四元式
				
					QER.RS = ON;   //赋值的源操作数
				}

                if(DOLLAR != YYV[2].type_spec_v.type) {
                    QER.OP = "MOV";
                    QER.RD.isLabel = false;
                    QER.RD.Var.IsImmNum = false;
                    QER.RD.Var.IsTempVar = false;
                    QER.RD.Var.VP = VP;//YYV[2].expr_v.place;
                    SC.AppendTail(QER);//加入赋值的四元式
                }else{
                    //SC.CODE.pop_back();
                    QER.OP = "SAV";
                    QER.RD = DOLLAR_ON;
                    SC.AppendTail(QER);//加入赋值的四元式
                }
				nextItem.expr_v.place = YYV[2].expr_v.place;
			}
		}
		nextItem.stmt_v.code = SC;
		yysymbol.push(nextItem);
		return !isError;
	case 59: //	conditional_expression	: logical_or_expression	
		nextItem.expr_v.place = YYV[0].expr_v.place;
		nextItem.stmt_v.code = YYV[0].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 60: //	conditional_expression	| logical_or_expression QUESTION expression COLON conditional_expression
		return true;
	case 61: //	logical_or_expression	: logical_and_expression
		nextItem.expr_v.place = YYV[0].expr_v.place;
		nextItem.stmt_v.code = YYV[0].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 62: //	logical_or_expression	| logical_or_expression OR_OP logical_and_expression	
		//此表达式为左右两侧表达式或操作
		SC.AppendTail(YYV[2].stmt_v.code);  //压入左侧表达式的三地址码
		SC.AppendTail(YYV[0].stmt_v.code);  //压入右侧表达式的三地址码

		//立即数优化
		if(YYV[0].expr_v.place.Var.IsImmNum && YYV[2].expr_v.place.Var.IsImmNum) {
			ON.isLabel = false;
			ON.Var.IsImmNum = true;
			ON.Var.imm_num = YYV[2].expr_v.place.Var.imm_num | YYV[0].expr_v.place.Var.imm_num;

			nextItem.expr_v.place = ON;
		} else {
			isError = isTwoTypeSame(YYV, expType1, expType2, VP);

			if(!isError && expType1 != expType2) {
				if(isDebug) {  //输出到控制台
					cout<<"Error Line-"<<yylineno<<":  产生式62错误：二元运算符左右两侧类型不同，不可以进行运算！"<<endl;
				} else {  //写入到错误日志
					err_lst<<"Error Line-"<<yylineno<<":  产生式62错误：二元运算符左右两侧类型不同，不可以进行运算！"<<endl;
				}
				isError = true;
			} else if(isError) {
			} else {
				ON = GenTemp(expType1);   //创立临时变量存储结果

				QER.OP = "OR";
				QER.RS = YYV[2].expr_v.place;
				QER.RT = YYV[0].expr_v.place;
				QER.RD = ON;

				SC.AppendTail(QER);  //插入加法表达式三地址码

				nextItem.expr_v.place = ON;
			}
		}
		nextItem.stmt_v.code = SC;
		yysymbol.push(nextItem);
		return !isError;
	case 63: //	logical_and_expression	: inclusive_or_expression	
		nextItem.expr_v.place = YYV[0].expr_v.place;
		nextItem.stmt_v.code = YYV[0].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 64: //	logical_and_expression	| logical_and_expression AND_OP inclusive_or_expression	
		//此表达式为左右两侧表达式与操作
		SC.AppendTail(YYV[2].stmt_v.code);  //压入左侧表达式的三地址码
		SC.AppendTail(YYV[0].stmt_v.code);  //压入右侧表达式的三地址码

		if(YYV[0].expr_v.place.Var.IsImmNum && YYV[2].expr_v.place.Var.IsImmNum) {
			ON.isLabel = false;
			ON.Var.IsImmNum = true;
			ON.Var.imm_num = YYV[2].expr_v.place.Var.imm_num & YYV[0].expr_v.place.Var.imm_num;

			nextItem.expr_v.place = ON;
		} else {
			isError = isTwoTypeSame(YYV, expType1, expType2, VP);

			if(!isError && expType1 != expType2) {
				if(isDebug) {  //输出到控制台
					cout<<"Error Line-"<<yylineno<<":  产生式64错误：二元运算符左右两侧类型不同，不可以进行运算！"<<endl;
				} else {  //写入到错误日志
					err_lst<<"Error Line-"<<yylineno<<":  产生式64错误：二元运算符左右两侧类型不同，不可以进行运算！"<<endl;
				}
				isError = true;
			} else if(isError) {
			} else {
				ON = GenTemp(expType1);   //创立临时变量存储结果

				QER.OP = "AND";
				QER.RS = YYV[2].expr_v.place;
				QER.RT = YYV[0].expr_v.place;
				QER.RD = ON;

				SC.AppendTail(QER);  //插入加法表达式三地址码
				nextItem.expr_v.place = ON;
			}
		}
		nextItem.stmt_v.code = SC;
		yysymbol.push(nextItem);
		return !isError;
	case 65: //	inclusive_or_expression	: exclusive_or_expression		
		nextItem.expr_v.place = YYV[0].expr_v.place;
		nextItem.stmt_v.code = YYV[0].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 66: //	inclusive_or_expression	| inclusive_or_expression BIT_OR exclusive_or_expression				
	case 67: //	exclusive_or_expression	: and_expression
		nextItem.expr_v.place = YYV[0].expr_v.place;
		nextItem.stmt_v.code = YYV[0].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 68: //	exclusive_or_expression	| exclusive_or_expression BIT_XOR and_expression				
	case 69: //	and_expression	: equality_expression
		nextItem.expr_v.place = YYV[0].expr_v.place;
		nextItem.stmt_v.code = YYV[0].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 70: //	and_expression	| and_expression BIT_AND equality_expression

	case 71: //	equality_expression	: relational_expression	
		nextItem.expr_v.place = YYV[0].expr_v.place;
		nextItem.stmt_v.code = YYV[0].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 72: //	equality_expression	| equality_expression EQ_OP relational_expression	
		//此表达是判断左右表达式是否相等  如果相等则将结果的值设为1
		SC.AppendTail(YYV[2].stmt_v.code);  //先压入符号左侧的表达式的三地址码
		SC.AppendTail(YYV[0].stmt_v.code);  //再压入符号右侧的表达式的三地址码

		if(YYV[0].expr_v.place.Var.IsImmNum && YYV[2].expr_v.place.Var.IsImmNum) {
			ON.isLabel = false;
			ON.Var.IsImmNum = true;
			if(YYV[2].expr_v.place.Var.imm_num == YYV[0].expr_v.place.Var.imm_num) {
				ON.Var.imm_num = 1;
			} else {
				ON.Var.imm_num = 0;
			}

			nextItem.expr_v.place = ON;
		} else {
			isError = isTwoTypeSame(YYV, expType1, expType2, VP);

			if(!isError && expType1 != expType2) {
				if(isDebug) {  //输出到控制台
					cout<<"Error Line-"<<yylineno<<":  产生式72错误：二元运算符左右两侧类型不同，不可以进行运算！"<<endl;
				} else {  //写入到错误日志
					err_lst<<"Error Line-"<<yylineno<<":  产生式72错误：二元运算符左右两侧类型不同，不可以进行运算！"<<endl;
				}
				isError = true;
			} else if(isError) {
		
			} else {
				 //如果无错误则生成三地址码，结果存放于临时变量中
				lentry = Gen_New_Label();  //判断结果为否，所跳转到的标号，将结果赋值为0
				lexit = Gen_New_Label();   //次段三地址码结束的出口

				//判断两侧表达式不相等的跳转
				QER.OP = "BNE";
				QER.RS = YYV[2].expr_v.place;  
				QER.RT = YYV[0].expr_v.place;
				QER.RD.isLabel = true;
				QER.RD.label = lentry;

				SC.AppendTail(QER);  //压入此跳转判断

				//未跳转，则表示两个表达式相等，则将结果置为1，存于临时变量中
				ON = GenTemp(expType1);
				QER.OP = "MOV";
				QER.RS.isLabel = false;
				QER.RS.Var.IsImmNum = true;
				QER.RS.Var.imm_num = 1;
				QER.RD = ON;

				SC.AppendTail(QER);  //压入将判断结果复制为1

				//将结果赋值之后需要跳转
				QER.OP = "GOTO";
				QER.RD.isLabel = true;
				QER.RD.label = lexit;

				SC.AppendTail(QER);  //压入跳出的三地址码

				//判断结果为否后跳转的入口
				QER.OP = "LABEL";
				QER.RS.isLabel = true;
				QER.RS.label = lentry;

				SC.AppendTail(QER);  //压入入口的标号

				//跳转到此处证明条件判断结果为否，需要将结果置为0，存于临时变量中
				QER.OP = "MOV";
				QER.RS.isLabel = false;
				QER.RS.Var.IsImmNum = true;
				QER.RS.Var.imm_num = 0;
				QER.RD = ON;

				SC.AppendTail(QER); //压入结果为否的赋值三地址码

				//整段三地址码结束标号
				QER.OP = "LABEL";
				QER.RS.isLabel = true;
				QER.RS.label = lexit;

				SC.AppendTail(QER); //压入结束标号
				nextItem.expr_v.place = ON;
			}
		}
		nextItem.stmt_v.code = SC;
		yysymbol.push(nextItem);
		return !isError;
	case 73: //	equality_expression	| equality_expression NE_OP relational_expression	
		//此表达是判断左右表达式是否不相等  如果相等则将结果的值设为1
		SC.AppendTail(YYV[2].stmt_v.code);  //先压入符号左侧的表达式的三地址码
		SC.AppendTail(YYV[0].stmt_v.code);  //再压入符号右侧的表达式的三地址码
		
		if(YYV[0].expr_v.place.Var.IsImmNum && YYV[2].expr_v.place.Var.IsImmNum) {
			ON.isLabel = false;
			ON.Var.IsImmNum = true;
			if(YYV[2].expr_v.place.Var.imm_num != YYV[0].expr_v.place.Var.imm_num) {
				ON.Var.imm_num = 1;
			} else {
				ON.Var.imm_num = 0;
			}

			nextItem.expr_v.place = ON;
		} else {
			isError = isTwoTypeSame(YYV, expType1, expType2, VP);

			if(!isError && expType1 != expType2) {
				if(isDebug) {  //输出到控制台
					cout<<"Error Line-"<<yylineno<<":  产生式73错误：二元运算符左右两侧类型不同，不可以进行运算！"<<endl;
				} else {  //写入到错误日志
					err_lst<<"Error Line-"<<yylineno<<":  产生式73错误：二元运算符左右两侧类型不同，不可以进行运算！"<<endl;
				}
				isError = true;
			} else if(isError) {
		
			} else {
				//如果无错误则生成三地址码，结果存放于临时变量中
				lentry = Gen_New_Label();  //判断结果为否，所跳转到的标号，将结果赋值为0
				lexit = Gen_New_Label();   //次段三地址码结束的出口

				//判断两侧表达式不相等的跳转
				QER.OP = "BNE";
				QER.RS = YYV[2].expr_v.place;  
				QER.RT = YYV[0].expr_v.place;
				QER.RD.isLabel = true;
				QER.RD.label = lentry;

				SC.AppendTail(QER);  //压入此跳转判断

				//未跳转，则表示两个表达式相等，则将结果置为0，存于临时变量中
				ON = GenTemp(expType1);
				QER.OP = "MOV";
				QER.RS.isLabel = false;
				QER.RS.Var.IsImmNum = true;
				QER.RS.Var.imm_num = 0;
				QER.RD = ON;

				SC.AppendTail(QER);  //压入将判断结果赋值为0

				//将结果赋值之后需要跳转
				QER.OP = "GOTO";
				QER.RD.isLabel = true;
				QER.RD.label = lexit;

				SC.AppendTail(QER);  //压入跳出的三地址码

				//判断结果为否后跳转的入口
				QER.OP = "LABEL";
				QER.RS.isLabel = true;
				QER.RS.label = lentry;

				SC.AppendTail(QER);  //压入入口的标号

				//跳转到此处证明条件判断结果为否，需要将结果置为1，存于临时变量中
				QER.OP = "MOV";
				QER.RS.isLabel = false;
				QER.RS.Var.IsImmNum = true;
				QER.RS.Var.imm_num = 1;
				QER.RD = ON;

				SC.AppendTail(QER); //压入结果为否的赋值三地址码

				//整段三地址码结束标号
				QER.OP = "LABEL";
				QER.RS.isLabel = true;
				QER.RS.label = lexit;

				SC.AppendTail(QER); //压入结束标号
				nextItem.expr_v.place = ON;
			}
		}
		nextItem.stmt_v.code = SC;
		yysymbol.push(nextItem);
		return !isError;
	case 74: //	relational_expression	: shift_expression		
		nextItem.expr_v.place = YYV[0].expr_v.place;
		nextItem.stmt_v.code = YYV[0].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 75: //	relational_expression	| relational_expression L_OP shift_expression	
		//此表达式判断左侧表达式的值是否小于右侧表达式，如果小于则结果为1，否则为0，结果存于临时变量中
		SC.AppendTail(YYV[2].stmt_v.code);  //先压入符号左侧的表达式的三地址码
		SC.AppendTail(YYV[0].stmt_v.code);  //再压入符号右侧的表达式的三地址码
		
		if(YYV[0].expr_v.place.Var.IsImmNum && YYV[2].expr_v.place.Var.IsImmNum) {
			ON.isLabel = false;
			ON.Var.IsImmNum = true;
			if(YYV[2].expr_v.place.Var.imm_num < YYV[0].expr_v.place.Var.imm_num) {
				ON.Var.imm_num = 1;
			} else {
				ON.Var.imm_num = 0;
			}

			nextItem.expr_v.place = ON;
		} else {
			isError = isTwoTypeSame(YYV, expType1, expType2, VP);
		
			if(!isError && expType1 != expType2) {
				if(isDebug) {  //输出到控制台
					cout<<"Error Line-"<<yylineno<<":  产生式75错误：二元运算符左右两侧类型不同，不可以进行运算！"<<endl;
				} else {  //写入到错误日志
					err_lst<<"Error Line-"<<yylineno<<":  产生式75错误：二元运算符左右两侧类型不同，不可以进行运算！"<<endl;
				}
				isError = true;
			} else if(isError) {
			
			} else {
				ON = GenTemp(expType1);
				QER.OP = "SLT";
				QER.RS = YYV[2].expr_v.place;
				QER.RT = YYV[0].expr_v.place;
				QER.RD = ON;

				SC.AppendTail(QER);
				nextItem.expr_v.place = ON;
			}
		}
		nextItem.stmt_v.code = SC;
		yysymbol.push(nextItem);
		return !isError;
	case 76: //	relational_expression	| relational_expression G_OP shift_expression
		//此表达式判断左侧表达式的值是否大于右侧表达式，如果大于则结果为1，否则为0，结果存于临时变量中
		SC.AppendTail(YYV[2].stmt_v.code);  //先压入符号左侧的表达式的三地址码
		SC.AppendTail(YYV[0].stmt_v.code);  //再压入符号右侧的表达式的三地址码
		
		if(YYV[0].expr_v.place.Var.IsImmNum && YYV[2].expr_v.place.Var.IsImmNum) {
			ON.isLabel = false;
			ON.Var.IsImmNum = true;
			if(YYV[2].expr_v.place.Var.imm_num > YYV[0].expr_v.place.Var.imm_num) {
				ON.Var.imm_num = 1;
			} else {
				ON.Var.imm_num = 0;
			}

			nextItem.expr_v.place = ON;
		} else {
			isError = isTwoTypeSame(YYV, expType1, expType2, VP);
		
			if(!isError && expType1 != expType2) {
				if(isDebug) {  //输出到控制台
					cout<<"Error Line-"<<yylineno<<":  产生式76错误：二元运算符左右两侧类型不同，不可以进行运算！"<<endl;
				} else {  //写入到错误日志
					err_lst<<"Error Line-"<<yylineno<<":  产生式76错误：二元运算符左右两侧类型不同，不可以进行运算！"<<endl;
				}
				isError = true;
			} else if(isError) {
			
			} else {
				ON = GenTemp(expType1);
				QER.OP = "SLT";
				QER.RS = YYV[0].expr_v.place;   //此处交换rs与rt，同样利用SLT指令
				QER.RT = YYV[2].expr_v.place;
				QER.RD = ON;

				SC.AppendTail(QER);
				nextItem.expr_v.place = ON;
			}
		}
		nextItem.stmt_v.code = SC;
		yysymbol.push(nextItem);
		return !isError;
	case 77: //	relational_expression	| relational_expression LE_OP shift_expression	
		//此表达式判断左侧表达式的值是否小于等于右侧表达式，如果小于等于则结果为1，否则为0，结果存于临时变量中
		SC.AppendTail(YYV[2].stmt_v.code);  //先压入符号左侧的表达式的三地址码
		SC.AppendTail(YYV[0].stmt_v.code);  //再压入符号右侧的表达式的三地址码
		
		if(YYV[0].expr_v.place.Var.IsImmNum && YYV[2].expr_v.place.Var.IsImmNum) {
			ON.isLabel = false;
			ON.Var.IsImmNum = true;
			if(YYV[2].expr_v.place.Var.imm_num <= YYV[0].expr_v.place.Var.imm_num) {
				ON.Var.imm_num = 1;
			} else {
				ON.Var.imm_num = 0;
			}

			nextItem.expr_v.place = ON;
		} else {
			isError = isTwoTypeSame(YYV, expType1, expType2, VP);
		
			if(!isError && expType1 != expType2) {
				if(isDebug) {  //输出到控制台
					cout<<"Error Line-"<<yylineno<<":  产生式77错误：二元运算符左右两侧类型不同，不可以进行运算！"<<endl;
				} else {  //写入到错误日志
					err_lst<<"Error Line-"<<yylineno<<":  产生式77错误：二元运算符左右两侧类型不同，不可以进行运算！"<<endl;
				}
				isError = true;
			} else if(isError) {
			
			} else {
				ON = GenTemp(expType1);    //存储结果的临时变量
				lexit = Gen_New_Label();   //新建出口标签

				//判断小于的三地址码
				QER.OP ="SLT";
				QER.RS = YYV[2].expr_v.place;
				QER.RT = YYV[0].expr_v.place;
				QER.RD = ON;
				SC.AppendTail(QER);

				//判断“判断小于”的结果,如果小于直接结束
				QER.OP = "BEQ";
				QER.RS.isLabel = false;
				QER.RS.Var.IsImmNum = true;
				QER.RS.Var.imm_num = 1;
				QER.RT = ON;
				QER.RD.isLabel = true;
				QER.RD.label = lexit;
				SC.AppendTail(QER);

				//如果不小于，判断是否左右两侧相等,如果还不相等，结束判断
				QER.OP = "BNE";
				QER.RS = YYV[2].expr_v.place;
				QER.RT = YYV[0].expr_v.place;
				QER.RD.isLabel = true;
				QER.RD.label = lexit;
				SC.AppendTail(QER);

				//当相等时将结果赋值为1
				QER.OP = "MOV";
				QER.RS.isLabel = false;
				QER.RS.Var.IsImmNum = true;
				QER.RS.Var.imm_num = 1;
				QER.RD = ON;
				SC.AppendTail(QER);

				//压入出口标号
				QER.OP = "LABEL";
				QER.RS.isLabel = true;
				QER.RS.label = lexit;
				SC.AppendTail(QER);

				nextItem.expr_v.place = ON;
			}
		}
		nextItem.stmt_v.code = SC;
		yysymbol.push(nextItem);
		return !isError;
	case 78: //	relational_expression	| relational_expression GE_OP shift_expression	
		//此表达式判断左侧表达式的值是否大于等于右侧表达式，如果大于等于则结果为1，否则为0，结果存于临时变量中
		SC.AppendTail(YYV[2].stmt_v.code);   //压入左侧表达式的三地址码
		SC.AppendTail(YYV[0].stmt_v.code);   //压入右侧表达式的三地址码
		
		if(YYV[0].expr_v.place.Var.IsImmNum && YYV[2].expr_v.place.Var.IsImmNum) {
			ON.isLabel = false;
			ON.Var.IsImmNum = true;
			if(YYV[2].expr_v.place.Var.imm_num >= YYV[0].expr_v.place.Var.imm_num) {
				ON.Var.imm_num = 1;
			} else {
				ON.Var.imm_num = 0;
			}

			nextItem.expr_v.place = ON;
		} else {
			isError = isTwoTypeSame(YYV, expType1, expType2, VP);
		
			if(!isError && expType1 != expType2) {
				if(isDebug) {  //输出到控制台
					cout<<"Error Line-"<<yylineno<<":  产生式78错误：二元运算符左右两侧类型不同，不可以进行运算！"<<endl;
				} else {  //写入到错误日志
					err_lst<<"Error Line-"<<yylineno<<":  产生式78错误：二元运算符左右两侧类型不同，不可以进行运算！"<<endl;
				}
				isError = true;
			} else if(isError) {
			
			} else {
				ON = GenTemp(expType1);    //存储结果的临时变量
				lexit = Gen_New_Label();   //新建出口标签

				//判断大于的三地址码
				QER.OP ="SLT";
				QER.RS = YYV[0].expr_v.place;   //此处手动交换RS与RD用于判断“大于”
				QER.RT = YYV[2].expr_v.place;
				QER.RD = ON;
				SC.AppendTail(QER);

				//判断“判断大于”的结果,如果大于直接结束
				QER.OP = "BEQ";
				QER.RS.isLabel = false;
				QER.RS.Var.IsImmNum = true;
				QER.RS.Var.imm_num = 1;
				QER.RT = ON;
				QER.RD.isLabel = true;
				QER.RD.label = lexit;
				SC.AppendTail(QER);

				//如果不大于，判断是否左右两侧相等,如果还不相等，结束判断
				QER.OP = "BNE";
				QER.RS = YYV[2].expr_v.place;
				QER.RT = YYV[0].expr_v.place;
				QER.RD.isLabel = true;
				QER.RD.label = lexit;
				SC.AppendTail(QER);

				//当相等时将结果赋值为1
				QER.OP = "MOV";
				QER.RS.isLabel = false;
				QER.RS.Var.IsImmNum = true;
				QER.RS.Var.imm_num = 1;
				QER.RD = ON;
				SC.AppendTail(QER);

				//压入出口标号
				QER.OP = "LABEL";
				QER.RS.isLabel = true;
				QER.RS.label = lexit;
				SC.AppendTail(QER);

				nextItem.expr_v.place = ON;
			}
		}
		nextItem.stmt_v.code = SC;
		yysymbol.push(nextItem);
		return !isError;
	case 79: //	shift_expression	: additive_expression	
		nextItem.expr_v.place = YYV[0].expr_v.place;
		nextItem.stmt_v.code = YYV[0].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 80: //	shift_expression	| shift_expression LEFT_OP additive_expression
		//此表达式为向左移位操作，结果存放于临时变量中
		SC.AppendTail(YYV[2].stmt_v.code);  //压入左侧表达式的三地址码
		SC.AppendTail(YYV[0].stmt_v.code);  //压入右侧表达式的三地址码
		
		if(YYV[0].expr_v.place.Var.IsImmNum && YYV[2].expr_v.place.Var.IsImmNum) {
			ON.isLabel = false;
			ON.Var.IsImmNum = true;
			ON.Var.imm_num = (YYV[2].expr_v.place.Var.imm_num << YYV[0].expr_v.place.Var.imm_num);

			nextItem.expr_v.place = ON;
		} else {
			isError = isTwoTypeSame(YYV, expType1, expType2, VP);

			if(!isError && expType1 != expType2) {
				if(isDebug) {  //输出到控制台
					cout<<"Error Line-"<<yylineno<<":  产生式80错误：二元运算符左右两侧类型不同，不可以进行运算！"<<endl;
				} else {  //写入到错误日志
					err_lst<<"Error Line-"<<yylineno<<":  产生式80错误：二元运算符左右两侧类型不同，不可以进行运算！"<<endl;
				}
				isError = true;
			} else if(isError) {
			} else {
				ON = GenTemp(expType1);   //创立临时变量存储结果

				QER.OP = "SLLV";
				QER.RS = YYV[0].expr_v.place;     //此处注意貌似，rs与rd相反
				QER.RT = YYV[2].expr_v.place;
				QER.RD = ON;

				SC.AppendTail(QER);  //插入加法表达式三地址码
				nextItem.expr_v.place = ON;
			}
		}
		nextItem.stmt_v.code = SC;
		yysymbol.push(nextItem);
		return !isError;
	case 81: //	shift_expression	| shift_expression RIGHT_OP additive_expression
		//此表达式为向右移位操作，结果存放于临时变量中   此处为算术右移
		SC.AppendTail(YYV[2].stmt_v.code);  //压入左侧表达式的三地址码
		SC.AppendTail(YYV[0].stmt_v.code);  //压入右侧表达式的三地址码
		
		if(YYV[0].expr_v.place.Var.IsImmNum && YYV[2].expr_v.place.Var.IsImmNum) {
			ON.isLabel = false;
			ON.Var.IsImmNum = true;
			ON.Var.imm_num = (YYV[2].expr_v.place.Var.imm_num >> YYV[0].expr_v.place.Var.imm_num);

			nextItem.expr_v.place = ON;
		} else {
			isError = isTwoTypeSame(YYV, expType1, expType2, VP);

			if(!isError && expType1 != expType2) {
				if(isDebug) {  //输出到控制台
					cout<<"Error Line-"<<yylineno<<":  产生式81错误：二元运算符左右两侧类型不同，不可以进行运算！"<<endl;
				} else {  //写入到错误日志
					err_lst<<"Error Line-"<<yylineno<<":  产生式81错误：二元运算符左右两侧类型不同，不可以进行运算！"<<endl;
				}
				isError = true;
			} else if(isError) {
			} else {
				ON = GenTemp(expType1);   //创立临时变量存储结果

				QER.OP = "SRLV";
				QER.RS = YYV[0].expr_v.place;     //此处注意貌似，rs与rd相反
				QER.RT = YYV[2].expr_v.place;
				QER.RD = ON;

				SC.AppendTail(QER);  //插入加法表达式三地址码
				nextItem.expr_v.place = ON;
			}
		}
		nextItem.stmt_v.code = SC;
		yysymbol.push(nextItem);
		return !isError;
	case 82: //	additive_expression	: multiplicative_expression	
		nextItem.expr_v.place = YYV[0].expr_v.place;
		nextItem.stmt_v.code = YYV[0].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 83: //	additive_expression	| additive_expression ADD_OP multiplicative_expression	
		//此表达式为加法计算，结果存放于临时变量中，目前要求符号两侧变量类型相同
		SC.AppendTail(YYV[2].stmt_v.code);  //压入左侧表达式的三地址码
		SC.AppendTail(YYV[0].stmt_v.code);  //压入右侧表达式的三地址码
		
		if(YYV[0].expr_v.place.Var.IsImmNum && YYV[2].expr_v.place.Var.IsImmNum) {
			ON.isLabel = false;
			ON.Var.IsImmNum = true;
			ON.Var.imm_num = (YYV[2].expr_v.place.Var.imm_num + YYV[0].expr_v.place.Var.imm_num);

			nextItem.expr_v.place = ON;
		} else {
			isError = isTwoTypeSame(YYV, expType1, expType2, VP);

			if(!isError && expType1 != expType2) {
				if(isDebug) {  //输出到控制台
					cout<<"Error Line-"<<yylineno<<":  产生式83错误：二元运算符左右两侧类型不同，不可以进行运算！"<<endl;
				} else {  //写入到错误日志
					err_lst<<"Error Line-"<<yylineno<<":  产生式83错误：二元运算符左右两侧类型不同，不可以进行运算！"<<endl;
				}
				isError = true;
			} else if(isError) {
			} else {
				ON = GenTemp(expType1);   //创立临时变量存储结果

				QER.OP = "ADD";
				QER.RS = YYV[2].expr_v.place;
				QER.RT = YYV[0].expr_v.place;
				QER.RD = ON;

				SC.AppendTail(QER);  //插入加法表达式三地址码
				nextItem.expr_v.place = ON;
			}
		}
		nextItem.stmt_v.code = SC;
		yysymbol.push(nextItem);
		return !isError;
	case 84: //	additive_expression	| additive_expression SUB_OP multiplicative_expression	
		SC.AppendTail(YYV[2].stmt_v.code);  //压入左侧表达式的三地址码
		SC.AppendTail(YYV[0].stmt_v.code);  //压入右侧表达式的三地址码
		
		if(YYV[0].expr_v.place.Var.IsImmNum && YYV[2].expr_v.place.Var.IsImmNum) {
			ON.isLabel = false;
			ON.Var.IsImmNum = true;
			ON.Var.imm_num = (YYV[2].expr_v.place.Var.imm_num - YYV[0].expr_v.place.Var.imm_num);

			nextItem.expr_v.place = ON;
		} else {
			isError = isTwoTypeSame(YYV, expType1, expType2, VP);

			if(!isError && expType1 != expType2) {
				if(isDebug) {  //输出到控制台
					cout<<"Error Line-"<<yylineno<<":  产生式84错误：二元运算符左右两侧类型不同，不可以进行运算！"<<endl;
				} else {  //写入到错误日志
					err_lst<<"Error Line-"<<yylineno<<":  产生式84错误：二元运算符左右两侧类型不同，不可以进行运算！"<<endl;
				}
				isError = true;
			} else if(isError) {
			} else {
				ON = GenTemp(expType1);   //创立临时变量存储结果

				QER.OP = "SUB";
				QER.RS = YYV[2].expr_v.place;
				QER.RT = YYV[0].expr_v.place;
				QER.RD = ON;

				SC.AppendTail(QER);  //插入加法表达式三地址码
				nextItem.expr_v.place = ON;
			}
		}
		nextItem.stmt_v.code = SC;
		yysymbol.push(nextItem);
		return !isError;
	case 85: //	multiplicative_expression	: cast_expression
		nextItem.expr_v.place = YYV[0].expr_v.place;
		nextItem.stmt_v.code = YYV[0].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 86: //	multiplicative_expression	| multiplicative_expression MUL_OP cast_expression	
		//此表达式为乘法运算
		SC.AppendTail(YYV[2].stmt_v.code);  //压入左侧表达式的三地址码
		SC.AppendTail(YYV[0].stmt_v.code);  //压入右侧表达式的三地址码
		
		if(YYV[0].expr_v.place.Var.IsImmNum && YYV[2].expr_v.place.Var.IsImmNum) {
			ON.isLabel = false;
			ON.Var.IsImmNum = true;
			ON.Var.imm_num = (YYV[2].expr_v.place.Var.imm_num * YYV[0].expr_v.place.Var.imm_num);

			nextItem.expr_v.place = ON;
		} else {
			isError = isTwoTypeSame(YYV, expType1, expType2, VP);

			if(!isError && expType1 != expType2) {
				if(isDebug) {  //输出到控制台
					cout<<"Error Line-"<<yylineno<<":  产生式86错误：二元运算符左右两侧类型不同，不可以进行运算！"<<endl;
				} else {  //写入到错误日志
					err_lst<<"Error Line-"<<yylineno<<":  产生式86错误：二元运算符左右两侧类型不同，不可以进行运算！"<<endl;
				}
				isError = true;
			} else if(isError) {
			} else {
				ON = GenTemp(expType1);   //创立临时变量存储结果

				QER.OP = "MUL";
				QER.RS = YYV[2].expr_v.place;
				QER.RT = YYV[0].expr_v.place;
				QER.RD = ON;

				SC.AppendTail(QER);  //插入加法表达式三地址码
				nextItem.expr_v.place = ON;
			}
		}
		nextItem.stmt_v.code = SC;
		yysymbol.push(nextItem);
		return !isError;
	case 87: //	multiplicative_expression	| multiplicative_expression DIV_OP cast_expression
		//此表达式为左右两侧表达式结果进行除法
		SC.AppendTail(YYV[2].stmt_v.code);  //压入左侧表达式的三地址码
		SC.AppendTail(YYV[0].stmt_v.code);  //压入右侧表达式的三地址码
		
		if(YYV[0].expr_v.place.Var.IsImmNum && YYV[2].expr_v.place.Var.IsImmNum) {
			ON.isLabel = false;
			ON.Var.IsImmNum = true;
			ON.Var.imm_num = (YYV[2].expr_v.place.Var.imm_num / YYV[0].expr_v.place.Var.imm_num);

			nextItem.expr_v.place = ON;
		} else {
			isError = isTwoTypeSame(YYV, expType1, expType2, VP);

			if(!isError && expType1 != expType2) {
				if(isDebug) {  //输出到控制台
					cout<<"Error Line-"<<yylineno<<":  产生式87错误：二元运算符左右两侧类型不同，不可以进行运算！"<<endl;
				} else {  //写入到错误日志
					err_lst<<"Error Line-"<<yylineno<<":  产生式87错误：二元运算符左右两侧类型不同，不可以进行运算！"<<endl;
				}
				isError = true;
			} else if(isError) {
			} else {
				ON = GenTemp(expType1);   //创立临时变量存储结果

				QER.OP = "DIV";
				QER.RS = YYV[2].expr_v.place;
				QER.RT = YYV[0].expr_v.place;
				QER.RD = ON;

				SC.AppendTail(QER);  //插入加法表达式三地址码
				nextItem.expr_v.place = ON;
			}
		}
		nextItem.stmt_v.code = SC;
		yysymbol.push(nextItem);
		return !isError;
	case 88: //	multiplicative_expression	| multiplicative_expression MOD_OP cast_expression		
		//此表达式为左右两侧表达式结果进行模运算
		SC.AppendTail(YYV[2].stmt_v.code);  //压入左侧表达式的三地址码
		SC.AppendTail(YYV[0].stmt_v.code);  //压入右侧表达式的三地址码
		
		if(YYV[0].expr_v.place.Var.IsImmNum && YYV[2].expr_v.place.Var.IsImmNum) {
			ON.isLabel = false;
			ON.Var.IsImmNum = true;
			ON.Var.imm_num = (YYV[2].expr_v.place.Var.imm_num % YYV[0].expr_v.place.Var.imm_num);

			nextItem.expr_v.place = ON;
		} else {
			isError = isTwoTypeSame(YYV, expType1, expType2, VP);

			if(!isError && expType1 != expType2) {
				if(isDebug) {  //输出到控制台
					cout<<"Error Line-"<<yylineno<<":  产生式88错误：二元运算符左右两侧类型不同，不可以进行运算！"<<endl;
				} else {  //写入到错误日志
					err_lst<<"Error Line-"<<yylineno<<":  产生式88错误：二元运算符左右两侧类型不同，不可以进行运算！"<<endl;
				}
				isError = true;
			} else if(isError) {
			} else {
				ON = GenTemp(expType1);   //创立临时变量存储结果

				QER.OP = "MOD";
				QER.RS = YYV[2].expr_v.place;
				QER.RT = YYV[0].expr_v.place;
				QER.RD = ON;

				SC.AppendTail(QER);  //插入加法表达式三地址码
				nextItem.expr_v.place = ON;
			}
		}
		nextItem.stmt_v.code = SC;
		yysymbol.push(nextItem);
		return !isError;
	case 89: //	cast_expression	: unary_expression	
		nextItem.expr_v.place = YYV[0].expr_v.place;
		nextItem.stmt_v.code = YYV[0].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 90: //	cast_expression	| LPAR specifier_qualifier_list RPAR cast_expression	

	case 91: //	assignment_operator	: ASSIGN	
		//各种赋值符号存储于stmt_v中的三地址码的op中
		nextItem.type_spec_v.type = ASSIGN;
		yysymbol.push(nextItem);
		return true;
	case 92: //	assignment_operator	| MUL_ASSIGN	
		nextItem.type_spec_v.type = MUL_ASSIGN;
		yysymbol.push(nextItem);
		return true;
	case 93: //	assignment_operator	| DIV_ASSIGN
		nextItem.type_spec_v.type = DIV_ASSIGN;
		yysymbol.push(nextItem);
		return true;
	case 94: //	assignment_operator	| MOD_ASSIGN
		nextItem.type_spec_v.type = MOD_ASSIGN;
		yysymbol.push(nextItem);
		return true;
	case 95: //	assignment_operator	| ADD_ASSIGN
		nextItem.type_spec_v.type = ADD_ASSIGN;
		yysymbol.push(nextItem);
		return true;
	case 96: //	assignment_operator	| SUB_ASSIGN
		nextItem.type_spec_v.type = SUB_ASSIGN;
		yysymbol.push(nextItem);
		return true;
	case 97: //	assignment_operator	| LEFT_ASSIGN
		nextItem.type_spec_v.type = LEFT_ASSIGN;
		yysymbol.push(nextItem);
		return true;
	case 98: //	assignment_operator	| RIGHT_ASSIGN
		nextItem.type_spec_v.type = RIGHT_ASSIGN;
		yysymbol.push(nextItem);
		return true;
	case 99: //	assignment_operator	| AND_ASSIGN
		nextItem.type_spec_v.type = AND_ASSIGN;
		yysymbol.push(nextItem);
		return true;
	case 100://	assignment_operator	| XOR_ASSIGN
		nextItem.type_spec_v.type = XOR_ASSIGN;
		yysymbol.push(nextItem);
		return true;
	case 101://	assignment_operator	| OR_ASSIGN
		nextItem.type_spec_v.type = OR_ASSIGN;
		yysymbol.push(nextItem);
		return true;
	case 102://	specifier_qualifier_list	: type_specifier specifier_qualifier_list	
		YYV[1].stmt_v.code.AppendTail(YYV[0].stmt_v.code);
		nextItem.stmt_v.code = YYV[1].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 103://	specifier_qualifier_list	| type_specifier	
		nextItem.stmt_v.code = YYV[0].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 104://	specifier_qualifier_list	| CONST specifier_qualifier_list	
		YYV[1].stmt_v.code.AppendTail(YYV[0].stmt_v.code);
		nextItem.stmt_v.code = YYV[1].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 105://	specifier_qualifier_list	| CONST	
		yysymbol.push(nextItem);
		return true;
	case 106://	parameter_list	: parameter_declaration	
		//函数参数定义，这是其中一个，需要一个一个压入
		//此处只需要将后面的参数定义压入
		nextItem.param_list_v.param_lst.append_back(YYV[0].param_list_v.param_lst);

		nextItem.stmt_v.code = YYV[0].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 107://	parameter_list	| parameter_list COMMA parameter_declaration
		//此产生式作用同106，也需要将函数参数定义拼接在一起，压入
		YYV[2].param_list_v.param_lst.append_back(YYV[0].param_list_v.param_lst);
		nextItem.param_list_v.param_lst.append_back(YYV[2].param_list_v.param_lst);

		nextItem.stmt_v.code = YYV[0].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 108://	parameter_declaration	: declaration_specifiers declarator	
		//此处应该将变量定义转换为函数的的参数定义之一
		//此处应该新建一个VarList进行插入
		//VarList newParam;
		newParam.ID_Name = YYV[0].expr_v.place.Var.VP.VarName;
		newParam.Type = YYV[1].type_spec_v.type;
		newParam.isArray = false;
		nextItem.param_list_v.param_lst.append_back(newParam);

		nextItem.stmt_v.code = YYV[0].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 109://	parameter_declaration	| declaration_specifiers	
		//此表达是指定义了函数参数的类型，用途同case 108
		//VarList newParam;
		newParam.Type = YYV[1].type_spec_v.type;
		newParam.isArray = false;
		nextItem.param_list_v.param_lst.append_back(newParam);

		nextItem.stmt_v.code = YYV[0].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 110://	identifier_list	: IDENTIFIER	
		//此表达式为函数输入参数，应新建一个Operator_NUM，压入args_参数列表
		//Operator_NUM newArg;
		ON.isLabel = false;
		ON.Var.IsImmNum = false;
		ON.Var.IsTempVar = false;
		ON.Var.VP.VarName = YYV[0].IDENT_v.ID_NAME;
		nextItem.args_list_v.args_lst.append_back(ON);

		nextItem.stmt_v.code = YYV[0].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 111://	identifier_list	| identifier_list COMMA IDENTIFIER	
		//此表达式为拼接传入参数列表，因此传入参数均压入
		YYV[2].args_list_v.args_lst.append_back(YYV[0].args_list_v.args_lst);
		nextItem.args_list_v.args_lst.append_back(YYV[2].args_list_v.args_lst);
		
		//无三地址码需要传递
		yysymbol.push(nextItem);
		return true;
	case 112://	declaration_list	: declaration	

		yysymbol.push(nextItem);
		return true;
	case 113://	declaration_list	| declaration_list declaration	
		YYV[1].stmt_v.code.AppendTail(YYV[0].stmt_v.code);
		nextItem.stmt_v.code = YYV[1].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 114://	declaration	: declaration_specifiers SEMICOLON	
		//目测是个无效的产生式

		nextItem.stmt_v.code = YYV[1].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 115://	declaration	| declaration_specifiers init_declarator_list SEMICOLON	
		//nextItem.type_spec_v = YYV[2].type_spec_v;
		nextItem.expr_v.place = YYV[1].expr_v.place;

		//此处注册新的变量，判断是局部变量还是全局变量，是否重复定义
		count_num =  YYV[1].args_list_v.args_lst.args_place.size();
		//遍历变量定义列表
		for(i_count = 0; i_count < count_num; i_count++) {
			id = YYV[1].args_list_v.args_lst.args_place[i_count].Var.VP.VarName;
			isError = true;
			//查找变量是否在全局中定义，是否在局部中定义，如果均未定义则注册新的
			if(FC_.isBegFunDecl && MST.Lookup(id, FC_.IDENT_NAME, VP)) {  //如果函数中找到，则局部已定义，报错
				if(isDebug) {  //输出到控制台
					cout<<"Error Line-"<<yylineno<<":  产生式115错误：变量： \'"<<id<<"\' 已经在此函数中被定义！"<<endl;
				} else {  //写入到错误日志
					err_lst<<"Error Line-"<<yylineno<<":  产生式115错误：变量： \'"<<id<<"\' 已经在此函数中被定义！"<<endl;
				}
			} else if(MST.Lookup(id, "", VP)) {   //在全局变量中找到
				if(isDebug) {  //输出到控制台
					cout<<"Error Line-"<<yylineno<<":  产生式115错误：变量： \'"<<id<<"\' 已经在全局数据区被定义！"<<endl;
				} else {  //写入到错误日志
					err_lst<<"Error Line-"<<yylineno<<":  产生式115错误：变量： \'"<<id<<"\' 已经在全局数据区被定义！"<<endl;
				}
			} else {  //未找到，则建立新的变量，插入符号表
				//创建新的变量
				if(YYV[1].args_list_v.args_lst.args_place[i_count].Var.VP.isArray) {
					newParam.isArray = true;
					newParam.Array_Len = YYV[1].args_list_v.args_lst.args_place[i_count].Var.VP.Array_Len;
				}
				else
					newParam.isArray = false;
				if(YYV[2].type_spec_v.type == VOID) {
					if(isDebug) {  //输出到控制台
						cout<<"Error Line-"<<yylineno<<":  产生式115错误：变量或者数组类型不能申明为viod类型" << endl;
					} else {  //写入到错误日志
						err_lst<<"Error Line-"<<yylineno<<":  产生式115错误：变量或者数组类型不能申明为viod类型" << endl;
					}
					isError = true;
				}
				newParam.Type = YYV[2].type_spec_v.type;
				newParam.ID_Name = id;

				if(FC_.isBegFunDecl) {  //在函数内部则为局部变量
					newParam.offset = local_offset;
					local_offset += YYV[2].type_spec_v.width;
					MST.insert(newParam, FC_.IDENT_NAME);
					if(isDebug) {  //输出到控制台
						cout<<"注册函数"<<FC_.IDENT_NAME<<" 内局部变量: "<<id<<endl;
					} 
				} else {  //不在，则为全局变量
					newParam.offset = global_offset;
					global_offset += YYV[2].type_spec_v.width;
					MST.insert(newParam, "");
					if(isDebug) {  //输出到控制台
						cout<<"注册全局变量: "<<id<<endl;
					} 
				}
				isError = false;
			}	
		}
		
		YYV[2].stmt_v.code.AppendTail(YYV[1].stmt_v.code);
		nextItem.stmt_v.code = YYV[2].stmt_v.code;
		yysymbol.push(nextItem);
		return !isError;
	case 116://	init_declarator_list	: init_declarator
		//nextItem.expr_v.place = YYV[0].expr_v.place;
		nextItem.stmt_v.code = YYV[0].stmt_v.code;
		//使用args_传递多个变量定义
		nextItem.args_list_v.args_lst.append_back(YYV[0].args_list_v.args_lst);

		yysymbol.push(nextItem);
		return true;
	case 117://	init_declarator_list	| init_declarator_list COMMA init_declarator	
		//多个变量定义拼接，使用args_传递
		YYV[2].args_list_v.args_lst.append_back(YYV[0].args_list_v.args_lst);
		nextItem.args_list_v.args_lst = YYV[2].args_list_v.args_lst;

		YYV[2].stmt_v.code.AppendTail(YYV[0].stmt_v.code);
		nextItem.stmt_v.code = YYV[2].stmt_v.code;

		yysymbol.push(nextItem);
		return true;
	case 118://	init_declarator	: declarator	
		//nextItem.expr_v.place = YYV[0].expr_v.place;
		nextItem.stmt_v.code = YYV[0].stmt_v.code;

		//此处可能是多个变量声明，因此应为一个变量名集合，与上面.place重复，因此不是用.place
		//使用args_传递，不与函数调用穿入参数冲突
		nextItem.args_list_v.args_lst.append_back(YYV[0].expr_v.place);

		yysymbol.push(nextItem);
		return true;
	case 119://	init_declarator	| declarator ASSIGN assignment_expression	
		//次表达式不仅定义了变量还同时进行了初始化赋值操作，应该有赋值操作的三地址码生成。
		//此处可能是多个变量声明，因此应为一个变量名集合，与上面.place重复，因此不是用.place
		//使用args_传递，不与函数调用穿入参数冲突
		nextItem.args_list_v.args_lst.append_back(YYV[0].expr_v.place);

		//此处表达式应该将变量初始化，结果，由于悲催的文法限制，做不了

		nextItem.stmt_v.code = YYV[0].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 120://	compound_statement	: LBRACE RBRACE			
		yysymbol.push(nextItem);
		return true;
	case 121://	compound_statement	| LBRACE block_item_list RBRACE	
		nextItem.expr_v = YYV[1].expr_v;

		//YYV[2].stmt_v.code.AppendTail(YYV[1].stmt_v.code);
		nextItem.stmt_v.code = YYV[1].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 122://	block_item_list	: block_item	
		nextItem.expr_v = YYV[0].expr_v;
		nextItem.stmt_v.code = YYV[0].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 123://	block_item_list	| block_item_list block_item
		YYV[1].stmt_v.code.AppendTail(YYV[0].stmt_v.code);
		nextItem.stmt_v.code = YYV[1].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 124://	block_item	: declaration	
		nextItem.stmt_v.code = YYV[0].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 125://	block_item	| statement	
		nextItem.expr_v = YYV[0].expr_v;
		nextItem.stmt_v.code = YYV[0].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 126://	statement	: labeled_statement	
		nextItem.stmt_v.code = YYV[0].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 127://	statement	| compound_statement	
		nextItem.stmt_v.code = YYV[0].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 128://	statement	| expression_statement
		nextItem.expr_v = YYV[0].expr_v;
		nextItem.stmt_v.code = YYV[0].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 129://	statement	| selection_statement	
		nextItem.stmt_v.code = YYV[0].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 130://	statement	| iteration_statement	
		nextItem.stmt_v.code = YYV[0].stmt_v.code;
		yysymbol.push(nextItem);
		return true;

	case 131 : //	statement	| jump_statement	
		nextItem.stmt_v.code = YYV[0].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 132 : //	labeled_statement	: IDENTIFIER COLON statement	
	case 133 : //	labeled_statement	| CASE constant_expression COLON statement	
	case 134 : //	labeled_statement	| DEFAULT COLON statement	
	case 135 : //	constant_expression	: conditional_expression	
		nextItem.stmt_v.code = YYV[0].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 136 : //	expression_statement	: SEMICOLON	

	case 137 : //	expression_statement	| expression SEMICOLON	
		nextItem.expr_v = YYV[1].expr_v;
		nextItem.stmt_v.code = YYV[1].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 138 : //	selection_statement	: IF LPAR expression RPAR statement	//ELSE
		//此表达式为生成if语句的三地址码，同样没有判断是否进入if的判断
		lexit = Gen_New_Label();   //新的出口标号
		SC.AppendTail(YYV[2].stmt_v.code);  //压入判断条件的三地址码

		if(YYV[2].expr_v.place.isLabel) {
			if(isDebug) {  //输出到控制台
				cout<<"Error Line-"<<yylineno<<":  产生式138错误：不合法表达式！"<<endl;
			} else {  //写入到错误日志
				err_lst<<"Error Line-"<<yylineno<<":  产生式138错误：不合法表达式！"<<endl;
			}

			nextItem.stmt_v.code = SC;
			yysymbol.push(nextItem);
			return false;
		}

		// judge for expression | expression must be a value
		if(!YYV[2].expr_v.place.Var.IsImmNum && !YYV[2].expr_v.place.Var.IsTempVar) {
			id = YYV[2].expr_v.place.Var.VP.VarName;
			if(FC_.isBegFunDecl && !MST.Lookup(id, FC_.IDENT_NAME, VP) && !MST.Lookup(id, "", VP)) {
				if(isDebug) {  //输出到控制台
					cout<<"Error Line-"<<yylineno<<":  产生式138错误：未定义变量\'"<<id<<"\'请检查定义！"<<endl;
				} else {  //写入到错误日志
					err_lst<<"Error Line-"<<yylineno<<":  产生式138错误：未定义变量\'"<<id<<"\'请检查定义！"<<endl;
				}
				isError = true;
			} else if(!FC_.isBegFunDecl && !MST.Lookup(id, "", VP)) {
				if(isDebug) {  //输出到控制台
					cout<<"Error Line-"<<yylineno<<":  产生式138错误：未定义变量\'"<<id<<"\'请检查定义！"<<endl;
				} else {  //写入到错误日志
					err_lst<<"Error Line-"<<yylineno<<":  产生式138错误：未定义变量\'"<<id<<"\'请检查定义！"<<endl;
				}
				isError = true;
			} else {
				isError = false;
			}
		}

		if(!isError) {
			//否定判断跳转的三地址码
			QER.OP = "BEQ";
			QER.RS.isLabel = false;
			QER.RS.Var.IsImmNum = true;
			QER.RS.Var.imm_num = 0;
			QER.RT = YYV[2].expr_v.place;
			QER.RD.isLabel = true;
			QER.RD.label = lexit;

			SC.AppendTail(QER);  //压入否定判断跳转三地址码
			SC.AppendTail(YYV[0].stmt_v.code);  //压入if语句块中的三地址码

			//出口的三地址码
			QER.OP = "LABEL";
			QER.RS.isLabel = true;
			QER.RS.label = lexit;

			SC.AppendTail(QER);  //压入出口的label标记
		}

		nextItem.stmt_v.code = SC;
		yysymbol.push(nextItem);
		return !isError;
	case 139 : //	selection_statement	| IF LPAR expression RPAR statement ELSE statement
		lentry = Gen_New_Label();  //else的入口标号
		lexit = Gen_New_Label();   //新的出口标号

		SC.AppendTail(YYV[4].stmt_v.code);  //压入判断条件的三地址码

		if(YYV[4].expr_v.place.isLabel) {
			if(isDebug) {  //输出到控制台
				cout<<"Error Line-"<<yylineno<<":  产生式139错误：产生式139错误：不合法表达式！"<<endl;
			} else {  //写入到错误日志
				err_lst<<"Error Line-"<<yylineno<<":  产生式139错误：产生式139错误：不合法表达式！"<<endl;
			}

			nextItem.stmt_v.code = SC;
			yysymbol.push(nextItem);
			return false;
		}

		// judge for expression | expression must be a value
		if(!YYV[4].expr_v.place.Var.IsImmNum && !YYV[4].expr_v.place.Var.IsTempVar) {
			id = YYV[4].expr_v.place.Var.VP.VarName;
			if(FC_.isBegFunDecl && !MST.Lookup(id, FC_.IDENT_NAME, VP) && !MST.Lookup(id, "", VP)) {
				if(isDebug) {  //输出到控制台
					cout<<"Error Line-"<<yylineno<<":  产生式139错误：未定义变量\'"<<id<<"\'请检查定义！"<<endl;
				} else {  //写入到错误日志
					err_lst<<"Error Line-"<<yylineno<<":  产生式139错误：未定义变量\'"<<id<<"\'请检查定义！"<<endl;
				}

				isError = true;
			} else if(!FC_.isBegFunDecl && !MST.Lookup(id, "", VP)) {
				if(isDebug) {  //输出到控制台
					cout<<"Error Line-"<<yylineno<<":  产生式139错误：未定义变量\'"<<id<<"\'请检查定义！"<<endl;
				} else {  //写入到错误日志
					err_lst<<"Error Line-"<<yylineno<<":  产生式139错误：未定义变量\'"<<id<<"\'请检查定义！"<<endl;
				}
				isError = true;
			} else {
				isError = false;
			}
		}

		if(!isError) {
			//否定判断跳转的三地址码
			QER.OP = "BEQ";
			QER.RS.isLabel = false;
			QER.RS.Var.IsImmNum = true;
			QER.RS.Var.imm_num = 0;
			QER.RT = YYV[4].expr_v.place;
			QER.RD.isLabel = true;
			QER.RD.label = lentry;  //跳入else

			SC.AppendTail(QER);  //压入否定判断跳转三地址码
			SC.AppendTail(YYV[1].stmt_v.code);  //压入if语句块中的三地址码

			//执行完if块内，跳过else块
			QER.OP = "GOTO";
			QER.RD.isLabel = true;
			QER.RD.label = lexit;

			SC.AppendTail(QER); //压入跳出到else之后的三地址码

			//else的入口标号
			QER.OP = "LABEL";
			QER.RS.isLabel = true;
			QER.RS.label = lentry;

			SC.AppendTail(QER);  //压入else的入口标号
			SC.AppendTail(YYV[0].stmt_v.code);  //压入else的三地址码

			//if..else退出的标号
			QER.OP = "LABEL";
			QER.RS.isLabel = true;
			QER.RS.label = lexit;

			SC.AppendTail(QER);  //压入if..else的出口标号
		}

		nextItem.stmt_v.code = SC;
		yysymbol.push(nextItem);
		return !isError;
	case 140 : //	selection_statement	| SWITCH LPAR expression RPAR statement	
	case 141 : //	iteration_statement	: WHILE LPAR expression RPAR statement	
		//此表达式生成while语句的三地址码  暂时未进行是否进入while判断
		SC.AppendTail(YYV[2].stmt_v.code);  //压入判断条件的三地址码

		if(YYV[2].expr_v.place.isLabel) {
			if(isDebug) {  //输出到控制台
				cout<<"Error Line-"<<yylineno<<":  产生式141错误：不合法表达式！"<<endl;
			} else {  //写入到错误日志
				err_lst<<"Error Line-"<<yylineno<<":  产生式141错误：不合法表达式！"<<endl;
			}
			nextItem.stmt_v.code = SC;
			yysymbol.push(nextItem);
			return false;
		}

		// judge for expression | expression must be a value
		if(!YYV[2].expr_v.place.Var.IsImmNum && !YYV[2].expr_v.place.Var.IsTempVar) {
			id = YYV[2].expr_v.place.Var.VP.VarName;
			if(FC_.isBegFunDecl && !MST.Lookup(id, FC_.IDENT_NAME, VP) && !MST.Lookup(id, "", VP)) {
				if(isDebug) {  //输出到控制台
					cout<<"Error Line-"<<yylineno<<":  产生式141错误：未定义变量\'"<<id<<"\'请检查定义！"<<endl;
				} else {  //写入到错误日志
					err_lst<<"Error Line-"<<yylineno<<":  产生式141错误：未定义变量\'"<<id<<"\'请检查定义！"<<endl;
				}

				isError = true;
			} else if(!FC_.isBegFunDecl && !MST.Lookup(id, "", VP)) {
				if(isDebug) {  //输出到控制台
					cout<<"Error Line-"<<yylineno<<":  产生式141错误：未定义变量\'"<<id<<"\'请检查定义！"<<endl;
				} else {  //写入到错误日志
					err_lst<<"Error Line-"<<yylineno<<":  产生式141错误：未定义变量\'"<<id<<"\'请检查定义！"<<endl;
				}

				isError = true;
			} else {
				isError = false;
			}
		}

		if(!isError) {
			//跳转用， 入口标号三地址码
			QER.OP = "LABEL";
			QER.RS.isLabel = true;
			QER.RS.label = WC_.entry;

			SC.AppendTail(QER);  //压入跳转三地址码
			SC.AppendTail(YYV[2].stmt_v.code);  //压入判断语句的三地址码
		
			//循环条件判断三地址码
			QER.OP = "BEQ";
			QER.RS.isLabel = false;
			QER.RS.Var.IsImmNum = true;
			QER.RS.Var.imm_num = 0;
			QER.RT = YYV[2].expr_v.place;
			QER.RD.isLabel = true;
			QER.RD.label = WC_.exit;

			SC.AppendTail(QER);  //压入否定判断跳转三地址码
			SC.AppendTail(YYV[0].stmt_v.code);  //压入while循环体内的三地址码

			QER.OP = "GOTO";
			QER.RD.isLabel = true;
			QER.RD.label = WC_.entry;

			SC.AppendTail(QER);  //压入跳转回while入口的三地址码

			QER.OP = "LABEL";
			QER.RS.isLabel = true;
			QER.RS.label = WC_.exit;

			SC.AppendTail(QER);  //压入while出口三地址码
		}

		nextItem.stmt_v.code = SC;
		yysymbol.push(nextItem);

		WC_.isInWhileStmt = false;

		return !isError;
	case 142 : //	iteration_statement	| DO statement WHILE LPAR expression RPAR SEMICOLON	
	case 143 : //	iteration_statement	| FOR LPAR expression_statement expression_statement RPAR statement	
	case 144 : //	iteration_statement	| FOR LPAR expression_statement expression_statement expression RPAR statement	
	case 145 : //	iteration_statement	| FOR LPAR declaration expression_statement RPAR statement	
	case 146 : //	iteration_statement	| FOR LPAR declaration expression_statement expression RPAR statement	
	case 147 : //	jump_statement	: GOTO IDENTIFIER SEMICOLON	
	case 148 : //	jump_statement	| CONTINUE SEMICOLON	
		if(WC_.isInWhileStmt) {
			QER.OP = "GOTO";
			QER.RD.isLabel = true;
			QER.RD.label = WC_.entry;
			SC.AppendTail(QER);
		} else {
			if(isDebug) {  //输出到控制台
				cout<<"Error Line-"<<yylineno<<":  产生式148错误：continue不可以使用在while以外的块中！"<<endl;
			} else {  //写入到错误日志
				err_lst<<"Error Line-"<<yylineno<<":  产生式148错误：continue不可以使用在while以外的块中！"<<endl;
			}
			isError = true;
		}
		nextItem.stmt_v.code = SC;
		yysymbol.push(nextItem);
		return !isError;
	case 149 : //	jump_statement	| BREAK SEMICOLON	
		if(WC_.isInWhileStmt) {
			QER.OP = "GOTO";
			QER.RD.isLabel = true;
			QER.RD.label = WC_.exit;
			SC.AppendTail(QER);
		} else {
			if(isDebug) {  //输出到控制台
				cout<<"Error Line-"<<yylineno<<":  产生式149错误：break不可以使用在while以外的块中！"<<endl;
			} else {  //写入到错误日志
				err_lst<<"Error Line-"<<yylineno<<":  产生式149错误：break不可以使用在while以外的块中！"<<endl;
			}

			isError = true;
		}
		nextItem.stmt_v.code = SC;
		yysymbol.push(nextItem);
		return !isError;
	case 150 : //	jump_statement	| RETURN SEMICOLON	
		if(FC_.isBegFunDecl) {
			finFT = MST.GetFunction_Table(FC_.IDENT_NAME);
			if(finFT->return_type != VOID) {
				if(isDebug) {  //输出到控制台
					cout<<"Error Line-"<<yylineno<<":  产生式150错误：函数不可以无返回类型！"<<endl;
				} else {  //写入到错误日志
					err_lst<<"Error Line-"<<yylineno<<":  产生式150错误：函数不可以无返回类型！"<<endl;
				}
				isError = true;
			} else {
				QER.OP = "RETN";
				SC.AppendTail(QER);
			}
		} else {
			if(isDebug) {  //输出到控制台
				cout<<"Error Line-"<<yylineno<<":  产生式150错误：return不可以使用在函数以外！"<<endl;
			} else {  //写入到错误日志
				err_lst<<"Error Line-"<<yylineno<<":  产生式150错误：return不可以使用在函数以外！"<<endl;
			}
			isError = true;
		}
		nextItem.stmt_v.code = SC;
		yysymbol.push(nextItem);
		return !isError;
	case 151 : //	jump_statement	| RETURN expression SEMICOLON	
		SC.AppendTail(YYV[1].stmt_v.code);  //压入return 后的表达式的三地址码

		if(FC_.isBegFunDecl) {
			finFT = MST.GetFunction_Table(FC_.IDENT_NAME);
			if(YYV[1].expr_v.place.isLabel) {
				if(isDebug) {  //输出到控制台
					cout<<"Error Line-"<<yylineno<<":  产生式151错误：函数返回表达式非法！"<<endl;
				} else {  //写入到错误日志
					err_lst<<"Error Line-"<<yylineno<<":  产生式151错误：函数返回表达式非法！"<<endl;
				}
				
				isError = true;
			} else {
				if(YYV[1].expr_v.place.Var.IsImmNum && finFT->return_type != INT) {
					if(isDebug) {  //输出到控制台
						cout<<"Error Line-"<<yylineno<<":  产生式151错误：函数返回类型与定义不符！"<<endl;
					} else {  //写入到错误日志
						err_lst<<"Error Line-"<<yylineno<<":  产生式151错误：函数返回类型与定义不符！"<<endl;
					}
					isError = true;
				} else if(YYV[1].expr_v.place.Var.IsTempVar && finFT->return_type != YYV[1].expr_v.place.Var.VT.type) {
					if(isDebug) {  //输出到控制台
						cout<<"Error Line-"<<yylineno<<":  产生式151错误：函数返回类型与定义不符！"<<endl;
					} else {  //写入到错误日志
						err_lst<<"Error Line-"<<yylineno<<":  产生式151错误：函数返回类型与定义不符！"<<endl;
					}
					isError = true;
				} else if(finFT->return_type != YYV[1].expr_v.place.Var.VP.type) {
					if(isDebug) {  //输出到控制台
						cout<<"Error Line-"<<yylineno<<":  产生式151错误：函数返回类型与定义不符！"<<endl;
					} else {  //写入到错误日志
						err_lst<<"Error Line-"<<yylineno<<":  产生式151错误：函数返回类型与定义不符！"<<endl;
					}
					isError = true;
				} else {
					QER.OP = "RETN";
					QER.RD = YYV[1].expr_v.place;
					SC.AppendTail(QER);
					isError = false;
				}
			}
		} else {
			if(isDebug) {  //输出到控制台
				cout<<"Error Line-"<<yylineno<<":  产生式151错误：return不可以使用在函数以外！"<<endl;
			} else {  //写入到错误日志
				err_lst<<"Error Line-"<<yylineno<<":  产生式151错误：return不可以使用在函数以外！"<<endl;
			}
			isError = true;
		}
		nextItem.stmt_v.code = SC;
		yysymbol.push(nextItem);
		return !isError;
	default:
		break;
	}

	return false;
}

bool isTwoTypeSame(vector<YYTYPE>YYV, int &expType1, int &expType2, VarPlace &VP) {
	bool isError = false;
	string id;

	if(YYV[0].expr_v.place.isLabel || YYV[2].expr_v.place.isLabel) {
		if(isDebug) {  //输出到控制台
			cout<<"Error Line-"<<yylineno<<":  二元运算符两侧出现了非变量！！"<<endl;
		} else {  //写入到错误日志
			err_lst<<"Error Line-"<<yylineno<<":  二元运算符两侧出现了非变量！！"<<endl;
		}
		isError = true;
	}

	//符号右侧表达式最终结果的类型
	if(YYV[0].expr_v.place.Var.IsImmNum) {
		expType1 = INT;
	} else if(YYV[0].expr_v.place.Var.IsTempVar) {
		expType1 = YYV[0].expr_v.place.Var.VT.type;
	} else {
		id = YYV[0].expr_v.place.Var.VP.VarName;
		if(FC_.isBegFunDecl && !MST.Lookup(id, FC_.IDENT_NAME, VP) && !MST.Lookup(id, "", VP)) {
			if(isDebug) {  //输出到控制台
				cout<<"Error Line-"<<yylineno<<":  未定义变量\'"<<id<<"\'请检查定义！"<<endl;
			} else {  //写入到错误日志
				err_lst<<"Error Line-"<<yylineno<<":  未定义变量\'"<<id<<"\'请检查定义！"<<endl;
			}
			isError = true;
		} else if(!FC_.isBegFunDecl && !MST.Lookup(id, "", VP)) {
			if(isDebug) {  //输出到控制台
				cout<<"Error Line-"<<yylineno<<":  未定义变量\'"<<id<<"\'请检查定义！"<<endl;
			} else {  //写入到错误日志
				err_lst<<"Error Line-"<<yylineno<<":  未定义变量\'"<<id<<"\'请检查定义！"<<endl;
			}
			isError = true;
		} else {
			expType1 = VP.type;
		}
	}

	//符号左侧表达式最终结果的类型
	if(YYV[2].expr_v.place.Var.IsImmNum) {
		expType2 = INT;
	} else if(YYV[2].expr_v.place.Var.IsTempVar) {
		expType2 = YYV[2].expr_v.place.Var.VT.type;
	} else {
		id = YYV[2].expr_v.place.Var.VP.VarName;
		if(FC_.isBegFunDecl && !MST.Lookup(id, FC_.IDENT_NAME, VP) && !MST.Lookup(id, "", VP)) {
			if(isDebug) {  //输出到控制台
				cout<<"Error Line-"<<yylineno<<":  未定义变量\'"<<id<<"\'请检查定义！"<<endl;
			} else {  //写入到错误日志
				err_lst<<"Error Line-"<<yylineno<<":  未定义变量\'"<<id<<"\'请检查定义！"<<endl;
			}
			isError = true;
		} else if(!FC_.isBegFunDecl && !MST.Lookup(id, "", VP)) {
			if(isDebug) {  //输出到控制台
				cout<<"Error Line-"<<yylineno<<":  未定义变量\'"<<id<<"\'请检查定义！"<<endl;
			} else {  //写入到错误日志
				err_lst<<"Error Line-"<<yylineno<<":  未定义变量\'"<<id<<"\'请检查定义！"<<endl;
			}
			isError = true;
		} else {
			expType2 = VP.type;
		}
	}

	return isError;
}
#endif // YYACTION_H
