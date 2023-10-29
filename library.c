//
// Created by unifmnalesso on 09/10/2023.
//
#include <stdio.h>
#include "library.h"
#include <string.h>

void NovoCliente (Cadastro *pessoas,int *usados, ExtratoCliente *grupo[]){
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
                char tmpsaldo[500];
                sprintf(tmpsaldo, "Conta criada.\n"
                                  "Deposito : %.2lf", pessoas[*usados].saldo);
                strcpy(grupo[*usados][0].info,tmpsaldo);
                pessoas[*usados].transacao = 1;
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

void ApagarCliente (Cadastro *pessoas, int *usados, ExtratoCliente *grupo){
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
            grupo[h] = grupo[h+1];
            //printf("%s",pessoas[h].nome);//temporario
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

void Debito (Cadastro *pessoas, int *usados, ExtratoCliente *grupo[]){
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

            double valordigitado;
            printf("Quanto deseja debitar da conta? R: ");
            scanf("%lf",&valordigitado);
            if (pessoas[i].minimo <= pessoas[i].saldo - ((pessoas[i].taxa * valordigitado)+valordigitado)){
                pessoas[i].saldo = pessoas[i].saldo - (pessoas[i].taxa * valordigitado)-valordigitado;
                printf("Seu saldo atual eh: %.2lf", pessoas[i].saldo);
                char tmpsaldo[500];
                sprintf(tmpsaldo,"Debito : %.2lf", pessoas[i].saldo);
                strcpy(grupo[i][pessoas[i].transacao].info,tmpsaldo);
                pessoas[i].transacao++;
            } else{
                printf("Valor do debito superior ao valor disponivel na conta!", pessoas[i].saldo);
            }




        } else{
            break;
        }
    }

}
void Deposito (Cadastro *pessoas, int *usados) {
    char cpf[11];
    int i;
    printf("Digite seu cpf para deposito: ");
    scanf("%s",cpf);
    //int exec = 1;
    for (i = 0; i < *usados + 1; ++i) {
        char comparativo[11];
        strcpy(comparativo,pessoas[i].cpf);
        int resultado = stricmp(cpf, comparativo);
        //printf("exec %d\n",exec);
        //exec++;
       // for (int j = 0; j < 11; ++j) {
            //printf("\n");
           // int valor = cpf[j]-comparativo[j];
           // printf("%d\n",valor);
       // }
        if (resultado == 0) {
            break;
        } else if (resultado != 0 && i > *usados) {
            printf("CPF nao encontrado!\n");
            return;
        } else {
            continue;
        }

    }
    printf("Insira o valor a ser depositado: \n");
    double valor;
    scanf("%lf",&valor);
    pessoas[i].saldo = pessoas[i].saldo + valor;
    printf("Seu saldo atual é %.2lf\n", pessoas[i].saldo);

}
void Extrato (Cadastro *pessoas ,int *usados, ExtratoCliente *grupo) {
    char cpf[11];
    while (1) {
        char mensagem[4];
        printf("\n");
        printf("Quer continuar a operacao: (Sim ou Nao) R: \n");
        scanf("%s", mensagem);
        int positivo = stricmp(mensagem, "Sim");
        if (positivo == 0) {
            printf("Digite seu CPF: ");
            scanf("%s", cpf);
            int i;
            for (i = 0; i <= *usados + 1; ++i) {
                int resultado = stricmp(cpf, pessoas[i].cpf);
                if (resultado == 0) {
                    break;
                } else if (resultado != 0 && i > *usados) {
                    printf("CPF nao encontrado!\n");
                    return;
                } else {
                    continue;//Isso funciona? O código chega nesse cara? SIM
                }
            }
            while (1) {
                char senhaconfirma[20];
                strcpy(senhaconfirma, pessoas[i].senha);
                char senhatemporaria[20];
                printf("Digite sua senha: ");
                scanf("%s", senhatemporaria);
                int comparacao = stricmp(senhatemporaria, senhaconfirma);
                if (comparacao == 0) {
                    break;
                } else {
                    printf("Senha incorreta! Realize a operacao novamente!\n");
                    continue;
                }
            }


        }
    }



}


void Transferencia (Cadastro *pessoas, int *usados){
    char cpf[11];
    char cpf2[11];
    int i;
    int j;
    printf("Digite seu cpf de origem: ");
    scanf("%s",cpf);
    //int exec = 1;
    for (i = 0; i < *usados + 1; ++i) {
        char comparativo[11];
        strcpy(comparativo, pessoas[i].cpf);
        int resultado = stricmp(cpf, comparativo);
        if (resultado == 0) {
            break;
        } else if (resultado != 0 && i > *usados) {
            printf("CPF nao encontrado!\n");
            return;
        } else {
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
        printf("Digite seu cpf de destino: ");
        scanf("%s",cpf2);
        for (j = 0; j < *usados + 1; ++j) {
            char comparativo[11];
            strcpy(comparativo, pessoas[j].cpf);
            int resultado = stricmp(cpf2, comparativo);
            if (resultado == 0) {
                break;
            } else if (resultado != 0 && j > *usados) {
                printf("CPF nao encontrado!\n");
                return;
            } else {
                continue;
            }
        }
        double transferencia;
        printf("quanto deseja transferir?");
        scanf("%lf", &transferencia);
        pessoas[i].saldo-=transferencia;
        pessoas[j].saldo+=transferencia;



}