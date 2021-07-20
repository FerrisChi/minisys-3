#ifndef YYACTION_H
#define YYACTION_H
#pragma once
#include "GlobalVar.h"
#include "SEM_GLOBAL_INF.H"
#include "FunctionForest.h"


//�ж϶�Ԫ���������������Ƿ���ͬ��������������ͣ�����Ѿ��д�����false
//���÷��ţ�==  ��=  + -  *  /  %  
bool isTwoTypeSame(vector<YYTYPE>YYV, int &expType1, int &expType2, VarPlace &VP);


//produceID---����ʽID��  reduceDepth---��Լ���---����ʽ����
bool checkAction(int produceID, int reduceDepth) {
	vector<YYTYPE> YYV;
	YYV.clear();
	YYTYPE nextItem;
	
	for(int i = 0; i < reduceDepth; i++) {
		if(yysymbol.empty()){
			cout<<"���崦�����"<<"\r\n";
			return false;
		}

		YYV.push_back(yysymbol.top());
		yysymbol.pop();
	}

	//��������
	SEM_CODE SC;      //�м����
	QUAD_EXP_ROW QER;//������Ԫʽ
    Operator_NUM ON;//������
    static Operator_NUM DOLLAR_ON;//������
	VarPlace VP;    //��������

	string id;     //����
	string lentry;  //��ת��ڱ��
	string lexit;   //��ת���ڱ��

	Function_Table *finFT; //���ڲ��Һ���
	Function_Table newFT;  //ע���º���

	int i_count;  //forѭ���ü�����
	int count_num; //forѭ���ü�������ֵ
	bool isError = false;  //�Ƿ����

	int expType1;  //��¼�����ж������������ֵ������
	int expType2;

	VarList newParam;  //�µĲ�������
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
		/*QER.OP = "LABEL";    //������ڱ�ǩ���Ѿ�����Ҫ
		QER.RS.isLabel = true;
		QER.RS.label = FC_.IDENT_NAME;
		SC.AppendTail(QER);*/
		SC.AppendTail(YYV[0].stmt_v.code);   //ѹ�뺯�����ڵ�����ַ��

		//��亯���ķ�������
		finFT = MST.GetFunction_Table(FC_.IDENT_NAME);

		if(NULL != finFT) {
			//finFT->return_type = YYV[2].type_spec_v.type;
			//MST.update(FC_.IDENT_NAME, "return_type", YYV[2].type_spec_v.type);
			MST.update(FC_.IDENT_NAME, "top", local_offset);
		} else {
			if(isDebug) {  //���������̨
				cout<<"Error Line-"<<yylineno<<":  ����ʽ7�����޷��ҵ���Ҫ��䷵�����͵ĺ�����"<<endl;
			} else {  //д�뵽������־
				err_lst<<"Error Line-"<<yylineno<<":  ����ʽ7�����޷��ҵ���Ҫ��䷵�����͵ĺ�����"<<endl;
			}
		}

		//��������
		FC_.isBegFunDecl = false;

		//��������ɭ��
		fst.Fun_Name = FC_.IDENT_NAME;
		fst.SC=YYV[0].stmt_v.code;
		
		Fun_Sem_Forest.push_back(fst);//����ɭ��

		//���ɺ��������ı��
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
			if(isDebug) {  //���������̨
				cout<<"Error Line-"<<yylineno<<":  ����ʽ11��������'" << YYV[1].type_spec_v.type << "'��������" << endl;
			} else {  //д�뵽������־
				err_lst<<"Error Line-"<<yylineno<<":  ����ʽ11��������'" << YYV[1].type_spec_v.type << "'��������" << endl;
			}
			isError = true;
		}
		if(YYV[0].type_spec_v.type == VOID || YYV[0].type_spec_v.type == BOOL) {
			if(isDebug) {  //���������̨
				cout<<"Error Line-"<<yylineno<<":  ����ʽ11��������'" << YYV[0].type_spec_v.type << "'��������" << endl;
			} else {  //д�뵽������־
				err_lst<<"Error Line-"<<yylineno<<":  ����ʽ11��������'" << YYV[0].type_spec_v.type << "'��������" << endl;
			}
			isError = true;
		}
		//YYV[1].stmt_v.code.AppendTail(YYV[0].stmt_v.code);

		if(!isError) {
			typeStack.pop();   //��int,char,short�Ȼ�Ϊunsigned int

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
	case 12: //  declaration_specifiers	| CONST	--������ַ��
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
		//ͳһ����place��
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
				if(isDebug) {  //���������̨
					cout<<"Error Line-"<<yylineno<<":  ����ʽ27���󣺱���'" << id << "'�ض���" << endl;
				} else {  //д�뵽������־
					err_lst<<"Error Line-"<<yylineno<<":  ����ʽ27���󣺱���'" << id << "'�ض���" << endl;
				}
				isError = true;
			}
		} else {
			// global array
			if(MST.Lookup(id, "", VP)) {
				if(isDebug) {  //���������̨
					cout<<"Error Line-"<<yylineno<<":  ����ʽ27���󣺱���'" << id << "'�ض���" << endl;
				} else {  //д�뵽������־
					err_lst<<"Error Line-"<<yylineno<<":  ����ʽ27���󣺱���'" << id << "'�ض���" << endl;
				}
				isError = true;
			}
		}

		if(id.length() == 0) {
			if(isDebug) {  //���������̨
				cout<<"Error Line-"<<yylineno<<":  ����ʽ27���󣺱������ڲ�����" << endl;
			} else {  //д�뵽������־
				err_lst<<"Error Line-"<<yylineno<<":  ����ʽ27���󣺱������ڲ�����" << endl;
			}
			isError = true;
		}
		if(!YYV[1].expr_v.place.Var.imm_num) {
			if(isDebug) {  //���������̨
				cout<<"Error Line-"<<yylineno<<":  ����ʽ27�������鳤��ֻ��˵����������" << endl;
			} else {  //д�뵽������־
				err_lst<<"Error Line-"<<yylineno<<":  ����ʽ27�������鳤��ֻ��˵����������" << endl;
			}
			isError = true;
		}
		if(YYV[1].expr_v.place.Var.imm_num <= 0) {
			if(isDebug) {  //���������̨
				cout<<"Error Line-"<<yylineno<<":  ����ʽ27�������鳤�ȱ����Ǵ���0����" << endl;
			} else {  //д�뵽������־
				err_lst<<"Error Line-"<<yylineno<<":  ����ʽ27�������鳤�ȱ����Ǵ���0����" << endl;
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
		//���Ϊ���뺯���壬���ı�ǣ�ע�ắ��
		isError = false;
		if(!FC_.isBegFunDecl) {
			FC_.isBegFunDecl = true;
			FC_.IDENT_NAME = YYV[3].expr_v.place.Var.VP.VarName;
		} else {
			if(isDebug) {  //���������̨
				cout<<"Error Line-"<<yylineno<<":  ����ʽ31���󣺺����ڲ������Զ��庯����"<<endl;
			} else {  //д�뵽������־
				err_lst<<"Error Line-"<<yylineno<<":  ����ʽ31���󣺺����ڲ������Զ��庯����"<<endl;
			}
			isError = true;
		}

		if(!isError) {
			//�����Ƿ�����ͬ���������壬�˴�Ŀǰֻ���Ǻ���������û�п��Ǻ���ǩ��
			finFT = MST.GetFunction_Table(FC_.IDENT_NAME); 

			if(finFT != NULL) {  //�Ѵ��ڸú�������Ҫ����
				if(isDebug) {  //���������̨
					cout<<"Error Line-"<<yylineno<<":  ����ʽ31���󣺺�������: \'"<<FC_.IDENT_NAME<<"\' �Ѿ�������"<<endl;
				} else {  //д�뵽������־
					err_lst<<"Error Line-"<<yylineno<<":  ����ʽ31���󣺺�������: \'"<<FC_.IDENT_NAME<<"\' �Ѿ�������"<<endl;
				}

				FC_.isBegFunDecl = false;   // ��ǳ�������
				isError = true;

			} 
			
			if(!isError) { //���������ڣ�ע�ắ��
				newFT.Fun_Name = FC_.IDENT_NAME;   //������
				//�˴��޷���亯����������
				newFT.param_VarList = YYV[1].param_list_v.param_lst.params_list;  // �����б�
				newFT.param_num = YYV[1].param_list_v.param_lst.params_list.size();  //��������
				newFT.top = local_offset;

				count_num = YYV[1].param_list_v.param_lst.params_list.size();
				//��ջ��ȡ�������Ͷ���
				for(i_count = 0; i_count < count_num; i_count++) {
					typeStack.pop();
				}

				newFT.return_type = typeStack.top();   //������������
				MST.insert_function(newFT);  // ���뵽���ű�������
				
				if(isDebug){
					cout<<"ע�ắ���� "<<newFT.Fun_Name<<endl;
				}
				
				//ע�ắ�������б�ѹ�뵽�����ľֲ����ű���
				for(i_count = 0; i_count < count_num; i_count++) {
					newParam = YYV[1].param_list_v.param_lst.params_list[i_count];
					newParam.offset = local_offset;
					local_offset += GetTypeWidth(newParam.Type);
					MST.insert(newParam, newFT.Fun_Name);
					
					if(isDebug){
						cout<<"ע�ắ��\'"<<newFT.Fun_Name<<"\' ����: "<<newParam.ID_Name<<endl;
					}
				}

			}

		}

		//���ջ
		while(!typeStack.empty()) {
			typeStack.pop();
		}

		//ѹ����������
		nextItem.param_list_v.param_lst = YYV[1].param_list_v.param_lst;
		nextItem.IDENT_v.ID_NAME = FC_.IDENT_NAME; // �о�Ҳ����Ҫ

		nextItem.fun_decl_v.fun_name = YYV[3].expr_v.place.Var.VP.VarName;
		nextItem.fun_decl_v.code = YYV[1].stmt_v.code;

		//��ȷ�������ò���Ҫ��ֵplace
		nextItem.expr_v.place = YYV[3].expr_v.place;

		YYV[2].stmt_v.code.AppendTail(YYV[1].stmt_v.code);
		YYV[3].stmt_v.code.AppendTail(YYV[2].stmt_v.code);
		nextItem.stmt_v.code = YYV[3].stmt_v.code;
		
		yysymbol.push(nextItem);
		return !isError;
	case 32: //	direct_declarator	| direct_declarator LPAR identifier_list RPAR
		//���Ϊ���뺯���壬 �������⣬�˴�ӦΪ�������ú��治���ǽ��뺯����
		//FC_.isBegFunDecl = true;
		//FC_.IDENT_NAME = YYV[3].expr_v.place.Var.VP.VarName;

		//ѹ�봫�ݲ����б�
		nextItem.args_list_v.args_lst = YYV[1].args_list_v.args_lst;
		nextItem.IDENT_v.ID_NAME = FC_.IDENT_NAME;

		nextItem.fun_decl_v.fun_name = YYV[3].expr_v.place.Var.VP.VarName;
		nextItem.fun_decl_v.code = YYV[1].stmt_v.code;

		//��ȷ�������ò���Ҫ��ֵplace
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
			if(isDebug) {  //���������̨
				cout<<"Error Line-"<<yylineno<<":  ����ʽ33���󣺺����ڲ������Զ��庯����"<<endl;
			} else {  //д�뵽������־
				err_lst<<"Error Line-"<<yylineno<<":  ����ʽ33���󣺺����ڲ������Զ��庯����"<<endl;
			}
			isError = true;
		}
		
		if(!isError) {
			//�����Ƿ�����ͬ���������壬�˴�Ŀǰֻ���Ǻ���������û�п��Ǻ���ǩ��
			finFT = MST.GetFunction_Table(FC_.IDENT_NAME); 

			if(finFT != NULL) {  //�Ѵ��ڸú�������Ҫ����
				if(isDebug) {  //���������̨
					cout<<"Error Line-"<<yylineno<<":  ����ʽ33���󣺺�������: \'"<<FC_.IDENT_NAME<<"\' �Ѿ�������"<<endl;
				} else {  //д�뵽������־
					err_lst<<"Error Line-"<<yylineno<<":  ����ʽ33���󣺺�������: \'"<<FC_.IDENT_NAME<<"\' �Ѿ�������"<<endl;
				}

				FC_.isBegFunDecl = false;   //��ǳ�������
				isError = true;
			} 
			if(!isError) {    //δ�ظ����壬ע�ắ��
				newFT.Fun_Name = FC_.IDENT_NAME;   //������
				//�˴��޷���亯����������
				//�޲����б�
				newFT.param_num = 0;  //��������
				newFT.top = local_offset;
				newFT.return_type = typeStack.top();   //������������
				MST.insert_function(newFT);  // ���뵽���ű�������
				//FC_.exitLabel = Gen_New_Label();   //���ɺ���������
				if(isDebug) {
					cout<<"ע�ắ���� "<<newFT.Fun_Name<<endl;
				}
			}
		}

		//���ջ
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
			if(isDebug) {  //���������̨
				cout<<"Error Line-"<<yylineno<<":  ����ʽ35���󣺱��ʽ������һ�������޸ĵ���ֵ" << endl;
			} else {  //д�뵽������־
				err_lst<<"Error Line-"<<yylineno<<":  ����ʽ35���󣺱��ʽ������һ�������޸ĵ���ֵ" << endl;
			}
			
			isError = true;
		}
		id = YYV[0].expr_v.place.Var.VP.VarName;
		if(id == "") {
			if(isDebug) {  //���������̨
				cout<<"Error Line-"<<yylineno<<":  ����ʽ35��������ʲô������" << endl;
			} else {  //д�뵽������־
				err_lst<<"Error Line-"<<yylineno<<":  ����ʽ35��������ʲô������" << endl;
			}
		} else if(!(FC_.isBegFunDecl && MST.Lookup(id, FC_.IDENT_NAME, VP)) || !MST.Lookup(id, "", VP)) {
			if(isDebug) {  //���������̨
				cout<<"Error Line-"<<yylineno<<":  ����ʽ35����δ�������\'"<<id<<"\'"<<endl;
			} else {  //д�뵽������־
				err_lst<<"Error Line-"<<yylineno<<":  ����ʽ35����δ�������\'"<<id<<"\'"<<endl;
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
			if(isDebug) {  //���������̨
				cout<<"Error Line-"<<yylineno<<":  ����ʽ36���󣺱��ʽ������һ�������޸ĵ���ֵ" << endl;
			} else {  //д�뵽������־
				err_lst<<"Error Line-"<<yylineno<<":  ����ʽ36���󣺱��ʽ������һ�������޸ĵ���ֵ" << endl;
			}
			isError = true;
		}
		id = YYV[0].expr_v.place.Var.VP.VarName;
		if(id == "") {
			if(isDebug) {  //���������̨
				cout<<"Error Line-"<<yylineno<<":  ����ʽ36��������ʲô������" << endl;
			} else {  //д�뵽������־
				err_lst<<"Error Line-"<<yylineno<<":  ����ʽ36��������ʲô������" << endl;
			}
		} else if(!(FC_.isBegFunDecl && MST.Lookup(id, FC_.IDENT_NAME, VP)) && !MST.Lookup(id, "", VP)) {
			if(isDebug) {  //���������̨
				cout<<"Error Line-"<<yylineno<<":  ����ʽ36����δ�������\'"<<id<<"\'"<<endl;
			} else {  //д�뵽������־
				err_lst<<"Error Line-"<<yylineno<<":  ����ʽ36����δ�������\'"<<id<<"\'"<<endl;
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
		SC.AppendTail(YYV[0].stmt_v.code); //��ѹ������Ҳ���ʽ������ַ��
		
		if(YYV[0].expr_v.place.isLabel) {
			if(isDebug) {  //���������̨
				cout<<"Error Line-"<<yylineno<<":  ����ʽ37����������Ҳ���ַǷ�������"<<endl;
			} else {  //д�뵽������־
				err_lst<<"Error Line-"<<yylineno<<":  ����ʽ37����������Ҳ���ַǷ�������"<<endl;
			}

			isError = true;
		}

		//�жϲ���������
		if(!isError) {
			//�������Ż�
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
					if(isDebug) {  //���������̨
						cout<<"Error Line-"<<yylineno<<":  ����ʽ37����δ�������\'"<<id<<"\'���鶨�壡"<<endl;
					} else {  //д�뵽������־
						err_lst<<"Error Line-"<<yylineno<<":  ����ʽ37����δ�������\'"<<id<<"\'���鶨�壡"<<endl;
					}
					isError = true;
				} else if(!FC_.isBegFunDecl && !MST.Lookup(id, "", VP)) {
					if(isDebug) {  //���������̨
						cout<<"Error Line-"<<yylineno<<":  ����ʽ37����δ�������\'"<<id<<"\'���鶨�壡"<<endl;
					} else {  //д�뵽������־
						err_lst<<"Error Line-"<<yylineno<<":  ����ʽ37����δ�������\'"<<id<<"\'���鶨�壡"<<endl;
					}
					isError = true;
				} else {
					expType1 = VP.type;
				}
			}	

			if(expType1 != INT && expType1 != LONG && expType1 != SHORT) {
				if(isDebug) {  //���������̨
					cout<<"Error Line-"<<yylineno<<":  ����ʽ37����������Ҳ���������Ͳ��Ϸ�"<<endl;
				} else {  //д�뵽������־
					err_lst<<"Error Line-"<<yylineno<<":  ����ʽ37����������Ҳ���������Ͳ��Ϸ�"<<endl;
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
				lentry = Gen_New_Label();  //����ʱ������ֵ����ڱ��
				lexit = Gen_New_Label();   //�뿪�˶εı��
				ON = GenTemp(expType1);

				//����Ƿ����0��������ת�Ҹ�ֵΪ1�������ڼ����Ҹ�ֵΪ0
				QER.OP = "BEQ";
				QER.RS.isLabel = false;
				QER.RS.Var.IsImmNum = true;
				QER.RS.Var.imm_num = 0;
				QER.RT = YYV[0].expr_v.place;
				QER.RD.isLabel = true;
				QER.RD.label = lentry;
				SC.AppendTail(QER);

				//����ʱ���������ֵΪ0
				QER.OP = "MOV";
				QER.RS.isLabel = false;
				QER.RS.Var.IsImmNum = true;
				QER.RS.Var.imm_num = 0;
				QER.RD = ON;
				SC.AppendTail(QER); //MOV 1,ON

				//��ת���˶ν���
				QER.OP = "GOTO";
				QER.RD.isLabel = true;
				QER.RD.label = lexit;
				SC.AppendTail(QER); //goto exit

				//��ֵ��ڱ��
				QER.OP="LABEL";
				QER.RS.isLabel = true;
				QER.RS.label = lentry;
				SC.AppendTail(QER);  

				//����ʱ���������ֵΪ1
				QER.OP = "MOV";
				QER.RS.isLabel = false;
				QER.RS.Var.IsImmNum = true;
				QER.RS.Var.imm_num = 1;
				QER.RD = ON;
				SC.AppendTail(QER); //MOV 1,ON

				//�˶ν���
				QER.OP="LABEL";
				QER.RS.isLabel = true;
				QER.RS.label = lexit;
                SC.AppendTail(QER);

				nextItem.expr_v.place = ON;  //�������
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
			if(isDebug) {  //���������̨
				cout<<"Error Line-"<<yylineno<<":  ����ʽ45�����������'" << id << "'δ����" << endl;
			} else {  //д�뵽������־
				err_lst<<"Error Line-"<<yylineno<<":  ����ʽ45�����������'" << id << "'δ����" << endl;
			}

			isError = true;
		}
		if(VP.isArray == false) {
			if(isDebug) {  //���������̨
				cout<<"Error Line-"<<yylineno<<":  ����ʽ45���󣺱���'" << id << "'������������" << endl;
			} else {  //д�뵽������־
				err_lst<<"Error Line-"<<yylineno<<":  ����ʽ45���󣺱���'" << id << "'������������" << endl;
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
		//�޲�����������
		if(YYV[2].expr_v.place.isLabel || YYV[2].expr_v.place.Var.IsImmNum || YYV[2].expr_v.place.Var.IsTempVar) {
			if(isDebug) {  //���������̨
				cout<<"Error Line-"<<yylineno<<":  ����ʽ46���󣺺�������ʹ�ô���"<<endl;
			} else {  //д�뵽������־
				err_lst<<"Error Line-"<<yylineno<<":  ����ʽ46���󣺺�������ʹ�ô���"<<endl;
			}

			isError = true;
		} else {
			id = YYV[2].expr_v.place.Var.VP.VarName;
		}

		if(!isError) {
			finFT = MST.GetFunction_Table(id);  //Ѱ�Һ�������
			if(finFT == NULL) {   //δ�ҵ���������
				if(isDebug) {  //���������̨
					cout<<"Error Line-"<<yylineno<<":  ����ʽ46����δ�ҵ�����\'"<<id<<"\'���壬���麯�����壡"<<endl;
				} else {  //д�뵽������־
					err_lst<<"Error Line-"<<yylineno<<":  ����ʽ46����δ�ҵ�����\'"<<id<<"\'���壬���麯�����壡"<<endl;
				}
				isError = true;
			} else if(finFT->param_num != 0) {   //����������ƥ��
				if(isDebug) {  //���������̨
					cout<<"Error Line-"<<yylineno<<":  ����ʽ46���󣺺������ò����б�ƥ�䣡"<<endl;
				} else {  //д�뵽������־
					err_lst<<"Error Line-"<<yylineno<<":  ����ʽ46���󣺺������ò����б�ƥ�䣡"<<endl;
				}
				isError = true;
			} else {
				QER.OP = "CALL";
				QER.RS.isLabel = true;
				QER.RS.label = id;
				ON = GenTemp(finFT->return_type);  //���ݺ�������ֵ�����洢�������ʱ����
				QER.RD = ON;
				SC.AppendTail(QER);
				nextItem.expr_v.place = ON;   //���ݽ��
			}
		} 

		nextItem.stmt_v.code = SC;
		yysymbol.push(nextItem);
		return !isError;
	case 47: //	postfix_expression	| postfix_expression LPAR argument_expression_list RPAR	
		SC.AppendTail(YYV[1].stmt_v.code);  //��ѹ������б����漰��������ַ��

		if(YYV[3].expr_v.place.isLabel || YYV[3].expr_v.place.Var.IsImmNum || YYV[3].expr_v.place.Var.IsTempVar) {
			if(isDebug) {  //���������̨
				cout<<"Error Line-"<<yylineno<<":  ����ʽ47���󣺺�������ʹ�ô���"<<endl;
			} else {  //д�뵽������־
				err_lst<<"Error Line-"<<yylineno<<":  ����ʽ47���󣺺�������ʹ�ô���"<<endl;
			}
			isError = true;
		} else {
			id = YYV[3].expr_v.place.Var.VP.VarName;
		}

		if(!isError) {
			finFT = MST.GetFunction_Table(id);  //Ѱ�Һ�������
			if(finFT == NULL) {   //δ�ҵ���������
				if(isDebug) {  //���������̨
					cout<<"Error Line-"<<yylineno<<":  ����ʽ47����δ�ҵ�����\'"<<id<<"\'���壬���麯�����壡"<<endl;
				} else {  //д�뵽������־
					err_lst<<"Error Line-"<<yylineno<<":  ����ʽ47����δ�ҵ�����\'"<<id<<"\'���壬���麯�����壡"<<endl;
				}
				isError = true;
			} else if(finFT->param_num != YYV[1].args_list_v.args_lst.args_place.size()) {   //����������ƥ��
				if(isDebug) {  //���������̨
					cout<<"Error Line-"<<yylineno<<":  ����ʽ47���󣺺������ò����б�ƥ�䣡"<<endl;
				} else {  //д�뵽������־
					err_lst<<"Error Line-"<<yylineno<<":  ����ʽ47���󣺺������ò����б�ƥ�䣡"<<endl;
				}
				isError = true;
			} else {   //�Ƚ�ÿ������������
				count_num = finFT->param_VarList.size();
				for(i_count = 0; i_count < count_num; i_count++) {
					expType1 = finFT->param_VarList[i_count].Type;
					ON = YYV[1].args_list_v.args_lst.args_place[i_count];
					if(ON.isLabel) {
						if(isDebug) {  //���������̨
							cout<<"Error Line-"<<yylineno<<":  ����ʽ47���󣺺��������б���ڷǷ�������"<<endl;
						} else {  //д�뵽������־
							err_lst<<"Error Line-"<<yylineno<<":  ����ʽ47���󣺺��������б���ڷǷ�������"<<endl;
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
							if(isDebug) {  //���������̨
								cout<<"Error Line-"<<yylineno<<":  ����ʽ47���󣺱���\'"<<YYV[1].args_list_v.args_lst.args_place[i_count].Var.VP.VarName<<"\'δ�ҵ�����"<<endl;
							} else {  //д�뵽������־
								err_lst<<"Error Line-"<<yylineno<<":  ����ʽ47���󣺱���\'"<<YYV[1].args_list_v.args_lst.args_place[i_count].Var.VP.VarName<<"\'δ�ҵ�����"<<endl;
							}
							
							isError = true;
							break;
						}
					}
					if( expType1 != expType2 ) {
						if(isDebug) {  //���������̨
							cout<<"Error Line-"<<yylineno<<":  ����ʽ47���󣺺������ò����б����󣡵�"<<i_count+1<<"���������Ͳ�ƥ��"<<endl;
						} else {  //д�뵽������־
							err_lst<<"Error Line-"<<yylineno<<":  ����ʽ47���󣺺������ò����б����󣡵�"<<i_count+1<<"���������Ͳ�ƥ��"<<endl;
						}
						isError = true;
						break;
					} else {   //ѹ�����α����ַ����
						QER.OP = "PARAM";
						QER.RS = YYV[1].args_list_v.args_lst.args_place[i_count];  //ʵ��
						//����Щ����
						SC.AppendTail(QER);
					}
				}
			}

			if(!isError) {   //ȫ����ȷ���Ե�����
				QER.OP = "CALL";
				QER.RS.isLabel = true;
				QER.RS.label = id;
				ON = GenTemp(finFT->return_type);  //���ݺ�������ֵ�����洢�������ʱ����
				QER.RD = ON;
				SC.AppendTail(QER);
				nextItem.expr_v.place = ON;   //���ݽ��
			}
		}

		nextItem.stmt_v.code = SC;
		yysymbol.push(nextItem);
		return true;
	case 48: //	postfix_expression	| postfix_expression INC_OP	
    if(YYV[1].expr_v.place.isLabel || YYV[1].expr_v.place.Var.IsImmNum || YYV[1].expr_v.place.Var.IsTempVar) {
			if(isDebug) {  //���������̨
				cout<<"Error Line-"<<yylineno<<":  ����ʽ48���󣺱��ʽ������һ�������޸ĵ���ֵ" << endl;
			} else {  //д�뵽������־
				err_lst<<"Error Line-"<<yylineno<<":  ����ʽ48���󣺱��ʽ������һ�������޸ĵ���ֵ" << endl;
			}

			isError = true;
		}
		id = YYV[1].expr_v.place.Var.VP.VarName;
		if(!(FC_.isBegFunDecl && MST.Lookup(id, FC_.IDENT_NAME, VP)) && !MST.Lookup(id, "", VP)) {
			if(isDebug) {  //���������̨
				cout<<"Error Line-"<<yylineno<<":  ����ʽ48����δ�������\'"<<id<<"\'"<<endl;
			} else {  //д�뵽������־
				err_lst<<"Error Line-"<<yylineno<<":  ����ʽ48����δ�������\'"<<id<<"\'"<<endl;
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
			if(isDebug) {  //���������̨
				cout<<"Error Line-"<<yylineno<<":  ����ʽ49���󣺱��ʽ������һ�������޸ĵ���ֵ" << endl;
			} else {  //д�뵽������־
				err_lst<<"Error Line-"<<yylineno<<":  ����ʽ49���󣺱��ʽ������һ�������޸ĵ���ֵ" << endl;
			}
			isError = true;
		}
		id = YYV[1].expr_v.place.Var.VP.VarName;
		if(!(FC_.isBegFunDecl && MST.Lookup(id, FC_.IDENT_NAME, VP)) && !MST.Lookup(id, "", VP)) {
			if(isDebug) {  //���������̨
				cout<<"Error Line-"<<yylineno<<":  ����ʽ49����δ�������\'"<<id<<"\'"<<endl;
			} else {  //д�뵽������־
				err_lst<<"Error Line-"<<yylineno<<":  ����ʽ49����δ�������\'"<<id<<"\'"<<endl;
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
		//�������ò����б�
		SC.AppendTail(YYV[0].stmt_v.code);   //ѹ���Ҳ���ʽ������ַ��

		nextItem.args_list_v.args_lst.append_back(YYV[0].expr_v.place);   //��������ѹ������б�

		nextItem.stmt_v.code = SC;
		yysymbol.push(nextItem);
		return true;
	case 56: //	argument_expression_list	| argument_expression_list COMMA assignment_expression	
		//�������ò����б�
		SC.AppendTail(YYV[0].stmt_v.code);   //ѹ���Ҳ��������ʽ������ַ��
		SC.AppendTail(YYV[2].stmt_v.code);   //ѹ���Ҳ��������ʽ������ַ��

		YYV[2].args_list_v.args_lst.append_back(YYV[0].expr_v.place);  //ѹ���Ҳ�Ĳ���
		nextItem.args_list_v.args_lst.append_back(YYV[2].args_list_v.args_lst);   //��ȫ������ѹ���б�

		nextItem.stmt_v.code = SC;
		yysymbol.push(nextItem);
		return true;
	case 57: //	assignment_expression	: conditional_expression
		nextItem.expr_v.place = YYV[0].expr_v.place;
		nextItem.stmt_v.code = YYV[0].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 58: //	assignment_expression	| unary_expression assignment_operator assignment_expression	
		SC.AppendTail(YYV[2].stmt_v.code);   //ѹ���������������ַ��
		SC.AppendTail(YYV[0].stmt_v.code);    //ѹ��������Ҳ������ַ��

		//�������Ż�
		if(YYV[0].expr_v.place.Var.IsImmNum && YYV[2].expr_v.place.Var.IsImmNum) {
			ON.isLabel = false;
			ON.Var.IsImmNum = true;

			switch(YYV[1].type_spec_v.type) {  //�жϸ�ֵ��������
				case ASSIGN:   //���ڸ�ֵ
					ON.Var.imm_num = YYV[0].expr_v.place.Var.IsImmNum;
					break;
				case MUL_ASSIGN:  //��*=����ֵ
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
				if(isDebug) {  //���������̨
					cout<<"Error Line-"<<yylineno<<":  ����ʽ58���󣺶�Ԫ����������������Ͳ�ͬ�������Խ������㣡"<<endl;
				} else {  //д�뵽������־
					err_lst<<"Error Line-"<<yylineno<<":  ����ʽ58���󣺶�Ԫ����������������Ͳ�ͬ�������Խ������㣡"<<endl;
				}
				isError = true;
			} else if(isError) {
			} else {
 				switch(YYV[1].type_spec_v.type) {  //�жϸ�ֵ��������
				case ASSIGN:   //���ڸ�ֵ
					QER.RS = YYV[0].expr_v.place;  //��ֵ��Դ������
					break;
				case MUL_ASSIGN:  //��*=����ֵ
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
				if(ASSIGN != YYV[1].type_spec_v.type) {   //���ڡ�=������������
					QER.RS = YYV[2].expr_v.place;
					QER.RT = YYV[0].expr_v.place;
					//��λ�����е��ر�
					if(LEFT_ASSIGN == YYV[1].type_spec_v.type || RIGHT_ASSIGN == YYV[1].type_spec_v.type) {  
						ON = QER.RS;
						QER.RS = QER.RT;
						QER.RT = ON;
					}
					ON = GenTemp(expType1);  //�洢��ʱ�������ı���
					QER.RD = ON;
					SC.AppendTail(QER);   //������Ԫʽ
				
					QER.RS = ON;   //��ֵ��Դ������
				}

                if(DOLLAR != YYV[2].type_spec_v.type) {
                    QER.OP = "MOV";
                    QER.RD.isLabel = false;
                    QER.RD.Var.IsImmNum = false;
                    QER.RD.Var.IsTempVar = false;
                    QER.RD.Var.VP = VP;//YYV[2].expr_v.place;
                    SC.AppendTail(QER);//���븳ֵ����Ԫʽ
                }else{
                    //SC.CODE.pop_back();
                    QER.OP = "SAV";
                    QER.RD = DOLLAR_ON;
                    SC.AppendTail(QER);//���븳ֵ����Ԫʽ
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
		//�˱��ʽΪ����������ʽ�����
		SC.AppendTail(YYV[2].stmt_v.code);  //ѹ�������ʽ������ַ��
		SC.AppendTail(YYV[0].stmt_v.code);  //ѹ���Ҳ���ʽ������ַ��

		//�������Ż�
		if(YYV[0].expr_v.place.Var.IsImmNum && YYV[2].expr_v.place.Var.IsImmNum) {
			ON.isLabel = false;
			ON.Var.IsImmNum = true;
			ON.Var.imm_num = YYV[2].expr_v.place.Var.imm_num | YYV[0].expr_v.place.Var.imm_num;

			nextItem.expr_v.place = ON;
		} else {
			isError = isTwoTypeSame(YYV, expType1, expType2, VP);

			if(!isError && expType1 != expType2) {
				if(isDebug) {  //���������̨
					cout<<"Error Line-"<<yylineno<<":  ����ʽ62���󣺶�Ԫ����������������Ͳ�ͬ�������Խ������㣡"<<endl;
				} else {  //д�뵽������־
					err_lst<<"Error Line-"<<yylineno<<":  ����ʽ62���󣺶�Ԫ����������������Ͳ�ͬ�������Խ������㣡"<<endl;
				}
				isError = true;
			} else if(isError) {
			} else {
				ON = GenTemp(expType1);   //������ʱ�����洢���

				QER.OP = "OR";
				QER.RS = YYV[2].expr_v.place;
				QER.RT = YYV[0].expr_v.place;
				QER.RD = ON;

				SC.AppendTail(QER);  //����ӷ����ʽ����ַ��

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
		//�˱��ʽΪ����������ʽ�����
		SC.AppendTail(YYV[2].stmt_v.code);  //ѹ�������ʽ������ַ��
		SC.AppendTail(YYV[0].stmt_v.code);  //ѹ���Ҳ���ʽ������ַ��

		if(YYV[0].expr_v.place.Var.IsImmNum && YYV[2].expr_v.place.Var.IsImmNum) {
			ON.isLabel = false;
			ON.Var.IsImmNum = true;
			ON.Var.imm_num = YYV[2].expr_v.place.Var.imm_num & YYV[0].expr_v.place.Var.imm_num;

			nextItem.expr_v.place = ON;
		} else {
			isError = isTwoTypeSame(YYV, expType1, expType2, VP);

			if(!isError && expType1 != expType2) {
				if(isDebug) {  //���������̨
					cout<<"Error Line-"<<yylineno<<":  ����ʽ64���󣺶�Ԫ����������������Ͳ�ͬ�������Խ������㣡"<<endl;
				} else {  //д�뵽������־
					err_lst<<"Error Line-"<<yylineno<<":  ����ʽ64���󣺶�Ԫ����������������Ͳ�ͬ�������Խ������㣡"<<endl;
				}
				isError = true;
			} else if(isError) {
			} else {
				ON = GenTemp(expType1);   //������ʱ�����洢���

				QER.OP = "AND";
				QER.RS = YYV[2].expr_v.place;
				QER.RT = YYV[0].expr_v.place;
				QER.RD = ON;

				SC.AppendTail(QER);  //����ӷ����ʽ����ַ��
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
		//�˱�����ж����ұ��ʽ�Ƿ����  �������򽫽����ֵ��Ϊ1
		SC.AppendTail(YYV[2].stmt_v.code);  //��ѹ��������ı��ʽ������ַ��
		SC.AppendTail(YYV[0].stmt_v.code);  //��ѹ������Ҳ�ı��ʽ������ַ��

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
				if(isDebug) {  //���������̨
					cout<<"Error Line-"<<yylineno<<":  ����ʽ72���󣺶�Ԫ����������������Ͳ�ͬ�������Խ������㣡"<<endl;
				} else {  //д�뵽������־
					err_lst<<"Error Line-"<<yylineno<<":  ����ʽ72���󣺶�Ԫ����������������Ͳ�ͬ�������Խ������㣡"<<endl;
				}
				isError = true;
			} else if(isError) {
		
			} else {
				 //����޴�������������ַ�룬����������ʱ������
				lentry = Gen_New_Label();  //�жϽ��Ϊ������ת���ı�ţ��������ֵΪ0
				lexit = Gen_New_Label();   //�ζ�����ַ������ĳ���

				//�ж�������ʽ����ȵ���ת
				QER.OP = "BNE";
				QER.RS = YYV[2].expr_v.place;  
				QER.RT = YYV[0].expr_v.place;
				QER.RD.isLabel = true;
				QER.RD.label = lentry;

				SC.AppendTail(QER);  //ѹ�����ת�ж�

				//δ��ת�����ʾ�������ʽ��ȣ��򽫽����Ϊ1��������ʱ������
				ON = GenTemp(expType1);
				QER.OP = "MOV";
				QER.RS.isLabel = false;
				QER.RS.Var.IsImmNum = true;
				QER.RS.Var.imm_num = 1;
				QER.RD = ON;

				SC.AppendTail(QER);  //ѹ�뽫�жϽ������Ϊ1

				//�������ֵ֮����Ҫ��ת
				QER.OP = "GOTO";
				QER.RD.isLabel = true;
				QER.RD.label = lexit;

				SC.AppendTail(QER);  //ѹ������������ַ��

				//�жϽ��Ϊ�����ת�����
				QER.OP = "LABEL";
				QER.RS.isLabel = true;
				QER.RS.label = lentry;

				SC.AppendTail(QER);  //ѹ����ڵı��

				//��ת���˴�֤�������жϽ��Ϊ����Ҫ�������Ϊ0��������ʱ������
				QER.OP = "MOV";
				QER.RS.isLabel = false;
				QER.RS.Var.IsImmNum = true;
				QER.RS.Var.imm_num = 0;
				QER.RD = ON;

				SC.AppendTail(QER); //ѹ����Ϊ��ĸ�ֵ����ַ��

				//��������ַ��������
				QER.OP = "LABEL";
				QER.RS.isLabel = true;
				QER.RS.label = lexit;

				SC.AppendTail(QER); //ѹ��������
				nextItem.expr_v.place = ON;
			}
		}
		nextItem.stmt_v.code = SC;
		yysymbol.push(nextItem);
		return !isError;
	case 73: //	equality_expression	| equality_expression NE_OP relational_expression	
		//�˱�����ж����ұ��ʽ�Ƿ����  �������򽫽����ֵ��Ϊ1
		SC.AppendTail(YYV[2].stmt_v.code);  //��ѹ��������ı��ʽ������ַ��
		SC.AppendTail(YYV[0].stmt_v.code);  //��ѹ������Ҳ�ı��ʽ������ַ��
		
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
				if(isDebug) {  //���������̨
					cout<<"Error Line-"<<yylineno<<":  ����ʽ73���󣺶�Ԫ����������������Ͳ�ͬ�������Խ������㣡"<<endl;
				} else {  //д�뵽������־
					err_lst<<"Error Line-"<<yylineno<<":  ����ʽ73���󣺶�Ԫ����������������Ͳ�ͬ�������Խ������㣡"<<endl;
				}
				isError = true;
			} else if(isError) {
		
			} else {
				//����޴�������������ַ�룬����������ʱ������
				lentry = Gen_New_Label();  //�жϽ��Ϊ������ת���ı�ţ��������ֵΪ0
				lexit = Gen_New_Label();   //�ζ�����ַ������ĳ���

				//�ж�������ʽ����ȵ���ת
				QER.OP = "BNE";
				QER.RS = YYV[2].expr_v.place;  
				QER.RT = YYV[0].expr_v.place;
				QER.RD.isLabel = true;
				QER.RD.label = lentry;

				SC.AppendTail(QER);  //ѹ�����ת�ж�

				//δ��ת�����ʾ�������ʽ��ȣ��򽫽����Ϊ0��������ʱ������
				ON = GenTemp(expType1);
				QER.OP = "MOV";
				QER.RS.isLabel = false;
				QER.RS.Var.IsImmNum = true;
				QER.RS.Var.imm_num = 0;
				QER.RD = ON;

				SC.AppendTail(QER);  //ѹ�뽫�жϽ����ֵΪ0

				//�������ֵ֮����Ҫ��ת
				QER.OP = "GOTO";
				QER.RD.isLabel = true;
				QER.RD.label = lexit;

				SC.AppendTail(QER);  //ѹ������������ַ��

				//�жϽ��Ϊ�����ת�����
				QER.OP = "LABEL";
				QER.RS.isLabel = true;
				QER.RS.label = lentry;

				SC.AppendTail(QER);  //ѹ����ڵı��

				//��ת���˴�֤�������жϽ��Ϊ����Ҫ�������Ϊ1��������ʱ������
				QER.OP = "MOV";
				QER.RS.isLabel = false;
				QER.RS.Var.IsImmNum = true;
				QER.RS.Var.imm_num = 1;
				QER.RD = ON;

				SC.AppendTail(QER); //ѹ����Ϊ��ĸ�ֵ����ַ��

				//��������ַ��������
				QER.OP = "LABEL";
				QER.RS.isLabel = true;
				QER.RS.label = lexit;

				SC.AppendTail(QER); //ѹ��������
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
		//�˱��ʽ�ж������ʽ��ֵ�Ƿ�С���Ҳ���ʽ�����С������Ϊ1������Ϊ0�����������ʱ������
		SC.AppendTail(YYV[2].stmt_v.code);  //��ѹ��������ı��ʽ������ַ��
		SC.AppendTail(YYV[0].stmt_v.code);  //��ѹ������Ҳ�ı��ʽ������ַ��
		
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
				if(isDebug) {  //���������̨
					cout<<"Error Line-"<<yylineno<<":  ����ʽ75���󣺶�Ԫ����������������Ͳ�ͬ�������Խ������㣡"<<endl;
				} else {  //д�뵽������־
					err_lst<<"Error Line-"<<yylineno<<":  ����ʽ75���󣺶�Ԫ����������������Ͳ�ͬ�������Խ������㣡"<<endl;
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
		//�˱��ʽ�ж������ʽ��ֵ�Ƿ�����Ҳ���ʽ�������������Ϊ1������Ϊ0�����������ʱ������
		SC.AppendTail(YYV[2].stmt_v.code);  //��ѹ��������ı��ʽ������ַ��
		SC.AppendTail(YYV[0].stmt_v.code);  //��ѹ������Ҳ�ı��ʽ������ַ��
		
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
				if(isDebug) {  //���������̨
					cout<<"Error Line-"<<yylineno<<":  ����ʽ76���󣺶�Ԫ����������������Ͳ�ͬ�������Խ������㣡"<<endl;
				} else {  //д�뵽������־
					err_lst<<"Error Line-"<<yylineno<<":  ����ʽ76���󣺶�Ԫ����������������Ͳ�ͬ�������Խ������㣡"<<endl;
				}
				isError = true;
			} else if(isError) {
			
			} else {
				ON = GenTemp(expType1);
				QER.OP = "SLT";
				QER.RS = YYV[0].expr_v.place;   //�˴�����rs��rt��ͬ������SLTָ��
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
		//�˱��ʽ�ж������ʽ��ֵ�Ƿ�С�ڵ����Ҳ���ʽ�����С�ڵ�������Ϊ1������Ϊ0�����������ʱ������
		SC.AppendTail(YYV[2].stmt_v.code);  //��ѹ��������ı��ʽ������ַ��
		SC.AppendTail(YYV[0].stmt_v.code);  //��ѹ������Ҳ�ı��ʽ������ַ��
		
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
				if(isDebug) {  //���������̨
					cout<<"Error Line-"<<yylineno<<":  ����ʽ77���󣺶�Ԫ����������������Ͳ�ͬ�������Խ������㣡"<<endl;
				} else {  //д�뵽������־
					err_lst<<"Error Line-"<<yylineno<<":  ����ʽ77���󣺶�Ԫ����������������Ͳ�ͬ�������Խ������㣡"<<endl;
				}
				isError = true;
			} else if(isError) {
			
			} else {
				ON = GenTemp(expType1);    //�洢�������ʱ����
				lexit = Gen_New_Label();   //�½����ڱ�ǩ

				//�ж�С�ڵ�����ַ��
				QER.OP ="SLT";
				QER.RS = YYV[2].expr_v.place;
				QER.RT = YYV[0].expr_v.place;
				QER.RD = ON;
				SC.AppendTail(QER);

				//�жϡ��ж�С�ڡ��Ľ��,���С��ֱ�ӽ���
				QER.OP = "BEQ";
				QER.RS.isLabel = false;
				QER.RS.Var.IsImmNum = true;
				QER.RS.Var.imm_num = 1;
				QER.RT = ON;
				QER.RD.isLabel = true;
				QER.RD.label = lexit;
				SC.AppendTail(QER);

				//�����С�ڣ��ж��Ƿ������������,���������ȣ������ж�
				QER.OP = "BNE";
				QER.RS = YYV[2].expr_v.place;
				QER.RT = YYV[0].expr_v.place;
				QER.RD.isLabel = true;
				QER.RD.label = lexit;
				SC.AppendTail(QER);

				//�����ʱ�������ֵΪ1
				QER.OP = "MOV";
				QER.RS.isLabel = false;
				QER.RS.Var.IsImmNum = true;
				QER.RS.Var.imm_num = 1;
				QER.RD = ON;
				SC.AppendTail(QER);

				//ѹ����ڱ��
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
		//�˱��ʽ�ж������ʽ��ֵ�Ƿ���ڵ����Ҳ���ʽ��������ڵ�������Ϊ1������Ϊ0�����������ʱ������
		SC.AppendTail(YYV[2].stmt_v.code);   //ѹ�������ʽ������ַ��
		SC.AppendTail(YYV[0].stmt_v.code);   //ѹ���Ҳ���ʽ������ַ��
		
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
				if(isDebug) {  //���������̨
					cout<<"Error Line-"<<yylineno<<":  ����ʽ78���󣺶�Ԫ����������������Ͳ�ͬ�������Խ������㣡"<<endl;
				} else {  //д�뵽������־
					err_lst<<"Error Line-"<<yylineno<<":  ����ʽ78���󣺶�Ԫ����������������Ͳ�ͬ�������Խ������㣡"<<endl;
				}
				isError = true;
			} else if(isError) {
			
			} else {
				ON = GenTemp(expType1);    //�洢�������ʱ����
				lexit = Gen_New_Label();   //�½����ڱ�ǩ

				//�жϴ��ڵ�����ַ��
				QER.OP ="SLT";
				QER.RS = YYV[0].expr_v.place;   //�˴��ֶ�����RS��RD�����жϡ����ڡ�
				QER.RT = YYV[2].expr_v.place;
				QER.RD = ON;
				SC.AppendTail(QER);

				//�жϡ��жϴ��ڡ��Ľ��,�������ֱ�ӽ���
				QER.OP = "BEQ";
				QER.RS.isLabel = false;
				QER.RS.Var.IsImmNum = true;
				QER.RS.Var.imm_num = 1;
				QER.RT = ON;
				QER.RD.isLabel = true;
				QER.RD.label = lexit;
				SC.AppendTail(QER);

				//��������ڣ��ж��Ƿ������������,���������ȣ������ж�
				QER.OP = "BNE";
				QER.RS = YYV[2].expr_v.place;
				QER.RT = YYV[0].expr_v.place;
				QER.RD.isLabel = true;
				QER.RD.label = lexit;
				SC.AppendTail(QER);

				//�����ʱ�������ֵΪ1
				QER.OP = "MOV";
				QER.RS.isLabel = false;
				QER.RS.Var.IsImmNum = true;
				QER.RS.Var.imm_num = 1;
				QER.RD = ON;
				SC.AppendTail(QER);

				//ѹ����ڱ��
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
		//�˱��ʽΪ������λ����������������ʱ������
		SC.AppendTail(YYV[2].stmt_v.code);  //ѹ�������ʽ������ַ��
		SC.AppendTail(YYV[0].stmt_v.code);  //ѹ���Ҳ���ʽ������ַ��
		
		if(YYV[0].expr_v.place.Var.IsImmNum && YYV[2].expr_v.place.Var.IsImmNum) {
			ON.isLabel = false;
			ON.Var.IsImmNum = true;
			ON.Var.imm_num = (YYV[2].expr_v.place.Var.imm_num << YYV[0].expr_v.place.Var.imm_num);

			nextItem.expr_v.place = ON;
		} else {
			isError = isTwoTypeSame(YYV, expType1, expType2, VP);

			if(!isError && expType1 != expType2) {
				if(isDebug) {  //���������̨
					cout<<"Error Line-"<<yylineno<<":  ����ʽ80���󣺶�Ԫ����������������Ͳ�ͬ�������Խ������㣡"<<endl;
				} else {  //д�뵽������־
					err_lst<<"Error Line-"<<yylineno<<":  ����ʽ80���󣺶�Ԫ����������������Ͳ�ͬ�������Խ������㣡"<<endl;
				}
				isError = true;
			} else if(isError) {
			} else {
				ON = GenTemp(expType1);   //������ʱ�����洢���

				QER.OP = "SLLV";
				QER.RS = YYV[0].expr_v.place;     //�˴�ע��ò�ƣ�rs��rd�෴
				QER.RT = YYV[2].expr_v.place;
				QER.RD = ON;

				SC.AppendTail(QER);  //����ӷ����ʽ����ַ��
				nextItem.expr_v.place = ON;
			}
		}
		nextItem.stmt_v.code = SC;
		yysymbol.push(nextItem);
		return !isError;
	case 81: //	shift_expression	| shift_expression RIGHT_OP additive_expression
		//�˱��ʽΪ������λ����������������ʱ������   �˴�Ϊ��������
		SC.AppendTail(YYV[2].stmt_v.code);  //ѹ�������ʽ������ַ��
		SC.AppendTail(YYV[0].stmt_v.code);  //ѹ���Ҳ���ʽ������ַ��
		
		if(YYV[0].expr_v.place.Var.IsImmNum && YYV[2].expr_v.place.Var.IsImmNum) {
			ON.isLabel = false;
			ON.Var.IsImmNum = true;
			ON.Var.imm_num = (YYV[2].expr_v.place.Var.imm_num >> YYV[0].expr_v.place.Var.imm_num);

			nextItem.expr_v.place = ON;
		} else {
			isError = isTwoTypeSame(YYV, expType1, expType2, VP);

			if(!isError && expType1 != expType2) {
				if(isDebug) {  //���������̨
					cout<<"Error Line-"<<yylineno<<":  ����ʽ81���󣺶�Ԫ����������������Ͳ�ͬ�������Խ������㣡"<<endl;
				} else {  //д�뵽������־
					err_lst<<"Error Line-"<<yylineno<<":  ����ʽ81���󣺶�Ԫ����������������Ͳ�ͬ�������Խ������㣡"<<endl;
				}
				isError = true;
			} else if(isError) {
			} else {
				ON = GenTemp(expType1);   //������ʱ�����洢���

				QER.OP = "SRLV";
				QER.RS = YYV[0].expr_v.place;     //�˴�ע��ò�ƣ�rs��rd�෴
				QER.RT = YYV[2].expr_v.place;
				QER.RD = ON;

				SC.AppendTail(QER);  //����ӷ����ʽ����ַ��
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
		//�˱��ʽΪ�ӷ����㣬����������ʱ�����У�ĿǰҪ������������������ͬ
		SC.AppendTail(YYV[2].stmt_v.code);  //ѹ�������ʽ������ַ��
		SC.AppendTail(YYV[0].stmt_v.code);  //ѹ���Ҳ���ʽ������ַ��
		
		if(YYV[0].expr_v.place.Var.IsImmNum && YYV[2].expr_v.place.Var.IsImmNum) {
			ON.isLabel = false;
			ON.Var.IsImmNum = true;
			ON.Var.imm_num = (YYV[2].expr_v.place.Var.imm_num + YYV[0].expr_v.place.Var.imm_num);

			nextItem.expr_v.place = ON;
		} else {
			isError = isTwoTypeSame(YYV, expType1, expType2, VP);

			if(!isError && expType1 != expType2) {
				if(isDebug) {  //���������̨
					cout<<"Error Line-"<<yylineno<<":  ����ʽ83���󣺶�Ԫ����������������Ͳ�ͬ�������Խ������㣡"<<endl;
				} else {  //д�뵽������־
					err_lst<<"Error Line-"<<yylineno<<":  ����ʽ83���󣺶�Ԫ����������������Ͳ�ͬ�������Խ������㣡"<<endl;
				}
				isError = true;
			} else if(isError) {
			} else {
				ON = GenTemp(expType1);   //������ʱ�����洢���

				QER.OP = "ADD";
				QER.RS = YYV[2].expr_v.place;
				QER.RT = YYV[0].expr_v.place;
				QER.RD = ON;

				SC.AppendTail(QER);  //����ӷ����ʽ����ַ��
				nextItem.expr_v.place = ON;
			}
		}
		nextItem.stmt_v.code = SC;
		yysymbol.push(nextItem);
		return !isError;
	case 84: //	additive_expression	| additive_expression SUB_OP multiplicative_expression	
		SC.AppendTail(YYV[2].stmt_v.code);  //ѹ�������ʽ������ַ��
		SC.AppendTail(YYV[0].stmt_v.code);  //ѹ���Ҳ���ʽ������ַ��
		
		if(YYV[0].expr_v.place.Var.IsImmNum && YYV[2].expr_v.place.Var.IsImmNum) {
			ON.isLabel = false;
			ON.Var.IsImmNum = true;
			ON.Var.imm_num = (YYV[2].expr_v.place.Var.imm_num - YYV[0].expr_v.place.Var.imm_num);

			nextItem.expr_v.place = ON;
		} else {
			isError = isTwoTypeSame(YYV, expType1, expType2, VP);

			if(!isError && expType1 != expType2) {
				if(isDebug) {  //���������̨
					cout<<"Error Line-"<<yylineno<<":  ����ʽ84���󣺶�Ԫ����������������Ͳ�ͬ�������Խ������㣡"<<endl;
				} else {  //д�뵽������־
					err_lst<<"Error Line-"<<yylineno<<":  ����ʽ84���󣺶�Ԫ����������������Ͳ�ͬ�������Խ������㣡"<<endl;
				}
				isError = true;
			} else if(isError) {
			} else {
				ON = GenTemp(expType1);   //������ʱ�����洢���

				QER.OP = "SUB";
				QER.RS = YYV[2].expr_v.place;
				QER.RT = YYV[0].expr_v.place;
				QER.RD = ON;

				SC.AppendTail(QER);  //����ӷ����ʽ����ַ��
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
		//�˱��ʽΪ�˷�����
		SC.AppendTail(YYV[2].stmt_v.code);  //ѹ�������ʽ������ַ��
		SC.AppendTail(YYV[0].stmt_v.code);  //ѹ���Ҳ���ʽ������ַ��
		
		if(YYV[0].expr_v.place.Var.IsImmNum && YYV[2].expr_v.place.Var.IsImmNum) {
			ON.isLabel = false;
			ON.Var.IsImmNum = true;
			ON.Var.imm_num = (YYV[2].expr_v.place.Var.imm_num * YYV[0].expr_v.place.Var.imm_num);

			nextItem.expr_v.place = ON;
		} else {
			isError = isTwoTypeSame(YYV, expType1, expType2, VP);

			if(!isError && expType1 != expType2) {
				if(isDebug) {  //���������̨
					cout<<"Error Line-"<<yylineno<<":  ����ʽ86���󣺶�Ԫ����������������Ͳ�ͬ�������Խ������㣡"<<endl;
				} else {  //д�뵽������־
					err_lst<<"Error Line-"<<yylineno<<":  ����ʽ86���󣺶�Ԫ����������������Ͳ�ͬ�������Խ������㣡"<<endl;
				}
				isError = true;
			} else if(isError) {
			} else {
				ON = GenTemp(expType1);   //������ʱ�����洢���

				QER.OP = "MUL";
				QER.RS = YYV[2].expr_v.place;
				QER.RT = YYV[0].expr_v.place;
				QER.RD = ON;

				SC.AppendTail(QER);  //����ӷ����ʽ����ַ��
				nextItem.expr_v.place = ON;
			}
		}
		nextItem.stmt_v.code = SC;
		yysymbol.push(nextItem);
		return !isError;
	case 87: //	multiplicative_expression	| multiplicative_expression DIV_OP cast_expression
		//�˱��ʽΪ����������ʽ������г���
		SC.AppendTail(YYV[2].stmt_v.code);  //ѹ�������ʽ������ַ��
		SC.AppendTail(YYV[0].stmt_v.code);  //ѹ���Ҳ���ʽ������ַ��
		
		if(YYV[0].expr_v.place.Var.IsImmNum && YYV[2].expr_v.place.Var.IsImmNum) {
			ON.isLabel = false;
			ON.Var.IsImmNum = true;
			ON.Var.imm_num = (YYV[2].expr_v.place.Var.imm_num / YYV[0].expr_v.place.Var.imm_num);

			nextItem.expr_v.place = ON;
		} else {
			isError = isTwoTypeSame(YYV, expType1, expType2, VP);

			if(!isError && expType1 != expType2) {
				if(isDebug) {  //���������̨
					cout<<"Error Line-"<<yylineno<<":  ����ʽ87���󣺶�Ԫ����������������Ͳ�ͬ�������Խ������㣡"<<endl;
				} else {  //д�뵽������־
					err_lst<<"Error Line-"<<yylineno<<":  ����ʽ87���󣺶�Ԫ����������������Ͳ�ͬ�������Խ������㣡"<<endl;
				}
				isError = true;
			} else if(isError) {
			} else {
				ON = GenTemp(expType1);   //������ʱ�����洢���

				QER.OP = "DIV";
				QER.RS = YYV[2].expr_v.place;
				QER.RT = YYV[0].expr_v.place;
				QER.RD = ON;

				SC.AppendTail(QER);  //����ӷ����ʽ����ַ��
				nextItem.expr_v.place = ON;
			}
		}
		nextItem.stmt_v.code = SC;
		yysymbol.push(nextItem);
		return !isError;
	case 88: //	multiplicative_expression	| multiplicative_expression MOD_OP cast_expression		
		//�˱��ʽΪ����������ʽ�������ģ����
		SC.AppendTail(YYV[2].stmt_v.code);  //ѹ�������ʽ������ַ��
		SC.AppendTail(YYV[0].stmt_v.code);  //ѹ���Ҳ���ʽ������ַ��
		
		if(YYV[0].expr_v.place.Var.IsImmNum && YYV[2].expr_v.place.Var.IsImmNum) {
			ON.isLabel = false;
			ON.Var.IsImmNum = true;
			ON.Var.imm_num = (YYV[2].expr_v.place.Var.imm_num % YYV[0].expr_v.place.Var.imm_num);

			nextItem.expr_v.place = ON;
		} else {
			isError = isTwoTypeSame(YYV, expType1, expType2, VP);

			if(!isError && expType1 != expType2) {
				if(isDebug) {  //���������̨
					cout<<"Error Line-"<<yylineno<<":  ����ʽ88���󣺶�Ԫ����������������Ͳ�ͬ�������Խ������㣡"<<endl;
				} else {  //д�뵽������־
					err_lst<<"Error Line-"<<yylineno<<":  ����ʽ88���󣺶�Ԫ����������������Ͳ�ͬ�������Խ������㣡"<<endl;
				}
				isError = true;
			} else if(isError) {
			} else {
				ON = GenTemp(expType1);   //������ʱ�����洢���

				QER.OP = "MOD";
				QER.RS = YYV[2].expr_v.place;
				QER.RT = YYV[0].expr_v.place;
				QER.RD = ON;

				SC.AppendTail(QER);  //����ӷ����ʽ����ַ��
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
		//���ָ�ֵ���Ŵ洢��stmt_v�е�����ַ���op��
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
		//�����������壬��������һ������Ҫһ��һ��ѹ��
		//�˴�ֻ��Ҫ������Ĳ�������ѹ��
		nextItem.param_list_v.param_lst.append_back(YYV[0].param_list_v.param_lst);

		nextItem.stmt_v.code = YYV[0].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 107://	parameter_list	| parameter_list COMMA parameter_declaration
		//�˲���ʽ����ͬ106��Ҳ��Ҫ��������������ƴ����һ��ѹ��
		YYV[2].param_list_v.param_lst.append_back(YYV[0].param_list_v.param_lst);
		nextItem.param_list_v.param_lst.append_back(YYV[2].param_list_v.param_lst);

		nextItem.stmt_v.code = YYV[0].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 108://	parameter_declaration	: declaration_specifiers declarator	
		//�˴�Ӧ�ý���������ת��Ϊ�����ĵĲ�������֮һ
		//�˴�Ӧ���½�һ��VarList���в���
		//VarList newParam;
		newParam.ID_Name = YYV[0].expr_v.place.Var.VP.VarName;
		newParam.Type = YYV[1].type_spec_v.type;
		newParam.isArray = false;
		nextItem.param_list_v.param_lst.append_back(newParam);

		nextItem.stmt_v.code = YYV[0].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 109://	parameter_declaration	| declaration_specifiers	
		//�˱����ָ�����˺������������ͣ���;ͬcase 108
		//VarList newParam;
		newParam.Type = YYV[1].type_spec_v.type;
		newParam.isArray = false;
		nextItem.param_list_v.param_lst.append_back(newParam);

		nextItem.stmt_v.code = YYV[0].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 110://	identifier_list	: IDENTIFIER	
		//�˱��ʽΪ�������������Ӧ�½�һ��Operator_NUM��ѹ��args_�����б�
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
		//�˱��ʽΪƴ�Ӵ�������б���˴��������ѹ��
		YYV[2].args_list_v.args_lst.append_back(YYV[0].args_list_v.args_lst);
		nextItem.args_list_v.args_lst.append_back(YYV[2].args_list_v.args_lst);
		
		//������ַ����Ҫ����
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
		//Ŀ���Ǹ���Ч�Ĳ���ʽ

		nextItem.stmt_v.code = YYV[1].stmt_v.code;
		yysymbol.push(nextItem);
		return true;
	case 115://	declaration	| declaration_specifiers init_declarator_list SEMICOLON	
		//nextItem.type_spec_v = YYV[2].type_spec_v;
		nextItem.expr_v.place = YYV[1].expr_v.place;

		//�˴�ע���µı������ж��Ǿֲ���������ȫ�ֱ������Ƿ��ظ�����
		count_num =  YYV[1].args_list_v.args_lst.args_place.size();
		//�������������б�
		for(i_count = 0; i_count < count_num; i_count++) {
			id = YYV[1].args_list_v.args_lst.args_place[i_count].Var.VP.VarName;
			isError = true;
			//���ұ����Ƿ���ȫ���ж��壬�Ƿ��ھֲ��ж��壬�����δ������ע���µ�
			if(FC_.isBegFunDecl && MST.Lookup(id, FC_.IDENT_NAME, VP)) {  //����������ҵ�����ֲ��Ѷ��壬����
				if(isDebug) {  //���������̨
					cout<<"Error Line-"<<yylineno<<":  ����ʽ115���󣺱����� \'"<<id<<"\' �Ѿ��ڴ˺����б����壡"<<endl;
				} else {  //д�뵽������־
					err_lst<<"Error Line-"<<yylineno<<":  ����ʽ115���󣺱����� \'"<<id<<"\' �Ѿ��ڴ˺����б����壡"<<endl;
				}
			} else if(MST.Lookup(id, "", VP)) {   //��ȫ�ֱ������ҵ�
				if(isDebug) {  //���������̨
					cout<<"Error Line-"<<yylineno<<":  ����ʽ115���󣺱����� \'"<<id<<"\' �Ѿ���ȫ�������������壡"<<endl;
				} else {  //д�뵽������־
					err_lst<<"Error Line-"<<yylineno<<":  ����ʽ115���󣺱����� \'"<<id<<"\' �Ѿ���ȫ�������������壡"<<endl;
				}
			} else {  //δ�ҵ��������µı�����������ű�
				//�����µı���
				if(YYV[1].args_list_v.args_lst.args_place[i_count].Var.VP.isArray) {
					newParam.isArray = true;
					newParam.Array_Len = YYV[1].args_list_v.args_lst.args_place[i_count].Var.VP.Array_Len;
				}
				else
					newParam.isArray = false;
				if(YYV[2].type_spec_v.type == VOID) {
					if(isDebug) {  //���������̨
						cout<<"Error Line-"<<yylineno<<":  ����ʽ115���󣺱��������������Ͳ�������Ϊviod����" << endl;
					} else {  //д�뵽������־
						err_lst<<"Error Line-"<<yylineno<<":  ����ʽ115���󣺱��������������Ͳ�������Ϊviod����" << endl;
					}
					isError = true;
				}
				newParam.Type = YYV[2].type_spec_v.type;
				newParam.ID_Name = id;

				if(FC_.isBegFunDecl) {  //�ں����ڲ���Ϊ�ֲ�����
					newParam.offset = local_offset;
					local_offset += YYV[2].type_spec_v.width;
					MST.insert(newParam, FC_.IDENT_NAME);
					if(isDebug) {  //���������̨
						cout<<"ע�ắ��"<<FC_.IDENT_NAME<<" �ھֲ�����: "<<id<<endl;
					} 
				} else {  //���ڣ���Ϊȫ�ֱ���
					newParam.offset = global_offset;
					global_offset += YYV[2].type_spec_v.width;
					MST.insert(newParam, "");
					if(isDebug) {  //���������̨
						cout<<"ע��ȫ�ֱ���: "<<id<<endl;
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
		//ʹ��args_���ݶ����������
		nextItem.args_list_v.args_lst.append_back(YYV[0].args_list_v.args_lst);

		yysymbol.push(nextItem);
		return true;
	case 117://	init_declarator_list	| init_declarator_list COMMA init_declarator	
		//�����������ƴ�ӣ�ʹ��args_����
		YYV[2].args_list_v.args_lst.append_back(YYV[0].args_list_v.args_lst);
		nextItem.args_list_v.args_lst = YYV[2].args_list_v.args_lst;

		YYV[2].stmt_v.code.AppendTail(YYV[0].stmt_v.code);
		nextItem.stmt_v.code = YYV[2].stmt_v.code;

		yysymbol.push(nextItem);
		return true;
	case 118://	init_declarator	: declarator	
		//nextItem.expr_v.place = YYV[0].expr_v.place;
		nextItem.stmt_v.code = YYV[0].stmt_v.code;

		//�˴������Ƕ���������������ӦΪһ�����������ϣ�������.place�ظ�����˲�����.place
		//ʹ��args_���ݣ����뺯�����ô��������ͻ
		nextItem.args_list_v.args_lst.append_back(YYV[0].expr_v.place);

		yysymbol.push(nextItem);
		return true;
	case 119://	init_declarator	| declarator ASSIGN assignment_expression	
		//�α��ʽ���������˱�����ͬʱ�����˳�ʼ����ֵ������Ӧ���и�ֵ����������ַ�����ɡ�
		//�˴������Ƕ���������������ӦΪһ�����������ϣ�������.place�ظ�����˲�����.place
		//ʹ��args_���ݣ����뺯�����ô��������ͻ
		nextItem.args_list_v.args_lst.append_back(YYV[0].expr_v.place);

		//�˴����ʽӦ�ý�������ʼ������������ڱ��ߵ��ķ����ƣ�������

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
		//�˱��ʽΪ����if��������ַ�룬ͬ��û���ж��Ƿ����if���ж�
		lexit = Gen_New_Label();   //�µĳ��ڱ��
		SC.AppendTail(YYV[2].stmt_v.code);  //ѹ���ж�����������ַ��

		if(YYV[2].expr_v.place.isLabel) {
			if(isDebug) {  //���������̨
				cout<<"Error Line-"<<yylineno<<":  ����ʽ138���󣺲��Ϸ����ʽ��"<<endl;
			} else {  //д�뵽������־
				err_lst<<"Error Line-"<<yylineno<<":  ����ʽ138���󣺲��Ϸ����ʽ��"<<endl;
			}

			nextItem.stmt_v.code = SC;
			yysymbol.push(nextItem);
			return false;
		}

		// judge for expression | expression must be a value
		if(!YYV[2].expr_v.place.Var.IsImmNum && !YYV[2].expr_v.place.Var.IsTempVar) {
			id = YYV[2].expr_v.place.Var.VP.VarName;
			if(FC_.isBegFunDecl && !MST.Lookup(id, FC_.IDENT_NAME, VP) && !MST.Lookup(id, "", VP)) {
				if(isDebug) {  //���������̨
					cout<<"Error Line-"<<yylineno<<":  ����ʽ138����δ�������\'"<<id<<"\'���鶨�壡"<<endl;
				} else {  //д�뵽������־
					err_lst<<"Error Line-"<<yylineno<<":  ����ʽ138����δ�������\'"<<id<<"\'���鶨�壡"<<endl;
				}
				isError = true;
			} else if(!FC_.isBegFunDecl && !MST.Lookup(id, "", VP)) {
				if(isDebug) {  //���������̨
					cout<<"Error Line-"<<yylineno<<":  ����ʽ138����δ�������\'"<<id<<"\'���鶨�壡"<<endl;
				} else {  //д�뵽������־
					err_lst<<"Error Line-"<<yylineno<<":  ����ʽ138����δ�������\'"<<id<<"\'���鶨�壡"<<endl;
				}
				isError = true;
			} else {
				isError = false;
			}
		}

		if(!isError) {
			//���ж���ת������ַ��
			QER.OP = "BEQ";
			QER.RS.isLabel = false;
			QER.RS.Var.IsImmNum = true;
			QER.RS.Var.imm_num = 0;
			QER.RT = YYV[2].expr_v.place;
			QER.RD.isLabel = true;
			QER.RD.label = lexit;

			SC.AppendTail(QER);  //ѹ����ж���ת����ַ��
			SC.AppendTail(YYV[0].stmt_v.code);  //ѹ��if�����е�����ַ��

			//���ڵ�����ַ��
			QER.OP = "LABEL";
			QER.RS.isLabel = true;
			QER.RS.label = lexit;

			SC.AppendTail(QER);  //ѹ����ڵ�label���
		}

		nextItem.stmt_v.code = SC;
		yysymbol.push(nextItem);
		return !isError;
	case 139 : //	selection_statement	| IF LPAR expression RPAR statement ELSE statement
		lentry = Gen_New_Label();  //else����ڱ��
		lexit = Gen_New_Label();   //�µĳ��ڱ��

		SC.AppendTail(YYV[4].stmt_v.code);  //ѹ���ж�����������ַ��

		if(YYV[4].expr_v.place.isLabel) {
			if(isDebug) {  //���������̨
				cout<<"Error Line-"<<yylineno<<":  ����ʽ139���󣺲���ʽ139���󣺲��Ϸ����ʽ��"<<endl;
			} else {  //д�뵽������־
				err_lst<<"Error Line-"<<yylineno<<":  ����ʽ139���󣺲���ʽ139���󣺲��Ϸ����ʽ��"<<endl;
			}

			nextItem.stmt_v.code = SC;
			yysymbol.push(nextItem);
			return false;
		}

		// judge for expression | expression must be a value
		if(!YYV[4].expr_v.place.Var.IsImmNum && !YYV[4].expr_v.place.Var.IsTempVar) {
			id = YYV[4].expr_v.place.Var.VP.VarName;
			if(FC_.isBegFunDecl && !MST.Lookup(id, FC_.IDENT_NAME, VP) && !MST.Lookup(id, "", VP)) {
				if(isDebug) {  //���������̨
					cout<<"Error Line-"<<yylineno<<":  ����ʽ139����δ�������\'"<<id<<"\'���鶨�壡"<<endl;
				} else {  //д�뵽������־
					err_lst<<"Error Line-"<<yylineno<<":  ����ʽ139����δ�������\'"<<id<<"\'���鶨�壡"<<endl;
				}

				isError = true;
			} else if(!FC_.isBegFunDecl && !MST.Lookup(id, "", VP)) {
				if(isDebug) {  //���������̨
					cout<<"Error Line-"<<yylineno<<":  ����ʽ139����δ�������\'"<<id<<"\'���鶨�壡"<<endl;
				} else {  //д�뵽������־
					err_lst<<"Error Line-"<<yylineno<<":  ����ʽ139����δ�������\'"<<id<<"\'���鶨�壡"<<endl;
				}
				isError = true;
			} else {
				isError = false;
			}
		}

		if(!isError) {
			//���ж���ת������ַ��
			QER.OP = "BEQ";
			QER.RS.isLabel = false;
			QER.RS.Var.IsImmNum = true;
			QER.RS.Var.imm_num = 0;
			QER.RT = YYV[4].expr_v.place;
			QER.RD.isLabel = true;
			QER.RD.label = lentry;  //����else

			SC.AppendTail(QER);  //ѹ����ж���ת����ַ��
			SC.AppendTail(YYV[1].stmt_v.code);  //ѹ��if�����е�����ַ��

			//ִ����if���ڣ�����else��
			QER.OP = "GOTO";
			QER.RD.isLabel = true;
			QER.RD.label = lexit;

			SC.AppendTail(QER); //ѹ��������else֮�������ַ��

			//else����ڱ��
			QER.OP = "LABEL";
			QER.RS.isLabel = true;
			QER.RS.label = lentry;

			SC.AppendTail(QER);  //ѹ��else����ڱ��
			SC.AppendTail(YYV[0].stmt_v.code);  //ѹ��else������ַ��

			//if..else�˳��ı��
			QER.OP = "LABEL";
			QER.RS.isLabel = true;
			QER.RS.label = lexit;

			SC.AppendTail(QER);  //ѹ��if..else�ĳ��ڱ��
		}

		nextItem.stmt_v.code = SC;
		yysymbol.push(nextItem);
		return !isError;
	case 140 : //	selection_statement	| SWITCH LPAR expression RPAR statement	
	case 141 : //	iteration_statement	: WHILE LPAR expression RPAR statement	
		//�˱��ʽ����while��������ַ��  ��ʱδ�����Ƿ����while�ж�
		SC.AppendTail(YYV[2].stmt_v.code);  //ѹ���ж�����������ַ��

		if(YYV[2].expr_v.place.isLabel) {
			if(isDebug) {  //���������̨
				cout<<"Error Line-"<<yylineno<<":  ����ʽ141���󣺲��Ϸ����ʽ��"<<endl;
			} else {  //д�뵽������־
				err_lst<<"Error Line-"<<yylineno<<":  ����ʽ141���󣺲��Ϸ����ʽ��"<<endl;
			}
			nextItem.stmt_v.code = SC;
			yysymbol.push(nextItem);
			return false;
		}

		// judge for expression | expression must be a value
		if(!YYV[2].expr_v.place.Var.IsImmNum && !YYV[2].expr_v.place.Var.IsTempVar) {
			id = YYV[2].expr_v.place.Var.VP.VarName;
			if(FC_.isBegFunDecl && !MST.Lookup(id, FC_.IDENT_NAME, VP) && !MST.Lookup(id, "", VP)) {
				if(isDebug) {  //���������̨
					cout<<"Error Line-"<<yylineno<<":  ����ʽ141����δ�������\'"<<id<<"\'���鶨�壡"<<endl;
				} else {  //д�뵽������־
					err_lst<<"Error Line-"<<yylineno<<":  ����ʽ141����δ�������\'"<<id<<"\'���鶨�壡"<<endl;
				}

				isError = true;
			} else if(!FC_.isBegFunDecl && !MST.Lookup(id, "", VP)) {
				if(isDebug) {  //���������̨
					cout<<"Error Line-"<<yylineno<<":  ����ʽ141����δ�������\'"<<id<<"\'���鶨�壡"<<endl;
				} else {  //д�뵽������־
					err_lst<<"Error Line-"<<yylineno<<":  ����ʽ141����δ�������\'"<<id<<"\'���鶨�壡"<<endl;
				}

				isError = true;
			} else {
				isError = false;
			}
		}

		if(!isError) {
			//��ת�ã� ��ڱ������ַ��
			QER.OP = "LABEL";
			QER.RS.isLabel = true;
			QER.RS.label = WC_.entry;

			SC.AppendTail(QER);  //ѹ����ת����ַ��
			SC.AppendTail(YYV[2].stmt_v.code);  //ѹ���ж���������ַ��
		
			//ѭ�������ж�����ַ��
			QER.OP = "BEQ";
			QER.RS.isLabel = false;
			QER.RS.Var.IsImmNum = true;
			QER.RS.Var.imm_num = 0;
			QER.RT = YYV[2].expr_v.place;
			QER.RD.isLabel = true;
			QER.RD.label = WC_.exit;

			SC.AppendTail(QER);  //ѹ����ж���ת����ַ��
			SC.AppendTail(YYV[0].stmt_v.code);  //ѹ��whileѭ�����ڵ�����ַ��

			QER.OP = "GOTO";
			QER.RD.isLabel = true;
			QER.RD.label = WC_.entry;

			SC.AppendTail(QER);  //ѹ����ת��while��ڵ�����ַ��

			QER.OP = "LABEL";
			QER.RS.isLabel = true;
			QER.RS.label = WC_.exit;

			SC.AppendTail(QER);  //ѹ��while��������ַ��
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
			if(isDebug) {  //���������̨
				cout<<"Error Line-"<<yylineno<<":  ����ʽ148����continue������ʹ����while����Ŀ��У�"<<endl;
			} else {  //д�뵽������־
				err_lst<<"Error Line-"<<yylineno<<":  ����ʽ148����continue������ʹ����while����Ŀ��У�"<<endl;
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
			if(isDebug) {  //���������̨
				cout<<"Error Line-"<<yylineno<<":  ����ʽ149����break������ʹ����while����Ŀ��У�"<<endl;
			} else {  //д�뵽������־
				err_lst<<"Error Line-"<<yylineno<<":  ����ʽ149����break������ʹ����while����Ŀ��У�"<<endl;
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
				if(isDebug) {  //���������̨
					cout<<"Error Line-"<<yylineno<<":  ����ʽ150���󣺺����������޷������ͣ�"<<endl;
				} else {  //д�뵽������־
					err_lst<<"Error Line-"<<yylineno<<":  ����ʽ150���󣺺����������޷������ͣ�"<<endl;
				}
				isError = true;
			} else {
				QER.OP = "RETN";
				SC.AppendTail(QER);
			}
		} else {
			if(isDebug) {  //���������̨
				cout<<"Error Line-"<<yylineno<<":  ����ʽ150����return������ʹ���ں������⣡"<<endl;
			} else {  //д�뵽������־
				err_lst<<"Error Line-"<<yylineno<<":  ����ʽ150����return������ʹ���ں������⣡"<<endl;
			}
			isError = true;
		}
		nextItem.stmt_v.code = SC;
		yysymbol.push(nextItem);
		return !isError;
	case 151 : //	jump_statement	| RETURN expression SEMICOLON	
		SC.AppendTail(YYV[1].stmt_v.code);  //ѹ��return ��ı��ʽ������ַ��

		if(FC_.isBegFunDecl) {
			finFT = MST.GetFunction_Table(FC_.IDENT_NAME);
			if(YYV[1].expr_v.place.isLabel) {
				if(isDebug) {  //���������̨
					cout<<"Error Line-"<<yylineno<<":  ����ʽ151���󣺺������ر��ʽ�Ƿ���"<<endl;
				} else {  //д�뵽������־
					err_lst<<"Error Line-"<<yylineno<<":  ����ʽ151���󣺺������ر��ʽ�Ƿ���"<<endl;
				}
				
				isError = true;
			} else {
				if(YYV[1].expr_v.place.Var.IsImmNum && finFT->return_type != INT) {
					if(isDebug) {  //���������̨
						cout<<"Error Line-"<<yylineno<<":  ����ʽ151���󣺺������������붨�岻����"<<endl;
					} else {  //д�뵽������־
						err_lst<<"Error Line-"<<yylineno<<":  ����ʽ151���󣺺������������붨�岻����"<<endl;
					}
					isError = true;
				} else if(YYV[1].expr_v.place.Var.IsTempVar && finFT->return_type != YYV[1].expr_v.place.Var.VT.type) {
					if(isDebug) {  //���������̨
						cout<<"Error Line-"<<yylineno<<":  ����ʽ151���󣺺������������붨�岻����"<<endl;
					} else {  //д�뵽������־
						err_lst<<"Error Line-"<<yylineno<<":  ����ʽ151���󣺺������������붨�岻����"<<endl;
					}
					isError = true;
				} else if(finFT->return_type != YYV[1].expr_v.place.Var.VP.type) {
					if(isDebug) {  //���������̨
						cout<<"Error Line-"<<yylineno<<":  ����ʽ151���󣺺������������붨�岻����"<<endl;
					} else {  //д�뵽������־
						err_lst<<"Error Line-"<<yylineno<<":  ����ʽ151���󣺺������������붨�岻����"<<endl;
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
			if(isDebug) {  //���������̨
				cout<<"Error Line-"<<yylineno<<":  ����ʽ151����return������ʹ���ں������⣡"<<endl;
			} else {  //д�뵽������־
				err_lst<<"Error Line-"<<yylineno<<":  ����ʽ151����return������ʹ���ں������⣡"<<endl;
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
		if(isDebug) {  //���������̨
			cout<<"Error Line-"<<yylineno<<":  ��Ԫ�������������˷Ǳ�������"<<endl;
		} else {  //д�뵽������־
			err_lst<<"Error Line-"<<yylineno<<":  ��Ԫ�������������˷Ǳ�������"<<endl;
		}
		isError = true;
	}

	//�����Ҳ���ʽ���ս��������
	if(YYV[0].expr_v.place.Var.IsImmNum) {
		expType1 = INT;
	} else if(YYV[0].expr_v.place.Var.IsTempVar) {
		expType1 = YYV[0].expr_v.place.Var.VT.type;
	} else {
		id = YYV[0].expr_v.place.Var.VP.VarName;
		if(FC_.isBegFunDecl && !MST.Lookup(id, FC_.IDENT_NAME, VP) && !MST.Lookup(id, "", VP)) {
			if(isDebug) {  //���������̨
				cout<<"Error Line-"<<yylineno<<":  δ�������\'"<<id<<"\'���鶨�壡"<<endl;
			} else {  //д�뵽������־
				err_lst<<"Error Line-"<<yylineno<<":  δ�������\'"<<id<<"\'���鶨�壡"<<endl;
			}
			isError = true;
		} else if(!FC_.isBegFunDecl && !MST.Lookup(id, "", VP)) {
			if(isDebug) {  //���������̨
				cout<<"Error Line-"<<yylineno<<":  δ�������\'"<<id<<"\'���鶨�壡"<<endl;
			} else {  //д�뵽������־
				err_lst<<"Error Line-"<<yylineno<<":  δ�������\'"<<id<<"\'���鶨�壡"<<endl;
			}
			isError = true;
		} else {
			expType1 = VP.type;
		}
	}

	//���������ʽ���ս��������
	if(YYV[2].expr_v.place.Var.IsImmNum) {
		expType2 = INT;
	} else if(YYV[2].expr_v.place.Var.IsTempVar) {
		expType2 = YYV[2].expr_v.place.Var.VT.type;
	} else {
		id = YYV[2].expr_v.place.Var.VP.VarName;
		if(FC_.isBegFunDecl && !MST.Lookup(id, FC_.IDENT_NAME, VP) && !MST.Lookup(id, "", VP)) {
			if(isDebug) {  //���������̨
				cout<<"Error Line-"<<yylineno<<":  δ�������\'"<<id<<"\'���鶨�壡"<<endl;
			} else {  //д�뵽������־
				err_lst<<"Error Line-"<<yylineno<<":  δ�������\'"<<id<<"\'���鶨�壡"<<endl;
			}
			isError = true;
		} else if(!FC_.isBegFunDecl && !MST.Lookup(id, "", VP)) {
			if(isDebug) {  //���������̨
				cout<<"Error Line-"<<yylineno<<":  δ�������\'"<<id<<"\'���鶨�壡"<<endl;
			} else {  //д�뵽������־
				err_lst<<"Error Line-"<<yylineno<<":  δ�������\'"<<id<<"\'���鶨�壡"<<endl;
			}
			isError = true;
		} else {
			expType2 = VP.type;
		}
	}

	return isError;
}
#endif // YYACTION_H
