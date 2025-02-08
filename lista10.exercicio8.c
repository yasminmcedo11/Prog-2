#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _ALUNO {
    char nome[81];
    float nota1;
    float nota2;
} ALUNO;

void mostrar_alunos_media_maior_6(FILE* arquivo) {
    ALUNO aluno;
    float media;

    fseek(arquivo, 0, SEEK_SET);

    printf("Alunos com média maior que 6.0:\n");

    while (fread(&aluno, sizeof(ALUNO), 1, arquivo) == 1) {
        media = (aluno.nota1 + aluno.nota2) / 2.0;

        if (media > 6.0) {
            printf("Nome: %s\n", aluno.nome);
            printf("Nota 1: %.2f\n", aluno.nota1);
            printf("Nota 2: %.2f\n", aluno.nota2);
            printf("Média: %.2f\n", media);
            printf("---------------------------\n");
        }
    }
}

void incluir_aluno(FILE* arquivo) {
    ALUNO aluno;

    printf("Digite o nome do aluno: ");
    fgets(aluno.nome, sizeof(aluno.nome), stdin);
    aluno.nome[strcspn(aluno.nome, "\n")] = '\0';

    printf("Digite a nota 1 do aluno: ");
    scanf("%f", &aluno.nota1);

    printf("Digite a nota 2 do aluno: ");
    scanf("%f", &aluno.nota2);

    fseek(arquivo, 0, SEEK_END);
    fwrite(&aluno, sizeof(ALUNO), 1, arquivo);

    printf("Aluno incluído com sucesso!\n");
}

void alterar_aluno(FILE* arquivo) {
    char nome[81];
    ALUNO aluno;
    int encontrado = 0;

    printf("Digite o nome do aluno que deseja alterar: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    fseek(arquivo, 0, SEEK_SET);

    while (fread(&aluno, sizeof(ALUNO), 1, arquivo) == 1) {
        if (strcmp(aluno.nome, nome) == 0) {
            encontrado = 1;

            printf("Digite a nova nota 1 do aluno: ");
            scanf("%f", &aluno.nota1);

            printf("Digite a nova nota 2 do aluno: ");
            scanf("%f", &aluno.nota2);

            fseek(arquivo, -sizeof(ALUNO), SEEK_CUR);
            fwrite(&aluno, sizeof(ALUNO), 1, arquivo);

            printf("Aluno alterado com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Aluno não encontrado!\n");
    }
}

void consultar_aluno(FILE* arquivo) {
    char nome[81];
    ALUNO aluno;
    int encontrado = 0;

    printf("Digite o nome do aluno que deseja consultar: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    fseek(arquivo, 0, SEEK_SET);

    while (fread(&aluno, sizeof(ALUNO), 1, arquivo) == 1) {
        if (strcmp(aluno.nome, nome) == 0) {
            encontrado = 1;

            printf("Nome: %s\n", aluno.nome);
            printf("Nota 1: %.2f\n", aluno.nota1);
            printf("Nota 2: %.2f\n", aluno.nota2);
            printf("---------------------------\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Aluno não encontrado!\n");
    }
}

void excluir_aluno(FILE* arquivo) {
    char nome[81];
    ALUNO aluno;
    FILE* arquivo_temp = fopen("temp.bin", "wb");
    int encontrado = 0;

    printf("Digite o nome do aluno que deseja excluir: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    fseek(arquivo, 0, SEEK_SET);

    while (fread(&aluno, sizeof(ALUNO), 1, arquivo) == 1) {
        if (strcmp(aluno.nome, nome) != 0) {
            fwrite(&aluno, sizeof(ALUNO), 1, arquivo_temp);
        } else {
            encontrado = 1;
        }
    }

    fclose(arquivo);
    fclose(arquivo_temp);

    remove("alunos.bin");
    rename("temp.bin", "alunos.bin");

    if (encontrado) {
        printf("Aluno excluído com sucesso!\n");
    } else {
        printf("Aluno não encontrado!\n");
    }
}

int main() {
    FILE* arquivo = fopen("alunos.bin", "ab+");
    if (arquivo == NULL) {
        printf("ERRO: Não foi possível abrir o arquivo alunos.bin\n");
        return 1;
    }

    int opcao;

    do {
        printf("Selecione uma opção:\n");
        printf("1 - Mostrar alunos com média maior que 6.0\n");
        printf("2 - Incluir aluno\n");
        printf("3 - Alterar aluno\n");
        printf("4 - Consultar aluno\n");
        printf("5 - Excluir aluno\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer do teclado

        switch (opcao) {
            case 1:
                mostrar_alunos_media_maior_6(arquivo);
                break;
            case 2:
                incluir_aluno(arquivo);
                break;
            case 3:
                alterar_aluno(arquivo);
                break;
            case 4:
                consultar_aluno(arquivo);
                break;
            case 5:
                excluir_aluno(arquivo);
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }

        printf("\n");
    } while (opcao != 0);

    fclose(arquivo);

    return 0;
}