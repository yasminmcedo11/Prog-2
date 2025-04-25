#include <stdio.h>
#include <string.h>

int main () {
    char *frase = "Otimo teste";
    char *p , misterio[80];
    int i = 0;
    int j = 0;
    p = frase + strlen ( frase ) - 1;
    while (*p != ' ') {
        misterio[i] = *p;
        i ++; 
        p --;
    }
    misterio[i] = ' '; i ++;
    while ( frase[j] != ' ') {
        misterio [i] = frase[j];
        j ++; 
        i ++;
    }
    misterio[i] = '\0';
    puts (misterio);
    
    return 0;
}

/*O codigo imprimira a frase etset Otimo*/