#include <stdio.h>

struct elemento {
    float info; /* Valor real armazenado */
    struct elemento *prox; /* Ponteiro para o próximo elemento */
};
typedef struct elemento Elemento;

Elemento* filtra(Elemento *lst, float min, float max) {
    Elemento *atual = lst;
    Elemento *anterior = NULL;
    while (atual != NULL) {
        if (atual->info < min || atual->info > max) {
            Elemento* proximo = atual->prox;
            free(atual);
            if (anterior == NULL) {
                lst = proximo;
            } else {
                anterior->prox = proximo;
            }
            atual = proximo;
        } else {
            anterior = atual;
            atual = atual->prox;
        }
    }
    return lst;
}