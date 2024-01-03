#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "hash.h"

node *makenode(char *s)
{
    node *p = malloc(sizeof(node));
    p->s = s;
    p->next = NULL;
    return p;
}

node **hash( node** array ,char *s)
{
    int a = 0;

    node *ptr = makenode(s);

    for (int i = 0; i < strlen(s); i++)
    {
        a += s[i]*s[i];
    }

    if (array[a] != NULL)
    {
        // ptr->next = array[a];
        node *p = array[a];
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = ptr;
    }
    else
    {
        array[a] = ptr;
    }
    return array;
}

int *makefreqarr(char *s)
{
    int *p = malloc(sizeof(int) * 26);
    for (int i = 0; i < 26; i++) {
        p[i] = 0;
    }

    for (int i = 0; i < strlen(s); i++)
    {
        p[s[i] - 'a']++;
    }

    return p;
}

// node *Gethash(char *s, node **array)
// {
//     int a = 0;
//     for (int i = 0; i < strlen(s); i++)
//     {
//         a += s[i];
//     }
//     node *p = array[a];
//     return p;
// }

node *Gethash(char *s, node **array)
{
    int a = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        a += s[i]*s[i];
    }
    node *p = array[a];
    return p;
}