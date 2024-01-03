#include<stdio.h>
#include<stdlib.h>

#include"functions.h"


/*int* IntersectionArray(int* Arr1 , int* Arr2, int lenArr1, int lenArr2)
{
    int m;
    int n,k = 0;


    if(lenArr1<=lenArr2)
    {
        m=lenArr1;
    }
    else
    {
        m=lenArr2;
    }

int arr[m]={0};


if(lenArr1<=lenArr2)
{
    for(int i=0;i<lenArr1;i++)
        {
            for (int j=0;j<lenArr2;j++)
            {
                if(Arr1[i]==Arr2[j]);
                {
                    arr[i] = 1;
                    n++;
                    
                    break;
                }
            }
        }
}

     




else
{
    for ( int i = 0; i < lenArr2; i++)
    {
        for(int j=0;j<lenArr1;j++)
        {
            if(Arr2[i]==Arr1[j])
            {
                arr[i]=1;
                n++;
                break;
            }
        }
    }

    if(n==0)
    {
        return -1;
    }   

int arr1[n];



        int arr1[n];
        for(int i=0;i<m;i++)
        {
            if(arr[i]==1)
            {
                arr1[k]=Arr2[i];
                k++;
            }
        }
        
     

    void qsort (void* arr1, size_t num, size_t size, 
            int (*comparator)(const void*,const void*));
}


if (n==0)
     {
        return -1;
     }
     
    else
    {
        int arr1[n];
        for(int i=0;i<m;i++)
        {
            if(arr[i]==1)
            {
                arr1[k]=Arr1[i];
                k++;
            }
     
       }

    }
}

*/



int countCharOccurrences(const char* str, int length, char ch)
{

    int a=0;
    for(int i=0;i<length;i++)
    {
    if(ch==str[i])
    {
        a++;
    }
    }

    return a;
}


char findFirstNonRepeatingChar(const char* str, int length)
{

int arr[300]={0};

     for(int i=0;i<length;i++)
     {
       arr[(int)str[i]]++;
       
     }    

     for(int i=0;i<length;i++)
     {
        if(arr[(int)str[i]] == 1)
        return str[i];
     }

     return '1';

}


void intersectionArray(int* arr1, int* arr2, int lenArr1, int lenArr2)
{


 int max = 0;

    for (int i = 0; i < lenArr1; i++) {
        if (arr1[i] > max) {
            max = arr1[i];
        }
    }

    for (int i = 0; i < lenArr2; i++) {
        if (arr2[i] > max) {
            max = arr2[i];
        }
    }

    int* f1 = (int*)calloc(max+1, sizeof(int));
    int* f2 = (int*)calloc(max+1, sizeof(int));
    int* f3 = (int*)calloc(max+1, sizeof(int));



for(int i=0;i<lenArr1;i++)
{
    f1[arr1[i]]++;
}

for(int i=0;i<lenArr2;i++)
{
    f2[arr2[i]]++;
}


int m=0;
for(int i=0;i<=max;i++)
{
f3[i] = f1[i] <= f2[i] ? f1[i]:f2[i];
    int k = f3[i];
    if(k!=0)
    {
        m++;
    }
   
    while(k>0)
    {
        printf("%d ", i);
        k--;
    }

}
if(m==0)
{printf("-1");}

printf("\n");
}





int* maxMin(int* arr , int lenArr)
{
    
    int left[lenArr];
    int right[lenArr];
int leftmax = arr[0];
int rightmin= arr[lenArr-1];
int k=0;


int* m = (int*)malloc(sizeof(int)*lenArr);

    for(int i=0;i<lenArr;i++)
    {
        if(arr[i]>leftmax)
        leftmax=arr[i];

        left[i]=leftmax;
    }

    for(int i=lenArr-1;i>-1;i--)
    {
        if(arr[i]<rightmin)
        rightmin=arr[i];

        right[i]=rightmin;
    }

if(arr[0]<right[1])
{
   printf("0 ");
   m[k++]=0;
}

    for(int i=1;i<lenArr-1;i++)
    {
        if(arr[i]>left[i-1] && arr[i]<right[i+1])
        {
            
            printf("%d ", i);
            m[k++]=i;
        }
    }

if(arr[lenArr-1]>left[lenArr-2])
{
    printf("%d ", lenArr-1);
    m[k++]=lenArr-1;
}    

if(k==0)
{
  printf("-1");
}

printf("\n");

return m;

}

char* removeSubstring(char* str, int strLength, const char* substr, int substrLength)
{

    char* c = str;
    const char* ch=substr;

if(strLength!=0)
{

char* now=(char*)malloc(strLength*sizeof(char));
int m=0;


for(int i=0;i<strLength;i++)
{

if(c[i]!= ch[0])
{
   now[m]=c[i];
   printf("%c", now[m]);
   m++;
   continue;
}


if(c[i] == ch[0])
{
    int n=i+1;
    int j=1;
    int k=0;
    for(j=1;j<substrLength;j++)
    {
        if(c[n] != ch[j])
        {
        k=1;        
        break;
        }

        n++;
    }
    
    if(k==1)
    {
    now[m++]=c[i];
    printf("%c", c[i]);
    }

    else
    {
    i = n-1;
    }      
}
    


}
   
   
   
   

if(m==0)
{
    char* x="-1";
    printf("%s", x);
    printf("\n");
    return x;
}

printf("\n");
return now;

}
}
