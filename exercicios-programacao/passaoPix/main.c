/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    char PIX[50];
    int seila[10];
    printf("\npassa o pix"); 
    for (int i=0; i<9; i++){
        scanf("%d", &seila[i]);
    }
    printf("\npassa o pix denovo e em texto bixo");
    for (int i=0; i<3; i++){
        scanf("%s", &PIX[i]);
    }
    return 0;
}


