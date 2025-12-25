#include <iostream>
using namespace std;

struct No
{
    int info;
    struct No* prox;
};

typedef No *NoPtr;

NoPtr topo=NULL;


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

void lista()
{
    int i=1;
    NoPtr p;
    p = topo;
    if(!listaVazia())
    {
       do
       {
        cout<<"prox de no "<<i<<"#: "<<p->prox<<endl;
        cout<<"info de no "<<i<<"#: "<<p->info<<endl<<endl;
        p=p->prox;
        i++;
        
        }while((p!=NULL)); 
    }
    
}

void empilha()
{
    NoPtr p;
    int valor;
    
    p = new No;
    
    cout<<"digite o valor do elemento:";
    cin>>valor;
    
    p->info=valor;
    p->prox=topo;
    topo=p;

}

void desempilha()
{
    NoPtr p = topo;
    if(!listaVazia())
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
        cout<<"(1)empilhar\n(2)desempilhar\n(3)listar\n"<<endl;
        cin>>op;
        switch(op)
        {
            case 1:empilha();break;
            case 2:desempilha();break;
            case 3:lista();break;
        }
        printf("op:%d\n",op);
    }while(op!=0);

    return 0;
}





