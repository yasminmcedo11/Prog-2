#include <stdio.h>
#include <string.h>
#define MAX_NOMES 81
#define MAX_TAMANHO 81

int ler_nomes(char nomes[][MAX_TAMANHO]);
float calcular_variancia(char nomes[][MAX_TAMANHO], int tamanho_medio, int quantidade);

int main () {
    char nomes[MAX_NOMES][MAX_TAMANHO];
    int quantidade;
    int tamanho_total = 0;
    float media, variancia;
    quantidade = ler_nomes(nomes);
    for (int i = 0; i < quantidade; i++) {
        tamanho_total += strlen(nomes[i]);
    }
    if (quantidade > 0) {
        media = tamanho_total/quantidade;
        variancia = calcular_variancia(nomes, media, quantidade);
        printf("Media do tamanho dos nomes: %f\n", media);
        printf("Variancia do tamanho dos nomes: %f\n", variancia);
    } else {
        printf("Nenhum nome foi inserido.\n");
    }

    return 0;
}

int ler_nomes(char nomes[][MAX_TAMANHO]) {
    int i = 0, quantidade = 0;
    char nome[MAX_TAMANHO];
    printf("Digite os nomes (digite 'fim' para encerrar):\n");
    while (i < MAX_NOMES) {
        scanf("%s", nome);
        if (strcmp(nome, "fim") == 0) {
            break;
        }
        strcpy(nomes[i], nome);
        i++;
    }
    quantidade = i;
    return quantidade;
}

float calcular_variancia(char nomes[][MAX_TAMANHO], int tamanho_medio, int quantidade) {
    int soma_quadrados = 0;
    float variancia;
    for (int i = 0; i < quantidade; i++) {
        int tamanho = strlen(nomes[i]);
        soma_quadrados += (tamanho - tamanho_medio) * (tamanho - tamanho_medio);
    }
    variancia = soma_quadrados/quantidade;
    return variancia;
}