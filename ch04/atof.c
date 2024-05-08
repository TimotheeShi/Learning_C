#include <ctype.h>

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