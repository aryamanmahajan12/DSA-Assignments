#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    int key;
    struct tree *left;
    struct tree *right;
} treenode;

treenode *makenode(int e)
{
    treenode *t;
    t = (treenode *)malloc(sizeof(treenode));

    t->left = NULL;
    t->right = NULL;
    t->key = e;

    return t;
}

treenode *insert(treenode *t, int e)
{
    if (t == NULL)
    {
        t = makenode(e);
    }

    else if (e < t->key)
    {
        t->left = insert(t->left, e);
    }

    else if (e > t->key)
    {
        t->right = insert(t->right, e);
    }

    return t;
}

typedef struct queue
{
    int capacity;
    int size;
    int front;
    int rear;
    treenode **elems;
} q;

q *createq(int capacity)
{

    q *qptr = (q *)malloc(sizeof(q));

    qptr->capacity = capacity;
    qptr->front = -1;
    qptr->rear = -1;
    qptr->size = 0;
    qptr->elems = (treenode **)malloc(sizeof(treenode *) * capacity);

    return qptr;
}

int isempty(q *qptr)
{
    if (qptr->size == 0)
    {
        return 1;
    }
    return 0;
}

int isfull(q *qptr)
{
    if (qptr->size == qptr->capacity)
    {
        return 1;
    }
    return 0;
}

void enque(q *qptr, treenode *t)
{
    if (isfull(qptr))
        return;

    if (qptr->size == 0)
    {
        qptr->front++;
        qptr->rear++;
        qptr->elems[qptr->rear] = t;
        qptr->size++;
    }

    else
    {
        qptr->rear++;
        qptr->size++;
        qptr->elems[qptr->rear] = t;
    }
}

treenode *deque(q *qptr)
{
    if (isempty(qptr))
        return NULL;

    treenode *front = qptr->elems[qptr->front];
    qptr->front = (qptr->front + 1) % qptr->capacity;
    qptr->size--;

    if (qptr->size == 0)
    {
        qptr->front = -1;
        qptr->rear = -1;
    }

    return front;
}

void zigzag(treenode *t, int n)
{

    q *mq;
    mq = createq(n);

    enque(mq, t);

    int l2r = 1;

    while (!isempty(mq))
    {
        int k = mq->size;
        int a[k];

        for (int i = 0; i < k; i++)
        {
            treenode *z = deque(mq);

            if (l2r)
            {
                a[i] = z->key;
            }

            else
            {
                a[k - i - 1] = z->key;
            }

            if (z->left != NULL)
            {
                enque(mq, z->left);
            }

            if (z->right != NULL)
            {
                enque(mq, z->right);
            }
        }

        for (int i = 0; i < k; i++)
        {
            printf("%d ", a[i]);
        }

        l2r = !l2r;
    }
}

int main()
{

    int test;

    scanf("%d", &test);

    for (int i = 0; i < test; i++)
    {
        int n;
        scanf("%d", &n);

        int arr[n];

        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[j]);
        }

        treenode *t = NULL;

        for (int j = 0; j < n; j++)
        {
            t = insert(t, arr[j]);
        }

        zigzag(t,n);

        printf("\n");
    }

    return 0;
}

