#ifndef _CommentCovert__
#define _CommentCovert__
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
enum State //������״̬
{
	NUL_State,//��״̬
	C_State,//Cע��״̬
	Cpp_State,//C++ע��״̬
	End_State//����״̬
};
void CommentCovert(FILE *pIn, FILE *pOut);//ע��ת��
void Do_NUL_State(FILE *pIn, FILE *pOut, enum State *ps); //��״̬����
void Do_C_State(FILE *pIn, FILE *pOut, enum State *ps); //Cע��
void Do_Cpp_State(FILE *pIn, FILE *pOut, enum State *ps);//C++ע��
//
#endif //_CommentCovert__