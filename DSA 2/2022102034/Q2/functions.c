#include <stdio.h>
#include <stdlib.h>
#include "functions.h"



typedef struct queue
{
    int val;
    struct queue *next;
    struct queue *rear;
} queue;

void push(queue **head, int val)
{
    queue *p = (queue *)malloc(sizeof(queue));
    p->val = val;

    if ((*head) == NULL)
    {
        p->next = p;
        p->rear = p;
        *head = p;
    }
    else
    {
        p->next = *head;
        p->rear = (*head)->rear;
        (*head)->rear->next = p;
        (*head)->rear = p;
    }
}

int pop(queue **head)
{
    if ((*head) == NULL)
    {
        return -1;
    }

    int t = (*head)->val;
    queue *temp = *head;

    if ((*head)->next == *head)
    {
        *head = NULL;
    }
    else
    {
        *head = (*head)->next;
        (*head)->rear = temp->rear;
        temp->rear->next = *head;
    }

    free(temp);
    return t;
}

void inject(queue **head, int val)
{
    queue *p = (queue *)malloc(sizeof(queue));
    p->val = val;

    if (*head == NULL)
    {
        p->next = p;
        p->rear = p;
        *head = p;
    }
    else
    {
        p->next = *head;
        p->rear = (*head)->rear;
        (*head)->rear->next = p;
        (*head)->rear = p;
        *head = p;
    }
}

int poprear(queue **head)
{
    if ((*head) == NULL)
    {
        return -1;
    }
    int t = (*head)->rear->val;
    queue *temp = (*head)->rear;

    if ((*head)->next == *head)
    {
        *head = NULL;
    }
    else
    {
        (*head)->rear = temp->rear;
        temp->rear->next = *head;
    }

    free(temp);
    return t;
}

void print(queue *head)
{
    if (head == NULL)
    {
        printf("-1\n");
        return;
    }

    queue *p = head;

    do
    {
        printf("%d ", p->val);
        p = p->next;
    } while (p != head);

    printf("\n");
}

void printreverse(queue *head)
{
    if (head == NULL)
    {
        printf("-1\n");
        return;
    }

    queue *p = head->rear;

    do
    {
        printf("%d ", p->val);
        p = p->rear;
    } while (p != head->rear);

    printf("\n");
}

int findelem(queue *head, int pos)
{
    if (head == NULL)
    {
        return -1;
    }

    queue *p = head;
    int count = 1;

    do
    {
        if (count == pos)
        {
            return p->val;
        }
        p = p->next;
        count++;
    } while (count <= pos && p != head);

    return -1;
}


void removeKelems(queue **head, int k)
{
    if (*head == NULL)
        return;

    queue *p = *head;
    int count = 1;

    while (p->next != (*head))
    {
        p = p->next;
        count++;
    }

    if (k <= count)
    {
        for (int i = 0; i < k; i++)
        {
            pop(head);
        }
    }

    if (k > count)
    {
        for (int i = 0; i < count; i++)
        {
            pop(head);
        }
    }
}
