#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CLIENTES 100
#define TAM_NOME     100
#define TAM_CPF      15
#define TAM_TEL      20

typedef struct {
    int  id;
    char nome[TAM_NOME];
    char cpf[TAM_CPF];
    char telefone[TAM_TEL];
} Cliente;

Cliente clientes[MAX_CLIENTES];
int total = 0;

void removerNewline(char *str) {
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';
}

int cadastrarCliente() {
    if (total >= MAX_CLIENTES) {
        printf("Limite de clientes atingido!\n");
        return 0;
    }

    Cliente novo;
    novo.id = total + 1;

    printf("Nome: ");
    fgets(novo.nome, TAM_NOME, stdin);
    removerNewline(novo.nome);

    if (strlen(novo.nome) == 0) {
        printf("Erro: nome nao pode ser vazio.\n");
        return 0;
    }

    printf("CPF (000.000.000-00): ");
    fgets(novo.cpf, TAM_CPF, stdin);
    removerNewline(novo.cpf);

    printf("Telefone: ");
    fgets(novo.telefone, TAM_TEL, stdin);
    removerNewline(novo.telefone);

    clientes[total++] = novo;

    printf("\nCliente #%d cadastrado com sucesso!\n", novo.id);
    return 1;
}

void listarClientes() {
    if (total == 0) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }
    printf("\n%-4s %-30s %-15s %-15s\n", "ID", "Nome", "CPF", "Telefone");
    printf("--------------------------------------------------------------\n");
    int i;
    for (i = 0; i < total; i++) {
        printf("%-4d %-30s %-15s %-15s\n",
            clientes[i].id,
            clientes[i].nome,
            clientes[i].cpf,
            clientes[i].telefone);
    }
}

int main() {
    int opcao;
    do {
        printf("\n1 - Cadastrar cliente\n");
        printf("2 - Listar clientes\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1: cadastrarCliente(); break;
            case 2: listarClientes();   break;
        }
    } while (opcao != 0);

    return 0;
}