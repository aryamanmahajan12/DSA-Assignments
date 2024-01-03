#include <stdio.h>
#include <stdlib.h>
#include "Hash.h"

int main()
{

    int n, q, l, r;
    scanf("%d", &n);
    scanf("%d", &q);

    char *s = (char *)malloc(sizeof(char) * n);

    scanf("%s", s);

    for (int j = 0; j < q; j++)
    {
        scanf("%d", &l);
        scanf("%d", &r);

        if (palindrome(s, l, r))
            printf("YES\n");

        else
            printf("NO\n");
    }

    return 0;
}
