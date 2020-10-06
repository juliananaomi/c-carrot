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

int main(void) {
    int n, i;
    Dados *Registro;
    printf("Deseja adicionar um número a sua Agenda?");
    printf("1-Sim \n 2-Não");
    scanf("%d", &n);
    Registro = (Dados *)malloc(sizeof(Dados));
    i=0;
    while(n==1) { // Sim
        ler_dados(Registro, i);
        printf("Deseja adicionar mais um numero na Agenda?");
        printf("1-Sim \n 2-Não");
        scanf("%d", &n);
        if(n==1){
            i+=1;
            Registro = realloc(Registro, (i+1)*sizeof(Dados));
            ler_dados(Registro, i);
        }
        else return(Registro);
    }
}