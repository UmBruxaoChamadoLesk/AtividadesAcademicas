#include <iostream>

using namespace std;

struct No 
{
    int info;
    
    struct No* prox;
    struct No* ant;
};
typedef struct No* Noptr;

bool listavazia(Noptr i)
{
    return (i==NULL);
}

void inserir(Noptr *i)
{
    Noptr p = new No;
    
    cout<<"Digite o valor do elemento\n";
    cin>>p->info;
    
    p->ant=NULL;
    
    if(listavazia(*i))
    {
        p->prox=NULL;
        
    }
    else
    {
        p->prox = *i;
        (*i)->ant = p;
    }
    *i = p;
}

void retirar(Noptr *i)
{
    Noptr p = *i;
    
    if(!listavazia(*i))
    {
        if(p->prox==NULL)
        {
            *i = NULL;
        }
        else
        {
            *i = (*i)->prox;
            (*i)->ant = NULL;
        }
        delete(p);
        cout<<"elemento retirado da lista!\n";
    }
    else
    {
        cout<<"a lista esta vazia\n";
    }
}

void listar(Noptr p)
{
    if (!listavazia(p))
    {
        while(p != NULL)
        {
            cout<<p->info<<" "<<&p<<"\n";
            p = p->prox;
        }
    }
    else
    {
        cout<<"lista vazia\n";
    }
}


int main()
{
    Noptr topo = NULL;
    int op;
    
    do
    {
        cout<<"insira o valor de operação(Inserir(1),Retirar(2),Listar (3)\n";
        cin>>op;
        switch(op)
        {
            case 1:inserir(&topo);break;
            case 2:retirar(&topo);break;
            case 3:listar(topo);break;
        }
        
    }while(op!=0);
    
    return 0;
}