#include <stdio.h>
#include "pedidos.h"
#include "pratos.h"
#include "utils.h"

ItemPedido carrinho[100];
int totalItens = 0;

//Adicionar ao carrinho//

void adicionarAoCarrinho()
{
    int codigo;
    int quantidade;

    listarPratos();

    printf("\nCodigo do prato: ");
    scanf("%d", &codigo);

    Prato pratoEscolhido = buscarPrato(codigo);

    if(pratoEscolhido.codigo ==0)
    {
        printf("\nPrato nao encontrado!\n");
        return;
    }

    printf("Quantidade: ");
    scanf("%d", &quantidade);

    carrinho[totalItens].prato = pratoEscolhido;
    carrinho[totalItens].quantidade = quantidade;

    totalItens++;
}

//Visualizar Carrinho giv up//

void visualizarCarrinho()
{
    float total = 0;

    printf("\n====== Carrinho ======\n");

    for(int i = 0; i < totalItens; i++)
    {
        float subtotal =
        carrinho[i].prato.preco *
        carrinho[i].quantidade;

        printf("%s x%d = R$ %.2f\n",
        carrinho[i].prato.nome,
        carrinho[i].quantidade,
        subtotal);

        total += subtotal;
    }
    printf("\nTotal: R$ %.2f\n", total);
}

//Finalizar pedido estoy harto//

void finalizarPedido()
{
    visualizarCarrinho();

    totalItens = 0;

    printf("\nPedido finalizado!\n");
}

//Realizar Pedido oi to hysteria//

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

        scanf("%d", &op);

        switch (op)
        {
        case 1:
            adicionarAoCarrinho();
            break;
        case 2:
            visualizarCarrinho();
            break;

            case 3:
            finalizarPedido();
            break;

        default:
            printf("\nOpção invalida!\n");
            pausar();
            
        }
    } while(op != 0);
}