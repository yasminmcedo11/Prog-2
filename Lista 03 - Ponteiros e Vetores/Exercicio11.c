#include <stdio.h>
#define MAX 20
/*Definindo sexo masculino = 1 e sexo feminino = 0*/

int faixa_idade (int n, int *idade, int *sexo);
int faixa_altura (int n, float *altura, int *sexo);
float calcular_variancia (int n, float *altura);

int main () {
    int idade[MAX], sexo[MAX], i, n, qtd_mulheres, qtd_homens;
    float altura[MAX], var;
    printf("Digite a quantidade de pessoas analisadas.\n");
    scanf("%d", &n);
    printf("Insira valores de idade, altura e sexo (nesta exata ordem).\n Digite 1 para sexo masculino e 0 para sexo feminino.\n");
    for (i = 1; i <= n; i++) {
        scanf("%d %f %d", &idade[i], &altura[i], &sexo[i]);
    }
    qtd_mulheres = faixa_idade (n, idade, sexo);
    qtd_homens = faixa_altura (n, altura, sexo);
    var = calcular_variancia (n, altura);
    printf("A quantidade de mulheres na faixa de idade e %d, a quantidade de homens na faixa de altura e %d e a variancia da altura e %f", qtd_mulheres, qtd_homens, var);

    return 0;
}

int faixa_idade (int n, int *idade, int *sexo) {
    int i, qtd_mulheres = 0;
    for (i = 1; i <= n; i++) {
        if ((idade[i] >= 20) && (idade[i] <= 35) && (sexo[i] == 0)) {
            qtd_mulheres += 1;
        }
    }
    return qtd_mulheres;
}

int faixa_altura (int n, float *altura, int *sexo) {
    int i, qtd_homens = 0;
    for (i = 1; i <= n; i++) {
        if ((altura[i] > 1.80f) && (sexo[i] == 1)) {
            qtd_homens += 1;
        }
    }
    return qtd_homens;
}

float calcular_variancia (int n, float *altura) {
    float var = 0, med = 0;
    int i;
    for (i = 1; i <= n; i++) {
        med = med + altura[i];
    }
    med = med/n;
    for (i = 1; i <= n; i++) {
        var = var + (altura[i]-med)*(altura[i]-med);
    }
    var = var/n;

    return var;
}