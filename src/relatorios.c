#include <stdio.h>
#include <string.h>

#include "relatorios.h"
#include "clientes.h"
#include "pratos.h"
#include "utils.h"

void listarClientesRelatorio() {

    FILE *arquivo;

    int id;
    char nome[100];
    char cpf[15];
    char telefone[20];

    arquivo = fopen("data/clientes.txt", "r");

    if(arquivo == NULL) {

        printf("\nNenhum cliente cadastrado.\n");
        return;
    }

    printf("\n==========================================================================\n");
    printf("%-5s %-30s %-15s %-15s\n",
           "ID", "Nome", "CPF", "Telefone");
    printf("==========================================================================\n");

    while(
        fscanf(
            arquivo,
            "%d;%99[^;];%14[^;];%19[^\n]\n",
            &id,
            nome,
            cpf,
            telefone
        ) == 4
    ) {

        printf(
            "%-5d %-30s %-15s %-15s\n",
            id,
            nome,
            cpf,
            telefone
        );
    }

    fclose(arquivo);
}

void listarPratosRelatorio()
{
    FILE *arquivo;

    Prato p;

    arquivo = fopen("data/pratos.txt", "r");

    if (arquivo == NULL)
    {
        printf("\nNenhum prato cadastrado.\n");
        return;
    }

    printf("\n==================================================================\n");
    printf("%-8s %-25s %-20s %-20s\n",
           "Código",
           "Nome",
           "Preço",
           "Categoria");

    printf("==================================================================\n");

    if (hojeESexta())
    {
        printf("\n*** SEXTA DO SABOR ***\n");
        printf("20%% OFF nos pratos principais!\n\n");
    }

    while (
        fscanf(
            arquivo,
            "%d;%49[^;];%f;%19[^\n]\n",
            &p.codigo,
            p.nome,
            &p.preco,
            p.categoria
        ) == 4
    )
    {
        if (hojeESexta() &&
            strcmp(p.categoria, "Prato Principal") == 0)
        {
            printf(
                "%-8d %-25s R$ %.2f -> R$ %.2f %-20s\n",
                p.codigo,
                p.nome,
                p.preco,
                calcularPreco(p),
                p.categoria
            );
        }
        else
        {
            printf(
                "%-8d %-25s R$ %.2f %-20s\n",
                p.codigo,
                p.nome,
                p.preco,
                p.categoria
            );
        }
    }

    fclose(arquivo);
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

        opcao = lerInteiro();

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
