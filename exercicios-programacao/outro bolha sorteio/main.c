#include <stdio.h>
#define MAX 10

int bubblesort(float v[],int qtd)
{
    for(int i=0;i<qtd-1;i++)
    {
        for(int j=i+1;j<qtd;j++)
        {
            if(v[i]>v[j])
            {
                int aux=v[i];
                v[i]=v[j];
                v[j]=aux;
                
                
            }
            //printf("***%2.f",v[i]); //debug bixo
        }
    }
}


int main()
{
    int quant = MAX;
    float algumaCoisa[MAX];
    
    for(int i=0;i<quant;i++)
    {
        scanf("%f",&algumaCoisa[i]);
    }
    
    bubblesort(algumaCoisa,quant);
    printf("\n");
    for(int i=0;i<quant;i++)
    {
        printf("%2.f ",algumaCoisa[i]);
    }


    return 0;
}

