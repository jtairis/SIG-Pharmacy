//Nesse arquivo estarão contidas todas as funções relacionadas ao Módulo Produtos 


#include <stdio.h>
#include <stdlib.h>
#include "valida.h"

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
void tela_cadastrar_produto(void) {
    char nome[30];
    char codigo[8];
    char data[11];
    char valor[8];
    char descricao[30];

    system("clear||cls");
    printf("---------------------------------------------------------------------------\n");
    printf("          = = = = Sistema de Gestão SIG-PHARMACY = = = = =               \n");
    printf("---------------------------------------------------------------------------\n");
    printf("               = = = = = Cadastrar Novo Produto = = = = =                  \n");
    printf("---------------------------------------------------------------------------\n");
    getchar();

    do {
        printf("Nome do produto: ");
        scanf("%29[^\n]", nome);
        getchar();
        if (!validar_nome(nome)) {
            printf("Nome inválido! Digite novamente.\n");
        }
    } while (!validar_nome(nome));

    do {
        printf("Código: ");
        scanf("%7s", codigo);
        getchar();  // Limpa o buffer
        if (!validar_codigo(codigo)) {
            printf("Código inválido! Digite um código com 7 dígitos numéricos.\n");
        }
    } while (!validar_codigo(codigo));

    do {
        printf("Data de validade (dd/mm/aaaa): ");
        scanf("%10s", data);
        getchar();  // Limpa o buffer
        if (!validar_data(data)) {
            printf("Data inválida! Digite no formato dd/mm/aaaa.\n");
        }
    } while (!validar_data(data));

    do {
        printf("Valor: ");
        scanf("%7s", valor);
        getchar();  // Limpa o buffer
        if (!validar_valor(valor)) {
            printf("Valor inválido! Digite um valor numérico com até 7 caracteres,com ou sem , \n");
        }
    } while (!validar_valor(valor));

    do {
        printf("Descrição: ");
        scanf("%29[^\n]", descricao);
        getchar();  // Limpa o buffer
        if (!validar_descricao(descricao)) {
            printf("Descrição inválida! Digite uma descrição válida.\n");
        }
    } while (!validar_descricao(descricao));

    printf("\nProduto cadastrado com sucesso.\n");
    printf("---------------------------------------------------------------------------\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...");
    getchar();
}

// Função para pesquisar produto
void tela_pesquisar_produto(void) {
    char codigo[8];

    system("clear||cls");
    printf("---------------------------------------------------------------------------\n");
    printf("          = = = = = Sistema de Gestão SIG-PHARMACY = = = = =               \n");
    printf("---------------------------------------------------------------------------\n");
    printf("                 = = = = = Pesquisar Produto = = = = =                     \n");
    printf("---------------------------------------------------------------------------\n");

    do {
        printf("       Digite o código do produto para pesquisar: ");
        scanf("%7s", codigo);
        getchar();  // Limpa o buffer
        if (!validar_codigo(codigo)) {
            printf("Código inválido! Digite um código com 7 dígitos numéricos.\n");
        }
    } while (!validar_codigo(codigo));

    printf("---------------------------------------------------------------------------\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...");
    getchar();
}

void tela_atualizar_produto(void) {
    char codigo[8];

    system("clear||cls");
    printf("\n");
    printf("---------------------------------------------------------------------------\n");
    printf("          = = = = = Sistema de Gestão SIG-PHARMACY = = = = =               \n");
    printf("---------------------------------------------------------------------------\n");
    printf("                  = = = = = Atualizar Produto = = = = =                    \n");
    printf("---------------------------------------------------------------------------\n");

    do {
        printf("          Digite o código para atualizar o produto: ");
        scanf("%7s", codigo);
        getchar();  // Limpa o buffer
        if (!validar_codigo(codigo)) {
            printf("Código inválido! Digite um código com 7 dígitos numéricos.\n");
        }
    } while (!validar_codigo(codigo));

    printf("---------------------------------------------------------------------------\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...");
    getchar();
}

void tela_excluir_produto(void) {
    char codigo [8];
    
    system("clear||cls");
    printf("\n");
    printf("---------------------------------------------------------------------------\n");
    printf("                                                                           \n");
    printf("          = = = = = Sistema de Gestão SIG-PHARMACY = = = = =             \n");
    printf("                                                                           \n");
    printf("---------------------------------------------------------------------------\n");
    printf("                                                                           \n");
    printf("                  = = = = = Excluir Produto = = = = =                      \n");
    printf("                                                                           \n");
    getchar();
    printf("            Digite o código para excluir o produto: ");
    scanf("%s 7[0-9]", codigo);
    getchar();
    printf("                                                                           \n");
    printf("---------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...");
    getchar();
}