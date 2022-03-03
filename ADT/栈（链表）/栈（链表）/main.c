#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"

int main(void)
{
	Stack S = CreatStack();
	assert(S);
	int i;
	for (i = 0; i < 5; i++)
	{
		Push(i, S);
	}


	for (i = 0; i < 5; i++)
	{
		printf("%d\n", Top(S));
		Pop(S);
	}
	return 0;
}