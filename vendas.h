typedef struct venda {
    char cpfCliente[12];
    char codigoProduto[8];
    int quantidade;
    float valorTotal;
    char data[11];  // dd/mm/aaaa
} Venda;

void modulovenda(void);
int tela_menu_venda(void);
void tela_cadastrar_venda(void);
void tela_pesquisar_venda(void);
void tela_atualizar_venda(void);
void tela_excluir_venda(void);
void gravarVenda(Venda* venda);
Venda* buscarVenda(char* cpf);
void exibirVenda(Venda* venda);
void regravarVenda(Venda* venda);
void excluirVenda(char* cpf, char* codigo);
void regravarVenda(Venda* venda);