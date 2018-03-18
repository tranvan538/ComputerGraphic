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
    for (int i = 0; i < n; i++) {
        canvas.forward(len, 1);
        canvas.turn(angle);
        len += inc;
    }
}
void display()
{
    canvas.clearScreen();
    
    canvas.setWindow(-10, 10, -10, 10);
    canvas.moveTo(0.0, 0.0);
    canvas.setCD(0.0);
    canvas.setViewport(0, 300, 300, 600);
    polyspiral(100, 60, 0.1, 0.07);
    
    canvas.setWindow(-10, 10, -10, 10);
    canvas.setViewport(300, 600, 300, 600);
    canvas.moveTo(0.0, 0.0);
    canvas.setCD(0.0);
    polyspiral(100, 89.5, 0.1, 0.11);
    
    canvas.setWindow(-10, 10, -10, 10);
    canvas.setViewport(0, 300, 0, 300);
    canvas.moveTo(0.0, 0.0);
    canvas.setCD(0.0);
    polyspiral(100, -144, 0.1, 0.16);
    
    canvas.setWindow(-10, 10, -10, 10);
    canvas.setViewport(300, 600, 0, 300);
    canvas.moveTo(0.0, 0.0);
    canvas.setCD(0.0);
    polyspiral(100, 170, 0.1, 0.16);
}
