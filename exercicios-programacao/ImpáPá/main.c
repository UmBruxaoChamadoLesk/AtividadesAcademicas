#include <stdio.h>



void ImparPar(int n1)
{
    int ImpaPa = n1%2;
    
    if (ImpaPa==0)
    {
        n1=n1*2;
        printf("\no numero é par");
        printf("\no dobro do numero é:%d",n1);
        
        
    }
    
    else 
    {
        n1=n1*3;
        printf("\no numero é impar");
        printf("\no triplo do numero é:%d",n1);
        
        
    }
}

int main()
{
    int num;
    printf("\n insira um numero inteiro:");
    scanf("%d",&num);
    ImparPar(num);
    return 0;
}


