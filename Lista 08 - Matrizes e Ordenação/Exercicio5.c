#include <stdio.h>
#define MAX 10

void multiplicar_matrizes(int matriz1[][MAX], int matriz2[][MAX], int resultado[][MAX], int linhas1, int colunas1, int colunas2);
int somar_diagonais(int matriz[][MAX], int dimensao);
void somar_matrizes(int matriz1[][MAX], int matriz2[][MAX], int resultado[][MAX], int linhas, int colunas);
void imprimir_matriz(int matriz[][MAX], int linhas, int colunas);
void ler_matriz(int matriz[][MAX], int linhas, int colunas);

int main () {
    int matriz1[MAX][MAX], matriz2[MAX][MAX];
    int resultado_soma[MAX][MAX], resultado_multiplicacao[MAX][MAX];
    int linhas, colunas;
    printf("Digite o numero de linhas das matrizes: ");
    scanf("%d", &linhas);
    printf("Digite o numero de colunas das matrizes: ");
    scanf("%d", &colunas);
    ler_matriz(matriz1, linhas, colunas);
    ler_matriz(matriz2, linhas, colunas);
    imprimir_matriz(matriz1, linhas, colunas);
    imprimir_matriz(matriz2, linhas, colunas);
    somar_matrizes(matriz1, matriz2, resultado_soma, linhas, colunas);
    printf("\nResultado da soma das matrizes:\n");
    imprimir_matriz(resultado_soma, linhas, colunas);
    int soma_diagonal1 = somar_diagonais(matriz1, linhas);
    int soma_diagonal2 = somar_diagonais(matriz2, linhas);
    printf("Soma da diagonal da matriz 1: %d\n", soma_diagonal1);
    printf("Soma da diagonal da matriz 2: %d\n", soma_diagonal2);
    multiplicar_matrizes(matriz1, matriz2, resultado_multiplicacao, linhas, colunas, colunas);
    printf("\nResultado da multiplicação das matrizes:\n");
    imprimir_matriz(resultado_multiplicacao, linhas, colunas);

    return 0;
}

void multiplicar_matrizes(int matriz1[][MAX], int matriz2[][MAX], int resultado[][MAX], int linhas1, int colunas1, int colunas2) {
    for (int i = 0; i < linhas1; i++) {
        for (int j = 0; j < colunas2; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < colunas1; k++) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
}

int somar_diagonais(int matriz[][MAX], int dimensao) {
    int soma = 0;
    for (int i = 0; i < dimensao; i++) {
        soma += matriz[i][i];
    }
    return soma;
}

void somar_matrizes(int matriz1[][MAX], int matriz2[][MAX], int resultado[][MAX], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            resultado[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
}

void imprimir_matriz(int matriz[][MAX], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
    }
}

void ler_matriz(int matriz[][MAX], int linhas, int colunas) {
    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
}