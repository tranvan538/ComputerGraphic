#ifdef WIN32
#include <windows.h>
#endif

#ifdef __APPLE__
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#endif

#include <string.h>
#include <cstdlib>
#include <math.h>

#include "Canvas.h"

#define PI               M_PI

Canvas canvas(600, 600, "Using Polyspirals");

void polyspiral(int n, float angle, float len0, float inc);
void display();

int main(int argc, char** argv) {
    canvas.setBackgroundColor(1.0, 1.0, 1.0);
    canvas.setColor(0.0, 0.0, 0.0);
    
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;
}

void polyspiral(int n, float angle, float length, float inc)
{
    float len = length;
    for (int i = 0; i < 12; i++) {
        canvas.forward(len, 1);
        canvas.forward(-len, 0);
        canvas.turn(angle);
    }
    canvas.forward(len, 1);

    for (int j = 5; j > 0; j--) {
        canvas.turn(angle);
        canvas.forward(len, 1);
        for (int i = 0; i < 12; i++) {
            canvas.turn(j * angle);
            canvas.forward(len, 1);
            
            canvas.turn((1 -j) * angle);
            canvas.forward(len, 1);
        }
    }
}
void display()
{
    canvas.clearScreen();
    
    canvas.setWindow(-10, 10, -10, 10);
    canvas.moveTo(0.0, 0.0);
    canvas.setCD(0.0);
    canvas.setViewport(0, 600, 0, 600);
    polyspiral(100, 30, 2, 30);
}
