#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

Fila* Criar(void) {
    Fila *F;
    F = (Fila *)malloc(sizeof(Fila)); //Alocando memoria para a fila
    F->inicio = NULL;
    F->fim = NULL;
    return(F);
}
int Vazia(Fila *F) {
    if (F->inicio == NULL && F->fim ==NULL) return(1);
    else return(0);
}

//Entra no inicio da fila
void entrar_na_esquerda(Fila *F, elem *x, int *erro) {
    No *p = (No *)malloc(sizeof(No));
    if(p==NULL) *erro=1; //Não conseguiu alocar
    else {
        p->info = *x; 
        //Primeiro elemento sendo inserido
        if (F->inicio == NULL) {
            F->inicio = p;
            F->fim =p;
            p->prox = NULL; //é o primeiro e ultimo elemento
        }
        //Não é o primeiro elemento sendo inserido
        else {
            p->prox = F->inicio; //o que entra ponta para o primeiro da fila
            F->inicio = p; //inicio passa a apontar para o q entrou
        } 
    }
}

//Sai do inicio da fila
void sair_da_esquerda(Fila *F, elem *x, int *erro) {
    No *p;
    if (Vazia(F)) *erro =1;
    else {
        *x = F->inicio->info; //O elemento do inicio ira sair
        p = F->inicio;
        F->inicio= F->inicio->prox;
        free(p);
        *erro=0;
    }
}
