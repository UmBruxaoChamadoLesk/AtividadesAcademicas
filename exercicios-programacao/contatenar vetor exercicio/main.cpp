#include <iostream>
using namespace std;


bool busca(int V[],int qtd,int Elem,int *Vposicao)
{

    for(int i=0;i<qtd;i++)
    {
        if(V[i]==Elem)
        {
            
            *Vposicao = i+1;
            return true;
        }
        
    }
    return false;
    
}

void intercala(int V1[],int qtd1,int V2[],int qtd2,int V3[],int qtd3)
{
    int i,j=i=0;
    
    
    while(i<qtd3)
    {
        while(i<qtd1)
        {
            V3[i]=V1[i];
            i++;
        }
        while(j<qtd2)
        {
            V3[i]=V2[j];
            
            j++;i++;
         
        }
    }    
}   

int main()
{
    int A[10]={1,4,5,2,3,7,5,4,8,6};
    int B[10]={8,6,3,5,2,8,5,7,2,3};
    int C[20];
    
    intercala(A,10,B,10,C,20);
    for(int i=0;i<20;i++)
    {
        printf("%d ",C[i]);
    }
    cout<<endl;
    cout<<"escreva um elemento a ser buscado\n";
    int x;
    int posicao;
    cin>>x;
    
    bool resultado = busca(C,20,x,&posicao);
    
    if(resultado)
    {
        printf("elemento encontrado na posicao %d do vetor C",posicao);
    }
    else
    {
        printf("elemento nao encontrado\n");
    }
    
    
    
    

    return 0;
}