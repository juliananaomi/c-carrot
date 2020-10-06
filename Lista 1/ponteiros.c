#include <stdio.h>

void ler_valor(int*x) {
    *x=4;
    printf("Valor de x dentro da funcao: %d\n", *x);
}

int main(void)  {
    int x=2 ;
    printf("Valor inicial de x: %d\n", x);
    ler_valor(&x);
    printf("Novo valor de x: %d\n", x);
    x = x*x;
    printf("A área do quadrado é %d\n",x);
    return(0);
}