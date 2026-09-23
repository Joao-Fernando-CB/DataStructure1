#include <stdio.h>

int soma(int n){
    // Caso Base: Se n for maior que 0, retorna n + soma(n-1), o passo recursivo. Caso contrário, retorna 0.
    if(n>0){
        return n + soma(n-1);
    }
    return 0;
}

int main() {
    int num;
    printf("Digite o número inicial: ");
    scanf("%d", &num);

    printf("Soma: %d\n", soma(num));
    return 0;
}