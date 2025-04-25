#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comparar(const void *a, const void *b);
void ordenar_bolha(char *vetor[], int tamanho);
int particionar(char *vetor[], int inicio, int fim);
void ordenar_quicksort(char *vetor[], int inicio, int fim);

int main () {
    char *vetor[] = {"acai", "pudim", "sorvete", "chocolate", "bolo"};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    /*Metodo Bolha*/
    ordenar_bolha(vetor, tamanho);
    for (int i = 0; i < tamanho; i++) {
        printf("%s ", vetor[i]);
    }
    /*Metodo Quick Sort*/
    ordenar_quicksort(vetor, 0, tamanho - 1);
    for (int i = 0; i < tamanho; i++) {
        printf("%s ", vetor[i]);
    }
    // Funcao QuickSort
    qsort(vetor, tamanho, sizeof(char *), comparar);
    for (int i = 0; i < tamanho; i++) {
        printf("%s ", vetor[i]);
    }

    return 0;
}

int comparar(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

void ordenar_bolha(char *vetor[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (strcmp(vetor[j], vetor[j+1]) > 0) {
                char *temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
            }
        }
    }
}

int particionar(char *vetor[], int inicio, int fim) {
    char *pivo = vetor[fim];
    int i = inicio - 1;
    for (int j = inicio; j <= fim - 1; j++) {
        if (strcmp(vetor[j], pivo) < 0) {
            i++;
            char *temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
        }
    }
    char *temp = vetor[i+1];
    vetor[i+1] = vetor[fim];
    vetor[fim] = temp;

    return i + 1;
}

void ordenar_quicksort(char *vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int pivo = particionar(vetor, inicio, fim);
        ordenar_quicksort(vetor, inicio, pivo - 1);
        ordenar_quicksort(vetor, pivo + 1, fim);
    }
}