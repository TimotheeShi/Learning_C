#include <stdio.h>

int main() {
    int c, i;
    int lim = 100;
    char s[100];
    for(i = 0; (i < lim-1) * ((c = getchar()) != '\n') * (c != EOF); ++i )
        s[i] = c;
    for(int j = 0; j < i; ++j)
        printf('%c ', s[j]);
    printf("'\n'");
    return 0;
}