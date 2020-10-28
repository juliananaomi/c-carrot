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