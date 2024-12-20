//Nesse arquivo estarão contidas todas as funções relacionadas ao Módulo Produtos 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "valida.h"
#include "produtos.h"

typedef struct produto Produto;

void moduloproduto(void) {
    int opcao;
    do {
        opcao = tela_menu_produto();  // Função que exibe o menu e retorna a escolha
        switch(opcao) {
            case 1:
                cadastrarProduto();
                break;
            case 2:
                pesquisarProduto();
                break;
            case 3:
                atualizarProduto();
                break;
            case 4:
                excluirProduto();
                break;
            case 0:
                printf("Retornando ao menu principal...\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
                getchar();  // Pausa para o usuário ler a mensagem
                break;
        } 		
    } while (opcao != 0);  // Continua até que o usuário escolha a opção 0
}

void cadastrarProduto(void) {
    Produto *prod;
    prod = tela_cadastrar_produto();
    gravarProduto(prod);
    free(prod);
}

void pesquisarProduto(void) {
    Produto* prod;
    char* codigo;
    codigo = tela_pesquisar_produto();
    prod = buscarProduto(codigo);
    exibirProduto(prod);
    free(prod); 
    free(codigo);
}

void atualizarProduto(void) {
    Produto* prod;
    char* codigo;
    codigo = tela_atualizar_produto();
    prod = buscarProduto(codigo);
    if (prod == NULL) {
        printf("\n\nProduto não encontrado!\n\n");
    } else {
        printf("\nProduto encontrado! Atualizando dados...\n");
        prod = tela_cadastrar_produto();
        strcpy(prod->codigo, codigo);  // Mantém o código original
        regravarProduto(prod);
        free(prod);
    }
    free(codigo);
}

void excluirProduto(void) {
    Produto* prod;
    char* codigo;
    char opcao;

    // Solicita o código do produto a ser excluído
    codigo = tela_excluir_produto();

    // Busca o produto no arquivo
    prod = buscarProduto(codigo);

    if (prod == NULL) {
        printf("\n\nProduto não encontrado!\n\n");
    } else {
        printf("\nProduto encontrado:\n");
        exibirProduto(prod);

        printf("\nDeseja realmente excluir este produto? (s/n): ");
        scanf(" %c", &opcao);
        getchar();

        if (opcao == 's' || opcao == 'S') {
            prod->status = 0;
            regravarProduto(prod);
            printf("\nProduto excluído com sucesso!\n");
        } else {
            printf("\nA exclusão foi cancelada.\n");
        }
    }

    free(prod);
    free(codigo);
}

// Função para mostrar o menu de produtos
int tela_menu_produto() {
    int op;
    system("clear||cls");
    printf("-------------------------------------------------------------------------- \n");
    printf("          - - - - Sistema de Gestão SIG-PHARMACY - - - - -               \n");
    printf("---------------------------------------------------------------------------\n");
    printf("                - - - - - Módulo Produtos - - - - -                        \n");
    printf("---------------------------------------------------------------------------\n");
    printf("           1. Cadastrar novo produto                                       \n");
    printf("           2. Pesquisar produto                                            \n");
    printf("           3. Atualizar produto                                            \n");
    printf("           4. Excluir produto                                              \n");
    printf("           0. Voltar ao Menu Principal                                     \n");
    printf("---------------------------------------------------------------------------\n");
    printf("           Digite o número da sua opção:                                   \n");
    scanf("%d", &op);
    getchar();
    return op;
}

// Função para cadastrar produto
Produto* tela_cadastrar_produto(void) {
    Produto *prod = (Produto*) malloc(sizeof(Produto));
    printf("\n");
    printf("---------------------------------------------------------------------------\n");
    printf("          - - - - Sistema de Gestão SIG-PHARMACY - - - - - \n");
    printf("---------------------------------------------------------------------------\n");
    printf("               - - - - - Cadastrar Novo Produto - - - - - \n");
    printf("---------------------------------------------------------------------------\n");

    do {
        printf("-----           Codigo (apenas números): ");
        scanf("%7s", prod->codigo);  
    } while (!validar_codigo(prod->codigo));
    getchar();

    do {
        printf("-----           Nome do produto: ");
        scanf("%50[^\n]", prod->nome);  
        getchar();
    } while (!validar_nome(prod->nome));

    do {
        printf("-----           Valor: ");
        scanf("%f", &prod->valor);  
        getchar();
    } while (!validar_valor(prod->valor));

    do {
        printf("-----           Data de validade (dd/mm/aaaa): ");
        scanf("%10s", prod->data);  
        getchar();
    } while (!validar_data(prod->data));

    do {
        printf("-----           Descrição: ");
        scanf("%100[^\n]", prod->descricao);  
        getchar();
    } while (!validar_descricao(prod->descricao));

    prod->status = 1;

    return prod;
}


// Função para pesquisar produto
char* tela_pesquisar_produto(void) {
    char* codigo = (char*) malloc(12 * sizeof(char));
    printf("Informe o código do produto: ");
    scanf("%11[^\n]", codigo);
    getchar();  
    return codigo;
}

// Função para atualizar produto
char* tela_atualizar_produto(void) {
    char* codigo = (char*) malloc(12 * sizeof(char));
    printf("Informe o código do produto: ");
    scanf("%11[^\n]", codigo);
    getchar();
    return codigo;
}

// Função para excluir produto
char* tela_excluir_produto(void) {
    char* codigo = (char*) malloc(12 * sizeof(char));
    printf("Informe o código do produto: ");
    scanf("%11[^\n]", codigo);
    getchar();
    return codigo;
}

// Função para gravar produto no arquivo binário
void gravarProduto(Produto* prod) {
    FILE* fp = fopen("Produto.dat", "ab");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo para gravação!\n");
        return;
    }
    fwrite(prod, sizeof(Produto), 1, fp);
    fclose(fp);
}

// Função para buscar produto no arquivo
Produto* buscarProduto(char* codigo) {
    FILE* fp = fopen("Produto.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo para leitura!\n");
        return NULL;
    }
    Produto* prod = (Produto*) malloc(sizeof(Produto));
    while (fread(prod, sizeof(Produto), 1, fp)) {
        if (strcmp(prod->codigo, codigo) == 0 && prod->status == 1) {
            fclose(fp);
            return prod;
        }
    }
    fclose(fp);
    free(prod);
    return NULL;
}

// Função para exibir dados do produto
void exibirProduto(Produto* prod) {
    if (prod == NULL) {
        printf("\n- - - Produto Inexistente - - -\n");
    } else {
        printf("\n- - - Produto Cadastrado - - -\n");
        printf("Código: %s\n", prod->codigo);
        printf("Nome: %s\n", prod->nome);
        printf("Valor: %.2f\n", prod->valor);  // Corrigido para imprimir um valor float com 2 casas decimais
        printf("Data de validade: %s\n", prod->data);
        printf("Descrição: %s\n", prod->descricao);
        printf("Status: %d\n", prod->status);
    }
    printf("\n\nTecle ENTER para continuar!\n");
    getchar();
}

// Função para regravar produto no arquivo binário
void regravarProduto(Produto* prod) {
    FILE* fp = fopen("Produto.dat", "r+b");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo para atualização!\n");
        return;
    }
    Produto* prodLido = (Produto*) malloc(sizeof(Produto));
    int achou = 0;
    while (fread(prodLido, sizeof(Produto), 1, fp) && !achou) {
        if (strcmp(prodLido->codigo, prod->codigo) == 0) {
            achou = 1;
            fseek(fp, -1 * sizeof(Produto), SEEK_CUR);  // Voltar para o começo do registro
            fwrite(prod, sizeof(Produto), 1, fp);  // Sobrescrever com os novos dados
        }
    }
    fclose(fp);
    free(prodLido);
}

// Função de erro
void tela_erro(void) {
    printf("Erro! Não foi possível realizar a operação.\n");
    getchar();
}