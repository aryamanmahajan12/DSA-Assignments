typedef struct node
{
   int Element;
   struct node* NextNode;       
}node;
typedef struct node* PtrNode;
void Insert(PtrNode Head, int num);
void Find(PtrNode Head, int num);
void Print(PtrNode Head);