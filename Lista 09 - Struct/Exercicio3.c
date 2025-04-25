#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char * estado[27] = {"AC","AL","AM","AP","BA","CE","DF","ES","GO","MA","MG","MS","MT","PA",
"PB","PE","PI","PR","RJ","RN","RO","RR","RS","SC","SE","SP","TO"};

typedef struct assalariados {
    char nome[51];
    char sexo;
    int idade;
    float salario;
    char estado[3];
} Assalariados;

Assalariados* cadastra (char *nome, char sexo, int idade, float
salario, char *estado);
void relatorio (Assalariados ** ptr, int numAssalariados);
void imprime (Assalariados ** ptr, int numAssalariados);

int main() {
    Assalariados **pessoas;
    int i, numAssalariados=3;
    pessoas = (Assalariados **) malloc (numAssalariados*sizeof(Assalariados*));
    pessoas[0] = cadastra("Fulano de tal", 'M',45,1500.00, "RJ");
    pessoas[1] = cadastra("Ciclano", 'M',50,2500.00, "RS");
    pessoas[2] = cadastra("Beltrano", 'M',42,500.00, "RS");
    imprime(pessoas, numAssalariados);
    relatorio(pessoas,numAssalariados);
    for (i = 0; i < numAssalariados; i++) {
        free(pessoas[i]);
    }
    free(pessoas);

    return 0;
}

Assalariados* cadastra (char *nome, char sexo, int idade, float salario, char *estado) {
    Assalariados *novas_pessoas = (Assalariados *) malloc(sizeof(Assalariados));
    if (novas_pessoas != NULL) {
        strcpy(novas_pessoas->nome, nome);
        novas_pessoas->sexo = sexo;
        novas_pessoas->idade = idade;
        novas_pessoas->salario = salario;
        strcpy(novas_pessoas->estado, estado);
    }
    return novas_pessoas;
}

void imprime (Assalariados ** ptr, int numAssalariados) {
    int i;
    for (int i = 0; i < numAssalariados; i++) {
        printf("Nome: %s\n", ptr[i]->nome);
        printf("Sexo: %c\n", ptr[i]->sexo);
        printf("Idade: %d\n", ptr[i]->idade);
        printf("Salario: %f\n", ptr[i]->salario);
        printf("Estado: %s\n", ptr[i]->estado);
    }
}

void relatorio (Assalariados ** ptr, int numAssalariados) {
    int i, j, count = 0;
    for (i = 0; i < 27; i++) {
        count = 0;
        for (j = 0; j < numAssalariados; j++) {
            if ((ptr[j]->sexo =='M') && (ptr[j]->idade > 40) && (ptr[j]->salario > 1000)) {
                count++;
            }
        }
        if (count > 0) {
            printf("Estado=%s com %d homens maiores de 40 anos e salario maior que R$ 1000,00", ptr[i]->estado, count);
        }
    } 
}       