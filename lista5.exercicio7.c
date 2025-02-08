#include <stdio.h>
#include <string.h>

int main () {
    char nome [80], abv [10];
    int i, n = 0;
    printf("Digite seu nome completo\n");
    scanf(" %80[^\n]", nome);
    for (i = 0; nome[i] != '\0' ; i++) {
        if (i == 0) {
            nome[i] = (nome[i] - 'a') + 'A';
            abv[n] = nome[i];
            n++; 
            abv[n] = '.';
            n++;
        }
        if (nome[i] == ' ') {
            nome[i+1] = (nome[i+1] - 'a') + 'A';
            abv[n] = nome[i+1];
            n++;
            abv[n] = '.';
            n++;
        }
    }
    printf("A abreviacao e %s", abv);

    return 0;
}