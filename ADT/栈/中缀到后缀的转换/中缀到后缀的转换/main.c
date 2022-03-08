#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"
#include <string.h>

char* Shift(char* str)
{
    int len = (int)strlen(str);
    char* p = (char*)malloc(sizeof(char) * len);
    assert(p);
    Stack S = CreatStack();
    int i = 0, j = 0;
    char temp1 = 0, temp2 =0;
    while (str[i] != '\0')
    {
        // + * (  ---> 
        //   43              42                40              41  
        if ('+' == str[i] || '*' == str[i] || '(' == str[i] || ')' == str[i])
        {
            if (str[i] != ')')
            {
                Push(str[i], S);
                while (S->TopOfStack >= 1)
                {
                    temp1 = TopAndPop(S);
                    temp2 = TopAndPop(S);
                    if (temp2 != '(' && temp1 - temp2 >= 0) // ÓÅÏÈ¼¶µÍ
                    {
                        p[j++] = temp2;
                        Push(temp1, S);
                    }
                    else
                    {
                        Push(temp2, S);
                        Push(temp1, S);
                        break;
                    }
                }
            }
            else if (str[i] == ')')
            {
                while (Top(S) != '(')
                {
                    p[j++] = TopAndPop(S);
                }
                Pop(S);
            }
            else
            {
                Push(str[i], S);
            }
        }
        else
        {
            // ×ÖÄ¸ --> out
            p[j++] = str[i];
        }
        i++;
    }
    while (!IsEmpty(S))
    {
        p[j++] = TopAndPop(S);
    }
    p[j] = '\0';
    return p;
}

int main(void)
{
    char str[] = "a+b*c+(d*e+f)*g";     // ---> a b c * + d e * f + g * +
    char* p = Shift(str);
    printf("%s", p);

    return 0;
}