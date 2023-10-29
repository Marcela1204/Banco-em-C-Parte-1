
#include <stdio.h>
#include "library.h"

Cadastro cliente[1000];
ExtratoCliente grupo[1000][1000];
int usados = 0;

int main() {
    int valor;

    while (1){
    printf("Digite o valor da operacao a ser realizada:\n");
    printf("1- Novo Cliente;\n"
           "2- Apagar Cliente;\n"
           "3- Listar Clientes;\n"
           "4- Debito;\n"
           "5- Deposito;\n"
           "6- Extrato;\n"
           "7- Transferencia entre contas;\n"
           "0- Sair;\n");
    printf("Qual operacao deseja realizar?\n");
    scanf("%d", &valor);

    if (valor == 1) {
        NovoCliente(&cliente,&usados, &grupo);
    }

    else if (valor == 2){
        ApagarCliente(&cliente,&usados, &grupo);
    }

    else if (valor == 3){
        ListarClientes(&cliente,&usados);
    }

    else if (valor == 4){
        Debito(&cliente, &usados, &grupo);
    }

    else if (valor == 5){
        Deposito(&cliente,&usados);

    }

    else if (valor == 6){
        Extrato(&cliente,&usados, &grupo);

    }

    else if (valor == 7){

    }

    else if (valor == 0){
        break;
    }

    }


}