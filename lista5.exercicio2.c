#include<stdio.h>
#include<string.h>

main(void) {
    char texto[]= "foi muito facil";
    int i;
    for (i = 0; texto[i]!='\0'; i++) { /*Laço para ler todos os elementos da cadeia de caracteres*/
        if (texto[i] == ' ')  /*Quando o programa acha uam cedula vazia (espaço) ele encerra o laço*/
            break; 
    }
    /*Dessa forma, i passa a valer 3 e no comando abaixo será incrementado e passará a valer 4*/
    i++; /*agora quando o proximo laço for chamado ele passará a ler os valores a partir da posição 4 do vetor de caracteres*/
    for ( ; texto[i]!='\0'; i++) {
        printf("%c", texto[i]);  /*Ler todos os valores até o \0, que define o fim do vetor*/
    } /*No final imprime a frase "muito facil"*/
}