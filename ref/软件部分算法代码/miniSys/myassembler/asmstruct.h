#ifndef ASMSTRUCT_H
#define ASMSTRUCT_H
struct My_Stack  //�����������Ͷ���ջ
{
  int Depth[STACK_SIZE];
  int Top;
};
struct My_Token  //�������룺�洢�����ȡ��һ�����ʵ���Ϣ
{
   int  ID;                  //��������
   char Content[COMMOM_SIZE];       //��������
   int  Idx;                 //�±� 
}; 
struct My_Data   //���ݱ�
{
	int Addr;                //���ݵ�ַ
	char Value[DATA_SIZE];   //��ֵ
	My_Data *Next;
};
struct My_Var    //������ʾ���ű��洢��������Ϣ
{
	int Addr;                //������ַ
    char Name[COMMOM_SIZE];  //��������   
    My_Var *Next;
};

struct My_SegID  //ָ���ţ��洢�����Ϣ
{
   int Addr;                 //ָ���ַ(���ֵ)
   char Name[COMMOM_SIZE];   //�������
   My_SegID *Next;
};
struct My_Com	 //ָ����洢ָ����Ϣ
{
	int  Addr;               //ָ���ַ
	char JSegName[6];        //ָ���а�����ָ��������
	char Content[COMMOM_SIZE];      //���ݲ���	
	int  TypeOfCom;          //ָ������
	int  NumOfCom;           //ָ����
	char Com[COM_SIZE];      //��������ָ��
	My_Com *Next;            //��һ��ָ���ַ
};

struct My_Back   //�����
{
	My_Com  *Com;            //��Ҫ����ָ��ĵ�ַ
	char Name[COMMOM_SIZE];         //���
	int lineNum;             //�����е�λ��
	My_Back *Next;
};
struct My_Op     //���Ƿ���
{
	char Op[OP_SIZE];
	char Name[8];
};
struct My_Func   //���ܺű�
{
	char Func[FUNC_SIZE];
	char Name[8];
};
struct My_Reg    //�Ĵ�����
{
	char Reg[REG_SIZE];
	char Name[10];
};
struct My_Sel    //Sel��
{
	char Sel[SEL_SIZE];
	char Name[10];
};



#endif