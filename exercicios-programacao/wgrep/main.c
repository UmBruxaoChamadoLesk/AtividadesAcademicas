#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100000

int main(int argc,char* argv[])
{
    char* padrao= argv[1];
    int i = 2;   
    do
    {
        char buffer[BUFFER_SIZE];
        FILE* fp = fopen(argv[i],"r");
        
        if(fp==NULL)
        {
            printf("erro ao abrir o arquivo *%s*\n",argv[i]);
            return 1;
        
        }
        
        while(fgets(buffer,BUFFER_SIZE,fp))
        {
            if(strstr(buffer,padrao))
            {
                printf("%s",buffer);
            }
            
        }
        
        i++;
        fclose(fp);
    }while(i<argc);
    
    

    return 0;
}
