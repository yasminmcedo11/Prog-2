#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Faça um programa que informe se a letra escolhida é maior, menor ou igual a sorteada

int maior_ou_menor(char l1, char l2);

int main() {
    char letra_escolhida, letra_sorteada;
    int resultado;

    srand(time(NULL)); 
    letra_sorteada = 'a' + rand() % 26;

    printf("Digite a letra que voce acha que sera sorteada: \n");
    scanf(" %c", &letra_escolhida);

    resultado = maior_ou_menor(letra_escolhida, letra_sorteada);
    if (resultado == 0) {
        printf("Parabens, voce acertou a letra sorteada.");
    }
    if (resultado == 1) {
        printf("A letra sorteada e menor que a escolhida. sorteada = %c, escolhida = %c.", letra_sorteada, letra_escolhida);
    }
    if (resultado == -1) {
        printf("A letra sorteada e maior que a escolhida. sorteada = %c, escolhida = %c.", letra_sorteada, letra_escolhida);
    }


    return 0;
}

int maior_ou_menor(char l1, char l2) {
    if (l1 > l2) {
        return 1;
    }
    if (l1 < l2) {
        return -1;
    }
    if (l1 == l2) {
        return 0;
    }
}
