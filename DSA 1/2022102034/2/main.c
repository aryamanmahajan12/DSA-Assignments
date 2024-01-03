#include<stdio.h>
#include<stdlib.h>
#include"functions.h"
int main()
{

    int test_cases;
    scanf("%d", &test_cases);

    for(int i=0;i<test_cases;i++)
    {
        char s[5];
        scanf("%s", s);


        if(s[4]=='2')
        {
            int l;
            scanf("%d", &l);

            char a[l];
            scanf("%s", a);

            const char* str=a;

            char i;
            scanf(" %c", &i);

            int n = countCharOccurrences(str,l,i);  
            printf("%d\n", n);
        }


        if(s[4]=='3')
        {   
            int len;
            scanf("%d", &len);
            char ch[len+2];
            scanf("%s", ch);

            const char* str=ch;

            char c= findFirstNonRepeatingChar(str,len);

            if(c=='1')
            {
                printf("-1\n");
            }

            

            else
            {
                printf("%c\n", c);
            }
        }


        if(s[4]=='5')
        {

            int lenArr;
            scanf("%d", &lenArr);
        if(lenArr!=0)
        {
            int arr[lenArr];

            for(int i=0;i<lenArr;i++)
            {
                scanf("%d", &arr[i]);
            }
            int* m = maxMin(arr,lenArr);
            
        }

        }
        
 if(s[4]=='1')
        {
        int l1,l2;


        scanf("%d %d", &l1, &l2);

        int* a1=(int*)malloc(sizeof(int)*l1);

        int* a2=(int*)malloc(sizeof(int)*l2);

        for(int i=0;i<l1;i++)
        {
        scanf("%d", &a1[i]);
        }

        for(int i=0;i<l2;i++)
        {
        scanf("%d", &a2[i]);
        }

    intersectionArray(a1,a2,l1,l2);
    free(a1);
    free(a2);
    }


if(s[4]=='6')
{
    int l1,l2;
    scanf("%d %d", &l1,&l2);
    char* str;

if(l1!=0)
str=(char*)malloc(l1*sizeof(char));

char* substr=(char*)malloc(l2*sizeof(char));

scanf("%s", str);
scanf("%s", substr);

const char*s =substr;

removeSubstring(str,l1,substr,l2);
}


    }

    
    return 0;
}
