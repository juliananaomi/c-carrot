#include "lista_encadeada.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    Lista *L;
    elem x;
    int erro;
    L = Criar();
    x = 10;
    Inserir(L, &x, &erro);
    Remover(L, &x, &erro);
    return(0);
}