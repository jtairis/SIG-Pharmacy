//Nesse arquivo estarão contidas todas as funções relacionadas ao Módulo Produtos 


#include <stdio.h>
#include <stdlib.h>

//Funções para mostrar telas
int tela_menu_produto(void) {
    int op;
    printf("\n");
    system("clear||cls");
    printf("-------------------------------------------------------------------------- \n");
    printf("                                                                           \n");
    printf("          = = = = = Sistema de Gestão SIG-PHARMACY = = = = =               \n");
    printf("                                                                           \n");
    printf("---------------------------------------------------------------------------\n");
    printf("                                                                           \n");
    printf("                = = = = = Módulo Produtos = = = = =                        \n");
    printf("                                                                           \n");
    printf("           1. Cadastrar novo produto                                       \n");
    printf("           2. Pesquisar produto                                            \n");
    printf("           3. Atualizar produto                                            \n");
    printf("           4. Excluir produto                                              \n");
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

void tela_cadastrar_produto(void) {
    char nomeproduto [30];
    char codigo [8];
    char validade [11];
    char valor [8];
    char descricao [30];


    system("clear||cls");
    printf("---------------------------------------------------------------------------\n");
    printf("                                                                           \n");
    printf("          = = = = = Sistema de Gestão SIG-PHARMACY = = = = =               \n");
    printf("                                                                           \n");
    printf("---------------------------------------------------------------------------\n");
    printf("                                                                           \n");
    printf("               = = = = = Cadastrar Novo Produto = = = = =                  \n");
    printf("                                                                           \n");
    getchar();
    printf("          Nome do produto: ");
    scanf("%s 29[A-ZAÁÉÍÓÚÇÃÕ a-zéíóúãõç]", nomeproduto);
    getchar();
    printf("          Código: ");
    scanf("%s 7[0-9]", codigo);
    getchar();
    printf("          Data de validade (dd/mm/aaaa): ");
    scanf("%10s[0-9/]", validade);
    getchar();
    printf("          Valor: ");
    scanf("%7s", valor);
    getchar();
    printf("          Descrição: ");
    scanf("%29s[A-ZAÁÉÍÓÚÇÃÕ a-zéíóúãõç]", descricao);
    getchar();
    printf("\n");
    printf("---------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...");
    getchar();
}

void tela_pesquisar_produto(void) {
    char codigo [8];

    system("clear||cls");
    printf("\n");
    printf("---------------------------------------------------------------------------\n");
    printf("                                                                           \n");
    printf("          = = = = = Sistema de Gestão SIG-PHARMACY = = = = =               \n");
    printf("                                                                           \n");
    printf("---------------------------------------------------------------------------\n");
    printf("                                                                           \n");
    printf("                 = = = = = Pesquisar Produto = = = = =                     \n");
    printf("                                                                           \n");
    getchar();
    printf("       Digite o código do produto para pesquisar: ");
    scanf("%s 7[0-9]", codigo);
    getchar();
    printf("                                                                           \n");
    printf("---------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...");
    getchar();
}

void tela_atualizar_produto(void) {
    char codigo [8];

    system("clear||cls");
    printf("\n");
    printf("---------------------------------------------------------------------------\n");
    printf("                                                                           \n");
    printf("          = = = = = Sistema de Gestão SIG-PHARMACY = = = = =               \n");
    printf("                                                                           \n");
    printf("---------------------------------------------------------------------------\n");
    printf("                                                                           \n");
    printf("                  = = = = = Atualizar Produto = = = = =                    \n");
    printf("                                                                           \n");
    getchar();
    printf("          Digite o código para atualizar o produto: ");
    scanf("%s 7[0-9]", codigo);
    getchar();
    printf("                                                                           \n");
    printf("---------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...");
    getchar();
}

void tela_excluir_produto(void) {
    char codigo [8];
    
    system("clear||cls");
    printf("\n");
    printf("---------------------------------------------------------------------------\n");
    printf("                                                                           \n");
    printf("          = = = = = Sistema de Gestão SIG-PHARMACY = = = = =             \n");
    printf("                                                                           \n");
    printf("---------------------------------------------------------------------------\n");
    printf("                                                                           \n");
    printf("                  = = = = = Excluir Produto = = = = =                      \n");
    printf("                                                                           \n");
    getchar();
    printf("            Digite o código para excluir o produto: ");
    scanf("%s 7[0-9]", codigo);
    getchar();
    printf("                                                                           \n");
    printf("---------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...");
    getchar();
}