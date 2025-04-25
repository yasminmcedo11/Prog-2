#include <stdio.h>
#define MAX 20

float media (int n, float *v);

int main () {
    float med, v[MAX];
    int n, i;
    printf("Digite a quantidade de numeros armazenados: \n");
    scanf("%d", &n);
    for (i = 0; i <= n-1; i++) {
        scanf("%f", &v[i]);
    }
    med = media (n, v);
    printf("A media e igual a %f", med);
    return 0;
}

float media (int n, float *v) {
    float med;
    int i;
    for (i = 0; i <= n; i++) {
        med = med + v[i];
    }
    med = med/n;

    return med;
}