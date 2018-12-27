//Roland Benz 97-923-163
//gcc -Wall task1.c -o task1

#include <stdio.h>
#include <math.h>

//## Forward declarations
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
#define arr_maxlen 50

int main(void)
{
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Hello from task1!\n");

    //# integer array declaration
    int arr_int[arr_maxlen]={0};
    int arr_int_len;

    //# ask for user input
    printf(" Type for example <3 8 9 1 7 end>: \n");
    arr_int_len = read_digit_array(arr_int);
    printf("\n You typed: %d numbers\n", arr_int_len);
    print_digit_array(arr_int, arr_int_len);

    //# invoke algo
    /*Note: You can copy the output of your program and use it on
     * http://www.webgraphviz.com/ to view your max-heap in the form
     * of a binary tree, as illustrated on the right figure.
    */
    build_max_heap(arr_int, arr_int_len);
    printf("\n array as max heap:\n");
    print_max_heap(arr_int, arr_int_len);


    //# ask for user input
    printf(" Type for example <4 3 2 5 6 7 8 9 12 1 end>: \n");
    arr_int_len=read_digit_array(arr_int);
    printf("\n You typed: %d numbers\n", arr_int_len);
    print_digit_array(arr_int, arr_int_len);

    //# invoke algo
    heap_sort(arr_int, arr_int_len);
    printf("\n sorted array after heap_sort:\n");
    print_digit_array(arr_int, arr_int_len);


    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    return 0;
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








