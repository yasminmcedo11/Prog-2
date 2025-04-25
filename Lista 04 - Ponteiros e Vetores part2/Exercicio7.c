#include <stdio.h>
#include <ctype.h>
#include <string.h>

void CamelCase(char *s);

int main() {
    char s[20];
    strcpy(s, "media da turma");
    printf("%s\n", s);
    CamelCase(s);
    printf("%s\n", s);

    return 0;
}

void CamelCase(char *s) {
    int length = strlen(s);
    int capitalizeNext = 1; 
    for (int i = 0; i < length; i++) {
        char c = s[i];
        if (c == ' ') {
            capitalizeNext = 1; 
        } else {
            if (capitalizeNext) {
                s[i] = toupper(c); 
                capitalizeNext = 0;
            } else {
                s[i] = tolower(c);  
            }
        }
    }
}