#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"
#include <stdio.h>

//char 类型
//范围 -128 ---> 127

int main(void)
{
    Stack S = CreatStack();
    char str[] = { '6', '5', '2', '3', '+', '8', '*', '+', '3', '+', '+', '\0'};
    int temp = 0;
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '+')
        {
            // 变int
            temp = TopAndPop(S) - '0';
            temp += TopAndPop(S) - '0';

            // 变char
            Push(temp + '0', S);
        }
        //else if (str[i] == '-')
        //{
        //    temp = TopAndPop(S) - '0';
        //    temp -= TopAndPop(S) - '0';
        //    Push(temp + '0', S);
        //}
        else if (str[i] == '*')
        {
            temp = TopAndPop(S) - '0';
            temp *= TopAndPop(S) - '0';
            Push(temp + '0', S);
        }
        //else if (str[i] == '/')
        //{
        //    temp = TopAndPop(S) - '0';
        //    temp /= TopAndPop(S) - '0';
        //    Push(temp + '0', S);
        //}
        else
        {
            Push(str[i], S);
        }
        i++;
    }
    printf("ans = %d\n", TopAndPop(S) - '0');

    return 0;
}