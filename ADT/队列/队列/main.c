#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include "queue.h"

int main(void)
{
    Queue Q = CreateQueue(10);
    printf("%d\n", Q->Capacity);
    printf("%d\n\n", Q->Size);

    for (int i = 0; i < 10; i++)
    {
        Enqueue(i, Q);
        printf("%d\n", Q->Size);
        printf("%d\n", FrontAndDequeue(Q));
        printf("%d\n\n", Q->Size);
    }

    printf("%s\n", IsFull(Q) ? "yes" : "no");

    DisposeQueue(Q);
    Q = NULL;
    
    return 0;
}