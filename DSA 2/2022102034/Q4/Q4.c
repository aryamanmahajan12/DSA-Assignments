#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    long int key;
    struct tree *left;
    struct tree *right;
} treenode;

treenode *makenode(long int e)
{
    treenode *t;
    t = (treenode *)malloc(sizeof(treenode));

    t->left = NULL;
    t->right = NULL;
    t->key = e;

    return t;
}

treenode *insert(treenode *t, long int e)
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

long int update(treenode *t, long int s)
{
    if (t == NULL)
        return s;
    s = update(t->left, s);
    s += t->key;
    t->key = s;
    s = update(t->right, s);
    return s;
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

void levelorder(treenode *t, int n)
{
    long int array[n];

    int k = 0;

    q *mq;
    mq = createq(n);

    enque(mq, t);

    while (mq->size != 0)
    {
        treenode *x = deque(mq);

        array[k] = x->key;
        k++;

        printf("%ld ", x->key);

        if (x->left != NULL)
        {
            enque(mq, x->left);
        }

        if (x->right != NULL)
        {
            enque(mq, x->right);
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        array[i + 1] += array[i];
    }

    printf("\n");

    printf("%ld\n", array[n - 1]);
}


int main()
{

    long int n;
    scanf("%ld", &n);

    long int a;

    treenode *t = NULL;

    for (int j = 0; j < n; j++)
    {
        scanf("%ld", &a);
        t = insert(t, a);
    }

    long int x = update(t, 0);

    levelorder(t, n);
    printf("\n");

    return 0;
}