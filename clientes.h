//Nesse arquivo estão as assinaturas das funções do arquivo clientes.c, relacionadas ao Módulo Clientes

//Assinatura das funções
int tela_menu_cliente(void);
void tela_cadastrar_cliente(void);
void tela_pesquisar_cliente(void);
void tela_atualizar_cliente(void);
void tela_excluir_cliente(void);
// Definição do tipo Cliente
#ifndef CLIENTES_H
#define CLIENTES_H
typedef struct cliente {
    char nome[51];
    char data[11];
    char cpf[12];
    char tele[12];
    char email[30];
} Cliente;
// Declarações de funções que usam o tipo Cliente
void preencheCliente(Cliente*, int);
void exibeCliente(Cliente*, int);
#endif 