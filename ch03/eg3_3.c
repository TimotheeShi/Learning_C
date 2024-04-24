#include <stdio.h>

int binsearch(int x, int v[], int n);

int main() {
    int n = 7;
    int v[n];
    for (int i = 0; i < n; ++i)
        v[i] = i;
    int pos = binsearch(3, v, n);
    printf("%d\n", pos);
    return 0;
}

int binsearch(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n-1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (v[mid] < x) {
            low = mid + 1;
        }
        else if (v[mid] > x) {
            high = mid - 1;
        }
        else
            return mid;
    }
    return -1;
}