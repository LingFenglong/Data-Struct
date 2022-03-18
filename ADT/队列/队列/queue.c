#pragma warning(disable : 4996)
#pragma warning(disable : 6031)

#include "queue.h"

int IsEmpty(Queue Q)
{
    return Q->Size == 0;
    // == -> return 1
    // != -> return 0
}

void MakeEmpty(Queue Q)
{
    Q->Size = 0;
    Q->Front = 1;   // 队首
    Q->Rear = 0;    // 队尾
}


Queue CreateQueue(int MaxElement)
{
    Queue Q = (Queue*)malloc(sizeof(struct QueueRecord));
    assert(Q);
    Q->Array = (ElementType*)malloc(sizeof(ElementType) * MaxElement);
    assert(Q->Array);
    MakeEmpty(Q);
    Q->Capacity = MaxElement;
    return Q;
}

int IsFull(Queue Q)
{
    return Q->Capacity == Q->Size;
}

void Enqueue(ElementType X, Queue Q)
{
    if (IsFull(Q))
    {
        printf("Queue is full!");
    }
    else
    {
        // 入队
        if (Q->Rear == Q->Capacity - 1)
        {
            Q->Rear = 0;
            Q->Array[Q->Rear] = X;
        }
        else
        {
            Q->Array[++Q->Rear] = X;
        }
        Q->Size++;
    }
}

ElementType Front(Queue Q)
{
    return Q->Array[Q->Front];
}

void Dequeue(Queue Q)
{
    if (Q->Front == Q->Capacity - 1)
    {
        Q -> Front = 0;
    }
    else
    {
        Q->Front++;
    }
    Q->Size--;
}

ElementType FrontAndDequeue(Queue Q)
{
    ElementType ret = Front(Q);
    Dequeue(Q);
    return ret;
}

void DisposeQueue(Queue Q)
{
    free(Q->Array);
    free(Q);
    // 自行   Q = NULL
}