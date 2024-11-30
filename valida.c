#include <stdio.h>
#include <string.h>
#include <ctype.h>

int validar_nome(const char *nome) {
    for (int i = 0; nome[i] != '\0'; i++) {
        if (!isalpha(nome[i]) && nome[i] != ' ') {
            return 0;  // Nome inválido
        }
    }
    return 1;  // Nome válido
}

int validar_data(const char *data) {
    if (strlen(data) != 10) return 0;  // Verifica o tamanho
    if (data[2] != '/' || data[5] != '/') return 0;  // Verifica os separadores
    for (int i = 0; i < 10; i++) {
        if (i != 2 && i != 5 && !isdigit(data[i])) {
            return 0;  // Data inválida
        }
    }
    return 1;  // Data válida
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
int validar_codigo(const char *codigo) {
    if (strlen(codigo) != 7) return 0;  // Verifica se o código tem exatamente 7 caracteres
    for (int i = 0; i < 7; i++) {
        if (!isdigit(codigo[i])) return 0;  // Verifica se cada caractere é um número
    }
    return 1; // Código válido
}

// Valida o valor (aceita números e vírgula)
int validar_valor(const char *valor) {
    int ponto_virgula = 0;  // Para controlar se já encontramos uma vírgula

    for (int i = 0; valor[i] != '\0'; i++) {
        if (valor[i] == ',') {
            // Aceita apenas uma vírgula, que deve ser um separador decimal
            if (ponto_virgula) return 0;
            ponto_virgula = 1;
        } else if (!isdigit(valor[i])) {
            return 0;  // Verifica se é um número ou vírgula
        }
    }
    return 1; // Valor válido
}

// Função para validar a descrição (somente letras e espaços)
int validar_descricao(const char *descricao) {
    for (int i = 0; descricao[i] != '\0'; i++) {
        if (!(isalpha(descricao[i]) || descricao[i] == ' ' || strchr("áéíóúçãõàâô", descricao[i]) != NULL)) {
            return 0; // Descrição inválida
        }
    }
    return 1; // Descrição válida
}
