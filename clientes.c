//Nesse arquivo estarão contidas as funções relacionadas ao Módulo Clientes

#include <string.h>  
#include <stdio.h>
#include <stdlib.h>
#include "valida.h"

typedef struct cliente {
    char nome[51];
    char data[11];
    char cpf[12];
    char tele[12];
    char email[30];
} Cliente;

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

void tela_cadastrar_cliente(Cliente *c) {
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
        scanf("%50[^\n]", c->nome);
        getchar();
        valido = validar_nome(c->nome);
        if (!valido) {
            printf("Nome inválido! Digite novamente.\n");
        }
    } while (!valido);

    do {
        printf("Data de nascimento (dd/mm/aaaa): ");
        scanf("%10[^\n]", c->data);
        getchar();
        valido = validar_data(c->data);
        if (!valido) {
            printf("Data inválida! Digite novamente.\n");
        }
    } while (!valido);

    do {
        printf("CPF (somente números): ");
        scanf("%11[^\n]", c->cpf);
        getchar();
        valido = validar_cpf(c->cpf);
        if (!valido) {
            printf("CPF inválido! Digite novamente.\n");
        }
    } while (!valido);

    do {
        printf("Telefone (com DDD): ");
        scanf(" %11[^\n]", c->tele);
        getchar();
        valido = validar_telefone(c->tele);
        if (!valido) {
            printf("Telefone inválido! Digite novamente.\n");
        }
    } while (!valido);

    do {
        printf("Email: ");
        scanf(" %29[^\n]", c->email);
        getchar();
        valido = validar_email(c->email);
        if (!valido) {
            printf("Email inválido! Digite novamente.\n");
        }
    } while (!valido);
    printf("\nCliente cadastrado com sucesso!\n");
    printf("\n---------------------------------------------------------------------------\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...");
    getchar();
} 


void tela_pesquisar_cliente(Cliente clientes[], int qtdClientes) {
    char cpf[12];
    int encontrado = 0;

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

    for (int i = 0; i < qtdClientes; i++) {
        if (strcmp(clientes[i].cpf, cpf) == 0) {  
            printf("\nCliente encontrado com sucesso:\n");
            printf("Nome: %s\n", clientes[i].nome);
            printf("Data de nascimento: %s\n", clientes[i].data);
            printf("CPF: %s\n", clientes[i].cpf);
            printf("Telefone: %s\n", clientes[i].tele);
            printf("Email: %s\n", clientes[i].email);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\nCliente com CPF %s não encontrado.\n", cpf);
    }
 
    printf("---------------------------------------------------------------------------\n");
    printf(">>> Tecle <ENTER> para continuar...");
    getchar();
}

void tela_atualizar_cliente(Cliente clientes[], int qtdClientes) {
    char cpf[12];
     int encontrado = 0;

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
    } while (!validar_cpf(cpf)); //Solicita e em seguida busca.

    for (int i = 0; i < qtdClientes; i++) {
        if (strcmp(clientes[i].cpf, cpf) == 0) {
            encontrado = 1;

            printf("\nCliente encontrado: %s\n", clientes[i].nome);

            // Atualiza os dados.
            int valido;

            do {
                printf("Novo Nome (atual: %s): ", clientes[i].nome);
                scanf("%50[^\n]", clientes[i].nome);
                getchar();
                valido = validar_nome(clientes[i].nome);
                if (!valido) {
                    printf("Nome inválido! Digite novamente.\n");
                }
            } while (!valido);

            do {
                printf("Nova Data de nascimento (atual: %s): ", clientes[i].data);
                scanf("%10[^\n]", clientes[i].data);
                getchar();
                valido = validar_data(clientes[i].data);
                if (!valido) {
                    printf("Data inválida! Digite novamente.\n");
                }
            } while (!valido);

            do {
                printf("Novo Telefone (atual: %s): ", clientes[i].tele);
                scanf("%11[^\n]", clientes[i].tele);
                getchar();
                valido = validar_telefone(clientes[i].tele);
                if (!valido) {
                    printf("Telefone inválido! Digite novamente.\n");
                }
            } while (!valido);

            do {
                printf("Novo Email (atual: %s): ", clientes[i].email);
                scanf("%29[^\n]", clientes[i].email);
                getchar();
                valido = validar_email(clientes[i].email);
                if (!valido) {
                    printf("Email inválido! Digite novamente.\n");
                }
            } while (!valido);

            printf("\nCliente atualizado com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("\nCliente com CPF %s não encontrado.\n", cpf);
    }

    printf("---------------------------------------------------------------------------\n");
    printf(">>> Tecle <ENTER> para continuar...");
    getchar();
}

void tela_excluir_cliente(Cliente clientes[], int *qtdClientes) {
    if (clientes == NULL || qtdClientes == NULL || *qtdClientes <= 0) {
        printf("Erro: Lista de clientes vazia ou inválida.\n");
        return;
    }

    char cpf[12];
    int encontrado = 0;

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

    for (int i = 0; i < *qtdClientes; i++) {
        if (strcmp(clientes[i].cpf, cpf) == 0) {
            encontrado = 1;

            // Exibe os dados.
            printf("\nCliente encontrado:\n");
            printf("Nome: %s\n", clientes[i].nome);
            printf("Data de nascimento: %s\n", clientes[i].data);
            printf("Telefone: %s\n", clientes[i].tele);
            printf("Email: %s\n", clientes[i].email);

            // Confirmação de exclusão
            char confirmacao;
            printf("Deseja realmente excluir este cliente (S/N)? ");
            scanf(" %c", &confirmacao);
            getchar();

            if (confirmacao == 'S' || confirmacao == 's') {
                for (int j = i; j < (*qtdClientes) - 1; j++) {
                    clientes[j] = clientes[j + 1];
                }
                (*qtdClientes)--; 
                printf("\nCliente excluído com sucesso!\n");
            } else {
                printf("\nOperação cancelada.\n");
            }
            break;
        }
    }

    if (!encontrado) {
        printf("\nCliente com CPF %s não encontrado.\n", cpf);
    }


    printf("---------------------------------------------------------------------------\n");
    printf(">>> Tecle <ENTER> para continuar...");
    getchar();
}
