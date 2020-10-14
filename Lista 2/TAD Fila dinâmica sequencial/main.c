#include <stdio.h>
#include <stdlib.h>
#include "fila_dinamica.h"

int main(void) {
    Fila *F;
    elem x;
    int erro;
    F=Criar();
    x = 2;
    Inserir(F, &x);
    x = 9;
    Inserir(F, &x);
    x = 34;
    Inserir(F, &x);
    Retirar(F, &x, &erro);
    Print(F);
    return(0);
}