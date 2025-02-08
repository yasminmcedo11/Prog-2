#include <stdio.h>
#include <stdlib.h>

int comparar(const void* a, const void* b);

int main() {
    FILE* arquivo_texto = fopen("numeros.txt", "r");
    if (arquivo_texto == NULL) {
        printf("ERRO: Não foi possível abrir o arquivo numeros.txt\n");
        return 1;
    }
    float numeros[1000];
    int quantidade_numeros = 0;
    while (fscanf(arquivo_texto, "%f", &numeros[quantidade_numeros]) == 1) {
        quantidade_numeros++;
    }
    fclose(arquivo_texto);
    qsort(numeros, quantidade_numeros, sizeof(float), comparar);
    FILE* arquivo_binario = fopen("numeros.bin", "wb");
    if (arquivo_binario == NULL) {
        printf("ERRO: Não foi possível criar o arquivo numeros.bin\n");
        return 1;
    }
    fwrite(numeros, sizeof(float), quantidade_numeros, arquivo_binario);
    fclose(arquivo_binario);
    printf("Os números foram ordenados e gravados no arquivo numeros.bin\n");

    return 0;
}

int comparar(const void* a, const void* b) {
    float valor1 = *(float*)a;
    float valor2 = *(float*)b;
    if (valor1 < valor2) {
        return -1;
    } else if (valor1 > valor2) {
        return 1;
    } else {
        return 0;
    }
}