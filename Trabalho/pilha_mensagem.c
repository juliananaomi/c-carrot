#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "rede_social.h"


/*
struct no_pilha_mensagem{
   elem_mensagens info;
   struct no_pilha_mensagem *next_msg; 
};
*/

//===================================
// Criação e Refresh da pilha
//===================================

// Criar pilha para elem_mensagens
Pilha_mensagens* Create_PM(void){
    Pilha_mensagens* PM = (Pilha_mensagens*)malloc(sizeof(Pilha_mensagens));
    if (PM != NULL){
        PM->topo = NULL;
        return PM;
    }
}

// Esvaziar dados da pilha
void Clear_PM(Pilha_mensagens *PM){
    NO_mensagem* P = PM->topo;
    while(P != NULL){
        PM-> topo = PM->topo->next_msg;
        free(P);
        P = PM->topo;
    }
}

//===================================
// Funções da pilha
//===================================
//Enviar mensagem pra pilha por meio de um elemento com remetente e texto
void Push_PM(Pilha_mensagens *PM, elem_mensagens *txt, int *flag){
    NO_mensagem* P = (NO_mensagem*)malloc(sizeof(NO_mensagem));
    if(P == NULL){
        *flag = 1;
    }
    else{
        *flag = 0;
        strcpy(P->info.remetente, txt->remetente);
        strcpy(P->info.texto_mensagem, txt->texto_mensagem);
        P->next_msg = PM->topo;
        PM-> topo = P;
    }
}

//Enviar mensagem pra pilha por meio de um elemento com remetente e texto
void Pop_PM(Pilha_mensagens *PM, elem_mensagens *txt, int *flag){
    NO_mensagem* P;
    if(PM-> topo == NULL){
        *flag = 1;
    }
    else{
        *flag = 0;
        P = PM->topo;
        PM->topo = PM->topo->next_msg;
        strcpy(txt->remetente, P->info.remetente);
        strcpy(txt->texto_mensagem, P->info.texto_mensagem);
        free(P);
    }
}

// Verifica se a pilha está vazia
int IsEmpty_PM(Pilha_mensagens *PM){
    if(PM->topo == NULL)
        return (1);
    return 0;
}