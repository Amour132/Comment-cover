#ifndef _CommentCovert__
#define _CommentCovert__
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
enum State //¶¨ÒåÖÖ×´Ì¬
{
	NUL_State,//ÎŞ×´Ì¬
	C_State,//C×¢ÊÍ×´Ì¬
	Cpp_State,//C++×¢ÊÍ×´Ì¬
	End_State//½áÊø×´Ì¬
};
void CommentCovert(FILE *pIn, FILE *pOut);//×¢ÊÍ×ª»»
void Do_NUL_State(FILE *pIn, FILE *pOut, enum State *ps); //ÎŞ×´Ì¬º¯Êı
void Do_C_State(FILE *pIn, FILE *pOut, enum State *ps); //C×¢ÊÍ
void Do_Cpp_State(FILE *pIn, FILE *pOut, enum State *ps);//C++×¢ÊÍ
//
#endif //_CommentCovert__