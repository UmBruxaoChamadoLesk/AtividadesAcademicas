#include <stdio.h>
#define MAX 10

void organizador(int v[],int qtd)
{
    
 
    
    int i,j,aux=0;
    
    for(i=0;i<qtd;i++)
    {
            for(j=0;j<qtd-1;j++)
            {
                if(v[j]>v[j+1])
                {
                    aux=v[j];
                    v[j]=v[j+1];
                    v[j+1]=aux;
                }
             printf("***%d %d %d %d %d %d %d %d %d %d***",v[0],v[1],v[2],v[3],v[4],v[5],v[6],v[7],v[8],v[9]);//debug garaio
            }
    }

    
}

int main()
{
    int vnum[MAX];
    int qtd=MAX;
    int i;
    
    for (i=0;i<qtd;i++)
    {
      scanf("%d",&vnum[i]);
    }
    organizador(vnum,qtd);
    
    printf("\nprint:");
    
    int cont = 0;
    while(cont < qtd)
    {
        printf("%d, ",vnum[cont]);
        cont++;
    }

    return 0;
}





