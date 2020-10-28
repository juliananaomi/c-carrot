#include "pilhap.h" //Incluindo o TAD criado
#include <stdio.h>

// Função para criar/inicializar a pilha
void Criar(Pilha *P) {
    P->topo =-1; //Pilha vazia
}

int IsEmpty(Pilha *P) {
    if (P->topo==-1) return(1); //Vazia
    else return(0); // Não está vazia
}

int IsFull(Pilha *P) {
    if (P->topo==TamPilha-1)
        return(1); // Cheia
    else return(0); // Ainda há espaço
}

//Preencher os dados do aluno
void ler_dados(Pilha *P, Dados *a) {
    printf("Entre com o nome: ");
    scanf("%s", a[P->topo].nome);
    printf("Entre com o numero USP: ");
    scanf("%d", a[P->topo].numero_USP); 
    printf("Entre com a nota do aluno: ");
    scanf("%d", a[P->topo].nota);   
}

//Função para colocar elementos na pilha
void Push(Pilha *P, Dados *x, int *erro) {
    if (IsFull(P)) {
        *erro=1;
        printf("A pilha está cheia!\n");
    }
    else {
        P->topo++;
        P->aluno[P->topo] = *x;
        *erro=0;
    }
}

void Pop(Pilha *P, Dados *x, int *erro) {
    if (IsEmpty(P)) {
        *erro=1;
        printf("A lista está vazia!\n");
    }
    else {
        *x = P->aluno[P->topo];
        P->topo--;
        *erro=0;
    }
}