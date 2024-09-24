#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

/////
// Assinatura das fun��es
void tela_menu_principal(void);
void tela_equipe(void);
void tela_sobre(void);

/////
// Programa principal
int main(void) {

    setlocale(LC_ALL, "Portuguese");

    tela_menu_principal();
    tela_equipe();
    tela_sobre();
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
    printf("        ��o, ministrada pelo docente Flavius Gorg�nio, no 2� per�odo do curso \n");
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