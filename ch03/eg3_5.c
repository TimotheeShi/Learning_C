#include <ctype.h>
#include <stdio.h>

int atoi(char s[]) {
    int i, n, sign;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = s[i] == '-' ? -1 : 1;
    if (s[i] == '-' || s[i] == '+')
        i++;
    for(n = 0; isdigit(s[i]); i++)
        n = n * 10 + s[i] - '0';
    return sign * n;
}

int main() {
    char s[10];
    for (int i = 0; i < 10; i++)
        s[i] = 0;
    int j, c;
    j = 0;
    while((c = getchar()) != EOF && j < 10)
        s[j++] = c;
    printf("%d\n", atoi(s));
    return 0;
}