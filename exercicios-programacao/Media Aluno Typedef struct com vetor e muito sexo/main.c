#include <stdio.h>
#define MAX 5
struct aluno
{
    int matr;
    float md;
    
};
typedef struct aluno talu;

void exibe(talu v[],int qtd, float mdturma)
{
    int cont;
    for(cont=0;cont<qtd;cont++)
    {
        printf("\nMatricula:%d",v[cont].matr);
        printf("\nMedia:%.2f",v[cont].md);
        
        if(v[cont].md>mdturma)
        {
            printf("\nAcima da media da turma");
        }
        else
        {
            if(v[cont].md==mdturma)
            {
            printf("\nNa media da turma");
            }
            else
            {
                printf("\nAbaixo da media da turma");
            }
        } 
        
    }
}

int main()
{
      int cont, matricula;
      talu valunos[MAX];
      float somamd,nota1,nota2,mdturma;
      cont=somamd=0;
      printf("Digite a matricula ou 0 para encerrar:");
      scanf("%d",&matricula);
      while(matricula!=0 && cont < MAX)
      {
          printf("Digite as 2 notas: ");
          scanf("%f%f",&nota1,&nota2);
          valunos[cont].matr = matricula;
          valunos[cont].md = (nota1 + nota2) / 2;
          somamd += valunos[cont].md;//somand = somand + valunos[cont]
          cont++;
          printf("\nDigite a matricula ou 0:");
          scanf("%d",&matricula);
          
      }
      if (cont!=0)
      {
          mdturma = somamd/cont;
          exibe(valunos,cont,mdturma);
      }

    return 0;
}

