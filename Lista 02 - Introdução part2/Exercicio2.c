#include <stdio.h>

/*Fazer um programa para calcular a soma dos primeiros n numeros impares*/

int main () {
    int n, i;
    int soma = 0;
    int impar = 1;
    do {
       printf("Digite um numero: \n");
       scanf("%d", &n); 
    } while (n < 0);
    for (i = 1; i <= n; i++) {
        soma += impar; 
        impar += 2;
    }
    printf("O total da soma e %d", soma);

    return 0; 
}