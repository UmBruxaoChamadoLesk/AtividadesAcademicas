#include <stdio.h>

void situacao(float med, int *apr, int *rep)
{
 if (med >=5)
 {
     printf("\nAprovado gloria a DEUX");
     (*apr)++;
 }
 else
 {
     printf("\nReprovado,vira uber ai otario kakakkakaka");
    (*rep)++;    
 }
}

int main()
{ 
    int qtdapr, qtdrep,cont,matr;
    float nota1,nota2,med;
    qtdapr=qtdrep=0;
    for (cont=0;cont<40;cont++)
    {
        printf("\nDigite matricula e 2 notas:");
        scanf(" %d %f %f",&matr,&nota1,&nota2);
        med=(nota1+nota2)/2;
        printf("\nmatricula: %d\tMedia:%.1f",matr,med);
        situacao(med,&qtdapr,&qtdrep);
    }
    printf("\n Quantidade aprovados:%d",qtdapr);
    printf("\n Quantidade reprovados:%d",qtdrep);
    return 0;
}
