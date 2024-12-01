//Aqui estão as assinaturas das funções do arquivo produtos.c, relacionadas ao Módulo Produtos

//Assinaturas das funções
int tela_menu_produto(void);
void tela_cadastrar_produto(void);
void tela_pesquisar_produto(void);
void tela_atualizar_produto(void);
void tela_excluir_produto(void);

#ifndef PRODUTOS_H
#define PRODUTOS_H

typedef struct produto {
    char nome[51];
    char codigo[8];
    char dataValidade[11];
    char valor[12];
    char descricao[101];
} Produto;

Produto* alocar_produtos(int quantidade);
void liberar_produtos(Produto* produtos);

#endif
