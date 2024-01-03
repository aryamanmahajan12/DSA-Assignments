#include <stdio.h>
#include <stdlib.h>
#include"functions.h"



/*Q. Write a function to insert a new element at the front of a circular linked list.
This means, the first element oof the list should be updated with every new insertion to the list.
The function format has been specified by the questionaire.*/




//function for inserting a new node

//Head node here is the sentinel node

void Insert(PtrNode Head, int num)
{

  //creating a new node for storing the new element
  PtrNode n =(PtrNode)malloc(sizeof(node));

//assigning value to the new node
  n->Element=num;

//CASE : Insertion of First node
if( Head->NextNode == NULL)
{
    n->NextNode=Head;
    Head->NextNode=n;
}

//CASE: Insertion of new node in already made list
else
{
  n->NextNode=Head->NextNode;
  Head->NextNode=n;
}


}






/*Write a function to search for a given element in the list and move it to the front of the list.*/



//Procedure or function for finding the required element
//Head is the sentinel node and num is the element to be found or searched for in the list 


void Find(PtrNode Head, int num)
{

if(Head->NextNode->Element == num)
{
  return;
}


//CASE: List contains more than one elements

//Traversing through list to get to the required element. Also, loop breaks if last element is reached but element has not been foundif ( Head->NextNode->NextNode == Head )

  for ( PtrNode finder = Head; finder->NextNode != Head; finder = finder->NextNode){
      if ( finder->NextNode->Element == num){
          PtrNode dummy = finder->NextNode;
          finder->NextNode = dummy->NextNode;
          dummy->NextNode = Head->NextNode;
          Head->NextNode = dummy;
          return;
      }
  }
  return; 

}






/*Write code for printing the elements  in the list.*/





//Function for printing the elements in the list

void Print(PtrNode Head)
{ 
  if (Head->NextNode==Head)
    return;
    for ( PtrNode p = Head; p->NextNode != Head; p = p->NextNode )
      printf("%d ", p->NextNode->Element);
    printf ("\n");  
}

