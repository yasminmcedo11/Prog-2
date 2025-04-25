#include <stdio.h>
#include <conio.h>
#define MAX_FRASE 80

void mostrarPalavras(char frase[]);

int main() {
    char frase[MAX_FRASE];
    char caractere;
    int i = 0;
    printf("Digite uma frase (maximo de %d caracteres):\n", MAX_FRASE);
    do {
        caractere = getch();
        if (caractere != '\r') {
            frase[i] = caractere;
            putchar(caractere);
            i++;
        }
    } while (caractere != '\r' && i < MAX_FRASE - 1);
    frase[i] = '\0';
    mostrarPalavras(frase);

    return 0;
}

void mostrarPalavras(char frase[]) {
    int i = 0;
    while (frase[i] != '\0') {
        if (frase[i] != ' ') {
            putchar(frase[i]);
        } else {
            putchar('\n');
        }
        i++;
    }
}