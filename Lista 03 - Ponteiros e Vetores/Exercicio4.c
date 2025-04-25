#include <stdio.h>

int divs (int n, int *max, int *min);

int main () {
    int n, maior, menor, p;
    printf("Digite um numero: \n");
    scanf("%d", &n);
    p = divs(n, &maior, &menor);
    printf("p = %d, maior = %d, menor = %d", p, maior, menor);

    return 0;
}

int divs (int n, int *max, int *min) {
    int p;
    int divisores1 = 0;
    int i = 0;
    int divisores = 0;
    while (i <= n) {
        i +=1;
        if (n%i == 0) {
            divisores += 1;
            if (divisores == 2) {
                *min = i;
            }
        }
    }    
    if (divisores > 2) {
        p = 1;
        divisores1 = divisores;
        divisores = 0;
        i = 0;
        while (i <= n) {
        i +=1;
        if (n%i == 0) {
            divisores += 1;
            if (divisores == (divisores1-1)) {
                *max = i;
            }
        }
        } 
    }
    else {
        p = 0;
        *max = 0;
        *min = 0;
    }
    return p;
}