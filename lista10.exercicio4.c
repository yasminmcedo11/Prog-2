#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void remove_comentarios(char* nome_arquivo);

int main() {
    char nome_arquivo[100];
    printf("Digite o nome do arquivo .c: ");
    scanf("%s", nome_arquivo);
    remove_comentarios(nome_arquivo);
    printf("Arquivo gerado sem os comentarios: output.c\n");

    return 0;
}

void remove_comentarios(char* nome_arquivo) {
    FILE* arquivo_entrada = fopen(nome_arquivo, "r");
    FILE* arquivo_saida = fopen("output.c", "w");
    if (arquivo_entrada == NULL || arquivo_saida == NULL) {
        printf("ERRO: Não foi possível abrir os arquivos.\n");
        exit(1);
    }
    char linha[1000];
    char* comentario;
    while (fgets(linha, sizeof(linha), arquivo_entrada) != NULL) {
        comentario = strstr(linha, "//");
        if (comentario == NULL) {
            fputs(linha, arquivo_saida);
        }
    }
    fclose(arquivo_entrada);
    fclose(arquivo_saida);
}