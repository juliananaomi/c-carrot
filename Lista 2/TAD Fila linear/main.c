#include <stdio.h>
#include <stdlib.h>
#include "fila_linear.h"

int main(void) {
    Fila F;
    int erro;
    elem x;
    criar_fila(&F);
    x=10;
    inserir(&F, &x, &erro);
    x=5;
    inserir(&F, &x, &erro);
    Print(&F);
    Total(&F);
    retirar(&F, &x, &erro);
    Print(&F);
    Total(&F);
    return(0);
}
