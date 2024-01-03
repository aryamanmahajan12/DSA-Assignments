#include <stdio.h>
#include <stdlib.h>
#include"functions.h"
int main()
{

  int no_of_operations_to_be_performed;

  scanf("%d", &no_of_operations_to_be_performed);
  
  PtrNode Head = (PtrNode)malloc(sizeof(node));
  Head->NextNode = Head;

for(int i=0;i<no_of_operations_to_be_performed;i++)
{
  char s[10];
  int num = 0;


  
  scanf(" %s", s);


  if(s[4]=='1')
  {
    scanf("%d", &num);
    Insert(Head,num); 
  }

  if(s[4]=='2')
  {
    scanf("%d", &num);
    Find(Head,num);
  }

  if(s[4]=='3')
  {
    Print(Head);
  }
}
    
  return 0;
}