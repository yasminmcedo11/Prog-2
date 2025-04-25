#include <stdio.h>
#define MAX 20

/*Faça um programa que imprima os n primeiros termos da série de Fibonacci*/

int main () {
    int n, i, serie[MAX];
    do {
       printf("Digite o numero de termos da serie: \n");
       scanf("%d", &n); 
    } while (n < 0);
    
    for (i = 1; i <= n; i++) {
        if (i == 1) {
            serie[i] = 1;
        }
        else if (i == 2) {
            serie[i] = 1;
        }
        else {
            serie[i] = serie[i-1] + serie[i-2];
        }   
    }
    for (i = 1; i <= n; i++) {
        printf(" %d", serie[i]);
    }
    return 0;
}