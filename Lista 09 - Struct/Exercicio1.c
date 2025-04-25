#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct data {
    int dia, mes, ano;
} Data;

typedef struct local {
    char ender[81]; /* endereço do local de provas */
    int sala; /* numero sala */
} Local;

typedef struct notas {
    float geral; /* prova de conhecimentos gerais */
    float especifica; /* prova de conhecimentos especificos */
} Notas;

typedef struct candidato {
    int inscr; /* numero de inscricao */
    char nome[81]; /* nome do candidato */
    Data nasc; /* data de nascimento */
    Local *loc; /* local de prova */
    Notas nt; /* notas de prova */
} Candidato;

void inicializa (int n, Candidato **tab);
void preenche (int n, Candidato **tab, int i);
void imprime (int n, Candidato **tab);
void mudar_endereco (int i, Candidato **tab);

int main () { 
    Candidato* tab[MAX];
    int n, i, opcao;
    printf("Digite o numero de candidatos cadastrados\n");
    scanf("%d", &n);
    inicializa(n, tab);
    printf("Digite a opcao: 1 para leitura de dados e 2 para impressao de dados\n");
    scanf("%d", &opcao);
    if ((opcao == 1) || (opcao == 2)) {
        for (i = 0; i < n; i++) {
            preenche(n, tab, i);
        }
    }
    if (opcao == 2) {
        imprime(n, tab);
    }
    printf("Caso deseje mudar informacao de endereco, digitar opcao 3\n");
    scanf("%d", &opcao);
    i = 0;
    if (opcao == 3) {
        printf("Digite qual aluno quer alterar dados de endereco\n");
        scanf("%d", &i);
        mudar_endereco(i, tab);
        imprime(n, tab);
    }
    for (i = 0; i < n; i++) {
        free(tab[i]);
    }
    free(tab);

    return 0;
}

void inicializa (int n, Candidato **tab) {
    int i;
    for (i = 0; i < n; i++) {
        tab[i] = NULL;
    }
}

void preenche (int n, Candidato **tab, int i) {
    if ((i < 0) || (i >= n)) {
        printf("Indice fora do limite do programa\n");
        exit(1);
    }
    if (tab[i] == NULL) {
        tab[i] = (Candidato*) malloc(sizeof(Candidato));
        tab[i]->loc = (Local*) malloc(sizeof(Local));
    }
    printf("Entre com os dados do candidato; \n");
    printf("Numero de inscricao: \n");
    scanf("%d", &tab[i]->inscr);
    printf("Nome: \n");
    scanf(" %81[^\n]", tab[i]->nome);
    printf("Data de nascimento\n");
    scanf("%d %d %d", &tab[i]->nasc.dia, &tab[i]->nasc.mes, &tab[i]->nasc.ano);
    printf("Notas: \n");
    scanf("%f %f", &tab[i]->nt.geral, &tab[i]->nt.especifica);
    printf("Endereco\n");
    scanf(" %81[^\n]", tab[i]->loc->ender);
    scanf("%d", &tab[i]->loc->sala);
}

void imprime (int n, Candidato **tab) {
    int i;
    for (i = 0; i < n; i++) {
        if (i < 0 || i >= n) {
            printf("Indice fora do limite do vetor.\n");
            exit(1);
        }
        if (tab[i] != NULL) {
            printf("Nome: %s\n", tab[i]->nome);
            printf("Numero de inscricao: %d\n", tab[i]->inscr);
            printf("Data de Nascimento: %d/%d/%d\n", tab[i]->nasc.dia, tab[i]->nasc.mes, tab[i]->nasc.ano);
            printf("Notas: %f e %f\n", tab[i]->nt.geral, tab[i]->nt.especifica);
            printf("Endereco: %s, sala %d\n", tab[i]->loc->ender, tab[i]->loc->sala);

        }
    }
}

void mudar_endereco (int i, Candidato **tab) {
    if ((i < 0) || (tab[i] == NULL)) {
        printf("Indice inválido ou candidato não existe.\n");
    }
    else {
        printf("Digite o novo endereco: ");
        scanf(" %81[^\n]", tab[i]->loc->ender);
        printf("Digite a nova sala: ");
        scanf("%d", &(tab[i]->loc->sala));
    }
}



