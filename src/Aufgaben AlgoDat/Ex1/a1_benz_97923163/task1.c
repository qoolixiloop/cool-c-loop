//Exercise 1
//Roland Benz
//97-923-163

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//## Task
/*
 * Task 1. Given a string of characters, write a program in C that uses the func-
tion void reverse(char word[], char reverseString[]) to reverse a string.
Your program should first print a prompt asking the user to type a string and
then print the reverse of the input string. An input/output example is illus-
trated below (input is typeset in bold):
Type a string: Hello
Reverse string: olleH
*/

//## Forward Declarations
int reverse_order_in_array(char arr_char[], char arr_char_reverse[]);
void print_char_array(const char* arr_char, int arr_char_len);
#define arr_maxlen 10

//## Main
int task1(void){

    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Hello from task1: reverse array order!\n");

    //# character array declaration
    char arr_char[arr_maxlen]={0};
    char arr_char_reverse[arr_maxlen]={0};

    //# calculate array length
    //(for debugging purposes)
    //returns arr_maxlen
    int arr_char_len = sizeof(arr_char) / sizeof(char);
    printf(" Info: arr_char_len: %d\n", arr_char_len);

    //# ask for user input and console output
    printf(" Type for example <Test>: \n");
    scanf("%s", arr_char);
    printf("\n You typed: %s\n", arr_char);

    //# check user input
    //(for debugging purposes)
    //gcc adds a 0 at the end of a char array
    // that has been filled with scanf
    //include string.h for c-function strlen()
    // returns no of chars before 0 occurs
    int str_len=strlen(arr_char);
    printf(" Info: str_len: %d\n", str_len);

    //# own print function
    //(what's inside the array)
    print_char_array(arr_char, arr_char_len);

    //# task: reverse the user input
    reverse_order_in_array(arr_char,arr_char_reverse);
    printf(" Output reverse string: %s\n", arr_char_reverse);
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    return 0;
}

//## Algo
int reverse_order_in_array(char arr_char[], char arr_char_reverse[]){
/*
 * arguments: two pointers to char arrays
 * arr_char[]: input array remains unchanged
 * arr_char_reverse[]: output array changes
 *
 * output: reverses order of elements in character array
 *
 * remark:characters are stored as ascii code integers
 * ("\0" does not work, use 0 instead.)
*/

    int i;
    int count_chars;

    //# determine length of char array
    //(iterate until a 0 occurs)
    count_chars=0;
    while (arr_char[count_chars]!=0){
        //printf(" Debug:, count_chars: %d:%d\n",
        //       count_chars, arr_char[count_chars]);
        count_chars++;
    }

    //# fill output array
    //(write elements in reversed order)
    for (i=0;arr_char[i]!=0; i++){
        arr_char_reverse[count_chars-i-1]=arr_char[i];
    }

    //# output array
    //(add a 0 as last element)
    arr_char_reverse[count_chars]=0;

    return 0;
}


