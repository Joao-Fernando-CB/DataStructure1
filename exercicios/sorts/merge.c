#include <stdio.h>

void merge(int a[], int inicio, int meio, int fim){
    int temp[fim - inicio + 1];
    int i = inicio;
    int j = meio + 1;
    int k = 0;

    while(i <= meio && j <= fim){
        if(a[i] < a[j]){
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }

    while(i <= meio){
        temp[k++] = a[i++];
    }

    while(j <= fim){
        temp[k++] = a[j++];
    }

    for(i = inicio, k = 0; i <= fim; i++, k++){
        a[i] = temp[k];
    }
}

void mergeSort(int a[], int inicio, int fim){
    if(inicio < fim){
        int meio = (inicio + fim) / 2;
        mergeSort(a, inicio, meio);
        mergeSort(a, meio + 1, fim);
        merge(a, inicio, meio, fim);
    }
}

void print(int v[], int n){
    printf("\n=================================== Começo do print ===================================\n");
    for(int i = 0; i<n; i++){
        printf("[%d] -> %d \n", i+1, v[i]);
    }
}

int main(){
    int v[135];
    for(int i = 0; i<135; i++){
        v[i] = 1765*i%432;
    }
    print(v,135);
    mergeSort(v, 0, 134);
    print(v,135);
    return 0;
}