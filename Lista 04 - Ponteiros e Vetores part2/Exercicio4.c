#include <stdio.h>
#define MAX 10

int testa_PA (int n, int *v);

int main () {
    int v[MAX], n, i, valor;
    printf("Digite a quantidade de numeros no vetor (maior que 3)\n");
    scanf("%d", &n);
    printf("Digite os numeros: \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    valor = testa_PA (n, v);
    printf("%d", valor);
    
    return 0;
}

int testa_PA (int n, int *v) {
    int i, pa, k, valor, chegou = 0;
    for (k = 1; k <= 10; k++) {
        pa = 0; 
        for (i = 0; i < n; i++) {
            if (v[i] == v[0]+(k*i)) {
                pa += 1;
            }
        }   
        if (pa == n) {
        valor = k;
        chegou = 1;
        break;
        } 
    }
    if (chegou == 1) {
        valor = valor;
    }
    else {
        valor = 0;
    }

    return valor;
}