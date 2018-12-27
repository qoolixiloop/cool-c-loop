//Exercise 1
//Roland Benz
//97-923-163

#include <math.h>
#include <stdio.h>
#include <GL/glut.h>

#ifdef __MINGW32__
#include <windows.h>
#endif
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

//## Forward declarations
#define PI 3.14159265
void draw_levy_curve(int n, int iter, float x0, float y0, float x1, float y1);
void draw_levy_curve_2(int n, int iter,float x0, float y0, float x1, float y1);
void display();
int level;


//## Main
void task7b(int argc, char** argv){

/*
 * couldn't figure out a solution with
 * polar coordinates. Used a new interface
 * with cartesian coordinates
*/

    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Hello from task7b: draw levy C with openGL!\n");

    //user input
    printf(" Enter Levy C level. Type for example: <15>: \n");
    scanf("%d",&level);
    printf("\n You typed: %d\n", level);

    //draw lines
    glutInit(&argc, argv); // Declare initial window
    glutInitWindowSize(800, 600);   // Set the window's initial width & height - non-square
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Levy C"); // Open window with the title "Tree".
    glutDisplayFunc(display); // use the function "display" to determine what
                              // will be shown in the window you created
    glutMainLoop(); // Enter main loop and process events.

    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

//## GCC compiler
// Linux: gcc task7b.c -lglut -lGL -lGLU -lm -o task7b; ./task7b
// MacOS: gcc -Wno-deprecated task7b.c -o task7b -framework OpenGL -framework GLUT; ./task7b
// Windows: gcc task7b.c -o  task7b -lfreeglut -lopengl32; task7b


//## GL: Handler or call back function for window-repaint event.
void display() {
    glClear(GL_COLOR_BUFFER_BIT); //clear all pixels
    glColor3f(1.0,1.0,1.0); // use white color to draw the lines
    glBegin(GL_LINES);

    //calculation of vertices
    //(draws just last genertion of children, no ancestors)
    //int level=15;
    int start_level=0;
    draw_levy_curve(level,start_level,-0.4,0.2,0.4,0.2);

    //used for debugging
    //(draws ancesters as well)
    //level=15;
    //start_level=15;
    //draw_levy_curve_2(level,start_level,-0.4,0.2,0.4,0.2);

    glEnd();
    glFlush();
}

//## Algos
void draw_levy_curve(int n, int iter,float x0, float y0, float x1, float y1){
/*This version just draws the lines
 * the deepest iteration level
 * It uses carthesian coordinates
*/
    //just draw lines of the last generation of lines (not its ancestors)
    if (iter==n){
        //draw line
        glVertex2f(x0,y0);
        glVertex2f(x1,y1);
    }

    //just calculation and recusion through the tree
    if (iter<n){
        //calculate mid-point (vector algebra)
        float xm=x0+0.5*(x1-x0)+0.5*(y1-y0);
        float ym=y0+0.5*(y1-y0)-0.5*(x1-x0);

        //call for replacement line 1
        draw_levy_curve(n,iter+1, x0,y0,xm,ym);

        //call for replacement line 2
        draw_levy_curve(n,iter+1, xm,ym,x1,y1);
    }
}

void draw_levy_curve_2(int n, int iter,float x0, float y0, float x1, float y1){
/*This version draws the lines
 * of each iteration or recursion
 * levels and not just
 * the deepest level (or leaves of
 * the tree). Used for debugging.
 * It uses carthesian coordinates
*/

    //first draw the one big line, and call recursion
    if (iter==n){
        //drawing
        glVertex2f(x0, y0);
        glVertex2f(x1, y1);
        //call children
        draw_levy_curve_2(n,iter-1, x0,y0,x1,y1);
    //then draw its children and grandgrand....children by recursion
    }else if (iter>0){

        //calculate mid-point (vector algebra)
        float xm=x0+0.5*(x1-x0)+0.5*(y1-y0);
        float ym=y0+0.5*(y1-y0)-0.5*(x1-x0);

        //draw line 1
        glVertex2f(x0,y0);
        glVertex2f(xm,ym);
        //call children
        draw_levy_curve_2(n,iter-1, x0,y0,xm,ym);

        //draw line 2
        glVertex2f(xm,ym);
        glVertex2f(x1,y1);
        //call children
        draw_levy_curve_2(n,iter-1, xm,ym,x1,y1);
    }
}
