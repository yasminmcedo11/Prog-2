#include <stdio.h>
#include <stdlib.h>

float calcular_media(float* numeros, int tamanho);

int main() {
    char nome_arquivo[100];
    FILE* arquivo;
    int tamanho = 0;
    float* numeros = NULL;
    float numero;
    float media;
    printf("Digite o nome do arquivo: ");
    scanf("%s", nome_arquivo);
    arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("ERRO: Não foi possível abrir o arquivo.\n");
        return 1;
    }
    while (fscanf(arquivo, "%f", &numero) == 1) {
        tamanho++;
    }
    fseek(arquivo, 0, SEEK_SET);
    numeros = (float*)malloc(tamanho * sizeof(float));
    if (numeros == NULL) {
        printf("ERRO: Falha na alocação de memória.\n");
        return 1;
    }
    for (int i = 0; i < tamanho; i++) {
        fscanf(arquivo, "%f", &numeros[i]);
    }
    media = calcular_media(numeros, tamanho);
    printf("A média dos números é: %.2f\n", media);
    free(numeros);
    fclose(arquivo);

    return 0;
}

float calcular_media(float* numeros, int tamanho) {
    float soma = 0.0;
    for (int i = 0; i < tamanho; i++) {
        soma += numeros[i];
    }

    return soma / tamanho;
}