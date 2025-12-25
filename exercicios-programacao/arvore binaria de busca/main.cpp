#include <iostream>

using namespace std;

struct No
{
    int info;
    
    struct No *esq;
    struct No *dir;
};
typedef struct No *Noptr;

bool EnderecoVazio(Noptr p)
{
    return(p==NULL);
}

void inserir(Noptr *p,int x)
{
    if (EnderecoVazio(*p))
    {
        *p = new No;
        (*p)->info = x;
        (*p)->esq = NULL;
        (*p)->dir = NULL;
    }
    else
    {
        if(x<(*p)->info)
        {
            inserir(&(*p)->esq,x);
        }
        else
        {
            inserir(&(*p)->dir,x);
        }
    }
}

bool buscar(Noptr p, int x)
{
    bool achei = false;
    if(EnderecoVazio(p))
    {
        cout << "\nArvore nao possui elementos" << endl;
    }
    else
    {
        if(x==(p->info))
        {
            cout<<"\nO elemento"<< p->info <<"foi encontrado\n";
            achei = true;
        }
        else
        {
            if(x<(p->info))
            {
                buscar((p->esq),x);
            }
            else
            {
                buscar((p->dir),x);
            }
        }    
    }
    return achei;
}

void listarEmOrdem(Noptr p)
{
    if(!EnderecoVazio(p))
    {
        listarEmOrdem(p->esq);
        cout<<"\t"<<p->info;
        listarEmOrdem(p->dir);
    }
}

void listarPreOrdem(Noptr p)
{
    if(!EnderecoVazio(p))
    {
        cout<<"\t"<<p->info;
        listarPreOrdem(p->esq);
        listarPreOrdem(p->dir);
    }
}

void listarPosOrdem(Noptr p)
{
    if(!EnderecoVazio(p))
    {
        listarPosOrdem(p->esq);
        listarPosOrdem(p->dir);
        cout<<"\t"<<p->info;
    }
}

int soma(Noptr p)
{

    if(EnderecoVazio(p))
    {
        cout<<"\nlista vazia\n";
        return 0;
    }
    
    int somaEsq = soma(p->esq);
    int somaDir = soma(p->dir);
    
    return p->info + somaEsq + somaDir;
    
}

int maiorVal(Noptr p)
{
    if(EnderecoVazio(p))
    {
        cout<<"\nlista vazia\n";
        return 0;
    }
    int m = p->info;
    
    int maiorEsq = maiorVal(p->esq);
    int maiorDir = maiorVal(p->dir);
    
    if(maiorEsq > m && maiorEsq > maiorDir)
    {
        m = maiorEsq;
    }
    else
    if(maiorDir > m && maiorEsq < maiorDir)
    {
        m = maiorDir;
    }
    
    
    return m;
    
}

Noptr maior(Noptr *p)
{
    Noptr t;
    
    t=*p;
    
    if((t->dir)==NULL)
    {
        *p = (*p)->esq;
        return t;
    }
    else
    {
        return(maior(&((*p)->dir)));
    }
}

void remover(Noptr *p, int x)
{
    if(EnderecoVazio(*p))
    {
        cout<<"\nlista vazia\n";
        return;
    }
    
    
    Noptr aux;
    if (x==((*p)->info))
    {
        aux = *p;
        if(((*p)->esq)==NULL)
        {
            *p = (*p)->dir;
        } 
        else
        {
            if(((*p)->dir)==NULL)
            {
                *p = (*p)->esq; 
            }
            else
            {
                aux = maior(&((*p)->esq));
                (*p)->info = aux->info;
            }
        }    
    }
    else
    {
        if(x<((*p)->info))
        {
            remover(&((*p)->esq),x);
        }
        else
        {
            remover(&((*p)->dir),x);
        }
    }
}

int menu()
{
    int opcao;
    cout<<"\n----Menu Principal----\n\n"
    <<"\n1.Inserir No na arvore"
    <<"\n2.Remover No na arvore"
    <<"\n3.Listar todos os Nos da arvore"
    <<"\n4.Buscar No"
    <<"\n5 somatório"
    <<"\n6 maior valor"
    <<"\n0.Sair"
    <<"\nDigite um numero: ";
    
    cin>>opcao;
    return opcao;
}

int listarNos()
{
    int opcao;
    cout<<"\n\nTipos de listagem"
    <<"\n1.em Ordem"
    <<"\n2.Pre Ordem"
    <<"\n3.Pos Ordem"
    <<"\n\nDigite o numero correspondente ao tipo de listagem: ";
    
    cin>>opcao;
    return opcao;
}

int main()
{
    Noptr raiz;
    
    int op1,op2,x;
    bool achei;
    raiz = NULL;
    
    do
    {
        op1 = menu();
        switch(op1)
        {
            case 1:
                cout<<"\nElemento a inserir: ";
                cin>>x;
                inserir(&raiz,x);
                break;
            case 2:
                cout<<"\nElemento para remover: ";
                cin>>x;
                remover(&raiz,x);
                break;
            case 3:
                op2 = listarNos();
                if(op2==1){listarEmOrdem(raiz);};
                if(op2==2){listarPreOrdem(raiz);};
                if(op2==3){listarPosOrdem(raiz);};
                break;
            case 4:
                cout<<"\nElemento para buscar: ";
                cin>>x;
                achei = buscar(raiz,x);
                if(!achei)
                {
                    cout<<"Elemento nao encontrado";
                }
                break;
            case 5:
                cout<<"\nsomatório: "<<soma(raiz)<<"\n";
                break;
            case 6:
                cout<<"\nMaior valor da arvore: "<<maiorVal(raiz)<<"\n";
                break;
        }
        
    }while(op1 !=0);
    
    

    return 0;
}