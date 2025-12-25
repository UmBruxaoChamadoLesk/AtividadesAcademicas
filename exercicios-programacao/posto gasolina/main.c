#include <stdio.h>

void umPosto(int qtvendas, float *maior1, float *maior2,float *maior3)
{
    int cont,tipo;
    float valor;
    *maior1=*maior2=*maior3=0;
    for(cont=0;cont<qtvendas;cont++)
    {
        printf("\nDigite o tipo e valor da venda: ");
        scanf("%d%f",&tipo,&valor);
        if(tipo==1)
        {
            if(valor>*maior1)
            {
                *maior1=valor;
            }
        }
        else
        if(tipo==2)
        {
         if(valor > *maior2)
            {
                *maior2=valor;
            }
        }
        else
        
        {
            if(valor >*maior3)
            {
                *maior3=valor;
            }
        }
    }
}


int main()
{
    int cod,qtvendas;
    float maioralc,maiorgas,maiordie;
    printf("Digite codigo ou 0 para encerrar: ");
    scanf(" %d",&cod);
    while(cod!=0)
    {
        printf("Digite a quantidade de vendas");
        scanf("%d",&qtvendas);
        umPosto(qtvendas,&maioralc,&maiorgas,&maiordie);
        printf("\nMaior alcool:%.2f",maioralc);
        printf("\nMaior gasolina:%.2f",maiorgas);
        printf("\nMaior diesel:%.2f",maiordie);
        printf("\nDigite codigo ou 0 para encerrar: ");
        scanf("%d",&cod);
    }
    return 0;
}


