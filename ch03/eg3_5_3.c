#include <stdio.h>
#include <string.h>

void reverse(char s[]) {
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

int main() {
    int c, i;
    int max = 100;
    char str[100];
    for (i = 0; (str[i] = getchar()) != EOF && str[i] != '\n'; i++)
        ;
    str[i] = 0;
    reverse(str);
    for (int j = 0; j < i; j++)
        printf("%c", str[j]);
    printf("\n");
    return 0;
}