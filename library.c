//
// Created by unifmnalesso on 09/10/2023.
//
#include <stdio.h>
#include "library.h"
#include <string.h>

void NovoCliente (Cadastro *pessoas,int *usados, ExtratoCliente *grupo[]){
    while (1){//abre o loop para cadastrar o usuario
        char mensagem[4]; //cria a variavel para guardar resposta da proxima pergunta
        printf("\nQuer continuar a operacao: (Sim ou Nao) R: \n"); //pergunta se a pessoa quer continuar
        scanf("%s",mensagem); //recebe a mensagem
        int positivo = stricmp(mensagem,"Sim"); //compara o que tiver na variavel com a palavra sim
        if (positivo == 0) {//se for igual, faz a operação abaixo
            printf("Digite seu nome: "); //pede o nome do usuario
            scanf("%s", pessoas[*usados].nome); //guarda o nome na variavel nome (dentro da struct)
            printf("Digite seu CPF: "); //pede o CPF do usuario
            scanf("%s", pessoas[*usados].cpf); //guarda o nome na variavel nome (dentro da struct)
            while (1){ //abre o loop para cadastrar o tipo de conta do usuario
            printf("Digite o tipo da sua conta: \n" //pede o tipo de conta
                   "1 - Comum;\n"
                   "2 - Plus\n"
                   "R: ");
            int tipotemp;
            scanf("%d", &tipotemp); //guarda a escolha na variavel para realizar a condicional
            if (tipotemp == 2){ //se o valor da variavel for 2, a taxa das operações se torna de 3% e o saldo fica negativo de até 5000.00
                pessoas[*usados].taxa = 0.03;
                pessoas[*usados].minimo = (-5000);
                break; //quebra o loop do tipo de conta e vai para a sessão de senha
            } else if(tipotemp == 1){ //se o valor da variavel for 1, a taxa das operações se torna de 3% e o saldo fica negativo de até 1000.00
                pessoas[*usados].taxa = 0.05;
                pessoas[*usados].minimo = (-3000);
                break; //quebra o loop do tipo de conta e vai para a sessão de senha
            }else{ //caso não seja nem 1 e nem 2, printa a proxima mensagem
                printf("Valor incorreto!\n");
                continue; //faz o loop voltar para o menu
            }
            }
            printf("Digite um valor inicial para colocar na conta: "); //pede ujm valor inicial para conta
            scanf("%lf", &pessoas[*usados].saldo); //guarda o valor na variavel saldo (dentro da struct)
            char senhaconfirma[20]; //variavel para guardar a primeira senha digitada
            char senhatemporaria[20]; //variavel para guardar a segunda senha digitada
            printf("Digite sua senha: "); //pede a primeira senha
            scanf("%s", senhatemporaria); //guarda a primeira senha nesta variavel
            printf("Confirma sua senha? R: "); //pede a segunda senha
            scanf("%s", senhaconfirma); //guarda a segunda senha nesta variavel
            int comparacao = stricmp(senhatemporaria,senhaconfirma); //compara se as senhas são iguais
            if (comparacao == 0){ //se forem iguais, guarda a senha na variavel senha (dentro da struct)
                strcpy(pessoas[*usados].senha,senhatemporaria);
                printf("Conta criada com sucesso!\n");
                //char tmpsaldo[500];
                //sprintf(tmpsaldo, "Conta criada.\n"
                //                  "Deposito : %.2lf", pessoas[*usados].saldo);
                //strcpy(grupo[*usados][0].info,tmpsaldo);
                //pessoas[*usados].transacao = 1;
                *usados+=1;
            } else{ //caso contrário, printa a próxima mensagem e realiza a operação novamente
                printf("Senha incorreta! Realize a operacao novamente!\n");
                continue;
            }
        } else{//caso o usuario nao queira continuar a operação, o loop se encerra e volta para o menu
            break;
        }
    }

}



