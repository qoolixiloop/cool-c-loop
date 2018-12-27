//Exercise 1
//Roland Benz
//97-923-163
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*Compile Project with:
gcc -c -pipe -std=c99 -g -Wall -W -fPIE  -I../a1_benz_97923163 -I. -I/usr/lib/i386-linux-gnu/qt5/mkspecs/linux-g++ -o main.o ../a1_benz_97923163/main.c
gcc -c -pipe -std=c99 -g -Wall -W -fPIE  -I../a1_benz_97923163 -I. -I/usr/lib/i386-linux-gnu/qt5/mkspecs/linux-g++ -o task1.o ../a1_benz_97923163/task1.c
gcc -c -pipe -std=c99 -g -Wall -W -fPIE  -I../a1_benz_97923163 -I. -I/usr/lib/i386-linux-gnu/qt5/mkspecs/linux-g++ -o task3.o ../a1_benz_97923163/task3.c
gcc -c -pipe -std=c99 -g -Wall -W -fPIE  -I../a1_benz_97923163 -I. -I/usr/lib/i386-linux-gnu/qt5/mkspecs/linux-g++ -o task2.o ../a1_benz_97923163/task2.c
gcc -c -pipe -std=c99 -g -Wall -W -fPIE  -I../a1_benz_97923163 -I. -I/usr/lib/i386-linux-gnu/qt5/mkspecs/linux-g++ -o task5.o ../a1_benz_97923163/task5.c
gcc -c -pipe -std=c99 -g -Wall -W -fPIE  -I../a1_benz_97923163 -I. -I/usr/lib/i386-linux-gnu/qt5/mkspecs/linux-g++ -o task6.o ../a1_benz_97923163/task6.c
gcc -c -pipe -std=c99 -g -Wall -W -fPIE  -I../a1_benz_97923163 -I. -I/usr/lib/i386-linux-gnu/qt5/mkspecs/linux-g++ -o task4.o ../a1_benz_97923163/task4.c
gcc -c -pipe -std=c99 -g -Wall -W -fPIE  -I../a1_benz_97923163 -I. -I/usr/lib/i386-linux-gnu/qt5/mkspecs/linux-g++ -o task7b.o ../a1_benz_97923163/task7b.c
gcc -c -pipe -std=c99 -g -Wall -W -fPIE  -I../a1_benz_97923163 -I. -I/usr/lib/i386-linux-gnu/qt5/mkspecs/linux-g++ -o task7a.o ../a1_benz_97923163/task7a.c
g++  -o a1_benz_97923163 main.o task1.o task3.o task2.o task5.o task6.o task4.o task7b.o task7a.o   -lGLU -lGL -lglut
*/
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>

/*
 * Submission
Please submit a folder a<exercise number> <family name> <matriculation
number>.zip where family name and matriculation number correspond to
your personal data. The folder should include the C files you created for each
of the tasks. Each C file should be named task<task number>.c and it should
include your personal data in the form of a comment on the top.
The zipped folder should be uploaded in the page of the course in OLAT in
the ‘‘Drop box’’ corresponding to Assignment 1 latest on Sunday, March
6th at 23:59.
Important Notes
 Include the library math.h (#include <math.h>). It will allow you to use
the functions pow and sqrt which are useful in some of the tasks.
*/


//## Forward Declarations
int task1(void);
int task2(void);
int task3(void);
int task4(void);
int task5(void);
int task6(void);
int task7a(void);
int task7b(int argc, char** argv);

//## Main
int main(int argc, char *argv[])
{

    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    //answer=0 to skip task
    int answer;

    printf("\nHello from main!\n");
    printf(" Exercise 1\n Roland Benz\n 97-923-163\n\n");
    printf("enter <1> to start task1, enter <0> to skip task1: ");
    scanf("%d", &answer);
    if (answer){task1();}

    printf("\nHello from main!\n");
    printf(" Exercise 1\n Roland Benz\n 97-923-163\n\n");
    printf("enter <1> to start task2, enter <0> to skip task2: ");
    scanf("%d", &answer);
    if (answer){task2();}

    printf("\nHello from main!\n");
    printf(" Exercise 1\n Roland Benz\n 97-923-163\n\n");
    printf("enter <1> to start task3, enter <0> to skip task3: ");
    scanf("%d", &answer);
    if (answer){task3();}

    printf("\nHello from main!\n");
    printf(" Exercise 1\n Roland Benz\n 97-923-163\n\n");
    printf("enter <1> to start task4, enter <0> to skip task4: ");
    scanf("%d", &answer);
    if (answer){task4();}

    printf("\nHello from main!\n");
    printf(" Exercise 1\n Roland Benz\n 97-923-163\n\n");
    printf("enter <1> to start task5, enter <0> to skip task5: ");
    scanf("%d", &answer);
    if (answer){task5();}

    printf("\nHello from main!\n");
    printf(" Exercise 1\n Roland Benz\n 97-923-163\n\n");
    printf("enter <1> to start task6, enter <0> to skip task6: ");
    scanf("%d", &answer);
    if (answer){task6();}

    printf("\nHello from main!\n");
    printf(" Exercise 1\n Roland Benz\n 97-923-163\n\n");
    printf("enter <1> to start task7a, enter <0> to skip task7a: ");
    scanf("%d", &answer);
    if (answer){task7a();}

    printf("\nHello from main!\n");
    printf(" Exercise 1\n Roland Benz\n 97-923-163\n\n");
    printf("enter <1> to start task7b, enter <0> to skip task7b: ");
    scanf("%d", &answer);
    if (answer){task7b(argc,argv);}

    printf("Good bye from main!\n");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    return 0;
}


//## Own integer array print function
void print_digit_array(int arr_digit[], int arr_digit_len){
    //include ctype.h for isdigit
    int i,arr_elem;
    printf("\n");
    for (i=0;i<arr_digit_len;++i){
        arr_elem=arr_digit[i];
        printf(" Info: array[%d]: %d\n", i,arr_elem);
    }
    printf("\n");
}

//## Own character Array print function
void print_char_array(const char* arr_char, int arr_char_len){
    //include ctype.h for isalpha
    int i;
    printf("\n");
    for (i=0;i<arr_char_len;++i){
        //Only print chars
        if (isalpha(arr_char[i])){
            printf(" Info: array[%d]: %c (ascii: %d)\n", i,arr_char[i], arr_char[i]);
        }
    }
    printf("\n");
}
