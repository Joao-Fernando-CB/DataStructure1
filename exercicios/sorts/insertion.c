#include <stdio.h>

int insertionSort(int a[], int n){
    for(int i = 0; i< n; i++){
        int x = a[i];
        int j = i-1;
        while(j>=0 && a[j]>x){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = x;
    }
}

void print(int v[], int n){
    printf("\n=================================== Começo do print ===================================\n");
    for(int i = 0; i<n; i++){
        printf("[%d] -> %d \n", i+1, v[i]);
    }
}

void main(){
    int v[135];
    for(int i = 1; i<135; i++){
        v[i] = 1765*i%432;
    }
    print(v,135);
    insertionSort(v, 135);
    print(v,135);
}