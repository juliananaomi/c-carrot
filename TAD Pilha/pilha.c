#include "pilha.h"

typedef int elem;

void Create(Pilha *P) {
    P->topo=-1;
    return;
}

int IsFull(Pilha *P) {
    if (P->topo==TamPilha-1)
        return(1); // Cheia
    else return(0); //Vazia
}

int IsEmpty(Pilha *P) {
    if (P->topo==-1)
        return(1); // Vazia
    else return(0); // Não esta vazia
}

void Push(Pilha *P, elem *X, int *erro) {
    if (IsFull(P))
        *erro=1;
    else {
        P->topo++;
        P->itens[P->topo]=*X;
        *erro=0;
    }
}

void Pop(Pilha *P, elem *X, int *erro){
    if (IsEmpty(P))
        *erro=1;
    else {
        *X = P->itens[P->topo];
        P->topo--;
        *erro=0;
    }
}

elem Top(Pilha *P, int *erro) {
    if (!IsEmpty(P)) {
            *erro=0;
            return(P->itens[P->topo]);
    }
    else {
        *erro=1;
        return(-1);
    }
}
