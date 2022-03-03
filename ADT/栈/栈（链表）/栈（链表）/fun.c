#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"

int IsEmpty(Stack S)
{
	return S->Next == NULL;
	// Õ»Í·
}

Stack CreatStack()
{
	Stack P;
	P = (Stack)malloc(sizeof(struct Node));
	assert(P);
	P->Next = NULL;
	MakeEmpty(P);
	return P;
}

void MakeEmpty(Stack S)
{
	if (S == NULL)
	{
		printf("ÒÑÎªNULL");
	}
	else
	{
		while (!IsEmpty(S))
		{
			Pop(S);
		}
	}
}

void Pop(Stack S)
{
	assert(S->Next);
	// del
	Stack TempS = S->Next;
	S->Next = S->Next->Next;
	free(TempS);
}

ElementType Top(Stack S)
{
	assert(S->Next);
	return S->Next->Element;
}

void Push(ElementType x, Stack S)
{
	Stack P = CreatStack();
	assert(P);
	P->Element = x;
	P->Next = S->Next;
	S->Next = P;
}
