#include <stdio.h>

#define MAXLINE 1000

int strindex(char s[], char t[]);
int mygetline(char s[]);

char target[] = "ould";

int main() {
    // Declarate variables
    char line[MAXLINE], c;
    
    // Get lines form the terminal input
    while (mygetline(line)) {
        printf("%d\n", strindex(line, target));
    }
    return 0;
}

int mygetline(char s[]) {
    // Declaration
    int i, c;
    // Get char from the terminal input
    for (i = 0; (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

int strindex(char s[], char t[]) {
    // Declaration
    int i, j, k;
    int pos = -1;

    // Compare
    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++) 
            ;
        if (t[k] == '\0')
            pos = i;
    }

    return pos;
}