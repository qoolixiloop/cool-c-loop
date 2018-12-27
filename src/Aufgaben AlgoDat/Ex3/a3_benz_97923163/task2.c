//Roland Benz 97-923-163
//gcc -Wall task2.c -o task2

#include <stdio.h>

//## Forward declarations
void quick_sort(int arr_digit[], int index_low, int index_high);
void quick_sort_median(int arr_digit[], int index_low, int index_high, int pivoting_mode);
int median(int arr_digit[], int index_low, int index_high);
void swap_elements(int arr_digit[], int index_i, int index_j);
int partition_hoare(int arr_digit[], int index_low, int index_high, int pivoting_mode);
int read_digit_array(int arr_digit[]);
void print_digit_array(int arr_digit[], int arr_digit_len);
#define arr_maxlen 50

int main(void)
{
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Hello from task2a!\n");

    //# integer array declaration
    int arr_int[arr_maxlen]={0};
    int arr_int_len;
    int array_int_first=0;

    //# ask for user input
    printf(" Type for example <1 0 7 9 6 2 5 8 4 3 end>: \n");
    printf(" Test with <4 3 2 5 6 7 8 9 12 1 end>: \n");
    arr_int_len = read_digit_array(arr_int);
    printf("\n You typed: %d numbers\n", arr_int_len);
    print_digit_array(arr_int, arr_int_len);

    //# invoke algo
    quick_sort(arr_int,array_int_first, arr_int_len-1);
    printf("\n sorted array after quick_sort:\n");
    print_digit_array(arr_int, arr_int_len);

    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Hello from task2b!\n");

    //# ask for user input
    printf(" Type for example <8 4 2 0 9 6 3 7 end>: \n");
    arr_int_len = read_digit_array(arr_int);
    printf("\n You typed: %d numbers\n", arr_int_len);
    print_digit_array(arr_int, arr_int_len);

    //# pivoting mode
    int pivoting_mode;
    printf("\n Choose the pivoting mode <0> array end, <1> median: \n");
    scanf("%d", &pivoting_mode);

    //# invoke algo
    quick_sort_median(arr_int, array_int_first, arr_int_len-1, pivoting_mode);
    printf("\n sorted array after quick_sort:\n");
    print_digit_array(arr_int, arr_int_len);


    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    return 0;
}

//## Algo
// recursive sort of sub array
void quick_sort(int arr_digit[], int index_low, int index_high){
/*sorts the area of array
 * restricted by indices low, high.
*/
    //do as long as index_low is lower than index_high
    if (index_low < index_high) {
        //determine index_middle
        //move elements:
        //small elements to the left of index_middle
        //large elements to the right of index_middle
        int index_middle = partition_hoare(arr_digit, index_low, index_high, 0);
        //recursive call
        //left side of index middle
        quick_sort(arr_digit, index_low, index_middle-1);
        //recursive call
        //right sid of index middle (inclusive)
        quick_sort(arr_digit, index_middle, index_high);
    }
    return;
}

// recursive sort of sub array
void quick_sort_median(int arr_digit[], int index_low, int index_high, int pivoting_mode){
/*sorts the area of array
 * restricted by indices low, high.
 * Extend the program you created so that function quick_sort
 * has one more argument int choice that determines the way
 * the pivot will be chosen and can be assigned the values 1 or 0.
 * If choice=1, the function shall check the three array elements
 * A[low], A[bottom(low+high/2)] and A[high] and use their median as a pivot.
*/
    //pivoting_mode==1 (value of median)
    //stop if index_high becomes equal or smaller than index_low
    if ( (pivoting_mode == 1) && ((index_high-index_low) <= 1) )
            return;
    //pivoting_mode == 0 (value of index_high)
    //do as long as index_low is lower than index_high
    if (index_low < index_high) {
        //determine pivot
        //determine index_middle
        //move elements:
        //small elements to the left of index_middle
        //large elements to the right of index_middle
        int index_middle = partition_hoare(arr_digit, index_low, index_high, pivoting_mode);
        //recursive call
        //left side of index middle
        quick_sort_median(arr_digit, index_low, index_middle-1, pivoting_mode);
        //recursive call
        //right sid of index middle (inclusive)
        quick_sort_median(arr_digit, index_middle, index_high, pivoting_mode);
    }

}

//## Auxilliary functions for quick_sort and quick_sort_median
//determine median of three array element values
int median(int arr_digit[], int index_low, int index_high){
/* returns the median
 * of the array values
 * A[low], A[bottom(low+high/2)] and A[high]
*/
    int index_mid = (index_low + index_high)/2;

    //return the median (=2)
    //mid: 2 or 3
    //low: 1 or 2
    if (arr_digit[index_low] < arr_digit[index_mid])
    {
        //low: 2
        //high: 1
        if(arr_digit[index_low] >= arr_digit[index_high]){
            return arr_digit[index_low];
        }
        //high: 3
        //mid: 2
        else if(arr_digit[index_mid] < arr_digit[index_high]){
            return arr_digit[index_mid];
        }
    }
    //low: 2 or 3
    //mid: 1 or 2
    else{
        //high: 3
        //low: 2
        if(arr_digit[index_low] < arr_digit[index_high]){
            return arr_digit[index_low];
        }
        //mid: 2
        //high: 1
        else if(arr_digit[index_mid] >= arr_digit[index_high]){
            return arr_digit[index_mid];
        }
    }
    //use normal case if
    //all three values are identical
    return arr_digit[index_high];
}

//one complete partitioning of sub array
int partition_hoare(int arr_digit[], int index_low, int index_high, int pivoting_mode){
/* rearranges the area of the array restricted
 * by indices low, high based on the element array[high],
 * that is chosen as the pivot.
*/

    int pivot;
    int index_i;
    int index_j;

    //decrement left side index
    index_i = index_low-1;
    //increment right side index
    index_j = index_high+1;

    //determine pivot:
    //value of index_median element
    if (pivoting_mode == 1)
    {
        pivot = median(arr_digit, index_low, index_high);
    }
    //determine pivot:
    //value of index_high element
    else {
        pivot = arr_digit[index_high];
    }

    //given the determined pivot:
    //move elements:
    //small elements to the left of index_middle
    //large elements to the right of index_middle
    //pivot into index_middle
    while (1)
    {

        //increment left side index_i until
        //element value becomes larger than pivot
        do index_i++; while (arr_digit[index_i] < pivot);

        //decrement right side index_j until
        //element value becomes smaller than pivot
        do index_j--; while (arr_digit[index_j] > pivot);

        //swap if:
        //value of left side element
        //is smaller than
        //value of right side element
        if (index_i<index_j) {
            swap_elements(arr_digit, index_i, index_j);
        }
        //return left side index
        //as determined new index_middle
        else {
            return index_i;
        }
    }
}

//swap two elements in an array
void swap_elements(int arr_digit[], int index_i, int index_j){
/* exchanges the element of index i
 * with the element of index j
*/
    //swap values of index_i and index_j
    int temp = arr_digit[index_i];
    arr_digit[index_i] = arr_digit[index_j];
    arr_digit[index_j] = temp;
}

//## Own integer array function
int read_digit_array(int arr_digit[]){
/*reads a given array from the console
*/
    int index = 0;

    //read user input from console
    //as long as a digit follows a space
    while(scanf("%d", &arr_digit[index]) == 1)
        index++;
    scanf("%*s");

    //index holds:
    //number of elements in array (=length)
    return index;
}

void print_digit_array(int arr_digit[], int arr_digit_len){
/*prints a given array to the console
*/
    int i,arr_elem;
    printf("\n");
    for (i=0;i<arr_digit_len;++i){
        arr_elem=arr_digit[i];
        printf(" Info: array[%d]: %d\n", i,arr_elem);
    }
    printf("\n");
}





