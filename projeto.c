#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void menuPrincipal();
void MenuCliente();
void MenuVenda();
void MenuProduto();

int main ()
    {
	setlocale(LC_ALL, "Portuguese");
	menuPrincipal();
	return 0;
    }

void LimpaTela()
    {
    system("cls");
    }

void menuPrincipal(){
	int opcao;
	system ("cls");
	
	printf ("--------- mercado -------- \n");
	printf ("1 - Vendas \n");
	printf ("2 - Produtos \n");
	printf ("3 - Cliente \n");
	printf ("0 - Sair \n");
	
	scanf ("%d", &opcao);
	
switch (opcao){
    case 1:
        LimpaTela();
        MenuVenda();
        break;

		case 2:
            LimpaTela();
            MenuProduto();
        break;

		case 3:
            LimpaTela();
			MenuCliente();
			break;
		case 0: 
			LimpaTela();
			printf ("------ Fechando Sistema ------- \n");
			break;
		default:
            LimpaTela();
			printf ("------ Opcão Invalida ------- \n");
			menuPrincipal();
		
	}

}
