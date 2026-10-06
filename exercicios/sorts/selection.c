#include <stdio.h>

void selection(int a[], int n){
    for(int i = 0; i<n-1;i++){
        int m = i;
        for(int j = i+1; j<n; j++){
            if(a[j] < a[m]){
                m = j;
            }
        }
        int temp = a[i];
        a[i] = a[m];
        a[m] = temp;
    }
}

int main(){
    int arr[] = {64, 25, 12, 22, 11};
    int n = 5;
    
    selection(arr, n);
    
    printf("Array ordenado: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}