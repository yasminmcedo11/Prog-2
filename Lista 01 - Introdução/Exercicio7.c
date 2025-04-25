#include <stdio.h>
#include <math.h>

int main () {
    float a = 3.2f, arredonda_baixo, arredonda_cima;
    arredonda_baixo = floor(a);
    arredonda_cima = ceil(a);
    printf("arredonda para cima = %f; arredonda para baixo = %f", arredonda_cima, arredonda_baixo);

    return 0;
}