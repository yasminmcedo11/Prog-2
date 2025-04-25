#include <stdio.h>

int main () {
    int n1, n2, n3;
    unsigned int a; 
    printf("Digite um numero de 3 digitos: \n");
    scanf("%d", &a);
    n1 = a%10;
    a = a/10;
    n2 = a%10;
    a = a/10;
    n3 = a%10;
    printf("%d%d%d", n1, n2, n3);

    return 0;
}