#include <stdio.h>

/*Fazer um programa para descobrir se um numero e primo*/

int main () {
    int a;
    int i = 0;
    int divisores = 0;
    printf("Digite um numero: \n");
    scanf("%d", &a);
    while (i <= a) {
        i +=1;
        if (a%i == 0) {
            divisores += 1;
        }
    }
    if (divisores > 2) {
        printf("NUMERO NAO PRIMO");
    }
    else {
        printf("NUMERO PRIMO");
    }
    return 0;
}