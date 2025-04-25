#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int* aprovados (int n, int *mat, float *notas, int *tam);

int main () {
    int n, mat[MAX], tam, i, *ap;
    float notas[MAX];
    printf("Digite a quantidade de alunos: \n");
    scanf("%d", &n);
    printf("Digite o numero de matricula (contem 3 numeros) e nota correspodente do aluno (nessa exata ordem)\n");
    for (i = 1; i <= n; i++) {
        scanf("%d %f", &mat[i], &notas[i]);
    }
    ap = aprovados (n, mat, notas, &tam);
    printf("tam = %d\n",tam);
    for (i = 0; i <= tam-1; i++) {
        printf(" %d", ap[i]);
    }
    free(ap);
    
    return 0;
}

int* aprovados (int n, int *mat, float *notas, int *tam) {
    int i, *ap, apd = 0, i1 = 0;
    for (i = 1; i <= n; i++) {
        if (notas[i] > 5.0f) {
            apd += 1;
        }
    }
    ap = (int*) malloc (apd*(sizeof(int)));
    if (ap == NULL) {
        printf("Memoria Insuficiente.\n");
        exit(1);
    }
    for (i = 1; i <= n; i++) {
        if (notas[i] > 5.0f) {
            ap[i1] = mat[i];
            i1 += 1;
        }
    }
     
    *tam = apd;

    return ap;
}