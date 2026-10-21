#include <stdio.h>

void troca(int *a, int *b, int t){
    for(int i = 0; i<t;i++){
        b[i] = a[t-i-1];
    }
}

void main(){
    int a[] = {123,353,14,97,2,76,23}, b[7];
    troca(a, b, 7);

    for(int i = 0; i<7; i++){
        printf("%d \n", b[i]);
    }
}