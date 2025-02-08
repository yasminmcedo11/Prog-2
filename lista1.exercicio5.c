#include <stdio.h>

/*Definir as variaveis para obter todas as respostas possivies de c*/
int calcular_inteiros (int a, int b);
float calcular_c_float (int a, int b);
float calcular_floats (float a2, float b2);

int main () {
    int a, b, c1;
    float b2, c2, c3, a2; 
    
    c1 =  calcular_inteiros (a, b);
    c2 = calcular_c_float (a, b);
    c3 = calcular_floats (a2, b2);
    printf("O resultado da conta se ambos a, b e c foram inteiros: %d\n", c1);
    printf("O resultado da conta se apenas a e b forem inteiros: %f\n", c2);
    printf("O resultado se todos os numeros forem do tipo float: %f\n", c3);

    return 0;
}

int calcular_inteiros (int a, int b) {
    int c1;
    a = 3;
    b = a/2;
    c1 = b + 3.1;
    return c1;
}

float calcular_c_float (int a, int b) {
    float c2;
    a = 3;
    b = a/2;
    c2 = b + 3.1f;
    return c2;
}

float calcular_floats (float a2, float b2) {
    float c3;
    a2 = 3.0;
    b2 = a2/2;
    c3 = b2 + 3.1f;
    return c3;
}