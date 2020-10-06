#define TamPilha 10

typedef struct {
    int topo;
    int itens[TamPilha];
} Pilha;

void Create(Pilha*);
void Push(Pilha*, int, int*);
void Pop(Pilha *, int*, int*);
int IsFull(Pilha*);
int IsEmpty(Pilha*);