#include <stdio.h>

typedef struct {
    int matricula;
    char nome[81];
    float media;
} ALUNO;

void ordena (ALUNO turma[], int tam);

int main () {
    ALUNO turma[] = {{ 1, "Yasmin", 8.5 }, { 2, "Lucas", 7.8 }, { 3, "Pedro", 9.2 }, { 4, "Julia", 6.7 }};
    int tamanho = sizeof(turma) / sizeof(turma[0]);
    for (int i = 0; i < tamanho; i++) {
        printf("Matricula: %d, Nome: %s, Média: %.2f\n", turma[i].matricula, turma[i].nome, turma[i].media);
    }
    ordena(turma, tamanho);
    for (int i = 0; i < tamanho; i++) {
        printf("Matricula: %d, Nome: %s, Média: %.2f\n", turma[i].matricula, turma[i].nome, turma[i].media);
    }
    return 0;
}

void ordena (ALUNO turma[], int tam) {
    int i, foraOrdem , jaOrdenados = 0;
    ALUNO temp;
    do {
        foraOrdem = 0;
        for (i = 0; i < 4 - 1 - jaOrdenados ; i++) {
            if (turma[i]. media > turma[i+1]. media) {
                temp = turma[i];
                turma[i] = turma[i+1];
                turma[i+1] = temp ;
                foraOrdem = 1;
            }
        }
        jaOrdenados ++;
    } while (foraOrdem);
}