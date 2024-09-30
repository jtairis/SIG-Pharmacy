#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

/////
// Assinatura das fun��es
void tela_menu_principal(void);
void tela_equipe(void);
void tela_sobre(void);
void tela_menu_cliente(void);
void tela_cadastrar_cliente(void);
void tela_pesquisar_cliente(void);

/////
// Programa principal
int main(void) {

    setlocale(LC_ALL, "Portuguese");

    tela_menu_principal();
    tela_equipe();
    tela_sobre();
    tela_menu_cliente();
    tela_cadastrar_cliente();
    tela_pesquisar_cliente();
    return 0;
}


// Fun��es

void tela_menu_principal(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------\n");
    printf("\n");
    printf("                                                                         \n");
    printf("            = = = = = Sistema de Gest�o SIG-PHARMACY = = = = =           \n");
    printf("                                                                         \n");
    printf("            1. M�dulo Produtos                                           \n");
    printf("            2. M�dulo Vendas                                             \n");
    printf("            3. M�dulo Clientes                                           \n");
    printf("            4. M�dulo Informa��es                                        \n");
    printf("            0. Sair                                                      \n");
    printf("                                                                         \n");
    printf("            Escolha a op��o desejada: ");
    scanf("%c", &op);
    getchar();
    printf("                                                                          \n");
    printf("--------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}



void tela_equipe(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------\n");
    printf("                                                                         \n");
    printf("            = = = = = Sistema de Gest�o SIG-PHARMACY = = = = =           \n");
    printf("                                                                         \n");
    printf("            Este projeto foi desenvolvido por:                           \n");
    printf("                                                                         \n");
    printf("            Dupla: Julia Costa e Juliany Tairis                          \n");
    printf("            E-mail: juliajs.costa@gmail.com | Julianytairis04@gmail.com  \n");
    printf("            Git: https://github.com/jtairis/SIG-Pharmacy.git             \n");
    printf("            Este projeto teve como base o Sistema De Gest�o Escolar      \n");
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
    printf("                      CENTRO DE ENSINO SUPERIOR DO SERID�                     \n");
    printf("                     DEPARTAMENTO DE COMPUTA��O E TECNOLOGIA                  \n");
    printf("                       BACHARELADO EM SISTEMAS DE INFORMA��O                  \n");
    printf("                        DISCIPLINA: DCT-1106 -- PROGRAMA��O                   \n");
    printf("                           PROFESSOR: FLAVIUS GORG�NIO                        \n");
    printf("                            CAIC�-RN, Setembro de 2024                        \n");
    printf("                                                                              \n");
    printf("               = = = = = Sistema de Gest�o SIG-Pharmacy = = = = =             \n");
    printf("                                                                              \n");
    printf("     >> O que �?                                                              \n");
    printf("        O projeto SIG-Pharmacy consiste no desenvolvimento de um sistema de   \n");
    printf("        computador que realiza a gest�o de uma farm�cia, armazenando dados de \n");
    printf("        clientes, dos medicamentos e produtos comercializados, al�m da gest�o \n");
    printf("        das vendas e outros servi�os prestados por farm�cias ou drogarias     \n");
    printf("        convencionais. O projeto faz parte da disciplina DCT-1106 - Programa- \n");
    printf("        ��o, ministrada pelo docente Flavius Gorg�nio, no 2 per�odo do curso \n");
    printf("        de Bacharelado em Sistemas de Informa��o, pela UFRN (CERES), durante o\n");
    printf("        semestre de 2024.2, sendo desenvolvido por estudantes da disciplina.  \n");
    printf("------------------------------------------------------------------------------------\n");
    printf("     >> Como � desenvolvido?                                                  \n");
    printf("        Para o desenvolvimento do projeto, � utilizada a linguagem de progra- \n");
    printf("        ma��o C, linguagem compilada, relativamente simples e acess�vel. Du-  \n");
    printf("        rante o semestre de 2024.2, o projeto ser� dividido em v�rias etapas: \n");
    printf("        a cada semana, ser�o implementadas novas partes do programa, com no-  \n");
    printf("        vas funcionalidades, buscando o aprimoramento cont�nuo do sistema.    \n");
    printf("------------------------------------------------------------------------------------\n");
    printf("     >> O que se espera do projeto?                                           \n");
    printf("        Espera-se que o sistema do projeto atinja sua finalidade: garantir uma\n");
    printf("        boa gest�o de uma farm�cia, proporcionando uma boa e eficiente experi-\n");
    printf("        �ncia em sua utiliza��o. Tamb�m espera-se que, ao t�rmino do projeto, \n");
    printf("        os alunos envolvidos possam ter ampliado suas habilidades pr�ticas de \n");
    printf("        programa��o, aprendido mais sobre o uso da linguagem C, sobre planeja-\n");
    printf("        mento e gerenciamento de projetos, al�m de poderem ter conquistado ha-\n");
    printf("        bilidades essenciais, como foco, organiza��o, paci�ncia, disciplina,  \n");
    printf("        pontualidade, comunica��o e trabalho em equipe.                       \n");
    printf("                                                              Atenciosamente, \n");
    printf("                                                          os Desenvolvedores. \n");
    printf("------------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...");
    getchar();
}

void tela_menu_cliente(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------- \n");
    printf("                                                                           \n");
    printf("          = = = = = Sistema de Gest�o SIG-PHARMACY = = = = =               \n");
    printf("                                                                           \n");
    printf("---------------------------------------------------------------------------\n");
    printf("                                                                           \n");
    printf("                = = = = = M�dulo Cliente = = = = =                         \n");
    printf("                                                                           \n");
    printf("           1. Cadastrar novo cliente                                       \n");
    printf("           2. Pesquisar dados de um cliente                                \n");
    printf("           3. Atualizar dados de um cliente                                \n");
    printf("           4. Excluir cliente                                              \n");
    printf("           0. Voltar ao Menu Principal                                     \n");
    printf("                                                                           \n");
    printf("           Digite o n�mero da sua op��o:                                   \n");
    printf("                                                                           \n");
    printf("---------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...");
    getchar();
}

void tela_cadastrar_cliente(void) {
    system("clear||cls");
    printf("\n");
    printf("---------------------------------------------------------------------------\n");
    printf("                                                                           \n");
    printf("          = = = = = Sistema de Gest�o SIG-PHARMACY = = = = =               \n");
    printf("                                                                           \n");
    printf("---------------------------------------------------------------------------\n");
    printf("                                                                           \n");
    printf("               = = = = = Cadastrar Novo Cliente = = = = =                  \n");
    printf("                                                                           \n");
    printf("          Nome Completo:                                                   \n");
    printf("          Data de nascimento (dd/mm/aaaa):                                 \n");
    printf("          CPF (somente n�meros):                                           \n");
    printf("          Telefone:                                                        \n");
    printf("          Email:                                                           \n");
    printf("          Bairro:                                                          \n");
    printf("          Rua:                                                             \n");
    printf("          N� da casa:                                                      \n");
    printf("\n");
    printf("---------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...");
    getchar();
}

void tela_pesquisar_cliente(void) {
    system("clear||cls");
    printf("\n");
    printf("---------------------------------------------------------------------------\n");
    printf("                                                                           \n");
    printf("          = = = = = Sistema de Gest�o SIG-PHARMACY = = = = =               \n");
    printf("                                                                           \n");
    printf("---------------------------------------------------------------------------\n");
    printf("                                                                           \n");
    printf("           = = = = = Pesquisar dados de um Cliente = = = = =               \n");
    printf("                                                                           \n");
    printf("     Digite o CPF do cliente para pesquisar (apenas n�meros):              \n");
    printf("                                                                           \n");
    printf("---------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...");
    getchar();
}