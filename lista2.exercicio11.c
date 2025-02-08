#include <stdio.h>
#include <math.h>

int main () {
    int a, b, valor;
    printf("Digite 2 numeros inteiros: \n");
    scanf("%d %d", &a, &b);
    valor = pow(a, b);
    printf("O resultado e %d", valor);

    return 0;
}