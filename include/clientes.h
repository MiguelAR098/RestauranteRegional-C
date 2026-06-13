#ifndef CLIENTES_H
#define CLIENTES_H

#define MAX_CLIENTES 100
#define TAM_NOME 100
#define TAM_CPF 15
#define TAM_TEL 20

typedef struct {

    int id;
    char nome[TAM_NOME];
    char cpf[TAM_CPF];
    char telefone[TAM_TEL];

} Cliente;

void cadastrarCliente();
void listarClientes();
void salvarClientes();
void carregarClientes();
int menu_Clientes();
void menuClientes();

#endif