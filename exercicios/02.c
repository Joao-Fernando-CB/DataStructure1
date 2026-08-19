#include <stdio.h>

int troca(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

void main(){
    int a = 10, b = 20;
    troca(&a, &b);
    printf("%d %d", a, b);
}