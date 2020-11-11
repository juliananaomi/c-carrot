#include <stdio.h>
#include <stdlib.h>
#include "rede_social.h"

int main(void) {
  List_User *L;
  L = Registro();
  Cadastro(L);
  return (0);
}