#ifndef _function_H
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Node;
typedef struct Node Node;
typedef Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

// 将表置空
List MakeEmpty(const List L);

// 测试是否为空表
int IsEmpty(const List L);

// 测试是否为最后一个位置
int IsLast(const Position P, List L);

// 查找
Position Find(const int X, const List L);

// 删除
void Delete(int X, List L);

// 找前驱
Position FindPrevious(int X, List L);

// 插入到由P所指位置之后
void Insert(int X, List L, Position P);

// 删除表
void DeleteList(List L);

// 返回头部位置
Position Header(List L);

// 返回第一个位置
Position First(List L);

// 返回后继位置
Position Advance(Position P);

// 返回元素值
int Retrieve(Position P);

// 创建结点
Position CreateNode();

// 创建链表
Position CreatNodeList(unsigned int N);

void PrintNodeList(List L);
#endif

struct Node
{
	int Element;
	Position Next;
};