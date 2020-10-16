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
    No *p;
    p->info = *x;
    while (p->info != )
    {
        /* code */
    }
    

}

void Finalizar(Lista *L) {
    No *p;
    while (p!=NULL) {
        
    }
    
}
