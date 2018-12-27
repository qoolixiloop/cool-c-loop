#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_N 10000

// ... include code from Task 2 ...

int m[MAX_N][MAX_N];

int max(int x, int y) {
    if (x > y) return x; else return y;
}

void prepareMemoizationArray(int n) {
    int i, j;

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            m[i][j] = -1;
        }
    }
}

void printMemoizationArray(int n) {
    int i, j;

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%2d ", m[i][j]);
        }
        printf("\n");
    }
}

int wineprofitRecursive(int price[], int n, int begin, int end) {
    int year = n - (end-begin+1) + 1;

    if (begin > end) return 0;

    return max(
        wineprofitRecursive(price, n, begin+1, end) + year * price[begin],
        wineprofitRecursive(price, n, begin, end-1) + year * price[end]
    );
}

int wineprofitMemoized(int price[], int n, int begin, int end) {
    if (begin > end) return 0;
    if (m[begin][end] != -1)
        return m[begin][end];
    int year = n - (end-begin+1) + 1;
    return m[begin][end] = max(
        wineprofitMemoized(price, n, begin+1, end) + year * price[begin],
        wineprofitMemoized(price, n, begin, end-1) + year * price[end]
    );
}

int wineprofitDynamic(int price[], int n) {
    int i, j;
    int begin, end, year;

    for (i = 0; i < n; i++) {
        m[i][i] = price[i] * n;
    }

    for (j = 1; j < n; j++) {
        for (i = 0; i < n - j; i++) {
            begin = i;
            end = i + j;
            year = n - (end - begin);

            m[begin][end] = max(
                m[begin + 1][end] + year * price[begin],
                m[begin][end - 1] + year * price[end]
            );
        }
    }
    return m[0][n - 1];
}


// ------------------- auxiliary functions --------------

void readFile(char filename[], int output[], int *n) {
    FILE *f;
    int i;

    f=fopen(filename, "r");

    i=0;
    while(fscanf(f, "%d", &output[i]) == 1) i++;
    *n=i;

    fclose(f);
}

// ------------------- main -----------------------------

void main() {
    int a[MAX_N];
    int n;
    clock_t start;
    clock_t end;
    float seconds;

    printf("                    | small    | medium   | large    |\n");

    // ------------------- dynamic programming --------------

    // small
    readFile("small.txt", a, &n);
    start = clock();
    wineprofitDynamic(a, n);
    end = clock();
    seconds = (float)(end-start)/CLOCKS_PER_SEC;
    printf("Dynamic Programming | %8.4f | ", seconds);

    // medium
    readFile("medium.txt", a, &n);
    start = clock();
    wineprofitDynamic(a, n);
    end = clock();
    seconds = (float)(end-start)/CLOCKS_PER_SEC;
    printf("%8.4f |", seconds);

    // large
    readFile("large.txt", a, &n);
    start = clock();
    wineprofitDynamic(a, n);
    end = clock();
    seconds = (float)(end-start)/CLOCKS_PER_SEC;
    printf(" %8.4f |\n", seconds);

    // ------------------- memoization ----------------------

    // small
    readFile("small.txt", a, &n);
    start = clock();
    prepareMemoizationArray(n);
    wineprofitMemoized(a, n, 0, n-1);
    end = clock();
    seconds = (float)(end-start)/CLOCKS_PER_SEC;
    printf("Memoization         | %8.4f | ", seconds);

    // medium
    readFile("medium.txt", a, &n);
    start = clock();
    prepareMemoizationArray(n);
    wineprofitMemoized(a, n, 0, n-1);
    end = clock();
    seconds = (float)(end-start)/CLOCKS_PER_SEC;
    printf("%8.4f |", seconds);

    // large
    readFile("large.txt", a, &n);
    start = clock();
    prepareMemoizationArray(n);
    wineprofitMemoized(a, n, 0, n-1);
    end = clock();
    seconds = (float)(end-start)/CLOCKS_PER_SEC;
    printf(" %8.4f |\n", seconds);

    // ------------------- recursive ------------------------

    // small
    readFile("small.txt", a, &n);
    start = clock();
    wineprofitRecursive(a, n, 0, n-1);
    end = clock();
    seconds = (float)(end-start)/CLOCKS_PER_SEC;
    printf("Recursion           | %8.4f | ", seconds);

    // medium
    readFile("medium.txt", a, &n);
    start = clock();
    wineprofitRecursive(a, n, 0, n-1);
    end = clock();
    seconds = (float)(end-start)/CLOCKS_PER_SEC;
    printf("%8.4f |", seconds);

    // large
    printf("   ----   |\n");
}

// Linux, Mac: gcc task3.c -o task3; ./task3
// Windows: gcc task3.c -o task3; task3
