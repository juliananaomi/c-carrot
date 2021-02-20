#include <stdio.h>
#include <stdlib.h>

typedef int elem;

typedef struct bloco {
    elem info;
    struct bloco *esq, *dir;
} no;

typedef struct {
    no *raiz;
} ABB;

ABB* criar(void);
int buscar(no*, elem*);
int inserir(no**, elem*);
int remover(no**, elem*);
elem busca_maior(no**);