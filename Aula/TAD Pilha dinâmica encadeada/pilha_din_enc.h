typedef char elem;

typedef struct bloco {
    elem info;
    struct bloco *prox;
} no;

typedef struct  {
    no *topo;
} Pilha;

Pilha* Create(void);
void Push(Pilha*, elem*, int*);
void Pop(Pilha*, elem*, int*);
void Destroy(Pilha*);
int Empty(Pilha*);