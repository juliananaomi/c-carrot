#include <stdio.h>
#include <stdlib.h>
#include "rede_social.h"

List_User* Registro(void){
  List_User *L = (List_User *)malloc(sizeof(List_User));
  L->ini = NULL;
  L->fim = NULL;
  return(L);
}

int Cadastro(List_User *L) {
    User *user = (User *)malloc(sizeof(User));
    if(user==NULL) return(1); //Não conseguiu alocar

    else {

      printf("Entre com seu nome: ");
      scanf("%s", user->info.nome);
      printf("Entre com seu apelido: ");
      scanf("%s", user->info.apelido);

      //último a ser adicionado, ainda sem nenhuma informação
      user->nextUser = NULL; 
      user->nextFriend = NULL;
      user->nextRequest = NULL;

      if (L->ini==NULL) L->ini = user;
      else L->fim->nextUser=user; //Encadeia
      L->fim = user;
      printf("Usuario cadastrado com sucesso!");
      return(0);
  }
}

