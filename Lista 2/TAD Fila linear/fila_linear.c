#include <stdio.h>
#include <stdlib.h>
#include "fila_linear.h"

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
    printf("\n%d\n", F->total);
}

void inserir(Fila *F, elem *x, int *erro) {
    if(Cheia(F)) *erro=1;
    else {
        F->info[F->fim] = *x;
        F->fim++;
        F->total++;
        *erro=0;
    }
}

void retirar(Fila *F, elem *x, int *erro) {
    int i;
    if(Vazia(F)) *erro=1;
    else {
        for (i = 0; i < F->fim; i++) {
            F->info[i] = F->info[i+1];
        }
        F->total--;
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