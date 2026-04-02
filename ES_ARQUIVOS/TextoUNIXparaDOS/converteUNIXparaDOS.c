#include <stdio.h> 
#include <stdlib.h>

int main(int argc, char **argv)
{
    FILE *file = fopen(argv[1],"rb");

    if(file == NULL)
    {
        printf("arquivo nao existe");
        return 1;
    }

    fseek(file,0,SEEK_END);
    long tamanhoArq = ftell(file);
    char *buffer = malloc(tamanhoArq+1);

    fseek(file,0,SEEK_SET);
    fread(buffer,1,tamanhoArq,file);
    buffer[tamanhoArq] = '\0';

    printf("%s",buffer);
    free(buffer);
    fclose(file);
    return 0;

    
}
