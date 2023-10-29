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
    double saldo;
    char senha[20];

    double taxa;
    double minimo;
}Cadastro;

void NovoCliente (Cadastro *,int *);
void ApagarCliente (Cadastro *,int *);
void ListarClientes (Cadastro *, int *);
void Debito (Cadastro *, int *);
void Deposito (Cadastro *,int *);
void Extrato (Cadastro *);
void Transfarencia (Cadastro *);
void DebitoAutomatico (Cadastro *);
