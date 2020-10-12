#include <stdio.h>
#include <stdlib.h>
#include "fila_estatica.h"

typedef int elem;

void criar_fila(Fila *F) {
    F->inicio = 0;
    F->fim = 0;
    F->total = 0;
}

int Cheia(Fila *F) {
    if (F->total==TamFila) return(1); //Cheia
    else return(0); // Há espaço
}

int Vazia(Fila *F) {
    if(F->total==0) return(1); //Vazia
    else return(0); //Não está cheia 
}

void Total(Fila *F) {
    printf("%d", F->total);
}

int inserir(Fila *F, elem *x, int *erro) {
    if(Cheia(F)) {
        *erro=1;
    }
    else {
        F->info[F->fim] = *x;
        if(F->fim == TamFila-1) F->fim=0;
        else F->fim++;
        F->total++;
        *erro=0;
    }
}

void retirar(Fila *F, elem *x, int *erro) {
    if(Vazia(F)) {
        *erro=1;
    }
    else {
        *x = F->info[F->inicio];
        if (F->inicio==TamFila-1) F->inicio=0;
        else F->inicio++;
        F->total--;
        *erro=0;
    }
}