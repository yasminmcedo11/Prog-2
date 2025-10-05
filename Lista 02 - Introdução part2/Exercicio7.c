#include <stdio.h>

float calcula_salario(int h, float v);

int main() {
    int horas;
    float valor_hora, salario;

    printf("Digite o numero de horas trabalhadas e seu valor por hora: \n");
    scanf("%d %f", &horas, &valor_hora);

    salario = calcula_salario(horas, valor_hora);
    printf("O salario e de R$%.2f.\n", salario);


    return 0;
}


float calcula_salario(int h, float v) {
    float salario;
    if (h <= 40) {
        salario = h * v;
    } else if (h > 40 && h <= 60) {
        salario = ((h * v) * 0.5) + (h * v);
    } else if (h > 60) {
        salario = (h * v) * 2;
    }
    
    return salario;
}