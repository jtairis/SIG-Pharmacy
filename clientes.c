//Nesse arquivo estarão contidas as funções relacionadas ao Módulo Clientes

#include <stdio.h>
#include <stdlib.h>
#include "valida.h"

//Funções para mostrar telas
int tela_menu_cliente(void) {
    int op;
    system("clear||cls");
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
    printf("                                                                           \n");
    printf("---------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...");
    return op;
}


void tela_cadastrar_cliente(void) {
    char nome[51];
    char data[11];
    char cpf[12];
    char tele[12];
    char email[30];
    int valido;

    system("clear||cls");
    printf("\n");
    printf("---------------------------------------------------------------------------\n");
    printf("          = = = = Sistema de Gestão SIG-PHARMACY = = = = = \n");
    printf("---------------------------------------------------------------------------\n");
    printf("               = = = = = Cadastrar Novo Cliente = = = = = \n");
    printf("---------------------------------------------------------------------------\n");

    do {
        printf("Nome Completo: ");
        scanf("%50[^\n]", nome);
        getchar();
        valido = validar_nome(nome);
        if (!valido) {
            printf("Nome inválido! Digite novamente.\n");
        }
    } while (!valido);

    do {
        printf("Data de nascimento (dd/mm/aaaa): ");
        scanf("%10s", data);
        getchar();
        valido = validar_data(data);
        if (!valido) {
            printf("Data inválida! Digite novamente.\n");
        }
    } while (!valido);

    do {
        printf("CPF (somente números): ");
        scanf("%11s", cpf);
        getchar();  
        valido = validar_cpf(cpf);
        if (!valido) {
            printf("CPF inválido! Digite novamente.\n");
        }
    } while (!valido);

    do {
        printf("Telefone (com DDD): ");
        scanf("%11s", tele);
        getchar();
        valido = validar_telefone(tele);
        if (!valido) {
            printf("Telefone inválido! Digite novamente.\n");
        }
    } while (!valido);

    do {
        printf("Email: ");
        scanf("%29s", email);
        getchar();
        valido = validar_email(email);
        if (!valido) {
            printf("Email inválido! Digite novamente.\n");
        }
    } while (!valido);

    printf("\nCliente cadastrado com sucesso!\n");
    printf("\n---------------------------------------------------------------------------\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...");
    getchar();
}


void tela_pesquisar_cliente(void) {
    char cpf[12];

    system("clear||cls");
    printf("---------------------------------------------------------------------------\n");
    printf("          = = = = Sistema de Gestão SIG-PHARMACY = = = = = \n");
    printf("---------------------------------------------------------------------------\n");
    printf("                = = = = = Pesquisar Cliente = = = = = \n");
    printf("---------------------------------------------------------------------------\n");

    do {
        printf("Digite o CPF (apenas números): ");
        scanf("%11s", cpf);
        getchar();
        if (!validar_cpf(cpf)) {
            printf("CPF inválido! Digite novamente.\n");
        }
    } while (!validar_cpf(cpf));

    printf("cliente encontrado com sucesso\n");
    printf("---------------------------------------------------------------------------\n");
    printf(">>> Tecle <ENTER> para continuar...");
    getchar();
}

void tela_atualizar_cliente(void) {
    char cpf[12];

    system("clear||cls");
    printf("---------------------------------------------------------------------------\n");
    printf("          = = = = Sistema de Gestão SIG-PHARMACY = = = = = \n");
    printf("---------------------------------------------------------------------------\n");
    printf("               = = = = = Atualizar Dados de Cliente = = = = = \n");
    printf("---------------------------------------------------------------------------\n");

    do {
        printf("Digite o CPF: ");
        scanf("%11s", cpf);
        getchar();
        if (!validar_cpf(cpf)) {
            printf("CPF inválido! Digite novamente.\n");
        }
    } while (!validar_cpf(cpf));

    printf("cliente foi atualizado com sucesso\n");
    printf("---------------------------------------------------------------------------\n");
    printf(">>> Tecle <ENTER> para continuar...");
    getchar();
}

void tela_excluir_cliente(void) {
    char cpf[12];

    system("clear||cls");
    printf("---------------------------------------------------------------------------\n");
    printf("          = = = = Sistema de Gestão SIG-PHARMACY = = = = = \n");
    printf("---------------------------------------------------------------------------\n");
    printf("                   = = = = = Excluir Cliente = = = = = \n");
    printf("---------------------------------------------------------------------------\n");

    do {
        printf("Digite o CPF para excluir o cliente: ");
        scanf("%11s", cpf);
        getchar();
        if (!validar_cpf(cpf)) {
            printf("CPF inválido! Digite novamente.\n");
        }
    } while (!validar_cpf(cpf));

    printf("cliente excluido com sucesso\n");
    printf("---------------------------------------------------------------------------\n");
    printf(">>> Tecle <ENTER> para continuar...");
    getchar();
}
