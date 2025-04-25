#include <stdio.h>
#include <stdlib.h>

int* repeticao (int *vet, int tam, int *n);

int main () {
    int *vet, i, tam, *rpt, n;
    printf("Digite o numero de valores no vetor\n");
    scanf("%d", &tam);
    vet = (int*) malloc(tam*(sizeof(int)));
    if (vet == NULL) {
        printf("Memoria Insuficiente");
        exit(1);
    }
    printf("Digite os valores de v (dentro do intervalo de 0 a 9): \n");
    for (i = 1; i <= tam; i++) {
        scanf("%d", &vet[i]);
    }
    rpt = repeticao (vet, tam, &n);
    printf("n = %d\n", n);
    for (i = 0; i < n; i++) {
        if (i == n-1) {
            printf("|%d|", rpt[i]);
        }
        else {
            printf("|%d", rpt[i]);
        }
    }
    free(vet);
    free(rpt);

    return 0;
}

int* repeticao (int *vet, int tam, int *n) {
    int i, j, *rpt, i1 = 0, repetido, i2 = 0;
    rpt = (int*) malloc (tam*(sizeof(int)));
    if (rpt == NULL) {
        printf("Memoria Insuficiente");
        exit(1);
    }
    for (i = 0; i < tam; i++) {
        repetido = 0;
        for (j = i + 1; j < tam; j++) {
            if (vet[j] == vet[i]) {
                repetido = 1;
                break;
            }
        }
        if (repetido) {
            int encontrado = 0;
            for (j = 0; j < i1; j++) {
                if (vet[i] == rpt[j]) {
                    encontrado = 1;
                    break;
                }
            }
            if (!encontrado) {
                rpt[i2] = vet[i];
                i1++;
                i2++;
            }
        }
    }
    *n = i1;
    return rpt;
}