typedef struct produto Produto;

typedef struct produto {
    char nome[51];
    char codigo[8];
    char data[11];
    float valor;
    char descricao[101];
    int status;
}Produto;

void moduloproduto();
void cadastrarProduto();
void pesquisarProduto();
void atualizarProduto();
void excluirProduto();

int tela_menu_produto();
Produto* tela_cadastrar_produto();
char* tela_pesquisar_produto();
char* tela_atualizar_produto();
char* tela_excluir_produto();

void gravarProduto(Produto* prod);
Produto* buscarProduto(char* codigo);
void exibirProduto(Produto* prod);
void regravarProduto(Produto* prod);
int verificarCodigoExistente(char* codigo);

