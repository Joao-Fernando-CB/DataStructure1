#include <stdio.h>

int busca(int *a, int t, int busca){
    for(int i = 0; i<t;i++){
        if(a[t] == busca) return i;
    }
}

void main(){
    int a[] = {123,353,14,97,2,76,23};
    int pos = troca(a, 7, 2);
    printf("A posicao da busca e %d", pos);
}