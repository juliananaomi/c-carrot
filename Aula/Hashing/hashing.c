#include "hashing.h"

//alternativa p macro
void inicializa(int T[]) {
    for (int i=0; i<B; i++)
        T[i]=-1; //vazia = -1
}

int inserir(int T[], int k) {
    int i,j;
    for (i=0; i<B; i++) {
        j=h(k,i);
        if (T[j]==-1 || (T[j]==-2)) {
            T[j]=k;
            return(j);
        }
    }
    return(-1);
}

int remover(int T[], int k) {
    int i, j;
    for (i=0; i<B, i++) {
        j=h(k,i);
        if (T[j]==k) {
            T[j]=-2; //indica que já foi ocupada uma vez
            return(j);
        }
        else if (T[j]==-1)
            return(-1);
    }
}