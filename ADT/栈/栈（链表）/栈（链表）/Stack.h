#pragma once
#define ElementType int
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#ifndef __Stack_H__

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

int IsEmpty(Stack S);

Stack CreatStack();

//void DisposeStack(Stack S);

void MakeEmpty(Stack S);

void Push(ElementType x, Stack S);

ElementType Top(Stack S);

void Pop(Stack S);

#endif



struct Node
{
	ElementType Element;
	PtrToNode Next;
};