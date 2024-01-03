typedef struct queue
{
    int val;
    struct queue *next;
    struct queue *rear;
} queue;

void push(queue **head, int val);

int pop(queue **head);

void inject(queue **head, int val);

int poprear(queue **head);

void print(queue *head);

void printreverse(queue *head);

int findelem(queue *head, int pos);

void removeKelems(queue **head, int k);
