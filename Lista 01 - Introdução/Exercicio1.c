#include <stdio.h>

//Receber valor em segundos e repassar em horas, minutos e segundos

int main() {
    int s, horas, minutos, segundos, s_inicial;
    printf("Digite um numero inteiro de segundos: \n");
    scanf("%d", &s);
    s_inicial = s;
    
    horas = s/3600;
    s = s - (horas * 3600);
    minutos = s/60;
    s = s - (minutos * 60);
    segundos = s;

    printf("%d sao %d horas, %d minutos e %d segundos\n", s_inicial, horas, minutos, segundos);
    return 0;
}
