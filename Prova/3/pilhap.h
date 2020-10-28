//Supondo uma turma com 30 alunos, vamos definir o tamanho da pilha

#define TamPilha 30

//Fazendo um struct para os dados do Aluno
typedef struct {
    int numero_USP[8], nota[3];
    char nome[30];
} Dados;

typedef struct {
    int topo;
    Dados aluno[TamPilha]; 
} Pilha;

void Criar(Pilha*);
int IsFull(Pilha*);
int IsEmpty(Pilha*);
void ler_dados(Pilha*, Dados*);
void Push(Pilha*, Dados*, int*);
void Pop(Pilha*, Dados*, int*);
