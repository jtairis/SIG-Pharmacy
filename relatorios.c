#include <stdio.h>
#include <string.h>
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
        opcao = tela_menu_relatorio();
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
                getchar();
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
        printf("           3. Relatório de Produtos por Data de Validade                   \n");
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
            case 3:
                relatorioProdutosPorDataValidade();
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
    int produtosEncontrados = 0;

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

void relatorioProdutosPorDataValidade(void) {
    char dataValidade[11];
    printf("Informe a data de validade (formato DD/MM/AAAA): ");
    scanf("%s", dataValidade);

    FILE *fp = fopen("Produto.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo de produtos!\n");
        return;
    }

    Produto prod;
    int produtosEncontrados = 0;

    printf("\n----------------------------------------------------\n");
    printf("   Relatório de Produtos com Data de Validade: %s\n", dataValidade);
    printf("----------------------------------------------------\n");

    while (fread(&prod, sizeof(Produto), 1, fp)) {
        if (prod.status == 1 && strcmp(prod.data, dataValidade) == 0) {
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
        printf("Nenhum produto encontrado com a data de validade informada.\n");
    }

    fclose(fp);
    printf("\nPressione <ENTER> para continuar...");
    getchar();
    getchar();
}



void tela_relatorios_clientes(void) {
    int opcao;
    do {
        system("clear||cls");
        printf("\n");
        printf("-------------------------------------------------------------------------- \n");
        printf("          - - - - - Sistema de Gestão SIG-PHARMACY - - - - -               \n");
        printf("---------------------------------------------------------------------------\n");
        printf("                 - - - - - Relatórios de Clientes - - - - -                \n");
        printf("---------------------------------------------------------------------------\n");
        printf("           1. Relatório Geral de Clientes Ativos                           \n");
        printf("           2. Relatório de Clientes por Data de Nascimento                 \n");
        printf("           0. Voltar ao Menu de Relatórios                                 \n");
        printf("---------------------------------------------------------------------------\n");
        printf("           Digite o número da sua opção:                                   \n");
        scanf("%d", &opcao);
        getchar();

        switch(opcao) {
            case 1:
                relatorioGeralClientes();
                break;
            case 2:
                relatorioClientesPorData();
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

void relatorioGeralClientes(void) {
    FILE* fp = fopen("Cliente.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo de clientes!\n");
        return;
    }

    Cliente cli;
    int clientesEncontrados = 0;

    printf("\n----------------------------------------------------\n");
    printf("             Relatório Geral de Clientes             \n");
    printf("----------------------------------------------------\n");

    while (fread(&cli, sizeof(Cliente), 1, fp)) {
        if (cli.status == 1) {
            printf("CPF: %s\n", cli.cpf);
            printf("Nome: %s\n", cli.nome);
            printf("Telefone: %s\n", cli.tele);
            printf("E-mail: %s\n", cli.email);
            printf("Data de Nascimento: %s\n", cli.data);
            printf("----------------------------------------------------\n");
            clientesEncontrados = 1;
        }
    }

    if (!clientesEncontrados) {
        printf("Nenhum cliente ativo encontrado.\n");
    }

    fclose(fp);
    printf("\nPressione <ENTER> para continuar...");
    getchar();
}

void relatorioClientesPorData(void) {
    FILE* fp = fopen("Cliente.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo de clientes!\n");
        return;
    }

    char dataDesejada[11];
    printf("Informe a data de nascimento desejada (dd/mm/aaaa): ");
    scanf("%10[^\n]", dataDesejada);
    getchar();

    Cliente cli;
    int clientesEncontrados = 0;

    printf("\n----------------------------------------------------\n");
    printf("      Relatório de Clientes por Data de Nascimento   \n");
    printf("----------------------------------------------------\n");

    while (fread(&cli, sizeof(Cliente), 1, fp)) {
        if (cli.status == 1 && strcmp(cli.data, dataDesejada) == 0) {
            printf("CPF: %s\n", cli.cpf);
            printf("Nome: %s\n", cli.nome);
            printf("Telefone: %s\n", cli.tele);
            printf("E-mail: %s\n", cli.email);
            printf("Data de Nascimento: %s\n", cli.data);
            printf("----------------------------------------------------\n");
            clientesEncontrados = 1;
        }
    }

    if (!clientesEncontrados) {
        printf("Nenhum cliente encontrado com a data de nascimento %s.\n", dataDesejada);
    }

    fclose(fp);
    printf("\nPressione <ENTER> para continuar...");
    getchar();
}


void tela_relatorios_vendas(void) {
    int opcao;
    do {
        system("clear||cls");
        printf("\n");
        printf("-------------------------------------------------------------------------- \n");
        printf("          - - - - - Sistema de Gestão SIG-PHARMACY - - - - -               \n");
        printf("---------------------------------------------------------------------------\n");
        printf("                 - - - - - Relatórios de Vendas - - - - -                  \n");
        printf("---------------------------------------------------------------------------\n");
        printf("           1. Relatório Geral de Vendas                                    \n");
        printf("           2. Relatório de Vendas por Cliente (CPF)                        \n");
        printf("           3. Relatório de Vendas por Data                                 \n");
        printf("           0. Voltar ao Menu de Relatórios                                 \n");
        printf("---------------------------------------------------------------------------\n");
        printf("           Digite o número da sua opção:                                   \n");
        scanf("%d", &opcao);
        getchar();

        switch(opcao) {
            case 1:
                relatorioGeralVendas();
                break;
            case 2:
                relatorioVendasPorCliente();
                break;
            case 3:
                relatorioVendasPorData();
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

void relatorioGeralVendas(void) {
    FILE *fpVendas = fopen("vendas.dat", "rb");
    FILE *fpClientes = fopen("Cliente.dat", "rb");
    FILE *fpProdutos = fopen("Produto.dat", "rb");

    if (fpVendas == NULL || fpClientes == NULL || fpProdutos == NULL) {
        printf("Erro ao abrir os arquivos!\n");
        return;
    }

    Venda venda;
    Cliente cli;
    Produto prod;

    printf("\n----------------------------------------------------\n");
    printf("               Relatório Geral de Vendas            \n");
    printf("----------------------------------------------------\n");

    while (fread(&venda, sizeof(Venda), 1, fpVendas)) {
        if (venda.status == 1) {
            fseek(fpClientes, 0, SEEK_SET);
            while (fread(&cli, sizeof(Cliente), 1, fpClientes)) {
                if (cli.status == 1 && strcmp(cli.cpf, venda.cpfCliente) == 0) {
                    break;
                }
            }

            fseek(fpProdutos, 0, SEEK_SET);
            while (fread(&prod, sizeof(Produto), 1, fpProdutos)) {
                if (prod.status == 1 && strcmp(prod.codigo, venda.codigo) == 0) {
                    break;
                }
            }

            printf("Número da Venda: %d\n", venda.numeroVenda);
            printf("Cliente: %s\n", cli.nome);
            printf("Produto: %s\n", prod.nome);
            printf("Quantidade: %d\n", venda.quantidade);
            printf("Valor Total: %.2f\n", venda.valorTotal);
            printf("Data: %s\n", venda.data);
            printf("----------------------------------------------------\n");
        }
    }

    fclose(fpVendas);
    fclose(fpClientes);
    fclose(fpProdutos);
    printf("\nPressione <ENTER> para continuar...");
    getchar();
}


void relatorioVendasPorCliente(void) {
    char cpf[12];
    printf("Informe o CPF do cliente (somente números): ");
    scanf("%11s", cpf);
    getchar();

    FILE *fpVendas = fopen("vendas.dat", "rb");
    FILE *fpClientes = fopen("Cliente.dat", "rb");
    FILE *fpProdutos = fopen("Produto.dat", "rb");

    if (fpVendas == NULL || fpClientes == NULL || fpProdutos == NULL) {
        printf("Erro ao abrir os arquivos!\n");
        return;
    }

    Venda venda;
    Cliente cli;
    Produto prod;
    int vendasEncontradas = 0;

    printf("\n----------------------------------------------------\n");
    printf("               Relatório de Vendas por Cliente       \n");
    printf("----------------------------------------------------\n");

    while (fread(&venda, sizeof(Venda), 1, fpVendas)) {
        if (venda.status == 1 && strcmp(venda.cpfCliente, cpf) == 0) {
            fseek(fpClientes, 0, SEEK_SET);
            while (fread(&cli, sizeof(Cliente), 1, fpClientes)) {
                if (cli.status == 1 && strcmp(cli.cpf, venda.cpfCliente) == 0) {
                    break;
                }
            }

            fseek(fpProdutos, 0, SEEK_SET);
            while (fread(&prod, sizeof(Produto), 1, fpProdutos)) {
                if (prod.status == 1 && strcmp(prod.codigo, venda.codigo) == 0) {
                    break;
                }
            }

            printf("Número da Venda: %d\n", venda.numeroVenda);
            printf("Cliente: %s\n", cli.nome);
            printf("Produto: %s\n", prod.nome);
            printf("Quantidade: %d\n", venda.quantidade);
            printf("Valor Total: %.2f\n", venda.valorTotal);
            printf("Data: %s\n", venda.data);
            printf("----------------------------------------------------\n");
            vendasEncontradas = 1;
        }
    }

    if (!vendasEncontradas) {
        printf("Nenhuma venda encontrada para o CPF informado.\n");
    }

    fclose(fpVendas);
    fclose(fpClientes);
    fclose(fpProdutos);
    printf("\nPressione <ENTER> para continuar...");
    getchar();
}

void relatorioVendasPorData(void) {
    char data[11];
    printf("Informe a data da venda (formato DD/MM/AAAA): ");
    scanf("%10s", data);
    getchar();

    FILE *fpVendas = fopen("vendas.dat", "rb");
    FILE *fpClientes = fopen("Cliente.dat", "rb");
    FILE *fpProdutos = fopen("Produto.dat", "rb");

    if (fpVendas == NULL || fpClientes == NULL || fpProdutos == NULL) {
        printf("Erro ao abrir os arquivos!\n");
        return;
    }

    Venda venda;
    Cliente cli;
    Produto prod;
    int vendasEncontradas = 0;

    printf("\n----------------------------------------------------\n");
    printf("               Relatório de Vendas por Data          \n");
    printf("----------------------------------------------------\n");

    while (fread(&venda, sizeof(Venda), 1, fpVendas)) {
        if (venda.status == 1 && strcmp(venda.data, data) == 0) {
            fseek(fpClientes, 0, SEEK_SET);
            while (fread(&cli, sizeof(Cliente), 1, fpClientes)) {
                if (cli.status == 1 && strcmp(cli.cpf, venda.cpfCliente) == 0) {
                    break;
                }
            }

            fseek(fpProdutos, 0, SEEK_SET);
            while (fread(&prod, sizeof(Produto), 1, fpProdutos)) {
                if (prod.status == 1 && strcmp(prod.codigo, venda.codigo) == 0) {
                    break;
                }
            }

            printf("Número da Venda: %d\n", venda.numeroVenda);
            printf("Cliente: %s\n", cli.nome);
            printf("Produto: %s\n", prod.nome);
            printf("Quantidade: %d\n", venda.quantidade);
            printf("Valor Total: %.2f\n", venda.valorTotal);
            printf("Data: %s\n", venda.data);
            printf("----------------------------------------------------\n");
            vendasEncontradas = 1;
        }
    }

    if (!vendasEncontradas) {
        printf("Nenhuma venda encontrada para a data informada.\n");
    }

    fclose(fpVendas);
    fclose(fpClientes);
    fclose(fpProdutos);
    printf("\nPressione <ENTER> para continuar...");
    getchar();
}
