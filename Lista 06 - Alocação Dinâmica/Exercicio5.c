#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* cifra_cesar(char* msg);

int main() {
    char mensagem[] = "zebra";
    char* mensagem_codificada = cifra_cesar(mensagem);

    if (mensagem_codificada != NULL) {
        printf("Mensagem codificada: %s\n", mensagem_codificada);
        free(mensagem_codificada);  
    } else {
        printf("Não foi possível alocar memoria.\n");
    }

    return 0;
}

char* cifra_cesar(char* msg) {
    int tamanho = strlen(msg), i;
    char* mensagem_codificada = malloc((tamanho + 1) * sizeof(char));
    if (mensagem_codificada == NULL) {
        printf("Memoria Inexistente");
        exit(1);
    }
    for (i = 0; i < tamanho; i++) {
        char caractere = msg[i];
        if (isalpha(caractere)) {  
            char base = islower(caractere) ? 'a' : 'A';  
            char codificado = (caractere - base + 3) % 26 + base;  
            mensagem_codificada[i] = codificado;
        } else {
            mensagem_codificada[i] = caractere; 
            }
        mensagem_codificada[tamanho] = '\0';  
        return mensagem_codificada;
    }    
}
