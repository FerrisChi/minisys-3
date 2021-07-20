#ifndef ASSEMBLER_H  
#define ASSEMBLER_H 
#include <fstream>
#include "asmconst.h"
#include "asmstruct.h"
using namespace std;
class assembler     
{
private:
	int ForcastTable[VN_NUM][VT_NUM];     //LL(1)Ԥ�������
	int SyntacticRules[RULE_NUM][RULE_DEPTH]; //MiniSys�﷨�����
	char *KeyWords[KEYWORDS_SIZE];              //�ؼ��ֱ�,ǰ����ָ������
	char FileName[COMMOM_SIZE];   //�����ļ���
   	ifstream fin;                 //�����ļ�
    ofstream dfout,cfout,sfout,efout;   //����ļ�������������ļ�,�Լ�ͳ��ָ������ļ�
    string ramFile, romFile, countFile, errFile;
	int ErrorID;            //�����ţ����崦��Ҫ�õ�
	int NumOfLine;          //�к�
	int NumOfError;         //������
	int NumOfWarning;       //������
	int CurrentDataAddr;    //��ǰ���ݵ�ַ
	int CurrentComAddr;     //��ǰָ���ַ
	int LastRule;           //ǰһ������
	int CurrentRule;        //��ǰ����
	int HasError;           //ǰһ��������û�д�  
	int NeedExplain;        //�Ƿ���Ҫע��
	int NeedSel;			//mtc0��mfc0�Ƿ���Ҫ����sel
 
	My_Stack STACK;         //����ջ
	My_Token TOKEN;         //ʶ��ĵ���
	My_Data*  DATAS_TABLE;  //���ݱ�
	My_Com*   COMS_TABLE;   //ָ���	
	My_Var*   VARS_TABLE;   //������
	My_SegID* SEGIDS_TABLE; //��ű�
	My_Back*  BACKS_TABLE;  //�����
	My_Op   OpTable[OP_TABLE_SIZE];      //���Ƿ���
	My_Func FuncTable[FUNC_TABLE_SIZE];  //���ܺű�
	My_Reg  RegTable[REG_TABLE_SIZE];    //�Ĵ�����ű�
	My_Sel  SelTable[SEL_TABLE_SIZE];    //Sel��ű�
	My_Data*  DATA_POS;     //��ǰλ�� 
	My_Com*   COM_POS;	
	My_Var*   VAR_POS;
	My_SegID* SEGID_POS;
	My_Back*  BACK_POS;
	char *CODE;//="01010101010101010101";
public:
    assembler();
    assembler(string asmFile,int needExplain);
	virtual ~assembler();
	void InitVar();                       //��ʼ�������
//���Ĳ���
    int Parser(string resultFile);                         //�﷨������
	int Scanner(int TypeOfToken);         //ɨ����
	int Translater();                     //������
	int Error(int TypeOfError);           //������
	int Warning(int TypeOfWarning);       //���洦��
//�﷨����
	int Deduction();                      //�﷨�Ƶ���
	void Succeed();                       //�ɹ�
	void Fail();                          //ʧ��
//ɨ��������
protected:
	int ScanCom();
	int ScanIdname();
	int Scan16Radix(int maxlen);
	int Scan10Radix(int maxlen);
	int Scan2Radix(int maxlen);
	int ScanReg();
	int ScanEndl();
	bool IsKeyWords(char ID[COMMOM_SIZE]);//�жϱ�־���ǲ��ǹؼ���
	bool IsSeparate(char ch);             //�ж��ǲ��Ƿָ���
	char ReadAChar();                     //��һ���ַ�
	void ReadAString(char Str[COMMOM_SIZE]);     //��һ���ַ���
	void WriteAChar(char ch);             //дһ���ַ�
	void WriteAString();                  //дһ���ַ���
//����������
protected:   
	//����ָ��
	int	TranslateRcom();
	int	TranslateSrcom();
	int	TranslateSllRcom();
	int	TranslateIcom();
	int	TranslateSicom();
	int	TranslateLwicom();
	int	TranslateJcom();
	int TranslateBcom();
	int	TranslatePcom();
	int TranslateJbcom();
	int TranslateNop();
	//����6��ָ���Լ�Sel
	int	TranslateMRCOM();
	int TranslateMFCRCOM();
	int TranslateMULRCOM();
	int TranslateSYSRCOM();
	int TranslateJRCOM();
	int TranslateBGICOM();
	int	TranslateSel();

	//����������
	int TranslateImmi();
	//�����ַ
	int	TranslateAddr();
	//�������
	int TranslateID();
	//���,���
	int InsertVar();                         //���������
	int InsertData();                        //��������
	int InsertSegID();	                     //������
	int InsertCom(char segName[6],int type); //����ָ��
	int InsertBack();                        //��������
	int SearchVar(char Name[COMMOM_SIZE]);   //�������
	int SearchSegID(char Name[COMMOM_SIZE]); //���ű�
	int SearchFirstSegID(char Name[COMMOM_SIZE]);
	int SearchOp(char Name[COMMOM_SIZE],char Op[OP_SIZE]);       //���Ƿ�
	int SearchFunc(char Name[COMMOM_SIZE],char Func[FUNC_SIZE]); //�鹦�ܺ�
	int SearchReg(char Name[COMMOM_SIZE],char Reg[REG_SIZE]);    //�Ĵ�����
	int SearchNum(char Name[COMMOM_SIZE]);                       //ָ����
	int SearchBack();                                     //����ָ��
	int SearchCP0Reg(char Name[COMMOM_SIZE],char Reg[REG_SIZE],char Sel[SEL_SIZE]);    //CP0�Ĵ�����
	int SearchSel(char Name[COMMOM_SIZE],char Sel[SEL_SIZE]);    //CP0�Ĵ�����
//��������(�����ʷ����﷨���������)
protected:
	int ErrorLexical();
	int ErrorSemantic();
	int ReadErrorToken();
	int ReadErrorSentence();
//����
protected:
	//�������
    int  WriteProgram();                  //�������    
	int  WriteData();                     //������� 
	int  WriteCount();                    //ָ��ʹ�����ͳ��
	void Write32Bit(int addr,char Line[COMMOM_SIZE],ofstream &out);
	void WriteExplain(My_Com* pCom);      //������������� 
};
#endif

