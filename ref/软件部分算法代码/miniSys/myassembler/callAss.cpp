#include "assembler.h"
#include <iostream>
#include <string>
using namespace std;

void callAssemblerParser(string srcFile, string errFile)
{
    //cout<<"��ʼ��"<<endl;

    //cout<<"asm file: "<<srcFile<<endl;

    assembler asmParser(srcFile,1);

    //cout<<"��ʼ����������ʼParser"<<endl;

    //cout<<"asm error file: "<<errFile<<endl;

    asmParser.Parser(errFile);

}
