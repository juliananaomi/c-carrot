typedef char elem;

typedef struct bloco {
    elem info;
    struct bloco *esq, *dir;
} no;

typedef struct {
    no *raiz;
} Arvore;