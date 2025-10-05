#include <stdio.h>

// Fazer um programa para calcular a soma dos primeiros n numeros impares

int main() {
    int n, n_inicial, soma = 0, i = 1;

    printf("Digite o numero da sequencia que deseja analisar: \n");
    scanf("%d", &n);
    n_inicial = n;

    while (n != 0) {
        if (i % 2 != 0) {
            soma += i;
            n--;
        }
        i++;
    }

    printf("A soma dos primeiros %d numeros e %d.\n", n_inicial, soma);

    return 0;
}