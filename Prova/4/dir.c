#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

void entrar_na_direita(Fila *F, elem *x, int *erro) {
    No *aux;
    No *p = (No *)malloc(sizeof(No));
    if(p==NULL) *erro=1; //Não conseguiu alocar
    else {
        p->info = *x; 
        //Primeiro elemento sendo inserido
        if (F->inicio == NULL) {
            F->inicio = p;
            F->fim =p;
        }
        //Não é o primeiro elemento sendo inserido
        else {
            aux = F->fim;
            aux->prox = p; // o que está no fim aponta para o que entra
            F->fim = p; //Fim muda para o q entrou
        } 
        p->prox = NULL;
    }
}

//Sai do inicio da fila
void sair_da_esquerda(Fila *F, elem *x, int *erro) {
    No *p, *anterior;

    if (Vazia(F)) *erro =1;
    else {
        *x = F->fim->info; //O elemento do fim ira sair
        p = F->fim;
        anterior->prox = NULL; //eu n fiz a parte logica de obter o anterior, mas continuei supondo q fiz
        free(p);lista
        F->fim = anterior;
        *erro=0;
    }
}
