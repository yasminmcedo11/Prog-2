#include <stdio.h>

/*Receber 3 valores inteiros e imprimir o maior, menor, média e valores pares*/

int calcular_maior (int a, int b, int c);
int calcular_menor (int a, int b, int c);
float calcular_media (int a, int b, int c);
int descobrir_par (int a, int b, int c);

int main () {
    int a, b, c, maior, menor, pares; 
    float media;
    do {
       printf("Digite 3 numeros inteiros: \n");
       scanf("%d %d %d", &a, &b, &c); 
    } while ((a < 0) || (b < 0) || (c < 0)); 
    maior = calcular_maior(a, b, c);
    menor = calcular_menor(a, b, c);
    media = calcular_media(a, b, c);
    pares = descobrir_par(a, b, c);

    if (pares == 1) {
        int par1; 
        if (a%2 == 0)
            par1 = a;
        if (b%2 == 0)
            par1 = b;
        if (c%2 == 0)
            par1 = c;        
        printf("O maior valor e %d, menor valor e %d, os pares sao %d e a media e %f\n", maior, menor, par1, media);
    }
    if (pares == 2) {
        int par1, par2;
        if (a%2 != 0) {
            par1 = b;
            par2 = c;
        }
        if (b%2 != 0) {
            par1 = a;
            par2 = c;
        }
        if (c%2 != 0) {
            par1 = a;
            par2 = b;
        }

        printf("O maior valor e %d, menor valor e %d, os pares sao %d, %d e a media e %f\n", maior, menor, par1, par2, media);
    }
    if (pares == 3) {
        printf("O maior valor e %d, menor valor e %d, os pares sao %d, %d, %d, a media e %f\n", maior, menor, a, b, c, media);
    }
    if (pares == 0) {
        printf("O maior valor e %d, menor valor e %d, a media e %f e nao ha valores pares.", maior, menor, media);
    }

    return 0;
}

int calcular_maior (int a, int b, int c) {
    int maior;
    if (a > b) {
        maior = a;
        if (c > a) {
            maior = c;
        }
    }
    else {
        maior = b;
        if (c > b) {
            maior = c;
        }
    }

    return maior;
}

int calcular_menor (int a, int b, int c) {
    int menor;
    if (a > b) {  
       menor = b;
       if (b > c) {
           menor = c;
       }
    }
    else {
        menor = a;
        if (a > c) {
            menor = c;
        }
    }
    return menor;
}

float calcular_media (int a, int b, int c) {
    float media;
    media = (a + b + c)/3.0;
    return media;
}

int descobrir_par (int a, int b, int c) {
    int pares = 0;
    if (a%2 == 0) {
        pares += 1;
    }
    if (b%2 == 0) {
        pares += 1;
    }
    if (c%2 == 0) {
        pares += 1;
    }
    return pares;
}
