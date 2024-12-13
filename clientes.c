//Nesse arquivo estarão contidas as funções relacionadas ao Módulo Clientes

#include <string.h>  
#include <stdio.h>
#include <stdlib.h>
#include "valida.h"
#include "clientes.h"

typedef struct cliente Cliente;


void modulocliente(void) {
    int opcao;
    do {
        opcao = tela_menu_cliente();  // Função que exibe o menu e retorna a escolha
        switch(opcao) {
            case 1:
                tela_cadastrar_cliente();
                break;
            case 2:
                tela_pesquisar_cliente();
                break;
            case 3:
                tela_atualizar_cliente();
                break;
            case 4:
                tela_excluir_cliente();
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

void cadastrarCliente(void) {
	Cliente *clt;

	clt = tela_cadastrar_cliente();
	gravarCliente(clt);
	free(clt);
}


void pesquisarCliente(void) {
	Cliente* clt;
	char* cpf;

	cpf = tela_pesquisar_cliente();
	clt = buscarCliente(cpf);
	exibirCliente(clt);
	free(clt); 
	free(cpf);
}


void atualizarCliente(void) {
	Cliente* clt;
	char* cpf;

	cpf = tela_pesquisar_cliente();
	clt = buscarCliente(cpf);
	if (clt == NULL) {
    	printf("\n\nCliente não encontrado!\n\n");
  	} else {
		  clt = tela_cadastrar_cliente();
		  strcpy(clt->cpf, cpf);
		  regravarCliente(clt);
		  free(clt);
	}
	free(cpf);
}


void excluirCliente(void) {
	Cliente* clt;
	char *cpf;

	cpf = tela_excluir_cliente();
	clt = (Cliente*) malloc(sizeof(Cliente));
	clt = buscarCliente(cpf);
	if (clt == NULL) {
    	printf("\n\nCliente não encontrado!\n\n");
  	} else {
		  clt->status = 0;
		  regravarCliente(clt);
		  free(clt);
	}
	free(cpf);
}


int tela_menu_cliente(void) {
    int op;
    printf("\n");
    printf("-------------------------------------------------------------------------- \n");
    printf("                                                                           \n");
    printf("          = = = = = Sistema de Gestão SIG-PHARMACY = = = = =               \n");
    printf("                                                                           \n");
    printf("---------------------------------------------------------------------------\n");
    printf("                                                                           \n");
    printf("                = = = = = Módulo Cliente = = = = =                         \n");
    printf("                                                                           \n");
    printf("           1. Cadastrar novo cliente                                       \n");
    printf("           2. Pesquisar cliente                                            \n");
    printf("           3. Atualizar cliente                                            \n");
    printf("           4. Excluir cliente                                              \n");
    printf("           0. Voltar ao Menu Principal                                     \n");
    printf("                                                                           \n");
    printf("           Digite o número da sua opção:                                   \n");
    scanf("%d", &op);
    getchar();
    printf("                                                                           \n");
    printf("---------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...");
    return op;
}

Cliente* tela_cadastrar_cliente(void) {
    Cliente *clt;
	clt = (Cliente*) malloc(sizeof(Cliente));

    printf("\n");
    printf("---------------------------------------------------------------------------\n");
    printf("          = = = = Sistema de Gestão SIG-PHARMACY = = = = = \n");
    printf("---------------------------------------------------------------------------\n");
    printf("               = = = = = Cadastrar Novo Cliente = = = = = \n");
    printf("---------------------------------------------------------------------------\n");
    do {
		printf("-----           cpf(apenas números): ");
		scanf("%[^\n]", clt->cpf);
		getchar();
	} while (!validar_cpf(clt->cpf));
	printf("-----           Nome completo: ");
	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", clt->nome);
	getchar();
	printf("-----           E-mail: ");
	scanf("%[a-z0-9@.]", clt->email);
	getchar();
	printf("-----           Data de Nascimento (dd/mm/aaaa):  ");
	scanf("%[0-9/]", clt->data);
	getchar();
	do {
		printf("-----           Telefone  (apenas números com DDD): ");
		scanf("%[^\n]", clt->tele);
		getchar();
	} while (!validar_telefone(clt->tele));
	clt->status = 1;
    printf("\nCliente cadastrado com sucesso!\n");
    printf("\n---------------------------------------------------------------------------\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...");
	getchar();
    return clt;
} 


char* tela_pesquisar_cliente(void) {
    char* cpf;
	cpf = (char*) malloc(12*sizeof(char));

    printf("---------------------------------------------------------------------------\n");
    printf("          = = = = Sistema de Gestão SIG-PHARMACY = = = = = \n");
    printf("---------------------------------------------------------------------------\n");
    printf("                = = = = = Pesquisar Cliente = = = = = \n");
    printf("---------------------------------------------------------------------------\n");
    printf("///           Informe o cpf do cliente (apenas números): ");
	scanf("%[0-9]", cpf);
	getchar();
    printf("---------------------------------------------------------------------------\n");
    printf(">>> Tecle <ENTER> para continuar...");
	getchar();
    return cpf;
}

char* tela_atualizar_cliente(void) {
    char* cpf;
	cpf = (char*) malloc(12*sizeof(char));

    printf("---------------------------------------------------------------------------\n");
    printf("          = = = = Sistema de Gestão SIG-PHARMACY = = = = = \n");
    printf("---------------------------------------------------------------------------\n");
    printf("               = = = = = Atualizar Dados de Cliente = = = = = \n");
    printf("---------------------------------------------------------------------------\n");
    printf("///           Informe o cpf do cliente (apenas números): ");
	scanf("%[0-9]", cpf);
	getchar();
    printf("---------------------------------------------------------------------------\n");
    printf(">>> Tecle <ENTER> para continuar...");
	getchar();
    return cpf;
}

char* tela_excluir_cliente(void) {
    char *cpf;
	cpf = (char*) malloc(12*sizeof(char));

    printf("---------------------------------------------------------------------------\n");
    printf("          = = = = Sistema de Gestão SIG-PHARMACY = = = = = \n");
    printf("---------------------------------------------------------------------------\n");
    printf("                   = = = = = Excluir Cliente = = = = = \n");
    printf("---------------------------------------------------------------------------\n");
    printf("///           Informe o cpf do cliente (apenas números): ");
	scanf("%[0-9]", cpf);
	getchar();
    printf("---------------------------------------------------------------------------\n");
    printf(">>> Tecle <ENTER> para continuar...");
	getchar();
    return cpf;
}


void gravarCliente(Cliente* clt) {
	FILE* fp;

	fp = fopen("Cliente.dat", "ab");
	if (fp == NULL) {
		tela_erro();
	}
	fwrite(clt, sizeof(Cliente), 1, fp);
	fclose(fp);
}


Cliente* buscarCliente(char* cpf) {
	FILE* fp;
	Cliente* clt;

	clt = (Cliente*) malloc(sizeof(Cliente));
	fp = fopen("Cliente.dat", "rb");
	if (fp == NULL) {
		tela_erro();
	}
	while(fread(clt, sizeof(Cliente), 1, fp)) {
		if ((strcmp(clt->cpf, cpf) == 0) && (clt->status == 1)) {
			fclose(fp);
			return clt;
		}
	}
	fclose(fp);
	return NULL;
}


void exibirCliente(Cliente* clt) {

	if (clt == NULL) {
		printf("\n- - - Cliente Inexistente - - -\n");
	} else {
		printf("\n- - - Cliente Cadastrado - - -\n");
		printf("Cpf: %s\n", clt->cpf);
		printf("Nome do Cliente: %s\n", clt->nome);
		printf("Email do cliente: %s\n", clt->email);
		printf("Data de Nascimento: %s\n", clt->data);
		printf("Telefone: %s\n", clt->tele);
		printf("Status: %d\n", clt->status);
	}
	printf("\n\nTecle ENTER para continuar!\n\n");
	getchar();
}


void regravarCliente(Cliente* clt) {
	int achou;
	FILE* fp;
	Cliente* cltLido;

	cltLido = (Cliente*) malloc(sizeof(Cliente));
	fp = fopen("Cliente.dat", "r+b");
	if (fp == NULL) {
		tela_erro();
	}
	achou = 0;
	while(fread(cltLido, sizeof(Cliente), 1, fp) && !achou) {
		if (strcmp(cltLido->cpf, clt->cpf) == 0) {
			achou = 1;
			fseek(fp, -1*sizeof(Cliente), SEEK_CUR);
        	fwrite(clt, sizeof(Cliente), 1, fp);
		}
	}
	fclose(fp);
	free(cltLido);
}