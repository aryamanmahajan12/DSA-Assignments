#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "hash.h"



int main()
{
    int n, q;
    scanf("%d", &n);
    scanf("%d", &q);
    node **array = malloc(sizeof(node *) * 10000000);
    for (int i = 0; i < n; i++)
    {
        char *s = malloc(sizeof(char) * 12);
        scanf("%s", s);
        array = hash( array,s);
    }

    for (int j = 0; j < q; j++)
    {
        char *c = (char *)malloc(sizeof(char) * 12);
        scanf("%s", c);
        node *n = Gethash(c, array);
        if (n == NULL)
            printf("-1\n");

        else
        {
            // int *b = makefreqarr(c);
            int b[26] = {0};
            for (int i = 0; i < strlen(c); i++)
            {
                b[c[i] - 'a']++;
            }

            int flag = 0;
            node *p = n;
            // printf("HERE IS N %s\n",n->s);
            while (p != NULL)
            {
                // int *a = makefreqarr(p->s);
                int a[26] = {0};
                for (int i = 0; i < strlen(p->s); i++)
                {
                    a[p->s[i] - 'a']++;
                }

                int m = 0;
                for (int k = 0; k < 26; k++)
                {
                    if (a[k] != b[k])
                    {
                        m++;
                        break;
                    }
                }
                if (m == 0)
                {
                    flag++;
                    printf("%s ", p->s);
                }
                p = p->next;
            }

            if (flag == 0)
                printf("-1");
            printf("\n");
        }
    }
    for (int i = 0; i < 1500; i++) {
        if (array[i] == NULL) {
            continue;
        }
        node* curr = array[i];
        node* next;
        while (curr != NULL) {
            next = curr->next;
            free(curr->s);
            free(curr);
            curr = next;
        }
    }
    free(array);

    return 0;
}
