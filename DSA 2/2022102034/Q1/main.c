#include <stdio.h>
#include <stdlib.h>
#include "functions.h"


int main()
{
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {

        char *s = (char *)malloc(sizeof(char) * 10000);

        scanf("%s", s);

        int n = 0;

        // obtaining length of string
        char m = s[0];

        while (m != '\0')
        {
            n++;
            m = s[n];
        }
        
int x=palindrome(s,n);
int y=balanced(s,n);

        if (x==1)
        {
            printf("Palindromic\n");
        }

        if (y==1)
        {
            printf("Balanced\n");
        }

        if (x==0 && y==0)
        {
            printf("-1\n");
        }
    }

    return 0;
}
