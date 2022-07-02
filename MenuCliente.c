#include <stdio.h>
#include <stdlib.h>
#include "projeto.h"

    typedef struct
    {
        int idade, pontos;
        int datacli;
        char nome[50], cpf[13], rua[50], bairro[50], numero[50], cidade[50], estado[2];
    } Cliente;

    Cliente clienteleitura[1000];
    Cliente *cliente;

int contcliente=1, menu3;
    FILE *arquivocliente;

int main ();

//função para atualizar cliente
void alterarCliente()
    {
    FILE *arquivo = fopen("Clientes.dat", "rb+");
    Cliente c;
    int id=0,i=1, resp=1;

    if (arquivo)
        {
        printf("\t Lista de clientes\n");
        while(fread(&c, sizeof(Cliente),1, arquivo))
            {
            printf("\t %d = %s \n", i, c.nome);
            printf("\t--------------------\n");
            i++;
            }
        printf("\t\nDigite o indice do cliente que deseja alterar os dados: \n");
        scanf("%d", &id);
        getchar();
        id--;
        do
            {
            if(id>= 0 && id < i-1)
                {
                printf("\n\tAlterar:\n");
                printf("Digite o nome novo: \n");
                scanf("%49[^\n]", &c.nome);
                getchar();

                printf("\nDigite o novo CPF: \n");
                scanf("%s", &c.cpf);
                getchar();


                printf("\nDigite o novo Endereço: \nRua:\nBairro: \nNumero: \n");
                scanf("%49[^\n] %49[^\n] %49[^\n]", &c.rua, &c.bairro, &c.numero);
                getchar();


                printf("\nDigite a nova cidade: \n");
                scanf("%49[^\n]", &c.cidade);
                getchar();

                printf("\nDigite o novo Estado: \n");
                scanf("%s", &c.estado);


                printf("\nDigite a nova idade \n:");
                scanf("%d", &c.idade);



                fseek(arquivo, sizeof(Cliente)*id, SEEK_SET);
                fwrite(&c, sizeof(Cliente), 1 , arquivo);
                }

            printf("\n=================================== \n");
            printf("   AlTERAÇÃO EFETUADA COM SUCESSO! \n");
            printf("   Alterar outro Cliente? \n\n\n 1. SIM \n 0. NAO \n");
            printf("=================================== \n");
            scanf("%d", &resp);
            fclose(arquivo);

            } while(resp!=0);

        menuPrincipal();
        }
    else
        {
        printf("Erro na abertura do arquivo");
        }
    }

//função para mostrar clientes com mais de 1000 pontos
void clienteMaior()
    {
    Cliente c;
    FILE *arquivo = fopen("Clientes.dat", "r");
    int i=1;
    if(arquivo)
        {
        while(fread(&c, sizeof(Cliente), 1, arquivo))
            {
            if (c.pontos>1000)
                {
                printf("\t------------ Clientes com mais de 1000 pontos ---------- \n\n");
                printf("%d° Cliente\nNome: %s\nCPF: %s\nPontos: %d",i,c.nome, c.cpf, c.pontos);
                printf("\n--------------------------------\n");
                i++;
                }
            }
        }
    else
        {
        printf("Erro na abertura do arquivo");
        }
    }

//função para cadastrar cliente
void cadastrarCli(Cliente *cliente)
    {
    int resp=1, i=0;
    arquivocliente = fopen("Clientes.dat","a");

    do	{
        cliente = (Cliente *)(malloc(contcliente * sizeof(Cliente)));

        printf("NOME DO Cliente: \n");
        scanf("%s", &cliente[i].nome);

        printf("CPF: \n");
        scanf("%s", &cliente[i].cpf);

        printf("Endereço (Sem espaços e Acentuação - Respectivamente)\nRua: \nBairro: \nNumero: \n");
        scanf("%s %s %s", &cliente[i].rua, &cliente[i].bairro, &cliente[i].numero);

        printf("Cidade: \n");
        scanf("%s", &cliente[i].cidade);

        printf("Estado: \n");
        scanf("%s", &cliente[i].estado);

        printf("Idade: ");
        scanf("%d", &cliente[i].idade);

        fwrite(&cliente[i], 1, sizeof(Cliente), arquivocliente);
        i++;
        contcliente++;
        printf("\n =================================== \n");
        printf("    CADASTRO EFETUADO COM SUCESSO! \n");
        printf("   CADASTRAR outro Cliente? \n\n\n 1. SIM \n 0. NAO \n");
        printf("=================================== \n");
        scanf("%d", &resp);

        system("cls");
        fclose(arquivocliente);
        menuPrincipal();

        }	while(resp!= 0);
    }

//função para mostrar clientes que possuem idade entre 18 e 15 anos
void clienteIdade(Cliente *clienteleitura)
    {
    int i=0, resp=0;
    arquivocliente = fopen ("Clientes.dat", "r");

        while (fread(&clienteleitura[i], sizeof(Cliente), 1, arquivocliente))
        {
            if (clienteleitura[i].idade >= 18 && clienteleitura[i].idade <= 25)
            {
                printf("Cliente %d°\n Nome: %s\nCpf: %s\nIdade:%d\n------------------\n", i + 1,
                       clienteleitura[i].nome, clienteleitura[i].cpf, clienteleitura[i].idade);
                i++;
            }
        }

    fclose(arquivocliente);
    printf("\n=================================== \n");
    printf(" Voltar para o menu principal? \n 1. SIM \n");
    printf("=================================== \n");
    scanf("%d", &resp);

    if(resp == 1)
        {
        system("cls");
        menuPrincipal();
        }
    }

//submenu (cliente)
void MenuCliente(){

    printf("1 - Cadastrar novo cliente \n");
    printf("2 - Atualizar pontuação \n");
    printf("3 - Atualizar cliente \n");
    printf("4 - Listar clientes entre 18 e 25 anos \n");
    printf("5 - Listar clientes com mais de 1000 pontos \n");
    printf("6 - Sair \n");
    scanf("%d", &menu3);

    switch(menu3)
    {
        case 1:
            LimpaTela();
            printf("----- Cadastro de cliente ----- \n");
            cadastrarCli(cliente);
            break;

        case 2:
            LimpaTela();
            //insira a função de atualizar pontuação
            break;

        case 3:
            LimpaTela();
            printf("----- Atualizar Cliente ----- \n");
            alterarCliente();
            break;

        case 4:
            LimpaTela();
            printf ("------  Cliente entre 18 e 25 anos------- \n");
            clienteIdade(clienteleitura);
            break;

        case 5:
            LimpaTela();
            printf("----- Clientes com mais de 1000 pontos ----- \n");
            clienteMaior();
            break;

        default:
            printf("----- Opção Inválida ----- \n");
            menuPrincipal();
            break;

    }
}