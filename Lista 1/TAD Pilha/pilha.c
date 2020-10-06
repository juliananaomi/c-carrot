#include "pilha.h"

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

void Push(Pilha *P, int X, int *erro) {
    if (IsFull(P))
        *erro=1;
    else {
        P->topo++;
        P->itens[P->topo]=X;
        *erro=0;
    }
}

void Pop(Pilha *P, int *X, int *erro){
    if (IsEmpty(P))
        *erro=1;
    else {
        *X = P->itens[P->topo];
        P->topo--;
        *erro=0;
    }
}

