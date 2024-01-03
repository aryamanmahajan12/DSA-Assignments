#include <stdio.h>
#include <stdlib.h>
#include"functions.h"



// char* compressString(char* str, int length)
// {

// char arr[3*length];
// int count =1;
// int j=0;
//  char* c = (char*) malloc(3*length*sizeof(char));

// for(int i=0;i<length;i++)
// {

//   if(str[i+1]==str[i])
//   {
//     count++;
//   }

//   if(str[i+1]!= str[i])
//   {
//    c[j]= str[i];
//    arr[j+1]=count;
//    j=j+2;
//    count=1;
//   }
// }



// for(int m=1;m<j;m=m+2)
// {
  
//   c[m]='0' + (char)arr[m];

// }

// c[j+1]='\0';

// return c;
// }





int** transpose(int** matrix, int NumRow, int NumCol)
{
 int** n=(int**)malloc(NumCol*sizeof(int*));

 for(int i=0;i<NumCol;i++)
 {
    int* k= (int*)malloc(NumRow*sizeof(int));
    n[i]=k;
    for(int j=0;j<NumRow;j++)
    {
     n[i][j]=matrix[j][i];   
     printf("%d ",n[i][j]);
    }
    printf("\n");
 }       

 return n;
}



void reverseString(char* str, int length)
{

for(int i = length-1;i>-1;i--)
{
  printf("%c", str[i]);
}
printf("\n");

}






int* uniqueElements(int* arr, int length)
{

int myarr[1000001]={0};

int* a=(int*)malloc(sizeof(int)*(length+1));
int k=0;

for(int i=0;i<length;i++)
{
  myarr[arr[i]]++;
}

for(int i=0;i<length;i++)
{
  if(myarr[arr[i]] >= 1)
    {
      a[k++]=arr[i];
      printf("%d ", arr[i]);
      myarr[arr[i]]= 0;
    }
}

printf("\n");

return a;

}




