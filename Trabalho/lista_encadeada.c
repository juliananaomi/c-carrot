#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rede_social.h"


/*
struct no_lista{
    elem_lista info;
    struct no_lista *prox;
};
*/



//===================================
// Criação e Refresh da lista
//===================================

//Cria uma lista vazia
Lista* Create_Lista(void){
    Lista* L = (Lista*)malloc(sizeof(Lista));
    L-> inicio = NULL;
    L-> fim = NULL;
    return L;
}

//Esvazia a lista
void Empty_Lista(Lista* L){
    NO_lista* p = L-> inicio;
    while (p != NULL){
        L-> inicio = L-> inicio-> prox;
        free(p);
        p = L-> inicio;
    }
    free(L); 
}

//===================================
// Funções da lista
//===================================

//Insere um elemento no fim da lista
void Push_Lista(Lista* L, elem_lista *var, int *flag){
    NO_lista* p = (NO_lista*)malloc(sizeof(NO_lista));
    
    if(p == NULL){
        *flag = 1;
    }
    else{
        *flag = 0;
        strcpy(p-> info.item, var-> item);
        p-> prox = NULL;
        if(L-> inicio == NULL)
            L-> inicio = p;
        else
            L-> fim-> prox = p;
        L-> fim = p;
    }
}

//Retira um elemento da lista
void Pop_lista(Lista* L, elem_lista *var, int *flag){
    NO_lista *p1, *p2;
    int aux = 0;

    p2 = L-> inicio;
    while(p2 != NULL && !aux){
        if(strcmp(p2-> info.item, var->item) != 0){
            p1 = p2;
            p2 = p2-> prox;
        }
        else{
            if(p2 == L-> inicio){
                L-> inicio = L-> inicio-> prox;
                if(L-> inicio == NULL)
                    L-> fim = NULL;
            }
            else if(p2 == L-> fim){
                L-> fim = p1;
                L-> fim -> prox = NULL;
            }
            else{
                p1-> prox = p2-> prox;
            }
            free(p2);
            aux = 1;
        }
    }
    *flag = !aux;
}

//Retorna o número de elementos na lista
int Len_Lista(Lista *L){
    NO_lista *p = L->inicio;
    int counter = 0;
    while(p != NULL){
        p = p-> prox;
        counter++;
    }
    return counter;
}

//Imprime os elementos da lista
void Display_Lista(Lista *L){
    NO_lista* p = L-> inicio;
    if(p == NULL)
        printf("Nao ha elementos.\n");
    while(p != NULL){
        printf("%s\n",p-> info.item);
        p = p-> prox;
    }
    printf("\n");
}

//Procura um elemento na lista
int Search_Lista(Lista *L, elem_lista *var){
    NO_lista* p = L->inicio;
    while(p != NULL){
        if(strcmp(p-> info.item, var->item) == 0)
            return 1;
        else
            p = p-> prox;
    }
    return 0;
}
