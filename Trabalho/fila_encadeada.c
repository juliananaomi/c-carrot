#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rede_social.h"

/*
struct no_fila{
    elem_fila info;
    struct no_fila *prox;
};
*/

//===================================
// Criação e Refresh da Fila
//===================================

//Cria uma fila vazia
Fila* Create_Fila(void){
    Fila* F = (Fila*)malloc(sizeof(Fila));
    if (F != NULL){
        F-> inicio = NULL;
        F-> fim = NULL;
        return F;
    }
}

//Reseta a fila
void Empty_Fila(Fila *F){
    NO_fila* p = F-> inicio;

    while(p != NULL){
        F-> inicio = F-> inicio-> prox;
        free(p);
        p = F-> inicio;
    }
    free(F);
}

//===================================
// Funções da Fila
//===================================

//Insere um elemento no fim da Fila
void Push_Fila(Fila* F, elem_fila *var, int *flag){
    NO_fila* p = (NO_fila*)malloc(sizeof(NO_fila));

    if(p == NULL){
        *flag = 1;
    }
    else{
        *flag = 0;
        strcpy(p-> info.item, var-> item);
        p-> prox = NULL;
        if(F-> inicio == NULL)
            F-> inicio = p;
        else
            F-> fim-> prox = p;
        F-> fim = p;
    }
}

//Retira um elemento do inicio da Fila
void Pop_Fila(Fila *F, elem_fila *var, int *flag){
    NO_fila *p;
    if(!IsEmpty_Fila(F)){
        *flag = 0;
        strcpy(var-> item, F-> inicio-> info.item);
        p = F->inicio;
        F-> inicio = F-> inicio->prox;
        free(p);
        if(F-> inicio == NULL)
            F-> fim = NULL;
    }
    else
        *flag = 1;
}

//Verifica se a fila está vazia
int IsEmpty_Fila(Fila *F){
    if(F-> inicio == NULL)
        return 1;
    return 0;
}

int Search_Fila(Fila *F, elem_fila *var){
    NO_fila* p = F->inicio;
    while(p != NULL){
        if(strcmp(p->info.item,var->item) == 0)
            return 1;
        else
            p = p->prox;
    }
    return 0;
}