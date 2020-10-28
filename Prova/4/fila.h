typedef int elem;

//Estrutura do bloco
typedef struct no {
    elem info;
    struct no *prox;
} No;

//Fila com ponteiros de início e fim
typedef struct {
    No *inicio, *fim;
} Fila; //Estrutura da fila