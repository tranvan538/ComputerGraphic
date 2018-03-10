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

#include "Canvas.h"

Canvas canvas(600, 300, "Using Canvas");

void display();

int main(int argc, char** argv) {
    canvas.setBackgroundColor(1.0, 1.0, 1.0);
    canvas.setColor(0.0, 0.0, 0.0);
    
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;
}

void display()
{
    canvas.clearScreen();
    //Draw a red triangle
    canvas.setViewport(0, 300, 0, 300);
    canvas.setWindow(0, 6, 0, 6);
    canvas.setLineWidth(3.0);
    canvas.setColor(1, 0, 0);
    canvas.moveTo(1, 1);
    canvas.lineTo(5, 1);
    canvas.lineTo(3, 5);
    canvas.lineTo(1, 1);

    //Draw a blue square
    canvas.setViewport(300, 600, 0,300);
    canvas.setWindow(10, 70, 10, 70);
    canvas.setLineWidth(6.0);
    canvas.setColor(0, 0, 1);
    canvas.moveTo(20, 20);
    canvas.lineTo(60, 20);
    canvas.lineTo(60, 60);
    canvas.lineTo(20, 60);
    canvas.lineTo(20, 20);
}
