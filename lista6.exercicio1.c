#include <stdio.h>
#include <stdlib.h>
#define MAX 20

float* acima_da_media (int n, float *vet, int *tam);

int main () {
    float vet[MAX], *x;
    int i, n, tam;
    printf("Digite o quantidade de notas e os valores das medias (nessa ordem exata)\n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%f", &vet[i]);
    }
    x = acima_da_media(n, vet, &tam);
    printf("tamanho =%d\n", tam);
    printf("o vetor x = ");
    for (i = 0; i <= tam-1; i++) {
        printf(" %f,", x[i]);
    }
    free(x);

    return 0;
}

float* acima_da_media (int n, float *vet, int *tam) {
    float *x, med = 0;
    int i, i1 = 0, m = 0;
    for (i = 1; i <= n; i++) {
        med = med + vet[i];
    }
    med = med/n;
    for (i = 1; i <= n; i++) {
        if (vet[i] > med) {
            m += 1;
        }
    }
    x = (float*) malloc(m*(sizeof(float)));
    if (x == NULL) {
        printf("Memoria Insuficiente.\n");
        exit(1);
    }
    for (i = 1; i <= n; i++) {  
        if (vet[i] > med) {
            x[i1] = vet[i];
            i1 += 1;
        }
    }
    *tam = m;

    return x;
}