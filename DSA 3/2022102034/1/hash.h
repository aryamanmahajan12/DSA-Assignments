#ifndef hash_h
#define hash_h

typedef struct node
{
    char *s;
    struct node *next;
} node;

node *makenode(char *s);
node **hash( node** array ,char *s);
int *makefreqarr(char *s);
node *Gethash(char *s, node **array);


#endif