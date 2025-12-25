#include <iostream>

void sograu2(Noptr p)
{
    if(ListaVazia(p))
    {
        return;
    }
    
    sograu2(p->esq);
    sograu2(p->dir);
    
    if(p->esq != NULL && p->dir != NULL)
    {
        cout<<" "<<p->info;
    }
}

int main()
{
    std::cout<<"Hello World";

    return 0;
}