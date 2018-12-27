//Exercise 1
//Roland Benz
//97-923-163

#include <stdio.h>
#include<stdlib.h>
#include <ctype.h>

//## Task
/*
 * Task 2. Consider an array A[0...n-1] with n integer values and an integer x.
Write a program in C that prints proper prompt messages, reads the elements
of A, reads x and then prints the number of copies of x in A. An input/output
example is illustrated below (input is typeset in bold):
Elements of A separated by spaces (non-number to stop): 1 2 3 2 2 5 end
Type x: 3
Copies = 1
*/


//## Forward Declarations
int count_same_digits_in_array(int a[], int size, int x);
void print_digit_array(int* arr_digit, int arr_digit_len);
#define arr_maxlen 10

//## Main
int task2(void){

    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Hello from task2: count frequencies!\n");

    int i, no_digits;
    int same_digit;
    int arr_int[arr_maxlen]={0};

    //# calculate array length
    //(for debugging purposes)
    int arr_int_len = sizeof(arr_int) / sizeof(int);
    printf(" Info: arr_int_len=%d\n", arr_int_len);

    //# first user input
    //scanf liest bis zum ersten Blank, speichert den Wert in arr_int[0],
    //prüft ob der Inhalt ein Digit ist, und gibt 1 für True zurück
    //bei der Eingabe end gibt scanf 0 zurück für False und arr_int[6] bleibt leer
    //int arr_int[arr_maxlen] = {1,2,3,2,2,5};
    printf(" Type for example <1 2 3 2 2 5 end>: \n");
    i=0;
    while (scanf("%d", &arr_int[i])==1){i++;}
    no_digits=i;
    printf("\n You typed: %d numbers\n", no_digits);
    print_digit_array(arr_int, arr_int_len);

    //#Second user input
    //Ohne scanf("%*s") stoppt das Programm nicht für
    //die zweite Eingabe
    //scanf verlangt eine char Adresse als Input,
    //welche der Pointer Variablen const char* zugewiesen wird
    //same_digit=2;
    scanf("%*s");
    printf(" Type for example: <2>: \n");
    scanf("%d",&same_digit);
    printf("\n You typed: %d\n", same_digit);

    //#Algo invocation
    int out=count_same_digits_in_array
            (arr_int, no_digits, same_digit);
    printf(" Same digits = %d\n",out);
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    return 0;
}

//## Algo
int count_same_digits_in_array
        (int a[], int size, int same_digit){
/*
* arguments: pointer to int array, two integers
* a[]: input array remains unchanged
* size: elements entered into a[]
* same_digit: search for this element in a[]
*
* output:how often same_digit is stored in a[]
*
*/

    int count=0;
    int i;
    int arr_elem;

    //Prüfe ob x in a[i] ist,
    //wenn ja erhöhe den counter   
    for (i=0;i<size;i++){
        arr_elem=a[i];
        if (arr_elem==same_digit){
            count++;
        }
    }
    return count ;
}


