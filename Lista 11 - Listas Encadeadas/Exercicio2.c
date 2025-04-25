#include <stdio.h>

struct elemento {
    int info; /* Valor inteiro armazenado */
    struct elemento *prox; /* Ponteiro para o próximo elemento */
};
typedef struct elemento Elemento;

Elemento* copia(Elemento* lst) {
     if (lst == NULL) {
        return NULL;
    }
    Elemento* copia_inicio = (Elemento*)malloc(sizeof(Elemento));
    copia_inicio->info = lst->info;
    copia_inicio->prox = NULL;
    Elemento* atual_origem = lst->prox;
    Elemento* atual_copia = copia_inicio;
    while (atual_origem != NULL) {
        Elemento* novo_elemento = (Elemento*)malloc(sizeof(Elemento));
        novo_elemento->info = atual_origem->info;
        novo_elemento->prox = NULL;
        atual_copia->prox = novo_elemento;
        atual_origem = atual_origem->prox;
        atual_copia = atual_copia->prox;
    }
    return copia_inicio;
}