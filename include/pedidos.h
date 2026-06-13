#ifndef PEDIDOS_H
#define PEDIDOS_H

#include "pratos.h"

typedef struct
{
    Prato prato;
    int quantidade;
} ItemPedido;

void realizarPedido();
void adicionarAoCarrinho();
void visualizarCarrinho();
void finalizarPedido();

#endif