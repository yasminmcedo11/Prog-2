#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 8 


int main() {
    int v[MAX], i;
    int *p1, *p2;
    p1 = &v;
    p2 = &v[MAX-1];
    srand(time(NULL));
    for (i = 1; i <= MAX; i++) {
        v[i] = rand()%100; 
    }
    while (p1 < p2) {
        p1 += 1;
        p2 -= 1;
    }
    return 0;
}
