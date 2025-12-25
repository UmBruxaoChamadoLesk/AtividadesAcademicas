#include <stdio.h>
#include <string.h>

void leDadosCargos(char cargos[20][31],float notasMinimas[20][2])
{
    for(int i=0;i<20;i++)
    {
        printf("digite nome do cargo, nota minima titular e nota minima especifica\n");
        scanf(" %[^\n]",cargos[i]);
        scanf("%f",&notasMinimas[i][0]);
        scanf("%f",&notasMinimas[i][1]);
    }
}

int calculaNotaFinal(float *media,float notaMinimaTitulos,float notaMinimaEspecifica)
{
    float notas[5];
    int qtdZero = 0;
    int notabaixa = 0;
    float soma = 0;
    for(int i=0;i<5;i++)
    {
        if(i==0)
        {
            printf("digite nota da prova titular:\n");
        }
        else
        {
            printf("digite nota da prova especifica %d:\n",i);
        }
        scanf("%f",&notas[i]);
        soma += notas[i];
        if(notas[i]==0)
        {
            qtdZero++;
        }
        else if((i==0) && (notas[i] < notaMinimaTitulos) || (i>0) && notas[i]<notaMinimaEspecifica)
        {
            notabaixa++;
        }
    }
    
    if((qtdZero==0) && (notabaixa == 0))
    {
        *media = soma / 5;
    }
    else
    {
        *media = 0;
    }
    
    return qtdZero;
}

int busca(char cargos[20][31],char cargo[31])
{
    for(int i=0;i<20;i++)
    {
        if(strcmp(cargos[i],cargo)==0)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    char cargos[20][31];
    float notasMinimas[20][2];
    char nome[31];
    char cargo[31];
    
    leDadosCargos(cargos, notasMinimas);
    for(int i=0;i<10500;i++)
    {
        printf("digite nome e cargo:\n");
        scanf(" %[^\n]",nome);
        scanf(" %[^\n]",cargo);
        
        int id = busca(cargos,cargo);
        if(id == -1)
        {
            printf("cargo não existente\n");
            
        }
        
        else
        {
            float media;
            int qtdZero = calculaNotaFinal(&media, notasMinimas[id][0],notasMinimas[id][1]);
            if(media>0)
            {
                printf("voce passou com %.2f de media\n",media);
            }
            else if(qtdZero>0)
            {
                printf("candidato %s foi reprovado com %d provas zeradas.",nome,qtdZero);
            }else
            {
                printf("candidato %s foi reprovado por nota baixa\n",nome);
            }
        }
        
    }
    return 0;
}

