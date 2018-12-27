//Exercise 1
//Roland Benz
//97-923-163

#include <stdio.h>
#include<stdlib.h>
#include <string.h> /* memset */

//## Task
/*Task 4. Before a football game starts, team A and team B shall take a group
picture. One team is in the front row and the other team in the back row. To
get a nice picture the photographer requires a person in the front row to be
shorter than the corresponding person in the back row. Given arrays A and B,
both of size n, whose elements are the heights of the team members, check if it
is possible to make a nice picture.
Write a program in C that uses the function int team photo(int A[],
int B[], int size) to print “TRUE” if it is possible to arrange two teams as
described, and print “FALSE” otherwise. Hint: Implement and use a function
void bubblesort(int a[], int size) to solve the task. [20 points]
*/

//## Forward Declarations
#define team_size 14
int team_photo(int arr_a_sorted[],int arr_b_sorted[], int arr_size);
void bubble_sort(int arr_in[], int *arr_out, int arr_size);
void bubble_sort2(int arr_in[], int **arr_out, int arr_size);
void bubble_sort3(int arr_in[], int arr_size);
void print_digit_array(int arr_digit[], int arr_digit_len);


//## Main
int task4(void)
{
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Hello from task4: bubble sort!\n");

    //# initialize team heights array
    int team_liliput[team_size]={156,159,145,186,167,172,142,91,184,123,148,182,191,134};
    int team_gulliver[team_size]={201,192,176,154,198,186,193,165,187,182,197,212,322,159};
    printf("\n initial arrays\n");
    print_digit_array(team_liliput, team_size);
    print_digit_array(team_gulliver, team_size);

    //# call bubble sort (first version)
    //memory of sorted arrays is allocated next
    //address of first array elements are passed on to bubble sort
    //output via input argument: changes inside have effect outside
    int team_liliput_sorted[team_size];
    int team_gulliver_sorted[team_size];
    //&team_liliput_sorted[0] is conceptually equivalent to team_liliput_sorted[]
    bubble_sort(team_liliput, &team_liliput_sorted[0], team_size);
    bubble_sort(team_gulliver, team_gulliver_sorted, team_size);
    printf("\n sorted arrays after bubble sort (first version): \n");
    print_digit_array(team_liliput_sorted, team_size);
    print_digit_array(team_gulliver_sorted, team_size);
    //check that input arrays remain unchanged
    printf("\n initial arrays after bubble sort (first version): \n");
    print_digit_array(team_liliput, team_size);
    print_digit_array(team_gulliver, team_size);

    //# call bubble sort(second version)
    //pointers for sorted arrays are declared next
    //addresses of pointers are passed on to bubble sort
    //inside bubblesort memory is allocated and assigned to pointers
    //output via input argument: changes inside have effect outside
    int *team_liliput_sorted2;
    int *team_gulliver_sorted2;
    bubble_sort2(team_liliput, &team_liliput_sorted2, team_size);
    bubble_sort2(team_gulliver, &team_gulliver_sorted2, team_size);
    printf("\n sorted arrays after bubble sort (second version): \n");
    print_digit_array(team_liliput_sorted2, team_size);
    print_digit_array(team_gulliver_sorted2, team_size);
    //check that input arrays remain unchanged
    printf("\n initial arrays after bubble sort (second version): \n");
    print_digit_array(team_liliput, team_size);
    print_digit_array(team_gulliver, team_size);

    //# call bubble sort(third version)
    //changes are made directly to the input arrays
    //no extra memory allocated inside bubble sort
    bubble_sort3(team_liliput, team_size);
    bubble_sort3(team_gulliver,team_size);
    //check that input arrays have changed
    printf("\n sorted arrays after bubble sort (third version): \n");
    print_digit_array(team_liliput, team_size);
    print_digit_array(team_gulliver, team_size);

    //# invoke algo (after bubble sort first version)
    int out;
    out=team_photo(team_liliput_sorted,team_gulliver_sorted, team_size);
    if (out==1){
        printf(" output: click! ");
    }else{
        printf(" output: team shuffle needed! ");
    }

    //# invoke algo (after bubble sort second version)
    out=team_photo(team_liliput_sorted2,team_gulliver_sorted2, team_size);
    if (out==1){
        printf(" output: click! ");
    }else{
        printf(" output: team shuffle needed! ");
    }

    //# invoke algo (after bubble sort third version)
    out=team_photo(team_liliput, team_gulliver, team_size);
    if (out==1){
        printf(" output: click! ");
    }else{
        printf(" output: team shuffle needed! ");
    }
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    return 0;
}


//## Algo
int team_photo(int arr_a_sorted[],int arr_b_sorted[], int arr_size){
/*arguments: two pointer to equally sized and sorted arrays and one integer
 * arr_a_sorted[]: remains unchanged
 * arr_b_sorted[]: remains unchanged
 * arr_size: size of both arrays
 *
 *output: checks whether tuples (ai,bi) can paired up such that
 * ai is smaller than bi for all i or vice versa and returns true(1),
 * if no array is systematically smaller than the other it returns false(0)
*/
    //iterate through all elements
    //to return true sum_up must be zero or arr_size
    int i, sum_up=0;
    for (i=0;i<arr_size;++i){
        int element_ai=arr_a_sorted[i];
        int element_bi=arr_b_sorted[i];
        if (element_ai<element_bi){
            sum_up+=1;
        }else{
            sum_up+=0;
        }
    }
    if (sum_up==arr_size || sum_up==0){
        return 1;
    }
    return 0;
}

//int arr_out[] is conceptually equivalent to int * arr_out
void bubble_sort(int arr_in[], int *arr_out, int arr_size){
/*(Version 1)
 * arguments: pointers to two arrays and size of both arrays
 * arr_in[]: remains unchanged
 * *arr_out equivalent to arr_out[]: output array changes
 * arr_size: size of input and output array
 *
 *output: memcopy of input array is made, so that input array is uneffected
 *        from sorting. Sorting is carried out on the copy. Sorted copy is
 *        then memcopied to output array (allocated outside).
 *
Algo: BubbleSort(A)
for i = n to 2 do
for j = 2 to i do
if A[j]<A[j-1] then
t = A[j];
A[j] = A[j-1];
A[j-1] = t;
*/
    //local copy arr_in into arr
    int arr[arr_size];
    memcpy(arr, arr_in, sizeof(int)*arr_size);
    //print_digit_array(arr, arr_size);

    //Outer loop: from right to left
    //Inner loop: from left to right (stops at outer loop iterator)
    //Swap if left element is bigger than right element
    //At the end of each inner loop the remaining biggest
    //element left is moved to the left to its final position
    int i,j,tmp;
    for (i = arr_size ; i >=1 ; --i){
        for (j = 1 ; j < i; ++j){
            //Swap elements if larger element is left
            if (arr[j-1] > arr[j]){
                //memorize smaller right element
                //move bigger to the right
                //move smaller to the left
                tmp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = tmp;
            }
        }
    }
    //assign arr to pointer arr_out
    memcpy(arr_out, arr, sizeof(int)*arr_size);
}


void bubble_sort2(int arr_in[], int **arr_out, int arr_size){
/*(Version 2)
* arguments: pointer to one array, pointer to a pointer and size of array
* arr_in[]: remains unchanged
* **arr_out: this pointer hold the address of assigned pointer outside
*            malloc inside of function and
*            address assigned to dereferenced double pointer
*            which is the location of the outside pointer
* arr_size: size of input and output array
*
*output: new array pointer is declared because (dereferencing and
*        assigning to a double pointer stops execution).
*        malloc for new array and memcopy of input array is made
*        so that input array is uneffected from sorting.
*        Sorting is carried out on the copy.
*        Sorted copy is then assigned to output double pointer.

 * Algo: BubbleSort(A)
for i = n to 2 do
for j = 2 to i do
if A[j]<A[j-1] then
t = A[j];
A[j] = A[j-1];
A[j-1] = t;
*/

    //allocate memory of an array.
    //dereferencing and assigning to a double pointer
    //makes Ubuntu cry. Execution stops. Therefore,
    //a copy is needed or maybe there is another solution.
    int *arr;
    arr = malloc(arr_size*sizeof(int));

    //copy input to newly allocated memory
    memcpy(arr, arr_in, sizeof(int)*arr_size);
    //printf("\nDebug 0: \n");
    //print_digit_array(arr, arr_size);


    //Outer loop: from right to left
    //Inner loop: from left to right (stops at outer loop iterator)
    //Swap if left element is bigger than right element
    //At the end of each inner loop the remaining biggest
    //element left is moved to the left to its final position
    int i,j,tmp;
    for (i = arr_size ; i >=1 ; --i){
        for (j = 1 ; j < i; ++j){
            //Swap elements if larger element is left
            if (arr[j-1] > arr[j]){
                //memorize smaller right element
                //move bigger to the right
                //move smaller to the left
                tmp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = tmp;
            }
        }
    }

    //dereferenced double pointer, which is
    //the memory location of outside pointer,
    //and assign address of malloced array
    *arr_out=arr;
}


void bubble_sort3(int arr_in[], int arr_size){
/*(Version 3)
* arguments: pointers to one array and size of array
* arr_in[]: changes
* arr_size: size of input and output array
*
*output: arr_in[] is a pointer that gets assigned the
*        address of the outside array. Changes made to
*        memory location of inside pointer affects are
*        made to the outside array.
*
*
 * Algo: BubbleSort(A)
for i = n to 2 do
for j = 2 to i do
if A[j]<A[j-1] then
t = A[j];
A[j] = A[j-1];
A[j-1] = t;
*/
    //changes done directly to the input array memory
    //location of arr_in

    //Outer loop: from right to left
    //Inner loop: from left to right (stops at outer loop iterator)
    //Swap if left element is bigger than right element
    //At the end of each inner loop the remaining biggest
    //element left is moved to the left to its final position
    int i,j,tmp;
    for (i = arr_size ; i >=1 ; --i){
        for (j = 1 ; j < i; ++j){
            //Swap elements if larger element is left
            if (arr_in[j-1] > arr_in[j]){
                //memorize smaller right element
                //move bigger to the right
                //move smaller to the left
                tmp = arr_in[j];
                arr_in[j] = arr_in[j-1];
                arr_in[j-1] = tmp;
            }
        }
    }
}

/*From stackoverflow:
 *(about double pointers)
 *
How should I pass a pointer to a function and allocate memory
for the passed pointer from inside the called function?

Ask yourself this: if you had to write a function that
had to return an int, how would you do it?

You'd either return it directly:

int foo(void)
{
    return 42;
}

or return it through an output parameter by adding
a level of indirection (i.e., using an int* instead of int):

void foo(int* out)
{
    assert(out != NULL);
    *out = 42;
}

So when you're returning a pointer type (T*), it's the same
thing: you either return the pointer type directly:

T* foo(void)
{
    T* p = malloc(...);
    return p;
}

or you add one level of indirection:
T** out is a pointer that stores the address of a pointer
in main: T* out_; foo(&out_) stores the
address of pointer out_ in pointer out

void foo(T** out)
{
    assert(out != NULL);
    *out = malloc(...);
}
*/
