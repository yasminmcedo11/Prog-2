#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int* premiados (int n, int *inscr, float *t1, int p1, float *t2, int p2, int *tam);

int main () {
    int i, tam, n, p1, p2, inscr[MAX], *maiores; 
    float t1[MAX], t2[MAX];
    printf("Digite a quantidade de participantes do consurso, os pesos das notas do testes 1 e 2  e suas inscricoes: (nessa exata ordem)\n");
    scanf("%d %d %d", &n, &p1, &p2);
    printf("Digite as notas dos testes e seu numero de inscricao:\n");
    for (i = 1; i <= n; i++) {
        scanf("%f %f %d", &t1[i], &t2[i], &inscr[i]);
    }
    maiores = premiados (n, inscr, t1, p1, t2, p2, &tam);
    printf("tam = %d e o vetor maiores =", tam);
    for (i = 0; i <= tam-1; i++) {
        printf("%d", maiores[i]);
    }
    free(maiores);

    return 0;
}

int* premiados (int n, int *inscr, float *t1, int p1, float *t2, int p2, int *tam) {
    int i, i1 = 0, qtd_maiores = 0, *maiores;
    float med, maior = 0.0f;
    for (i = 1; i <= n; i++) {
        med = ((t1[i]*p1) + (t2[i]*p2)/(p1+p2));
        if (med >= maior) {
            maior = med;
        }
    }
    for (i = 1; i <= n; i++) {
        med = ((t1[i]*p1) + (t2[i]*p2)/(p1+p2));
        if (med == maior) {
            qtd_maiores += 1;
        }
    }
    maiores = (int*) malloc(qtd_maiores*(sizeof(int)));
    if (maiores == NULL) {
        printf("Memoria Insuficiente");
        exit(1);
    }
    for (i = 1; i <= n; i++) {
        med = ((t1[i]*p1) + (t2[i]*p2)/(p1+p2));
        if (med == maior) { 
            maiores[i1] = med;
            i1 += 1;
        }
    }
    *tam = qtd_maiores;

    return maiores;
}