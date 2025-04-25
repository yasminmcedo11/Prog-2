#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno {
    int matricula;
    float *vNotas; // Armazena as 5 notas de um aluno ao longo de um ano.
    char nome[100];
}Aluno;

typedef struct Materia {
    Aluno *V; // Armazena a informação de n alunos !!
    float media[5]; // Armazena as 5 médias do ano.
    int nAlunos // Número de alunos matriculados no curso.
}Materia;

Aluno* fillAluno();
Materia* fillMateria(int numAlunos);
void mediaMateria(Materia *m1);
void mostraMateria(Materia *m1);

int main () {
    int numAlunos;
    printf("Digite o numero de alunos: ");
    scanf("%d", &numAlunos);
    Materia *materia = fillMateria(numAlunos);
    mediaMateria(materia);
    mostraMateria(materia);
    for (int i = 0; i < numAlunos; i++) {
        free(materia->V[i].vNotas);
    }
    free(materia);

    return 0;
}

Aluno* fillAluno() {
    Aluno *aluno = (Aluno*) malloc(sizeof(Aluno));
    printf("Digite a matrícula do aluno: ");
    scanf("%d", &aluno->matricula);
    printf("Digite o nome do aluno: ");
    scanf(" %100[^\n]", aluno->nome);
    aluno->vNotas = (float*) malloc(5 * sizeof(float));
    for (int i = 0; i < 5; i++) {
        printf("Digite a nota %d: ", i + 1);
        scanf("%f", &aluno->vNotas[i]);
    }
    return aluno;
}

Materia* fillMateria(int numAlunos) {
    Materia *materia = (Materia*) malloc(sizeof(Materia));
    materia->nAlunos = numAlunos;
    materia->V = (Aluno*) malloc(numAlunos * sizeof(Aluno));
    for (int i = 0; i < numAlunos; i++) {
        materia->V[i] = *fillAluno();
    }
    return materia;
}

void mediaMateria(Materia *m1) {
    for (int i = 0; i < 5; i++) {
        float soma = 0;
        for (int j = 0; j < m1->nAlunos; j++) {
            soma += m1->V[j].vNotas[i];
        }
        m1->media[i] = soma / m1->nAlunos;
    }
}

void mostraMateria(Materia *m1) {
    for (int i = 0; i < m1->nAlunos; i++) {
        printf("Aluno %d:\n", i + 1);
        printf("Matricula: %d\n", m1->V[i].matricula);
        printf("Nome: %s\n", m1->V[i].nome);
        printf("Notas:\n");
        for (int j = 0; j < 5; j++) {
            printf("Nota %d: %.2f\n", j + 1, m1->V[i].vNotas[j]);
        }
    }
    for (int i = 0; i < 5; i++) {
        printf("Média prova %d: %.2f\n", i + 1, m1->media[i]);
    }
}