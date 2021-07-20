#ifndef TESTSEMCODE_H
#define TESTSEMCODE_H
#pragma once
//测试中间代码

//#include "yyparse.h"


int file_num=0;

char* ConvertString(string s)
{
	int len=s.length();
	if(len==0) return 0;
	char *ret=new char[len+1];
	int i;
	for(i=0;i<len;i++) {
		ret[i]=s[i];
		//cout<<s[i]<<endl;
	}
	ret[i]='\0';
	return ret;
}

char *GenPathName()
{
	char a[10];
	_itoa_s(file_num,a,10);
	file_num++;
	string s="sem_code";
	s+=a;s+=".txt";
	return ConvertString(s);
}

string ConvertOperatorNum(Operator_NUM ON) //转换为字符串
{
	string s="";
	if(ON.isLabel)//标号
	{
		return ON.label;
	}
	else if(ON.Var.IsImmNum)
	{
		char a[10];
		_itoa_s(ON.Var.imm_num,a,10);
		s=a;
	}
	else if(ON.Var.IsTempVar)
	{
		return ON.Var.VT.TempVar_ID;
	}
	else
	{
		return ON.Var.VP.VarName;
	}
	return s;
}

string ConvertQuadCode(QUAD_EXP_ROW QER)
{
	string s="";
	if(QER.OP.compare("LABEL")==0)
	{
		s=ConvertOperatorNum(QER.RS);
		s+=":";
	}
	else if(QER.OP.compare("ADD")==0)
	{
		s="ADD:";
		s+=ConvertOperatorNum(QER.RS);
		s+=",";
		s+=ConvertOperatorNum(QER.RT);
		s+=",";
		s+=ConvertOperatorNum(QER.RD);
	}
	else if(QER.OP.compare("SUB")==0)
	{
		s="SUB:";
		s+=ConvertOperatorNum(QER.RS);
		s+=",";
		s+=ConvertOperatorNum(QER.RT);
		s+=",";
		s+=ConvertOperatorNum(QER.RD);
	}
	else if(QER.OP.compare("MLT")==0)
	{
		s="MLT:";
		s+=ConvertOperatorNum(QER.RS);
		s+=",";
		s+=ConvertOperatorNum(QER.RT);
		s+=",";
		s+=ConvertOperatorNum(QER.RD);
	}
	else if(QER.OP.compare("DIV")==0)
	{
		s="DIV:";
		s+=ConvertOperatorNum(QER.RS);
		s+=",";
		s+=ConvertOperatorNum(QER.RT);
		s+=",";
		s+=ConvertOperatorNum(QER.RD);
	}
	else if(QER.OP.compare("MOD")==0)
	{
		s="MOD:";
		s+=ConvertOperatorNum(QER.RS);
		s+=",";
		s+=ConvertOperatorNum(QER.RT);
		s+=",";
		s+=ConvertOperatorNum(QER.RD);
	}
	else if(QER.OP.compare("MOV")==0)
	{
		s="MOV:";
		s+=ConvertOperatorNum(QER.RS);
		s+=",";
		s+=ConvertOperatorNum(QER.RD);
	}
	else if(QER.OP.compare("SLT")==0)
	{
		s="SLT:";
		s+=ConvertOperatorNum(QER.RS);
		s+=",";
		s+=ConvertOperatorNum(QER.RT);
		s+=",";
		s+=ConvertOperatorNum(QER.RD);
	}
	else if(QER.OP.compare("BEQ")==0)
	{
		s="BEQ:";
		s+=ConvertOperatorNum(QER.RS);
		s+=",";
		s+=ConvertOperatorNum(QER.RT);
		s+=",";
		s+=ConvertOperatorNum(QER.RD);
	}
	else if(QER.OP.compare("GOTO")==0)
	{
		s="GOTO:";
		s+=ConvertOperatorNum(QER.RD);
	}
	else if(QER.OP.compare("BNE")==0)
	{
		s="BNE:";
		s+=ConvertOperatorNum(QER.RS);
		s+=",";
		s+=ConvertOperatorNum(QER.RT);
		s+=",";
		s+=ConvertOperatorNum(QER.RD);
	}
	else if(QER.OP.compare("LDA")==0)
	{
		s="LDA:";
		s+=ConvertOperatorNum(QER.RS);
		s+=",";
		s+=ConvertOperatorNum(QER.RD);
	}
	else if(QER.OP.compare("CALL")==0)
	{
		s="CALL:";
		s+=ConvertOperatorNum(QER.RS);
		s+=",";
		s+=ConvertOperatorNum(QER.RD);
	}
	else if(QER.OP.compare("LOD")==0)
	{
		s="LOD:";
		s+=ConvertOperatorNum(QER.RS);
		s+=",";
		s+=ConvertOperatorNum(QER.RD);
	}
	else if(QER.OP.compare("SAV")==0)
	{
		s="SAV:";
		s+=ConvertOperatorNum(QER.RS);
		s+=",";
		s+=ConvertOperatorNum(QER.RD);
	}
	else if(QER.OP.compare("OR")==0)
	{
		s="OR:";
		s+=ConvertOperatorNum(QER.RS);
		s+=",";
		s+=ConvertOperatorNum(QER.RT);
		s+=",";
		s+=ConvertOperatorNum(QER.RD);
	}
	else if(QER.OP.compare("AND")==0)
	{
		s="AND:";
		s+=ConvertOperatorNum(QER.RS);
		s+=",";
		s+=ConvertOperatorNum(QER.RT);
		s+=",";
		s+=ConvertOperatorNum(QER.RD);
	}
	else if(QER.OP.compare("NOT")==0)
	{
		s="ADD:";
		s+=ConvertOperatorNum(QER.RS);
		s+=",";
		s+=ConvertOperatorNum(QER.RD);
	}
	else if(QER.OP.compare("XOR")==0)
	{
		s="XOR:";
		s+=ConvertOperatorNum(QER.RS);
		s+=",";
		s+=ConvertOperatorNum(QER.RT);
		s+=",";
		s+=ConvertOperatorNum(QER.RD);
	}
	else if(QER.OP.compare("LSHIFT")==0)
	{
		s="LSHIFT:";
		s+=ConvertOperatorNum(QER.RS);
		s+=",";
		s+=ConvertOperatorNum(QER.RT);
		s+=",";
		s+=ConvertOperatorNum(QER.RD);
	}
	else if(QER.OP.compare("RSHIFT")==0)
	{
		s="RSHIFT:";
		s+=ConvertOperatorNum(QER.RS);
		s+=",";
		s+=ConvertOperatorNum(QER.RT);
		s+=",";
		s+=ConvertOperatorNum(QER.RD);
	}
	else if(QER.OP.compare("PARAM")==0)
	{
		s="PARAM:";
		s+=ConvertOperatorNum(QER.RS);
		s+=",";
		s+=ConvertOperatorNum(QER.RD);
	}
	else if(QER.OP.compare("RET")==0)
	{
		s="RET:";
		s+=ConvertOperatorNum(QER.RD);
	}
	else if(QER.OP.compare("RETN")==0)
	{
		s="RETN:";
	}
	else if(QER.OP.compare("GETO")==0)
	{
		s="GOTO:";
		s+=ConvertOperatorNum(QER.RD);
	}
	else
	{
	}
	return s;
}

#endif //TESTSEMCODE_H
