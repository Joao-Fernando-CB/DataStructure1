#include <stdio.h>

void bubbleSort(int vetor[], int tamanho) {
    int i, j, aux;
    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                // Troca os elementos de posição
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

int busca_binaria_rec(int v[], int x, int ini, int fim){
    if(ini > fim) return -1;
    
    int meio = (ini+fim) / 2;

    if(v[meio] == x){
        return x;
    }else if(x<v[meio]){
        busca_binaria_rec(v, x, ini, meio-1);
    }else{
        busca_binaria_rec(v, x, meio+1, fim);
    }
}

void main(){
    int i, v[100], local;

    for(i=0;i<100;i++) v[i]=i*12%31;

    bubbleSort(v, 100);

    local = busca_binaria_rec(v, 30, 0, 100);

    if(local != -1) printf("O valor se encontra na posicao %d\n", local);
    else printf("O valor nao foi encontrado\n");
}