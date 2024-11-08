#include <stdio.h>
#include <string.h>
#include <ctype.h>

int validar_nome(const char *nome) {
    int i;
    for (i = 0; nome[i] != '\0'; i++) {
        if (!isalpha(nome[i]) && nome[i] != ' ' && nome[i] != 'á' && nome[i] != 'é' && nome[i] != 'í' && 
            nome[i] != 'ó' && nome[i] != 'ú' && nome[i] != 'ã' && nome[i] != 'õ' && nome[i] != 'ç') {
            return 0;
        }
    }
    return strlen(nome) > 0 && strlen(nome) < 51;
}

//fonte:openIA

int validar_data(const char *data) {
    if (strlen(data) != 10 || data[2] != '/' || data[5] != '/') {
        return 0;
    }
    for (int i = 0; i < 10; i++) {
        if ((i != 2 && i != 5) && !isdigit(data[i])) {
            return 0;
        }
    }
    return 1;
}

//fonte:openIA

int validar_cpf(const char *cpf) {
    if (strlen(cpf) != 11) return 0;
    for (int i = 0; i < 11; i++) {
        if (!isdigit(cpf[i])) {
            return 0;
        }
    }
    return 1;
}

//fonte:openIA

int validar_telefone(const char *telefone) {
    int len = strlen(telefone);
    if (len < 10 || len > 11) return 0;  // Considerando formatos com e sem DDD
    for (int i = 0; i < len; i++) {
        if (!isdigit(telefone[i])) {
            return 0;
        }
    }
    return 1;
}

//fonte:openIA

int validar_email(const char *email) {
    int len = strlen(email);
    int arroba = 0, ponto = 0;
    for (int i = 0; i < len; i++) {
        if (email[i] == '@') arroba++;
        if (email[i] == '.') ponto++;
    }
    return arroba == 1 && ponto >= 1 && len < 30;
}

//fonte:openIA