#include <stdio.h>

// ================= Protótipos ================= //

// Menus
int menuLogin();
int menu_Administrador();

// Fluxo do sistema
void iniciarSistema();
void realizarLogin();
void menuAdministrador();

// Administradores
void registrarAdministrador();
int loginAdministrador();

// ================= Main ================= //

int main() {

    iniciarSistema();

    return 0;
}

// ================= Fluxo Principal ================= //

void iniciarSistema() {

    int opcao;

    do {

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
                printf("\nOpcao invalida!\n");
        }

    } while(opcao != 3);
}

void realizarLogin() {

    if(loginAdministrador()) {

        printf("\nLogin realizado com sucesso!\n");

        menuAdministrador();

    } else {

        printf("\nUsuario ou senha incorretos!\n");
    }
}

void menuAdministrador() {

    int opcao;

    do {

        opcao = menu_Administrador();

        switch(opcao) {

            case 1:

                printf("\n=== Cadastro de Cliente ===\n");

                // cadastroCliente();

                break;

            case 2:

                printf("\n=== Cadastro de Pratos ===\n");

                // cadastroPrato();

                break;

            case 3:

                printf("\n=== Realizar Pedido ===\n");

                // realizarPedido();

                break;

            case 4:

                printf("\n=== Relatorios ===\n");

                // gerarRelatorios();

                break;

            case 5:

                printf("\nLogout realizado!\n");

                break;

            default:

                printf("\nOpcao invalida!\n");
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
    scanf("%d", &opcao);

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
    printf("4 - Relatorios\n");
    printf("5 - Logout\n");

    printf("Escolha: ");
    scanf("%d", &opcao);

    return opcao;
}

// ================= Administradores ================= //
// IMPLEMENTAR EM administradores.c

void registrarAdministrador() {

    printf("\n[Funcao registrarAdministrador() ainda nao implementada]\n");
}

int loginAdministrador() {

    printf("\n[Funcao loginAdministrador() ainda nao implementada]\n");

    return 1;
}