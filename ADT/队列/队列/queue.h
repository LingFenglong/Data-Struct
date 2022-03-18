#pragma warning(disable : 4996)
#pragma warning(disable : 6031)

#include  <stdio.h>
#include <assert.h>
#include <stdlib.h>
#define ElementType int

#ifndef __Queue_h__

struct QueueRecord;
typedef struct QueueRecord* Queue;

int IsEmpty(Queue Q);

int IsFull(Queue Q);

Queue CreateQueue(int MaxElement);

void DisposeQueue(Queue Q);

void MakeEmpty(Queue Q);

void Enqueue(ElementType X, Queue Q);

ElementType Front(Queue Q);

void Dequeue(Queue Q);

ElementType FrontAndDequeue(Queue Q);


#endif

struct QueueRecord
{
    int Capacity;
    int Front;
    int Rear;
    int Size;
    ElementType* Array;
};