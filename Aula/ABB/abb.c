#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

ABB* criar(void) {
    ABB *A = (ABB *)malloc(sizeof(ABB));
    A->raiz = NULL;
    return(A);
}

int buscar(no *p, elem *x) {
    if(p==NULL) return(0);
    else if (p->info==*x)
        return(1);
    else if (*x<p->info)
        return(buscar(p->esq, x));
    else return (buscar(p->dir, x));
}

int inserir(no **p, elem *x) {
    if (p==NULL) {
        *p=(no*) malloc(sizeof(no));
        (*p)->esq=NULL;
        (*p)->dir=NULL;
        (*p)->info=*x;
        return(1);
    }
    else if ((*p)->info==*x)
        return(0);
    else if (*x<(*p)->info)
        return(inserir((*p)->esq,x));
    else return(inserir((*p)->dir, x));
}

int remover(no **p, elem *x) {
    no *aux;
    if (*p==NULL)
        return(0);
    else if(*x < (*p)->info)
        return(remover(&(*p)->esq, x));
    else if(*x > (*p)->info)
        return(remover(&(*p)->dir, x));
    else if (*x == (*p)->info) {

        //caso 1: o nó nao tem filhos
        if (((*p)->esq==NULL) && ((*p)->dir==NULL)) {
            free(*p);
            *p=NULL;
            return(1);
        }

        //caso 2a: só há o filho direito
        else if ((*p)->esq==NULL) {
            aux=*p;
            *p=(*p)->dir;
            free(aux);
            return(1);
        }

        //caso 2b: só há o filho esquerdo
        else if ((*p)->dir==NULL) {
            aux=*p;
            *p=(*p)->esq;
            free(aux);
            return(1);
        }

        //caso : há dois filhos
        else {
            (*p)->info=busca_maior(&(*p)->esq);
            return(remover(&(*p)->esq, &(*p)->info));
        }
    }
}

elem busca_maior(no **p) {
            no *aux;
            aux=*p;
            while (aux->dir!=NULL)
                aux=aux->dir;
            return(aux->info);
        }