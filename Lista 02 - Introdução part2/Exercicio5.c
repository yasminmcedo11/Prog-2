#include <stdio.h>

int main () {
    int x, z, i, x1, qtd_somada = 1;
    printf("Digite o valor de x e de z, respectivamente\n");
    scanf("%d %d", &x, &z);
    while (z < x) {
        printf("Digite um novo valor para z");
        scanf("%d", &z);
    }
    i = x;
    x1 = x;
    while (x < z) {
        x = x + i;
        i++;
        qtd_somada += 1;
    }
    printf("%d (%d+", qtd_somada, x1);
    for (i = 0; i <= qtd_somada; i++) {
        if (i == 1) {
            x1 = x1 + i;
            printf("%d+", x1);
        }
        else {
            if (i == qtd_somada) {
                x1 += 1;
                printf("%d", x1);
            }
            else {
                x1 += 1;
                printf("%d+", x1);
            }
        }    
    }
    printf("=%d)", x+qtd_somada-1);

    return 0;
}