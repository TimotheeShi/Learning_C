#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100

/* rudimentary calculator */
int main() {
    double sum, atof(char[]); // Declare function inside another function.
    char line[MAXLINE];
    int mygetline(char line[], int max);

    sum = 0;
    while (mygetline(line, MAXLINE))
        printf("\t%g\n", sum += atof(line));
    return 0;
}

/* atof: convert string s to double */
double atof(char s[]) {
    // Declarations
    double val, power;
    int i, sign;

    // Conversion
    for (i = 0; isspace(s[i]); i++) // skip white space
        ;
    // Get the sign of the number
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '-' || s[i] == '+')
        i++;
    // Convert characters to numbers
    // Integer part:
    for (val = 0.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
    }
    // Decimal part:
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    return sign * val / power;
}

int mygetline(char s[], int lim) {
    int i, c;
    for (i = 0; i < lim && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}