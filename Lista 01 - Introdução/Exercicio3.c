#include <stdio.h>

//Receber 1 operação (+,-,*,/) e 2 números e imprimir o resultado da operação

int main() {
    float a, b, resultado;
    char operacao;

    printf("Digite os numeros que deseja incluir na operacao: \n");
    scanf("%f %f", &a, &b);
    printf("Digite a operacao que deseja realizar: \n");
    scanf(" %c", &operacao);

    switch (operacao) {
        case '+':
            resultado = a + b;
            break;
        case '-':
            resultado = a - b;
            break;
        case '*':
            resultado = a * b;
            break;
        case '/':
            resultado = a / b;
            break; 
        default:
            break;
    }

    printf("O resultado e %.2f", resultado);
}