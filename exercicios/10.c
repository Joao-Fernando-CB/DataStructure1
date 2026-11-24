#include <stdio.h>
#include <stdlib.h>

void adicionar(int *matriz, int cols, int i, int j, int valor){
    matriz[i*cols + j] = valor;
}

void main(){
    int linhas = 3, colunas = 4;

    int *matriz = malloc(linhas*colunas*sizeof(int));
    for(int i = 0; i<linhas; i++){
        for(int j = 0; j<colunas; j++){
            adicionar(matriz, colunas, i, j, 10*(i+1)+j);
        }
    }

    for(int i = 0; i<linhas; i++){
        for(int j = 0; j<colunas; j++){
            printf("%d  ", matriz[i*colunas + j]);
        }
        printf("\n");
    }

    free(matriz);

}