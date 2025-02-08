#include <stdio.h>
#define MAX 6

int calcular_distancia_total(int tabela[][MAX], int percurso[], int num_cidades);
void imprimir_tabela_sem_repeticoes(int tabela[][MAX]);
void imprimir_distancia(int tabela[][MAX], int cidade1, int cidade2);
void ler_tabela(int tabela[][MAX]);

int main () {
    int tabela[MAX][MAX];
    int percurso[] = {1, 2, 3, 2, 5, 1, 4};
    int num_cidades = sizeof(percurso) / sizeof(percurso[0]);
    int cidade1, cidade2, distancia_total;
    ler_tabela(tabela);
    do {
        printf("Informe o código das duas cidades (ou 0 para sair): ");
        scanf("%d %d", &cidade1, &cidade2);
        if (cidade1 != 0 && cidade2 != 0) {
            imprimir_distancia(tabela, cidade1, cidade2);
        }
    } while (cidade1 != 0 && cidade2 != 0);
    imprimir_tabela_sem_repeticoes(tabela);
    distancia_total = calcular_distancia_total(tabela, percurso, num_cidades);
    printf("Distância total percorrida: %d km\n", distancia_total);

    return 0;
}

void ler_tabela(int tabela[][MAX]) {
    printf("Informe as distancias entre as cidades (em km):\n");
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            scanf("%d", &tabela[i][j]);
        }
    }
}

int calcular_distancia_total(int tabela[][MAX], int percurso[], int num_cidades) {
    int distancia_total = 0;
    for (int i = 0; i < num_cidades - 1; i++) {
        distancia_total += tabela[percurso[i]-1][percurso[i+1]-1];
    }
    return distancia_total;
}

void imprimir_tabela_sem_repeticoes(int tabela[][MAX]) {
    printf("Tabela de distâncias sem repetições:\n");
    for (int i = 0; i < MAX; i++) {
        for (int j = i + 1; j < MAX; j++) {
            printf("Distancia entre as cidades %d e %d: %d km\n", i+1, j+1, tabela[i][j]);
        }
    }
}
void imprimir_distancia(int tabela[][MAX], int cidade1, int cidade2) {
    printf("Distância entre as cidades %d e %d: %d km\n", cidade1, cidade2, tabela[cidade1-1][cidade2-1]);
}