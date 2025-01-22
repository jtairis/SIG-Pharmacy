#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "produtos.h"
#include "vendas.h"
#include "clientes.h"

int validar_nome(char* nome) {
    return strlen(nome) > 0; // Nome não pode ser vazio
}

int validar_data(char* data) {
    if (strlen(data) != 10) {
        return 0; // Tamanho incorreto
    }
    if (data[2] != '/' || data[5] != '/') {
        return 0; // Formato incorreto
    }

    for (int i = 0; i < 10; i++) {
        if (i != 2 && i != 5 && !isdigit(data[i])) {
            return 0; // Se algum caractere não for número (exceto as barras)
        }
    }

    // Extrai o dia, mês e ano da data
    int dia, mes, ano;
    sscanf(data, "%2d/%2d/%4d", &dia, &mes, &ano);

    // Verifica se o mês está entre 1 e 12
    if (mes < 1 || mes > 12) {
        return 0; // Mês inválido
    }

    // Verifica o número de dias no mês
    int dias_no_mes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // Número de dias por mês
    // Verifica se o ano é bissexto e ajusta fevereiro
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
        dias_no_mes[1] = 29; // Fevereiro tem 29 dias em um ano bissexto
    }

    // Verifica se o dia é válido para o mês
    if (dia < 1 || dia > dias_no_mes[mes - 1]) {
        return 0; // Dia inválido para o mês
    }

    return 1; // Data válida
}

int validar_cpf(const char* cpf) {
    // Verifica se o CPF tem 11 caracteres e se são todos números
    if (strlen(cpf) != 11) {
        printf("Erro: CPF deve ter 11 dígitos.\n");
        return 0; // CPF inválido devido ao número de dígitos
    }

    for (int i = 0; i < 11; i++) {
        if (!isdigit(cpf[i])) {
            printf("Erro: O CPF deve conter apenas números.\n");
            return 0; // CPF inválido devido a caracteres não numéricos
        }
    }

    // Cálculo dos dígitos verificadores
    int soma = 0;
    for (int i = 0; i < 9; i++) {
        soma += (cpf[i] - '0') * (10 - i);
    }
    int primeiro_digito = (soma * 10) % 11;
    if (primeiro_digito == 10) {
        primeiro_digito = 0;
    }

    // Verifica o primeiro dígito verificador
    if (primeiro_digito != (cpf[9] - '0')) {
        printf("Erro: CPF inválido (primeiro dígito verificador).\n");
        return 0; // CPF inválido devido ao primeiro dígito
    }

    // Cálculo do segundo dígito verificador
    soma = 0;
    for (int i = 0; i < 10; i++) {
        soma += (cpf[i] - '0') * (11 - i);
    }
    int segundo_digito = (soma * 10) % 11;
    if (segundo_digito == 10) {
        segundo_digito = 0;
    }

    // Verifica o segundo dígito verificador
    if (segundo_digito != (cpf[10] - '0')) {
        printf("Erro: CPF inválido (segundo dígito verificador).\n");
        return 0; // CPF inválido devido ao segundo dígito
    }

    // Verifica se o CPF já está cadastrado
    if (buscarCliente(cpf) != NULL) {
        printf("Erro: Já existe um cliente cadastrado com este CPF (%s)!\n", cpf);
        return 0; // CPF já existe no cadastro
    }

    // CPF válido e único
    return 1;
}

int validar_telefone(const char *tele) {
    if (strlen(tele) < 10 || strlen(tele) > 11) return 0;
    for (int i = 0; tele[i] != '\0'; i++) {
        if (!isdigit(tele[i])) {
            return 0;  // Telefone inválido
        }
    }
    return 1;  // Telefone válido
}

int validar_email(const char *email) {
    int at_symbol = 0;
    for (int i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@') at_symbol++;
    }
    return (at_symbol == 1);  // Email válido se houver exatamente um '@'
}


// Valida o código (somente números, 7 dígitos)
int validar_codigo(char* codigo) {
    // Verifique se o comprimento do código é exatamente 7 dígitos
    if (strlen(codigo) != 7) {
        printf("Erro: O código deve conter exatamente 7 dígitos.\n");
        return 0; // Código inválido
    }

    // Verifique se o código contém apenas números
    for (int i = 0; codigo[i] != '\0'; i++) {
        if (codigo[i] < '0' || codigo[i] > '9') {
            printf("Erro: O código deve conter apenas números.\n");
            return 0; // Código inválido
        }
    }

    // Verifique se o código já existe no arquivo
    //if (verificarCodigoExistente(codigo)) {
       // printf("Erro: Já existe um produto com o código %s.\n", codigo);
        //return 0; // Código inválido
    //}

    return 1; // Código válido
}

// Valida o valor (aceita números e vírgula)
int validar_valor(float valor) {
    // Verifica se o valor é positivo
    if (valor > 0) {
        return 1; // Valor válido
    } else {
        printf("Erro: O valor deve ser um número positivo.\n");
        return 0; // Valor inválido
    }
}

// Função para validar a descrição (somente letras e espaços)
int validar_descricao(char* descricao) {
    return strlen(descricao) > 0; // Descrição não pode ser vazia
}

int validar_cpf_venda(char* cpf) {
    // Verifica se o CPF tem 11 caracteres e se são todos números
    if (strlen(cpf) != 11) {
        printf("Erro: CPF deve ter 11 dígitos.\n");
        return 0; // CPF inválido devido ao número de dígitos
    }

    for (int i = 0; i < 11; i++) {
        if (!isdigit(cpf[i])) {
            printf("Erro: O CPF deve conter apenas números.\n");
            return 0; // CPF inválido devido a caracteres não numéricos
        }
    }

    // Verifica se o cliente existe
    if (buscarCliente(cpf) == NULL) {
        printf("Erro: Cliente não encontrado!\n");
        return 0; // Cliente não encontrado
    }

    return 1; // CPF válido e cliente encontrado
}

int validar_codigo_venda(char* codigo) {
    // Verifica se o código tem 7 caracteres
    if (strlen(codigo) != 7) {
        printf("Erro: Código de produto deve ter 7 dígitos.\n");
        return 0;
    }

    // Verifica se o código contém apenas números
    for (int i = 0; i < 7; i++) {
        if (!isdigit(codigo[i])) {
            printf("Erro: O código de produto deve conter apenas números.\n");
            return 0;
        }
    }

    // Verifica se o produto existe no estoque
    if (buscarProduto(codigo) == NULL) {
        printf("Erro: Produto não encontrado!\n");
        return 0;
    }

    return 1; // Código válido e produto encontrado
}