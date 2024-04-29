#include <stdio.h>
#include <ctype.h>

int expand(char s1[], char s2[]) {
    int i, j, c;
    for (i = 0; isdigit(s1[i]) || isalpha(s1[i]); i++)
        ;
    j = 0;
    for (; s1[i]; i++) {
        if (s1[i] == '-')
            for (c = s1[i - 1]; c <= s1[i + 1]; c++)
                s2[j++] = c;
    }
    s2[j] = '\0';
    return j; 
}

int main() {
    int i, j, c;
    int max = 100;
    char s1[max], s2[max];
    for (i = 0; i < max; i++)
        s1[i] = s2[i] = 0;
    i = 0;
    while ((c = getchar()) != EOF && c != '\n') {
        s1[i++] = c;
    }
    j = expand(s1, s2);
    for (i = 0; i < j; i++)
        printf("%c", s2[i]);
    printf("\n");
    return 0;
}