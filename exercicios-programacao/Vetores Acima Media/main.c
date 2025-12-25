#include <stdio.h>

int AcimaMedia(float V[],int qtd,float media)
{
int cont,acimaMd;
cont=acimaMd=0;


 while(cont<qtd)
 {
  if(V[cont]>media)  
  {
      acimaMd++;
  }
  
  cont++;
 }
 
    return acimaMd;
}


int main()
{
  float Vnum[4]={8,17,9.2,4.8};
  int qatd =4;
  float MediaVetor= (Vnum[0]+Vnum[1]+Vnum[2]+Vnum[3])/qatd;
  
  int Mdprint=AcimaMedia(Vnum,qatd,MediaVetor);
  printf("Numeros acima da media %d\n",Mdprint);
  
    return 0;
}

