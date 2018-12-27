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

static float x, y;
int iteration;

void TurnAndForward(double r, int phi) {
    glVertex2f(x, y);
    glVertex2f(x + r * cos(phi / 180.0f * M_PI),
               y + r * sin(phi / 180.0f * M_PI));
    x = x + r * cos(phi / 180.0f * M_PI);
    y = y + r * sin(phi / 180.0f * M_PI);
}

void drawLevyCurve(int iter, double r, int phi) {
    if (iter==0) {
        TurnAndForward(r, phi);
    } else {
        drawLevyCurve(iter-1, r * sqrt(0.5), phi-45);
        drawLevyCurve(iter-1, r * sqrt(0.5), phi+45);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT); //clear all pixels
    glColor3f(1.0,1.0,1.0); // use white color to draw the lines
    glBegin(GL_LINES);

    x=-0.5; y=0.0;
    drawLevyCurve(iteration, 1.0, 0);
    
    glEnd();
    glFlush();
}

void main(int argc, char *argv[])
{
    printf("Type iteration: ");
    scanf("%d", &iteration);
    glutInit(&argc, argv);
    glutCreateWindow("Levy C");
    glutDisplayFunc(display);
    glutMainLoop();
}

// Linux: gcc task7b.c -lglut -lGL -lGLU -lm -o task7b; ./task7b
// MacOS: gcc -Wno-deprecated task7b.c -o task7b -framework OpenGL -framework GLUT; ./task7b
// Windows: gcc task7b.c -o  task7b -lfreeglut -lopengl32; task7b
