#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main () {
    char cadeia[21];
    char *cadeia2;
    int i, m;
    printf("Digite uma string: \n");
    scanf(" %21[^\n]", cadeia);
    cadeia2 = (char*) malloc(strlen(cadeia)*(sizeof(char)));
    if (cadeia2 == NULL) {
        printf("Memoria Insuficiente.");
        exit(1);
    }
    m = strlen(cadeia);
    for (i = 0; m >= 0; i++) {
        cadeia2[i] = cadeia[m];
        m--;
        printf("%c", cadeia2[i]);
    }
    free(cadeia2);

    return 0;
}