#include <stdio.h>
#include <string.h>
#define MAX 3

struct itemloja
{
    char nome[31];
    int estoque;
    int preco;
};
typedef struct itemloja produto;

int leitura(char vnome[31],produto v[])
{
    int cont,qtdlido;
    cont = qtdlido = 0;
    
    char ProdPesquisa[31]; 
    strcpy(ProdPesquisa,vnome);
    
   do 
   {
       if(strcmp(v[cont].nome,ProdPesquisa)==0)
       {
           printf("\nproduto:%3s\nestoque:%3d\npreco:%3d\n",v[cont].nome,v[cont].estoque,v[cont].preco);
           qtdlido++;
       }
       
       cont++;
   }while((strcmp(v[cont].nome,ProdPesquisa)!=0) || cont == MAX-1);
   
   if(qtdlido == 0)
   {
       printf("\nproduto inexistente\n");
   }
   
   return qtdlido;
   
    
}



int main()
{
    produto N[MAX];
    int i;
    
    for(i=0;i<MAX;i++)
    {
        printf("nome do produto %d ",i);
        scanf(" %[^\n]",N[i].nome);
        printf("\nquantidade em estoque:\n");
        scanf("%d",&N[i].estoque);
        printf("\npreco do produto.\n");
        scanf("%d",&N[i].preco);
    }
    
    char pesquisa[31];
    int qtdleituras = 0;
    
    do
    {
        printf("\ndigite o nome de um produto a consultar:\n");
        scanf(" %[^\n]",pesquisa);
        qtdleituras = qtdleituras + leitura(pesquisa,N);
        
        
    }while(strcmp(pesquisa,"fim")!=0);
    
    printf("\nquantidade de leituras: %d",qtdleituras);
 


    return 0;
}







