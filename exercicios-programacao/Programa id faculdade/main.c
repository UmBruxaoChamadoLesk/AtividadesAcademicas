#include <stdio.h>



int LeMat(int Ano, int Sem, int Num)
{
    if ((11 >= Ano <= 22) && (Sem == 1 || Sem == 2)  && (0 >= Num <= 90)) 
    {
        
        return 0;
    }
    else
    {
      
        return 1;
    }
    
    
}

int main()
{
    int aluno[5];
    printf("\nInsira o numero de matricula no formato AA,S,NN(ano,semestre,numero sequencial)" 
    "[pressione enter para inserir o primeiro componente(AA),repita com os outros componentes]:"); 
    scanf("%d%d%d",&aluno[1],&aluno[2],&aluno[3]);
    
    
    
    if (LeMat(aluno[1],aluno[2],aluno[3])==0)
    {
        printf("\nmatricula valida.");
    }
    else
    {
        printf("\nmatricula invalida.");
    }   
   return 0;
}

