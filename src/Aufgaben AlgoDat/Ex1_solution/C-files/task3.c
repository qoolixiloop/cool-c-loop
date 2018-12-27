#include <stdio.h>

void countPairs(int a[], int nA, int b[], int nB) {
    int i = 0, j = 0, count = 0;
    while (i<nA) {
        while (a[i] < b[j] && i < nA) {
            printf("(%d, %d) ", a[i], count);
            i++;
            count=0;
        }
        while (a[i] > b[j] && j < nB) j++;
        while (a[i] == b[j] && j < nB) { j++; count++; }
    }
    printf("\n");
}
