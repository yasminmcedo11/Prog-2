#include <stdio.h>

int verifica_soma_linhas(int matriz[][3], int linhas, int colunas);

int main() {
    int matriz[][3] = {{1, 2, 3}, {3,2,1},{2,1,3}};
    int linhas = 3;
    int colunas = 3;
    int verifica;
    verifica = verifica_soma_linhas(matriz, linhas, colunas);
    if (verifica == 1) {
        printf("A soma de todas as linhas e igual.\n");
    }   
    if (verifica == 0) {
        printf("A soma de todas as linhas e diferente.\n");
    }
    return 0;
}

int verifica_soma_linhas(int matriz[][3], int linhas, int colunas) {
    int soma_referencia = 0;
    for (int i = 0; i < colunas; i++) {
        soma_referencia += matriz[0][i];
    }
    for (int i = 1; i < linhas; i++) {
        int soma_linha = 0;
        for (int j = 0; j < colunas; j++) {
            soma_linha += matriz[i][j];
        }
        if (soma_linha != soma_referencia) {
            return 0;
        }
    }

    return 1;
}