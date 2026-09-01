#include <stdio.h>

int f(int n){
    if(n==0) return 1;
    return 2*f(n-1);
}

void main(){
    printf("f(4) = %d\n", f(4));
}