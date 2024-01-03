#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main()
{
    int test;
    scanf("%d", &test);
    char *s = (char *)malloc(6 * sizeof(char));
    queue *head = (queue *)malloc(sizeof(queue));

    head = NULL;

    for (int j = 0; j < test; j++)
    {
        scanf("%s", s);

        if (s[4] == '1')
        {
            int n;
            scanf("%d", &n);
            push(&head, n);
        }

        if (s[4] == '2')
        {
            int k = pop(&head);
            printf("%d\n", k);
        }

        if (s[4] == '3')
        {
            int n;
            scanf("%d", &n);

            inject(&head, n);
        }

        if (s[4] == '4')
        {
            int k = poprear(&head);
            printf("%d\n", k);
        }

        if (s[4] == '5')
        {
            print(head);
        }

        if (s[4] == '6')
        {
            printreverse(head);
        }

        if (s[4] == '7')
        {
            int pos;
            scanf("%d", &pos);
            int k = findelem(head, pos);
            printf("%d\n", k);
        }

        if (s[4] == '8')
        {
            int k;
            scanf("%d", &k);
            removeKelems(&head, k);
        }
    }
    return 0;
}
