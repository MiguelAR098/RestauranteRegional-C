#include <stdio.h>
#include <string.h>

#include "relatorios.h"
#include "clientes.h"
#include "pratos.h"
#include "utils.h"

void listarClientesRelatorio() {
    printf("\n=== Relatório: Lista de Clientes ===\n");
    listarClientes();
}

void listarPratosRelatorio() {
    printf("\n=== Relatório: Lista de Pratos ===\n");
    listarPratos();
}

// Lê data/pedidos.txt no formato: IDPedido;IDCliente;ValorTotal
static void imprimirPedidosDoArquivo(const char *caminhoArquivo) {
    FILE *arquivo = fopen(caminhoArquivo, "r");
    if (arquivo == NULL) {
        printf("\nNenhum pedido registrado ainda.\n");
        return;
    }

    int idPedido;
    int idCliente;
    float valorTotal;

    printf("\n==================================================================\n");
    printf("%-10s %-12s %-12s\n", "IDPedido", "IDCliente", "ValorTotal");
    printf("==================================================================\n");

    int teveAlgum = 0;
    while (fscanf(arquivo, "%d;%d;%f\n", &idPedido, &idCliente, &valorTotal) == 3) {
        teveAlgum = 1;
        printf("%-10d %-12d R$ %-10.2f\n", idPedido, idCliente, valorTotal);
    }

    if (!teveAlgum) {
        printf("\nNenhum pedido registrado ainda.\n");
    }

    fclose(arquivo);
}

void listarPedidosRelatorio() {
    printf("\n=== Relatório: Lista de Pedidos ===\n");
    imprimirPedidosDoArquivo("data/pedidos.txt");
}

void resumoVendas() {
    printf("\n=== Resumo de Vendas ===\n");

    FILE *arquivo = fopen("data/pedidos.txt", "r");
    if (arquivo == NULL) {
        printf("\nNenhuma venda registrada ainda.\n");
        return;
    }

    int idPedido;
    int idCliente;
    float valorTotal;

    int quantidadePedidos = 0;
    double totalVendido = 0.0;

    while (fscanf(arquivo, "%d;%d;%f\n", &idPedido, &idCliente, &valorTotal) == 3) {
        quantidadePedidos++;
        totalVendido += (double)valorTotal;
    }

    fclose(arquivo);

    printf("Pedidos registrados: %d\n", quantidadePedidos);
    printf("Valor total vendido: R$ %.2f\n", (float)totalVendido);

    if (quantidadePedidos > 0) {
        double ticketMedio = totalVendido / (double)quantidadePedidos;
        printf("Ticket médio: R$ %.2f\n", (float)ticketMedio);
    } else {
        printf("Ticket médio: R$ 0.00\n");
    }
}

void gerarRelatorios() {
    int opcao;

    do {
        limparTela();

        printf("\n===== RELATÓRIOS =====\n");
        printf("1 - Listar clientes\n");
        printf("2 - Listar pratos\n");
        printf("3 - Listar pedidos\n");
        printf("4 - Resumo de vendas\n");
        printf("0 - Voltar\n\n");
        printf("Escolha: ");

        if (scanf("%d", &opcao) != 1) {
            printf("\nEntrada inválida.\n");
            limparBuffer();
            pausar();
            opcao = -1;
            continue;
        }

        limparBuffer();

        switch (opcao) {
            case 1:
                listarClientesRelatorio();
                pausar();
                break;
            case 2:
                listarPratosRelatorio();
                pausar();
                break;
            case 3:
                listarPedidosRelatorio();
                pausar();
                break;
            case 4:
                resumoVendas();
                pausar();
                break;
            case 0:
                break;
            default:
                printf("\nOpção inválida!\n");
                pausar();
                break;
        }
    } while (opcao != 0);
}

