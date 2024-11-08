#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include <ctype.h>
#include <string.h>

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
