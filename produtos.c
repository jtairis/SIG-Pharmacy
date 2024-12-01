//Nesse arquivo estarão contidas todas as funções relacionadas ao Módulo Produtos 


#include <stdio.h>
#include <stdlib.h>
#include "valida.h"
#include <string.h>

typedef struct produto {
    char nome[51];
    char codigo[8];
    char dataValidade[11];
    char valor[12];
    char descricao[101];
} Produto;

//Funções para mostrar telas
int tela_menu_produto(void) {
    int op;
    printf("\n");
    system("clear||cls");
    printf("-------------------------------------------------------------------------- \n");
    printf("                                                                           \n");
    printf("          = = = = = Sistema de Gestão SIG-PHARMACY = = = = =               \n");
    printf("                                                                           \n");
    printf("---------------------------------------------------------------------------\n");
    printf("                                                                           \n");
    printf("                = = = = = Módulo Produtos = = = = =                        \n");
    printf("                                                                           \n");
    printf("           1. Cadastrar novo produto                                       \n");
    printf("           2. Pesquisar produto                                            \n");
    printf("           3. Atualizar produto                                            \n");
    printf("           4. Excluir produto                                              \n");
    printf("           0. Voltar ao Menu Principal                                     \n");
    printf("                                                                           \n");
    printf("           Digite o número da sua opção:                                   \n");
    scanf("%d", &op);
    printf("                                                                           \n");
    printf("---------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...");
    return op;
}

// Função para cadastrar produto
void tela_cadastrar_produto(Produto *p) {
    int valido;

    system("clear||cls");
    printf("---------------------------------------------------------------------------\n");
    printf("          = = = = Sistema de Gestão SIG-PHARMACY = = = = =               \n");
    printf("---------------------------------------------------------------------------\n");
    printf("               = = = = = Cadastrar Novo Produto = = = = =                  \n");
    printf("---------------------------------------------------------------------------\n");
    getchar();

    do {
        printf("Nome do Produto: ");
        scanf("%50[^\n]", p->nome);
        getchar();
        valido = validar_nome(p->nome);
        if (!valido) {
            printf("Nome inválido! Digite novamente.\n");
        }
    } while (!valido);

    do {
        printf("Código (7 dígitos): ");
        scanf("%7[^\n]", p->codigo);
        getchar();
        valido = validar_codigo(p->codigo);
        if (!valido) {
            printf("Código inválido! Digite novamente.\n");
        }
    } while (!valido);

    do {
        printf("Data de Validade (dd/mm/aaaa): ");
        scanf("%10[^\n]", p->dataValidade);
        getchar();
        valido = validar_data(p->dataValidade);
        if (!valido) {
            printf("Data inválida! Digite novamente.\n");
        }
    } while (!valido);

    do {
        printf("Valor (ex: 100,50): ");
        scanf("%11[^\n]", p->valor);
        getchar();
        valido = validar_valor(p->valor);
        if (!valido) {
            printf("Valor inválido! Digite novamente.\n");
        }
    } while (!valido);

    do {
        printf("Descrição do Produto: ");
        scanf("%100[^\n]", p->descricao);
        getchar();
        valido = validar_descricao(p->descricao);
        if (!valido) {
            printf("Descrição inválida! Digite novamente.\n");
        }
    } while (!valido);

    printf("\nProduto cadastrado com sucesso.\n");
    printf("---------------------------------------------------------------------------\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...");
    getchar();
}

// Função para pesquisar produto
void tela_pesquisar_produto(Produto produtos[], int qtdProdutos) {
    char codigo[8];
    int encontrado = 0;

    system("clear||cls");
    printf("---------------------------------------------------------------------------\n");
    printf("          = = = = = Sistema de Gestão SIG-PHARMACY = = = = =               \n");
    printf("---------------------------------------------------------------------------\n");
    printf("                 = = = = = Pesquisar Produto = = = = =                     \n");
    printf("---------------------------------------------------------------------------\n");

    do {
        printf("Digite o código do produto: ");
        scanf("%7s", codigo);
        getchar();
        if (!validar_codigo(codigo)) {
            printf("Código inválido! Digite novamente.\n");
        }
    } while (!validar_codigo(codigo));

    for (int i = 0; i < qtdProdutos; i++) {
        if (strcmp(produtos[i].codigo, codigo) == 0) {
            printf("\nProduto encontrado com sucesso:\n");
            printf("Nome: %s\n", produtos[i].nome);
            printf("Código: %s\n", produtos[i].codigo);
            printf("Validade: %s\n", produtos[i].dataValidade);
            printf("Valor: %s\n", produtos[i].valor);
            printf("Descrição: %s\n", produtos[i].descricao);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\nProduto com código %s não encontrado.\n", codigo);
    }

    printf("---------------------------------------------------------------------------\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...");
    getchar();
}

void tela_atualizar_produto(Produto produtos[], int qtdProdutos) {
    char codigo[8];
    int encontrado = 0;

    system("clear||cls");
    printf("\n");
    printf("---------------------------------------------------------------------------\n");
    printf("          = = = = = Sistema de Gestão SIG-PHARMACY = = = = =               \n");
    printf("---------------------------------------------------------------------------\n");
    printf("                  = = = = = Atualizar Produto = = = = =                    \n");
    printf("---------------------------------------------------------------------------\n");

    do {
        printf("Digite o código do produto para atualizar: ");
        scanf("%7s", codigo);
        getchar();
        if (!validar_codigo(codigo)) {
            printf("Código inválido! Digite novamente.\n");
        }
    } while (!validar_codigo(codigo));

    for (int i = 0; i < qtdProdutos; i++) {
        if (strcmp(produtos[i].codigo, codigo) == 0) {
            encontrado = 1;

            printf("\nProduto encontrado! Digite as novas informações:\n");

            int valido;
            do {
                printf("Nome do Produto: ");
                scanf("%50[^\n]", produtos[i].nome);
                getchar();
                valido = validar_nome(produtos[i].nome);
                if (!valido) {
                    printf("Nome inválido! Digite novamente.\n");
                }
            } while (!valido);

            do {
                printf("Data de Validade (dd/mm/aaaa): ");
                scanf("%10[^\n]", produtos[i].dataValidade);
                getchar();
                valido = validar_data(produtos[i].dataValidade);
                if (!valido) {
                    printf("Data inválida! Digite novamente.\n");
                }
            } while (!valido);

            do {
                printf("Valor (ex: 100,50): ");
                scanf("%11[^\n]", produtos[i].valor);
                getchar();
                valido = validar_valor(produtos[i].valor);
                if (!valido) {
                    printf("Valor inválido! Digite novamente.\n");
                }
            } while (!valido);

            do {
                printf("Descrição do Produto: ");
                scanf("%100[^\n]", produtos[i].descricao);
                getchar();
                valido = validar_descricao(produtos[i].descricao);
                if (!valido) {
                    printf("Descrição inválida! Digite novamente.\n");
                }
            } while (!valido);

            printf("\nProduto atualizado com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("\nProduto com código %s não encontrado.\n", codigo);
    }

    printf("---------------------------------------------------------------------------\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...");
    getchar();
}

void tela_excluir_produto(Produto produtos[], int *qtdProdutos) {
    char codigo[8];
    int encontrado = 0;

    system("clear||cls");
    printf("\n");
    printf("---------------------------------------------------------------------------\n");
    printf("          = = = = = Sistema de Gestão SIG-PHARMACY = = = = =               \n");
    printf("---------------------------------------------------------------------------\n");
    printf("                  = = = = = Excluir Produto = = = = =                      \n");
    printf("---------------------------------------------------------------------------\n");

    do {
        printf("Digite o código do produto para excluir: ");
        scanf("%7s", codigo);
        getchar();
        if (!validar_codigo(codigo)) {
            printf("Código inválido! Digite novamente.\n");
        }
    } while (!validar_codigo(codigo));

    for (int i = 0; i < *qtdProdutos; i++) {
        if (strcmp(produtos[i].codigo, codigo) == 0) {
            encontrado = 1;

            printf("\nProduto encontrado com sucesso:\n");
            printf("Nome: %s\n", produtos[i].nome);
            printf("Código: %s\n", produtos[i].codigo);
            printf("Validade: %s\n", produtos[i].dataValidade);
            printf("Valor: %s\n", produtos[i].valor);
            printf("Descrição: %s\n", produtos[i].descricao);

            char confirmacao;
            printf("\nDeseja realmente excluir este produto (S/N)? ");
            scanf(" %c", &confirmacao);
            getchar();

            if (confirmacao == 'S' || confirmacao == 's') {
                for (int j = i; j < (*qtdProdutos) - 1; j++) {
                    produtos[j] = produtos[j + 1];
                }
                (*qtdProdutos)--; 
                printf("\nProduto excluído com sucesso!\n");
            } else {
                printf("\nOperação cancelada.\n");
            }
            break;
        }
    }

    if (!encontrado) {
        printf("\nProduto com código %s não encontrado.\n", codigo);
    }


    printf("---------------------------------------------------------------------------\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...");
    getchar();
}