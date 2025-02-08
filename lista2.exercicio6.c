#include <stdio.h>
#include <stdlib.h>

int main () {
    int a, n, qtd_tentativas = 0;
    do {
       printf("Tente acertar o numero sorteado. Digite um numero de 0 a 100\n");
       scanf("%d", &a); 
    } while ((a < 0) || (a > 100));
    srand(time(NULL));
    n = rand()%100;
    while (a != n) {
        qtd_tentativas += 1;
        if (a > n) {
            printf("O numero sorteado e menor\n");
        }
        else {
            printf("O numero sorteado e maior\n");
        }
        scanf("%d", &a);
    }
    printf("Numero encontrado! Sua quantidade de tentativas foi %d", qtd_tentativas+1);

    return 0;
}