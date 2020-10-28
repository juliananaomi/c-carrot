#include "lista_encadeada.h"
#include <stdio.h>
#include <stdlib.h>

Lista* Criar(void) {
    Lista *L;
    L = (Lista *)malloc(sizeof(Lista));
    L->inicio = NULL;
    L->fim = NULL;
    return(L);
}

int Vazia(Lista *L) {
    if (L->inicio == NULL && L->fim ==NULL) return(1);
    else return(0);
}

void Inserir(Lista *L, elem *x, int *erro) {
    No *p = (No *)malloc(sizeof(No));
    if(p==NULL) *erro=1;
    else {
        p->info = *x;
        p->prox = NULL;
        if (L->inicio == NULL) L->inicio = p;
        else L->fim=p;
        *erro=0;
    }
}

void Remover(Lista *L, elem *x, int *erro) {
    No *p, *anterior;
    int teste_achou=0;

    p = L->inicio;
    anterior = NULL;

    while ((p!=NULL) && (!teste_achou)) {
        if (p->info!=*x) { //enquanto não encontra o elem
            anterior = p;
            p = p->prox;
        }
        else { // achou o elemento

            if (p = L->inicio) { // está no inicio
                L->inicio = L->inicio->prox;
                if (L->inicio==NULL) L->fim =NULL;
                
            }

            else if (p == L->fim) { // esta no fim
                anterior->prox = NULL;
                L->fim = anterior;
            }

            else anterior->prox = p->prox; //meio da lista

            free(p);
            teste_achou=1;
        }
    }
}

void Finalizar(Lista *L) {
    No *p;
    while (p!=NULL) {
        p = L->inicio;
        L->inicio = L->inicio->prox;
        free(p);
        p = L->inicio;
    }
    L->fim=NULL;
    free(L);
    L=NULL;
}
