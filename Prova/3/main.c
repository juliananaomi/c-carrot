#include "pilhap.h"
#include <stdio.h>


int main(void){
    Pilha P;
    Dados x;
    int erro;
    Criar(&P);
    ler_dados(&P, &x);
    Push(&P, &x, &erro);
    return(0);
}