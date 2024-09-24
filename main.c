#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

/////
// Assinatura das funções
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


// Funções

void tela_menu_principal(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------\n");
    printf("\n");
    printf("                                                                         \n");
    printf("            = = = = = Sistema de Gestão SIG-PHARMACY = = = = =           \n");
    printf("                                                                         \n");
    printf("            1. Módulo Produtos                                           \n");
    printf("            2. Módulo Vendas                                             \n");
    printf("            3. Módulo Clientes                                           \n");
    printf("            4. Módulo Informações                                        \n");
    printf("            0. Sair                                                      \n");
    printf("                                                                         \n");
    printf("            Escolha a opção desejada: ");
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
    printf("        ção, ministrada pelo docente Flavius Gorgônio, no 2° período do curso \n");
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