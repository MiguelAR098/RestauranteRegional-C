#include <stdio.h>
#include <stdlib.h>
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

    limparBuffer();

    printf("\nPressione ENTER para continuar...");

    getchar();

}