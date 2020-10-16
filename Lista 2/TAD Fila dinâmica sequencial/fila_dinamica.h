typedef int elem;

typedef struct  {
    elem *info;
    int inicio, fim, total; 
} Fila;

Fila* Criar(void);
void Inserir(Fila*, elem*);
void Retirar(Fila*, elem*, int*);
void Print(Fila*);