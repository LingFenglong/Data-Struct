#pragma once
#define ElementType int
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#ifndef __Stack_H__

struct StackRecord;

typedef struct StackRecord* Stack;

int IsEmpty(Stack S);

int IsFull(Stack S);

Stack CreatStack(ElementType Elements);

// ����ջ
void DisposeStack(Stack S);

void MakeEmpty(Stack S);

void Push(ElementType x, Stack S);

ElementType Top(Stack S);

void Pop(Stack S);

ElementType TopAndPop(Stack S);

#endif

#define EmptyTOS (-1)
#define MinStackSize 5


struct StackRecord
{
	int Capacity;		// ����
	int TopOfStack;		// ջ��
	ElementType* Arry;
};