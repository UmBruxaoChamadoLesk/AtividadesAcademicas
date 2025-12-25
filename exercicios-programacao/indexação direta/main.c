#include <stdio.h>
#define ALU 100
#define TOT 11

void inicializa (int v[])
{
  int cont;
  for (cont = 0; cont < TOT; cont++)
    {
      v[cont] = 0;
    }
}

void exibe (int v[])
{
  int cont;
  for (cont = 0; cont < TOT; cont++)
    {
      printf ("\nNota %d: %d aluno(s)", cont, v[cont]);
    }
}

int main ()
{
  int vqtd[TOT], cont, nota;
  inicializa (vqtd);
  for (cont = 0; cont < ALU; cont++)
    {
      printf ("Digite a nota de 0 a 10:");
      scanf ("%d", &nota);
      vqtd[nota]++;
    }
  exibe (vqtd);


  return 0;
}
