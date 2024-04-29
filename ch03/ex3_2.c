#include <stdio.h>

int escape(char s[], char t[]);

int main() {
    int max = 100;
    char src[max], tgt[max];
    int i, j, c;
    for (i = 0; i < max; i++) {
        src[i] = '\0';
        tgt[i] = '\0';
    }
    i = 0;
     while ((c = getchar()) != EOF && i < max)
        src[i++] = c; // Input EOF: Ctrl+Z in Win, Ctrl+D in Linux
    j = escape(src, tgt);
    for(i = 0; i < j; i++)
        printf("%c", tgt[i]);
    printf("\n");
    return 0;
}

int escape(char s[], char t[]) {
    int i, j;

    for (i = 0, j = 0; s[i] != '\0'; i++) {
        switch(s[i]) {
            case ' ': t[j++] = '_';
            break;

            case '\n': {
                t[j++] = '\\';
                t[j++] = 'n';
                break;
            }
            case '\t': {
                t[j++] = '\\';
                t[j++] = 't';
                break;
            }
            case '\0': {
                t[j++] = '\\';
                t[j++] = '0';
                break;
            }
            default : t[j++] = s[i];
        }
    }

    return j;
}