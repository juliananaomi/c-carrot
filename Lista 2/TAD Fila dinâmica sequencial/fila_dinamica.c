#include <stdio.h>
#include <stdlib.h>
#include "fila_dinamica.h"

Fila* Criar(void) {
    Fila *F = (Fila*)malloc(sizeof(Fila));
    F->inicio = 0;
    F->fim = 0;
    F->total = 0;
    return(F);
}

int Vazia(Fila *F) {
    if (F->total==0) return(1);
    return(0);
}

void Inserir(Fila *F, elem *x) {
    F->total++;
    F->info = (elem *)realloc(F->info, (F->total)*sizeof(elem));
    F->info[F->fim]= *x;
    F->fim++;
}

void Retirar(Fila *F, elem *x, int *erro) {
    int i;
    if (Vazia(F)) *erro = 1;
    else {
        *x = F->info[F->inicio];
        F->total--;
        for (i = 0; i < F->fim; i++) F->info[i] = F->info[i+1];
        F->info = (elem *)realloc(F->info, (F->total)*sizeof(elem));
        F->fim--;
        *erro=0;
    }
}

void Print(Fila *F) {
    int i;
    for (i = 0; i < F->fim; i++) {
        printf("%d ", F->info[i]);
    }
}