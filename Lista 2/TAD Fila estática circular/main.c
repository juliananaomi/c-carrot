#include <stdio.h>
#include <stdlib.h>
#include "fila_circular.h"

int main(void) {
    Fila F;
    int erro;
    elem x;
    criar_fila(&F);
    x=10;
    inserir(&F, &x, &erro);
    x=5;
    inserir(&F, &x, &erro);
    x=4;
    inserir(&F, &x, &erro);
    retirar(&F, &x, &erro);
    printf("%d ", x);
    retirar(&F, &x, &erro);
    printf("%d ", x);
    return(0);
}
