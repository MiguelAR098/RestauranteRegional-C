#include <stdio.h>
#include <stdlib.h>
#include "pratos.h"
#include "pedidos.h"
#include "utils.h"

//Função para Cadastrar Pratos//

void cadastrarPrato()
{

    limparTela();

    FILE *arquivo;

    Prato p;

    printf("Codigo: ");
    p.codigo = lerInteiro();

    // Proíbe código 0 (reservado para "não encontrado")
    if (p.codigo == 0)
    {
        printf("\nCódigo 0 é inválido. Informe um código diferente de 0.\n");
        pausar();
        return;
    }

    printf("Nome: ");
    lerTexto(p.nome, sizeof(p.nome));

    printf("Preco: ");
    p.preco = lerFloat();

    printf("Categoria: ");
    lerTexto(p.categoria, sizeof(p.categoria));

    // Impede cadastro duplicado pelo código
    arquivo = fopen("data/pratos.txt", "r");
    if (arquivo != NULL)
    {
        Prato temp;
        while (fscanf(arquivo,
                      "%d;%49[^;];%f;%19[^\n]\n",
                      &temp.codigo,
                      temp.nome,
                      &temp.preco,
                      temp.categoria) == 4)
        {
            if (temp.codigo == p.codigo)
            {
                fclose(arquivo);
                printf("\nJá existe um prato com este código.\n");
                pausar();
                return;
            }
        }
        fclose(arquivo);
    }

    arquivo = fopen("data/pratos.txt", "a");

    if (arquivo == NULL)
    {
        printf("\nErro ao abrir o arquivo de pratos!\n");
        pausar();
        return;
    }

    fprintf(arquivo,
            "%d;%s;%.2f;%s\n",
            p.codigo,
            p.nome,
            p.preco,
            p.categoria);

    fclose(arquivo);

    printf("\nPrato cadastrado!\n");
}

//Função para Exibir Cardápio//

void exibirCardapio()
{
    FILE *arquivo;
    Prato p;

    arquivo = fopen("data/pratos.txt", "r");

    if (arquivo == NULL)
    {
        printf("\nNenhum prato cadastrado.\n");
        return;
    }

    printf("\n===== CARDÁPIO =====\n");

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
        printf(
            "%d - %-20s R$ %.2f\n",
            p.codigo,
            p.nome,
            p.preco
        );
    }

    fclose(arquivo);
}

//Função para Buscar Pratos//

Prato buscarPrato(int codigo)
{
    FILE *arquivo;

    Prato p;
    Prato vazio = {0};

    arquivo = fopen("data/pratos.txt", "r");

    if (arquivo == NULL)
        return vazio;

    while (fscanf(arquivo,
                  "%d;%49[^;];%f;%19[^\n]\n",
                  &p.codigo,
                  p.nome,
                  &p.preco,
                  p.categoria) == 4)
    {
        if (p.codigo == codigo)
        {
            fclose(arquivo);
            return p;
        }
    }

    fclose(arquivo);

    return vazio;
}
