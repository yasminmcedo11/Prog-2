#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno {
    int matricula;
    char nome[100];
    float nota;
    struct Aluno* prox;
} Aluno;

void imprimirLista(Aluno* inicio);
Aluno* excluirAluno(Aluno* inicio, int matricula);
Aluno* incluirAluno(Aluno* inicio, int matricula, char nome[], float nota);
void alterarNota(Aluno* inicio, int matricula, float novaNota);
void liberarLista(Aluno* inicio);


int main() {
    FILE* arquivo;
    char linha[150];
    int matricula;
    char nome[100];
    float nota;
    Aluno* inicio = NULL;
    arquivo = fopen("alunos.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    while (fgets(linha, sizeof(linha), arquivo)) {
        sscanf(linha, "%d %150[^\t\n] %f", &matricula, nome, &nota);
        inicio = incluirAluno(inicio, matricula, nome, nota);
    }
    fclose(arquivo);
    imprimirLista(inicio);
    inicio = excluirAluno(inicio, 1234);
    alterarNota(inicio, 5678, 9.5);
    imprimirLista(inicio);
    liberarLista(inicio);

    return 0;
}

void imprimirLista(Aluno* inicio) {
    Aluno* atual = inicio;
    while (atual != NULL) {
        printf("Matricula: %d, Nome: %s, Nota: %.f\n", atual->matricula, atual->nome, atual->nota);
        atual = atual->prox;
    }
}

Aluno* excluirAluno(Aluno* inicio, int matricula) {
    Aluno* atual = inicio;
    Aluno* anterior = NULL;
    while (atual != NULL && atual->matricula != matricula) {
        anterior = atual;
        atual = atual->prox;
    }
    if (atual != NULL) {
        if (anterior == NULL) {
            inicio = atual->prox;
        } else {
            anterior->prox = atual->prox;
        }
        free(atual);
        printf("Aluno de matricula %d foi excluido.\n", matricula);
    } else {
        printf("Aluno de matricula %d nao encontrado.\n", matricula);
    }
    return inicio;
}

Aluno* incluirAluno(Aluno* inicio, int matricula, char nome[], float nota) {
    Aluno* novoAluno = (Aluno*)malloc(sizeof(Aluno));
    novoAluno->matricula = matricula;
    strcpy(novoAluno->nome, nome);
    novoAluno->nota = nota;
    novoAluno->prox = NULL;

    // Se a lista estiver vazia, o novo aluno será o primeiro da lista
    if (inicio == NULL) {
        inicio = novoAluno;
    } else {
        Aluno* atual = inicio;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novoAluno;
    }

    printf("Novo aluno adicionado.\n");
    return inicio;
}

// Função para alterar a nota de um aluno na lista
void alterarNota(Aluno* inicio, int matricula, float novaNota) {
    Aluno* atual = inicio;
    int encontrado = 0;

    while (atual != NULL) {
        if (atual->matricula == matricula) {
            atual->nota = novaNota;
            encontrado = 1;
            break;
        }
        atual = atual->prox;
    }
    if (encontrado) {
        printf("Nota do aluno de matricula %d alterada.\n", matricula);
    } else {
        printf("Aluno de matricula %d não encontrado.\n", matricula);
    }
}

void liberarLista(Aluno* inicio) {
    Aluno* atual = inicio;
    while (atual != NULL) {
        Aluno* proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
}
