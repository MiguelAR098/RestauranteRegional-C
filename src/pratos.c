#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "pratos.h"
#include "pedidos.h"
#include "utils.h"

//Função para Cadastrar Pratos//

void cadastrarPrato()
{
    FILE *arquivo;

    Prato p;

    printf("Codigo: ");
    scanf("%d", &p.codigo);

    // Proíbe código 0 (reservado para "não encontrado")
    if (p.codigo == 0)
    {
        printf("\nCodigo 0 invalido. Informe um codigo diferente de 0.\n");
        pausar();
        return;
    }

    limparBuffer();

    printf("Nome: ");
    scanf(" %49[^\n]", p.nome);

    printf("Preco: ");
    scanf("%f", &p.preco);

    limparBuffer();

    printf("Categoria: ");
    scanf(" %19[^\n]", p.categoria);

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

//Função para Lista de Pratos//

void listarPratos()
{
    FILE *arquivo;

    Prato p;

    arquivo = fopen("data/pratos.txt", "r");

    if (arquivo == NULL)
    {
        printf("Nenhum prato cadastrado.\n");
        return;
    }

    printf("\n===== Cardapio =====\n");

    if(hojeESexta())
{
    printf(
    "\n SEXTA DO SABOR \n"
    "20%% OFF nos Pratos Principais\n\n"
    );
}

    while (fscanf(arquivo,
                  "%d;%49[^;];%f;%19[^\n]\n",
                  &p.codigo,
                  p.nome,
                  &p.preco,
                  p.categoria) == 4)
    {
        printf("%d - %-20s R$ %.2f\n",
               p.codigo,
               p.nome,
               calcularPreco(p));
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

//Menu de pratos//

void menuPratos()
{
    int op;

    do
    {
        limparTela();

        printf("\n===== PRATOS =====\n");
        printf("1 - Cadastrar\n");
        printf("2 - Listar\n");
        printf("0 - Voltar\n");

        scanf("%d", &op);

        switch (op)
        {
            case 1:
                limparTela();
                cadastrarPrato();
                pausar();
                break;

            case 2:
                listarPratos();
                pausar();
                break;
        }

    } while (op != 0);

}
// Fun�ao Relogio para sexta//
    int hojeESexta(){
        
    time_t agora;

    time(&agora);

    struct tm *data =
        localtime(&agora);

    return data->tm_wday == 5;
    }

//Fun�ao do desconto do Relogio//

    float calcularPreco(Prato p)
{
    float preco = p.preco;

    if(
        hojeESexta()
        &&
        (
            strcmp(
                p.categoria,
                "Prato Principal"
            ) == 0
        )
    )
    {
        preco *= 0.80;
    }

    return preco;
}

