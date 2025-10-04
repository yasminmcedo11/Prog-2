#include <stdio.h>
#include <math.h>

//Calcular as raízes da equaçao de 2 grau

int main() {
    int a, b, c, delta;

    printf("Digite o valor dos coeficientes a, b, c da funcao: \n");
    scanf("%d %d %d", &a, &b, &c);

    delta = pow(b, 2) - (4*a*c);
    if (delta == 0) {
        double raiz = -b/2*a;
        printf("%.1f e a raiz da funcao.", raiz);
    }
    if (delta > 0) {
        double raiz1 = (-b+sqrt(delta))/(2*a);
        double raiz2 = (-b-sqrt(delta))/(2*a);
        printf("%.1f, %.1f sao as raizes da funcao.", raiz1, raiz2);
    }
    if (delta < 0) {
        printf("A funcao nao possui raizes reais.");
    }

    return 0;
}



