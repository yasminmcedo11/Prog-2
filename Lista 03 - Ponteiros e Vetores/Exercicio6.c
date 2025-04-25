#include <stdio.h>
#define MAX 20

int maiores (int n, int *vet, int x);

int main () {
    int n, i, qtd_maiores, x;
    int v[MAX];
    printf("Digite a quantidade de numeros armazenados: ; e um valor de parametro: \n");
    scanf("%d %d", &n, &x);
    for (i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
    }
    qtd_maiores = maiores (n, v, x);
    printf("Existe(m) %d numero(s) maior(es) no vetor.", qtd_maiores);

    return 0;
}

int maiores (int n, int *vet, int x) {
    int i, qtd_maiores = 0;
    for (i = 0; i <= n; i++) {
        if (vet[i] > x) {
            qtd_maiores += 1;
        }
    }
    return qtd_maiores;
}