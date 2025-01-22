typedef struct cliente Cliente;

typedef struct cliente {
    char nome[51];
    char data[11];
    char cpf[12];
    char tele[12];
    char email[30];
    int status;
}Cliente;

void modulocliente(void);
void cadastrarCliente(void);
void pesquisarCliente(void);
void atualizarCliente(void);
void excluirCliente(void);
int tela_menu_cliente(void);
Cliente* tela_cadastrar_cliente(void);
char* tela_pesquisar_cliente(void);
char* tela_atualizar_cliente(void);
char* tela_excluir_cliente(void);
void gravarCliente(Cliente* clt);
Cliente* buscarCliente(char* cpf);
void exibirCliente(Cliente* clt);
void regravarCliente(Cliente* clt);