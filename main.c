
#include <stdio.h>
#include "library.h"

Cadastro cliente[1000];//struct de clientes
ExtratoCliente grupo[1000][1000];//struct de extrato
int usados;//variavel para percorrer os cliente


int main() {
    int valor;
    while (1){//loop de menu
    printf("Digite o valor da operacao a ser realizada:\n");//menu de destino
    printf("1- Novo Cliente;\n"
           "2- Apagar Cliente;\n"
           "3- Listar Clientes;\n"
           "4- Debito;\n"
           "5- Deposito;\n"
           "6- Extrato;\n"
           "7- Transferencia entre contas;\n"
           "0- Sair;\n");
    printf("Qual operacao deseja realizar?\n");//pede o valor da operação
    scanf("%d", &valor);//guarda o valor da operação

    if (valor == 1) {//se o valor da operação for igual a 1
        NovoCliente(&cliente,&usados, &grupo); //vai para função Novo cliente
    }

    else if (valor == 2){//se o valor da operação for igual a 2
        
    }

    else if (valor == 3){//se o valor da operação for igual a 3
        
    }

    else if (valor == 4){//se o valor da operação for igual a 4
        
    }

    else if (valor == 5){//se o valor da operação for igual a 5
        

    }

    else if (valor == 6){//se o valor da operação for igual a 6
        

    }

    else if (valor == 7){//se o valor da operação for igual a 7
        

    }

    else if (valor == 0){//se o valor da operação for igual a 0
        break;//o programa se encerra
    }

    }


}