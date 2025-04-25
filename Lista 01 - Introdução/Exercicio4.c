#include <stdio.h>

/*Receber 1 operação (+,-,*,/) e 2 números e imprimir o resultado da operação*/

float calcular_media (float a, float b, float c);

int main () {
    float a, b, c, media;
    do {
       printf("Digite suas 3 notas: ");
       scanf("%f %f %f", &a, &b, &c); 
    } while ((a < 0) || (b < 0) || (c < 0));
    
    media = calcular_media(a, b, c);
    if (media >= 6.0f) {
        printf("Esta aprovado.\n");
    }
    if ((media < 6.0f) && (media >= 4.0f)) {
        printf("Esta de VS.\n");
    }
    if (media < 4.0f) {
        printf("Esta reprovado.");
    }

    return 0;
}

float calcular_media (float a, float b, float c) {
    float media;
    media = (a+b+c)/3;

    return media;
}