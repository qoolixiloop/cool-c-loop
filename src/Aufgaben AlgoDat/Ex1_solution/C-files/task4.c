void bubblesort(int a[], int size) {
    int t, i, j;
    for (i = size - 1; i > 0; i--) {
        for (j = 1; j <= i; j++) {
            if (a[j] < a[j-1]) {
                t = a[j];
                a[j] = a[j-1];
                a[j-1] = t;
            }
        }
    }
}

int team_photo(int A[], int B[], int size) {
    int i;
    int isPossible = 1;
    bubblesort(A, size);
    bubblesort(B, size);

    isPossible = A[0] != B[0];    
    for (i = 1; i < size && isPossible; i++)
        isPossible = isPossible && (A[i]!=B[i]) && ((A[i]<B[i]) == (A[i-1]<B[i-1]));

    return isPossible;
}
