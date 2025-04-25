#include <stdio.h>
#include <stdlib.h>

typedef struct Livro {
    int ano;
    char titulo[100];
    char autor[100];
    int nVolume; // Número de exemplares de um dado livro.
    float preco;
}Livro;

typedef struct Biblioteca {
    Livro **V; // Armazena a informação de n livros !!
    int nLivros // Número de livros existentes na biblioteca.
}Biblioteca;

Livro * fillLivro();
Biblioteca * fillBiblioteca(int numLivros);
void valorBiblioteca(Biblioteca * b1, int numLivros);
Livro * maiorBiblioteca(Biblioteca * b1, int numLivros);

int main () {
    int numLivros;
    printf("Digite o numero de livros na biblioteca: ");
    scanf("%d", &numLivros);
    Biblioteca *biblioteca = fillBiblioteca(numLivros);
    valorBiblioteca(biblioteca, numLivros);
    Livro *livroMaior = maiorBiblioteca(biblioteca, numLivros);
    printf("Ano: %d\n", livroMaior->ano);
    printf("Titulo: %s\n", livroMaior->titulo);
    printf("Autor: %s\n", livroMaior->autor);
    printf("Numero de exemplares: %d\n", livroMaior->nVolume);
    printf("Preco: %.f\n", livroMaior->preco);
    for (int i = 0; i < numLivros; i++) {
        free(biblioteca->V[i]);
    }
    free(biblioteca);

    return 0;
}

Livro * fillLivro() {
    Livro *livro = (Livro*) malloc(sizeof(Livro));
    printf("Digite o ano do livro: \n");
    scanf("%d", &livro->ano);
    printf("Digite o titulo do livro: \n");
    scanf(" %100[^\n]", livro->titulo);
    printf("Digite o autor do livro: \n");
    scanf(" %100[^\n]", livro->autor);
    printf("Digite o numero de exemplares do livro: \n");
    scanf("%d", &livro->nVolume);
    printf("Digite o preço do livro: \n");
    scanf("%f", &livro->preco);

    return livro;
}

Biblioteca * fillBiblioteca(int numLivros) {
    Biblioteca *biblioteca = (Biblioteca*) malloc(sizeof(Biblioteca));
    biblioteca->nLivros = numLivros;
    biblioteca->V = (Livro**) malloc(numLivros * sizeof(Livro*));
    for (int i = 0; i < numLivros; i++) {
        biblioteca->V[i] = fillLivro();
    }
    return biblioteca;
}

void valorBiblioteca(Biblioteca * b1, int numLivros) {
    float valorTotal = 0.0;
    for (int i = 0; i < numLivros; i++) {
        valorTotal += b1->V[i]->preco * b1->V[i]->nVolume;
    }
    printf("O valor total da biblioteca é: %.2f\n", valorTotal);
}

Livro * maiorBiblioteca(Biblioteca * b1, int numLivros) {
    Livro *maiorLivro = b1->V[0];
    for (int i = 1; i < numLivros; i++) {
        if (b1->V[i]->nVolume > maiorLivro->nVolume) {
            maiorLivro = b1->V[i];
        }
    }
    return maiorLivro;
}