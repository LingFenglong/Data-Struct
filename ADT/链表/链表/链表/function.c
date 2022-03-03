#define _CRT_SECURE_NO_WARNINGS 1
#include "function.h"

List MakeEmpty(const List L)
{
	// L ָ��յı�ͷ
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
	// ��1����ͷ
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
		// ���������� P = NULL
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
		// û�ҵ�
		return NULL;
	}
	return P;
}

// ���뵽��P��ָλ��֮�� O(1)
// FindPrevious ����P��ָλ��֮ǰ(����ʱ��)
void Insert(int X, List L, Position P)
{
	Position TempP = (PtrToNode)malloc(sizeof(Node));
	assert(TempP);
	// ����
	TempP->Element = X;
	TempP->Next = P->Next;
	P->Next = TempP;
}

void DeleteList(List L)
{
	// ��ͷҲɾ��
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
	// ����ͷ���
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