#include <stdio.h>
#include <locale.h>
#include "administradores.h"
#include "utils.h"
#include "clientes.h"
#include "pratos.h"
#include "pedidos.h"
#include "relatorios.h"

// ================= Protótipos ================= //


// Menus
int menuLogin();
int menu_Administrador();

// Fluxo do sistema
void iniciarSistema();
void realizarLogin();
void menuAdministrador();

// ================= Main ================= //

int main() {

    setlocale(LC_ALL, "");

    carregarClientes();
    iniciarSistema();

    return 0;
}

// ================= Fluxo Principal ================= //

void iniciarSistema() {

    int opcao;

    do {

        limparTela();

        opcao = menuLogin();

        switch(opcao) {

            case 1:
                realizarLogin();
                break;

            case 2:
                registrarAdministrador();
                break;

            case 3:
                printf("\nEncerrando sistema...\n");
                break;

            default:
                printf("\nOpção inválida!\n");
                pausar();
        }

    } while(opcao != 3);
}

void realizarLogin() {

    limparTela();

    if(loginAdministrador()) {

        printf("\nLogin realizado com sucesso!\n");

        pausar();

        menuAdministrador();

    } else {

        printf("\nUsuário ou senha incorretos!\n");

        pausar();
    }
}

void menuAdministrador() {

    int opcao;

    do {

        limparTela();

        opcao = menu_Administrador();

        switch(opcao) {

            case 1:

                cadastrarCliente();
                pausar();
                break;

            case 2:

                printf("\n=== Cadastro de Pratos ===\n");

                cadastrarPrato();
                pausar();
                break;

            case 3:

                printf("\n=== Realizar Pedido ===\n");

                realizarPedido();

                break;

            case 4:

                printf("\n=== Relatórios ===\n");

                gerarRelatorios();

                break;

            case 5:

                printf("\nLogout realizado!\n");

                pausar();
                limparTela();

                break;

            default:

                printf("\nOpção inválida!\n");

                pausar();
        }

    } while(opcao != 5);
}

// ================= Menus ================= //

int menuLogin() {

    int opcao;

    printf("\n==================================\n");
    printf("        SABOR NORDESTE\n");
    printf("==================================\n");

    printf("1 - Login\n");
    printf("2 - Registrar Administrador\n");
    printf("3 - Sair\n");

    printf("Escolha: ");
    opcao = lerInteiro();

    return opcao;
}

int menu_Administrador() {

    int opcao;

    printf("\n==================================\n");
    printf("            MENU\n");
    printf("==================================\n");

    printf("1 - Cadastro de Cliente\n");
    printf("2 - Cadastro de Pratos\n");
    printf("3 - Realizar Pedido\n");
    printf("4 - Relatórios\n");
    printf("5 - Logout\n");

    printf("Escolha: ");
    opcao = lerInteiro();

    return opcao;
}