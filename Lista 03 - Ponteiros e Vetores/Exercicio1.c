#include <stdio.h>
#define PI 3.14159265

/*Implementar função para calculo da area e circunferencia de um circulo*/

void calc_circulo (float r, float *circunferencia, float *area);

int main () {
    float r, a, c;
    printf("Digite o valor de raio do circulo: \n");
    scanf("%f", &r);
    calc_circulo(r, &c, &a);
    printf("O valor da area do circulo e %f, e o valor da circunferencia e %f.", a, c);

    return 0;
}

void calc_circulo (float r, float *circunferencia, float *area) {
    *area = PI*(r*r);
    *circunferencia = 2*PI*r;
}