#include <iostream>
#include <cstdlib>

using namespace std;


void troca(int* A,int* B)
{
    int aux;
    aux = *A;
    *A = *B;
    *B = aux;
}

void subir(int A[],int i)
{
    int j = (i-1)/2;
    if(i > 0 && A[i] > A[j]) // if(i > 0 && A[i] < A[j]) caso min heap
    {
        troca(&A[i],&A[j]);
        subir(A,j);
    }
}

void descer(int A[],int i,int qtd)
{
    int e = 2*i+1;
    int d = 2*i+2;
    
    int maior = i; //int menor = i; troque maior por menor caso min heap
    
    if(d < qtd && A[d] > A[maior]) //if(d < qtd && A[d] < A[menor])
    {
        maior = d; 
    }
    if(e < qtd && A[e] > A[maior]) //if(e < qtd && A[e] < A[menor])
    {
        maior = e; ;
    }
    if(maior != i)
    {
        troca(&A[i],&A[maior]);
        descer(A,maior,qtd);
    }
}

void inserir(int A[],int valor, int *qtd)
{
    
    if (*qtd < 10) 
    {  
        A[*qtd] = valor;
        subir(A, *qtd);
        (*qtd)++;
    } 
    else 
    {
        cout << "\theap cheia\n";
    }
}

void remover(int A[],int *qtd)
{
    
   if (*qtd == 0) {
        cout <<"\theap vazia"<< endl;
        return;
    }
    
    A[0] = A[*qtd - 1];
    (*qtd)--;
    descer(A, 0, *qtd);
    
}

void heap(int A[], int qtd)
{
    for(int i = (qtd/2);i>=0;i--)
    {
        descer(A,i,qtd-1);
    }
}

void heapsort(int A[], int qtd)
{
    heap(A,qtd);
    for(int i=qtd-1;i>=1;i--)
    {
        troca(&A[0],&A[i]);
        descer(A,0,i-1);
        
    }
    
}

int main()
{
    int T[10],qtd,u,x;
    qtd = 0;
    
    do
    {
        cout<<"\ndigite 1 para inserir 10 numeros na heap"
        <<"\ndigite 2 para exibir a arvore binária"
        <<"\ndigite 3 para remover o menor valor"
        <<"\ndigite 0 para sair\n";
        
        
        cin>>u;
        
        switch(u)
        {
            case 1: 
            cout<<"\ninsira os maximo 10 numeros na heap\n";
            cin>>x;
            inserir(T,x,&qtd);
            break;
            case 2:
            cout<<"\n";
            for(int j = 0;j<qtd;j++)
            {
                cout<<T[j]<<" ";
            }
            break;
            case 3:
            remover(T,&qtd);
            break;
            
        }
    }while(u!=0);

    return 0;
}