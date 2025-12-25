#include <stdio.h>
#define MAX 10573

struct conta
{
  int NumeroConta;
  float saldo;
};
typedef struct conta cliente;


int exibe(cliente v[],int denominadorMedia)
{
    int cont=0;
    int soma=0;
    float media;
    
    while(cont<MAX)
    {
        
        soma = soma + v[cont].saldo;
        cont++;
    }
    
    media = soma/denominadorMedia;
    
    cont=0;

    
    while(cont<MAX)
    {
      if(v[cont].NumeroConta!=0)
      {
        printf("\n\nnumero da conta: %d \n Saldo:%.2f",v[cont].NumeroConta,v[cont].saldo);
        if(v[cont].saldo>media)
        {
          printf("\nseu saldo esta acima da media");
        }
        else if(v[cont].saldo==media)
        {
          printf("\nseu saldo esta na media");
        }
        else
        {
          printf("\nseu saldo esta abaixo da media");
        }
      }
      
      cont++;
    }
    
    printf("media:R$%.2f",media);
}

void inicializa(cliente *v)
{
    int cont = 0;
    while(cont<MAX)
    {
        v[cont].NumeroConta=0;
        v[cont].saldo=0;
        cont++;
    }
    
}

void averigua(cliente *v)
{
    int cont=1;
    
    printf("\n");
    scanf(" %d",&v->NumeroConta);

    while(cont < MAX && v->NumeroConta !=0)
    {
        cont++;
         
        if(v->NumeroConta == v[cont].NumeroConta)
        {
            v->saldo = v[cont].saldo;
         
        }
    } 
   
    return;
}

int main()
{
    
  cliente pessoa[MAX];
  int DenoMd,cont;
  DenoMd = cont = 0;
  
  inicializa(pessoa);
  
  printf("digite numero da conta(ou 0 para encerrar o programa): \n");
  averigua(&pessoa[cont]);
  
  if (pessoa[cont].NumeroConta!=0)
  {
      DenoMd++;
      printf("\ndigite saldo: ");
      scanf("%f",&pessoa[cont].saldo);
  }
  
  while(pessoa[cont].NumeroConta!=0)
  {
      cont++;
      
      
      printf("digite numero da conta(ou 0 para encerrar o programa): \n");
      averigua(&pessoa[cont]);
      
      if (pessoa[cont].NumeroConta!=0)
      {
          DenoMd++;
         printf("\ndigite saldo: ");
         scanf("%f",&pessoa[cont].saldo);
      }
      
  }
  
  exibe(pessoa,DenoMd);

    return 0;
}


