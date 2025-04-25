#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float media(char* mat, char* nome_arquivo);

int main() {
    char matricula[] = "8820324-3";
    char arquivo[] = "notas.txt";
    float avg;
    avg = media(matricula, arquivo);
    if (avg == 1) {
        printf("Matricula nao encontrada.\n");
    } else {
        printf("Media do aluno %s: %.1f\n", matricula, avg);
    }

    return 0;
}

float media(char* mat, char* nome_arquivo) {
    FILE* file = fopen(nome_arquivo, "r");
    if (file == NULL) {
        printf("ERRO: Não foi possível abrir o arquivo.\n");
        exit(1);
    }
    char linha[100];
    char matricula_atual[20];
    float p1, p2, p3;
    while (fgets(linha, sizeof(linha), file) != NULL) {
        if (sscanf(linha, "%s %f %f %f", matricula_atual, &p1, &p2, &p3) == 4) {
            if (strcmp(mat, matricula_atual) == 0) {
                fclose(file);
                return (p1 + p2 + p3) / 3.0;
            }
        }
    }
    fclose(file);
    return 1;
}