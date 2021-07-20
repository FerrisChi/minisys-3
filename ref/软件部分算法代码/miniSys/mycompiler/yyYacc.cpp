#ifndef _YYYACC_H
#define _YYYACC_H

#pragma once
#include "yyLex.h"
#include "yyAction.h"
#include "GlobalVar.h"
#include "LRTable.h"
#include"ASM_TRANSLATE.h"
#include"WriteToASMFile.h"

#include<iostream>
#include<hash_map>
#include<stack>
#include<fstream>
#include<string>


using namespace std;
using namespace stdext;
#define E 4004
#define ACCEPT -1
#define SOURCE_END 9999


//extern int analysis(char *yytext,int n);
struct Sym
{
	int symbol;
	int state;
};
hash_map<int,int> signalTable;
int producerN[152]={1,1,2,1,1,4,3,1,2,1,2,1,2,1,1,1,1,1,1,1,1,1,1,3,5,4,4,6,6,3,4,4,3,1,2,2,2,2,4,1,1,1,1,1,4,3,4,2,2,1,1,3,1,3,1,3,1,3,1,5,1,3,1,3,1,3,1,3,1,3,1,3,3,1,3,3,3,3,1,3,3,1,3,3,1,3,3,3,1,4,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,1,3,2,1,1,3,1,2,2,3,1,3,1,3,2,3,1,2,1,1,1,1,1,1,1,1,3,4,3,1,1,2,5,7,5,5,7,6,7,6,7,3,2,2,2,3,1};
int pLeftSection[152]={30000,30001,30001,30002,30002,30003,30003,30005,30005,30005,30005,30005,30005,30009,30009,30009,30009,30009,30009,30009,30009,30006,30010,30010,30010,30010,30010,30010,30010,30010,30010,30010,30010,30014,30014,30014,30014,30014,30014,30016,30016,30016,30016,30015,30015,30015,30015,30015,30015,30019,30019,30019,30020,30020,30021,30021,30011,30011,30022,30022,30024,30024,30025,30025,30026,30026,30027,30027,30028,30028,30029,30029,30029,30030,30030,30030,30030,30030,30031,30031,30031,30032,30032,30032,30033,30033,30033,30033,30017,30017,30023,30023,30023,30023,30023,30023,30023,30023,30023,30023,30023,30018,30018,30018,30018,30012,30012,30034,30034,30013,30013,30007,30007,30004,30004,30035,30035,30036,30036,30008,30008,30037,30037,30038,30038,30039,30039,30039,30039,30039,30039,30040,30040,30040,30045,30041,30041,30042,30042,30042,30043,30043,30043,30043,30043,30043,30044,30044,30044,30044,30044,30016};
ifstream fin;

int searchTable(int cstate,char symbol)
{
	return actionTable[cstate][symbol];
}

int readToken()
{
	if(fin.eof())
		return SOURCE_END;
	char buf[256];//不支持超过256个字符的符号
	int pos=0;
	bool isEnd=false;
	bool isToken=false;//与isOperator互斥
	bool isOperator=false;
    string ops("!@#$%^&*()+-=|[]{};':\",.<>/?");
	string wss("\t\n\r ");
    string letter("_0123456789aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ");
    string special_symbol("@#$()[]{};':\",.?");
	char c=fin.get();
	while(c==' '||c=='\t'||c=='\n'||c=='\r') {
		if(c == '\n') yylineno++;
		c=fin.get();//滤掉空白符
	}
	// here we delete the comment info in the program of user input
	while(c == '/' && (fin.peek() == '/' || fin.peek() == '*')) {
		if(c == '/' && fin.peek() == '/') {
			while(c != '\n') fin.get(c);
			yylineno++;
			while(true) {
				if(fin.get(c) == NULL) return SOURCE_END;
				if(c == '\n') yylineno++;
				if(c == ' ' || c == '\t') continue;
				else break;
			}
		}
		else if(c == '/' && fin.peek() == '*') {
			fin.get(c);
			fin.get(c);
			if(c == '\n') yylineno++;
			while(!(c == '*' && fin.peek() == '/')) {
				if(fin.get(c) == NULL) return SOURCE_END;
				else if(c == '\n') yylineno++;
			}
			fin.get(c); fin.get(c);
			if(c == '\n') yylineno++;
			while(true) {
				if(fin.get(c) == NULL) return SOURCE_END;
				else if(c == '\n') yylineno++;
				else if(c == ' ' || c == '\t') continue;
				else break;
			}
		}
	}
	while(!isEnd)
	{
		if(c==-1)
		{
			buf[pos]='\0';
			isEnd=true;
			continue;
		}
		if(ops.find(c)>=0&&ops.find(c)<ops.size())//表示当c不是正常字符时。
		{
			//进入非正常字符的处理过程
			if(isToken)
			{
				fin.unget();
				buf[pos]='\0';
				isEnd=true;
			}
			else if(special_symbol.find(c) >= 0 && special_symbol.find(c) < special_symbol.size()) {
				if(isOperator) {
					buf[pos] = 0;
					fin.unget();
				} else {
					buf[pos] = c;
					buf[pos+1] = 0;
				}
				isEnd = true;
			}
			else
			{
				isOperator=true;
				buf[pos]=c;
				pos++;
				c=fin.get();
			}
			continue;
		}
		if(letter.find(c)>=0&&letter.find(c)<letter.size())
		{
			if(isOperator)
			{
				fin.unget();
				buf[pos]='\0';
				isEnd=true;
			}
			else
			{
				isToken=true;
				buf[pos]=c;
				pos++;
				c=fin.get();
			}
			continue;
		}
		if(wss.find(c)>=0&&wss.find(c)<wss.size())
		{
			buf[pos]='\0';
			isEnd=true;
		}
		else return -1;
	}
    //cout << buf << " " << analysis(buf, strlen(buf)) << endl;
	//printf("line: %d -> word: %s\n", yylineno, buf);
	int res = analysis(buf,strlen(buf));

	if(res == IDENTIFIER) {
		yyval.IDENT_v.ID_NAME = buf;
	} else if(res == CONSTANT) {
		yyval.int_literal_v.int_val = atoi(buf);
	}

	//遇到while时候，进行标记
	if(res == WHILE) {
		WC_.isInWhileStmt = true;
		WC_.entry = Gen_New_Label();
		WC_.exit = Gen_New_Label();
	}

	return res;
}

// 没有处理词法分析出错的情况
int parse()
{
	int inputsymbol=0;
	int cstate=0;
	stack<Sym> symStack;//符号栈
	Sym st;//用作分析时的临时栈顶元素存储变量
	st.symbol=0;
	st.state=0;
	symStack.push(st); 
    inputsymbol=readToken();
	while(1)
	{
		// here deal with lex error
		if(inputsymbol == LEXERROR) {
            //err_log << "词法分析出错，" << endl;
		}
		st=symStack.top();
		// avoid out range of array 
        if(st.state >= 1224 || inputsymbol >= 120) {
            //err_log << "未知语法分析出错" << endl;
		}

		int col=signalTable[inputsymbol];
		int result=searchTable(st.state,col);
        cout<<"st.state:"<<st.state<<" "
           <<"inputsymbol:"<<inputsymbol<<" "
          <<"result:"<<result<<endl;
		// error showed below should change its format

		if(result==E)//出错
		{
			cout<<"Compile Error!"<<endl;
			return 0;
		}
		if(result==ACCEPT)
		{
			cout<<"Compile sucessfully!"<<endl;
			YYTYPE result = yysymbol.top();
			vector<QUAD_EXP_ROW> allCode = result.stmt_v.code.CODE;

			for(vector<QUAD_EXP_ROW>::iterator iter = allCode.begin(); iter != allCode.end(); iter++) {
				cout<<"OP:"<<iter->OP<<"\tRS:";
				if(iter->RS.isLabel) {
					cout<<iter->RS.label<<"\tRT:";
				} else {
					if(iter->RS.Var.IsImmNum) {
						cout<<iter->RS.Var.imm_num<<"\tRT:";
					} else if(iter->RS.Var.IsTempVar) {
						cout<<iter->RS.Var.VT.TempVar_ID<<"\tRT:";
					} else {
						cout<<iter->RS.Var.VP.VarName<<"\tRT:";
					}
				}

				if(iter->RT.isLabel) {
					cout<<iter->RT.label<<"\tRD:";
				} else {
					if(iter->RT.Var.IsImmNum) {
						cout<<iter->RT.Var.imm_num<<"\tRD:";
					} else if(iter->RT.Var.IsTempVar) {
						cout<<iter->RT.Var.VT.TempVar_ID<<"\tRD:";
					} else {
						cout<<iter->RT.Var.VP.VarName<<"\tRD:";
					}
				}

				if(iter->RD.isLabel) {
					cout<<iter->RD.label<<endl;
				} else {
					if(iter->RD.Var.IsImmNum) {
						cout<<iter->RD.Var.imm_num<<endl;
					} else if(iter->RD.Var.IsTempVar) {
						cout<<iter->RD.Var.VT.TempVar_ID<<endl;
					} else {
						cout<<iter->RD.Var.VP.VarName<<endl;
					}
				}
			}
			
			return 1;
		}
		if(result<0)//负数表示为归约项目
		{
			result*=-1;
			int n=producerN[result-1];//取得该号产生式右部符号数量，以作弹栈用
			if(!checkAction(result, n)) {
				// here show the err msg

			}

			for(int i=0;i<n;i++)
			{
				symStack.pop();
			}
			//再将产生式左部的符号压栈
			st.symbol=pLeftSection[result-1];
			st.state=searchTable(symStack.top().state,signalTable[st.symbol]);
			symStack.push(st);
		}
		else // here we deal with shift
		{
			st.symbol=inputsymbol;
			st.state=result;
			symStack.push(st);
            yysymbol.push(yyval);

            inputsymbol=readToken();
		}
	}
}

bool complierParser(string filename)
{
	pair<int,int> tp;
	tp.first=40017;
	tp.second=17;
	signalTable.insert(tp);
	tp.first=40042;
	tp.second=42;
	signalTable.insert(tp);
	tp.first=40021;
	tp.second=21;
	signalTable.insert(tp);
	tp.first=40012;
	tp.second=12;
	signalTable.insert(tp);
	tp.first=40024;
	tp.second=24;
	signalTable.insert(tp);
	tp.first=40039;
	tp.second=39;
	signalTable.insert(tp);
	tp.first=40041;
	tp.second=41;
	signalTable.insert(tp);
	tp.first=40038;
	tp.second=38;
	signalTable.insert(tp);
	tp.first=40040;
	tp.second=40;
	signalTable.insert(tp);
	tp.first=40057;
	tp.second=57;
	signalTable.insert(tp);
	tp.first=40069;
	tp.second=69;
	signalTable.insert(tp);
	tp.first=40059;
	tp.second=59;
	signalTable.insert(tp);
	tp.first=40049;
	tp.second=49;
	signalTable.insert(tp);
	tp.first=40032;
	tp.second=32;
	signalTable.insert(tp);
	tp.first=40034;
	tp.second=34;
	signalTable.insert(tp);
	tp.first=40055;
	tp.second=55;
	signalTable.insert(tp);
	tp.first=40002;
	tp.second=2;
	signalTable.insert(tp);
	tp.first=40068;
	tp.second=68;
	signalTable.insert(tp);
	tp.first=40048;
	tp.second=48;
	signalTable.insert(tp);
	tp.first=40060;
	tp.second=60;
	signalTable.insert(tp);
	tp.first=40015;
	tp.second=15;
	signalTable.insert(tp);
	tp.first=40045;
	tp.second=45;
	signalTable.insert(tp);
	tp.first=40065;
	tp.second=65;
	signalTable.insert(tp);
	tp.first=40035;
	tp.second=35;
	signalTable.insert(tp);
	tp.first=40036;
	tp.second=36;
	signalTable.insert(tp);
	tp.first=40062;
	tp.second=62;
	signalTable.insert(tp);
	tp.first=9999;
	tp.second=0;
	signalTable.insert(tp);
	tp.first=40010;
	tp.second=10;
	signalTable.insert(tp);
	tp.first=40072;
	tp.second=72;
	signalTable.insert(tp);
	tp.first=40066;
	tp.second=66;
	signalTable.insert(tp);
	tp.first=40009;
	tp.second=9;
	signalTable.insert(tp);
	tp.first=40067;
	tp.second=67;
	signalTable.insert(tp);
	tp.first=40007;
	tp.second=7;
	signalTable.insert(tp);
	tp.first=40001;
	tp.second=1;
	signalTable.insert(tp);
	tp.first=40061;
	tp.second=61;
	signalTable.insert(tp);
	tp.first=40047;
	tp.second=47;
	signalTable.insert(tp);
	tp.first=40051;
	tp.second=51;
	signalTable.insert(tp);
	tp.first=40029;
	tp.second=29;
	signalTable.insert(tp);
	tp.first=40027;
	tp.second=27;
	signalTable.insert(tp);
	tp.first=40019;
	tp.second=19;
	signalTable.insert(tp);
	tp.first=40004;
	tp.second=4;
	signalTable.insert(tp);
	tp.first=40008;
	tp.second=8;
	signalTable.insert(tp);
	tp.first=40052;
	tp.second=52;
	signalTable.insert(tp);
	tp.first=40025;
	tp.second=25;
	signalTable.insert(tp);
	tp.first=40006;
	tp.second=6;
	signalTable.insert(tp);
	tp.first=40016;
	tp.second=16;
	signalTable.insert(tp);
	tp.first=40046;
	tp.second=46;
	signalTable.insert(tp);
	tp.first=40014;
	tp.second=14;
	signalTable.insert(tp);
	tp.first=40044;
	tp.second=44;
	signalTable.insert(tp);
	tp.first=40011;
	tp.second=11;
	signalTable.insert(tp);
	tp.first=40073;
	tp.second=73;
	signalTable.insert(tp);
	tp.first=40023;
	tp.second=23;
	signalTable.insert(tp);
	tp.first=40013;
	tp.second=13;
	signalTable.insert(tp);
	tp.first=40033;
	tp.second=33;
	signalTable.insert(tp);
	tp.first=40030;
	tp.second=30;
	signalTable.insert(tp);
	tp.first=40028;
	tp.second=28;
	signalTable.insert(tp);
	tp.first=40070;
	tp.second=70;
	signalTable.insert(tp);
	tp.first=40020;
	tp.second=20;
	signalTable.insert(tp);
	tp.first=40005;
	tp.second=5;
	signalTable.insert(tp);
	tp.first=40026;
	tp.second=26;
	signalTable.insert(tp);
	tp.first=40031;
	tp.second=31;
	signalTable.insert(tp);
	tp.first=40050;
	tp.second=50;
	signalTable.insert(tp);
	tp.first=40053;
	tp.second=53;
	signalTable.insert(tp);
	tp.first=40037;
	tp.second=37;
	signalTable.insert(tp);
	tp.first=40003;
	tp.second=3;
	signalTable.insert(tp);
	tp.first=40058;
	tp.second=58;
	signalTable.insert(tp);
	tp.first=40018;
	tp.second=18;
	signalTable.insert(tp);
	tp.first=40043;
	tp.second=43;
	signalTable.insert(tp);
	tp.first=40063;
	tp.second=63;
	signalTable.insert(tp);
	tp.first=40071;
	tp.second=71;
	signalTable.insert(tp);
	tp.first=40054;
	tp.second=54;
	signalTable.insert(tp);
	tp.first=40056;
	tp.second=56;
	signalTable.insert(tp);
	tp.first=40064;
	tp.second=64;
	signalTable.insert(tp);
	tp.first=40022;
	tp.second=22;
	signalTable.insert(tp);
	tp.first=30000;
	tp.second=74;
	signalTable.insert(tp);
	tp.first=30001;
	tp.second=75;
	signalTable.insert(tp);
	tp.first=30002;
	tp.second=76;
	signalTable.insert(tp);
	tp.first=30003;
	tp.second=77;
	signalTable.insert(tp);
	tp.first=30004;
	tp.second=78;
	signalTable.insert(tp);
	tp.first=30005;
	tp.second=79;
	signalTable.insert(tp);
	tp.first=30006;
	tp.second=80;
	signalTable.insert(tp);
	tp.first=30007;
	tp.second=81;
	signalTable.insert(tp);
	tp.first=30008;
	tp.second=82;
	signalTable.insert(tp);
	tp.first=30009;
	tp.second=83;
	signalTable.insert(tp);
	tp.first=30010;
	tp.second=84;
	signalTable.insert(tp);
	tp.first=30011;
	tp.second=85;
	signalTable.insert(tp);
	tp.first=30012;
	tp.second=86;
	signalTable.insert(tp);
	tp.first=30013;
	tp.second=87;
	signalTable.insert(tp);
	tp.first=30014;
	tp.second=88;
	signalTable.insert(tp);
	tp.first=30015;
	tp.second=89;
	signalTable.insert(tp);
	tp.first=30016;
	tp.second=90;
	signalTable.insert(tp);
	tp.first=30017;
	tp.second=91;
	signalTable.insert(tp);
	tp.first=30018;
	tp.second=92;
	signalTable.insert(tp);
	tp.first=30019;
	tp.second=93;
	signalTable.insert(tp);
	tp.first=30020;
	tp.second=94;
	signalTable.insert(tp);
	tp.first=30021;
	tp.second=95;
	signalTable.insert(tp);
	tp.first=30022;
	tp.second=96;
	signalTable.insert(tp);
	tp.first=30023;
	tp.second=97;
	signalTable.insert(tp);
	tp.first=30024;
	tp.second=98;
	signalTable.insert(tp);
	tp.first=30025;
	tp.second=99;
	signalTable.insert(tp);
	tp.first=30026;
	tp.second=100;
	signalTable.insert(tp);
	tp.first=30027;
	tp.second=101;
	signalTable.insert(tp);
	tp.first=30028;
	tp.second=102;
	signalTable.insert(tp);
	tp.first=30029;
	tp.second=103;
	signalTable.insert(tp);
	tp.first=30030;
	tp.second=104;
	signalTable.insert(tp);
	tp.first=30031;
	tp.second=105;
	signalTable.insert(tp);
	tp.first=30032;
	tp.second=106;
	signalTable.insert(tp);
	tp.first=30033;
	tp.second=107;
	signalTable.insert(tp);
	tp.first=30034;
	tp.second=108;
	signalTable.insert(tp);
	tp.first=30035;
	tp.second=109;
	signalTable.insert(tp);
	tp.first=30036;
	tp.second=110;
	signalTable.insert(tp);
	tp.first=30037;
	tp.second=111;
	signalTable.insert(tp);
	tp.first=30038;
	tp.second=112;
	signalTable.insert(tp);
	tp.first=30039;
	tp.second=113;
	signalTable.insert(tp);
	tp.first=30040;
	tp.second=114;
	signalTable.insert(tp);
	tp.first=30041;
	tp.second=115;
	signalTable.insert(tp);
	tp.first=30042;
	tp.second=116;
	signalTable.insert(tp);
	tp.first=30043;
	tp.second=117;
	signalTable.insert(tp);
	tp.first=30044;
	tp.second=118;
	signalTable.insert(tp);
	tp.first=30045;
	tp.second=119;
	signalTable.insert(tp);

    //string filename;
    //fin.open("test1.txt");
    fin.open(filename.c_str());

    if(fin.fail())
	{
		cout<<"Cannot open the file "<<filename<<endl;
        return false;
	}
    int res = parse();

    fin.close();
	fin.clear();

    if(res == 1) {
        return true;
    } else {
        return false;
    }
}


bool callCompiler(string srcFileName) {
    Global_Reset(srcFileName);

    bool result = complierParser(srcFileName);

    if(result) {
        AssReg();//分配寄存器
        EleminateContLable();//消除连续标号
        GenFunBlockASM();//生成汇编代码块

        //string resFileName ="res.asm";
        int index = srcFileName.find_last_of('.');
        srcFileName.replace(index+1, srcFileName.size()-index-1, "asm");

        cout<<"asm file: "<<srcFileName<<endl;

        Write_ASM_File(srcFileName.c_str());//写入asm文件
    }

    err_lst.close();

    return result;
}

#endif
