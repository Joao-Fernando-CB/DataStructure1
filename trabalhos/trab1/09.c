#include <stdio.h>
#include <stdlib.h>

int pal(int i, char vet[], int n){
    // Caso Base: Se i for menor que n, continua a verificação. Caso contrário, retorna 1.
    if(i < n){
        // Passo Recursivo: Se os caracteres nos extremos forem diferentes, retorna 0. Caso contrário, continua a verificação.
        if(vet[i] != vet[n - 1 - i]){
            return 0;
        }
        return pal(i + 1, vet, n);
    }
    return 1;
}

int main() {
    int tamanho;
    printf("Digite o tamanho da palavra: ");
    scanf("%d", &tamanho);

    char *palavra = malloc(tamanho * sizeof(char));
    for(int i = 0; i < tamanho; i++){
        printf("Digite o caractere %d: ", i);
        scanf(" %c", &palavra[i]);
    }

    if(pal(0, palavra, tamanho)){
        printf("O vetor eh um palindromo.\n");
    }else{
        printf("O vetor nao eh um palindromo.\n");
    }

    free(palavra);
    return 0;
}