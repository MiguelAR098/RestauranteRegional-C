#ifndef PRATOS_H
#define PRATOS_H

typedef struct
{
    int codigo;
    char nome[50];
    float preco;
    char categoria[20];
} Prato;

void cadastrarPrato();
void listarPratos();
Prato buscarPrato(int codigo);
void menuPratos();

#endif