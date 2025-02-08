#include <stdio.h>

/*Receber valor em segundos e repassar em horas, minutos e segundos*/

int main () {
    int c, h, m, s, h_m;
    do {
       printf("Digite um numero inteiro de segundos: \n");
       scanf("%d", &c); 
    } while (c < 0);
    h = c/3600;
    h_m = (c - 3600*h);      /* quantidade de segundos que sobrou*/
    m = (h_m)/60;
    s = (h_m - 60*m);
    printf("Sao %d horas, %d minutos e %d segundos\n", h, m, s);
    
    return 0;
}
