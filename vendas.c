//Nesse arquivo estão contidas as funções relacionadas ao Módulo Vendas

#include <stdio.h>
#include <stdlib.h>

void modulovenda(void) {
	char opcao;
	do {
		opcao = menu_produto();
		switch(opcao) {
			case '1': 	tela_cadastrar_produto();
						break;
			case '2': 	tela_pesquisar_produto();
						break;
			case '3': 	tela_atualizar_produto();
						break;
			case '4': 	tela_excluir_produto();
						break;
		} 		
	} while (opcao != '0');
}

//Funções de telas
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