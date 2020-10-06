#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char numero[11], nome[30];
} Agenda;

void ler_dados(Agenda *p, int n_pessoas) {
    int i;
    for (i=0; i<n_pessoas; i++) {
        printf("Pessoa %d - Entre com o nome: ", i+1);
        scanf("%s", p[i].nome);
        printf("Pessoa %d - Entre com o numero de telefone: ", i+1);
        scanf("%s", p[i].numero);   
    } 
}

int main(void) {
    int n_pessoas;
    printf("Informe o numero de pessoas a serem armazenadas\n");
    scanf("%d", &n_pessoas);
    Agenda *pessoa;
    pessoa = (Agenda *)malloc( n_pessoas*sizeof(Agenda));  
    ler_dados(pessoa, n_pessoas); 
    return(0); 
}