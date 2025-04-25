#include <stdio.h>
#include <string.h>

int comparar_strings (char *palavra1, char *palavra2);
int comparar_substring (char *palavra1, char *palavra2);

int main () {
    char palavra1 [20], palavra2[20];
    int palavra_igual, substring;
    printf("Digite a primeira palavra\n");
    scanf(" %20[^\n]", palavra1);
    printf("Digite a segunda palavra\n");
    scanf(" %20[^\n]", palavra2);
    palavra_igual = comparar_strings (palavra1, palavra2);
    if (palavra_igual == 1) {
        printf("As palavras sao iguais");
    }
    else {
        printf("As palavras sao diferentes\n");
        substring = comparar_substring (palavra1, palavra2);
        if (substring == 1) {
            printf("A segunda palavra e subtring da primeira");
        }
        else {
            printf("As palavras nao sao subtrings");
        }
    }

    return 0;
}

int comparar_strings (char *palavra1, char *palavra2) {
    int i, palavra_igual;
    int tamanho1 = strlen(palavra1);
    int tamanho2 = strlen(palavra2);
    for (i = 0; palavra2[i] != '\0'; i++) {
        if (palavra1[i] == palavra2[i]) {
            tamanho1++; 
        }
    }
    tamanho2 = strlen(palavra1);
    if (tamanho1 == tamanho2) {
        palavra_igual = 1;
    }
    else {
        palavra_igual = 0;
    }

    return palavra_igual;
}

int comparar_substring (char *palavra1, char *palavra2) {
    int substring = strstr(palavra1, palavra2) != NULL; 
    return substring;
}