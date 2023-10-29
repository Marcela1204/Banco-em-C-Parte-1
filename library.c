//
// Created by unifmnalesso on 09/10/2023.
//
#include <stdio.h>
#include "library.h"
#include <string.h>

void NovoCliente (Cadastro *pessoas,int usados){
    while (1){
        char mensagem[4];
        printf("Quer continuar a operacao: (Sim ou Nao) R: ");
        scanf("%s",mensagem);
        int positivo = stricmp(mensagem,"Sim");
        if (positivo == 0) {
            printf("Digite seu nome: ");
            scanf("%s", pessoas[usados].nome);
            printf("Digite seu CPF: ");
            scanf("%s", pessoas[usados].cpf);
            printf("Digite o tipo da sua conta: ");
            scanf("%d", &pessoas[usados].tipo);
            printf("Digite um valor inicial para colocar na conta: ");
            scanf("%lf", &pessoas[usados].valorinicial);
            char senhaconfirma[20];
            char senhatemporaria[20];
            printf("Digite sua senha: ");
            scanf("%s", senhatemporaria);
            printf("Confirma sua senha? R: ");
            scanf("%s", senhaconfirma);
            int comparacao = stricmp(senhatemporaria,senhaconfirma);
            if (comparacao == 0){
                strcpy(pessoas[usados].senha,senhatemporaria);
                printf("Conta criada com sucesso!\n");
                usados++;
            } else{
                printf("Senha incorreta! Realize a operacao novamente!\n");
                continue;
            }
        } else{
            break;
        }
    }

}

void ApagarCliente (Cadastro *pessoas){
    char cpf[11];
    printf("digite o cpf a ser removido");
    scanf("%s",cpf);
    int i;
    for (i = 0; i < 1001; ++i) {//i é equivalente ao valor dos indices do array, nosso array contendo 1000 espaços se ele percorrer 1001 como demonstrado no if significa que ele não existe no array, considerando o 1001 como um codigo de erro
        int comparacao = stricmp(cpf,pessoas[i].cpf);
        if(comparacao == 0){
            break;
    }
        }if(i==1001){
        printf("cpf nao encontrado");

    }else{
        for (int j = i; j < 999; ++j) {
            pessoas[j] = pessoas[j+1];
            printf("%s",pessoas[j].nome);//temporario
        }
    }
    printf("operacao concluida com sucesso\n");

    


}
void ListarClientes (Cadastro *){


}
void Debito (Cadastro *){}
void Deposito (Cadastro *){}
void Extrato (Cadastro *) {}
void Transfarencia (Cadastro *) {}
void DebitoAutomatico (Cadastro *) {}