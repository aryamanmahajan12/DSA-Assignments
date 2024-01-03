#include "sort.h"

int main()
{
    int testcases;
    scanf("%d", &testcases);

    for (int i = 0; i < testcases; i++)
    {
        int n;
        scanf("%d", &n);
        char **s = (char **)calloc(n, sizeof(char *));
        for (int j = 0; j < n; j++)
        {
            int m;
            scanf("%d", &m);
            s[j] = (char *)malloc(sizeof(char) * (m + 1));
            scanf("%s", s[j]);
        }

        // Sort the strings using shellsort
        shellsort(s, n);
        for (int j = 0; j < n; j++)
        {
            printf("%s\n", s[n - 1 - j]);
        }
    }

    return 0;
}
