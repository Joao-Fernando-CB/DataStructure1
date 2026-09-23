#include <stdio.h>

int soma_digitos(int n){
    // Caso Base: Se n for menor que 10, retorna n. Caso contrário, retorna o último dígito somado com a soma dos dígitos do restante do número.
    if (n < 10){
        return n;
    }
    return (n % 10) + soma_digitos(n / 10);
}

int main() {
    int numero;
    printf("Digite o número inicial: ");
    scanf("%d", &numero);

    printf("A soma dos digitos de %d eh: %d\n", numero, soma_digitos(numero));
    return 0;
}