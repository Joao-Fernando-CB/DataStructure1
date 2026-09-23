#include <stdio.h>

int fatorial(int n){
    
    // Caso Base: Se n for maior que 0, retorna n * fatorial(n-1), o passo recursivo. Caso contrário, retorna 1.
    if(n>0){
        return n * fatorial(n-1);
    }
    return 1;
}

int main() {
    int num;
    printf("Digite o número inicial: ");
    scanf("%d", &num);

    printf("Fatorial: %d\n", fatorial(num));
    return 0;
}