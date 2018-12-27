#include <stdio.h>
#include <stdlib.h>

void findKMax(int a[], int k, int n)
{
    int max;
    int i, j;

    printf("Results = ");
    for (i = 0; i <= n-k; i++)
    {
        max = a[i];

        for (j = 1; j < k; j++)
        {
            if (a[i+j] > max)
               max = a[i+j];
        }
        printf("%d ", max);
    }
    printf("\n");
}

void main() {
    int a[100];
    int k, i, n;
    
    printf("Type elements of A seperated by spaces (type 'end' to stop): ");
    i=0;
    while(scanf("%d", &a[i]) == 1) i++;
    n=i;

    // Read but do not store any terminating not integer values ('end')
    scanf("%*s");

    printf("Type k: ");
    scanf("%d", &k);

    findKMax(a, k, n);
}


// gcc task1.c -o task1; ./task1
