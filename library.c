//
// Created by unifmnalesso on 09/10/2023.
//
#include <stdio.h>
#include "library.h"

void NovoCliente (Cadastro *pessoas, char mensagem){
    while (1){
        printf("Quer continuar a operação: (Sim ou Não) R: ");
        scanf("%s",mensagem);
        if (mensagem == "SIM" || mensagem == "Sim" || mensagem == "sim") {
            printf("Digite seu nome: ");
            scanf("%s", pessoas->nome);
            printf("Digite seu CPF: ");
            scanf("%s", pessoas->cpf);
            printf("Digite o tipo da sua conta: ");
            scanf("%d", pessoas->tipo);
            printf("Digite um valor inicial para colocar na conta: ");
            scanf("%f", pessoas->valorinicial);
            char senhaconfirma[20];
            char senhatemporaria[20];
            printf("Digite sua senha: ");
            scanf("%s", senhatemporaria);
            printf("Confirma sua senha? R:");
            scanf("%s", senhaconfirma);
            if (senhatemporaria == senhaconfirma){
                pessoas->senha = senhaconfirma;
            }

        } else{
            break;
        }
    }

}

void ApagarCliente (Cadastro *){}
void ListarClientes (Cadastro *){}
void Debito (Cadastro *){}
void Deposito (Cadastro *){}
void Extrato (Cadastro *) {}
void Transfarencia (Cadastro *) {}
void DebitoAutomatico (Cadastro *) {}