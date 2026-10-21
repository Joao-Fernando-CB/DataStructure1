#include <stdio.h>

void troca(int *x, int *y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void main(){
    int a = 10, b = 20;
    troca(&a,&b);

    printf("Valor A: %d Valor B: %d", a, b);
}