#include <stdio.h>
#include <stdlib.h>
#define TamFila 10

typedef int elem;

typedef struct {
    elem info[TamFila];
    int inicio, fim, total;
} Fila;

void criar_fila(Fila*);
int Cheia(Fila*);
int Vazia(Fila*);
void Total(Fila*);
void inserir(Fila*, elem*, int*);
void retirar(Fila*, elem*, int*);
void Print(Fila*);