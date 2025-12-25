#include <stdio.h>
#include <string.h>

void lefrase(char V[3][99])
{
    int cont=0;
    
    while(cont<3)
    {
        scanf(" %[^\n]",V[cont]);
        
        cont++;
        
    }
}

void buscaFrase(char V[3][99],int TamanhoVetor, char Elemproc[99])
{
    int i;
    for(i=0;i<TamanhoVetor;i++)
    {
        printf("\n%d",i);
        if(strcmp(V[i],Elemproc) == 0)
        {
            printf("\n %s",V[i]);
            
            return;
        }
        else if(strcmp(V[i],Elemproc) != 0 && i== TamanhoVetor-1)
        {
            printf("\nnão achei foi nada");
        }
    }
}

int main()
{
    char Vstrings[3][99];
    int qtdV=3;
    char pesquisa[99];
    
    lefrase(Vstrings);
    
    do
    {
     printf("\n digite a frase certinho para buscar ou fim para sair ");
     scanf(" %[^\n]",pesquisa);
     buscaFrase(Vstrings,qtdV,pesquisa);
     
    }while(strcmp("fim",pesquisa));
    
   printf("%s %s %s",Vstrings[0],Vstrings[1],Vstrings[2]);
    return 0;
}
