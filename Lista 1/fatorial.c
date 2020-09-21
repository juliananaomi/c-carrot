#include <stdio.h>

int fat(int n) {
    int i, res=1;
    for(i=n; i>1; i--)
        res = res*i;
    return(res);
}

int fat_rec(int n) {
    if (n<=1)
        return(1);
    else return(n*fat_rec(n-1));
}

int main (void) {
    int n;
    printf("Entre com um numero: ");
    scanf("%d" , &n);
    printf("(iterativo) O fatorial do numero %d eh %d\n", n , fat(n));
    printf("(recursivo) O fatorial do numero %d eh %d\n", n , fat_rec(n));
    return(0);
}