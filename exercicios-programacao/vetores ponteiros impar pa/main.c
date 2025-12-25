#include <stdio.h>
#define MAX 100

int ImparParNum(int *vnum,int qtd)
{
    int cont;
    cont = 0;
    int par,impar;
    par=impar=0;
    
    printf("\n\n[DEBUG]\n");
    while (cont < qtd)
    {
        if(vnum[cont]%2==0)
        {
            
            vnum[cont]=0;
            par++;
            printf("%d\n",vnum[cont]);
        }
        else
        {
            vnum[cont]=1;
            impar++;
            printf("%d\n",vnum[cont]);
        }
        cont++;
    }
    printf("[FIM DEBUG]\n\n");
    printf("par:%d\nimpar:%d\n",par,impar);
}


int main()
{
    int vnumeros[MAX];
    int vqtd;
    int cont;
    
    
    scanf("%d",&vnumeros[cont]);
    
    while(vnumeros[cont]!=0)
    {
        cont++;vqtd++;
        
        scanf("%d",&vnumeros[cont]);
    }
    
    
    ImparParNum(vnumeros,vqtd);
   
    return 0;
}





