//Nesse arquivo, estão as assinaturas das funções do arquivo relatorios.c, relacionadas ao Módulo Relatórios

//Assinatura das funções
void modulorelatorio();
int tela_menu_relatorio(void);
void tela_relatorios_produtos(void);
void tela_relatorios_clientes(void);
void tela_relatorios_vendas(void);
void relatorioProdutosPorFaixaPreco(void);
void relatorioGeralProdutos(void);
void relatorioProdutosPorDataValidade(void);
void relatorioProdAlfabetica(void);
void relatorioGeralClientes(void);
void relatorioClientesPorData(void);
void relatorioClientesAlfabetica();
void relatorioGeralVendas(void);
void relatorioVendasPorCliente(void);
void relatorioVendasPorData(void);
int compararClientes(const void* a, const void* b);
void exibirVendasDoCliente(char* cpf, char* nome);
void gerarRelatorioClientesEVendas(void);