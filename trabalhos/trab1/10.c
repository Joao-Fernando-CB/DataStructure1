#include <stdio.h>
#include <stdlib.h>

void inverter(int i, int vet[], int vet2[], int tamanho){
    // Caso Base: Se o índice atingiu o tamanho do vetor, o processo de inversão terminou.
    if (i >= tamanho) {
        return;
    }
    
    // Passo Recursivo: Copia o elemento do final de 'vet' para o início de 'vet2' e avança para o próximo índice.
    vet2[i] = vet[tamanho - 1 - i];
    inverter(i + 1, vet, vet2, tamanho);
}

int main() {
    int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int *vet = malloc(tamanho * sizeof(int));
    int *vet2 = malloc(tamanho * sizeof(int));

    for(int i = 0; i < tamanho; i++){
        printf("Digite o elemento %d: ", i);
        scanf("%d", &vet[i]);
    }

    inverter(0, vet, vet2, tamanho);

    for(int i = 0; i < tamanho; i++){
        printf("%d ", vet2[i]);
    }
    printf("\n");

    free(vet);
    free(vet2);
    return 0;
}