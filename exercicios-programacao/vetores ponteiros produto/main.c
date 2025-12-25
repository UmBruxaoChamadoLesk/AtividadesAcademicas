#include <stdio.h>
#define MAX 5

int ProdutoVetores(int vnum[],int qtd)
{
    int cont,produto;
    cont = 0;
    produto = 1;
    
    while(cont<qtd)
    {
        printf("contagem %d  ",cont);
        printf("produto:%d * %d\n",produto,vnum[cont]);
        produto = produto * vnum[cont];
        cont++;
    }
}


int main()
{
    
    int qtdNum = 4;
    int vnumeros[4]={4,3,6,3};
    
    
    ProdutoVetores(vnumeros,qtdNum);
    
   
    return 0;
}
