#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[30], numero[11];
} Dados;

void ler_dados(Dados *p, int i) {
    printf("Pessoa %d - Entre com o nome: ", i);
    scanf("%s", p[i].nome);
    printf("Pessoa %d - Entre com o numero de telefone: ", i);
    scanf("%s", p[i].numero);  
}

void retirar(Dados *p, char nome_usuario, int i) {
    int j;
    for (j=0; j <= i; j++) {
        if (p[j].nome == nome_usuario) {
            free(p[j].nome);
            free(p[j].numero);
        }
    }
}


int main(void) {
    int n, i, j;
    char usuario;
    Dados *Registro;
    printf("Deseja adicionar um número a sua Agenda?\n1-Sim \n2-Não\n");
    scanf("%d", &n);
    Registro = (Dados *)malloc(sizeof(Dados));
    i=0;
    if(n==1){
        ler_dados(Registro, i);
        while(n==1) { // Sim
            printf("Deseja adicionar/retirar mais um numero na Agenda?\n1-Adicionar \n2-Retirar \n3-Sair\n");
            scanf("%d", &n);
            if(n==1) {
                i+=1;
                Registro = realloc(Registro, (i+1)*sizeof(Dados));
                ler_dados(Registro, i);
            }
            else if (n==2) {
                printf("Qual o nome da pessoa?");
                scanf("%s", &usuario);
                retirar(Registro, usuario, i);
            }
            else {
                for (j=0; j <= i; j++) {
                    printf("Nome: %s\n", Registro[j].nome);
                    printf("Numero: %s", Registro[j].numero);
                }
            }      
        }
    }
    else return(NULL);
}