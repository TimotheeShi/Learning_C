#include <stdio.h>

/* printd: primnt n in decimal */
void printd(int n) {
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n / 10)
        printd(n / 10);
    putchar(n % 10 + '0');
}

int main() {
    int a = -123;
    printd(a);
    printf("\n");

    return 0;
}