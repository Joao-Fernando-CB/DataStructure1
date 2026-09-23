#include <stdio.h>

int mdc(int a, int b){
    
    // Caso Base: Se b for igual a 0, retorna a. Caso contrário, retorna mdc(b, a % b).
    if(b == 0){
        return a;
    }
    return mdc(b, a % b);
}

int main() {
    int a, b;
    printf("Digite o primeiro número inicial: ");
    scanf("%d", &a);
    printf("Digite o segundo número inicial: ");
    scanf("%d", &b);

    printf("MDC: %d\n", mdc(a, b));
    return 0;
}