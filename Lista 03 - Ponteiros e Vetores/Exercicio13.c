#include <stdio.h>

int main () {
    int a, b, c, d;
    float e, f, g, h;
    char v[10];
    int x;
    int *p = &a;
    printf("Incremento de p = %d e seu endereco %d",(*p)++, &p);

    return 0;
}