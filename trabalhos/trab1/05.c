#include <stdio.h>

int contar(int n){
    
    // Caso Base: Se n for maior que 0, retorna 1 + contar(n/10), o passo recursivo. Caso contrário, retorna 0.
    if(n>0){
        return 1 + contar(n/10);
    }
    return 0;
}

int main() {
    int num;
    printf("Digite o número inicial: ");
    scanf("%d", &num);

    printf("Contagem de digitos: %d\n", contar(num));
    return 0;
}