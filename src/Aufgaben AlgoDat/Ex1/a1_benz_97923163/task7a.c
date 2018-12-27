//Exercise 1
//Roland Benz
//97-923-163

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//## Task
/* The Levy C curve in Figure 1 is a fractal whose initial pattern is a
straight line as illustrated in Fig. 1(a). In the first iteration, an isosceles triangle
with angles of 45o, 90o and 45o is built using this line as its hypotenuse. The
original line is then replaced by the other two sides of this triangle. In each
iteration, each straight line is replaced by the other two sides of a right-angled
isosceles triangle built on it. After n iterations the curve consists of 2^n line
segments, each of which is smaller than the original line by a factor of 2^(n/2) .
Drawing the Levy C curve can be done by drawing each segment separately.

Each segment is specified by an (r, φ) pair corresponding to the polar coordinates
of its ending point (x1 ) with respect to its starting one (x0 ), which coincides
with the ending point of its neighbouring segment on the left. For example, the
form of the curve after the second iteration, as shown
in Fig. 1(b), can be drawn following these steps:
 ”draw a segment of length sqrt(0.5) with angle -45, draw a
  segment of length sqrt(0.5) with angle 45”.
(a) Create the C function drawLevyCurve(int iter, double r, int phi),
which uses a recursive scheme to determine the polar coordinates to draw
Levy C curve after the i-th iteration. As input it receives the number of
remaining iterations (iter) and the polar coordinates (r, phi) of the ending
point of the segment to which they should be applied. [8 points]
Example: The invocation drawLevyCurve(1,1,0) describes the process
of applying one iteration (iter=1) on the horizontal (phi=0) 1cm long
(r=1cm) line in Fig. 1(a). Its output would be (0.707107,-45), (0.707107,45).
Accordingly, an invocation drawLevyCurve(2,1,0) should print the pairs
needed for the form of the curve presented in Fig. 1(c).
(b) Write a program in C that uses the function drawLevyCurve(int iter, double
r, int phi) to draw the curve using OpenGL. [8 points]
Note: A skeleton of the solution of Task 7(b) is provided.
*/


//## Forward Declarations
//int calculate_levy_curve(int iter, double r, int phi);
int calculate_levy_curve(int n, int iter,float x0, float y0, float x1, float y1);


//## Main
int task7a(void)
{
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Hello from task7a: calculate levy C!\n");

    /*
     * couldn't figure out a solution with
     * polar coordinates. Used a new interface
     * with cartesian coordinates
    */

    //calculate figure 1a
    printf("\n level 0: \n");
    calculate_levy_curve(0,0,-0.5,0.0,0.5,0.0);
    //calculate figure 1b
    printf("\n level 1: \n");
    calculate_levy_curve(1,0,-0.5,0.0,0.5,0.0);
    //calculate figure 1c
    printf("\n level 2: \n");
    calculate_levy_curve(2,0,-0.5,0.0,0.5,0.0);
    //calculate figure 1d
    printf("\n level 3: \n");
    calculate_levy_curve(3,0,-0.5,0.0,0.5,0.0);
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    return 0;
}

//## Algo
int calculate_levy_curve(int n, int iter,float x0, float y0, float x1, float y1){
/*This version calculates the line vertices
 * recursively
 * It uses carthesian coordinates
 * Half correct formulas for polar coordinats(not used)
 *      //calculate xm,ym
        //r=r/pow(2.0,(n-iter)/2.0);
        //phi=phi-PI/4.0;
        //float xm=x0+r*cos(phi);
        //float ym=y0+r*sin(phi);
*/

    //return vertices of lines of the last iteration level
    if (iter==n){
        printf(" output: maxlevel:%d, level:%d, point:(%.2f,%.2f), point:(%.2f,%.2f) \n",
               n,iter,x0,y0,x1,y1);

    //just calculation and recusion through the tree
    }else if (iter<n){

        //calculation of mid-point (vector algebra)
        float xm=x0+0.5*(x1-x0)+0.5*(y1-y0);
        float ym=y0+0.5*(y1-y0)-0.5*(x1-x0);

        //call for replacement line 1
        calculate_levy_curve(n,iter+1, x0,y0,xm,ym);

        //call for replacement line 2
        calculate_levy_curve(n,iter+1, xm,ym,x1,y1);
    }
    return 0;
}
