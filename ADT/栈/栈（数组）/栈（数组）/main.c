#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"

int main(void)
{
    Stack S = CreatStack(10);
    assert(S);
    int i;
    for (i = 0; i < 5; i++)
    {
        Push(i, S);
    }

    DisposeStack(S);

    for (i = 0; i < 5; i++)
    {
        printf("%d\n", Top(S));
        Pop(S);
    }

    return 0;
}