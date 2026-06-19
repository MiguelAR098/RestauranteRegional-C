#include <stdio.h>
#include <string.h>
#include "clientes.h"
#include "utils.h"

// ================= Variáveis Globais ================= //

Cliente clientes[MAX_CLIENTES];

int totalClientes = 0;

// ================= Funções Auxiliares ================= //

int cpfExiste(char cpf[]) {

    for(int i = 0; i < totalClientes; i++) {

        if(strcmp(clientes[i].cpf, cpf) == 0) {

            return 1;
        }
    }

    return 0;
}

// ================= Arquivo TXT ================= //

void salvarClientes() {

    FILE *arquivo;

    arquivo = fopen("data/clientes.txt", "w");

    if(arquivo == NULL) {

        printf("\nErro ao salvar clientes!\n");
        return;
    }

    for(int i = 0; i < totalClientes; i++) {

        fprintf(
            arquivo,
            "%d;%s;%s;%s\n",
            clientes[i].id,
            clientes[i].nome,
            clientes[i].cpf,
            clientes[i].telefone
        );
    }

    fclose(arquivo);
}

void carregarClientes() {

    FILE *arquivo;

    arquivo = fopen("data/clientes.txt", "r");

    if(arquivo == NULL) {

        return;
    }

    while(
        fscanf(
            arquivo,
            "%d;%99[^;];%14[^;];%19[^\n]\n",
            &clientes[totalClientes].id,
            clientes[totalClientes].nome,
            clientes[totalClientes].cpf,
            clientes[totalClientes].telefone
        ) == 4
    ) {

        totalClientes++;

        if(totalClientes >= MAX_CLIENTES) {

            break;
        }
    }

    fclose(arquivo);
}

// ================= Cadastro ================= //

void cadastrarCliente() {

    limparTela();

    if(totalClientes >= MAX_CLIENTES) {

        printf("\nLimite de clientes atingido!\n");
        return;
    }

    Cliente novo;

    novo.id = (totalClientes == 0)
                ? 1
                : clientes[totalClientes - 1].id + 1;

    printf("\n=== Cadastro de Cliente ===\n");

    printf("Nome: ");
    fgets(novo.nome, TAM_NOME, stdin);
    removerNewline(novo.nome);

    if(strlen(novo.nome) == 0) {

        printf("\nNome não pode ser vazio!\n");
        return;
    }

    printf("CPF: ");
    fgets(novo.cpf, TAM_CPF, stdin);
    removerNewline(novo.cpf);

    if(cpfExiste(novo.cpf)) {

        printf("\nCPF já cadastrado!\n");
        return;
    }

    printf("Telefone: ");
    fgets(novo.telefone, TAM_TEL, stdin);
    removerNewline(novo.telefone);

    clientes[totalClientes] = novo;

    totalClientes++;

    salvarClientes();

    printf("\nCliente cadastrado com sucesso!\n");
}

// ================= Consultas Auxiliares ================= //

int buscarClientePorId(int id, Cliente *out) {

    if (out == NULL) return 0;

    for (int i = 0; i < totalClientes; i++) {
        if (clientes[i].id == id) {
            *out = clientes[i];
            return 1;
        }
    }

    return 0;
}
