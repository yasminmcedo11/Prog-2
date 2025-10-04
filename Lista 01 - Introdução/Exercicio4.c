#include <stdio.h>

//Receber 3 notas e indicar se está aprovado, de VS ou reprovado.

float calcula_media(float a, float b, float c);

int main() {
    float p1, p2, p3, media;

    printf("Digite as 3 notas das provas: \n");
    scanf("%f %f %f", &p1, &p2, &p3);

    media = calcula_media(p1, p2, p3);
    if (media > 6) {
        printf("O aluno esta aprovado! Media = %.2f", media);
    }
    if (media < 6 && media >= 4) {
        printf("O aluno esta de VS. Media = %.2f", media);
    }
    if (media < 4) {
        printf("O aluno esta reprovado! Media = %.2f", media);
    }

    return 0;
}


float calcula_media(float p1, float p2, float p3) {
    float media = (p1 + p2 + p3) / 3.0;

    return media;
}