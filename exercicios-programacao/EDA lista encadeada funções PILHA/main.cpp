#include <iostream>

void inserir(Noptr *p, int x)
{
    if(listaVazia(*p))
    {
        *p = new no;
        (*p)->prox = NULL;
        (*p)->info = x;
        return;
    }
    
    Noptr aux = new no;
    aux->info = x;
    aux->prox = *p;
    *p = aux;
    
}


int main()
{
    std::cout<<"Hello World";

    return 0;
}