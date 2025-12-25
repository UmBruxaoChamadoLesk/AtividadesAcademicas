#include <stdio.h>
#define QUANTIDADE 6

void selectionSort(int v[],int qtd)
{
    int aux;
    
    for(int i=0;i<qtd-1;i++)
    {
     if(v[i]>v[i+1])
     {
         for(int j=i+1;j>0 && v[j]<v[j-1];j--)
         {
                 aux=v[j];
                v[j]=v[j-1];
                v[j-1]=aux;
             
         }
     }
    }
    
}

int main()
{
    
    int A[QUANTIDADE]={16,6,18,2,19,10};

    selectionSort(A,QUANTIDADE);
    
    for(int i=0;i<QUANTIDADE;i++)
    {
        printf("\t%d",A[i]);
    }
    
    

    return 0;
}

