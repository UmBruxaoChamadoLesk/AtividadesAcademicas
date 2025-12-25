#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) 
{
    FILE* fp;
    int cont = 0; 
    char c, c1;

    if (argc < 2) 
    {
        printf("Siga o formato: %s [arquivo1] [arquivo2]...\n", argv[0]);
        return 1;
    }

    int i = 1;
    while (i < argc) 
    {
        fp = fopen(argv[i], "r");

        if (fp == NULL) 
        {
            printf("Arquivo %s nao encontrado\n", argv[i]);
            i++;
            continue;
        }

        while ((c = fgetc(fp)) != EOF) 
        {
            cont = 1; 
            while ((c1 = fgetc(fp)) != EOF && c == c1) 
            {
                cont++; 
            }
            fprintf(stdout, "%d", cont); 
            fwrite(&c, sizeof(char), 1, stdout); 
        }

        fclose(fp);
        printf("\n");
        i++;
    }
    return 0;
}


