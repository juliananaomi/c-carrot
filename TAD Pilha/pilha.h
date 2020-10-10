#define TamPilha 10

typedef int elem;

typedef struct {
    int topo;
    elem itens[TamPilha];
} Pilha;

Pilha Create(Pilha*);
void Push(Pilha*, elem*, int*);
void Pop(Pilha *, elem*, int*);
int IsFull(Pilha*);
int IsEmpty(Pilha*);
elem Top(Pilha*, int*);