#include <stdio.h>
#define MAX 50
struct aluno
{
  int matr;
  float md;
};
typedef struct aluno talu;

int busca(talu v[], int elemproc, int qtd)
{
    int cont;
    for(cont = 0;cont <qtd;cont++)
    {
        if(v[cont].matr==elemproc)
        {
            return cont;
        }
    }
    return -1;
}
int leitura(talu v[])
{
    int cont, matricula;
    float nota1,nota2;
    cont=0;
    printf("Digite matricula ou digite -1 para encerrar");
    scanf("%d",&matricula);
    while(matricula != -1 && cont < MAX)
    {
        v[cont].matr = matricula;
        printf("Digite 2 notas: ");
        scanf("%f%f",&nota1,&nota2);
        v[cont].md=(nota1+nota2)/2;
        cont++;
        printf("Digite a matricula ou -1 para encerrar: ");
        scanf("%d",&matricula);
    }
    return cont;
}

int main()
{
    talu valunos[MAX];
    int qtdalunos,matrpesq,pos;
    qtdalunos = leitura(valunos);
    printf("\nDigite matricula a ser pesquisada ou 0 para encerrar:");
    scanf("%d",&matrpesq);
    while(matrpesq !=0)
    {
        pos = busca(valunos,matrpesq,qtdalunos);
        if(pos == -1)
        {
            printf("\nAluno inexistente");
        }
        else
        {
            printf("\nMedia:%.1f",valunos[pos].md);
        }
        printf("\nDigite matricula a ser pesquisada ou 0 para encerrar");
        scanf("%d",&matrpesq);
    }
    
    return 0;
}

