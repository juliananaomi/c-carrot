#include <stdio.h>

int fib(int n) {
    int resultado;
    if (n<2) return(1);
    else return(fib(n-1) + fib(n-2));
} 

int main(void) {
    int n;
    printf("Entre com o indice de Fibonacci: ");
    scanf("%d",&n);
    printf("O numero de Fibonacci do %d° termo eh: %d", n , fib(n));
    return(0);
}