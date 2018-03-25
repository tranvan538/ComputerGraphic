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

#include "Canvas.h"

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

void polyspiral(int n, float angle, float length, float inc) {
    float len = length;
    
    for (int i = 1; i <= n; i += 2)
    {
        for (int j = 0; j < 12; j++)
        {
            canvas.setColor(0.0, 0.0, 0.0);
            canvas.turn((1 - i) * angle);
            
            canvas.forward(len, 1);
            canvas.turn(i * angle);
            
            canvas.forward(len, 1);
            canvas.turn(180);
            canvas.turn(-i * angle);
            
            canvas.forward(len, 1);
            canvas.turn(i * angle);
            
            canvas.forward(len, 1);
            canvas.setColor(1.0, 0.0, 0.0);
            canvas.turn(180);
            canvas.forward(len, 0);
            canvas.turn(180);
            canvas.turn((1 - i) * angle);
            canvas.forward(len, 0);
            canvas.turn(180);
            canvas.turn((i - 1) * angle);
        }
        
        canvas.turn(angle);
        canvas.forward(len, 0);
        canvas.turn(angle);
        canvas.forward(len, 0);
    }
}

void display()
{
    canvas.clearScreen();
    canvas.setWindow(-12, 12, -12, 12);
    canvas.moveTo(0.0,0.0);
    canvas.setCD(0.0);
    canvas.setViewport(0, 600, 0, 600);
    polyspiral(5, 30, 3, 3);
}
