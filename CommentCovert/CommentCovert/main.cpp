#include "CommentCovert.h"
void test()
{
	FILE *pIn = NULL;
	FILE *pOut = NULL;
	pIn = fopen("input.c", "r");//���ķ�ʽ��
	if (pIn == NULL)
	{
		perror("open file for read");
		exit(EXIT_FAILURE);
	}
	pOut = fopen("output.c", "w");//д�ķ�ʽ���ļ�
	if (pOut == NULL)
	{
		perror("open file for write");
		exit(EXIT_FAILURE);
		fclose(pIn);
		pIn = NULL;
	}
	CommentCovert(pIn, pOut);
	fclose(pOut);
	pOut = NULL;
	fclose(pIn);
	pIn = NULL;
}
int main()
{
	test();
	return 0;
}