typedef char elem;

typedef struct bloco {
    elem info;
    struct bloco *esq, *dir;
} no;

typedef struct {
    no *raiz;
} AB;

AB* criar(void);
int vazia(AB*);
no* criar_no(elem*, int*);
no* busca(no*, elem*);
void inserir_esq(AB*, elem*, elem*, int*);
void inserir_dir(AB*, elem*, elem*, int*);
void preordem(no*);