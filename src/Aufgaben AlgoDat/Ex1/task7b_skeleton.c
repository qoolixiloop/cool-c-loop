#include <math.h>
#include <stdio.h>


#ifdef __MINGW32__
#include <windows.h>
#endif
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void display() {
    glClear(GL_COLOR_BUFFER_BIT); //clear all pixels
    glColor3f(1.0,1.0,1.0); // use white color to draw the lines
    glBegin(GL_LINES);
    
    // The function you created in task7a should be properly called here.
    
    glEnd();
    glFlush();
}

void main()
{
    glutInit(&argc, argv); // Declare initial window
    glutCreateWindow("Levy C"); // Open window with the title "Tree".
    glutDisplayFunc(display); /* use the function "display" to determine what
                                 will be shown in the window you created */
    glutMainLoop(); // Enter main loop and process events.
}

// Linux: gcc task7b.c -lglut -lGL -lGLU -lm -o task7b; ./task7b
// MacOS: gcc -Wno-deprecated task7b.c -o task7b -framework OpenGL -framework GLUT; ./task7b
// Windows: gcc task7b.c -o  task7b -lfreeglut -lopengl32; task7b
