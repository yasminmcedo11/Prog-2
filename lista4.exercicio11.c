#include <stdio.h>
#define MAX 20

int main () {
    int v1[MAX], v2[MAX], v4[MAX], i;
    char v3[MAX];
    for (i = 0; i < MAX; i++) {
        scanf("%d %d %c", &v1[i], &v2[i], &v3[i]);
    }
    for (i = 0; i < MAX; i++) {
        if (v3[i] == '+') {
            v4[i] = v1[i] + v2[i]; 
        }
        if (v3[i] == '-') {
            v4[i] = v1[i] - v2[i]; 
        }
        if (v3[i] == '*') {
            v4[i] = v1[i] * v2[i]; 
        }
        if (v3[i] == '/') {
            v4[i] = v1[i] / v2[i]; 
        }
    }
    for (i = 0; i < MAX; i++) {
        printf(" %d,", v4[i]);
    }
    return 0;
}