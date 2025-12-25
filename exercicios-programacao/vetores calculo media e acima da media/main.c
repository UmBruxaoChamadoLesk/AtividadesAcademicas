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

int ContagemEmedia(float v[], int *qtd)
{
    int cont = 0;
    int user;
    int soma;
    do
    {
        printf("digite um valor para o proximo vetor ou 0 para encerrar e fazer a media");
        scanf("%d",&user);
        if (user>0)
        {
            printf("************Debug**************\ninput: %d\n", user); //debug
            v[cont] = user; 
            soma = v[cont] + soma;
            cont++;
            *(qtd)= *(qtd)+1;
            printf("cont%d\nqtd:%d\nsoma%d:**************************\n",cont,*qtd,soma); //debug
        }
    }while(user != 0);
    
    cont = 0;
    while(cont < *qtd)
    {
        printf("%1.f",v[cont]);
        if(cont < *(qtd)-1)
        {
            printf("+");
        }
        else if(cont == *(qtd)-1)
        {
            printf("/%d",*qtd);
        }
        cont++;
    }
    
    float media = soma  / *qtd;
    printf("\nmedia de vetores:%.2f\n",media);
    
    return media;
}



int main()
{
  float Vnum[50];
  int qatd=0;
 
  int MediaVetor = ContagemEmedia(Vnum,&qatd);
  printf("qatd:%d\n",qatd);
  int Mdprint=AcimaMedia(Vnum,qatd,MediaVetor);
  printf("Numeros acima da media %d\n",Mdprint);
  
    return 0;
}




