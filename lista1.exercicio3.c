#include <stdio.h>

/*Receber 1 operação (+,-,*,/) e 2 números e imprimir o resultado da operação*/

int main () {
    float a, b;
    char sinal;
    printf("Digite 2 numeros e 1 sinal para fazer a operacao: ");
    scanf("%f %f %c", &a, &b, &sinal);
    switch (sinal) {
        case '+':
            printf("O resultado conta e %f", a+b);
        break;
        case '-':
            printf("O resultado conta e %f", a-b);
        break;
        case '*':
            printf("O resultado conta e %f", a*b);
        break;
        case '/':    
            printf("O resultado conta e %f", a/b);
        break;
        default:
            printf("Operador Invalido.\n");
        break;    
    }

    return 0;
}