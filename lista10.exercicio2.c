#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float busca(char* arquivo, char* matricula);

int main() {
    char arquivo[] = "alunos.txt";
    char matricula[] = "9010087-2";
    float cr ;
    cr = busca(arquivo, matricula);
    if (cr == 1) {
        printf("Matricula nao encontrada.\n");
    } else {
        printf("CR do aluno %s: %.1f\n", matricula, cr);
    }
    return 0;
}

float busca(char* arquivo, char* matricula) {
    FILE* file = fopen(arquivo, "r");
    if (file == NULL) {
        printf("ERRO: Não foi possível abrir o arquivo.\n");
        exit(1);
    }
    char linha[100];
    char matricula_atual[20];
    float cr;
    while (fgets(linha, sizeof(linha), file) != NULL) {
        if (sscanf(linha, "%s %f", matricula_atual, &cr) == 2) {
            if (strcmp(matricula, matricula_atual) == 0) {
                fclose(file);
                return cr;
            }
        }
    }
    fclose(file);
    return 1;
}