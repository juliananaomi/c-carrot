#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//=============================================================
// Estrutura Mensagens - Pilha
//=============================================================

typedef struct{
    char remetente[50];
    char texto_mensagem[300];
} elem_mensagens;

struct no_pilha_mensagem{
   elem_mensagens info;
   struct no_pilha_mensagem *next_msg; 
};

typedef struct no_pilha_mensagem NO_mensagem;

typedef struct{
    NO_mensagem *topo;
}Pilha_mensagens;

//Mensagens - Pilha

// Criar a pilha
Pilha_mensagens* Create_PM(void);
//Esvaziar pilha
void Clear_PM(Pilha_mensagens*);
//Enviar mensagem para a pilha
void Push_PM(Pilha_mensagens*, elem_mensagens*, int*);
//Retirar mensagem da pilha
void Pop_PM(Pilha_mensagens*, elem_mensagens*, int*);
//Verificar se pilha está vazia
int IsEmpty_PM(Pilha_mensagens*); 

//=============================================================
// Lista Dinamica Encadeada
//=============================================================

//Contém uma string
typedef struct{
    char item[20];
}elem_lista;

struct no_lista{
    elem_lista info;
    struct no_lista *prox;
};

typedef struct no_lista NO_lista;

typedef struct{
    NO_lista *inicio, *fim;
}Lista;

//Criação da Lista
Lista* Create_Lista(void);

//Esvaziar lista
void Empty_Lista(Lista*);

//Colocar elemento na lista
void Push_Lista(Lista*, elem_lista*, int*);

// Retirar elemento da lista
void Pop_Lista(Lista*, elem_lista*, int*);

//Porcurar elemento na lista
int Search_Lista(Lista*, elem_lista*);

//Tamanho da lista
int Len_Lista(Lista*);

//Printar a lista
void Display_Lista(Lista*);

//=============================================================
// Fila Dinamica Encadeada
//=============================================================

typedef struct{
    char item[20];
}elem_fila;

struct no_fila{
    elem_fila info;
    struct no_fila *prox;
};

typedef struct no_fila NO_fila;

typedef struct{
    NO_fila *inicio, *fim;
}Fila;

//Criação da Fila
Fila* Create_Fila(void);

//Esvaziar a Fila
void Empty_Fila(Fila*);

//Inserir elemento na Fila
void Push_Fila(Fila*, elem_fila*, int*);

//Retirar elemento da Fila
void Pop_Fila(Fila*,elem_fila*, int*);

//Verificar se a Fila está vazia
int IsEmpty_Fila(Fila*);

//Busca um elemento na Fila
int Search_Fila(Fila *F, elem_fila *var);

//=============================================================
// Estrutura Usuarios Final
//=============================================================

//Criação de uma estrutura para elementos do usuario

typedef struct{
    char nome[50];
    char apelido[20];
    Pilha_mensagens *messages;
    Fila *requests;
    Lista *friends;
}elem_user;

typedef struct no_user NO_user;

typedef struct{
    NO_user *inicio, *fim;
}Usuarios;

//Cria a lista com os usuarios
Usuarios* Create_Usuario(void);

//Adiciona um usuario
void Push_Usuario(Usuarios*, char*, char*, int*);

//Imprime usuarios
void Display_Usuario(Usuarios*);

//Verifica se apelido ja está cadastrado
int Verify_Usuario(Usuarios*, char*);

//Função para enviar pedido
void Send_Pedido(Usuarios*, elem_fila*, char*, int*);

//Função para procurar um nome na lista de amigos
int Search_Amigo(Usuarios*, elem_lista*, char*);

//Função para verificar pedidos
void Received_Pedido(Usuarios*, char*, int*); 

//Função para ler mensagens
void Received_Mensagens(Usuarios*, char*, int*);

//Função para enviar mensagens
void Send_Mensagens(Usuarios *U, elem_mensagens *E_apelido, char* D_apelido, int *flag);

//Reinicia a rede social
void Reiniciar(Usuarios *U);

void Sugestao(Usuarios*, int*);

int Compare_Lista(Lista*, Lista*);