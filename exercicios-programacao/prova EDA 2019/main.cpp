#include <stdio.h>

typedef spool *Noptr;

Noptr topo=NULL;
Noptr ultimo=NULL;

void retirar()
{
    Noptr p;
    
    if(topo!=NULL)
    {
        p=topo;
        topo = topo->prox;
        delete(p);
    }
    else
    {
        cout<<"lista vazia\n";
    }
}

void enfileira()
{
    Noptr p;
    p = new spool;
    
    int valor;
    cout<<"insira o dado\n";
    cin>>valor;
    
    p->num=valor;
    
    if(topo==NULL)
    {
        
        topo=p;
        if(ultimo==NULL)
        {
            ultimo=topo;
            
        }
    }
    else
    {
        ultimo->prox=p;
        ultimo=p;
    }
    
    
}

void Buscar_e_remove(int n)
{
    Noptr aux,p = aux = topo;
    
    if(topo->num==n)
        {
            topo=topo->prox;
            delete(p);
            return;
        }
    
    while(p!=NULL)
    {
        if(p->num==n)
        {
            aux->prox=p->prox;
            delete(p);
            
            return;
        }
        else
        {
         aux=p;
         p=p->prox;   
        }
        
    }
}

void MaiorValor()
{
    Noptr p=topo;
    Noptr maior=NULL;
    while(p!=NULL)
    {
        if(p->num > maior->num)
        {
            maior=p;
        }
        p=p->prox;
    }
    cout<<"o maior elemento: "<<maior->num<<"\n";
    maior=maior->prox;
    cout<<"e seu proximo é: "<< maior->num<<"\n";
}

//c) são iguais. Ambas as complexidades são O(N), 
//pois ambas só possuem uma estrutura de loop ao qual processam todos os elementos

void ordena(int V[],int tamanho)//tamanho = 20
{
    int i,j,aux;
    
    for(i=0;i<tamanho-1;i++)
    {
        for(j=i+1;j<tamanho;j++)
        {
            if(V[i]>V[j])
            {
                aux=V[i];
                V[i]=V[j];
                V[j]=aux;
            }
        }
        
    }
    
}

//4) 

int main()
{

    return 0;
}
