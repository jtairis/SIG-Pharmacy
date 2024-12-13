//Nesse arquivo estarão contidas todas as funções relacionadas ao Módulo Produtos 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "valida.h"
#include "produtos.h"

typedef struct produto Produto;

void moduloproduto(void) {
	char opcao;
	do {
		opcao = menu_produto();
		switch(opcao) {
			case '1': 	tela_cadastrar_produto();
						break;
			case '2': 	tela_pesquisar_produto();
						break;
			case '3': 	tela_atualizar_produto();
						break;
			case '4': 	tela_excluir_produto();
						break;
		} 		
	} while (opcao != '0');
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
		  prod = tela_cadastrar_produto();
		  strcpy(prod->codigo, codigo);
		  regravarProduto(prod);
		  free(prod);
	}
	free(codigo);
}


void excluirProduto(void) {
	Produto* prod;
	char *codigo;

	codigo = tela_excluir_produto();
	prod = (Produto*) malloc(sizeof(Produto));
	prod = buscarProduto(codigo);
	if (prod == NULL) {
    	printf("\n\nProduto não encontrado!\n\n");
  	} else {
		  prod->status = 0;
		  regravarProduto(prod);
		  free(prod);
	}
	free(codigo);
}


//Funções para mostrar telas
char menu_produto(void) {
    char op;
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
    scanf("%c", &op);
    printf("                                                                           \n");
    printf("---------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...");
    return op;
}

// Função para cadastrar produto
Produto* tela_cadastrar_produto(void) {
    Produto *prod;
    prod = (Produto*) malloc(sizeof(Produto));


    system("clear||cls");
    printf("---------------------------------------------------------------------------\n");
    printf("          = = = = Sistema de Gestão SIG-PHARMACY = = = = =               \n");
    printf("---------------------------------------------------------------------------\n");
    printf("               = = = = = Cadastrar Novo Produto = = = = =                  \n");
    printf("---------------------------------------------------------------------------\n");
    do {
		printf("///           codigo (apenas 7 números): ");
		scanf("%[^\n]", prod->codigo);
		getchar();
	} while (!validar_codigo(prod->codigo));
	printf("///           Nome do produto: ");
	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", prod->nome);
	getchar();
	printf("///           data de validade: ");
	scanf("%[a-z0-9@.]", prod->data);
	getchar();
	printf("///           valor do produto:  ");
	scanf("%[0-9/]", prod->valor);
	getchar();
	do {
		printf("///           descrição do produto: ");
		scanf("%[^\n]", prod->descricao);
		getchar();
	} while (!validar_descricao(prod->descricao));
	prod->status = 1;

    printf("\nProduto cadastrado com sucesso.\n");
    printf("---------------------------------------------------------------------------\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...");
    getchar();
    return prod;
}

// Função para pesquisar produto
char* tela_pesquisar_produto(void) {
    char* prod;
    prod = (char*) malloc(12*sizeof(char));


    system("clear||cls");
    printf("---------------------------------------------------------------------------\n");
    printf("          = = = = = Sistema de Gestão SIG-PHARMACY = = = = =               \n");
    printf("---------------------------------------------------------------------------\n");
    printf("                 = = = = = Pesquisar Produto = = = = =                     \n");
    printf("---------------------------------------------------------------------------\n");
    printf("-----           Informe o codigo do produto: ");
	scanf("%[0-9]", prod);
    getchar();
    printf("---------------------------------------------------------------------------\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...");
    return prod;
}

char* tela_atualizar_produto(void) {
    char* prod;
    prod = (char*) malloc(12*sizeof(char));

    system("clear||cls");
    printf("\n");
    printf("---------------------------------------------------------------------------\n");
    printf("          = = = = = Sistema de Gestão SIG-PHARMACY = = = = =               \n");
    printf("---------------------------------------------------------------------------\n");
    printf("                  = = = = = Atualizar Produto = = = = =                    \n");
    printf("---------------------------------------------------------------------------\n");
    printf("------           Informe o codigo do produto: ");
	scanf("%[0-9]", prod);
	getchar();
    printf("---------------------------------------------------------------------------\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...");
    return prod;
}

char* tela_excluir_produto(void) {
    char *prod;
    prod = (char*) malloc(12*sizeof(char));

    system("clear||cls");
    printf("\n");
    printf("---------------------------------------------------------------------------\n");
    printf("          = = = = = Sistema de Gestão SIG-PHARMACY = = = = =               \n");
    printf("---------------------------------------------------------------------------\n");
    printf("                  = = = = = Excluir Produto = = = = =                      \n");
    printf("---------------------------------------------------------------------------\n");
    printf("------           Informe o codigo do produto: ");
	scanf("%[0-9]", prod);
	getchar();
    printf("---------------------------------------------------------------------------\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...");
    return prod;
}

void gravarProduto(Produto* prod) {
	FILE* fp;

	fp = fopen("Produto.dat", "ab");
	if (fp == NULL) {
		tela_erro();
	}
	fwrite(prod, sizeof(Produto), 1, fp);
	fclose(fp);
}

Produto* buscarProduto(char* codigo) {
	FILE* fp;
	Produto* prod;

	prod = (Produto*) malloc(sizeof(Produto));
	fp = fopen("Produtos.dat", "rb");
	if (fp == NULL) {
		tela_erro();
	}
	while(fread(prod, sizeof(Produto), 1, fp)) {
		if ((strcmp(prod->codigo, codigo) == 0) && (prod->status == 1)) {
			fclose(fp);
			return prod;
		}
	}
	fclose(fp);
	return NULL;
}

void exibirProduto(Produto* prod) {

	if (prod == NULL) {
		printf("\n= = = Produto Inexistente = = =\n");
	} else {
		printf("\n= = = Produto Cadastrado = = =\n");
		printf("codigo do produto: %s\n", prod->codigo);
		printf("Nome do Produto: %s\n", prod->nome);
		printf("Valor do produto: %s\n", prod->valor);
		printf("Data de validade: %s\n", prod->data);
		printf("descricão do produto: %s\n", prod->descricao);
		printf("Status: %d\n", prod->status);
	}
	printf("\n\nTecle ENTER para continuar!\n\n");
	getchar();
}

void regravarProduto(Produto* prod) {
	int achou;
	FILE* fp;
	Produto* prodLido;

	prodLido = (Produto*) malloc(sizeof(Produto));
	fp = fopen("Produto.dat", "r+b");
	if (fp == NULL) {
		tela_erro();
	}
	achou = 0;
	while(fread(prodLido, sizeof(Produto), 1, fp) && !achou) {
		if (strcmp(prodLido->codigo, prod->codigo) == 0) {
			achou = 1;
			fseek(fp, -1*sizeof(Produto), SEEK_CUR);
        	fwrite(prod, sizeof(Produto), 1, fp);
			//break;
		}
	}
	fclose(fp);
	free(prodLido);
}