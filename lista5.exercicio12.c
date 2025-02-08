#include <stdio.h>
#include <string.h>
#define MAX 51

void calcularEstatisticas(char *string);

int main() {
    char string[MAX];
    printf("Digite uma string (max 50 caracteres): ");
    fgets(string, sizeof(string), stdin);
    calcularEstatisticas(string);

    return 0;
}

void calcularEstatisticas(char *string) {
    int length = strlen(string);
    int i, j;
    int ocorrencias[256] = {};
    for (i = 0; i < length; i++) {
        if (string[i] != ' ') {
            ocorrencias[(int)string[i]]++;
        }
    }
    for (j = 0; j < 256; j++) {
        if (ocorrencias[j] > 0) {
            printf("'%c' = %d\n", (char)j, ocorrencias[j]);
        }
    }
}