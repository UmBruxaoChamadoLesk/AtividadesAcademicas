#include <iostream>

using namespace std;

struct No 
{
    int info;
    struct No *prox;
    struct No *ant;
    
};

typedef struct No *Noptr;

bool ListaVazia(Noptr p)
{
    return (p == NULL);
}

void inserir(Noptr *p,Noptr *base, int x)
{
    Noptr aux;
    
    if(ListaVazia(*p))
    {
        *p = new No;
        (*p)->info = x;
        (*p)->prox=NULL;
        (*p)->ant=NULL;
        *base = *p;
        cout<<"\ttopo criado";
    }
    else
    {
        aux = new No;
        aux->info = x;
        
        (*p)->prox = aux;
        aux->ant = *p;
        aux->prox = *base;
        *p = aux;
    }
}

void remover(Noptr *p,Noptr *base, int x)
{
    Noptr aux = *p;

    if (ListaVazia(*p)) {
        cout << "\n\tLista Vazia\n";
        return;
    }

    while (aux != NULL) 
    {
        if (aux->info == x) 
        {
            if (aux->ant != NULL) 
            {
                aux->ant->prox = aux->prox;
                aux->prox->ant = aux->ant;
            } 
            else 
            {
                // Se aux->ant for NULL,remove primeiro elemento
                *base = aux->prox;
                
            }
            
            if(aux->ant==NULL && aux->prox==NULL)
            {
                *p=*base=NULL;
            }
            delete aux;
            cout << "\tElemento removido\n";
            return;
        }
        aux = aux->prox;
    }

    cout << "\tElemento não encontrado\n";
}

void listar(Noptr p, Noptr base)
{
    if (ListaVazia(p)) {
        cout << "\n\tLista Vazia\n";
        return;
    }

    Noptr aux = p;
    
    cout<<"\tultimo no "<<base->info<<"\n";
    while (aux != NULL) {
        cout << aux->info << " ";
        aux = aux->ant;
    }
    cout << endl;
}


void roleta(Noptr p, int x)
{
    int i = 0;
    
    if(ListaVazia(p))
    {
        cout<<"\t\nA lista esta vazia\n";
        return;
    }
    
    while(i < x)
    {
        p = p->prox;
        i++;
    }
    
    cout<<"\t|||||"<<p->info<<"|||||";
}

int menu(int u)
{
    cout<<"digite uma operacao"
    <<"\n1.inserir novo No"
    <<"\n2.remover No"
    <<"\n3.Listar"
    <<"\n4.roletar\n\n";
    cin>>u;
    
    return u;
}

int main()
{

Noptr topo,base;
topo = base = NULL;
int op,x;

do
{
    op = menu(op);
    switch(op)
    {
        case 1:
        cout<<"\ndigite um numero daora:\n\n";
        cin>>x;
        inserir(&topo,&base,x);
        break;
        case 2:
        cout<<"\nQual numero do elemento?";
        cin>>x;
        remover(&topo,&base,x);
        break;
        case 3:
        listar(topo,base);
        break;
        case 4:
        cout<<"girar quantas vezes?\n";
        cin>>x;
        roleta(base,x);
    }
}while(op!=0);

    return 0;
}