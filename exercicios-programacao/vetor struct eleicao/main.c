#include <stdio.h>
#include <string.h>
#define MAX 10

typedef struct candidato 
{
    char nome[21]; //sao 15 candidatos 
} presidente;

typedef struct eleitorado
{
    char nomeCandidato[21];
    int  residencia;
} eleitor;

void leDadosCandidatos(presidente v[])
{
    int i;
    for(i=0;i<15;i++)
    {
        printf("insira nome do candidato %d\n",i+1);
        scanf("%s",v[i].nome);
    }
    
    return;
}

void leDadosEleitor(eleitor v[])
{
    int i,j;
    
    char voto[21];
    for(i=0;i<MAX;i++)
    {
        int t = 0;
        printf("VOTE IMEDIATAMENTE NO SEU CANDIDATO! ELEITOR %d\n",&i+1);
        
        
        
        scanf("%s",voto);
        for(j=0;(j<15) && (t==0) ;j++)
        {
            if(strcmp(voto,v[j].nomeCandidato)==0)
            {
                t=1;
                strcpy(v[i].nomeCandidato,voto);
                printf("mora no exterior?(0- não, 1-sim)\n");
                scanf("%d",&v[i].residencia);
            }
            printf("%d",strcmp(voto,v[j].nomeCandidato));
            if(t==0)
            {
                printf("\t***VOTO INVALIDADO POR ERRO TERRORISTA DO ELEITOR***\n\nPARA PROTEGER A DEMOCRACIA,\nSUA MORTE FOI MARCADA PARA DIA 37/05/54802 NO PARQUE DA INDEPENDENCIA\nESTAREMOS ESPERANDO VOCE!!!\n");
            }
        }
        
        
        
        
    }
    
    
    
    return;
}

int contaVotos(presidente v[],eleitor vL[],int *VotoNacio,int *VotoExt)
{
    int i,j;
    int qtdvoto=0;
    
    for(i=0;i<15;i++)
    {
        for(j=0;j<MAX;j++)
        {
            if(strcmp(vL[i].nomeCandidato,v[j].nome) == 0)
            {
                qtdvoto++;
            }
            
            if(vL[i].residencia==0)
            {
                *VotoNacio++;
            }
            else
            {
                *VotoExt++;
            }
        }
    }
    
    return qtdvoto;
}

void ordena(presidente v[])
{
    int i,qtd;
    char aux[21];
    
    qtd = 15;
    
    while(qtd>1)
    {
     
        for(i=0;i<qtd;i++)
        {
            if(strcmp(v[i+1].nome,v[i].nome)<0)
            {
                strcpy(aux,v[i].nome) ;              //aux = v[i].nome;
                strcpy(v[i].nome,v[i+1].nome);       // v[i].nome = v[i+1].nome
                strcpy(v[i+1].nome,aux);                  //v[i+1].nome = aux
            }
        }
        
        qtd--;
    }
    
    return;
    
}

void geraRelatorio(presidente v[],eleitor vL[])
{
    int Cvotos[15];
    int i;

    for(i=0;i<15;i++)
    {
        int votosNacional; int votosExterior; 
        votosNacional = votosExterior = 0;
        Cvotos[i] = contaVotos(v,vL,&votosNacional,&votosExterior);
        printf("nome do candidato: %-10s total de votos locais:%-10d totais de votos exterior: %-10d total geral de votos %-10d ",v[i].nome,votosNacional,votosExterior,votosNacional+votosExterior);
    }
    
    
    return;
}

int main()
{
    presidente pessoa[15];
    eleitor pebleu[MAX];
    
    
    leDadosCandidatos(pessoa);
    leDadosEleitor(pebleu);
    ordena(pessoa);
    geraRelatorio(pessoa,pebleu);

    return 0;
}

