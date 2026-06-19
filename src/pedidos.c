#include <stdio.h>
#include "pedidos.h"
#include "pratos.h"
#include "clientes.h"
#include "utils.h"

ItemPedido carrinho[100];
int totalItens = 0;

// Adicionar ao carrinho
void adicionarAoCarrinho()
{
    int codigo;
    int quantidade;

    if (totalItens >= 100)
    {
        printf("\nCarrinho cheio! Nao e possivel adicionar mais itens.\n");
        pausar();
        return;
    }

    exibirCardapio();

    printf("\nCodigo do prato: ");
    codigo = lerInteiro();

    Prato pratoEscolhido = buscarPrato(codigo);

    // buscarPrato retorna um Prato vazio com codigo == 0 quando não encontra.
    // Como o cadastro proíbe código 0, isso passa a ser confiável.
    if (pratoEscolhido.codigo == 0)
    {
        printf("\nPrato nao encontrado!\n");
        pausar();
        return;
    }

    printf("Quantidade: ");
    quantidade = lerInteiro();

    if (quantidade < 1)
    {
        printf("\nQuantidade invalida. Informe um valor >= 1.\n");
        pausar();
        return;
    }

    carrinho[totalItens].prato = pratoEscolhido;
    carrinho[totalItens].quantidade = quantidade;
    totalItens++;
}

// Visualizar Carrinho
void visualizarCarrinho()
{
    float total = 0.0f;

    printf("\n====== Carrinho ======\n");

    if (totalItens == 0)
    {
        printf("Carrinho vazio.\n");
        printf("\nTotal: R$ %.2f\n", total);
        return;
    }

    for (int i = 0; i < totalItens; i++)
    {
        float subtotal = calcularPreco(carrinho[i].prato) * carrinho[i].quantidade;

        printf("%s x%d = R$ %.2f\n",
               carrinho[i].prato.nome,
               carrinho[i].quantidade,
               subtotal);

        total += subtotal;
    }

    printf("\nTotal: R$ %.2f\n", total);
}

// Finalizar pedido (persiste em data/pedidos.txt)
void finalizarPedido()
{
    if (totalItens == 0)
    {
        printf("\nCarrinho vazio! Nada para finalizar.\n");
        pausar();
        return;
    }

    // Mostra carrinho e calcula total
    visualizarCarrinho();

    // Recalcula total (porque visualizarCarrinho só imprime)
    float total = 0.0f;
    for (int i = 0; i < totalItens; i++)
    {
        total += calcularPreco(carrinho[i].prato) * carrinho[i].quantidade;
    }

    int idCliente;
    printf("\nInforme o ID do cliente: ");
    idCliente = lerInteiro();

    Cliente clienteSelecionado;
    if (!buscarClientePorId(idCliente, &clienteSelecionado))
    {
        printf("\nCliente não encontrado para o ID informado!\n");
        pausar();
        return;
    }

    // Gera IDPedido incremental
    int novoIdPedido = 1;
    FILE *fp = fopen("data/pedidos.txt", "r");
    if (fp != NULL)
    {
        int idPedidoArquivo;
        int idClienteArquivo;
        float valorTotalArquivo;

        while (fscanf(fp, "%d;%d;%f\n", &idPedidoArquivo, &idClienteArquivo, &valorTotalArquivo) == 3)
        {
            novoIdPedido = idPedidoArquivo + 1;
        }
        fclose(fp);
    }

    fp = fopen("data/pedidos.txt", "a");
    if (fp == NULL)
    {
        printf("\nErro ao abrir o arquivo de pedidos para salvar.\n");
        pausar();
        return;
    }

    fprintf(fp, "%d;%d;%.2f\n", novoIdPedido, idCliente, total);
    fclose(fp);

    totalItens = 0;
    printf("\nPedido finalizado e salvo com sucesso!\n");
    pausar();
}

// Realizar Pedido
void realizarPedido()
{
    int op;

    do
    {
        limparTela();

        printf("\n===== Pedidos =====\n");
        printf("1 - Adicionar Item\n");
        printf("2 - Ver Carrinho\n");
        printf("3 - Finalizar Pedido\n");
        printf("0 - Voltar\n");
        printf("Escolha: ");

        op = lerInteiro();

        switch (op)
        {
        case 1:
            adicionarAoCarrinho();
            break;
        case 2:
            visualizarCarrinho();
            pausar();
            break;
        case 3:
            finalizarPedido();
            break;
        case 0:
            break;
        default:
            printf("\nOpção invalida!\n");
            pausar();
            break;
        }

    } while (op != 0);
}
