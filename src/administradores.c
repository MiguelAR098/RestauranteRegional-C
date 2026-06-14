#include <stdio.h>
#include <string.h>
#include "administradores.h"
#include "utils.h"

void registrarAdministrador() {

    FILE *arquivo;

    char usuario[50], senha[50];

    limparTela();

    printf("\n=== Cadastro do Administrador ===\n");

    printf("Usuário: ");
    scanf("%49s", usuario);

    printf("Senha: ");
    scanf("%49s", senha);

    // Usuário deve ser único
    arquivo = fopen("data/administradores.txt", "r");
    if (arquivo != NULL)
    {
        char usuarioArquivo[50], senhaArquivo[50];
        while (fscanf(arquivo, "%49[^;];%49[^\n]\n", usuarioArquivo, senhaArquivo) == 2)
        {
            if (strcmp(usuario, usuarioArquivo) == 0)
            {
                fclose(arquivo);
                printf("\nEste usuário já existe.\n");
                limparBuffer();
                pausar();
                return;
            }
        }
        fclose(arquivo);
    }

    arquivo = fopen("data/administradores.txt", "a");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");

        limparBuffer();
        pausar();

        return;
    }

    fprintf(arquivo, "%s;%s\n", usuario, senha);

    fclose(arquivo);

    printf("\nAdministrador cadastrado com sucesso!\n");

    limparBuffer();
    pausar();
    limparTela();
}

int loginAdministrador() {

    FILE *arquivo;

    char usuarioDigitado[50], senhaDigitada[50], usuarioArquivo[50], senhaArquivo[50];

    printf("\n=== Login ===\n");

    printf("Usuário: ");
    scanf("%49s", usuarioDigitado);

    printf("Senha: ");
    scanf("%49s", senhaDigitada);

    arquivo = fopen("data/administradores.txt", "r");

    if (arquivo == NULL)
    {
        printf("Nenhum administrador cadastrado!\n");

        pausar();

        return 0;
    }

    while (fscanf(arquivo, "%49[^;];%49[^\n]\n", usuarioArquivo, senhaArquivo) == 2)
    {
        if (strcmp(usuarioDigitado, usuarioArquivo) == 0 && strcmp(senhaDigitada, senhaArquivo) == 0)
        {
            fclose(arquivo);
            return 1;
        }
    }

    fclose(arquivo);
    return 0;

}
