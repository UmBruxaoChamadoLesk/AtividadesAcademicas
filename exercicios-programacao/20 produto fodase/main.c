#include <stdio.h>
#include <string.h>
#define MAXP 3
#define MAXC 21
struct itemLoja
{
    int codigo;
    char nome[MAXC];
    int estoque;
    int estpendente;
    int estdevolvida;
    
};
typedef struct itemLoja produto;

void leDadosProdutos(produto v[])
{
    int i;
    
    for (i=0;i<MAXP;i++)
    {
        printf("insira o codigo do produto %d: ",i+1);
        scanf(" %d",&v[i].codigo);
        printf("\ninsira o nome do produto: ");
        scanf(" %[^\n]",v[i].nome);
        printf("\ninsira a quantidade no estoque: ");
        scanf(" %d",&v[i].estoque);
        
    }
}


void geraSaida(produto v[])
{
    int i;

    printf("\t*************status estoque**************");
    
    for (i=0;i<MAXP;i++)
    {
        printf("\t codigo:%d \n nome: %s\n estoque:%d \n quantidade pendente:%d \n quantidade devolvida:%d",
        v[i].codigo,v[i].nome,v[i].estoque,v[i].estpendente,v[i].estdevolvida);
    }
}

void movimentacoes(produto *v,int elemproc)
{
    int cont,teste;
    char op; //solicitar ou devolver (s ^ d)
    int i;
    
    for(i=0;i<MAXP;i++)
   {
      
        if(elemproc == v[i].codigo)
        {
            teste = 1;
            printf("\ndigite a operação desejada(s/d): ");
            do
            {
                
                 //solicitar ou devolver (s ^ d)
                int u;
                scanf("%c",&op);
                    
                if(op == 's')
                {
                    printf("\ndigite a quantidade a solicitar: ");
                    scanf("%d",&u);
                    v[i].estpendente += u;
                    v[i].estoque -= u;
                }
                else if(op == 'd')
                {
                printf("\ndigite a quantidade a devolver: ");
                scanf("%d",&u);
                v[i].estdevolvida += u;
                v[i].estoque += u;
                
                }
            }while(op!='s' && op!='d');
        }
        else if((teste ==0 ) && (i == MAXP-1))
        {
            printf("\n\t[DEBUG]%d %d",elemproc,v[i].codigo); //debug
            printf("\tproduto inexistente\n\n");
        }
    }

    
}

int main()
{
    produto N[MAXP];
    int pesquisa;
    
    leDadosProdutos(N);
    
    printf("digite o codigo do produto: ");
    scanf("%d",&pesquisa);
    while(pesquisa !=0)
    {
       movimentacoes(N,pesquisa);
       printf("digite o codigo do produto: ");
       scanf("%d",&pesquisa);
    }
    
    geraSaida(N);

    
    return 0;
}





