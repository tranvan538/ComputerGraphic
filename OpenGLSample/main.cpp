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

Canvas canvas(640, 640, "Draw Figure");

void drawFigure();
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

    canvas.setViewport(320, 640, 320, 640);
    canvas.setWindow(0, 2, 0, 2);
    drawFigure();

    canvas.setViewport(0, 320, 320, 640);
    canvas.setWindow(2, 0, 0, 2);
    drawFigure();

    canvas.setViewport(0, 320, 0, 320);
    canvas.setWindow(2, 0, 2, 0);
    drawFigure();

    canvas.setViewport(320, 640, 0, 320);
    canvas.setWindow(0, 2, 2, 0);
    drawFigure();
    
    canvas.setViewport(320, 480, 320, 480);
    canvas.setWindow(0, 2, 0, 2);
    drawFigure();
    
    canvas.setViewport(320, 480, 160, 320);
    canvas.setWindow(0, 2, 2, 0);
    drawFigure();

    canvas.setViewport(160, 320, 320, 480);
    canvas.setWindow(2, 0, 0, 2);
    drawFigure();
    
    canvas.setViewport(160, 320, 160, 320);
    canvas.setWindow(2, 0, 2, 0);
    drawFigure();
}

void drawFigure()
{
    canvas.setLineWidth(12);
    canvas.moveTo(0, 2);
    canvas.lineTo(1, 2);
    canvas.lineTo(1, 1);
    canvas.lineTo(2, 1);
    canvas.lineTo(2, 0);
}
