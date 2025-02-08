#include <stdio.h>

int main () {
    char cadeia[20];
    int i, n = 0;
    printf("Digite uma palavra\n");
    scanf(" %20[^\n]", cadeia);
    for (i = 0; cadeia[i] != '\0'; i++) {
        n++;
    }
    printf("A primeira letra da palavra e '%c', a ultima e '%c' e a quantidade de letras e %d", cadeia[0], cadeia[n-1], n);

    return 0;
}