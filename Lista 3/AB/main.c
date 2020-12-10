#include <stdio.h>
#include <stdlib.h>
#include "ab.h"

int main(void) {
  AB *A;
  int erro;
  elem x;
  A = criar();
  x= 4;
  inserir_esq(A, &(A->raiz->info), &x, &erro);
  x= 5;
  inserir_esq(A, &(A->raiz->info), &x, &erro);
  x= 2;
  inserir_dir(A, &(A->raiz->info), &x, &erro);
  preordem(A->raiz);
}