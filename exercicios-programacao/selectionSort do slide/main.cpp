#include <iostream>

void selectionSort(int A[],int n)
{
    int i,j,aux,maior = i =0;
    
    for (i = 0; i < n - 1; i++)
    {
       maior = i;
       for (j = i + 1; j < n; j++)
       {
            if (A[maior] < A[j])
            {
                maior = j;
            }
           
        }
        aux = A[i];
        A[i] = A[maior];
        A[maior] = aux;
    }
}

int main()
{
    int vetor[]={54,868,35,2,1,757};
    int qtd=6;
    
    selectionSort(vetor,qtd);
    for(int i=0;i<qtd;i++)
    {
        printf("%d ",vetor[i]);
    }
    

    return 0;
}
