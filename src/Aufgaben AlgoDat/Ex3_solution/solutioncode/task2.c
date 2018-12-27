#include <stdio.h>
#include <math.h>

#define MAX_ARRAY_SIZE 100

void swap(int A[], int i, int j) {
     int tmp = A[i];
     A[i] = A[j];
     A[j] = tmp;
}

void printArray(int a[], int size) {
     printf("[");
     int i;
     for(i = 0; i < size; i++) {
          printf(" %d", a[i]);
     }
     printf(" ]\n");
}

int medianOfThree(int A[], int low, int high) {
     int m = (low + high) / 2;

     if(A[m] < A[low]) swap(A, m, low);
     if(A[low] > A[high]) swap(A, high, low);
     if(A[m] > A[high]) swap(A, high, m);

     return m;
}

int partitionHoare(int A[], int low, int high) {
     int pivot= A[high], i=low-1, j= high+1;

     while(1) {
          while(A[--j] > pivot);
          while(A[++i] < pivot);

          if(i < j) swap(A, i, j);
          else return i;
     }
}


int quicksort(int A[], int low, int high, int choice) {
    int m;

    if(low < high) {
        if(choice == 1) {
             m = medianOfThree(A, low, high);
             swap(A, high, m);
        }
        m = partitionHoare(A, low, high);
        quicksort(A, low, m-1, choice);
        quicksort(A, m , high, choice);
    }
}

void main() {
    int a[MAX_ARRAY_SIZE];
    int i, n;
    int choice=1;

    printf("Type elements of A seperated by spaces (type 'end' to stop): ");
    i=0;
    while(scanf("%d", &a[i]) == 1) i++;
    n=i;
    // Read but do not store any terminating not integer values ('end')
    scanf("%*s");

    quicksort(a, 0, n-1, 0);
    printf("Sorted: ");
    printArray(a, n);
}

// Linux, Mac: gcc task2.c -o task2; ./task2
// Windows: gcc task2.c -o task2; task2
