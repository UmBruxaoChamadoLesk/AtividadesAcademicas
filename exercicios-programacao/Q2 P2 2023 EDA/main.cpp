#include <iostream>

struct playlist
{
    int codigo;
    struct playlist * prox;
};
typedef struct playlist *Noptr;  

bool ListaVazia(Noptr p)
{
    return(p==NULL);
}

void inserir(Noptr *top,Noptr *ult, int x)
{   Noptr aux;
    if(ListaVazia(*top))
    {
        *top = new playlist;
        *ult = *top;
        (*top)->prox = NULL;
        (*top)->codigo = x;
    }
    else
    {
        aux = new playlist;
        aux->codigo = x;
        aux->prox = *top;
        
        (*ult)->prox = aux;
        *ult = aux;
    }
}

int main()
{
    Noptr Topo = NULL;
    Noptr Ultimo = NULL;
    int x = 0;
    
    inserir(&Topo,&Ultimo,x);

    return 0;
}