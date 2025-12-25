#include <iostream>

struct no 
{
    int info;
    
    struct no* prox;
};

typedef struct no *Noptr;

void inserir(Noptr *p,Noptr *u, int x)
{
    if(listavazia(*p))
    {
        *p = new no;
        (*p)->info = x;
        (*p)->prox = NULL;
        *u = *p;
        return;
    }
    Noptr aux;
    
    aux = new no;
    aux->info = x;
    aux->prox = NULL;
    (*u)->prox = aux;
    *u = aux;
    
}

void removerFILA(Noptr *p,Noptr*u)
{
    if(listavazia(*p))
    {
        return;
    }
    
    if((*p)->prox==NULL) // se só tiver um nó, delete topo
    {
        delete(*p);
        return;
    }
    
    Noptr aux = *p;
    *p = (*p)->prox;
    delete(aux);
    
}


int main()
{
    std::cout<<"Hello World";

    return 0;
}