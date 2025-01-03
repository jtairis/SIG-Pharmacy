#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vendas.h"
#include "clientes.h"
#include "produtos.h"
#include "valida.h"

void modulovenda(void) {
    int opcao;
    do {
        opcao = tela_menu_venda();
        switch (opcao) {
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
                getchar();
                break;
        }
    } while (opcao != 0);
}

int tela_menu_venda(void) {
    int op;
    printf("\n");
    printf("--------------------------------------------------------------------------\n");
    printf("          - - - - - Sistema de Gestão SIG-PHARMACY - - - - -              \n");
    printf("---------------------------------------------------------------------------\n");
    printf("                 - - - - - Módulo Vendas - - - - -                        \n");
    printf("           1. Cadastrar Venda                                             \n");
    printf("           2. Pesquisar Venda                                             \n");
    printf("           3. Atualizar Venda                                             \n");
    printf("           4. Excluir Venda                                               \n");
    printf("           0. Voltar ao Menu Principal                                    \n");
    printf("---------------------------------------------------------------------------\n");
    printf("Digite o número da sua opção: ");
    scanf("%d", &op);
    return op;
}

Venda* tela_cadastrar_venda(void) {
    Venda* venda = (Venda*) malloc(sizeof(Venda));
    printf("\n");
    printf("---------------------------------------------------------------------------\n");
    printf("          - - - - Sistema de Gestão SIG-PHARMACY - - - - - \n");
    printf("---------------------------------------------------------------------------\n");
    printf("               - - - - - Cadastrar Nova Venda - - - - - \n");
    printf("---------------------------------------------------------------------------\n");


    do {
        printf("----- CPF do cliente (11 dígitos): ");
        scanf("%11s", venda->cpfCliente);  
        getchar();
        if (!validar_cpf_venda(venda->cpfCliente)) {
            printf("CPF inválido! Certifique-se de inserir 11 dígitos.\n");
        } else if (buscarCliente(venda->cpfCliente) == NULL) {
            printf("Cliente não encontrado!\n");
        }
    } while (!validar_cpf_venda(venda->cpfCliente) || buscarCliente(venda->cpfCliente) == NULL);


    Produto* prod = NULL;
    do {
        printf("----- Código do produto (7 dígitos): ");
        scanf("%7s", venda->codigo);  
        getchar();

        if (!validar_codigo_venda(venda->codigo)) {
            printf("Código inválido ou produto não encontrado. Tente novamente.\n");
        } else {
            prod = buscarProduto(venda->codigo);
        }
    } while (prod == NULL);


    do {
        printf("----- Quantidade desejada: ");
        if (scanf("%d", &venda->quantidade) != 1 || venda->quantidade <= 0) {
            printf("Quantidade inválida! Deve ser um número positivo.\n");
            while (getchar() != '\n');
        }
    } while (venda->quantidade <= 0);


    venda->valorTotal = prod->valor * venda->quantidade;


    do {
        printf("----- Data da compra (dd/mm/aaaa): ");
        scanf("%10s", venda->data);  
        getchar();
        if (!validar_data(venda->data)) {
            printf("Data inválida! Use o formato dd/mm/aaaa.\n");
        }
    } while (!validar_data(venda->data));


    venda->numeroVenda = obterNumeroVenda();
    venda->status = 1;


    gravarVenda(venda);
    printf("Venda cadastrada com sucesso!\n");

    return venda;
}

void tela_pesquisar_venda(void) {
    int numeroVenda;
    printf("\n");
    printf("---------------------------------------------------------------------------\n");
    printf("          - - - - Sistema de Gestão SIG-PHARMACY - - - - - \n");
    printf("---------------------------------------------------------------------------\n");
    printf("               - - - - - Pesquisar Venda - - - - - \n");
    printf("---------------------------------------------------------------------------\n");
    printf("Digite o número da venda para pesquisar: ");
    scanf("%d", &numeroVenda);

    Venda* venda = buscarVendaPorNumero(numeroVenda);
    if (venda != NULL && venda->status == 1) {
        exibirVenda(venda);
    } else {
        printf("Venda não encontrada ou excluída.\n");
    }
    free(venda);

    printf("\n\nTecle ENTER para continuar!\n");
    getchar();
    getchar();
}

void tela_atualizar_venda(void) {
    int numeroVenda;
    printf("\n");
    printf("---------------------------------------------------------------------------\n");
    printf("          - - - - Sistema de Gestão SIG-PHARMACY - - - - - \n");
    printf("---------------------------------------------------------------------------\n");
    printf("               - - - - - Atualizar Venda - - - - - \n");
    printf("---------------------------------------------------------------------------\n");
    printf("Digite o número da venda para atualizar: ");
    scanf("%d", &numeroVenda);

    Venda* venda = buscarVendaPorNumero(numeroVenda);
    if (venda == NULL || venda->status == 0) {
        printf("Venda não encontrada ou já excluída.\n");
        return;
    }

    printf("Digite a nova quantidade: ");
    scanf("%d", &venda->quantidade);

    Produto* prod = buscarProduto(venda->codigo);
    if (prod) {
        venda->valorTotal = prod->valor * venda->quantidade;
    }

    printf("Digite a nova data (dd/mm/aaaa): ");
    scanf("%10s", venda->data);

    regravarVenda(venda);
    printf("\nVenda atualizada com sucesso!\n");
    free(venda);

    printf("\n\nTecle ENTER para continuar!\n");
    getchar();
    getchar();
}

void tela_excluir_venda(void) {
    int numeroVenda;
    printf("\n");
    printf("---------------------------------------------------------------------------\n");
    printf("          - - - - Sistema de Gestão SIG-PHARMACY - - - - - \n");
    printf("---------------------------------------------------------------------------\n");
    printf("               - - - - - Excluir Venda - - - - - \n");
    printf("---------------------------------------------------------------------------\n");
    printf("Digite o número da venda para excluir: ");
    scanf("%d", &numeroVenda);

    Venda* venda = buscarVendaPorNumero(numeroVenda);
    if (venda != NULL && venda->status == 1) {
        exibirVenda(venda);
        printf("\nDeseja realmente excluir esta venda? (s/n): ");
        char confirmacao;
        scanf(" %c", &confirmacao);
        if (confirmacao == 's' || confirmacao == 'S') {
            excluirVendaLogica(numeroVenda);
            printf("\nVenda excluída com sucesso (lógica).\n");
        } else {
            printf("\nOperação de exclusão cancelada.\n");
        }
    } else {
        printf("Venda não encontrada ou já excluída.\n");
    }
    free(venda);

    printf("\n\nTecle ENTER para continuar!\n");
    getchar();
    getchar();
}

void gravarVenda(Venda* venda) {
    FILE* fp = fopen("vendas.dat", "ab");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo de vendas.\n");
        return;
    }
    fwrite(venda, sizeof(Venda), 1, fp);
    fclose(fp);
}

Venda* buscarVendaPorNumero(int numeroVenda) {
    FILE* fp = fopen("vendas.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo de vendas.\n");
        return NULL;
    }

    Venda* venda = (Venda*)malloc(sizeof(Venda));
    while (fread(venda, sizeof(Venda), 1, fp)) {
        if (venda->numeroVenda == numeroVenda) {
            fclose(fp);
            return venda;
        }
    }
    fclose(fp);
    free(venda);
    return NULL;
}

void regravarVenda(Venda* venda) {
    FILE* fp = fopen("vendas.dat", "rb+");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo de vendas.\n");
        return;
    }

    Venda temp;
    while (fread(&temp, sizeof(Venda), 1, fp)) {
        if (temp.numeroVenda == venda->numeroVenda) {
            fseek(fp, -sizeof(Venda), SEEK_CUR);
            fwrite(venda, sizeof(Venda), 1, fp);
            fclose(fp);
            return;
        }
    }
    fclose(fp);
}

void excluirVendaLogica(int numeroVenda) {
    Venda* venda = buscarVendaPorNumero(numeroVenda);
    if (venda) {
        venda->status = 0;
        regravarVenda(venda);
        free(venda);
    }
}

void exibirVenda(const Venda* venda) {
    printf("\nDetalhes da Venda:\n");
    printf("Número da Venda: %d\n", venda->numeroVenda);
    printf("CPF do Cliente: %s\n", venda->cpfCliente);
    printf("Código do Produto: %s\n", venda->codigo);
    printf("Quantidade: %d\n", venda->quantidade);
    printf("Valor Total: %.2f\n", venda->valorTotal);
    printf("Data: %s\n", venda->data);
}

int obterNumeroVenda() {
    FILE* fp = fopen("vendas.dat", "rb");
    if (!fp) return 1;

    Venda venda;
    int ultimoNumero = 0;

    while (fread(&venda, sizeof(Venda), 1, fp)) {
        if (venda.numeroVenda > ultimoNumero) {
            ultimoNumero = venda.numeroVenda;
        }
    }

    fclose(fp);
    return ultimoNumero + 1;
}
