#include <stdio.h>
#include <string.h>
#define MAX 50

int main () {
    char texto[MAX +2], temp ;
    int tam , i;
    gets( texto );
    tam = strlen ( texto );
    for (i = 0; i < tam ; i ++) {
    temp = texto[i];
    texto[i] = texto[ tam -1 - i ];
    texto[strlen(texto) -1 - i] = temp ;
}
    puts ( texto );
    
    return 0;
}

/*Ao por meu nome, o programa imprimiu como resposta o meu nome tambem*/