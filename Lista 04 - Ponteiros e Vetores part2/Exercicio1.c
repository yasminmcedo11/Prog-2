#include <stdio.h>
#define MAX 10

int main () {
    int x[MAX], y[MAX], i;
    printf("Digite os 10 valores do vetor x\n");
    for (i = 1; i <= MAX; i++) {
        scanf("%d", &x[i]);
    }
    for (i = 0; i <= MAX-1; i++) {
        y[i] = x[MAX-i];
    }
    printf("O vetor y =");
    for (i = 0; i <= MAX; i++) {
        printf(" %d, ", y[i]);
    }

    return 0;
}