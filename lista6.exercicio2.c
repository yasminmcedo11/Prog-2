#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *compactar(char *s);

int main() {
    char string[] = "   nota do aluno   ";
    char *resultado = compactar(string);
    if (resultado != NULL) {
        printf("Cadeia compactada: %s\n", resultado);
        free(resultado);  
    } else {
        printf("Não foi possivel alocar memoria.\n");
    }
    return 0;
}

char *compactar(char *s) {
    int tamanho = strlen(s);
    int inicio = 0, fim = tamanho - 1;
    while (isspace(s[inicio])) {
        inicio++;
    }
    while (fim >= inicio && isspace(s[fim])) {
        fim--;
    }
    int tamanho_nova_cadeia = fim - inicio + 1;
    char *nova_cadeia = malloc((tamanho_nova_cadeia + 1) * sizeof(char));
    if (nova_cadeia != NULL) {
        strncpy(nova_cadeia, &s[inicio], tamanho_nova_cadeia);
        nova_cadeia[tamanho_nova_cadeia] = '\0';  

        return nova_cadeia;
    } else {
        return NULL;  
    }
}