//Nesse arquivo estão contidas as funções relacionadas ao Módulo Informações 


#include <stdio.h>
#include <stdlib.h>
#include "informacoes.h"

void moduloinformacoes(void) {
    int opcao;
    do {
        opcao = tela_menu_informacoes();
        switch(opcao) {
            case 1:
                tela_equipe();
                break;
            case 2:
                tela_sobre(); 
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

//Funções para mostrar telas
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
    getchar();
    printf("\n");
    printf("-------------------------------------------------------------------------\n");
    printf("                                                                         \n");
    printf("            = = = = = Sistema de Gestão SIG-PHARMACY = = = = =           \n");
    printf("                                                                         \n");
    printf("            Este projeto foi desenvolvido por:                           \n");
    printf("                                                                         \n");
    printf("            Grupo: Julia Costa,Juliany Tairis                            \n");
    printf("            Julia Costa,Juliany Tairis                                   \n");
    printf("            leandro e arthur                                             \n");
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
    getchar();
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