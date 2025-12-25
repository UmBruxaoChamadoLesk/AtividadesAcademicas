#include <stdio.h>

int gasosaLucros(int vvendas[4][31],float vcombus[4][31])
{
    //exibir valor total das vendas no mes 
    //cada dia do mes, exibir valor total de cada combustivel
    int qtdVendas;
    float lucrogasosa;
    
    qtdVendas=0;
    
    int i,j;
    
    for (i=0;i<31;i++)
    {
        for(j=0;j<4;j++)
        {
            lucrogasosa = lucrogasosa + (vvendas[i][j] * vcombus[i][j]);
            qtdVendas = qtdVendas + vvendas[i][j];
            printf("total de vendas e lucro do dia %d da gasolina *%d: V:%d L:%.2f \n",i+1,j+1,vvendas[i][j],vvendas[i][j] * vcombus[i][j]);
        }
        
    }
    
    printf("total de vendas no mes:%d \n lucro no mes:%.2f",qtdVendas,lucrogasosa);
    
    
}

int main()
{
    int CombuVendas[4][31];
    float CombuPrecos[4][31];
    int i,j;
    
    for(i=0;i<31;i++)
    {
        printf("dia%d\n",i+1);
        for(j=0;j<4;j++)
        {
            printf("\ndigite quantidade de vendas e o preco de cada combustivel.");
            printf("\ncombustivel %d:",j+1);
            printf("numero de vendas:\n");
            scanf("%d",&CombuVendas[i][j]);
            printf("preco do combustivel no dia:\n");
            scanf("%f",&CombuPrecos[i][j]);
            
        }
        printf("\n\n");
    }
    
    gasosaLucros(CombuVendas,CombuPrecos);

    return 0;
}


