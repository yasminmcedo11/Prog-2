#include <stdio.h>

void inicializarVetorMultiplos(int vetor[], int tamanho, int numero);
void imprimirVetor(int vetor[], int tamanho);

int main() {
    int vetor[10];
    inicializarVetorMultiplos(vetor, 10, 5);
    imprimirVetor(vetor, 10);
    return 0;
}

void inicializarVetorMultiplos(int vetor[], int tamanho, int numero) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = numero * (i + 1);
    }
}

void imprimirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
}







