#include <stdio.h>

int countCopies(int a[], int size, int x) {
    int count = 0;
    int i;
    for (i = 0; i < size; i++) {
        if (a[i] == x) {
            count++;
        }
    }
    return count; 
}

void main() {
    int maxarraylen = 1000;
    int i, n;
    int x;
    int a[maxarraylen];

    printf("Type elements of A seperated by spaces (non-number to stop): ");
    i=0;
    while(scanf("%d", &a[i]) == 1) i++;
    n=i;
    // Read but do not store any terminating not integer values ('end')
    scanf("%*s");

    printf("Type x: ");
    scanf("%d", &x);

    printf("Copies = %d\n", countCopies(a, n, x));
}

// Linux, Mac: gcc task2.c -o task2; ./task2
// Windows: gcc task2.c -o task2; task2
