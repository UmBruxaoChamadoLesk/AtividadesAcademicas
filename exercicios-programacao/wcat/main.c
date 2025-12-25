#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10000

char bfLinha[BUFFER_SIZE];

int main(int argc,char* argv[])
{
    FILE* fp;
    
    int i=1;
    
    
    do
    {
        fp=fopen(argv[i],"r");
        
        if(fp==NULL)
        {  
        
            if(argc>1)
            {
            
            printf("cannot open file\n");
         
            }     
            exit(1);   
        
        }
        else
        {
            
            //printf("\ndebug argc:%d\n",argc);
            if(i<argc)
            {
                i++;
            }
            
            while(fgets(bfLinha,BUFFER_SIZE,fp))
            {
                fwrite(&bfLinha,BUFFER_SIZE,1,fp);
            }
            
        }
        fclose(fp);
    }while(i<argc);
  exit(0);
}





