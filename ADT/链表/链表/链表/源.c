#define _CRT_SECURE_NO_WARNINGS 1
#include "function.h"

int main()
{
	int i = 0;
	Position P;
	Position const L = CreatNodeList(20);
	P = L->Next;
	for (i = 0; i < 20; i++)
	{
		P->Element = i + 1;
		P = P->Next;
	}
	PrintNodeList(L);

	return 0;
}