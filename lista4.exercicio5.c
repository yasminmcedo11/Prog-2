#include <stdio.h>

void calcula_corrida (float dist, float *b1, float *b2);

int main () {
    int b1, b2, dist;
    calcula_corrida (dist, &b1, &b2);
    return 0;
}

void calcula_corrida (float dist, float *b1, float *b2) {
    *b1 = 4.95 + (dist*2.5);
    *b2 = 4.95 + (dist*3.0);
}
