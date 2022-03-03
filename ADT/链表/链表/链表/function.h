#ifndef _function_H
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Node;
typedef struct Node Node;
typedef Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

// �����ÿ�
List MakeEmpty(const List L);

// �����Ƿ�Ϊ�ձ�
int IsEmpty(const List L);

// �����Ƿ�Ϊ���һ��λ��
int IsLast(const Position P, List L);

// ����
Position Find(const int X, const List L);

// ɾ��
void Delete(int X, List L);

// ��ǰ��
Position FindPrevious(int X, List L);

// ���뵽��P��ָλ��֮��
void Insert(int X, List L, Position P);

// ɾ����
void DeleteList(List L);

// ����ͷ��λ��
Position Header(List L);

// ���ص�һ��λ��
Position First(List L);

// ���غ��λ��
Position Advance(Position P);

// ����Ԫ��ֵ
int Retrieve(Position P);

// �������
Position CreateNode();

// ��������
Position CreatNodeList(unsigned int N);

void PrintNodeList(List L);
#endif

struct Node
{
	int Element;
	Position Next;
};