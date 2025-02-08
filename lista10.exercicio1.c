#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct funcionario {
    char nome[81]; /* nome do funcionário */
    float valor_hora; /* valor da hora de trabalho em Reais */
    int horas_mes; /* horas trabalhadas em um mês */
};
typedef struct funcionario Funcionario;

void carrega(int n, Funcionario** vet, char* arquivo);

int main() {
    int num_funcionarios = 3, i;
    Funcionario* funcionarios[num_funcionarios];
    char arquivo[] = "funcionarios.txt";
    carrega(num_funcionarios, funcionarios, arquivo);
    for (i = 0; i < num_funcionarios; i++) {
        printf("Funcionario %d:\n", i + 1);
        printf("Nome: %s\n", funcionarios[i]->nome);
        printf("Valor da hora: %.2f\n", funcionarios[i]->valor_hora);
        printf("Horas trabalhadas: %d\n", funcionarios[i]->horas_mes);
    }
    for (int i = 0; i < num_funcionarios; i++) {
        free(funcionarios[i]);
    }
    free(funcionarios);

    return 0;
}

void carrega(int n, Funcionario** vet, char* arquivo) {
    FILE* file = fopen(arquivo, "r");
    if (file == NULL) {
        printf("ERRO: Não foi possível abrir o arquivo.\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        Funcionario* funcionario = (Funcionario*)malloc(sizeof(Funcionario));
        if (funcionario == NULL) {
            printf("ERRO: Não foi possível alocar memória.\n");
            exit(1);
        }
        if (fgets(funcionario->nome, sizeof(funcionario->nome), file) == NULL) {
            printf("ERRO: Falha na leitura do arquivo.\n");
            exit(1);
        }
        if (fscanf(file, "%f %d", &funcionario->valor_hora, &funcionario->horas_mes) != 2) {
            printf("ERRO: Falha na leitura do arquivo.\n");
            exit(1);
        }
        fgetc(file);
        vet[i] = funcionario;
    }
    fclose(file);
}