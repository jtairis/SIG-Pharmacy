#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "produtos.h"
#include "clientes.h"
#include "vendas.h"
#include "informacoes.h"
#include "relatorios.h"
#include "valida.h"

void modulorelatorio(void) {
    int opcao;
    do {
        opcao = tela_menu_relatorio();  // Função que exibe o menu e retorna a escolha
        switch(opcao) {
            case 1:
                tela_relatorios_produtos();
                break;
            case 2:
                tela_relatorios_clientes();
                break;
            case 3:
                tela_relatorios_vendas();
                break;
            case 0:
                printf("Retornando ao menu principal...\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
                getchar();  // Pausa para o usuário ler a mensagem
                break;
        }
    } while (opcao != 0);
}

//Funções de telas
int tela_menu_relatorio(void) {
    int op;
    printf("\n");
    printf("-------------------------------------------------------------------------- \n");
    printf("          - - - - - Sistema de Gestão SIG-PHARMACY - - - - -               \n");
    printf("---------------------------------------------------------------------------\n");
    printf("                 - - - - - Módulo Relatório - - - - -                      \n");
    printf("                                                                           \n");
    printf("           1. Relatório de Produtos                                        \n");
    printf("           2. Relatório de Clientes                                        \n");
    printf("           3. Relatório de Vendas                                          \n");
    printf("           0. Voltar ao Menu Principal                                     \n");
    printf("                                                                           \n");
    printf("           Digite o número da sua opção:                                   \n");
    scanf("%d", &op);
    printf("                                                                           \n");
    printf("---------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...");
    getchar();
    return op;
}

void tela_relatorios_produtos(void) {
    int opcao;
    do {
        system("clear||cls");
        printf("\n");
        printf("-------------------------------------------------------------------------- \n");
        printf("          - - - - - Sistema de Gestão SIG-PHARMACY - - - - -               \n");
        printf("---------------------------------------------------------------------------\n");
        printf("                 - - - - - Relatórios de Produtos - - - - -                \n");
        printf("---------------------------------------------------------------------------\n");
        printf("           1. Relatório Geral de Produtos                                  \n");
        printf("           2. Relatório de Produtos por Faixa de Preço                     \n");
        printf("           0. Voltar ao Menu de Relatórios                                 \n");
        printf("---------------------------------------------------------------------------\n");
        printf("           Digite o número da sua opção:                                   \n");
        scanf("%d", &opcao);
        getchar();
        switch(opcao) {
            case 1:
                relatorioGeralProdutos();
                break;
            case 2:
                relatorioProdutosPorFaixaPreco();
                break;
            case 0:
                printf("\nVoltando ao menu de relatórios...\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
                break;
        }
    } while (opcao != 0);
}

// Função para gerar o relatório geral de produtos
void relatorioGeralProdutos(void) {
    FILE *fp = fopen("Produto.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo de produtos!\n");
        return;
    }

    Produto prod;
    printf("\n----------------------------------------------------\n");
    printf("               Relatório Geral de Produtos           \n");
    printf("----------------------------------------------------\n");
    while (fread(&prod, sizeof(Produto), 1, fp)) {
        if (prod.status == 1) {
            printf("Código: %s\n", prod.codigo);
            printf("Nome: %s\n", prod.nome);
            printf("Valor: %.2f\n", prod.valor);
            printf("Data de validade: %s\n", prod.data);
            printf("Descrição: %s\n", prod.descricao);
            printf("----------------------------------------------------\n");
        }
    }
    fclose(fp);
    printf("\nPressione <ENTER> para continuar...");
    getchar();
}

// Função para gerar o relatório de produtos por faixa de preço
void relatorioProdutosPorFaixaPreco(void) {
    float valorMin, valorMax;
    printf("Informe o valor mínimo: ");
    scanf("%f", &valorMin);
    printf("Informe o valor máximo: ");
    scanf("%f", &valorMax);

    // Verifica se o valor mínimo é maior que o valor máximo
    if (valorMin > valorMax) {
        printf("Erro: O valor mínimo não pode ser maior que o valor máximo.\n");
        return;
    }

    FILE *fp = fopen("Produto.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo de produtos!\n");
        return;
    }

    Produto prod;
    int produtosEncontrados = 0;  // Variável para verificar se encontramos produtos que atendem ao critério

    printf("\n----------------------------------------------------\n");
    printf("   Relatório de Produtos na Faixa de Preço R$ %.2f - %.2f\n", valorMin, valorMax);
    printf("----------------------------------------------------\n");

    while (fread(&prod, sizeof(Produto), 1, fp)) {
        
        if (prod.status == 1 && prod.valor >= valorMin && prod.valor <= valorMax) {
            printf("Código: %s\n", prod.codigo);
            printf("Nome: %s\n", prod.nome);
            printf("Valor: %.2f\n", prod.valor);
            printf("Data de validade: %s\n", prod.data);
            printf("Descrição: %s\n", prod.descricao);
            printf("----------------------------------------------------\n");
            produtosEncontrados = 1;
        }
    }

    if (!produtosEncontrados) {
        printf("Nenhum produto encontrado dentro da faixa de preço informada.\n");
    }
    getchar();
    fclose(fp);
    printf("\nPressione <ENTER> para continuar...");
    getchar();
}



void tela_relatorios_clientes(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------- \n");
    printf("          - - - - - Sistema de Gestão SIG-PHARMACY - - - - -               \n");
    printf("---------------------------------------------------------------------------\n");
    printf("                 - - - - - Relatórios de Clientes - - - - -                \n");
    getchar();
    printf("---------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...");
    getchar();
}

void tela_relatorios_vendas(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------- \n");
    printf("          - - - - - Sistema de Gestão SIG-PHARMACY - - - - -               \n");
    printf("---------------------------------------------------------------------------\n");
    printf("                 - - - - - Relatórios de Vendas - - - - -                  \n");
    getchar();
    printf("---------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...");
    getchar();
}
