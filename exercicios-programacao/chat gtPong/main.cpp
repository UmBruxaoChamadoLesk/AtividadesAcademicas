#include <iostream>
#include <cstring>

using namespace std;

int pontuação(int p)
{
    p++;
    
    return p;
}

int main()
{
    int Sair,vida,pontos; Sair=0;
    
    while(Sair!=1)
    {
        vida = 3;
        pontos = 0;
        while(vida>=0)
        {
            cout<<"ping\n";
            char R[99];
            cin>>R;
        
            if (strcmp(R,"pong")!=0)
            {
                vida--;
                if(vida>=0)
                {
                    cout<<"errou!\nvida:"<<vida<<"\n";
                }
                
            }
            else
            {
                pontos = pontuação(pontos);
                cout<<"pontos: "<<pontos<<"\n";
            }
        
        }
        
        cout<<"\ntentar de novo?(digite 1 para sair)\n";
        cin>>Sair;
    }
    
    

    return 0;
}
