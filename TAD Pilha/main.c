#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

void Inverter(Pilha *P) {
    Pilha Paux1, Paux2;
    Create(&Paux1);
    Create(&Paux2);
    elem x; 
    int erro;
    while (!IsEmpty(P)) {
        Pop(P, &x, &erro);
        Push(&Paux1, &x, &erro);
    }
    while (!IsEmpty(&Paux1)) {
        Pop(&Paux1, &x, &erro);
        Push(&Paux2, &x, &erro);
    }
    while (!IsEmpty(&Paux2)) {
        Pop(&Paux2, &x, &erro);
        Push(P, &x, &erro);
    }
}

int main(void){
    Pilha P;
    elem x;
    int erro;
    Create(&P);
    x=10;
    Push(&P, &x, &erro);
    x=2;
    Push(&P, &x, &erro);
    x=9;
    Push(&P, &x, &erro);
    Print(&P);
    Inverter(&P);
    Print(&P);
    return(0);
}