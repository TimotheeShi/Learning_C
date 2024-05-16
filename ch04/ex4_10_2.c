#include <stdio.h>

void qsort(int v[], int left, int right);
void swap(int v[], int i, int j);

int main() {
    int a[10] = {5, 2, 9, 6, 1, 7, 3, 4, 0, 8};
    qsort(a, 0, 9);


    return 0;
}

void swap(int v[], int i, int j) {
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;

    return;
}

// void qsort(int v[], int left, int right) {
//     int i, last;
//     if (left >= right)                      // if the left >= right, the sort ends.
//         return;
//     swap(v, left, (left + right) / 2);      // Why do this swap? For the robustness of the algorithm.
//     last = left;                            // the v[left] is the pivot element, and the v[last] is the last element in the smaller area.
//     for (i = left + 1; i <= right; i++)     // traverse all elements in the array
//         if (v[i] < v[left])                 // if the element is less than pivot element, put this element into the smaller area.
//             swap(v, ++last, i);
//     swap(v, left, last);                    // swap the pivot element into its sorted position.
//     qsort(v, left, last-1);                 // divide and conquer!
//     qsort(v, last+1, right);
//     return;
// }

// Quick sort algorithm: a divide-and-conquer algorithm -- recursive funtion
void qsort(int v[], int left, int right) {
    int i, pivot;

    // recursive function 1: end condition
    if (left >= right)
        return;
    // recursive function 2: divide and conquer
    swap(v, left, (left + right) / 2); // For the robustness of algorithm, choose an element as pivot element.
    // The pivot element must be set at the left side, because we will traverse remain elements and compare with the pivot element.
    pivot = left;
    for (i = left; i <= right; i++)
        if (v[i] < v[pivot])
            swap(v, i, ++pivot);
    swap(v, left, pivot);
    qsort(v, left, pivot-1);
    qsort(v, pivot+1, right);
}