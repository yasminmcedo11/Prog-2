#include <string.h>
#include <stdlib.h>

struct aluno {
    int mat; /* Matricula do aluno */
    char nome[81]; /* Nome do aluno */
};
typedef struct aluno Aluno;

struct prova {
    Aluno a; /* Aluno que fez a prova */
    float q1, q2, q3, q4; /* Nota em cada questao */
};
typedef struct prova Prova;

int compara(Prova* p1, Prova* p2);
void troca(Prova** p1, Prova** p2);
void ordena(int n, Prova** v);

int main () {
    Aluno aluno1 = { 1, "Maria" };
    Aluno aluno2 = { 2, "Joao" };
    Aluno aluno3 = { 3, "Ana" };
    Prova prova1 = { aluno1, 7.5, 8.0, 7.0, 6.5 };
    Prova prova2 = { aluno2, 6.0, 7.0, 6.5, 7.5 };
    Prova prova3 = { aluno3, 7.5, 7.5, 7.5, 7.5 };
    Prova* provas[] = { &prova1, &prova2, &prova3 };
    int tamanho = sizeof(provas) / sizeof(provas[0]);
    int i;
    float nota_total;

    for (int i = 0; i < tamanho; i++) {
        nota_total = provas[i]->q1 + provas[i]->q2 + provas[i]->q3 + provas[i]->q4;
        printf("Aluno: %s | Nota total: %.2f\n", provas[i]->a.nome, nota_total);
        nota_total = 0;
    }
    ordena(tamanho, provas);
    for (int i = 0; i < tamanho; i++) {
        nota_total = provas[i]->q1 + provas[i]->q2 + provas[i]->q3 + provas[i]->q4;
        printf("Aluno: %s | Nota total: %.2f\n", provas[i]->a.nome, nota_total);
        nota_total = 0;
    }

    return 0;
}

int compara(Prova* p1, Prova* p2) {
    float nota1 = p1->q1 + p1->q2 + p1->q3 + p1->q4;
    float nota2 = p2->q1 + p2->q2 + p2->q3 + p2->q4;

    if (nota1 < nota2) {
        return 1;
    } else if (nota1 > nota2) {
        return 0;
    } else {
        return strcmp(p1->a.nome, p2->a.nome) > 0;
    }
}

void troca(Prova** p1, Prova** p2) {
    Prova* temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void ordena(int n, Prova** v) {
    int fim,i;
    for(fim=n-1; fim>0; fim--)
        for(i=0; i<fim; i++)
            if(compara(v[i],v[i+1]))
                troca(&v[i],&v[i+1]);
}