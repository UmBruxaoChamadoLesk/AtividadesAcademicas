#include <stdio.h>

int LeModelos (int VezesDeclara)
{
  int cont = 0;

  int Nmodelos;
  int QtdEstoq;
  int Qtd1000 = 0;

  while (cont <VezesDeclara)
    {
      printf ("\ninsira o numero de modelo e depois a quantidade em estoque\n");
      scanf ("%d%d", &Nmodelos, &QtdEstoq);
      cont++;
      if (QtdEstoq >= 1000)
      {
	    Qtd1000++;
	  }
    }
    
    return Qtd1000;
}

#include <stdio.h>

int main ()
{
  int vezes;
  do
    {

      printf("\ninsira quantas vezes iras declarar modelo de carros e sua quantidade em estoque\n digite 0 para fechar o programa\n");
      scanf ("%d", &vezes);
      int Estoq1000 = LeModelos (vezes);
      printf ("\tcarros com estoque acima de 1000: *%d*\n\n ",Estoq1000);
    }
  while (vezes > 0);
      

  return 0;
}

