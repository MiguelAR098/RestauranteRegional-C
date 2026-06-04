#include <stdio.h>

//================ Funções =================//
int login(){
    int opcao;
    printf("==================================\n");
    printf("\t\tLogin\n");
    printf("==================================\n");
    printf("1 - Já sou cadastrado\n2 - Fazer o Cadastro\nEscolha: ");
    scanf("%d", &opcao);
    
    return opcao;
}

int menu_Administrador(){
    // Menu do administrador, retorna o numero escolhido das opções
    int opcao_Administrador;

    printf("==================================\n");
    printf("\t\tMenu\n");
    printf("==================================\n");
    printf("1 - Cadastro de Cliente\n2 - Cadastro de Pratos\n3 - Realizar Pedido\n4 - Relatórios\n5 - Sair\nEscolha: ");
    scanf("%d", &opcao_Administrador);

    return opcao_Administrador;
}