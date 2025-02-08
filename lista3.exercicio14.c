#include <stdio.h>
#define MAX 100

/*Definindo 1 = pessimo; 2 = ruim; 3 = regular; 4 = bom; 5 = otimo*/

int calcular_qtdotimos (int n, int *opiniao);
float calcular_percentual (int n, int *opiniao);
float calcular_media (int n, int *opiniao, int *idade);
float calcular_porcentagem (int n, int *opiniao, int *idade, int *maior);
int calcular_diferenca (int n, int *opiniao, int *idade);

int main () {
    int idade[MAX], opiniao[MAX], i, n, a, e, maior = 0;
    float b, c, d;
    printf("Digite quantas pessoas foram ao cinema.\n");
    scanf("%d", &n);
    printf("Digite sua idade e sua opiniao sobre o filme assistido (nesta exata ordem)\n");
    printf("Digite 1 = pessimo; 2 = ruim; 3 = regular; 4 = bom; 5 = otimo");
    for (i = 1; i <= n; i++) {
        scanf("%d %d", &idade[i], &opiniao[i]);
    }
    a = calcular_qtdotimos (n, opiniao);
    b = calcular_percentual (n, opiniao);
    c = calcular_media (n, opiniao, idade);
    d = calcular_porcentagem (n, opiniao, idade, &maior);
    e = calcular_diferenca (n, opiniao, idade);
    printf("a = %d, b = %f, c = %f, d = porcentagem =%f e maior idade = %d, e = %d", a, b, c, d, maior, e);

    return 0;
}

int calcular_qtdotimos (int n, int *opiniao) {
    int i, qtd_otimos = 0;
    for (i = 1; i <= n; i++) {
        if (opiniao[i] == 5) {
            qtd_otimos += 1;
        }
    }
    return qtd_otimos;
}

float calcular_percentual (int n, int *opiniao) {
    int i;
    float qtd_bom = 0.0f, qtd_regular = 0.0f, dif_bom_reg;
    for (i = 1; i <= n; i++) {
        if (opiniao[i] == 3) {
            qtd_regular += 1.0f;
        }
        if (opiniao[i] == 4) {
            qtd_bom += 1.0f;
        }
    }
    qtd_regular = qtd_regular/n;
    qtd_bom = qtd_bom/n;
    if(qtd_regular >= qtd_bom) {
        dif_bom_reg = ((qtd_regular - qtd_bom)/(qtd_bom))*100;
    }
    else {
        dif_bom_reg = ((qtd_bom - qtd_regular)/(qtd_regular))*100;
    }
    return dif_bom_reg;
}

float calcular_media (int n, int *opiniao, int *idade) {
    int i, qtd_ruim = 0;
    float med = 0;
    for (i = 1; i <= n; i++) {
        if (opiniao[i == 2]) {
            med = med + idade[i];
            qtd_ruim += 1;
        }
    }
    med = med/qtd_ruim;

    return med;
}

float calcular_porcentagem (int n, int *opiniao, int *idade, int *maior) {
    int i, qtd_pessimo;
    for (i = 1; i <= n; i++) {
        if (opiniao[i] == 1) {
            qtd_pessimo += 1;
            if (idade[i] > *maior) {
                *maior = idade[i];
            }
        }
    }
    qtd_pessimo = qtd_pessimo/n;

    return qtd_pessimo;
}

int calcular_diferenca (int n, int *opiniao, int *idade) {
    int i, maior = 0, maior1 = 0, dif_idade;
    for (i = 1; i <= n; i++) {
        if (opiniao[i] == 5) {
            if (idade[i] > maior) {
                maior = idade[i];
            }
        }
        if (opiniao[i] == 2) {
            if (idade[i] > maior1) {
                maior1 = idade [i];
            }
        }
    }
    if (maior1 >= maior) {
        dif_idade = maior1 - maior;
    }
    else {
        dif_idade = maior - maior1;
    }

    return dif_idade;
}