#include <stdio.h>

int main() {
    int x, x_inicial, z, soma = 0, numeros = 0;

    do {
       printf("Digite os valores de X e Z: \n");
       scanf("%d %d", &x, &z); 
    } while (x > x);
    x_inicial = x;

    while (1) {
        soma += x;
        x++;
        numeros++;
        if (soma >= z) {
            break;
        }
    }

    printf("%d ", numeros);
    for (int i = 0; i < numeros; i++) {
        if (i == 0) {
            printf("(%d+", i+x_inicial);
        } else if (i == numeros-1) {
            printf("%d", i+x_inicial);
        } else {
            printf("%d+", i+x_inicial);
        }
    }
    printf("=%d)", soma);
    
    return 0;
}