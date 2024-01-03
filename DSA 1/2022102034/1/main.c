#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
int main()
{

    int test_cases;
    scanf("%d", &test_cases);

    for (int i = 0; i < test_cases; i++)
    {
        char s[6];

        scanf("%s", s);

        if (s[4] == '1')
        {
            int len;
            scanf("%d", &len);
            char inp[len];
            scanf("%s", inp);

            reverseString(inp, len);
        }

        // if(s[4]=='2')
        // {
        //   int lt;
        //   scanf("%d", &lt);

        //   char i[lt];
        //   scanf("%s", i);

        //   char* j =compressString(i,lt);
        // }

        if (s[4] == '3')
        {

            int l;
            scanf("%d", &l);

            if (l != 0)
            {
                int a[l];

                for (int i = 0; i < l; i++)
                {
                    scanf("%d", &a[i]);
                }

                int *k = uniqueElements(a, l);
            }
        }

        if (s[4] == '4')
        {
            int r, c;
            scanf("%d %d", &r, &c);

            int **m = (int **)malloc(r * sizeof(int *));

            for (int i = 0; i < r; i++)
            {
                int *b = (int *)malloc(c * sizeof(int));

                m[i] = b;

                for (int j = 0; j < c; j++)
                {
                    scanf("%d", &m[i][j]);
                }
            }

            int **t = transpose(m, r, c);
        }
    }

    return 0;
}
