#include <stdio.h>

int permutation(char A[], char B[]) {
    int i,j;
    int temp;

    /* Case 1 */
    if(A == NULL && B == NULL)
        return 1;

    /* Cases 2 & 3 */
    if(A == NULL || B == NULL)
        return 0;
 
    /* Case 4 */
    if(A[0] == '\0' && B[0] == '\0')
        return 1;

    /* Cases 5 & 6*/
    if(A[0] == '\0' || B[0] == '\0')
        return 0;

    for (i=0; A[i] != '\0'; i++) {

        j = i;
        while (A[i] != B[j] && B[j] != '\0') j++;

        /* Case 7 */
        if (B[j] == '\0')
            return 0;
        else {
            temp = B[i];
            B[i] = B[j];
            B[j] = temp;
        }
    }
    if (B[i] == '\0')
        return 1;
    else
        /* Case 8 */
        return 0;
}


void main() {
    int i, maxstrlen = 100;
    char a[maxstrlen];
    char b[maxstrlen];
    char t[maxstrlen];

    a[0] = '\0';
    printf("Type a: ");
    scanf("%[^\n]s", a);
    getc(stdin);

    b[0] = '\0';
    printf("Type b: ");
    scanf("%[^\n]s", b);
    getc(stdin);

    if (permutation(a, b))
        printf("TRUE\n");
    else
        printf("FALSE\n");

    // You input different variables to a,b to check it for all the cases
}

// gcc task4.c -o task4; ./task4
