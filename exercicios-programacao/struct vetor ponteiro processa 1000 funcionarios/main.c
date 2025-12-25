#include <stdio.h>
#define MAX 1000
struct funcionario 
{
    int matricula;
    int departamento; //1 a 10
    int idade;
};
typedef struct funcionario func;

void inicializa(func *v)
{
    printf("\n[DEBUG]função inicializa abriu\n"); //debug
    
    int cont=0;
    while(cont<MAX)
    {
        v[cont].matricula=0;
        v[cont].departamento=0;
        v[cont].idade=0;
        
        //printf("\n%d",v[cont].matricula);
        cont++;
    }
    
    
}

void exibe(func v[])
{
    
    int cont;
    int DepCont;
    cont = DepCont = 0;
    
    int Soma,Denominador;
    float Media;
    Media = Soma = 0;
    
    printf("\n[DEBUG]função exibe abriu\n"); //debug
    
    while (DepCont<11)
    {
        
        Soma = 0;
        Denominador = 0;
        cont = 0;
        while (cont < MAX)
        {
            if(v[cont].departamento==DepCont)
            {
                printf("departamento: %d",v[cont].departamento);
                Soma+= v[cont].idade;
                printf("\nsoma:%d\n",Soma);
                Denominador++;
             
            }
            cont++;
        }
        Media = Soma/Denominador;
        printf("departamento%d\n media de idade:%f\n",DepCont+1,Media);
        DepCont++;
    }
    
}

int main()
{
    func pessoa[MAX];
    int cont = 0;
    
    inicializa(pessoa);
    
    

    printf("matricula(ou 0 para sair):");
    scanf("%d",&pessoa[cont].matricula);
    
    if (pessoa[cont].matricula>0)
    {
        do
        {
            printf("\ndepartamento(1 a 10):");
            scanf("%d",&pessoa[cont].departamento);
            
        }while(pessoa[cont].departamento > 10 || 0 > pessoa[cont].departamento);
        
        printf("\nidade:");
        scanf("%d",&pessoa[cont].idade);
    
        while(cont < MAX && pessoa[cont].matricula>0)
        {
           cont++;
           printf("matricula(ou 0 para sair):");
           scanf("%d",&pessoa[cont].matricula);
        
           if (pessoa[cont].matricula>0)
           {
               do
               {
                    printf("\ndepartamento(1 a 10):");
                    scanf("%d",&pessoa[cont].departamento);
                    
               }while(pessoa[cont].departamento > 10 || 0 > pessoa[cont].departamento);
               printf("\nidade:");
               scanf("%d",&pessoa[cont].idade);
           }
        }
    }
    
    
    
    
    
    
    printf("\n\n[DEBUG]chamando funcao exibe..."); //debug
    
    exibe(pessoa);
    
    return 0;
}







