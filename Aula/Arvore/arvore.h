typedef char elem;

typedef struct bloco {
    elem info;
    struct bloco *esq, *dir;
} no;

typedef struct {
    no *raiz;
} Arvore;

Arvore* criar(void);
no* busca(no*, elem*);