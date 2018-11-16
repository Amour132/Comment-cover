#include "CommentCovert.h"
void Do_NUL_State(FILE *pIn, FILE *pOut, enum State *ps)
{
	int frist = fgetc(pIn);//��ȡһ���ַ�
	switch (frist)
	{
	case '/'://�����/���п��ܽ���ע��״̬
	{
				 int second = fgetc(pIn);//�ٶ�ȡһ���ַ�
				 switch (second)
				 {
				 case '*'://��*����Cע��״̬
				 {
							  fputc('/', pOut);
							  fputc('/', pOut);//��� // 
							  *ps = C_State;//״̬ת����Cע��
				 }
					 break;
				 case '/'://  ��/����C++��ע��״̬
				 {
							  fputc(frist, pOut);
							  fputc(second, pOut);
							  *ps = Cpp_State;//״̬ת����C++״̬
				 }
					 break;
				 default://������������
				 {
							 fputc(frist, pOut);
							 fputc(second, pOut);
				 }
					 break;
				 }
	}
		break;
	case EOF://����EOF�����
	{
				 *ps = End_State;
	}
		break;
	default://�������
	{
				fputc(frist, pOut);
	}
		break;
	}
}
void Do_Cpp_State(FILE *pIn, FILE *pOut, enum State *ps)//C++״̬
{
	int frist = fgetc(pIn);
	switch (frist)
	{
	case '\n'://��һ���ַ�����ǻ���
	{
				  *ps = NUL_State;//������ע��״̬
	}
		break;
	case EOF://�п�������EOF ����
	{
				 *ps = End_State;
	}
		break;
	default:
	{
			   fputc(frist, pOut);
	}
		break;
	}
}
void Do_C_State(FILE *pIn, FILE *pOut, enum State *ps)//Cע��״̬
{
	int frist = fgetc(pIn);
	switch (frist)
	{
	case '*'://����* ˵���п��ܻ����
	{
				 int second = fgetc(pIn);//��ȡ�ڶ����ַ�
				 switch (second)
				 {
				 case '/'://�� /  ����ע�ͽ���
				 {
							  int thrid = fgetc(pIn);//�Ƿ��е��жϼ�����
							  if (thrid == '\n')
							  {
								  fputc(thrid, pOut);
							  }
							  else
							  {
								  fputc('\n', pOut);
								  ungetc(thrid, pIn);
							  }
							  *ps = NUL_State;//ע�����ת������ע��״̬
				 }
					 break;
				 default://�������* ��һ������/  �Ǿͱ����* �Ż�ȥ��ֹ�ͽ�����* ����
				 {
							 fputc(frist, pOut);
							 ungetc(second, pIn);   //���ַ��Ż���   
				 }
					 break;
				 }
	}
		break;
	case '\n'://ע���ڵĻ������
	{
				  fputc(frist, pOut);
				  fputc('/', pOut);
				  fputc('/', pOut);
	}
		break;
	default:
	{
			   fputc(frist, pOut);
	}
		break;
	}
}
void CommentCovert(FILE *pIn, FILE *pOut)
{
	enum State state = NUL_State;
	while (state != End_State)
	{
		switch (state)
		{
		case NUL_State:
			Do_NUL_State(pIn, pOut, &state);
			break;
		case C_State:
			Do_C_State(pIn, pOut, &state);
			break;
		case Cpp_State:
			Do_Cpp_State(pIn, pOut, &state);
			break;
		default:
			break;
		}
	}
}