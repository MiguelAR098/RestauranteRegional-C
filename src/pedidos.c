#include <stdio.h>
#include "pedidos.h"
#include "pratos.h"
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

    listarPratos();

    printf("\nCodigo do prato: ");
    if (scanf("%d", &codigo) != 1)
    {
        printf("\nEntrada invalida.\n");
        limparBuffer();
        pausar();
        return;
    }

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
    if (scanf("%d", &quantidade) != 1)
    {
        printf("\nEntrada invalida.\n");
        limparBuffer();
        pausar();
        return;
    }

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
        float subtotal = carrinho[i].prato.preco * carrinho[i].quantidade;

        printf("%s x%d = R$ %.2f\n",
               carrinho[i].prato.nome,
               carrinho[i].quantidade,
               subtotal);

        total += subtotal;
    }

    printf("\nTotal: R$ %.2f\n", total);
}

// Finalizar pedido
void finalizarPedido()
{
    visualizarCarrinho();
    totalItens = 0;
    printf("\nPedido finalizado!\n");
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

        if (scanf("%d", &op) != 1)
        {
            printf("\nEntrada invalida.\n");
            limparBuffer();
            pausar();
            op = -1;
            continue;
        }

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

