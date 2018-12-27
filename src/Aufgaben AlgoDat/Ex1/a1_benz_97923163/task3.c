//Exercise 1
//Roland Benz
//97-923-163

#include <stdio.h>
#include<stdlib.h>
#include <string.h> /* memset */

//## Task
/*Task 3. Consider an array A[0...nA-1] with nA integers, and an array
B[0...nB -1] with nB integers. Array A does not include duplicated elements.
Array B may contain duplicated elements. Arrays A and B are both sorted in
increasing order. Write a program in C that reads arrays A and B and prints all
pairs of the form (v,t), where v corresponds to a value in array A and t to the
number of times it appears in array B. [10 points]
*/

//## Forward Declarations
struct arr_input{
    //Arrays sorted in increasing order
    int arr_int_a[14];
    int arr_int_b[21];
    const int arr_len_a;
    const int arr_len_b;
};

//int count_occurences_of_arr1_in_arr2(int *arr_int_a, int arr_int_b[], int arr_out[][2]);
int count_occurences_of_arr1_in_arr2(struct arr_input *arr_in, int arr_out[][2]);

//## Main
int task3(void){

    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Hello from task3: count frequencies!\n");

    //# Allocate memory for struct instance and initialize arrays
    //memcpy(struct->array, some_array, sizeof(struct->array));
    struct arr_input arr_in ={
        {1,2,3,4,6,7,9,11,22,23,25,28,45,67},
        {2,2,3,4,4,8,8,8,15,25,26,26,33,37,43,44,45,45,45,45,78},
        sizeof(arr_in.arr_int_a) / sizeof(int),
        sizeof(arr_in.arr_int_b) / sizeof(int)
    };

    //# Invoke Algo
    int arr_out[arr_in.arr_len_a][2];
    //count_occurences_of_arr1_in_arr2(arr_int_a, arr_int_b, arr_out);
    count_occurences_of_arr1_in_arr2(&arr_in, arr_out);

    //# Print
    int i;
    printf("\n Info: arr_in.arr_int_a\n");
    for (i=0;i<arr_in.arr_len_a;++i){
        printf(" %d,",arr_in.arr_int_a[i]);
    }
    printf("\n\n Info: arr_in.arr_int_b\n");
    for (i=0;i<arr_in.arr_len_b;++i){
        printf(" %d,",arr_in.arr_int_b[i]);
    }
    printf("\n\n Info: arr_out\n");
    for (i=0;i<arr_in.arr_len_a;++i){
        printf(" (%d,%d)\n",arr_out[i][0], arr_out[i][1]);
    }
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    return 0;
}

//## Algo
int count_occurences_of_arr1_in_arr2
        (struct arr_input *arr_in, int arr_out[][2]){
/*
* arguments: pointers to struct and int array,
* arr_in: struct containing two arrays and its sizes, remain unchanged
* arr_out[][2]: output array changes,
*               first column: element of first array,
*               second column: counting info
*
* output: how often is each digit in one array store in the other array
*
*/

    //returns the allocated no of indices
    //(for debugging purposes)
    int arr_len_a=sizeof(arr_in->arr_int_a) / sizeof(int);
    int arr_len_b=sizeof(arr_in->arr_int_b) / sizeof(int);
    //printf(" Info: %d : %d : %d : %d\n",
    //       arr_len_a,arr_len_b,arr_in->arr_len_a,arr_in->arr_len_b);

    //ways to access input array
    //1)copy array addresses to pointers
    //2)copy arrays in new arrays with memcpy (local copy)
    int *arr_int_a=arr_in->arr_int_a;
    int *arr_int_b=arr_in->arr_int_b;

    /*
    int arr_int_a[14];
    int arr_int_b[21];
    memcpy(arr_int_a, arr_in->arr_int_a, sizeof(arr_in->arr_int_a));
    memcpy(arr_int_b, arr_in->arr_int_b, sizeof(arr_in->arr_int_b));
    */

    int arr_elem_a, arr_elem_b;
    int i,j, cnt;

    //Take one element of arr1 and compare it
    //with all elements of arr2
    for (i=0;i<arr_len_a;++i){
        cnt=0;
        arr_elem_a=arr_int_a[i];
        for (j=0;j<arr_len_b;++j){
            arr_elem_b=arr_int_b[j];
            //comparison:
            //for each hit increase counter
            if (arr_elem_a==arr_elem_b){
                cnt++;
            }
        }
        //storage in output array
        arr_out[i][0]=arr_elem_a;
        arr_out[i][1]=cnt;
    }
    return 0;
}
