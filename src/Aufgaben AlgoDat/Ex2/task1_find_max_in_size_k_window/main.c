#include <stdio.h>


//## Forward declarations
#define arr_size 20
void findKMax(int arr_in[], int moving_window_size, int nof_digits);
void print_digit_array(int arr_digit[], int arr_digit_len);

//## Main
int main(void)
{
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Hello from task1!\n");

    //## Declaration & Initialisation
    int moving_window_size;
    int arr_int[arr_size]={0};
    moving_window_size=0;

    //## User inputs
    printf(" arr_int=. Type for example <8 5 10 7 9 4 15 12 90 13 end>: \n");
    int i=0;
    while (scanf("%d", &arr_int[i])==1){i++;}
    int nof_digits=i;

    scanf("%*s");
    printf(" moving_window_size=. Type for example: <4>: (between %d and %d)\n", 1, nof_digits);
    scanf("%d",&moving_window_size);


    printf("\n info: You typed %d numbers\n", nof_digits);
    print_digit_array(arr_int, nof_digits);
    printf(" info: You typed %d\n", moving_window_size);

    //## Invoke Algo
    findKMax(arr_int, moving_window_size, nof_digits);
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    return 0;
}


//## Algo
void findKMax(int arr_in[], int moving_window_size, int nof_digits){
    /*
     * Input: array A[1..n] of length n, 1 ≤ k ≤ n
     * Output: print the maximum value of every contiguous
     *         subarray of size k
     * For instance, if A = [8, 5, 10, 7, 9, 4, 15, 12, 90, 13], and k = 4,
     *               then findKMax(A, 4, 10) returns 10 10 10 15 15 90 90.
    */

    //renameing
    int k=moving_window_size;

    //Transformations from indices [0 to (n-1)] to [1 to n]
    //(I know, that shouldn't be done, but it's getting early in the morning)
    int n=nof_digits;
    int A[n+1];
    A[0]=0; //not used index
    int index;
    for(index=0; index<nof_digits; ++index){
        A[index+1]=arr_in[index];

    }

    //Algo
    /*
    for i = 1 to n − k + 1 do
        max = A[i];
        for j = 1 to k − 1 do
            if A[i + j] > max then
                max = A[i + j];
        print(max)
    */

    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\n Output: max values in moving windows of size %d\n", k);
    int i;
    int j;
    int max=0;
    for(i=1; i<= (n-k+1); ++i){
        max = A[i];
        for(j = 1; j<= (k - 1); ++j){
            if (A[i + j] > max){
                max = A[i + j];
            }
        }
        printf("\n i= %d, max= %d",i,max);
    }
    printf("\n");
}


//## Own integer array print function
void print_digit_array(int arr_digit[], int arr_digit_len){
    int i,arr_elem;
    printf("\n");
    for (i=0;i<arr_digit_len;++i){
        arr_elem=arr_digit[i];
        printf(" Info: array[%d]: %d\n", i,arr_elem);
    }
    printf("\n");
}
