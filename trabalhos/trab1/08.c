#include <stdio.h>
#include <stdlib.h>

int soma_elementos_vetor(int vet[], int n) {
    // Caso Base: Se n for igual a 0, retorna 0.
    if (n == 0) {
        return 0;
    }
    // Passo Recursivo: Retorna o elemento atual somado com a soma dos elementos restantes.
    return vet[n - 1] + soma_elementos_vetor(vet, n - 1);
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

    int n = soma_elementos_vetor(vet, tamanho);
    printf("%d\n", n);

    free(vet);
    return 0;
}