#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vendas.h"
#include "clientes.h"
#include "produtos.h"

void modulovenda(void) {
    int opcao;
    do {
        opcao = tela_menu_venda();  // Função que exibe o menu e retorna a escolha
        switch(opcao) {
            case 1:
                tela_cadastrar_venda();
                break;
            case 2:
                tela_pesquisar_venda();
                break;
            case 3:
                tela_atualizar_venda();
                break;
            case 4:
                tela_excluir_venda();
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

// Funções de tela

int tela_menu_venda(void) {
    int op;
    printf("\n");
    printf("-------------------------------------------------------------------------- \n");
    printf("                                                                           \n");
    printf("          - - - - - Sistema de Gestão SIG-PHARMACY - - - - -               \n");
    printf("                                                                           \n");
    printf("---------------------------------------------------------------------------\n");
    printf("                                                                           \n");
    printf("                 - - - - - Módulo Vendas - - - - -                         \n");
    printf("                                                                           \n");
    printf("           1. Cadastrar Venda                                              \n");
    printf("           2. Pesquisar Venda                                              \n");
    printf("           3. Atualizar Venda                                              \n");
    printf("           4. Excluir Venda                                                \n");
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


void tela_cadastrar_venda(void) {
    char cpf[12], codigo[8];
    Venda venda;
    
    system("clear||cls");
    printf("---------------------------------------------------------------------------\n");
    printf("          - - - - - Sistema de Gestão SIG-PHARMACY - - - - -               \n");
    printf("---------------------------------------------------------------------------\n");
    printf("               - - - - - Cadastrar Nova Venda - - - - -                    \n");
    printf("---------------------------------------------------------------------------\n");

    // Leitura do CPF do cliente
    printf("CPF do cliente: ");
    scanf("%11s", cpf);
    
    // Verifica se o cliente existe
    if (buscarCliente(cpf) == NULL) {
        printf("Cliente não encontrado!\n");
        return;
    }

    // Leitura do código do produto
    printf("Código do produto: ");
    scanf("%7s", codigo);

    // Verifica se o produto existe
    if (buscarProduto(codigo) == NULL) {
        printf("Produto não encontrado!\n");
        return;
    }

    // Leitura da quantidade
    printf("Quantidade desejada: ");
    scanf("%d", &venda.quantidade);

    // Cálculo do valor total da venda
    Produto* prod = buscarProduto(codigo);
    venda.valorTotal = prod->valor * venda.quantidade;
    
    // Armazena o CPF e código do produto
    strcpy(venda.cpfCliente, cpf);
    strcpy(venda.codigoProduto, codigo);
    
    // Leitura da data
    printf("Data da compra (dd/mm/aaaa): ");
    scanf("%10s", venda.data);
    
    // Grava a venda no arquivo
    gravarVenda(&venda);
    
    printf("\nVenda cadastrada com sucesso!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...");
    getchar();
}

void tela_pesquisar_venda(void) {
    char cpf[12];
    
    system("clear||cls");
    printf("---------------------------------------------------------------------------\n");
    printf("          - - - - - Sistema de Gestão SIG-PHARMACY - - - - -               \n");
    printf("---------------------------------------------------------------------------\n");
    printf("               - - - - - Pesquisar Venda - - - - -                        \n");
    printf("---------------------------------------------------------------------------\n");

    printf("Digite o CPF do cliente para pesquisar a venda: ");
    scanf("%11s", cpf);
    
    Venda* venda = buscarVenda(cpf);
    if (venda != NULL) {
        exibirVenda(venda);
        free(venda);
    } else {
        printf("Venda não encontrada para o CPF: %s\n", cpf);
    }
    
    printf("\t\t\t>>> Tecle <ENTER> para continuar...");
    getchar();
}

void tela_atualizar_venda(void) {
    char cpf[12], codigo[8];
    Venda* venda;

    system("clear||cls");
    printf("---------------------------------------------------------------------------\n");
    printf("          - - - - - Sistema de Gestão SIG-PHARMACY - - - - -               \n");
    printf("---------------------------------------------------------------------------\n");
    printf("               - - - - - Atualizar Venda - - - - -                        \n");
    printf("---------------------------------------------------------------------------\n");
    printf("Digite o CPF do cliente que efetuou a compra: ");
    scanf("%11s", cpf);
    getchar(); // Para consumir o '\n' após o scanf
    printf("Digite o código do produto que deseja atualizar: ");
    scanf("%7s", codigo);
    getchar();

    // Busca a venda existente
    venda = buscarVenda(cpf);
    if (venda == NULL) {
        printf("Venda não encontrada para o CPF: %s\n", cpf);
        return;
    }

    // Verifica se o código do produto corresponde à venda
    if (strcmp(venda->codigoProduto, codigo) != 0) {
        printf("Produto não encontrado na venda para o código: %s\n", codigo);
        free(venda);
        return;
    }

    // Permite atualizar os dados da venda
    printf("Atualizando a venda...\n");
    printf("Digite a nova quantidade: ");
    scanf("%d", &venda->quantidade);
    Produto* prod = buscarProduto(venda->codigoProduto);
    venda->valorTotal = prod->valor * venda->quantidade;

    // Atualiza a data da venda
    printf("Digite a nova data (dd/mm/aaaa): ");
    scanf("%10s", venda->data);

    // Regrava a venda no arquivo
    regravarVenda(venda);
    printf("\nVenda atualizada com sucesso!\n");
    free(venda);
}


void tela_excluir_venda(void) {
    char cpf[12], codigo[8];
    Venda* venda;

    system("clear||cls");
    printf("---------------------------------------------------------------------------\n");
    printf("          - - - - - Sistema de Gestão SIG-PHARMACY - - - - -               \n");
    printf("---------------------------------------------------------------------------\n");
    printf("               - - - - - Excluir Venda - - - - -                         \n");
    printf("---------------------------------------------------------------------------\n");
    printf("Digite o CPF do cliente que efetuou a compra: ");
    scanf("%11s", cpf);
    getchar();
    printf("Digite o código do produto que deseja excluir: ");
    scanf("%7s", codigo);
    getchar();

    // Busca a venda existente
    venda = buscarVenda(cpf);
    if (venda == NULL) {
        printf("Venda não encontrada para o CPF: %s\n", cpf);
        return;
    }

    // Verifica se o código do produto corresponde à venda
    if (strcmp(venda->codigoProduto, codigo) != 0) {
        printf("Produto não encontrado na venda para o código: %s\n", codigo);
        free(venda);
        return;
    }

    // Exclui a venda
    excluirVenda(cpf, codigo);
    printf("\nVenda excluída com sucesso!\n");
    free(venda);
}

void excluirVenda(char* cpf, char* codigo) {
    FILE* fp = fopen("Vendas.dat", "rb");
    FILE* temp = fopen("TempVendas.dat", "wb");
    
    if (fp == NULL || temp == NULL) {
        printf("Erro ao abrir os arquivos!\n");
        return;
    }
    
    Venda venda;
    while (fread(&venda, sizeof(Venda), 1, fp)) {
        if (strcmp(venda.cpfCliente, cpf) != 0 || strcmp(venda.codigoProduto, codigo) != 0) {
            fwrite(&venda, sizeof(Venda), 1, temp);  // Copia as vendas que não são a que deve ser excluída
        }
    }
    
    fclose(fp);
    fclose(temp);
    
    // Substitui o arquivo original pelo temporário
    remove("Vendas.dat");
    rename("TempVendas.dat", "Vendas.dat");
}

void regravarVenda(Venda* venda) {
    FILE* fp = fopen("Vendas.dat", "rb+");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo de vendas para atualização!\n");
        return;
    }
    
    Venda temp;
    while (fread(&temp, sizeof(Venda), 1, fp)) {
        if (strcmp(temp.cpfCliente, venda->cpfCliente) == 0 && strcmp(temp.codigoProduto, venda->codigoProduto) == 0) {
            fseek(fp, -sizeof(Venda), SEEK_CUR);  // Volta para sobrescrever a venda
            fwrite(venda, sizeof(Venda), 1, fp);
            fclose(fp);
            return;
        }
    }
    fclose(fp);
    printf("Venda não encontrada para atualizar.\n");
}


void gravarVenda(Venda* venda) {
    FILE* fp = fopen("Vendas.dat", "ab");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo de vendas para gravação!\n");
        return;
    }
    fwrite(venda, sizeof(Venda), 1, fp);
    fclose(fp);
}

Venda* buscarVenda(char* cpf) {
    FILE* fp = fopen("Vendas.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo de vendas para leitura!\n");
        return NULL;
    }
    
    Venda* venda = (Venda*) malloc(sizeof(Venda));
    while (fread(venda, sizeof(Venda), 1, fp)) {
        if (strcmp(venda->cpfCliente, cpf) == 0) {
            fclose(fp);
            return venda;
        }
    }
    fclose(fp);
    free(venda);
    return NULL;
}

void exibirVenda(Venda* venda) {
    if (venda == NULL) {
        printf("Venda não encontrada!\n");
    } else {
        printf("\n- - - Detalhes da Venda - - -\n");
        printf("CPF do cliente: %s\n", venda->cpfCliente);
        printf("Código do produto: %s\n", venda->codigoProduto);
        printf("Quantidade: %d\n", venda->quantidade);
        printf("Valor total: %.2f\n", venda->valorTotal);
        printf("Data da venda: %s\n", venda->data);
    }
    printf("\n\nTecle <ENTER> para continuar...");
    getchar();
}

