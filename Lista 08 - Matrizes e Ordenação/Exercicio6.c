#include <stdio.h>
#define MAX 8

void contar_tipo_pecas(int tabuleiro[][MAX], int *pecas);
void contar_pecas(int tabuleiro[][MAX], int *peoes, int *bispos, int *ausencia);

int main() {
    int tabuleiro[MAX][MAX] = {
        {1, 3, 0, 5, 4, 0, 2, 1},
        {1, 0, 1, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 6, 0},
        {1, 0, 0, 1, 1, 0, 0, 1},
        {0, 1, 0, 4, 0, 0, 1, 0},
        {0, 0, 3, 1, 0, 0, 1, 1},
        {1, 0, 6, 6, 0, 0, 1, 0},
        {1, 0, 5, 0, 1, 1, 0, 6}
    };
    int peoes, bispos, ausencia;
    contar_pecas(tabuleiro, &peoes, &bispos, &ausencia);
    printf("Soma total de peoes e bispos: %d\n", peoes + bispos);
    printf("Quantidade de posicoes com ausencia de pecas: %d\n", ausencia);
    int pecas[7] = {};
    contar_tipo_pecas(tabuleiro, pecas);
    printf("Peoes: %d\n", pecas[1]);
    printf("Cavalos: %d\n", pecas[2]);
    printf("Torres: %d\n", pecas[3]);
    printf("Bispos: %d\n", pecas[4]);
    printf("Rainhas: %d\n", pecas[5]);
    printf("Reis: %d\n", pecas[6]);

    return 0;
}

void contar_pecas(int tabuleiro[][MAX], int *peoes, int *bispos, int *ausencia) {
    *peoes = 0;
    *bispos = 0;
    *ausencia = 0;

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            int peca = tabuleiro[i][j];
            if (peca == 1 || peca == 2) {
                *peoes += 1;
            } else if (peca == 4) {
                *bispos += 1;
            } else if (peca == 0) {
                *ausencia += 1;
            }
        }
    }
}

void contar_tipo_pecas(int tabuleiro[][MAX], int *pecas) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            int peca = tabuleiro[i][j];
            pecas[peca]++;
        }
    }
}