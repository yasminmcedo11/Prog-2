#include <stdio.h>
#define MAX 7

int main () {
    int v[MAX], i, x, j = 0, som = 0;
    printf("Digite 7 valores\n");
    for (i = 0; i < MAX; i++) {
        scanf("%d", &v[i]);
    }
    /*Pesquisar no vetor valor*/
    printf("Digite um numero\n");
    scanf("%d", &x);
    for (i = 0; i < MAX; i++) {
        if (v[i] == x) {
            printf("%d\n", i);
            j = 1;
        }
    }
    if ( j == 0) {
        printf("-1\n");
    }
    /*Trocando valores no vetor*/
    for (i = 0; i < MAX; i++) {
        som += v[i];
        v[i] = som;
    }
    for (i = 0; i < MAX; i++) {
        printf(" %d,",v[i]);
    }

    return 0;
}