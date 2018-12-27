//Exercise 1
//Roland Benz
//97-923-163

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//## Task
/*Task 5. Given integers b and e, write a C program that uses the function int
power(int base, int exponent) to calculate b^e recursively. [4 points]
*/

//## Forward Declarations
int recursive_power_calc(int base, int exponent);

//## Main
int task5(void)
{
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Hello from task5: power function!\n");

    int out, base, exponent;
    //base=3;
    //exponent=4;

    //ask for user input
    printf(" Enter the base. Type for example <3>: \n");
    scanf("%d", &base);
    printf(" Enter the exponent. Type for example <4>: \n");
    scanf("%d", &exponent);
    printf("\n You typed: base: %d and exponent: %d\n\n", base, exponent);

    //call the power function
    out=recursive_power_calc(base,exponent);
    printf("\n output: base %d to the power of exponent %d equals: %d\n"  ,base, exponent,out);
    printf(" result of math::pow(base, exponent): %f\n", pow(base,exponent));
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    return 0;
}

//## Algo
int recursive_power_calc(int base, int exponent){
/*calculates the power recurively:
 * base^expontent, pow(base,exponent)
 *
*/
    printf(" Info: Hi from recursive_power_calc()\n");
    if (exponent==1){
        return base;
    }else{
        return base*recursive_power_calc(base, exponent-1);
    }
}
