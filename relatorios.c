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
        printf("           3. Relatório de Produtos por Data de Validade                   \n");
        printf("           4. Relatório de Produtos por Ordem Alfabetica                   \n");
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
            case 4:
                relatorioProdAlfabetica();
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
        printf("Código: %s\n", prod.codigo);
        printf("Nome: %s\n", prod.nome);
        printf("Valor: %.2f\n", prod.valor);
        printf("Data de validade: %s\n", prod.data);
        printf("Descrição: %s\n", prod.descricao);
        printf("status: %d\n", prod.status);
        printf("----------------------------------------------------\n");
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

void relatorioProdAlfabetica(void) {
    FILE *fp = fopen("Produto.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo de produtos!\n");
        return;
    }

    Produto *produtos = NULL;
    int count = 0;

    Produto prod;
    while (fread(&prod, sizeof(Produto), 1, fp)) {
        if (prod.status == 1) { // Apenas produtos ativos
            produtos = realloc(produtos, (count + 1) * sizeof(Produto));
            produtos[count] = prod;
            count++;
        }
    }
    fclose(fp);

    if (count == 0) {
        printf("Nenhum produto encontrado para exibição!\n");
        free(produtos);
        return;
    }

    // Ordenar produtos por ordem alfabética
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(produtos[i].nome, produtos[j].nome) > 0) {
                Produto temp = produtos[i];
                produtos[i] = produtos[j];
                produtos[j] = temp;
            }
        }
    }

    // Exibir os produtos ordenados
    printf("\n----------------------------------------------------\n");
    printf("         Relatório de Produtos em Ordem Alfabética  \n");
    printf("----------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("Código: %s\n", produtos[i].codigo);
        printf("Nome: %s\n", produtos[i].nome);
        printf("Valor: %.2f\n", produtos[i].valor);
        printf("Data de validade: %s\n", produtos[i].data);
        printf("Descrição: %s\n", produtos[i].descricao);
        printf("----------------------------------------------------\n");
    }

    // Liberar memória
    free(produtos);

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
        printf("           1. Relatório Geral de Clientes                                  \n");
        printf("           2. Relatório de Clientes por Data de Nascimento                 \n");
        printf("           3. Relatório de Clientes por Ordem Alfabética                   \n");
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
            case 3:
                relatorioClientesAlfabetica();
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
        printf("CPF: %s\n", cli.cpf);
        printf("Nome: %s\n", cli.nome);
        printf("Telefone: %s\n", cli.tele);
        printf("E-mail: %s\n", cli.email);
        printf("Data de Nascimento: %s\n", cli.data);
        printf("status: %d\n", cli.status);
        printf("----------------------------------------------------\n");
        clientesEncontrados = 1;
    }

    if (!clientesEncontrados) {
        printf("Nenhum cliente encontrado.\n");
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
void relatorioClientesAlfabetica(){
    FILE* fp = fopen("Cliente.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo de clientes!\n");
        return;
    }

    Cliente* clientes = NULL;  // Ponteiro para armazenar os registros
    int qtdClientes = 0;       // Contador de clientes
    Cliente cli;

    // Lê os registros do arquivo para a memória
    while (fread(&cli, sizeof(Cliente), 1, fp)) {
        if (cli.status == 1) { // Apenas clientes ativos
            clientes = realloc(clientes, (qtdClientes + 1) * sizeof(Cliente));
            if (clientes == NULL) {
                printf("Erro ao alocar memória!\n");
                fclose(fp);
                return;
            }
            clientes[qtdClientes] = cli;
            qtdClientes++;
        }
    }
    fclose(fp);

    if (qtdClientes == 0) {
        printf("Nenhum cliente encontrado!\n");
        free(clientes);
        return;
    }

    // Ordenar os registros por nome em ordem alfabética
    for (int i = 0; i < qtdClientes - 1; i++) {
        for (int j = i + 1; j < qtdClientes; j++) {
            if (strcmp(clientes[i].nome, clientes[j].nome) > 0) {
                Cliente temp = clientes[i];
                clientes[i] = clientes[j];
                clientes[j] = temp;
            }
        }
    }

    // Exibir os registros ordenados
    printf("\n----------------------------------------------------\n");
    printf("          Relatório de Clientes em Ordem Alfabética\n");
    printf("----------------------------------------------------\n");

    for (int i = 0; i < qtdClientes; i++) {
        printf("CPF: %s\n", clientes[i].cpf);
        printf("Nome: %s\n", clientes[i].nome);
        printf("Telefone: %s\n", clientes[i].tele);
        printf("E-mail: %s\n", clientes[i].email);
        printf("Data de Nascimento: %s\n", clientes[i].data);
        printf("----------------------------------------------------\n");
    }

    // Liberar memória alocada
    free(clientes);

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
        printf("           4. Relatório de Vendas por ordem alfabetica                     \n");
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
            case 4:
                gerarRelatorioClientesEVendas();
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
        fseek(fpClientes, 0, SEEK_SET);
        while (fread(&cli, sizeof(Cliente), 1, fpClientes)) {
            if (strcmp(cli.cpf, venda.cpfCliente) == 0) {
                break;
            }
        }

        fseek(fpProdutos, 0, SEEK_SET);
        while (fread(&prod, sizeof(Produto), 1, fpProdutos)) {
            if (strcmp(prod.codigo, venda.codigo) == 0) {
                break;
            }
        }

        printf("Número da Venda: %d\n", venda.numeroVenda);
        printf("Cliente: %s\n", cli.nome);
        printf("Produto: %s\n", prod.nome);
        printf("Quantidade: %d\n", venda.quantidade);
        printf("Valor Total: %.2f\n", venda.valorTotal);
        printf("Data: %s\n", venda.data);
        printf("status: %d\n", venda.status);
        printf("----------------------------------------------------\n");
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

void gerarRelatorioClientesEVendas(void) {
    FILE* fp = fopen("Cliente.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo de clientes!\n");
        return;
    }

    // Carregar todos os clientes
    Cliente clientes[100];
    int totalClientes = 0;

    while (fread(&clientes[totalClientes], sizeof(Cliente), 1, fp)) {
        totalClientes++;
    }
    fclose(fp);

    if (totalClientes == 0) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    // Ordenar clientes por nome
    qsort(clientes, totalClientes, sizeof(Cliente), compararClientes);

    // Exibir o relatório
    printf("\n---------------------------------------------------------------------------\n");
    printf("                Relatório de Clientes e Vendas\n");
    printf("---------------------------------------------------------------------------\n");

    for (int i = 0; i < totalClientes; i++) {
        printf("\nCliente: %s (CPF: %s)\n", clientes[i].nome, clientes[i].cpf);
        printf("---------------------------------------------------------------------------\n");

        // Exibir vendas do cliente atual
        exibirVendasDoCliente(clientes[i].cpf, clientes[i].nome);
    }

    printf("\nPressione <ENTER> para continuar...");
    getchar();
}

// Função para comparar clientes por nome
int compararClientes(const void* a, const void* b) {
    Cliente* cliente1 = (Cliente*)a;
    Cliente* cliente2 = (Cliente*)b;
    return strcmp(cliente1->nome, cliente2->nome);
}

// Função para exibir vendas associadas a um cliente
void exibirVendasDoCliente(char* cpf, char* nome) {
    FILE* fp = fopen("vendas.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo de vendas!\n");
        return;
    }

    Venda venda;
    int vendasEncontradas = 0;

    while (fread(&venda, sizeof(Venda), 1, fp)) {
        if (venda.status == 1 && strcmp(venda.cpfCliente, cpf) == 0) {
            if (!vendasEncontradas) {
                printf("| Nº Venda | Código Produto | Quantidade | Valor Total | Data da Venda |\n");
                printf("---------------------------------------------------------------------------\n");
            }

            printf("| %-8d | %-14s | %-10d | R$%-10.2f | %-12s |\n",
                   venda.numeroVenda,
                   venda.codigo,
                   venda.quantidade,
                   venda.valorTotal,
                   venda.data);

            vendasEncontradas = 1;
        }
    }

    if (!vendasEncontradas) {
        printf("Nenhuma venda registrada para este cliente.\n");
    }

    fclose(fp);
}
