#include <iostream>

int buscaBinaria(int A[], int qtd, int x) {
    int inicio = 0;
    int fim = qtd - 1;

    while (inicio <= fim) {  
        int meio = (inicio + fim) / 2;  

        if (A[meio] == x) {
            return [meio];  
        } else if (A[meio] > x) {
            fim = meio - 1;  
        } else {
            inicio = meio + 1;  
        }
    }

    return -1;  
}


int main()
{
    std::cout<<"Hello World";

    return 0;
}