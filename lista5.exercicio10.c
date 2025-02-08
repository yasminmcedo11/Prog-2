#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main () {
    char nome[9], senha[20], nome2[9], senha2[20], c, c2, c3, c4;
    int i = 0, n = 0, m = 0;
    printf("Digite seu nome: (maximo 8 caracteres)\n");
    while ((c = getchar()) != '\n' && c != EOF && i < 8) {
        if (isalnum(c)) { 
            nome[i] = c;
            i++;
        }
    }
    i = 0;
    printf("Digite sua senha: \n");
    while ((c3 = getchar()) != '\n' && c != EOF && i < 19) {
        if (isalnum(c3)) { 
            senha[i] = c3;
            putchar('*'); 
            i++;
        }
    }
    i = 0;
    printf("Digite novo nome de usuario: (maximo 8 caracteres)\n");
    while ((c2 = getchar()) != '\n' && c != EOF && i < 8) {
        if (isalnum(c2)) { 
            nome2[i] = c2;
            i++;
        }
    }
    i = 0;
    printf("Digite nova senha: \n");
    while ((c4 = getchar()) != '\n' && c != EOF && i < 19) {
        if (isalnum(c4)) { 
            senha2[i] = c4;
            putchar('*'); 
            i++;
        }
    }
    if (strlen(nome) >= strlen(nome2)) {
        for (i = 0; nome[i] != '\0'; i++) {
        if (nome[i] == nome2[i]) {
            n++;
            }
        }
    }
    else {
        for (i = 0; nome2[i] != '\0'; i++) {
        if (nome2[i] == nome[i]) {
            n++;
            }
        }
    }
    if (strlen(senha) >= strlen(senha2)) {
        for (i = 0; senha[i] != '\0'; i++) {
        if (senha[i] == senha2[i]) {
            m++;
            }
        }
    }
    else {
        for (i = 0; senha2[i] != '\0'; i++) {
        if (senha2[i] == senha[i]) {
            m++;
            }
        }
    }
    if (strlen(nome) >= strlen(nome2)) {
        if (strlen(senha) >= strlen(senha2)) {
            if ((n == strlen(nome)) && (m == strlen(senha))) {
                printf("OK\n");
            }    
            else {
                printf("Acesso Negado");
            }
        }
        else {
            if ((n == strlen(nome)) && (m == strlen(senha2))) {
                printf("OK\n");
            }    
            else {
                printf("Acesso Negado");
            }
        }
    }    
    else {
        if (strlen(senha) >= strlen(senha2)) {
            if ((n == strlen(nome2)) && (m == strlen(senha))) {
                printf("OK\n");
            }    
            else {
                printf("Acesso Negado");
            }
        }
        else {
            if ((n == strlen(nome2)) && (m == strlen(senha2))) {
                printf("OK\n");
            }    
            else {
                printf("Acesso Negado");
            }
        }
    }
    return 0;
}