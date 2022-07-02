#include "MenuVenda.h"
#include "projeto.h"
#include <stdio.h>

int menu1;

//ainda não existem funções aqui :(

void MenuVenda () {
    LimpaTela();
    printf("1 - Nova Venda \n");
    printf("2 - Listar Venda do Cliente \n");
    printf("3 - Sair \n");
    scanf("%d", menu1);

    switch(menu1) {
        case 1:
            printf("----- Cadastrar nova venda ----- \n");
            //insira a função de cadastrar venda aqui
            break;

        case 2:
            printf("----- Venda do cliente ----- \n");
            //insira a função aqui
            break;

        case 3:
            printf("----- Fechando o sistema ------ \n");
            break;

        default:
            printf("----- Opção Inválida ----- \n");
            menuPrincipal();
            break;
    }
}