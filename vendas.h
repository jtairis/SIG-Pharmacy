typedef struct {
    int numeroVenda;
    char cpfCliente[12];
    char codigoProduto[8];
    int quantidade;
    float valorTotal;
    char data[11];
    int status;
} Venda;

// Funções principais do módulo vendas
void modulovenda(void);

// Funções de tela
int tela_menu_venda(void);
void tela_cadastrar_venda(void);
void tela_pesquisar_venda(void);
void tela_atualizar_venda(void);
void tela_excluir_venda(void);

// Funções de manipulação de vendas
void gravarVenda(Venda* venda);
Venda* buscarVendaPorNumero(int numeroVenda);
void regravarVenda(Venda* venda);
void excluirVendaLogica(int numeroVenda);
void exibirVenda(const Venda* venda);
int obterNumeroVenda(void);