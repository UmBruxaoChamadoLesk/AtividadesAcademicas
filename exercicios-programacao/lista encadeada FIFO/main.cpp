#include <iostream>
using namespace std;

struct No
{
    int info;
    struct No* prox;
};

typedef No *NoPtr;

NoPtr topo=NULL;
NoPtr ultimo=NULL;


bool listaVazia()
{
    if (topo)
    {
        return false;    
    }
    else
    {
        return true;
    }
}

void listar()
{
    int i=1;
    NoPtr p;
    p = topo;
    if(!listaVazia())
    {
       while((p!=NULL))
       {
        
        if(p->prox==NULL)
        {
            cout<<"ultimo:\n";
        }
        
        cout<<"prox de no "<<i<<"#: "<<p->prox<<endl;
        cout<<"info de no "<<i<<"#: "<<p->info<<endl<<endl;
        
        p=p->prox;
        i++;
        
        }
    }
    else
    {
        printf("lista esta vazia\n");
    }
    
}

void enfileirar()
{
    NoPtr p;
    int valor;
    
    p = new No; //p=(NoPtr)malloc(sizeof(struct No));
    
    cout<<"digite o valor do elemento:";
    cin>>valor;
    
    p->info=valor;
    if(listaVazia())
    {
        topo=p; 
        
        if(ultimo==NULL)
        {
            ultimo=p;
        }
    }
    else
    {
        ultimo->prox=p;
        ultimo=p;
    }
    

}

void desenfileirar()
{
    NoPtr p = topo;
    if(topo)
    {
        topo= p->prox;
        delete(p);
        cout<<"\nO elemento foi retirado da pilha"<<endl;
    }
    else
    {
        cout<<"\na lista esta vazia."<<endl;
    }
}


int main()
{
    
    int op;
    do
    {
        cout<<"(1)enfileirar\n(2)desenfileirar\n(3)listar\n"<<endl;
        cin>>op;
        switch(op)
        {
            case 1:enfileirar();break;
            case 2:desenfileirar();break;
            case 3:listar();break;
        }
        printf("op:%d\n",op);
    }while(op!=0);

    return 0;
}













