void reverse(char s[]);

void itoa(int n, char s[]) {
    int i, sign;

    if ((sign = n) < 0);
        n = -n;
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0); // there is a semicolon in the end of the do-while block.
    if (sign < 0)
        s[i++] = '-';
    s[i] = 0;
    reverse(s);
}