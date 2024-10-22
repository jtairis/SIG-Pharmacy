#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "produtos.h"     //inclusão da biblioteca "produtos.h"

/////
// Assinatura das funções
int tela_menu_principal(void);
int tela_menu_informacoes(void);
void tela_equipe(void);
void tela_sobre(void);
int tela_menu_cliente(void);
void tela_cadastrar_cliente(void);
void tela_pesquisar_cliente(void);
void tela_atualizar_cliente(void);
void tela_excluir_cliente(void);
int tela_menu_venda(void);
void tela_cadastrar_venda(void);
void tela_pesquisar_venda(void);
int tela_menu_relatorio(void);

/////
// Programa principal
int main(void) {

    setlocale(LC_ALL, "Portuguese");
    int opcao;
    int op_produtos;
    int op_clientes;
    int op_vendas;
    int op_informacoes;
    int op_relatorio;
    do{
        opcao = tela_menu_principal();

        switch(opcao){
            case 1: 
            do{
                op_produtos = tela_menu_produto();

                switch (op_produtos){
                    case 1:
                    tela_cadastrar_produto();
                    break;
                    case 2:
                    tela_pesquisar_produto();
                    break;
                    case 3:
                    tela_atualizar_produto();
                    break;
                    case 4:
                    tela_excluir_produto();
                    break;
                    default:
                    printf("Opção inválida! \n");
                    break;
                }

            }while(op_produtos != 0);
            break;

            case 2: 
            do{
                op_clientes = tela_menu_cliente();

                switch (op_clientes){
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
                    default:
                    printf("Opção inválida!");
                    break;
                }

            }while (op_clientes != 0);
            break;

            case 3: 
            do{
                op_vendas = tela_menu_venda();

                switch (op_vendas){
                    case 1:
                    tela_cadastrar_venda();
                    break;
                    case 2:
                    tela_pesquisar_venda();
                    break;
                    default:
                    printf("Opção inválida!");
                    break;
                }

            }while(op_vendas != 0);
            break;
            
            case 4:
            do{
                op_informacoes = tela_menu_informacoes();

                switch (op_informacoes){
                case 1:
                tela_equipe();
                break;
                case 2:
                tela_sobre();
                break;
                default:
                printf("Opção inválida!");
                break;
            }
            }while(op_informacoes != 0);
            break;

            case 5:
            do{
                op_relatorio = tela_menu_relatorio();
            }while(opcao != 0);
            break;

            default:
            printf("Opção inválida!");
            break;
        }

    }while(opcao != 0);


    return 0;
}

// Funções

int tela_menu_principal(void) {
    int op;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------\n");
    printf("\n");
    printf("                                                                         \n");
    printf("            = = = = = Sistema de Gestão SIG-PHARMACY = = = = =           \n");
    printf("                                                                         \n");
    printf("            1. Módulo Produtos                                           \n");
    printf("            2. Módulo Clientes                                           \n");
    printf("            3. Módulo Vendas                                             \n");
    printf("            4. Módulo Informações                                        \n");
    printf("            5. Módulo Relatório                                          \n");    
    printf("            0. Sair                                                      \n");
    printf("                                                                         \n");
    printf("            Escolha a opção desejada: ");
    scanf("%d", &op);
    getchar();
    printf("                                                                          \n");
    printf("--------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    return op;
}

int tela_menu_informacoes(void) {
    int op;
    printf("\n");
    printf("-------------------------------------------------------------------------- \n");
    printf("                                                                           \n");
    printf("          = = = = = Sistema de Gestão SIG-PHARMACY = = = = =               \n");
    printf("                                                                           \n");
    printf("---------------------------------------------------------------------------\n");
    printf("                                                                           \n");
    printf("                = = = = = Módulo Informações = = = = =                     \n");
    printf("                                                                           \n");
    printf("           1. Equipe                                                       \n");
    printf("           2. Sobre                                                        \n");
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

void tela_equipe(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------\n");
    printf("                                                                         \n");
    printf("            = = = = = Sistema de Gestão SIG-PHARMACY = = = = =           \n");
    printf("                                                                         \n");
    printf("            Este projeto foi desenvolvido por:                           \n");
    printf("                                                                         \n");
    printf("            Dupla: Julia Costa e Juliany Tairis                          \n");
    printf("            E-mail: juliajs.costa@gmail.com | Julianytairis04@gmail.com  \n");
    printf("            Git: https://github.com/jtairis/SIG-Pharmacy.git             \n");
    printf("            Este projeto teve como base o Sistema De Gestão Escolar      \n");
    printf("            disponibilizado pelo professor Flavius Gorgonio.             \n");
    printf("                                                                         \n");
    printf("-------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
} 

void tela_sobre(void) {
    system("clear||cls");
    printf("\n");
    printf("------------------------------------------------------------------------------------\n");
    printf("                    UNIVERSIDADE FEDERAL DO RIO GRANDE DO NORTE               \n");
    printf("                      CENTRO DE ENSINO SUPERIOR DO SERIDÓ                     \n");
    printf("                     DEPARTAMENTO DE COMPUTAÇÃO E TECNOLOGIA                  \n");
    printf("                       BACHARELADO EM SISTEMAS DE INFORMAÇÃO                  \n");
    printf("                        DISCIPLINA: DCT-1106 -- PROGRAMAÇÃO                   \n");
    printf("                           PROFESSOR: FLAVIUS GORGÔNIO                        \n");
    printf("                            CAICÓ-RN, Setembro de 2024                        \n");
    printf("                                                                              \n");
    printf("               = = = = = Sistema de Gestão SIG-Pharmacy = = = = =             \n");
    printf("                                                                              \n");
    printf("     >> O que é?                                                              \n");
    printf("        O projeto SIG-Pharmacy consiste no desenvolvimento de um sistema de   \n");
    printf("        computador que realiza a gestão de uma farmácia, armazenando dados de \n");
    printf("        clientes, dos medicamentos e produtos comercializados, além da gestão \n");
    printf("        das vendas e outros serviços prestados por farmácias ou drogarias     \n");
    printf("        convencionais. O projeto faz parte da disciplina DCT-1106 - Programa- \n");
    printf("        ção, ministrada pelo docente Flavius Gorgônio, no 2º período do curso \n");
    printf("        de Bacharelado em Sistemas de Informação, pela UFRN (CERES), durante o\n");
    printf("        semestre de 2024.2, sendo desenvolvido por estudantes da disciplina.  \n");
    printf("------------------------------------------------------------------------------------\n");
    printf("     >> Como é desenvolvido?                                                  \n");
    printf("        Para o desenvolvimento do projeto, é utilizada a linguagem de progra- \n");
    printf("        mação C, linguagem compilada, relativamente simples e acessível. Du-  \n");
    printf("        rante o semestre de 2024.2, o projeto será dividido em várias etapas: \n");
    printf("        a cada semana, serão implementadas novas partes do programa, com no-  \n");
    printf("        vas funcionalidades, buscando o aprimoramento contínuo do sistema.    \n");
    printf("------------------------------------------------------------------------------------\n");
    printf("     >> O que se espera do projeto?                                           \n");
    printf("        Espera-se que o sistema do projeto atinja sua finalidade: garantir uma\n");
    printf("        boa gestão de uma farmácia, proporcionando uma boa e eficiente experi-\n");
    printf("        ência em sua utilização. Também espera-se que, ao término do projeto, \n");
    printf("        os alunos envolvidos possam ter ampliado suas habilidades práticas de \n");
    printf("        programação, aprendido mais sobre o uso da linguagem C, sobre planeja-\n");
    printf("        mento e gerenciamento de projetos, além de poderem ter conquistado ha-\n");
    printf("        bilidades essenciais, como foco, organização, paciência, disciplina,  \n");
    printf("        pontualidade, comunicação e trabalho em equipe.                       \n");
    printf("                                                              Atenciosamente, \n");
    printf("                                                          os Desenvolvedores. \n");
    printf("------------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...");
    getchar();
}
//Clientes
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
    char nome [51];
    char data [11];
    char cpf [12];
    char tele [12];
    char email [30];

    system("clear||cls");
    printf("\n");
    printf("---------------------------------------------------------------------------\n");
    printf("                                                                           \n");
    printf("          = = = = = Sistema de Gestão SIG-PHARMACY = = = = =               \n");
    printf("                                                                           \n");
    printf("---------------------------------------------------------------------------\n");
    printf("                                                                           \n");
    printf("               = = = = = Cadastrar Novo Cliente = = = = =                  \n");
    printf("                                                                           \n");
    getchar();
    printf("          Nome Completo: ");
    scanf("%50[A-ZAÁÉÍÓÚÇÃÕ a-zéíóúãõç]", nome);
    getchar();
    printf("          Data de nascimento (dd/mm/aaaa): ");
    scanf("%10[0-9/]", data);
    getchar();
    printf("          CPF (somente números): ");
    scanf("%11s", cpf);
    getchar();
    printf("          Telefone: ");
    scanf("%12[0-9]", tele);
    getchar();
    printf("          Email: ");
    scanf("%29[a-z@.]", email);
    getchar();
    printf("\n");
    printf("---------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...");
    getchar();
}

void tela_pesquisar_cliente(void) {
    char cpf [12];

    system("clear||cls");
    printf("\n");
    printf("---------------------------------------------------------------------------\n");
    printf("                                                                           \n");
    printf("          = = = = = Sistema de Gestão SIG-PHARMACY = = = = =               \n");
    printf("                                                                           \n");
    printf("---------------------------------------------------------------------------\n");
    printf("                                                                           \n");
    printf("                = = = = = Pesquisar Cliente = = = = =                      \n");
    printf("                                                                           \n");
    printf("      Digite o CPF do cliente para pesquisar (apenas números): ");
    scanf("%11s", cpf);
    getchar();
    printf("                                                                           \n");
    printf("---------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...");
}

void tela_atualizar_cliente(void) {
    char cpf [12];
    system("clear||cls");
    printf("\n");
    printf("---------------------------------------------------------------------------\n");
    printf("                                                                           \n");
    printf("          = = = = = Sistema de Gestão SIG-PHARMACY = = = = =               \n");
    printf("                                                                           \n");
    printf("---------------------------------------------------------------------------\n");
    printf("                                                                           \n");
    printf("               = = = = = Atualizar Dados de Cliente = = = = =              \n");
    printf("                                                                           \n");
    printf("          Digite o CPF: ");
    scanf("%11s", cpf);
    getchar();
    printf("                                                                           \n");
    printf("---------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...");
    getchar();
}

void tela_excluir_cliente(void) {
    char cpf [12];
    system("clear||cls");
    printf("\n");
    printf("---------------------------------------------------------------------------\n");
    printf("                                                                           \n");
    printf("          = = = = = Sistema de Gestão SIG-PHARMACY = = = = =               \n");
    printf("                                                                           \n");
    printf("---------------------------------------------------------------------------\n");
    printf("                                                                           \n");
    printf("                   = = = = = Excluir Cliente = = = = =                     \n");
    printf("                                                                           \n");
    printf("          Digite o CPF para excluir o cliente: ");
    scanf("%11s", cpf);
    getchar();
    printf("                                                                           \n");
    printf("---------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...");
    getchar();
}

//telas referentes ao módulo vendas
int tela_menu_venda(void) {
    int op;
    printf("\n");
    printf("-------------------------------------------------------------------------- \n");
    printf("                                                                           \n");
    printf("          = = = = = Sistema de Gestão SIG-PHARMACY = = = = =               \n");
    printf("                                                                           \n");
    printf("---------------------------------------------------------------------------\n");
    printf("                                                                           \n");
    printf("                 = = = = = Módulo Vendas = = = = =                         \n");
    printf("                                                                           \n");
    printf("           1. Cadastrar Venda                                              \n");
    printf("           2. Pesquisar Venda                                              \n");
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
    char cpf [12];
    char codigo [8];

    system("clear||cls");
    printf("---------------------------------------------------------------------------\n");
    printf("                                                                           \n");
    printf("          = = = = = Sistema de Gestão SIG-PHARMACY = = = = =               \n");
    printf("                                                                           \n");
    printf("---------------------------------------------------------------------------\n");
    printf("                                                                           \n");
    printf("               = = = = = Cadastrar Nova Venda = = = = =                    \n");
    printf("                                                                           \n");
    getchar();
    printf("          CPF do cliente: ");
    scanf("%11s", cpf);
    getchar();
    printf("          Código do rémedio: ");
    scanf("%7[0-9]", codigo);
    getchar();
    printf("                                                                           \n");
    printf("\n");
    printf("---------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...");
    getchar();
}

void tela_pesquisar_venda(void) {
    char cpf [12];

    system("clear||cls");
    printf("\n");
    printf("---------------------------------------------------------------------------\n");
    printf("                                                                           \n");
    printf("          = = = = = Sistema de Gestão SIG-PHARMACY = = = = =               \n");
    printf("                                                                           \n");
    printf("---------------------------------------------------------------------------\n");
    printf("                                                                           \n");
    printf("                 = = = = = Pesquisar Venda = = = = =                       \n");
    printf("                                                                           \n");
    getchar();
    printf("       Digite o CPF do cliente que efetuou a compra: ");
    scanf("%11s", cpf);
    getchar();
    printf("                                                                           \n");
    printf("---------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...");
    getchar();
}

int tela_menu_relatorio(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------- \n");
    printf("                                                                           \n");
    printf("          = = = = = Sistema de Gestão SIG-PHARMACY = = = = =               \n");
    printf("                                                                           \n");
    printf("---------------------------------------------------------------------------\n");
    printf("                                                                           \n");
    printf("                 = = = = = Módulo Relatório = = = = =                      \n");
    printf("                                                                           \n");
    printf("           1. Relatório de Produtos                                        \n");
    printf("           2. Relatório de Clientes                                        \n");
    printf("           3. Relatório de Vendas                                          \n");
    printf("           0. Voltar ao Menu Principal                                     \n");
    printf("                                                                           \n");
    printf("           Digite o número da sua opção:                                   \n");
    printf("                                                                           \n");
    printf("---------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...");
}
