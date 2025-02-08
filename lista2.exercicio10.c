#include <stdio.h>

int mdc (int x, int y);

int main () {
    int x, y, valor;
    printf("Digite 2 valores: \n");
    scanf("%d %d", &x, &y);
    valor = mdc (x, y);
    printf("O mdc e %d", valor);

    return 0;
}

int mdc (int x, int y) {
    int valor, i;
    if (x > y) {
        for (i = x; i >= 0; i--) {
            if ((x%i == 0) && (y%i == 0)) {
                valor = i;
                break;
            }
        }
    }
    else {
        for (i = y; i >= 0; i--) {
            if ((x%i == 0) && (y%i == 0)) {
                valor = i;
                break;
            }
        }
    }    

    return valor;
}