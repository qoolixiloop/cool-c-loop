//Roland Benz 97-923-163
//gcc -Wall task3.c -o task3

#include <stdio.h>
#include<time.h>

//## Forward declarations heap_sort
void heap_sort(int arr_digit[], int arr_digit_len);
void build_max_heap(int arr_digit[], int arr_digit_len);
void heapify(int arr_digit[], int index_low, int index_high);
int parent_index(int index);
int left_child_index(int index);
int right_child_index(int index);
void print_max_heap(int arr_digit[], int arr_digit_len);
void print_max_heap_recursion(int arr_digit[], int index_low, int arr_digit_len);
int read_digit_array(int arr_digit[]);
void print_digit_array(int arr_digit[], int arr_digit_len);

//## Forward declarations quick_sort
void quick_sort(int arr_digit[], int index_low, int index_high);
void quick_sort_median(int arr_digit[], int index_low, int index_high, int pivoting_mode);
int median(int arr_digit[], int index_low, int index_high);
void swap_elements(int arr_digit[], int index_i, int index_j);
int partition_hoare(int arr_digit[], int index_low, int index_high, int pivoting_mode);
int read_digit_array(int arr_digit[]);
void print_digit_array(int arr_digit[], int arr_digit_len);

//## Forward declarations bubble_sort
void bubble_sort(int arr_digit[], int arr_digit_len);

//## Forward declarations
void read_file(char filename[], int output[], int *n);
#define arr_maxlen 120000

int main(void)
{
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Hello from task3!\n");

    clock_t start;
    clock_t end;
    float seconds;
    int algorithm;
    int input_file;
    char *file_name;
    int number_of_integers_read;

    //array
    int arr_len = arr_maxlen;
    int arr_int[arr_maxlen];


    // user input
    printf(" algorithm: 0=bubble_sort 1=heap_sort 2=quick_sort 3=quick_sort_median\n");
    printf(" input file: 0=random 1=ordered 2=reverse\n");
    printf(" enter for example: <1 2>\n");
    scanf("%d %d", &algorithm, &input_file);

    //read file into array
    switch (input_file) {
        case 0: file_name = "/home/benzro/Documents/QT_Creator/Uebungen_Informatik2_AlgoDat/Informatik2_AlgoDat_Ex3/task3_sort_algo_comparison/integer_datasets/random.txt";
            break;
        case 1: file_name = "/home/benzro/Documents/QT_Creator/Uebungen_Informatik2_AlgoDat/Informatik2_AlgoDat_Ex3/task3_sort_algo_comparison/integer_datasets/ordered.txt";
            break;
        case 2: file_name = "/home/benzro/Documents/QT_Creator/Uebungen_Informatik2_AlgoDat/Informatik2_AlgoDat_Ex3/task3_sort_algo_comparison/integer_datasets/inverse.txt";
            break;
    }

    read_file(file_name, arr_int, &number_of_integers_read);
    printf(" info %d\n", number_of_integers_read);

    // your sorting function
    start = clock();
    switch (algorithm) {
        case 0: bubble_sort(arr_int, arr_len);
            break;
        case 1: heap_sort(arr_int, arr_len);
            break;
        case 2: quick_sort(arr_int, 0, arr_len-1);
            break;
        case 3: quick_sort_median(arr_int, 0, arr_len-1, 1);
            break;
    }
    end = clock();

    // console output
    seconds = (float)(end - start) / CLOCKS_PER_SEC;
    printf("secs: %f\n", seconds);

    //Zusammenfassung
    /*              bubble || heap || quick || quick_median
     * random      too long   0.13     0.05    does not work
     * ordered     too long   0.12   too long    correctly
     * inverse     too long   0.11   too long
     *
    */


    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    return 0;

}

void read_file(char filename[], int output[], int *n) {
/*read the given files
 * filename: is the name of an input file,
 * output: is the output array containing integers of the input file,
 * n: stores the size of the array (number of elements in the input file)
*/
    FILE *f;
    int i;
    f=fopen(filename, "r");
    i=0;
    printf(" info 1\n");
    while(fscanf(f, "%d", &output[i]) == 1) i++;
    printf(" info 2\n");
    *n=i-1;
    fclose(f);
}


//## Algo
void heap_sort(int arr_digit[], int arr_digit_len){
/*sorts the array in ascending order.
 * Implement it according to the algorithm HeapSort(A) provided
 * in the slides, using the function BuildHeap(A)
*/

    //index to virtually reduce the array
    //highest values have index larger than s
    int sub_index = arr_digit_len;
    int root_index=0;

    //heapify the whole array once at the beginning
    build_max_heap(arr_digit, arr_digit_len);

    //move highest values at the end of the array
    //heapify the remaining sub array
    int index;
    for (index = arr_digit_len-1; index >= 1; index--)
    {
        //swap root node (which has max value)
        // with lowest remaining internal node
        int temp = arr_digit[index];
        arr_digit[index] = arr_digit[root_index];
        arr_digit[root_index] = temp;

        //reduce remaining sub array size
        //(protect highest values at indexes
        //larger than sub_index)
        sub_index = sub_index - 1;

        //heapify the remaining sub array
        heapify(arr_digit, root_index, sub_index);
    }
}

//## heapify whole array once at the beginning
void build_max_heap(int arr_digit[], int arr_digit_len){
/* Implement it according to the algorithm
 * BuildHeap(A) provided in the slides.
*/
    //heapify only internal nodes
    //leaves are already heapified
    int index;
    for (index = arr_digit_len/2; index >= 0; index--)
    {
        //heapity sub array
        //from internal node index to the end
        heapify(arr_digit, index, arr_digit_len);
    }

}

//## heapify sub arrays
void heapify(int arr_digit[], int index_low, int index_high){
/* heapifies in array with indexes
 * from index_low to index_high
 * three elements:
 *  index_low (=parent)
 *  child_left
 *  child_right
*/
    //nodes under consideration
    //temporary indices middle, left, right
    int parent = index_low;
    int middle = parent;
    int left = left_child_index(parent);
    int right = right_child_index(parent);

    //left index within array &&
    //value of left index larger than those of its parent
    //than left becomes new parent candidate
    if ((left <= index_high-1) && (arr_digit[left] > arr_digit[middle]))
        //left becomes new parent candidate
        middle = left;

    //right index within array &&
    //value of right index larger than those of its parent
    //than right becomes new parent index
    if ((right <= index_high-1) && (arr_digit[right] > arr_digit[middle]))
        //right becomes new parent index
        middle = right;

    //now:
    //middle is assigned:
    //the index of either
    //left_child, right_child or index_low (=parent)
    //which holds the largest value

    //swap values
    //but only if:
    //parent (index_low)
    //didn't hold the largest value
    //from the beginning
    if (index_low != middle) {

        //swap:
        //largest value becomes new parent (=index_low)
        int temp = arr_digit[middle];
        arr_digit[middle] = arr_digit[index_low];
        arr_digit[index_low] = temp;

        //after swap:
        //new heapify becomes necessary
        //because of the swap the tree
        //below may no longer be a heap
        heapify(arr_digit,middle,index_high);
    }
}

//## Auxilliary functions for heapify
int parent_index(int index){
    return index/2;
}

int left_child_index(int index){
    return (index+1)*2-1;
}

int right_child_index(int index){
    return (index+1)*2;
}

//## print whole max heap
void print_max_heap(int arr_digit[], int arr_digit_len){
/*prints the created max-heap to the console in the format
 * graph g { (all the edges in the form NodeA -- NodeB) },
 * where each edge should be printed in a separate line.
 * The ordering of the edges is not relevant.
*/

    int root_index=0;

    //start recursion
    printf(" graph g {\n");
    print_max_heap_recursion(arr_digit, root_index, arr_digit_len);
    printf(" }\n\n");

}

//## print sub elements of max heap (print whole max heap recursively)
void print_max_heap_recursion(int arr_digit[], int index_low, int arr_digit_len){
/* print parent, left child, right child
 * recusive call with index_low==left child
 * recursive call with index_low==right child
*/

    //nodes under consideration
    int parent = index_low;
    int left = left_child_index(parent);
    int right = right_child_index(parent);

    //base case:
    //if left child out of range
    //then return
    if (left > arr_digit_len-1) {
        return;
    }

    //if left child last element
    //then there is no right child element
    else if (left == arr_digit_len-1) {
        //print: parent -- left child
        printf("  (%d -- %d)\n", arr_digit[parent], arr_digit[left]);
        return;

    }
    //if left child is not last element
    //then there is a right child element
    //and probably also grand children
    else {
        //print: parent -- left child
        //print: parent -- right child
        printf("  (%d -- %d)\n", arr_digit[parent], arr_digit[left]);
        printf("  (%d -- %d)\n", arr_digit[parent], arr_digit[right]);

        //print grand children of parent
        //children of left child
        print_max_heap_recursion(arr_digit, left, arr_digit_len);
        //children of right child
        print_max_heap_recursion(arr_digit, right, arr_digit_len);
    }
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

//## Algo
void bubble_sort(int arr_digit[], int arr_digit_len)
{
    //base case
    if(arr_digit_len < 2)
        return;

    int i,j;
    for(i = arr_digit_len; i > 1; i--)
    {
        for(j = 1; j < i; j++)
        {
            if(arr_digit[j] < arr_digit[j-1])
            {
                int tmp = arr_digit[j];
                arr_digit[j] = arr_digit[j-1];
                arr_digit[j-1] = tmp;
            }
        }
    }
}

