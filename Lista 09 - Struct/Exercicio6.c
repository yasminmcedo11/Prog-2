#include <stdio.h>

struct pessoa {
    int codigo;
    char nome[81];
};

typedef struct pessoa Pessoa;

Pessoa* busca(int n, Pessoa** vet, int codigo);

int main() {
    Pessoa pessoa1 = { 1, "João" };
    Pessoa pessoa2 = { 2, "Maria" };
    Pessoa pessoa3 = { 3, "Pedro" };

    Pessoa* pessoas[] = { &pessoa1, &pessoa2, &pessoa3 };
    int tamanho = sizeof(pessoas) / sizeof(pessoas[0]);
    int codigo;
    printf("Digite o código da pessoa: ");
    scanf("%d", &codigo);
    Pessoa* pessoaEncontrada = busca(tamanho, pessoas, codigo);
    if (pessoaEncontrada != NULL) {
        printf("Pessoa encontrada:\n");
        printf("Código: %d\n", pessoaEncontrada->codigo);
        printf("Nome: %s\n", pessoaEncontrada->nome);
    } else {
        printf("Pessoa não encontrada.\n");
    }

    return 0;
}

Pessoa* busca(int n, Pessoa** vet, int codigo) {
    int inicio = 0;
    int fim = n - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (vet[meio]->codigo == codigo) {
            return vet[meio];
        } else if (vet[meio]->codigo < codigo) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return NULL;
}