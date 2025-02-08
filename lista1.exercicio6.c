#include <stdio.h>
#include <math.h>

/*Calcular as raízes da equaçao de 2 grau*/
float calcular_delta (float a, float b, float c);
float calcular_raizes (float a, float b, float c, float delta);

int main () {
    float a, b, c, delta, x, x1, x2;
    printf("Passe os valores de parametro da funcao: a, b, c.\n");
    scanf("%f %f %f", &a, &b, &c);
    delta = calcular_delta (a, b, c);
    if (delta > 0) {
        x1 = (-b + sqrt(delta))/2*a;
        x2 = (-b - sqrt(delta))/2*a;
        printf("As raizes da funcao sao; x1 = %f e x2 = %f", x1, x2);
    }
    if (delta == 0) {
        x = (-b + sqrt(delta))/2*a;
        printf("A funcao possui apenas 1 raiz real; x = %f", x);
    }
    if (delta < 0) {
        printf("A funcao nao possui raiz real.");
    }

    return 0;
}

float calcular_delta (float a, float b, float c) {
    float delta;
    delta = (b*b) - (4 * a * c);    
    return delta;
}



