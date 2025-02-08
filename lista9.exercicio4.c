#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 4
#define MAXNOME 31

void atribui(char **nomes, int indice, char *nome);
char* get_sobrenome(char *nome);

int main() {
    int i;
    char **nomes;
    char *sobrenome;
    nomes = (char **) malloc(MAX*sizeof(char *));
    for ( i=0 ; i<MAX ; i++) {
    nomes[i] = (char *) malloc(sizeof(char)*MAXNOME);
    }
    atribui(nomes,0,"Fulano Silva"); 
    atribui(nomes,1,"Maria do Carmo");
    atribui(nomes,2,"Beltrano Belmonte"); 
    atribui(nomes,3,"Pedro dos Santos");
    for (i=0 ; i<MAX ; i++) {
        sobrenome = get_sobrenome(nomes[i]);
        printf("\n%s ", sobrenome);
        printf(" %d",strlen(sobrenome)>5?i:0); // 2o printf
    }
    printf("\n%c", nomes[0][3]); // 3o printf

    return 0;
}

void atribui(char **nomes, int indice, char *nome) {
    strcpy(nomes[indice], nome);
}

char* get_sobrenome(char *nome) {
    char *sobrenome = strrchr(nome, ' ');
    if (sobrenome != NULL) {
        return sobrenome + 1;
    }
    return nome;
}   

/*No segundo printf o valor impresso será uma comparacao com o tamanho da string (sobrenome)
Se o tamanho da string for maior qur 5, ele retorna o valor de i(indice do vetor)
Já se o tamanho for menor ou igual, ele retorna 0.

No terceiro printf ele acessa a primeira string armazenada no vetor (1° linha da matriz)
e retorna o 4°[0,1,2,3] caracter dessa string; o "a".*/
