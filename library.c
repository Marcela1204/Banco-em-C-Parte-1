//
// Created by unifmnalesso on 09/10/2023.
//
#include <stdio.h>
#include "library.h"
#include <string.h>

void NovoCliente (Cadastro *pessoas,int *usados){
    while (1){
        char mensagem[4];
        printf("Quer continuar a operacao: (Sim ou Nao) R: ");
        scanf("%s",mensagem);
        int positivo = stricmp(mensagem,"Sim");
        if (positivo == 0) {
            printf("Digite seu nome: ");
            scanf("%s", pessoas[*usados].nome);
            printf("Digite seu CPF: ");
            scanf("%s", pessoas[*usados].cpf);
            printf("Digite o tipo da sua conta: ");
            scanf("%d", &pessoas[*usados].tipo);
            printf("Digite um valor inicial para colocar na conta: ");
            scanf("%lf", &pessoas[*usados].valorinicial);
            char senhaconfirma[20];
            char senhatemporaria[20];
            printf("Digite sua senha: ");
            scanf("%s", senhatemporaria);
            printf("Confirma sua senha? R: ");
            scanf("%s", senhaconfirma);
            int comparacao = stricmp(senhatemporaria,senhaconfirma);
            if (comparacao == 0){
                strcpy(pessoas[*usados].senha,senhatemporaria);
                printf("Conta criada com sucesso!\n\n");
                *usados+=1;
            } else{
                printf("Senha incorreta! Realize a operacao novamente!\n");
                continue;
            }
        } else{
            break;
        }
    }

}

void ApagarCliente (Cadastro *pessoas, int *usados){
    char cpf[11];
    printf("Digite o cpf a ser removido: ");
    scanf("%s",cpf);
    int i;
    for (i = 0; i <= *usados+1; ++i) {
        int resultado = stricmp(cpf,pessoas[i].cpf);
        if(resultado == 0){
            break;
        } else if(resultado != 0 && i>*usados){
            printf("cpf nao encontrado");
            return;
        }else{
            continue;
        }
    }
    while (1){
        char senhaconfirma[20];
        strcpy(senhaconfirma,pessoas[i].senha);
        char senhatemporaria[20];
        printf("Digite sua senha: ");
        scanf("%s", senhatemporaria);
        int comparacao = stricmp(senhatemporaria,senhaconfirma);
        if (comparacao == 0){
            break;
        } else {
            printf("Senha incorreta! Realize a operacao novamente!\n");
            continue;
        }
    }

    int j;
    for (j = 0; j < 1001; ++j) {//i é equivalente ao valor dos indices do array, nosso array contendo 1000 espaços se ele percorrer 1001 como demonstrado no if significa que ele não existe no array, considerando o 1001 como um codigo de erro
        int comparacao = stricmp(cpf,pessoas[j].cpf);
        if(comparacao == 0){
            break;
    }
        }if(j==1001){
        printf("CPF nao encontrado!");

    }else{
        for (int h = j; h < 999; ++h) {
            pessoas[h] = pessoas[h+1];
            printf("%s",pessoas[h].nome);//temporario
        }
    }
    *usados-=1;
    printf("Operacao concluida com sucesso!\n\n");

    


}
void ListarClientes (Cadastro *pessoas, int *usados){
    printf("\n=========================================================================\n");
    for (int i = 0; i < *usados; ++i) {
        printf("Usuario %d:\n",i+1);
        printf("Nome: %s\n",pessoas[i].nome);
        printf("CPF:%s\n",pessoas[i].cpf);
        printf("-----------------------------------------------------------------------\n");
    }
    printf("=========================================================================\n\n");

}

void Debito (Cadastro *){

}
void Deposito (Cadastro *){}
void Extrato (Cadastro *) {}
void Transfarencia (Cadastro *) {}
void DebitoAutomatico (Cadastro *) {}