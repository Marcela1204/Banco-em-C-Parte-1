//
// Created by unifmnalesso on 09/10/2023.
//

#ifndef PROJETO2_LIBRARY_H
#define PROJETO2_LIBRARY_H

#endif //PROJETO2_LIBRARY_H

typedef struct {
    char nome[100];
    char cpf[11];
    double saldo;
    char senha[20];
    double taxa;
    double minimo;
    int transacao;
}Cadastro;

typedef struct {
    char info[1000];
}ExtratoCliente;

void NovoCliente (Cadastro *,int *, ExtratoCliente *[]);
void ApagarCliente (Cadastro *,int *, ExtratoCliente *);
void ListarClientes (Cadastro *, int *);
void Debito (Cadastro *, int *, ExtratoCliente *[]);
void Deposito (Cadastro *,int *);
void Extrato (Cadastro *, int *, ExtratoCliente *);
void Transferencia (Cadastro *, int *);
