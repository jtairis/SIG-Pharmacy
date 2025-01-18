#include <stdio.h>
#include <string.h>
#include <ctype.h>

int validar_nome(const char *nome) {
    // Nome não pode estar vazio
    if (strlen(nome) == 0) {
        printf("Erro: O nome não pode estar vazio!\n");
        return 0;
    }

    // Nome deve conter apenas letras e espaços
    for (int i = 0; nome[i] != '\0'; i++) {
        if (!isalpha(nome[i]) && nome[i] != ' ') {
            printf("Erro: O nome deve conter apenas letras!\n");
            return 0;
        }
    }
    return 1;
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
    return 1; // Data no formato correto
}

int validar_cpf(const char *cpf) {
    if (strlen(cpf) != 11) {
        return 0; // CPF inválido, pois não tem 11 caracteres
    }

    for (int i = 0; i < 11; i++) {
        if (!isdigit(cpf[i])) {
            return 0; // Se algum caractere não for número, CPF inválido
        }
    }

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
        return 0; // CPF inválido
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
        return 0; // CPF inválido
    }

    return 1; // CPF válido
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
    // Verificar se o código possui exatamente 7 caracteres numéricos
    if (strlen(codigo) != 7) {
        return 0; // Código inválido
    }
    for (int i = 0; i < 7; i++) {
        if (!isdigit(codigo[i])) {
            return 0; // Se algum caractere não for número
        }
    }
    return 1; // Código válido
}

// Valida o valor (aceita números e vírgula)
int validar_valor(float valor) {
    return valor > 0; // Valor deve ser positivo
}

// Função para validar a descrição (somente letras e espaços)
int validar_descricao(char* descricao) {
    return strlen(descricao) > 0; // Descrição não pode ser vazia
}

