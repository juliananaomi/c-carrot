#include <stdio.h>
#include <stdlib.h>
#include "fila_estatica.h"

int main(void) {
    Fila F;
    int erro;
    elem x;
    criar_fila(&F);
    x=10;
    inserir(&F, &x, &erro);
    x=5;
    inserir(&F, &x, &erro);
    Total(&F);
    retirar(&F, &x, &erro);
    retirar(&F, &x, &erro);
    Total(&F);
    return(0);
}
