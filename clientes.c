#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "clientes.h"
#include "valida.h"

void modulocliente(void) {
    int opcao;
    do {
        opcao = tela_menu_cliente();
        switch(opcao) {
            case 1:
                cadastrarCliente();
                break;
            case 2:
                pesquisarCliente();
                break;
            case 3:
                atualizarCliente();
                break;
            case 4:
                excluirCliente();
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

void cadastrarCliente(void) {
    verificar_arquivo_cliente();
    Cliente *cli;
    cli = tela_cadastrar_cliente();
    gravarCliente(cli);
    free(cli);
}


void pesquisarCliente(void) {
    Cliente* cli;
    char* cpf;
    cpf = tela_pesquisar_cliente();
    cli = buscarCliente(cpf);
    exibirCliente(cli);
    free(cli); 
    free(cpf);
}

void atualizarCliente(void) {
    Cliente* cli;
    char* cpf;
    cpf = tela_atualizar_cliente();
    cli = buscarCliente(cpf);

    if (cli == NULL) {
        printf("\n\nCliente não encontrado!\n\n");
    } else {
        printf("\nCliente encontrado! Atualizando dados...\n");
        exibirCliente(cli);
        atualizarDadosCliente(cli);
        regravarCliente(cli);
        free(cli);
    }

    free(cpf);
}

void excluirCliente(void) {
    Cliente* cli;
    char* cpf;
    char opcao;

    cpf = tela_excluir_cliente();

    cli = buscarCliente(cpf);

    if (cli == NULL) {
        printf("\n\nCliente não encontrado!\n\n");
    } else {
        printf("\nCliente encontrado:\n");
        exibirCliente(cli);

        printf("\nDeseja realmente excluir este cliente? (s/n): ");
        scanf(" %c", &opcao);
        getchar();

        if (opcao == 's' || opcao == 'S') {
            cli->status = 0;
            regravarCliente(cli);
            printf("\nCliente excluído com sucesso!\n");
        } else {
            printf("\nA exclusão foi cancelada.\n");
        }
    }

    free(cli);
    free(cpf);
}

int tela_menu_cliente() {
    int op;
    system("clear||cls");
    printf("-------------------------------------------------------------------------- \n");
    printf("          - - - - Sistema de Gestão SIG-PHARMACY - - - - -               \n");
    printf("---------------------------------------------------------------------------\n");
    printf("                - - - - - Módulo Clientes - - - - -                        \n");
    printf("---------------------------------------------------------------------------\n");
    printf("           1. Cadastrar novo cliente                                       \n");
    printf("           2. Pesquisar cliente                                            \n");
    printf("           3. Atualizar cliente                                            \n");
    printf("           4. Excluir cliente                                              \n");
    printf("           0. Voltar ao Menu Principal                                     \n");
    printf("---------------------------------------------------------------------------\n");
    printf("           Digite o número da sua opção:                                   \n");
    scanf("%d", &op);
    getchar();
    return op;
}

Cliente* tela_cadastrar_cliente(void) {
    Cliente *cli = (Cliente*) malloc(sizeof(Cliente));
    printf("\n");
    printf("---------------------------------------------------------------------------\n");
    printf("          - - - - Sistema de Gestão SIG-PHARMACY - - - - - \n");
    printf("---------------------------------------------------------------------------\n");
    printf("               - - - - - Cadastrar Novo Cliente - - - - - \n");
    printf("---------------------------------------------------------------------------\n");


    do {
        printf("----- CPF (apenas números): ");
        scanf("%14[^\n]", cli->cpf);
        getchar();
    } while (!validar_cpf(cli->cpf)); 


    do {
        printf("----- Nome: ");
        scanf("%51[^\n]", cli->nome);
        getchar();
    } while (!validar_nome(cli->nome)); 
    for (int i = 0; cli->nome[i] != '\0'; i++) {
        cli->nome[i] = toupper(cli->nome[i]); 
    }

    do {
        printf("----- Telefone: ");
        scanf("%12[^\n]", cli->tele);
        getchar();
    } while (!validar_telefone(cli->tele)); 


    do {
        printf("----- E-mail: ");
        scanf("%30[^\n]", cli->email);
        getchar();
    } while (!validar_email(cli->email)); 

    do {
        printf("----- Data de nascimento (dd/mm/aaaa): ");
        scanf("%10[^\n]", cli->data);
        getchar();
    } while (!validar_data(cli->data)); 

    cli->status = 1;
    return cli;
}

char* tela_pesquisar_cliente(void) {
    char* cpf = (char*) malloc(15 * sizeof(char));
    printf("\n");
    printf("---------------------------------------------------------------------------\n");
    printf("          - - - - Sistema de Gestão SIG-PHARMACY - - - - - \n");
    printf("---------------------------------------------------------------------------\n");
    printf("               - - - - - Pesquisar Cliente - - - - - \n");
    printf("---------------------------------------------------------------------------\n");
    printf("Informe o CPF do cliente: ");
    scanf("%14[^\n]", cpf);
    getchar();  
    return cpf;
}

char* tela_atualizar_cliente(void) {
    char* cpf = (char*) malloc(15 * sizeof(char));
    printf("\n");
    printf("---------------------------------------------------------------------------\n");
    printf("          - - - - Sistema de Gestão SIG-PHARMACY - - - - - \n");
    printf("---------------------------------------------------------------------------\n");
    printf("               - - - - - Atualizar Cliente - - - - - \n");
    printf("---------------------------------------------------------------------------\n");
    printf("Informe o CPF do cliente: ");
    scanf("%14[^\n]", cpf);
    getchar();
    return cpf;
}

char* tela_excluir_cliente(void) {
    char* cpf = (char*) malloc(15 * sizeof(char));
    printf("\n");
    printf("---------------------------------------------------------------------------\n");
    printf("          - - - - Sistema de Gestão SIG-PHARMACY - - - - - \n");
    printf("---------------------------------------------------------------------------\n");
    printf("               - - - - - Excluir Cliente - - - - - \n");
    printf("---------------------------------------------------------------------------\n");
    printf("Informe o CPF do cliente: ");
    scanf("%14[^\n]", cpf);
    getchar();
    return cpf;
}

void gravarCliente(Cliente* cli) {
    FILE* fp = fopen("Cliente.dat", "ab");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo para gravação!\n");
        return;
    }
    fwrite(cli, sizeof(Cliente), 1, fp);
    fclose(fp);
}

Cliente* buscarCliente(const char* cpf) {
    FILE* fp = fopen("Cliente.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo para leitura!\n");
        return NULL;
    }
    Cliente* cli = (Cliente*) malloc(sizeof(Cliente));
    while (fread(cli, sizeof(Cliente), 1, fp)) {
        if (strcmp(cli->cpf, cpf) == 0 && cli->status == 1) {
            fclose(fp);
            return cli;
        }
    }
    fclose(fp);
    free(cli);
    return NULL;
}

void exibirCliente(Cliente* cli) {
    if (cli == NULL) {
        printf("\n- - - Cliente Inexistente - - -\n");
    } else {
        printf("\n- - - Cliente Cadastrado - - -\n");
        printf("CPF: %s\n", cli->cpf);
        printf("Nome: %s\n", cli->nome);
        printf("Telefone: %s\n", cli->tele);
        printf("E-mail: %s\n", cli->email);
        printf("Data de nascimento: %s\n", cli->data);
    }
    printf("\n\nTecle ENTER para continuar!\n");
    getchar();
}

void regravarCliente(Cliente* cli) {
    FILE* fp = fopen("Cliente.dat", "r+b");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo para atualização!\n");
        return;
    }
    Cliente* cliLido = (Cliente*) malloc(sizeof(Cliente));
    int achou = 0;
    while (fread(cliLido, sizeof(Cliente), 1, fp) && !achou) {
        if (strcmp(cliLido->cpf, cli->cpf) == 0) {
            achou = 1;
            fseek(fp, -1 * sizeof(Cliente), SEEK_CUR);
            fwrite(cli, sizeof(Cliente), 1, fp);
        }
    }
    fclose(fp);
    free(cliLido);
}

void verificar_arquivo_cliente(void) {
    FILE *fp = fopen("Cliente.dat", "rb");
    if (fp == NULL) { 
        fp = fopen("Cliente.dat", "wb");
        if (fp == NULL) {
            printf("Erro: Não foi possível criar o arquivo Cliente.dat.\n");
            exit(1);
        }
        printf("Arquivo Cliente.dat criado com sucesso!\n");
    }
    fclose(fp);
}


void atualizarDadosCliente(Cliente* cli) {
    if (cli == NULL) {
        printf("\nErro: Cliente não encontrado ou inválido!\n");
        return;
    }

    printf("\nAtualizando dados do cliente (CPF: %s):\n", cli->cpf);

    do {
        printf(" Nome (%s): ", cli->nome);
        scanf("%50[^\n]", cli->nome);
        getchar();
    } while (!validar_nome(cli->nome));
    for (int i = 0; cli->nome[i] != '\0'; i++) {
        cli->nome[i] = toupper(cli->nome[i]);
    }

    do {
        printf(" Telefone (%s): ", cli->tele);
        scanf("%12[^\n]", cli->tele);
        getchar();
    } while (!validar_telefone(cli->tele));

    do {
        printf(" E-mail (%s): ", cli->email);
        scanf("%30[^\n]", cli->email);
        getchar();
    } while (!validar_email(cli->email));

    do {
        printf(" Data de nascimento (%s): ", cli->data);
        scanf("%10[^\n]", cli->data);
        getchar();
    } while (!validar_data(cli->data));

    printf("\nDados do cliente atualizados com sucesso!\n");
}
