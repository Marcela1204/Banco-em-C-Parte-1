//
// Created by unifmnalesso on 09/10/2023.
//

#ifndef PROJETO2_LIBRARY_H
#define PROJETO2_LIBRARY_H

#endif //PROJETO2_LIBRARY_H

typedef struct {
    char nome[100];
    char cpf[11];
    int tipo;
    double valorinicial;
    char senha[20];

    double taxa;
    double minimo;
    double saldo;


    char data[20];


    char servico[100];
    double debito;
}Cadastro;

void NovoCliente (Cadastro *,int );
void ApagarCliente (Cadastro *);
void ListarClientes (Cadastro *);
void Debito (Cadastro *);
void Deposito (Cadastro *);
void Extrato (Cadastro *);
void Transfarencia (Cadastro *);
void DebitoAutomatico (Cadastro *);
