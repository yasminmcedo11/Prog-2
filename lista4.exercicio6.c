#include <stdio.h>
#include <string.h>
#include <ctype.h>

int valida_mail(char *s);

int main() {
    char email[65];
    printf("Digite a parte local do endereco de email: ");
    scanf("%64s", email);
    if (valida_mail(email)) {
        printf("A parte local do endereco de email e valida.\n");
    } else {
        printf("A parte local do endereco de email a invalida.\n");
    }

    return 0;
}

int valida_mail(char *s) {
    int length = strlen(s);
    if (length < 2 || length > 64) {
        return 0;
    }
    if (!isalpha(s[0])) {
        return 0;
    }
    for (int i = 0; i < length - 1; i++) {
        if (s[i] == '.' && s[i + 1] == '.') {
            return 0;
        }
    }
    if (s[length - 1] == '.') {
        return 0;
    }
    for (int i = 0; i < length; i++) {
        char c = s[i];
        if (!(isalnum(c) || c == '.' || c == '-' || c == '_')) {
            return 0;
        }
    }
    return 1;
}