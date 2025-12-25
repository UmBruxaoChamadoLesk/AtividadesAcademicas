
#include <stdio.h>
#define MAX 500


struct funcionario //sao 500 funcionarios
{
int departamento[10]; //de 1 a 10
int salario;
};

typedef struct funcionario func;


int inicializa(func *vFunc[])
{
    int cont=0;
    while (cont < MAX)
    {
     *vFunc[cont]->departamento = *vFunc[cont]->salario = 0;
     
     cont++;
    }
    return 0;
}

int exibe(func vFunc[])
{
    int cont=0;
    int menorSal=0;
    while (cont < MAX)
    {
     if(vFunc[cont].salario<menorSal)
     {
         menorSal=vFunc[];
     }
     cont++;
    }
    printf("menor salario do departamento %d: R$%.2f\n",vFunc[cont].departamento,vFunc[cont].salario);
    
    return 0;
}

int main()
{
  func pessoa[MAX];
  
  inicializa(&pessoa);
  exibe(&pessoa)
    return 0;
}

