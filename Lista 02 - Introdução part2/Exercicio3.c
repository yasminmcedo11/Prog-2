#include <stdio.h>
#define MAX 100

//Faça um programa que imprima os n primeiros termos da série de Fibonacci

int main() {
    int n, serie[MAX];

    printf("Digite o numero da soma dos termos que deseja calcular: \n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        if (i == 0 || i == 1) {
            serie[i] = 1;
        } else {
            serie[i] = serie[i-1] + serie[i-2];
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", serie[i]);
    }

    return 0;
}