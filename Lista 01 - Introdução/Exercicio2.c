#include <stdio.h>

//Receber 3 valores inteiros e imprimir o maior, menor, média e valores pares

int calcula_maior(int a, int b, int c);
int calcula_menor(int a, int b, int c);
float calcula_media(int a, int b, int c);
int descobre_pares(int a, int b, int c);

int main() {
    int v1, v2, v3, maior, menor, qtd_pares;
    float media;
    printf("Digite os 3 numeros que deseja analisar: \n");
    scanf("%d %d %d", &v1, &v2, &v3);

    maior = calcula_maior(v1, v2, v3);
    menor = calcula_menor(v1, v2, v3);
    media = calcula_media(v1, v2, v3);
    qtd_pares = descobre_pares(v1, v2, v3);
    if (qtd_pares == 3) {
        printf("Os pares sao %d, %d, %d.\n", v1, v2, v3);
    } else if (qtd_pares == 2) {
        int par1, par2;
        if (v1 % 2 == 0) {
            par1 = v1;
            if (v2 % 2 == 0) {
                par2 = v2;
            } else {
                par2 = v3;
            }
        } else {
            par1 = v2;
            par2 = v3;
        }
        printf("Os pares sao %d, %d.\n", par1, par2);
    } else if (qtd_pares == 1) {
        int par;
        if (v1 % 2 == 0) {
            par = v1;
        } else if (v2 % 2 == 0) {
            par = v2;
        } else {
            par = v3;
        }
        printf("O par e %d.\n", par);
    } else if (qtd_pares == 0) {
        printf("Nao ha numeros pares.\n");
    }

    printf("Maior = %d, Menor = %d, Media = %.2f", maior, menor, media);
    return 0;
}

int calcula_menor(int n1, int n2, int n3) {
    int menor = n1;
    if (menor > n2) {
        menor = n2;
    }
    if (menor > n3) {
        menor = n3;
    }

    return menor;
}

int calcula_maior(int n1, int n2, int n3) {
    int maior = n1;
    if (maior < n2) {
        maior = n2;
    } 
    if (maior < n3) {
        maior = n3;
    }

    return maior;
}

float calcula_media(int n1, int n2, int n3) {
    float media = (n1 + n2 + n3)/3.0;

    return media;
}

int descobre_pares(int n1, int n2, int n3) {
    int pares = 0;
    if (n1 % 2 == 0) {
        pares++;
    }
    if (n2 % 2 == 0) {
        pares++;
    }
    if(n3 % 2 == 0) {
        pares++;
    }

    return pares;
}
