//
// Created by unifmnalesso on 09/10/2023.
//
#include <stdio.h>
#include "library.h"
#include <string.h>

void NovoCliente (Cadastro *pessoas,int *usados){
    while (1){
        char mensagem[4];
        printf("\nQuer continuar a operacao: (Sim ou Nao) R: \n");
        scanf("%s",mensagem);
        int positivo = stricmp(mensagem,"Sim");
        if (positivo == 0) {
            printf("Digite seu nome: ");
            scanf("%s", pessoas[*usados].nome);
            printf("Digite seu CPF: ");
            scanf("%s", pessoas[*usados].cpf);
            while (1){
            printf("Digite o tipo da sua conta: \n"
                   "1 - Comum;\n"
                   "2 - Plus\n"
                   "R: ");
            int tipotemp;
            scanf("%d", &tipotemp);
            if (tipotemp == 2){
                pessoas[*usados].taxa = 0.03;
                pessoas[*usados].minimo = (-5000);
                break;
            } else if(tipotemp == 1){
                pessoas[*usados].taxa = 0.05;
                pessoas[*usados].minimo = (-3000);
                break;
            }else{
                printf("Valor incorreto!\n");
                continue;
            }
            }
            printf("Digite um valor inicial para colocar na conta: ");
            scanf("%lf", &pessoas[*usados].saldo);
            char senhaconfirma[20];
            char senhatemporaria[20];
            printf("Digite sua senha: ");
            scanf("%s", senhatemporaria);
            printf("Confirma sua senha? R: ");
            scanf("%s", senhaconfirma);
            int comparacao = stricmp(senhatemporaria,senhaconfirma);
            if (comparacao == 0){
                strcpy(pessoas[*usados].senha,senhatemporaria);
                printf("Conta criada com sucesso!\n");
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
            printf("CPF nao encontrado!\n");
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
        printf("CPF nao encontrado!1\n");

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
        printf("-------------------------------------------------------------------------\n");
    }
    printf("=========================================================================\n\n");

}

void Debito (Cadastro *pessoas, int *usados){
    char cpf[11];
    while (1) {
        char mensagem[4];
        printf("\n");
        printf("Quer continuar a operacao: (Sim ou Nao) R: \n");
        scanf("%s", mensagem);
        int positivo = stricmp(mensagem, "Sim");
        if (positivo == 0) {
            printf("Digite seu CPF: ");
            scanf("%s",cpf);
            int i;
            for (i = 0; i <= *usados+1; ++i) {
                int resultado = stricmp(cpf,pessoas[i].cpf);
                if(resultado == 0){
                    break;
                } else if(resultado != 0 && i>*usados){
                    printf("CPF nao encontrado!\n");
                    return;
                }else{
                    continue;//Isso funciona? O código chega nesse cara? SIM
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

            double valordigitado;
            printf("Quanto deseja debitar da conta? R: ");
            scanf("%lf",&valordigitado);
            if (pessoas[*usados].minimo <= pessoas[*usados].saldo - (pessoas[*usados].taxa * valordigitado+valordigitado)){
                pessoas[*usados].saldo = pessoas[*usados].saldo - (pessoas[*usados].taxa * valordigitado)-valordigitado;
                printf("Seu saldo atual eh: %lf", pessoas[*usados].saldo);
            } else{
                printf("Valor do debito superior ao valor disponivel na conta!", pessoas[*usados].saldo);
            }




        } else{
            break;
        }
    }

}
void Deposito (Cadastro *pessoas, int *usados) {
    char cpf[11];
    int i;
    printf("Digite seu cpf para deposito");
    scanf("%s",cpf);
    for (i = 0; i <= *usados + 1; ++i) {
        int resultado = stricmp(cpf, pessoas[i].cpf);
        if (resultado == 0) {
            break;
        } else if (resultado != 0 && i > *usados) {
            printf("CPF nao encontrado!\n");
            return;
        } else {
            continue;
        }

    }
    printf("insira o valor a ser depositado");
    double valor;
    scanf("%lf",&valor);
    pessoas[i].saldo+=valor;

}
void Extrato (Cadastro *) {}
void Transfarencia (Cadastro *) {}
void DebitoAutomatico (Cadastro *) {}