#include <stdio.h>

int NumTabuada(int Num)
{
    int i;
    int Numero = Num;
    
    
    for (i=1;i<11;i++)
    {
        
        printf("\n%d * %d = %d",Num,i,Num * i);
        
        
    }
    
}


int main()
{
    int NumUser;
    
    printf("insira o numero para ver sua tabuada");
    scanf("%d",&NumUser);
    NumTabuada(NumUser);

    return 0;
}
