#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"

Stack CreatStack(ElementType Elements)
{
	Stack S = (Stack)malloc(sizeof(struct StackRecord));
	assert(S);
	S->Arry = (ElementType*)malloc(sizeof(ElementType) * MinStackSize);
	assert(S->Arry);
	S->Capacity = MinStackSize;
	MakeEmpty(S);
	return S;
}

void MakeEmpty(Stack S)
{
	S->TopOfStack = -1;
}

int IsEmpty(Stack S)
{
    if (S->TopOfStack == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int IsFull(Stack S)
{
    if (S->Capacity == S->TopOfStack + 1)
    {
        return 1;   // FULL
    }
    else
    {
        return 0;   // !FULL
    }
}

void Push(ElementType x, Stack S)
{
    S->Arry[++(S->TopOfStack)] = x;
}

void Pop(Stack S)
{
    (S->TopOfStack)--;
}

ElementType Top(Stack S)
{
    return S->Arry[S->TopOfStack];
}

ElementType TopAndPop(Stack S)
{
    Top(S);
    Pop(S);
}

void DisposeStack(Stack S)
{
    free(S);
    S = NULL;
}
