#include <stdio.h>
#include <stdlib.h>

int contar(int i, int vet[], int n, int tamanho){
    // Caso Base: Se o índice atingiu o tamanho do vetor, chegamos ao fim da busca e retornamos 0.
    if (i == tamanho) {
        return 0;
    }
    
    // Passo Recursivo: Se o elemento atual for igual a 'n', soma 1 ao resultado da busca nos elementos restantes.
    if (vet[i] == n) {
        return 1 + contar(i + 1, vet, n, tamanho);
    }
    
    // Caso contrário, apenas continua a busca no restante do vetor.
    return contar(i + 1, vet, n, tamanho);
}

int main() {
    int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int *vet = malloc(tamanho * sizeof(int));
    for(int i = 0; i < tamanho; i++){
        printf("Digite o elemento %d: ", i);
        scanf("%d", &vet[i]);
    }

    int n;
    printf("Digite o numero a ser buscado: ");
    scanf("%d", &n);

    printf("Contagem de digitos: %d\n", contar(0, vet, n, tamanho));

    free(vet);
    return 0;
}