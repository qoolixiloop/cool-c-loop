#include <stdio.h>

#define MAX_ARRAY_SIZE 100

int parent(int i) {
    return (i - 1) / 2;
}

int lchild(int i) {
    return (i + 1) * 2 - 1;
}

int rchild(int i) {
    return (i + 1) * 2;
}

void heapify(int A[], int i, int s) {
    int l = lchild(i);
    int r = rchild(i);
    int max = i;

    if ( l < s && A[l] > A[max] ) max = l;
    if ( r < s && A[r] > A[max] ) max = r;

    if ( max != i ) {
        /* Swap */
        int tmp = A[i];
        A[i] = A[max];
        A[max] = tmp;

        heapify(A, max, s);
    }
}

void printArray(int a[], int n) {
    int i;

    printf("[ ");
    for(i = 0; i < n; i++) {
        printf("%d", a[i]);
        if(i < n-1) {
            printf(", ");
        }
    }
    printf(" ]\n");
}

void buildMaxHeap(int A[], int n) {
    int i;

    for (i = n / 2; i >= 0; i--)
        heapify(A, i, n);
}

void printHeap(int A[], int n) {
    int i, l, r;

    printf("graph g {\n");
    for(i = 0; i < n; i++) {
        l = lchild(i);
        r = rchild(i);
        if(l < n) printf("  %d -- %d\n", A[i], A[l]);
        if(r < n) printf("  %d -- %d\n", A[i], A[r]);
    }
    printf("}\n");
}

void heapSort(int A[], int n) {
    int i;

    for (i = n - 1; i > 0; i--) {
        int tmp = A[i];
        A[i] = A[0];
        A[0] = tmp;
        n--;
        heapify(A, 0, n);
    }
}

void main() {
    int a[MAX_ARRAY_SIZE];
    int i, n;

    printf("Type elements of A seperated by spaces (type 'end' to stop): ");
    i=0;
    while(scanf("%d", &a[i]) == 1) i++;
    n=i;
    // Read but do not store any terminating not integer values ('end')
    scanf("%*s");

    buildMaxHeap(a, n);
    printHeap(a, n);
    
    heapSort(a, n);
    printf("Sorted: ");
    printArray(a, n);
}

// Linux, Mac: gcc task1.c -o task1; ./task1
// Windows: gcc task1.c -o task1; task1
