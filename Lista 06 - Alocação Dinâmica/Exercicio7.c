#include <stdio.h>
#include <stdlib.h>

void repeticao (int *vet, int tam);

int main () {
    int *vet, i, tam;
    printf("Digite o numero de valores no vetor\n");
    scanf("%d", &tam);
    vet = (int*) malloc(tam*(sizeof(int)));
    if (vet == NULL) {
        printf("Memoria Insuficiente");
        exit(1);
    }
    printf("Digite os valores de v (dentro do intervalo de 0 a 9): \n");
    for (i = 0; i < tam; i++) {
        scanf("%d", &vet[i]);
    }
    repeticao (vet, tam); 
    free(vet);

    return 0; 
}

void repeticao (int *vet, int tam) {
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
    printf("n = %d\n", i1);
    for (i = 0; i < i1; i++) {
        if (i == i1-1) {
            printf("|%d|", rpt[i]);
        }
        else {
            printf("|%d", rpt[i]);
        }
    } 
    free(rpt);   
}