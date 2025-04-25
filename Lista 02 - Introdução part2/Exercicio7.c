#include <stdio.h>

int main () {
    int h, v, salario;
    printf("Digite o numero de horas trabalhadas e o valor da hora trabalhada: \n");
    scanf("%d %d", &h, &v);
    if (h <= 40) {
        salario = h * v;
    }
    if ((h > 40) && (h <= 60)) {
        salario = h * v * 1.5;
    }
    if (h > 60) {
        salario = h * v * 2;
    }
    printf("O salario semanal e %d", salario);

    return 0;
}