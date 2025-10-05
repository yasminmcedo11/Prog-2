#include <stdio.h>

int mdc(int x, int y);

int main() {
    int x, y, valor;

    printf("Digite os 2 numeros que deseja calcular o MDC: \n");
    scanf("%d %d", &x, &y);

    valor = mdc(x, y);
    printf("O MDC e %d", valor);

    return 0;
}

int mdc(int x, int y) {
    int valor, menor;

    menor = x;
    if (menor > y) {
        menor = y;
    }

    for (int i = menor; i > 0; i--) {
        if ((x % i == 0) && (y % i == 0)) {
            valor = i;
            return valor;
        }
    }
}