#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rede_social.h"

//Nó para os usuarios, elem_user contém todos os atributos necessários explicitados no rede_social.h
struct no_user{
    elem_user info;
    struct no_user *prox;
};

//Função para criar uma lista para suportar os usuarios
Usuarios* Create_Usuario(void){
    Usuarios* U = (Usuarios*)malloc(sizeof(Usuarios));
    if(U != NULL){
        U-> inicio = NULL;
        U-> fim = NULL;
        return U;
    }

}
//Função para adicionar novos usuarios na lista, também chama uma função para conferir
//se já existe algum apelido igual já que ele vai ser usado para mandar mensagens e outras funções
//então não se pode ter repetições
void Push_Usuario (Usuarios *U, char *nome, char *apelido, int *flag){
    NO_user* p = (NO_user*)malloc(sizeof(NO_user));
    if(p == NULL)
        *flag = 1;
    else if(Verify_Usuario(U, apelido)){
        *flag = 2; // Flag de error para o caso de já existir um mesmo apelido na lista U
    }
    else{
        *flag = 0;
        strcpy(p->info.nome, nome);
        strcpy(p->info.apelido, apelido);
        p->info.messages = Create_PM(); // Chama função de criação de uma pilha de mensagens do usuario X
        p->info.requests = Create_Fila(); // Chama função de criação de uma fila de pedidos de amizades do usuario X
        p->info.friends = Create_Lista(); // Chama função de criação de uma lista de amizades do usuario X
        p->prox = NULL;
        if(U-> inicio == NULL)
            U-> inicio = p;
        else
            U->fim->prox = p;
        U->fim = p;
    }
}

int Len_Usuarios(Usuarios *U){
    NO_user *p = U->inicio;
    int counter = 0;
    while(p != NULL){
        p = p-> prox;
        counter++;
    }
    return counter;
}

//Função para imprimir todos os usuarios
void Display_Usuario(Usuarios *U){
    NO_user* p = U-> inicio;
    int error;
    elem_user friend;
    while(p != NULL){
        printf("Usuario: %s\n", p->info.nome); //Imprime o nome do usuario X
        printf("Apelido: %s\n",p->info.apelido); //Imprime o apelido do usuario X
        printf("Lista de amigos: \n");
        Display_Lista(p->info.friends); //Chama função para imprimir uma lista qualquer, neste caso a dos amigos do usuario X
        p = p-> prox;
    }
}
//Função simples de comparação de duas strings, utilizada para comparar os apelidos no decorrer da lista
int Verify_Usuario(Usuarios *U, char *apelido){
    NO_user* p = U-> inicio;
    while(p != NULL){
        if(strcmp(p->info.apelido, apelido) == 0)
            return (1);
        p = p->prox;
    }
    return (0);
}

//Função para procurar um nome na lista de amigos
int Search_Amigo(Usuarios *U, elem_lista *E_apelido, char *D_apelido){
    NO_user* p = U->inicio;
    while(p != NULL){
        if(strcmp(p->info.apelido, D_apelido) == 0) //Procura o usuario que enviou o pedido
            return Search_Lista(p->info.friends, E_apelido);//Chama a função para procurar se ela já está na lista de amigos
        p = p->prox;
    }
}

//Função para enviar o pedido de amizade para a fila do alvo. 
//Possui comparação para saber:
//se o usuario enviou pedido pra ele mesmo
//se ele ja está na lista de amizados do alvo

void Send_Pedido(Usuarios *U, elem_fila *E_apelido, char* D_apelido, int *flag){
    NO_user *p = U->inicio;
    int errorRequest;
    elem_lista E_apelido2;
    //Verificação se o usuario enviou pedido pra ele mesmo
    if(strcmp(E_apelido->item, D_apelido) == 0){
        *flag = 2;
        return;
    }
    strcpy(E_apelido2.item, D_apelido);
    //Verificação se o usuario já está na lista de amigos
    if(Search_Amigo(U, &E_apelido2, E_apelido->item) == 1){
        *flag = 1;
        return;
    }

    //Agora enquanto o ponteiro tem dado compara o apelido enviado e o destino e chama a função de Push_Fila
    while(p != NULL){
        if(strcmp(p->info.apelido, D_apelido) == 0){
            //Verificação se já foi enviado um pedido
            if(Search_Fila(p->info.requests, E_apelido)){
              *flag = 3;
              return;
            }
            Push_Fila(p->info.requests, E_apelido, &errorRequest);
            if(!errorRequest){
                *flag = 0;
                return;
            }
        }
        p = p->prox;
    }
    *flag = 1; //Se chegou até aqui deu erro
}


void Received_Pedido(Usuarios *U, char *D_apelido, int *flag) {
  NO_user *p = U->inicio; //primeiro para procurar usuario
  int errorReceived;
  char resposta[5];
  
  while (p != NULL) {

    if(strcmp(p->info.apelido, D_apelido) == 0) {
      if (p->info.requests == NULL){
        *flag = 1;
        return;
      }
      
      else {
        NO_fila *pf = p->info.requests->inicio; //acessa lista de pedidos
        elem_lista amigo, usuario;

        while (pf != NULL) {
          printf("%s quer ser seu(sua) amigo(a). Aceita (sim/não)? \n", pf->info.item);
          scanf("%s", resposta);

          if(strcmp(resposta,"não") == 0) {
            printf("Amizade Recusada.\n");
            Pop_Fila(p->info.requests, &(pf->info), &errorReceived);
            *flag = 2;
            return;
          }
          
          
          else if(strcmp(resposta,"sim") == 0) {
            printf("Amizade Aceita.\n");

            strcpy(amigo.item, p->info.apelido); //amigo aceitou usuario
            strcpy(usuario.item, pf->info.item); //usuario aceitou amigo
            Push_Lista(p->info.friends, &usuario, &errorReceived); 
            //Adiciona amigo na lista do usuario que consultou
            
            NO_user* a = U->inicio; // Segundo para procurar amigo
            while (a != NULL) {
                if(strcmp(a->info.apelido, pf->info.item) == 0)
                    Push_Lista(a->info.friends, &amigo, &errorReceived); //Adiciona usuario na lista de quem pediu amizade 
                a = a->prox;
            }
            Pop_Fila(p->info.requests, &(pf->info), &errorReceived);
            *flag=3;
          }
          pf = pf->prox;
        }
        return;
      }
    }
    p = p->prox;
  }
}

void Send_Mensagens(Usuarios *U, elem_mensagens *E_apelido, char* D_apelido, int *flag){
  NO_user *p = U->inicio;
  int errorMessage;
  elem_lista E_apelido2;

  if(strcmp(E_apelido->remetente,D_apelido) == 0){
    *flag = 2;
    return;
  }
  strcpy(E_apelido2.item, D_apelido);
  //checa se os usuários são amigos, caso negativo envia uma flag
  if(Search_Amigo(U, &E_apelido2, E_apelido->remetente) == 0){
    *flag = 1;
    return;
  }
  //percorre a lista de
  while(p != NULL){
    if (strcmp(p->info.apelido,D_apelido) == 0){
      Push_PM(p->info.messages, E_apelido, &errorMessage);
      if(!errorMessage){
        *flag = 0;
        return;
      }
    }
    p = p->prox;
  }
  *flag = 1;
}

void Received_Mensagens(Usuarios *U, char *D_apelido, int *flag) {
    NO_user *p = U->inicio;
    int errorMessage;
    elem_mensagens pessoa;

    while(p != NULL){
        if(strcmp(p->info.apelido, D_apelido) == 0){
            if(IsEmpty_PM(p->info.messages)){
                *flag = 1;
                return;
            }
            else{
                printf("Suas mensagens são: \n");
                while(!IsEmpty_PM(p->info.messages)){
                    Pop_PM(p->info.messages, &pessoa, &errorMessage);
                    if(!errorMessage){
                        printf("(%s): ",pessoa.remetente);
                        printf("%s\n",pessoa.texto_mensagem);
                    }
                }
                *flag = 0;
                return;
            }
        }
        p = p->prox;
    }
    *flag = 1;
}

void Reiniciar(Usuarios *U){
    NO_user* p = U->inicio;
    while(p != NULL){
        U-> inicio = U->inicio->prox;
        Clear_PM(p->info.messages);
        Empty_Fila(p-> info.requests);
        Empty_Lista(p->info.friends);
        p = U->inicio;
    }
    free(U);
}

int Compare_Lista(Lista *L1, Lista *L2){
    NO_lista* p1 = L1->inicio;
    while(p1 != NULL){
        NO_lista* p2 = L2->inicio;
        while(p2 != NULL){
            if(strcmp(p1->info.item, p2->info.item) == 0){
                return 1;
            }
            p2 = p2->prox;
        }
        p1 = p1->prox;
    }
    return 0;
}

void Sugestao(Usuarios *U, int *flag){
    Lista *Laux = Create_Lista(); 
    elem_lista elem_aux1, elem_aux2;
    int errorAux;
    NO_user *p1 = U->inicio;
    
    if (Len_Usuarios(U) < 3) {
     *flag = 1;
      return;
    }

    else {
    while(p1 != NULL){
        NO_user *p2 = U->inicio;
        while(p2 != NULL){
            if(strcmp(p1->info.apelido, p2->info.apelido) == 0){
                p2 = p2->prox;
                continue;
            }
            if(Compare_Lista(p1->info.friends, p2->info.friends) == 1){
                strcpy(elem_aux1.item, p1->info.apelido);
                strcat(elem_aux1.item, " e ");
                strcat(elem_aux1.item, p2->info.apelido);
                strcpy(elem_aux2.item, p2->info.apelido);
                strcat(elem_aux2.item, " e ");
                strcat(elem_aux2.item, p1->info.apelido);
                if(Search_Lista(Laux, &elem_aux1) && Search_Lista(Laux, &elem_aux2)){
                    p2 = p2->prox;
                    continue;
                }
                printf("Amizade sugerida entre %s e %s\n",p1->info.apelido,p2->info.apelido);
                Push_Lista(Laux, &elem_aux1, &errorAux);
                Push_Lista(Laux, &elem_aux2, &errorAux);
            }
            p2 = p2->prox;
        }
        p1 = p1->prox;
    }
    *flag = 0;
    return;
  }
}

