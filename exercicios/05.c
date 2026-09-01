#include <stdio.h>

int fib(int n, int memo[]){
    if(n==1||n==2) return 1;

    if(memo[n]!=-1) return memo[n];

    memo[n] = fib(n-1, memo) + fib(n-2, memo);
}

void main(){
    int i, memo[100];

    for(i=0;i<100;i++) memo[i]=-1;

    printf("%d\n", fib(10, memo));
}