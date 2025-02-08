#include <stdio.h>
#include <string.h>

int repetido (char *cadeia, char c);

int main () {
    int n_repetidos;
    char c;
    char cadeia[] = "abdrehdjchhethfpwuyt";
    printf("Digite uma letra\n");
    scanf("%c", &c);
    n_repetidos = repetido (cadeia, c);
    printf("A quantidade de vezes que o caracter %c se repetiu foi %d.", c, n_repetidos);

    return 0;
}

int repetido (char *cadeia, char c) {
    int i, repetido = 0;
    for (i = 0; cadeia[i] != '\0'; i++) {
        if (cadeia[i] == c) {
            repetido += 1;
        }
    }
    return repetido;
}