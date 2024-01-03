typedef struct stack
{
    char c[10000];
    int top;
} stack;


int palindrome(char *str, int length);

int balanced(char *str, int length);
