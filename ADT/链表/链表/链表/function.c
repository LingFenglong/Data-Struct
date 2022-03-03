#define _CRT_SECURE_NO_WARNINGS 1
#include "function.h"

List MakeEmpty(const List L)
{
	// L 指向空的表头
	Position P = L->Next;
	Position TempP;
	while (P != NULL)
	{
		TempP = P->Next;
		free(P);
		P = TempP;
	}
	L->Next = NULL;
	return L;
}

int IsEmpty(const List L)
{
	return L->Next == NULL;
}

int IsLast(const Position P, List L)
{
	return P->Next == NULL;
}

Position Find(const int X, const List L)
{
	Position P = L->Next;
	// 第1个是头
	while(P != NULL && P->Element != X)
	{
		P = P->Next;
	}
	return P;
}

void Delete(const int X, const List L)
{
	Position P, TempP;
	P = FindPrevious(X, L);
	if (P != NULL)
	{
		TempP = P->Next;
		P -> Next = TempP->Next;
		free(TempP);
		// 函数，不用 P = NULL
	}
}

Position FindPrevious(int X, List L)
{
	Position P = L;
	while (P->Next != NULL && P->Next->Element != X)
	{
		P = P->Next;
	}
	if (IsLast(P, L))
	{
		// 没找到
		return NULL;
	}
	return P;
}

// 插入到由P所指位置之后 O(1)
// FindPrevious 插入P所指位置之前(增加时间)
void Insert(int X, List L, Position P)
{
	Position TempP = (PtrToNode)malloc(sizeof(Node));
	assert(TempP);
	// 插入
	TempP->Element = X;
	TempP->Next = P->Next;
	P->Next = TempP;
}

void DeleteList(List L)
{
	// 表头也删除
	MakeEmpty(L);
	free(L);
	L = NULL;
}

Position Header(List L)
{
	return L;
}

Position First(List L)
{
	return L->Next;
}

Position Advance(Position P)
{
	return P->Next;
}

int Retrieve(Position P)
{
	return P->Element;
}

Position CreateNode()
{
	Position P = (PtrToNode)malloc(sizeof(Node));
	assert(P);
	return P;
}

Position CreatNodeList(unsigned int N)
{
	unsigned int i;
	Position L, P;
	// 申请头结点
	L = CreateNode();
	P = L;
	for (i = 0; i < N; i++)
	{
		P->Next = CreateNode();
		P = P->Next;
	}
	P->Next = NULL;
	return L;
}

void PrintNodeList(List L)
{
	Position P = L->Next;
	while (P != NULL)
	{
		printf("%d\t%p\n", P->Element, P->Next);
		P = P->Next;
	}
}