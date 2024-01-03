#include <stdio.h>
#include <stdlib.h>
#include "functions.h"



typedef struct stack
{
    char c[10000];
    int top;
} stack;

int palindrome(char *str, int length)
{
    int copy;
    int k = 0;

    if (length % 2 != 0)
    {
        copy = length - 1;
    }
    else
    {
        copy = length;
    }

    for (int j = 0; j < copy / 2; j++)
    {
        if (str[j] == str[length - 1 - j])
            continue;

        else
        {
            k++;
            break;
        }
    }

    if (k > 0)
    {
        return 0;
    }

    else
        return 1;
}








int balanced(char *str, int length)
{

    stack l;
    l.top = -1;

    for(int i=0;i<10000;i++)
    {
        l.c[i]='0';
    }

    int f = 0;
    int fc= 0;

    for (int p = 0; p < length; p++)
    {
        if ((str[p] == '(') || (str[p] == '{') || (str[p] == '['))
        {
            f++;
            l.top++;
            l.c[l.top] = str[p];
        }

        if ((str[p] == ')') || (str[p] == '}') || (str[p] == ']'))
        {
            fc++;
            if (l.top > -1)
            {
                if (str[p] == ')' && l.c[l.top] == '(')
                {
                    l.top--;
                }
                else if (str[p] == '}' && l.c[l.top] == '{')
                {
                    l.top--;
                }
                else if (str[p] == ']' && l.c[l.top] == '[')
                {
                    l.top--;
                }

                else
                {
                    return 0;
                }
            }

            else
            {
                return 0;
            }
        }
    }


if(f!=0 && fc!=0)
{
    if (f == fc)
    {
    return 1;
    }
}
    return 0;
}
