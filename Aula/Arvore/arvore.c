#include "arvore.h"

Arvore* criar(void) {
    Arvore *Aux=(Arvore*) malloc(sizeof(Arvore));
    if (Aux!=NULL)
        Aux->raiz=NULL;
    return(Aux);
}

int IsEmpty(Arvore *A) {
    if (A->raiz==NULL) return(1);
    else return(0);
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

no* busca_pai(no *p, elem *x) { // Procurar o pai de x
    no *aux;

    if (p==NULL)
        return(NULL);
    else if ((p->esq!=NULL) && (p->esq->info==*x))
        return(p);
    else if ((p->dir!=NULL) && (p->dir->info==*x))
        return(p);
    else {
        aux=busca_pai(p->esq,x);
        if (aux==NULL)
            aux=busca_pai(p->dir, x);
        return(aux);
    }
}

void inserir_esq(Arvore *A,elem *x, elem *pai, int *erro) {
    no *aux, *p;
    if (*pai!=-1) {
        aux=busca(A->raiz, pai);
        if ((aux!=NULL) && (aux->esq==NULL)) {
            p=(no*)malloc(sizeof(no));
            p->info=*x;
            p->esq=NULL;
            p->dir=NULL;
            aux->esq=p;
            *erro=0;
        }
        else *erro=1;
        }
        else if (A->raiz==NULL) {
            p=(no*)malloc(sizeof(no));
            p->info=*x;
            p->esq=NULL;
            p->dir=NULL;
            A->raiz=p;
            *erro=0;
        }
}

int altura (no *p) {
    int alt_esq, alt_dir;

    if (p==NULL)
        return(0);
    else {
        alt_esq=1+altura(p->esq);
        alt_dir=1+altura(p->dir);
        if (alt_esq>=alt_dir)
            return(alt_esq);
        else return(alt_dir);
    }
}

