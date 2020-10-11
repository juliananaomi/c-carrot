#include <stdio.h>
#include <stdlib.h>
#include "fila_estatica.h"

typedef int elem;

void criar_fila(Fila *F) {
    F->inicio = 0;
    F->fim = 1;
}

int inserir(Fila *F, elem *x) {
    F->info[F->fim] = *x;
    F->fim++;
}