#include <stdio.h>

int main () {
    int n = 1000, p1, p2, num, resultado, i; 
    for (i = 1000; i <= 9000; i++) {
        p1 = n/100;
        p2 = n%100;
        num = p1 + p2;
        resultado = num * num;
        if (resultado == n) {
            printf("%d ", resultado);
        }
        n += 1;
    }

    return 0;
}