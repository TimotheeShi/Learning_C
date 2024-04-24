#include <stdio.h>

int lim = 100;

int htoi(char s[], int n);

int main() {
    char s[2] = "11";
    int h = htoi(s, 2);
    printf("%d\n", h);
    return 0;

}

int htoi(char s[], int n) {
    int sum = 0;
    for(int i = 0; i < n; ++i) {
        if (s[i] <= '9' && s[i] > '0')
            sum = sum * 16 + (s[i] - '0');
        if (s[i] >= 'a' && s[i] <= 'f')
            sum = sum * 16 + (s[i] - 'a' + 10);
        if (s[i] >= 'A' && s[i] <= 'F')
            sum = sum * 16 + (s[i] - 'a' + 10);
    }
    return sum;
}