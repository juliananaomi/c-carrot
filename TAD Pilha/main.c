#include "pilha.h"

int main(void){
    int erro, x;
    Pilha P;
    Create(&P);
    Push(&P, x, &erro);
    Pop(&P, &x, &erro);
    return(0);
}