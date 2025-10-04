#include <stdio.h>
#include <math.h>

int main () {
    float a = 3.2f, arredonda_baixo, arredonda_cima;
    arredonda_baixo = floor(a);
    arredonda_cima = ceil(a);
    printf("arredonda para cima = %.2f; arredonda para baixo = %.2f", arredonda_cima, arredonda_baixo);

    return 0;
}