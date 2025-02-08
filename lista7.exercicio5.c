#include <stdio.h>
#include <ctype.h>

void criptografarBloco(char bloco[6]);

int main() {
    char linha[81];
    char bloco[6];
    int i, j, k;
    printf("Digite uma linha de caracteres: ");
    fgets(linha, sizeof(linha), stdin);
    j = 0;
    for (i = 0; linha[i] != '\0'; i++) {
        if (!isspace(linha[i])) {
            linha[j] = linha[i];
            j++;
        }
    }
    linha[j] = '\0';
    for (i = 0, k = 0; linha[i] != '\0'; i++) {
        bloco[k] = linha[i];
        k++;
        if (k == 5) {
            bloco[k] = '\0';
            criptografarBloco(bloco);
            printf("%s", bloco);
            k = 0;
        }
    }
    if (k > 0) {
        bloco[k] = '\0';
        criptografarBloco(bloco);
        printf("%s", bloco);
    }

    return 0;
}

void criptografarBloco(char bloco[6]) {
    int i;
    for (i = 0; bloco[i] != '\0'; i++) {
        bloco[i] = bloco[i] + i;
    }
}