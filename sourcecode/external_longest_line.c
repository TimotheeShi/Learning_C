#include <stdio.h>

/**
 * When you have variables which will be processed by several function.
 * It is worthy to consider to transform the variables to external variables
 * to prevent extra copy.
*/

#define MAXLINE 1000

int max;
char line[MAXLINE];
char longest[MAXLINE];

int getaline(void);
void copy(void);

int main() {
    int len;
    extern int max;
    extern char longest[];

    max = 0;
    while ((len = getaline()) > 0)
        if (len > max) {
            max = len;
            copy();
        }
    if (max > 0)
        printf("%s", longest);
    return 0;
}

int getaline(void) {
    int c, i;
    extern char line[];

    for (i = 0; i < MAXLINE - 1
            && (c = getchar()) != EOF && c != '\n'; ++i)
            line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

void copy() {
    int i;
    extern char line[], longest[];

    i = 0;
    while(i < MAXLINE && (longest[i] = line[i]) != '\0')
        ++i;
}