#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

void limparTela() {

    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

}

void limparBuffer() {

    int c;

    while ((c = getchar()) != '\n' && c != EOF);

}

void pausar() {

    char lixo[4];

    printf("\nPressione ENTER para continuar...");
    fgets(lixo, sizeof(lixo), stdin);

}

void removerNewline(char *str) {

    int tamanho = strlen(str);

    if (tamanho > 0 && str[tamanho - 1] == '\n') {

        str[tamanho - 1] = '\0';

    }

}

void lerTexto(char *texto, int tamanho) {

    fgets(texto, tamanho, stdin);
    removerNewline(texto);

}

int lerInteiro() {

    char entrada[50];
    int valor;

    while (1) {

        fgets(entrada, sizeof(entrada), stdin);

        if (sscanf(entrada, "%d", &valor) == 1) {
            return valor;
        }

        printf("Digite um número válido: ");
    }
}

float lerFloat() {

    char entrada[50];

    fgets(entrada, sizeof(entrada), stdin);

    return atof(entrada);
}