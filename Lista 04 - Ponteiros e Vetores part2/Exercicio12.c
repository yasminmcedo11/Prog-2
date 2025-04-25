#include <stdio.h>
#include <string.h>

void remover_caractere(char *string, char caractere);

int main() {
    char string[21];
    char caractere;
    printf("Digite uma string (max 20 caracteres): ");
    scanf("%20s", string);
    printf("Digite um caractere: ");
    scanf(" %c", &caractere);
    remover_caractere(string, caractere);
    printf("%s\n", string);

    return 0;
}

void remover_caractere(char *string, char caractere) {
    int i, j;
    int length = strlen(string);
    for (i = 0, j = 0; i < length; i++) {
        if (string[i] != caractere) {
            string[j] = string[i];
            j++;
        }
    }
    string[j] = '\0';  
}