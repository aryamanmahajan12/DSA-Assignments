#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define max 100000

typedef struct Node
{
    int planet;
    struct Node *next;
} Node;

typedef struct
{
    int planet;
    int order;
} qnode;

typedef struct
{
    qnode *heap;
    int size;
    int capacity;
} queue;

Node *adj[max];
bool visited[max];
int list[max];
int li = 0;

queue *q;

queue *cq(int capacity)
{
    queue *q = (queue *)malloc(sizeof(queue));
    q->heap = (qnode *)malloc(capacity * sizeof(qnode));
    q->size = 0;
    q->capacity = capacity;
    return q;
}

void enqueue(queue *q, int planet, int order)
{
    qnode node;
    node.planet = planet;
    node.order = order;

    q->heap[q->size++] = node;

    int i = q->size - 1;
    while (i > 0 && q->heap[i].order < q->heap[(i - 1) / 2].order)
    {
        qnode temp = q->heap[i];
        q->heap[i] = q->heap[(i - 1) / 2];
        q->heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

qnode dequeue(queue *q)
{
    qnode min = q->heap[0];
    q->heap[0] = q->heap[--q->size];

    int i = 0;
    while (true)
    {
        int child1 = 2 * i + 1;
        int child2 = 2 * i + 2;
        int least = i;

        if (child2 < q->size && q->heap[child2].order < q->heap[least].order)
            least = child2;

        if (child1 < q->size && q->heap[child1].order < q->heap[least].order)
            least = child1;

        if (least != i)
        {
            qnode temp = q->heap[i];
            q->heap[i] = q->heap[least];
            q->heap[least] = temp;
            i = least;
        }
        else
        {
            break;
        }
    }

    return min;
}

void Insert(int p1, int p2)
{
    Node *new = (Node *)malloc(sizeof(Node));
    new->planet = p2;
    new->next = adj[p1];
    adj[p1] = new;
    Node *new2 = (Node *)malloc(sizeof(Node));
    new2->planet = p1;
    new2->next = adj[p2];
    adj[p2] = new2;
}

void DFS(int planet)
{
    list[li++] = planet;
    Node *x = adj[planet];
    while (x != NULL)
    {
        int np = x->planet;
        if (!visited[np])
        {
            visited[np] = true;
            enqueue(q, np, np);
        }
        x = x->next;
    }
    while (q->size > 0)
    {
        qnode node = dequeue(q);
        int nextPlanet = node.planet;
        DFS(nextPlanet);
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i <= n; i++)
    {
        adj[i] = NULL;
        visited[i] = false;
    }

    for (int i = 0; i < m; i++)
    {
        int p1, p2;
        scanf("%d %d", &p1, &p2);
        Insert(p1, p2);
    }

    q = cq(max);

    visited[1] = true;
    DFS(1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", list[i]);
    }
    printf("\n");

    return 0;
}