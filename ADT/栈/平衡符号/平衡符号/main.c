#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "Stack.h"
#include <string.h>

int main(void)
{
    Stack S = CreatStack();
    // 三种括号 {} () []
    char str[] = "()[]{}";
    int len = strlen(str);
    int i;
    for (i = 0; i < len; i++)
    {
        if (str[i] == 0)
        {
            break;
        }
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            Push(str[i], S);
        }
        else if (str[i] == '}')
        {
            if (Top(S) == '{')
            {
                Pop(S);
            }
        }
        else if (str[i] == ']')
        {
            if (Top(S) == '[')
            {
                Pop(S);
            }
        }
        else if (str[i] == ')')
        {
            if (Top(S) == '(')
            {
                Pop(S);
            }
        }
    }

    if (IsEmpty(S))
    {
        printf("有效平衡括号\n");
    }
    else
    {
        printf("非有效平衡括号\n");
    }
    return 0;
}