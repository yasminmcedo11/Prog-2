#include <stdio.h>

int calcular_soma (int numeros[], int tamanho);

int main () {
    int soma_impares;
    int numeros[] = {10, 2, 15, 8, 5, 9, 23, 91, 35};
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);
    soma_impares = calcular_soma(numeros, tamanho);
    printf("A soma dos numeros impares no vetor e: %d\n", soma_impares);

    return 0;
}

int calcular_soma (int numeros[], int tamanho) {
    int soma = 0;
    if (tamanho == 0) {
        return 0;
    }
    if (numeros[tamanho-1]%2 != 0) {
        soma = numeros[tamanho-1];
    }
    return soma + calcular_soma(numeros, tamanho - 1);
}
