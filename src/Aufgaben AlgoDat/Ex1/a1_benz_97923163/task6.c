//Exercise 1
//Roland Benz
//97-923-163

#include <stdio.h>
#include<stdlib.h>

//###Task
/*Given two integers a and b, write a C program that uses the function
int gcd(int a, int b) to calculate the greatest common divisor (GCD) of a and
b, recursively. For example, gcd(5,7) should return 1, gcd(8,12) should return
4, and gcd(203,203) should return 203.
Hint: The gcd can be implemented using Euclid’s algorithm, which works
as follows:
 If the two numbers are identical, gcd(a,a) = a
 If one number is larger, subtract the smaller number from the larger num-
ber, and then compute the GCD of the difference and the smaller number.
For instance, to determine gcd(12,8), compute 12−8 = 4 and then solve gcd(4,8).
Since 8 is larger than 4, this can be solved by computing gcd(4,4), which is 4.
[10 points]

*/

//##Forward Declarations
int greatest_common_divisor(int a, int b);


//##Main
int task6(void)
{
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Hello from task6: gcd function!\n");

    int out, number1, number2;
    //number1=64;
    //number2=56;

    //ask for user input
    printf(" Enter the first number. Type for example <64>: \n");
    scanf("%d", &number1);
    printf(" Enter the second number. Type for example <56>: \n");
    scanf("%d", &number2);
    printf("\n You typed: %d and %d\n\n", number1, number2);

    out=greatest_common_divisor(number1,number2);
    printf("\n output: greatest common divisor of %d and %d equals %d\n" ,number1, number2 ,out);
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    return 0;
}

//##Algo
int greatest_common_divisor(int a, int b){
/*calculates the euclidian gcd
 *
*/
    printf("Info: Hi from greatest_common_divisor()\n") ;
    //base case
    //recursion
    if(a==b){
        return a;
    }else{
        //recursive call with arguments:
        //positive difference of a and b
        //the smaller of a and b
        if(a>b){
            return greatest_common_divisor(a-b,b);
        }else{
            return greatest_common_divisor(b-a,a);
        }
    }
}
