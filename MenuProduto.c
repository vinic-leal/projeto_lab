#include <stdio.h>
#include <stdlib.h>
#include "MenuProduto.h"
#include "projeto.h"

    typedef struct
    {
        int idProduto, qntdEs, dataval;
        char nome[50], setor[20];
        double preco;
    } Produto;

    Produto *produto;
    Produto produtoleitura[1000];
    FILE *arquivoprod;
    int printarproduto=0, contproduto=1, menu2;

void alterarProduto()
    {
    FILE *arquivo = fopen("Produto.dat", "rb+");
    Produto p;
    int id=0,i=1, resp=1;

    if (arquivo)
        {
        printf("\t Lista de Produtos\n");
        while(fread(&p, sizeof(Produto),1, arquivo))
            {
            printf("\t %d = %s \n", i, p.nome);
            printf("\t--------------------\n");
            i++;
            }

        printf("\t\nDigite o indice do produto que deseja alterar os dados: \n");
        scanf("%d", &id);
        getchar();
        id--;
        do
            {
            if(id>= 0 && id < i-1)
                {
                printf("\n\tAlterar:\n");
                printf("Digite o nome novo: \n");
                scanf("%49[^\n]", &p.nome);
                getchar();

                printf("\nDigite a nova identificação: \n");
                scanf("%d", &p.idProduto);
                getchar();


                printf("\nDigite o novo preço: \n");
                scanf("%ld", &p.preco);
                getchar();


                printf("\nDigite a nova data de validade: (ddmmaaaa) \n");
                scanf("%d", &p.dataval);
                getchar();

                printf("\nDigite o novo setor: \n");
                scanf("%49[^\n]", &p.setor);
                getchar();


                fseek(arquivo, sizeof(Produto)*id, SEEK_SET);
                fwrite(&p, sizeof(Produto), 1 , arquivo);
                }

            printf("\n=================================== \n");
            printf("   AlTERAÇÃO EFETUADA COM SUCESSO! \n");
            printf("   Alterar outro produto? \n\n\n 1. SIM \n 0. NAO \n");
            printf("=================================== \n");
            scanf("%d", &resp);
            fclose(arquivo);

            }while(resp!=0);

        menuPrincipal();

        }
    else
        {
        printf("Erro na abertura do arquivo");
        }
    }

//função para cadastrar produto
void cadastrarProd(Produto *produto)
    {

    int resp=1, i=0;
    arquivoprod = fopen("Produto.dat","a");

    do
        {
        produto = (Produto *)(malloc(contproduto * sizeof(Produto)));
        printf("NOME DO PRODUTO: \n");
        scanf("%s", &produto[i].nome);

        printf("Identificação do Produto: \n");
        scanf("%d", &produto[i].idProduto);

        printf("PRECO DO PRODUTO: \n");
        scanf("%ld", &produto[i].preco);

        printf("QUANTIDADE DO PRODUTO: \n");
        scanf("%d", &produto[i].qntdEs);

        printf("Data de Validade: \n");
        scanf("%d", &produto[i].dataval);

        printf("Setor: ");
        scanf("%s", &produto[i].setor);

        fwrite(&produto[i], 1, sizeof(Produto), arquivoprod);
        contproduto++;
        i++;
        printarproduto++;
        printf("\n =================================== \n");
        printf("    CADASTRO EFETUADO COM SUCESSO! \n");
        printf("   CADASTRAR NOVO PRODUTO? \n\n\n 1. SIM \n 0. NAO \n");
        printf("=================================== \n");
        scanf("%d", &resp);

        system("cls");
        fclose(arquivoprod);
        menuPrincipal();

        }	while(resp!= 0);

    }

//função para exibir produtos com qtd em estoque < 5 unidades
void produtoM5(Produto *produtoleitura)
    {
    arquivoprod = fopen ("Produto.dat", "r");
    int i=0, resp=0;

        while (fread(&produtoleitura[i], sizeof(Produto), 1, arquivoprod))
            {
            if (produtoleitura[i].qntdEs < 5)
                {
                printf("------ Produto com estoque baixo ------\n\nNome: %s\nIdentificação do Produto: %d\nQuantidade em estoque:%d\n------------------\n",
                       produtoleitura[i].nome, produtoleitura[i].idProduto, produtoleitura[i].qntdEs);
                i++;
                }
             }

    printf("\n=================================== \n");
    printf(" Voltar para o menu principal? \n 1. SIM \n");
    printf("=================================== \n");
    scanf("%d", &resp);

    if(resp == 1)
        {
        system("cls");
        menuPrincipal();
        }

     fclose(arquivoprod);
    }

//submenu (produto)
void MenuProduto ()
    {
    LimpaTela();
    printf("1 - Cadastrar novo produto \n");
    printf("2 - Atualizar informações \n");
    printf("3 - Estoque por setor \n");
    printf("4 - Produtos com baixa quantidade em estoque \n");
    printf ("5 - Sair \n");
    scanf("%d", &menu2);

    switch (menu2)
        {
        case 1:
            LimpaTela();
            printf("------ Cadastrar Produto ------- \n");
            cadastrarProd(produto);
            break;

        case 2:
            LimpaTela();
            printf("----- Atualizar informacoes----- \n");
            alterarProduto();
            break;

        case 3:
            LimpaTela();
            printf("----- Estoque por Setor ----- \n");
            //insira a função consulta de estoque aqui
            break;

        case 4:
            LimpaTela();
            printf("----- Produtos com baixa quantidade em estoque ----- \n");
            produtoM5(produtoleitura);
            break;

        case 5:
            LimpaTela();
            printf("----- Fechando o sistema ----- \n");
            break;

        default:
            LimpaTela();
            printf("----- Opção Inválida ----- \n");
            menuPrincipal();
            break;
        }

    }