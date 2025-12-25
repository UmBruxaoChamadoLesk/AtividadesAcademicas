#include <stdio.h>
#define ANOS 6
#define MESES 12
void CarrosVenda(int vvendas[ANOS][MESES],int vpreco[])
{
    //vvendas é vetor de vendas dos carros durante 6 anos e seus respectivos meses
    //vpreco é o preço anual dos carros vendidos durante o intervalo de 2010 a 2015.
    /* a quantidade de vendas deve entrar no vetor de meses
    ao completar a casa dos meses, a casa dos anos deve ser somado +1.
    Repita até chegar em na casa [5] [11]*/
    
    int TotalAnual,LucroAnual;  TotalAnual=LucroAnual=0;
    int i,j;
    int ano = 2010;
    for(i=0;i<ANOS;i++)
    {
        
        for(j=0;j<MESES;j++)
        {
            TotalAnual += vvendas[i][j];
            LucroAnual = vvendas[i][j] * vpreco[i];
        }
        
        
        printf("total vendas no ano de %d: %d\nlucro anual:R$%d\n",ano,TotalAnual,LucroAnual);
        ano++;
    }
    
    
}

int main()
{
    int vendaCarros[ANOS][MESES];
    int CarPrecoAnual[ANOS];
    int ano = 2010;
    int i,j;
    
    printf("digite o preco anual e a quantidade de carros vendidos para cada mes do ano:\n");
    
    for(i=0;i<ANOS;i++)
    {
        printf("\nano %d \n\n",ano);
        printf("preco anual: ");
        scanf("%d",&CarPrecoAnual[i]);
        for(j=0;j<MESES;j++)
        {
            printf("\nmes %d\n",j+1);
            printf("digite numero de vendas no mes:\n");
            scanf("%d",&vendaCarros[i][j]);
        }
        ano++;
    }

    CarrosVenda(vendaCarros,CarPrecoAnual);
    
    return 0;
}





