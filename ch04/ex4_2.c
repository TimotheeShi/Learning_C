#include <stdio.h>
#include <ctype.h>

/* atof: convert string s to double */
double atof(char s[]) {
    // Declarations
    double val, power;
    int i, sign, expc, expsign;
    double exp = 1.0;

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
    // Exponential part:
    if (s[i] == 'e' || s[i] == 'E')
        i++;
    expsign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '-' || s[i] == '+')
        i++;
    for (expc = 0; isdigit(s[i]); i++)
        expc = 10 * expc + (s[i] -'0');
    for (; expc > 0; expc--)
        exp *= 10.0;
    if (expsign == 1)
        return sign * val / power * exp;
    else
        return sign * val / power / exp;
}

int main() {
    char str[] = "314e3";
    printf("%lf\n", atof(str));
    return 0;
}