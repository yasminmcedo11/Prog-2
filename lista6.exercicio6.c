#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int main () {
    int *v, n, i, j, i1 = 0, i2 = 0, repetido, *rpt;
    printf("Digite o numero de valores no vetor\n");
    scanf("%d", &n);
    v = (int*) malloc(n*(sizeof(int)));
    if (v == NULL) {
        printf("Memoria Insuficiente");
        exit(1);
    }
    printf("Digite os valores de v (dentro do intervalo de 0 a 9): \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    rpt = (int*) malloc (n*(sizeof(int)));
    if (rpt == NULL) {
        printf("Memoria Insuficiente");
        exit(1);
    }
    for (i = 0; i < n; i++) {
        repetido = 0;
        for (j = i + 1; j < n; j++) {
            if (v[j] == v[i]) {
                repetido = 1;
                break;
            }
        }
        if (repetido) {
            int encontrado = 0;
            for (j = 0; j < i1; j++) {
                if (v[i] == rpt[j]) {
                    encontrado = 1;
                    break;
                }
            }
            if (!encontrado) {
                rpt[i2] = v[i];
                i1++;
                i2++;
            }
        }
    }
    printf("n = %d\n", i1);
    for (i = 0; i < i1; i++) {
        if (i == i1-1) {
            printf(" %d", rpt[i]);
        }
        else {
            printf(" %d,", rpt[i]);
        }
    } 
    free(v);
    free(rpt);
    return 0;
}