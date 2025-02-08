#include <stdio.h>
#define MAX 20

float max_vet (int n, float *vet);

int main () {
    int n, i;
    float v[MAX], maior;
    printf("Digite a quantidade de numeros armazenados: \n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%f", &v[i]);
    }
    maior = max_vet(n, v);
    printf("O maior numero armazenado no vetor e %f", maior);

    return 0;
}

float max_vet (int n, float *vet) {
    int i;
    float maior;
    for (i = 0; i <= n; i++) {
        if (i == 0) {
            maior = vet[i];
        }
        if (vet[i] > maior) {
            maior = vet[i];
        }
    }
    return maior;
}