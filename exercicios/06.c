#include <stdio.h>

int busca(int v[], int x, int n){
    int i;
    
    for(i = 0; i < n; i++){
        if(v[i] == x){
            return i;
        }
    }

    return -1;
}

void main(){
    int i, v[100], local;

    for(i=0;i<100;i++) v[i]=i*12%31;

    local = busca(v, 30, i);

    if(local != -1) printf("O valor se encontra na posicao %d\n", local);
    else printf("O valor nao foi encontrado\n");
}