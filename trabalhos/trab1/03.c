#include <stdio.h>

int potencia(int b, int n){
    // Caso Base: Se n for maior que 0, retorna b * potencia(b, n-1), o passo recursivo. Caso contrário, retorna 1.
    if(n>0){
        return b * potencia(b, n-1);
    }
    return 1;
}

int main() {
    int b, n;
    printf("Digite a base: ");
    scanf("%d", &b);
    printf("Digite o expoente inicial: ");
    scanf("%d", &n);

    printf("Potencia: %d\n", potencia(b, n));
    return 0;
}