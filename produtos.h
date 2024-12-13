

typedef struct produto Produto;

typedef struct produto {
    char nome[51];
    char codigo[8];
    char data[11];
    char valor[12];
    char descricao[101];
    int status;
}Produto;

void moduloproduto(void);
void cadastrarProduto(void);
void pesquisarProduto(void);
void atualizarProduto(void);
void excluirProduto(void);

char menu_produto(void);
Produto* tela_cadastrar_produto(void);
char* tela_pesquisar_produto(void);
char* tela_atualizar_produto(void);
char* tela_excluir_produto(void);

void gravarProduto(Produto* prod);
Produto* buscarProduto(char* codigo);
void exibirProduto(Produto* prod);
void regravarProduto(Produto* prod);


