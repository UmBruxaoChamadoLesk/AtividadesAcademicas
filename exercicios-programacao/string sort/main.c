
#include <stdio.h>
#include <string.h>

void ordena(char v[100][81],int qtd)
{
    char aux[81];
    for(int j=0;j<qtd-1;j++)
    {
        int imenor=j;
        for(int i=j+1;i<qtd;i++)
        {
            if(strcmp(v[i],v[imenor])<0)
            {
                imenor=i;
            }
        }
        if(imenor!=j)
        {
            strcpy(aux,v[imenor]);
            strcpy(v[imenor],v[j]);
            strcpy(v[j],aux);
        }
    }
}

void print(char linhas[5][81])
{
    printf("\n");
    for(int i=0;i<5;i++)
    {
        
        printf(" %d %s.\n",strcmp(linhas[i],""),linhas[i]);
        
    }
}

int main()
{
    char textos[100][81]={"oeeeeadawdawdwadaw","aaaqdeliciia","uuuiiiizzzzzwwwzzzzwwwzzzwwwzzzz","cavalozzzzzzzzzzzzzzzzzzzzzz","ratinhoooooo"};
    
    ordena(textos,5);
    print(textos);
    

    return 0;
}

