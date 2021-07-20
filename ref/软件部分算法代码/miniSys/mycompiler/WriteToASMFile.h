#ifndef WRITETOASMFILE_H
#define WRITETOASMFILE_H
#pragma once

#include "FunctionModuleASM.h"
#include "TestSemCode.h"
//#include "FunctionForest.h"
//#include "SEM_GLOBAL_INF.H"
//#include "RegDisattribute.h"

//生成最终的ASM文件

/*
//全局用于保存函数模块的代码
vector<Fun_ASM>  FA_ASM;
//函数块
void TransForest_REGToFunASM(Forest_REG &FR,Fun_ASM &FA)//进行函数中间代码到汇编的翻译
*/


/*
//函数森林
vector<Forest>  Fun_Sem_Forest;
vector<Forest_REG>  Fun_Sem_Forest_REG;//带寄存器分配的REG
//函数中间翻译的森林群
*/
//先进行寄存器分配

void AssReg()
{
	for(int i=0;i<Fun_Sem_Forest.size();i++)
	{
		Forest_REG FR;FR.SC.CODE.clear();
		DisattributeReg(Fun_Sem_Forest[i],FR);//Reg分配
		Fun_Sem_Forest_REG.push_back(FR);//加入寄存器分配后的森林
	}
	/*for(int j=0;j<Fun_Sem_Forest_REG.size();j++)//测试寄存器分配
	{
		fstream fgp;
		fgp.open(GenPathName(),std::ios::out|std::ios::binary);
		Forest_REG &FR=Fun_Sem_Forest_REG[j];
		for(int i=0;i<FR.SC.CODE.size();i++)
		{
			fgp<<ConvertString(ConvertQuadCode(FR.SC.CODE[i]))<<"\r\n";//测试寄存器分配
		}
	}*/
}


//消除连续的标号
void EleminateContLable()//消除连续标号,仅适用于中间代码
{
	int i=0;
	for(i=0;i<Fun_Sem_Forest_REG.size();i++)//遍历每一个函数树
	{
		Forest_REG &FR=Fun_Sem_Forest_REG[i];
		SEM_CODE_REG &SC=FR.SC;//中间代码
		//vector<QER_ASM> CODE;
		vector<QER_ASM> &CODE=SC.CODE;
		for(int j=0;j<CODE.size();j++)//扫描中间代码
		{
			if(j<CODE.size()-1)
			{
				if(CODE[j].OP.compare("LABEL")==0&&CODE[j+1].OP.compare("LABEL")==0)
				{
					//开始重新扫描，消除连续重复标号
					string L1=CODE[j].RS.ON.label;
					string L2=CODE[j+1].RS.ON.label; 
					//替换第一个下标，解决下面连续问题
					CODE[j].OP="NOP";//用空指令替换(只要没有的指令都可以,就是不翻译)
					for(int x=0;x<CODE.size();x++)//替换算法开始
					{
						if(CODE[x].OP.compare("BEQ")==0)
						{
							if(CODE[x].RD.ON.label.compare(L1)==0)
							{
								CODE[x].RD.ON.label=L2;
							}
						}
						else if(CODE[x].OP.compare("BNE")==0)
						{
							if(CODE[x].RD.ON.label.compare(L1)==0)
							{
								CODE[x].RD.ON.label=L2;
							}
						}
						else if(CODE[x].OP.compare("GOTO")==0)
						{
							if(CODE[x].RD.ON.label.compare(L1)==0)
							{
								CODE[x].RD.ON.label=L2;
							}
						}
						else if(CODE[x].OP.compare("CALL")==0)
						{
							if(CODE[x].RS.ON.label.compare(L1)==0)
							{
								CODE[x].RS.ON.label=L2;
							}
						}
						else if(CODE[x].OP.compare("LABEL")==0)
						{
							if(CODE[x].RS.ON.label.compare(L1)==0)
							{
								CODE[x].RS.ON.label=L2;
							}
						}
						else
						{
						}
					}
				}
			}
		}
	}
}

//再产生函数块代码
void GenFunBlockASM()
{
	for(int i=0;i<Fun_Sem_Forest_REG.size();i++)
	{
		Fun_ASM FA;//保存函数代码
		TransForest_REGToFunASM(Fun_Sem_Forest_REG[i],FA);//产生函数体代码
		FA_ASM.push_back(FA);FA.ASM.clear();
	}
}

//char* ConvertString(string s)
//{
//	int len=s.length();
//	if(len==0) return 0;
//	char *ret=new char[len+1];
//	int i;
//	for(i=0;i<len;i++) {
//		ret[i]=s[i];
//		//cout<<s[i]<<endl;
//	}
//	ret[i]='\0';
//	return ret;
//}

//启动写入模块
void Write_ASM_File(const char *path)
{
	//建立文件流
	fstream fs;
	fs.open(path,std::ios::out|std::ios::binary|std::ios::trunc);
	if(!fs)
	{
		if(!isDebug) {
			cout<<"创建文件失败.asm"<<"\r\n";
		} else {
			err_lst<<"创建文件失败.asm"<<"\r\n";
		}
		
		return;
	}
	//下面，先写入数据段定义
	fs<<"DATA SEG"<<"\r\n";
	fs<<"      "<<"\r\n";
	fs<<"DATA ENDS"<<"\r\n";
	//代码段开始
	fs<<"CODE SEG"<<"\r\n";
	fs<<"ORG_CODE 0000H"<<"\r\n";
	fs<<"start:"<<"\r\n";
	//初始化sp,$s9(top)为全局数据后面
	//fs<<";初始化sp,$s9(top)为全局数据后面\r\n";
	char gl_off[10];
	HexTrans(global_offset,gl_off);//itoa(global_offset,gl_off,10);
	fs<<"ORI $sp,$zero,"<<gl_off<<"\r\n";
	fs<<"ORI $s9,$zero,"<<gl_off<<"\r\n";
	//fs<<";初始化sp,$s9(top)完毕\r\n";
	//
	//检测有无main函数
	int i=0;
	bool ismain=false;//main
	vector<string> main_code;
	for(i=0;i<FA_ASM.size();i++)
	{
		if(FA_ASM[i].Name.compare("main")==0)
		{
			main_code=FA_ASM[i].ASM;//取main函数代码
			ismain=true;
			break;
		}
	}
	if(ismain)//main函数存在
	{
		fs<<"JAL main"<<"\r\n";
	}
	char *nlb=ConvertString(Gen_New_Label());
	fs<<nlb<<":\r\n";//产生一个新标号
	fs<<"J "<<nlb<<"\r\n";
	//动态停机
	if(ismain)//main入口
	{
		fs<<"main:"<<"\r\n";
		//产生体代码
		for(int i=0;i<main_code.size();i++)
		{
			fs<<ConvertString(main_code[i])<<"\r\n";
		}
	}
	//main函数产生完毕
	//产生其他子程序的代码
	for(i=0;i<FA_ASM.size();i++)
	{
		if(FA_ASM[i].Name.compare("main")!=0)//不再翻译main函数
		{
			fs<<ConvertString(FA_ASM[i].Name)<<":\r\n";//函数标号
			vector<string> &sub_code=FA_ASM[i].ASM;
			for(int j=0;j<sub_code.size();j++)//产生体
			{
				fs<<ConvertString(sub_code[j])<<"\r\n";
			}
		}
	}
	//子函数体产生完毕
	//检查是否有中断INT0,INT 1
	bool isINT0=false;
	bool isINT1=false;
	for(i=0;i<FA_ASM.size();i++)
	{
		if(FA_ASM[i].Name.compare("interuptServer0")==0)
		{
			isINT0=true;
		}
		else if(FA_ASM[i].Name.compare("interuptServer1")==0)
		{
			isINT1=true;
		}
	}
	fs<<"ORG_CODE 07F8H"<<"\r\n";//INT0
	if(isINT0)
	{
		fs<<"J interuptServer0"<<"\r\n";
	}
	else
	{
		fs<<"JR $i0"<<"\r\n";
	}
	fs<<"ORG_CODE 07FCH"<<"\r\n";//INT1
	if(isINT1)
	{
		fs<<"J interuptServer1"<<"\r\n";
	}
	else
	{
		fs<<"JR $i1"<<"\r\n";
	}
	//代码结束
	fs<<"end start"<<"\r\n";
	fs<<"CODE ENDS"<<"\r\n";
	fs.flush();
	fs.close();
}

void Global_Reset(string srcFile)//全局复位
{
	while(!while_stack.empty()){while_stack.pop();}
	//if(!(!err_lst)) err_lst.close();
	FA_ASM.clear();
    FC_=Function_Compound_();
	file_num=0;
	Fun_Sem_Forest.clear();
	Fun_Sem_Forest_REG.clear();
	Global_Fun_type=VOID;
	global_offset=0;
	Label_num=0;
	local_offset=0;
	MST.Reset();
	Temp_Var_num=0;
	WC_=While_Compound_();
	while(!yysymbol.empty()){yysymbol.pop();}
	//cc=0;//读头位置
	//yytext=0;//字符
	yylineno=1;//跟踪行号

    isDebug = false; //是否为测试输出

	if(!isDebug) {
        //const char* errLogFile = "error.log";
        int index = srcFile.find_last_of('/');
        srcFile.replace(index+1, srcFile.size()-index-1, "error.log");

        err_lst.open(srcFile.c_str(), ios::out);
		if(err_lst.fail()) {
			cout<<"can not open error log file!"<<endl;
		}
	}
}
#endif //WRITETOASMFILE_H
