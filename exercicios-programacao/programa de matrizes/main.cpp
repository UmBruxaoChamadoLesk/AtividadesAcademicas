#include <iostream>

void MontaMatriz(float matriz[99][99],int Linha,int Coluna)
{
    for(int i=1;i<=Linha;i++)
    {
        for(int j=1;j<=Coluna;j++)
        {
            printf("insira o elemento %i%i\n",i,j);
            scanf("%f",&matriz[i][j]);
        }
    }
}

void PrintaMatriz(float matriz[99][99],int Linha,int Coluna)
{
    for(int i=1;i<=Linha;i++)
    {
        printf("|");
        for(int j=1;j<=Coluna;j++)
        {
            printf(" %f ",matriz[i][j]);
        }
        printf("|");
        printf("\n");
    }
}

float multiplicador(float matriz[99][99],int i, int j)
{
   float m = (matriz[i][j]/matriz[j][j]);
   
   return m;
}

void ReduçãoGauss(float matriz[99][99],int Linha, int Coluna)
{
    
    //normalização
    
     for(int i=1;i<=Linha;i++)
    {
        for(int j=1;j<=Coluna;j++)
        {
            int m = multiplicador(matriz,i,j);
            
            matriz[i][j] = m;
        }
    }
    
    //Redução
    
     for(int i=1;i<=Linha;i++)
    {
        for(int j=1;j<=Coluna-1;j++)
        {
            int m = multiplicador(matriz,i+1,j);
            
            matriz[i+1][j] = matriz[i+1][j]-matriz[i][j]*m;
        }
    }
}

int main()
{
    float matriz[99][99];
    int Lin,Col,x;
    
    do
    {
        printf("montar matriz(1)\nprintar matriz(2)\nreduzir matriz(3)\nsair(0)\n");  
        scanf("%i",&x);
        switch(x)
        {
            case 1:
            printf("quantas linhas tem a matriz\n");  
            scanf("%i",&Lin);
            printf("quantas colunas tem a matriz\n");
            scanf("%i",&Col);
            MontaMatriz(matriz,Lin,Col);
            PrintaMatriz(matriz,Lin,Col);
            break;
            
            case 2:
            PrintaMatriz(matriz,Lin,Col);
            break;
            
            case 3:
            ReduçãoGauss(matriz,Lin,Col);
            break;
        }
    }while(x!=0);
   
    

    return 0;
}