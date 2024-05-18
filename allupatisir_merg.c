#include<stdio.h>

void merge(int a[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int x[n1], y[n2];

    for (int i = 0; i < n1; i++)
        x[i] = a[l + i];
    for (int i = 0; i < n2; i++)
        y[i] = a[m + 1 + i];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (x[i] <= y[j]) {
            a[k++] = x[i++];
        } else {
            a[k++] = y[j++];
        }
    }

    while (i < n1)
        a[k++] = x[i++];

    while (j < n2)
        a[k++] = y[j++];
}

void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

void display(int* a, int s) {
    printf("array content:\n");
    for (int i = 0; i < s; i++)
        printf("%7d", a[i]);
    printf("\n");
}

int main() {
    int a[] = {8, 6, 7, 5, 4, 3, 2, 1, 324-78, 768-0+23, 2, 567, 1, 5678, 21, 100};
    display(a, 16);
    mergeSort(a, 0, 15);
    display(a, 16);
    return 0;
}