#include <stdio.h>
//gcc -Wall task4.c -o task4

//## Forward declarations
int permutation(char A[], char B[]);
int char_array_length(char arr_char[]);
#define arr_maxlen 50
#define ascii_chars 128

struct dict{
    int values[ascii_chars];
    int length;
};

int main(void)
{
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Hello from task4!\n");

    //# character array declaration
    char arr_char_A[arr_maxlen]={0};
    char arr_char_B[arr_maxlen]={0};

    //# ask for user input
    printf(" Type for example <abab> (no spaces): \n");
    scanf("%s", arr_char_A);

    printf(" Type for example <aabb> (no spaces): \n");
    scanf("%s", arr_char_B);

    printf("\n info: You typed A = %s", arr_char_A);
    printf("\n info: You typed B = %s", arr_char_B);


    //# invoke algo
    int out;
    out=permutation(arr_char_A, arr_char_B);
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    if (out==1){
        printf("\n Output: A and B are permutations\n ");
    }else{
        printf("\n Output: A and B are not permutations\n ");
    }
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    return 0;
}


//## Algo
int permutation(char A[], char B[]){
/*
* Include a function int permutation(char A[], char B[])
* which returns 1 if B[] is a permutation of A[], and 0 otherwise.
*/
    //check length to stop algo early
    int len_A=char_array_length(A);
    int len_B=char_array_length(B);
    printf("\n info: length_A=%d, length_B=%d", len_A, len_B );
    if (len_A!=len_B){
        printf("\n info: not the same length, %d != %d", len_A, len_B );
        return 0; //not the same length
    }else if (len_A==0){
        printf("\n info: length = %d", len_A);
        return 1; //length 0
    }else if (len_A==1){
        if (A[0]==B[0]){
            printf("\n info: length = %d, same value", len_A);
            return 1; // length 0, same value
        }else{
            printf("\n info: length = %d, not the same value", len_A);
            return 0; // length 0, different value
        }
    }

    //create a dictionary {ascii, count} for each array
    struct dict dict_A={{0},0};
    dict_A.length=ascii_chars;
    struct dict dict_B={{0},0};
    int cnt_A;
    int cnt_B;
    int i;
    for (i=0;i<len_A; i++){
        int A_char_as_int=(int)A[i];
        int B_char_as_int=(int)B[i];

        cnt_A=dict_A.values[A_char_as_int];
        cnt_B=dict_B.values[B_char_as_int];

        dict_A.values[A_char_as_int]=cnt_A+1;
        dict_B.values[B_char_as_int]=cnt_B+1;
    }

    //print dictionaries as info
    for (i=0;i<dict_A.length; i++){
        cnt_A=dict_A.values[i];
        cnt_B=dict_B.values[i];
        if (cnt_A!=0 || cnt_B!=0){
            if (cnt_A!=0 && cnt_B!=0){
                printf("\n info: ascii=%d, char=%c, cnt_A=%d, cnt_B=%d", i, i, cnt_A, cnt_B);
            }else{
                printf("\n info: ascii=%d, char=%c, cnt_A=%d, cnt_B=%d, !!!", i, i, cnt_A, cnt_B);
            }

        }
    }

    //compare dictionaries for output 0 or 1
    for (i=0;i<dict_A.length; i++){
        cnt_A=dict_A.values[i];
        cnt_B=dict_B.values[i];
        if (cnt_A!=cnt_B){
            return 0;
        }
    }
    return 1;

}

int char_array_length(char arr_char[]){

    //# determine length of char array
    //(iterate until a 0 occurs)
    int count_chars=0;
    while (arr_char[count_chars]!=0){
        count_chars++;
    }
    return count_chars;
}
