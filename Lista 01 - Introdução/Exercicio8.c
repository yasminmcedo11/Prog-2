#include <stdio.h>

/*Receber um valor e imprimir o menor numero de notas possiveis para o valor*/

int total_de_notas (int valor);

int main () {
    int valor, qtd_notas;
    printf("Digite um valor inteiro de reais: ");
    scanf("%d", &valor);
    qtd_notas = total_de_notas (valor);
    printf("O menor numero de cedulas e %d", qtd_notas);

    return 0;
}

int total_de_notas (int valor) {
    int qtd_notas, sobra;
    qtd_notas = valor/100;
    sobra = valor - (qtd_notas*100);
    if (sobra != 0) {
        qtd_notas = qtd_notas + sobra/50;
        sobra = sobra - ((sobra/50)*50);
        if (sobra != 0) {
            qtd_notas = qtd_notas + sobra/20;
            sobra = sobra - ((sobra/20)*20);
            if (sobra != 0) {
                qtd_notas = qtd_notas + sobra/10;
                sobra = sobra - ((sobra/10)*10);
                if (sobra != 0) {
                    qtd_notas =  qtd_notas + sobra/5;
                    sobra = sobra - ((sobra/5)*5);
                    if (sobra != 0) {
                        qtd_notas = qtd_notas + sobra/2;
                        sobra = sobra - ((sobra/2)*2);
                        if (sobra != 0) {
                            qtd_notas = qtd_notas + 1;
                        }
                    }
                }
            }
        }
    }

    return qtd_notas;
}




