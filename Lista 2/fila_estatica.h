#include <stdio.h>
#include <stdlib.h>
#define TamFila 10

typedef int elem;

typedef struct {
    elem info[TamFila];
    int inicio, fim;
} Fila;

void criar_fila(Fila*);
