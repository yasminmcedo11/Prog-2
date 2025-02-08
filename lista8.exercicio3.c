#include <stdio.h>

void ler_matriz(int matriz[][4]);
int verificar_simetria(int matriz[][4]);

int main () {
    int linhas = 4, colunas = 4;
    int matriz[linhas][colunas];
    ler_matriz (matriz);
    int simetrica = verificar_simetria(matriz);
    if (simetrica == 1) {
        printf("A matriz e simetrica.\n");
    } if (simetrica == 0) {
        printf("A matriz nao e simetrica.\n");
    }
    return 0;
}

void ler_matriz(int matriz[][4]) {
    printf("Digite os elementos da matriz: (max 4x4)\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
}

int verificar_simetria(int matriz[][4]) {
    int transposta[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            transposta[i][j] = matriz[j][i];
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (matriz[i][j] != transposta[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}