#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rede_social.h"

int main (void){
    //Variaveis utilizadas para chamar guardar dados para as funções
    Usuarios *U;
    char nome[50],apelido[20];
    int opcao,PushError,PedidoError, ReceivedError, MessageError, SugestaoError;
    elem_fila Pedido;
    elem_mensagens Mensagem;
    
    U = Create_Usuario();
    while(1){
        printf("Caro usuario, suas opcoes sao:\n");
        printf("  1- Cadastre um usuario\n");
        printf("  2- Listar usuarios cadastrados e suas informacoes\n");
        printf("  3- Pedir para ser parceiro de um usuário\n");
        printf("  4- Avaliar lista de pedidos de parceria\n");
        printf("  5- Enviar mensagem para um parceiro\n");
        printf("  6- Ver mensagens recebidas\n");
        printf("  7- Sugerir novas parcerias\n");
        printf("  8- Reiniciar o sistema\n");
    
    scanf("%d", &opcao);
    system("clear");
    
    switch(opcao){
        case (1):
            setbuf(stdin,NULL);
            printf("Entre com seu nome: ");
            scanf("%[^\n]%*c", nome);
            printf("Entre com seu apelido: ");
            scanf("%[^\n]%*c", apelido);

            Push_Usuario(U,nome,apelido,&PushError); //mudar a função push. apelido esta como variável global, mas tem que ser apenas local. Push(U,&PushError)
            
            if(!PushError)
                printf("Usuario cadastrado com sucesso!\n");
            else if(PushError == 2)
                printf("Apelido ja esta em uso, tente novamente.\n");
            else{
                printf("Comando invalido, tente novamente.\n");
            }
            printf("\n\n");
            break;
        case (2):
            setbuf(stdin,NULL);
            Display_Usuario(U);
            break; 
        case (3):
            setbuf(stdin,NULL);
            printf("Entre com seu apelido: ");
            scanf("%[^\n]%*c", Pedido.item);
            setbuf(stdin,NULL);
            //Conferir se o usuario está cadastrado
            if(!Verify_Usuario(U, Pedido.item)){
                printf("Voce ainda nao efetuou cadastro.");
                printf("\n\n");
                continue;
            }
            
            setbuf(stdin,NULL);
            printf("Entre com o apelido do destinatario:");
            scanf("%[^\n]%*c", apelido);
            
            //Verificar se o usuario alvo exite    
            if(!Verify_Usuario(U, apelido)){
                printf("Usuario destino nao esta cadastrado!");
                printf("\n\n");
                continue;
            }
            //Finalmente o envio do pedidos
            Send_Pedido(U, &Pedido, apelido, &PedidoError);
            if(!PedidoError)
                printf("Pedido enviado com sucesso!\n");
            else{ 
                if(PedidoError == 1)
                    printf("Usuario destino ja esta na sua lista de amigos!");
                else if(PedidoError == 2)
                    printf("Voce nao pode enviar um pedido pra si mesmo!");
                else if(PedidoError == 3)
                    printf("O Usuario destino já possui um pedido seu.");
            }
            printf("\n\n");
            break;

        case (4):
            setbuf(stdin,NULL);
            printf("Entre com o seu apelido: "); 
            scanf("%[^\n]%*c",apelido);

            if(!Verify_Usuario(U, apelido)){
                printf("Voce ainda nao se cadastrou!");
                printf("\n\n");
                continue;
            }
            Received_Pedido(U, apelido, &ReceivedError);

            if(ReceivedError == 1){
              printf("Você não tem pedidos de amizade!");
              printf("\n\n");
              continue;
            }

            setbuf(stdin,NULL);
            break;
        case (5):
            setbuf(stdin,NULL);
            printf("Entre com o seu apelido: "); 
            scanf("%[^\n]%*c",Mensagem.remetente);

            if(!Verify_Usuario(U, Mensagem.remetente)){
                printf("Voce ainda nao se cadastrou!");
                printf("\n\n");
                continue;
            }

            setbuf(stdin,NULL);
            printf("Apelido da pessoa que receberá a mensagem: ");
            scanf("%[^\n]%*c", apelido);

            if(!Verify_Usuario(U, apelido)){
                printf("Usuario destino nao esta cadastrado!");
                printf("\n\n");
                continue;
            }

            setbuf(stdin,NULL);
            printf("Escreva a mensagem: ");
            scanf("%[^\n]%*c", Mensagem.texto_mensagem);

            Send_Mensagens(U, &Mensagem, apelido, &MessageError);

            if(MessageError == 1){
              printf("Este usuario não é seu amigo!");
              printf("\n\n");
              continue;
            }
            else if (MessageError == 2){
              printf("Você não pode enviar mensagens para si mesmo!");
              printf("\n\n");
              continue;
            }
            else if (MessageError == 0){
              printf("Mensagem enviada com sucesso!");
              printf("\n\n");
              continue;
            }

            break;
        case (6):
            setbuf(stdin,NULL);
            printf("Entre com o seu apelido: "); 
            scanf("%[^\n]%*c", apelido);

            if(!Verify_Usuario(U, apelido)){
                printf("Voce ainda nao se cadastrou!");
                printf("\n\n");
                continue;
            }

            
            
            Received_Mensagens(U, apelido, &MessageError);
            
            if(MessageError == 1){
                printf("Você nao possui mensagens!\n");
                printf("\n\n");
                continue;
            }
            else if(MessageError){
                printf("Mensagens exibidas!");
                printf("\n\n");
                continue;
            }
            setbuf(stdin,NULL);
            break;
        case (7):
            Sugestao(U, &SugestaoError);

            if(SugestaoError == 1){
                printf("Não há sugestões de parcerias!\n");
                printf("\n\n");
                continue;
            }
            break;
        case (8):
            setbuf(stdin,NULL);
            Reiniciar(U);
            printf("Rede Social reiniciada !!!");
            printf("\n\n");
            setbuf(stdin,NULL);
            U = Create_Usuario();
            break;
        default:
            getchar();
            printf("Caractere errado, insira um comando valido\n\n");
    }
    }
}
