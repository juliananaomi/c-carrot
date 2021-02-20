#include "ab.h"
#include <stdio.h>
#include <stdlib.h>

AB* criar(void) {
    AB *Aux=(AB*) malloc(sizeof(AB));
    if (Aux!=NULL)
        Aux->raiz=NULL;
    return(Aux);
}

int vazia(AB *A) {
    if (A->raiz==NULL) return(1);
    else return(0);
}

no* criar_no(elem *x, int *erro) {
  no *p = (no*)malloc(sizeof(no));

  if (p==NULL) {
    *erro=1;
  }

  else {
    p->info=*x;
    p->esq=NULL;
    p->dir=NULL;
    return(p);
  }
}

no* busca(no *p, elem *x) {
    no *aux;
    if (p==NULL) 
        return(NULL);
    else if (p->info==*x)
        return(p);
    else {
        aux = busca(p->esq, x);
        if (aux==NULL)
            aux = busca(p->dir, x);
            return(aux);
    }
} 

void inserir_esq(AB *A, elem *pai, elem *x, int *erro) {
  no *aux;
  int *errono;

  if (vazia(A)) {
    A->raiz = criar_no(x, errono);
    *erro = 0;
  }

  else {
    aux = busca(A->raiz, pai);
    if ((aux!=NULL) && (aux->esq == NULL)) {
      aux->esq = criar_no(x, errono);
      *erro = 0;
    }
    else *erro = 1;
  }
}

void inserir_dir(AB *A, elem *pai, elem *x, int *erro) {
  no *aux;
  int *errono;

  if (vazia(A)) {
    A->raiz = criar_no(x, errono);
    *erro = 0;
  }

  else {
    aux = busca(A->raiz, pai);
    if ((aux!=NULL) && (aux->dir == NULL)) {
      aux->dir = criar_no(x, errono);
      *erro = 0;
    }
    else *erro = 1;
  }
}

//Imprimir árvore

void preordem(no* raiz) {
  if (raiz==NULL) return;
  printf(" [%d] ", raiz->info);
  preordem(raiz->esq);
  preordem(raiz->dir);
}