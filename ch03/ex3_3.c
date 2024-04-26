#include <stdio.h>

int binsearch(int x, int v[], int n);

int main() {
    int n = 3;
    int v[n];
    for (int i = 0; i < n; ++i)
        v[i] = i + 1;
    int pos = binsearch(6, v, n);
    printf("%d\n", pos);
    return 0;
}

int binsearch(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while (low < high && x != v[mid]) {
        if(v[mid] > x)
            high = mid - 1;
        else
            low = mid + 1;
        mid = (low + high) / 2;
    }
    if (x == v[mid])
        return mid;
    else
        return -1;
}