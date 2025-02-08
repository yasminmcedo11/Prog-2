#include <stdio.h>
#include <string.h>

void contar_vogais (int *qtd_vogais, char *c);

int main () {
    int qtd_vogais;
    char c[81];
    printf("Digite uma palavra\n");
    scanf(" %80[^\n]", c);
    contar_vogais(&qtd_vogais, c);
    printf("A palavra tem %d vogais", qtd_vogais);

    return 0;
}

void contar_vogais (int *qtd_vogais, char *c) {
    int i, n = 0;
    for (i = 0; c[i] != '\0'; i++) {
        if ((c[i] == 'a') || (c[i] == 'e') || (c[i] == 'i') || (c[i] == 'o') || (c[i] == 'u')) {
            *qtd_vogais += 1;
        }
    }
}    