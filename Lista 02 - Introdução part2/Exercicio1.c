#include <stdio.h>

//Fazer um programa para descobrir se um numero e primo

int main() {
    int numero, divisores = 0;

    printf("Digite o numero que deseja analisar: \n");
    scanf("%d", &numero);

    for (int i = 1; i <= numero; i++) {
        if (numero % i == 0) {
            divisores++;
        }
    }
    
    if(divisores <= 2) {
        printf("NUMERO PRIMO");
    } else {
        printf("NUMERO NAO PRIMO");
    }

    return 0;
}