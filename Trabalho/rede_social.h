#include <stdio.h>
#include <stdlib.h>

typedef struct { //Dados do usuário
  char nome[30], apelido[20];
}Dados;

typedef struct Mensagens { //Pilha para envio de mensagens
  int *topo;
}Message;

typedef struct Parceiros { //Lista de parceiros do usuario
  Message *nextMessage;
}Friend;

typedef struct Pedidos { //Fila de pedidos de parceria
  int *inicio, *fim, total;
}Request;

typedef struct Usuario { // Informações do usuário

        Dados info; //Informações de cadastro
        Friend *nextFriend; //Amigos do usuário
        Request *nextRequest; // Solicitações de amizade

        struct Usuario *nextUser; //Ponteiro para o próximo usuário
}User;

typedef struct { //Lista contendo os usuarios da rede
    User *ini, *fim;
}List_User;


//Funções

List_User* Registro(void);
int Cadastro(List_User*);
