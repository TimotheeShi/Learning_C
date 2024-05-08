#include <stdio.h>
#define MAXLINE 1000

int mygetline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main() {
    char line[MAXLINE];
    int found = 0;

    while (mygetline(line, MAXLINE) > 0)
        if (strindex(line, pattern) >= 0) {
            printf("%s", line);
            found++;
        }
    return 0;
}

/* getline: get line into s, return length */
int mygetline(char s[], int lim) {
    int i, c;
    for (i = 0; i < lim && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* strindex: return index of t in s, -1 if none */
// int strindex(char s[], char t[]) {
//     int i, j, k;
//     for (i = 0; s[i] != '\0'; i++){
//         for (j = i, k = 0; s[j] == t[k] && t[k] != '\0'; j++, k++)
//             ;
//         if (k > 0 && t[k] == '\0')
//             return i;
//     }
//     return -1;
// }

/* Review of `strindex` */
int strindex(char s[], char t[]) {
    int i, j, k;
    for (i = 0; s[i] != '\0'; i++) { // outer loop: traverse all the char in `s`
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++) // inner loop: compare the string pattern
            ;
        // There are two situations when the inner loop breaks:
        // 1. string pattern is found in the `s`: `t[k] == '\0'`
        // 2. current charater is different (`s[j] == t[k]` is false)
        if (t[k] == '\0')
            return i;
    }
    // If the outter loop quits, it means that the string pattern is not found in the `s`
    return -1;
}