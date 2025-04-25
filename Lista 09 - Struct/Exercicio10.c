#include <stdio.h>
#include <string.h>
#define MAX 50

struct aluno {
    int matricula;
    char nome[81];
    float media;
};

void ordena_medias (struct aluno turma[]);
void imprime (struct aluno turma[]);
void le(struct aluno turma[]);

int main (void) {
    struct aluno turma[MAX];
    le(turma);
    puts (" Imprimindo dados lidos da turma.");
    puts (" Digite qualquer coisa para continuar .");
    getchar ();
    imprime (turma);
    ordena_medias( turma );
    puts ("Imprimindo dados ordenados da turma.");
    puts ("Digite qualquer coisa para continuar .");
    getchar ();
    imprime (turma);
    getchar ();
}

void imprime (struct aluno turma[]) {
    for (int i = 0; i < MAX; i++) {
        printf("Aluno %d:\n", i+1);
        printf("Matricula: %d\n", turma[i].matricula);
        printf("Nome: %s\n", turma[i].nome);
        printf("Média: %.2f\n\n", turma[i].media);
    }
}

void ordena_medias (struct aluno turma[]) {
    int foraOrdem, jaOrdenados = 0;
    struct aluno temp;
    do {
        foraOrdem = 0;
        for (int i = 0; i < MAX - 1 - jaOrdenados; i++) {
            if (turma[i].media > turma[i + 1].media) {
                temp = turma[i];
                turma[i] = turma[i + 1];
                turma[i + 1] = temp;
                foraOrdem = 1;
            }
        }
        jaOrdenados++;
    } while (foraOrdem);
}

void le (struct aluno turma[]) {
    printf("Entre com os dados dos alunos: \n");
    for (int i = 0; i < MAX; i++) {
        printf("Aluno %d:\n", i + 1);
        printf("Matricula: ");
        scanf("%d", &turma[i].matricula);
        printf("Nome: ");
        scanf("%s", turma[i].nome);
        printf("Media: ");
        scanf("%f", &turma[i].media);
    }
}

