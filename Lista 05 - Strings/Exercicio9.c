#include <stdio.h>
#include <string.h>

int main () {
    char nome [20], telefone[12], endereco[80];
    printf("Digite Nome, Endereco e Telefone (nessa exata ordem)\n");
    scanf(" %20[^\n] %80[^\n] %12[^\n]", nome, endereco, telefone);
    nome[strlen(nome)] = ' ';
    strcat(nome, endereco);
    nome[strlen(nome)] = ' ';
    strcat(nome, telefone);
    printf("%s", nome);

    return 0;
}