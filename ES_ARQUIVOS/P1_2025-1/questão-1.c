#include <stdio.h>
#include <stdlib.h>


struct registroTemporalCovid19
{
    int dia;
    int novos_casos;
    int obitos;
} typedef tempCovid;


int main(int argc, char **argv)
{
    FILE *file = fopen(argv[1],"rb");

        if(file == NULL)
        {
            printf("arquivo nao existe\n");
            return 1;
        }

    fseek(file,0,SEEK_END);
    int tamanhoArq = ftell(file);
    int tamanhoReg = sizeof(tempCovid);
    int qtdReg = (tamanhoArq/tamanhoReg);
    rewind(file);

    printf("tamanho do arquivo em bytes:%d\ntamanho do registro em bytes:%d\nquantidade de registros:%d\n",tamanhoArq,tamanhoReg,qtdReg);

    fclose(file);

    return 0;



}