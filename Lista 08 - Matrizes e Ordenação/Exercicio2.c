#include <stdio.h>
void somar_matrizes(int m1[][4], int m2[][4], int resultado[][4], int linhas, int colunas);
void imprimir_matriz(int matriz[][4], int linhas, int colunas);

int main() {
    int m1[][4] = {{1, 2, 3, 4},{5, 6, 7, 8},{9, 10, 11, 12}};
    int m2[][4] = {{2, 1, 1, 1},{2, 1, 3, 2},{1, 4, 1, 2}};
    int resultado[3][4];
    int linhas = 3;
    int colunas = 4;
    somar_matrizes(m1, m2, resultado, linhas, colunas);
    imprimir_matriz(resultado, linhas, colunas);

    return 0;
}

void somar_matrizes(int m1[][4], int m2[][4], int resultado[][4], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            resultado[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

void imprimir_matriz(int matriz[][4], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
    }
}