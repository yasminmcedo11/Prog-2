#include <stdio.h>
#include <stdlib.h>

int main () {
    char letra; 
    char vetorc[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l' , 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int numero, i, letra1; 
    int vetorn[26] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26};
    srand(time(NULL));
    numero = rand()%26;
    printf("Tente acertar a letra sorteada\n");
    scanf("%c", &letra);
    for (i = 1; i <= 26; i++) {
        if (letra == vetorc[i]) {
            letra1 = vetorn[i];
        }
    }
    while (numero != letra1) {
        if (letra1 > numero) {
            printf("A letra sorteada e menor\n");
        }
        else {
            printf("A letra sorteada e maior\n");
        }
        scanf("%c", &letra);
        for (i = 1; i <= 26; i++) {
            if (letra == vetorc[i]) {
                letra1 = vetorn[i];
            }
        }
    }
    printf("Letra encontrada\n");

    return 0;
}
