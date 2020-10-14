#include "pilha_din_enc.h"

Pilha *Create(void) {
    Pilha *Paux;
    Paux = (Pilha*)malloc(sizeof(Pilha));
    if (Paux!=NULL)
        Paux->topo=NULL;
    return(Paux); 
}

void Push(Pilha *P, elem *x, int *erro) {
    no *pont = (no*)malloc(sizeof(no));
    if (pont==NULL)
        *erro=1;
    else {
        pont->info = *x;
        pont->prox =P->topo;
        P->topo=pont;
        *erro=0;
    }
}

void Pop(Pilha *P, elem *x, int *erro) {
    no *pont;
    if (IsEmpty(P))
        *erro=1;
    else {
        *x=P->topo->info;
        pont=P->topo;
        P->topo=P->topo->prox;
        free(pont);
        *erro=0;
    }
}

int IsEmpty(Pilha *P) {
    if (P->topo==NULL) return(1);
    return(0);
}

void Destroy(Pilha *P) {
    no *pont = P->topo;
    while (pont!=NULL) {
        P->topo=P->topo->prox;
        free(pont);
        pont=P->topo;
    }
    free(P);
}