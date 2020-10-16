typedef int elem;

typedef struct no {
    elem info;
    struct no *prox;
} No;

typedef struct {
    No *inicio, *fim;
} Lista;

Lista* Criar(void);
void Inserir(Lista*, elem*, int*);