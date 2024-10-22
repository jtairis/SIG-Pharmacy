#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "produtos.h"     //inclusão da biblioteca "produtos.h"
#include "clientes.h"    //inclusão da biblioteca "clientes.h"
#include "vendas.h"      //inclusão da biblioteca "vendas.h"
#include "informacoes.h"  //inclusão da biblioteca "informacoes.h"

/////
// Assinatura das funções

int tela_menu_principal(void);
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
