#include <stdio.h>
#define MAX 15

int main () {
    int r[5], s[10], x[MAX];
    int i, tam = 15, i1 = 0;
    printf("Digite os valores presentes no vetores r e s (nessa exata ordem)\n");
    for (i = 1; i <= 5; i++) {
        scanf("%d", &r[i]);
    }
    for (i = 1; i <= 10; i++) {
        scanf("%d", &s[i]);
    }
    for (i = 0; i < 10; i++) {
        if (s[i] == r[0]) {
            tam = tam - 1;
        }
        if (s[i] == r[1]) {
            tam = tam - 1;
        }
        if (s[i] == r[2]) {
            tam = tam - 1;
        }
        if (s[i] == r[3]) {
            tam = tam - 1;
        }
        if (s[i] == r[4]) {
            tam = tam - 1;
        }
    }
    for (i = 0; i < 5; i++) {
        x[i] = r[i];
    }
    for (i = 0; i < 10; i++) {
        i1 += 1;
        if (s[i] == r[0]) {
            i1 = i1 - 1;
        }
        else {
            if (s[i] == r[1]) {
                i1 = i1 - 1;
            }
            else {
                if (s[i] == r[2]) {
                   i1 = i1 - 1; 
                }
                else {
                    if ((s[i] == r[3])) {
                        i1 = i1 - 1;
                    }
                    else {
                        if (s[i] == r[4]) {
                            i1 = i1 - 1;
                        }
                        else {
                            x[i1] = s[i];
                        }

                    }
                }
            }
        }
    }
    for (i = 1; i <= tam; i++) {
        printf(" %d", x[i]);
    }
    return 0;
}