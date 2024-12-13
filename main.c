#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "produtos.h"     //inclusão da biblioteca "produtos.h"
#include "clientes.h"    //inclusão da biblioteca "clientes.h"
#include "vendas.h"      //inclusão da biblioteca "vendas.h"
#include "informacoes.h"  //inclusão da biblioteca "informacoes.h"
#include "relatorios.h"   //inclusão da biblioteca "relatorios.h"
#include "valida.h"       //inclusão da biblioteca "valida.h"

// Assinatura das funções

int tela_menu_principal(void);
void tela_final(void);



int main(void){
    char opcao;
    do{
        opcao=tela_menu_principal();
        switch (opcao){
        case '1': menu_produto();
            break;
        case '2': menu_cliente();
            break;
        case '3': menu_venda();
            break;
        case '4': menu_informacoes();
            break;
        case '5': menu_relatorio();
            break;
        }
    }while ((opcao!='0'));
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

void tela_final(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------- \n");
    printf("                                                                           \n");
    printf("    = = = = = Obrigado por utilizar o sistema SIG-PHARMACY! = = = = =      \n");
    printf("\n");
    printf("-------------------------------------------------------------------------- \n");
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para encerrar o sistema!");
    getchar();
}

