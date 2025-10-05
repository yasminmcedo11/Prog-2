#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n_escolhido, n_sorteado, qtd_vezes = 0;

    do {
        printf("Digite o numero que deseja escolher: \n");
        scanf("%d", &n_escolhido); 
        srand(time(NULL));
        n_sorteado = rand()%100;
        qtd_vezes++;
        if (n_escolhido > n_sorteado) {
            printf("O numero escolhido e maior que o sorteado. sorteado = %d, escolhido = %d.\n", n_sorteado, n_escolhido);
        }
        if (n_escolhido < n_sorteado) {
            printf("O numero escolhido e menor que o sorteado. sorteado = %d, escolhido = %d.\n", n_sorteado, n_escolhido);
        }
        if (n_escolhido == n_sorteado) { 
            printf("Parabens, voce acertou! Sorteado = %d, escolhido = %d.\n", n_sorteado, n_escolhido);
            printf("Foram %d tentativas!\n", qtd_vezes);
            break;
        }
    } while (1);


    return 1;
}