#include <stdio.h>
#include <stdlib.h>
#define TamFila 4

typedef int elem;

typedef struct {
    elem info[TamFila];
    int inicio, fim;
} Fila;

void criar_fila(Fila*);
int Cheia(Fila*);
int Vazia(Fila*);
void Total(Fila*);
void inserir(Fila*, elem*, int*);
void retirar(Fila*, elem*, int*);