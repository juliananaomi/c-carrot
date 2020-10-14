#include <stdio.h>
#include <stdlib.h>
#include "fila_circular.h"

typedef int elem;

void criar_fila(Fila *F) {
    F->inicio = 0;
    F->fim = 0;
}

int Vazia(Fila *F) {
    if((F->inicio == 0 && F->fim == 0) || (F->inicio==F->fim)) return(1);
    else return(0);
}

int Cheia(Fila *F) { //perde uma casa pois F->fim ainda n foi preenchido
    if((F->fim==F->inicio-1) || (F->fim==TamFila-1 && F->inicio==0)) return(1);
    else return(0);
}

void inserir(Fila *F, elem *x, int *erro) {
    if(Cheia(F)) *erro=1;
    else {
        F->info[F->fim] = *x;
        if(F->fim == TamFila-1) F->fim=0;
        else F->fim++;
        *erro=0;
    }
}

void retirar(Fila *F, elem *x, int *erro) {
    if (Vazia(F)) *erro=1;
    else {
        *x = F->info[F->inicio];
        if (F->inicio==TamFila-1) F->inicio=0;
        else F->inicio++;
        *erro=0;
    }
}