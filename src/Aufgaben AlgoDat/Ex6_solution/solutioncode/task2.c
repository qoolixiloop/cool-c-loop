#include<stdio.h>

#define SIZE_A 4
#define SIZE_B 5

#define MAX_N SIZE_B

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


void main() {
    int i;
    int testPriceA[] = {1,4,2,3};
    int testPriceB[] = {2,3,5,1,4};

    printf("prices: ");
    for(i=0; i<SIZE_A; i++)
        printf("%2d ", testPriceA[i]);
    printf("\n");
    printf("wineprofitRecursive:\n");
    printf("Max profit A: %d\n", wineprofitRecursive(testPriceA, SIZE_A, 0, SIZE_A-1));
    printf("\n");

    printf("wineprofitMemoized:\n");
    prepareMemoizationArray(SIZE_A);
    printf("Max profit A: %d\n", wineprofitMemoized(testPriceA, SIZE_A, 0, SIZE_A-1));
    printf("\n");

    printf("wineprofitDynamic:\n");
    printf("Max profit A: %d\n", wineprofitDynamic(testPriceA, SIZE_A));
    printf("Memoized Array A:\n");
    printMemoizationArray(SIZE_A);

    printf("\n~~~~~~~~~\n\n");

    printf("prices: ");
    for(i=0; i<SIZE_B; i++)
        printf("%2d ", testPriceB[i]);
    printf("\n");
    printf("wineprofitRecursive:\n");
    printf("Max profit B: %d\n", wineprofitRecursive(testPriceB, SIZE_B, 0, SIZE_B-1));
    printf("\n");

    printf("wineprofitMemoized:\n");
    prepareMemoizationArray(SIZE_B);
    printf("Max profit B: %d\n", wineprofitMemoized(testPriceB, SIZE_B, 0, SIZE_B-1));
    printf("\n");

    printf("wineprofitDynamic:\n");
    printf("Max profit B: %d\n", wineprofitDynamic(testPriceB, SIZE_B));
    printf("Memoized Array B:\n");
    printMemoizationArray(SIZE_B);

}

// Linux, Mac: gcc task2.c -o task2; ./task2
// Windows: gcc task2.c -o task2; task2
