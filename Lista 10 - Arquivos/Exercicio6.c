#include <stdio.h>

int main() {
    int i;
    char nome_arquivo[12];
    for (i = 1; i <= 10; i++) {
        sprintf(nome_arquivo, "teste%02d.txt", i);
        FILE* arquivo = fopen(nome_arquivo, "w");
        if (arquivo == NULL) {
            printf("ERRO: Não foi possível criar o arquivo %s\n", nome_arquivo);
            return 1;
        }
        fprintf(arquivo, "Texto do arquivo [%02d]\n", i);
        fclose(arquivo);
    }
    printf("Os arquivos foram gerados com sucesso.\n");

    return 0;
}