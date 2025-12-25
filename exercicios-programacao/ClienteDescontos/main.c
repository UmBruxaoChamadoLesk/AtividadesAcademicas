
#include <stdio.h>


char leValidaTipo ()
{
    char tipo;
    do
    {
        printf("\nSelecione o tipo de assinatura.\n");
        scanf(" %c",&tipo);
        if (tipo != 'V' && tipo !='E'&& tipo!='P')
        {
           printf("\ntipo invalido.");
           printf("\nRegistro erro:%c",tipo);
        }
    }while(tipo !='V' && tipo !='E' && tipo != 'P');
  printf("%c",tipo);
  return tipo;
}

int main ()
{
	char pessoa;
	float DescNac,DescImpo;
	
	leValidaTipo();
    
    printf("\nDesconto produtos nacionais:%.2f \nDesconto para importados:%.2f\n",DescNac,DescImpo);
  return 0;
}












