#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

/*  Pilha Inverter(Pilha *P) {
    Pilha *Paux;
    int x, erro;
    while (!IsEmpty) {
        x = Top(P, &erro);
        Push(*Paux, &x, &erro);
    }
    
}
*/

int main(void){
    Pilha P;
    elem x;
    int erro;
    Create(&P);
    x=10;
    Push(&P, &x, &erro);
    x=2;
    Push(&P, &x, &erro);
    Print(&P);
    return(0);
}