#include <stdio.h>

void inicializarVetorAlfabeto(char vetor[], int tamanho);
void imprimirVetor(char vetor[], int tamanho);

int main() {
    char vetor[26];
    inicializarVetorAlfabeto(vetor, 26);
    imprimirVetor(vetor, 26);

    return 0;
}

void inicializarVetorAlfabeto(char vetor[], int tamanho) {
    char letra = 'a';
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = letra;
        letra++;
    }
}

void imprimirVetor(char vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%c ", vetor[i]);
    }
}