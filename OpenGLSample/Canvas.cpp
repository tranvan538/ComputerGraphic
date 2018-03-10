#include "Canvas.h"

Canvas::Canvas(int width, int height, char* windowTitle)
{
    char *argv[1];
    char dummyString[8];
    argv[0] = dummyString;
    int argc = 1;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(20, 20);
    glutCreateWindow(windowTitle);
    setWindow(0, (float)width, 0, (float)height);
    setViewport(0, width, 0, height);
    CP.set(0.0f, 0.0f);
};

void Canvas::setWindow(float l, float r, float b, float t)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D((GLdouble) l, (GLdouble)r, (GLdouble)b, (GLdouble)t);
    window.set(l, r, b, t);
}

void Canvas::setViewport(int l, int r, int b, int t)
{
    glViewport(l, b, r - l, t - b);
}

IntRect Canvas::getViewport()
{
    return viewport;
}

RealRect Canvas::getWindow()
{
    return window;
}

float Canvas::getWindowAspectRatio()
{
    return window.getWidth() / window.getHeight();
}

void Canvas::clearScreen()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void Canvas::setBackgroundColor(float r, float g, float b)
{
    glClearColor(r, g, b, 0.0);
}

void Canvas::setColor(float r, float g, float b)
{
    glColor3f(r, g, b);
}

void Canvas::moveTo(float x, float y)
{
    CP.set(x, y);
}

void Canvas::moveTo(Point2 p)
{
    CP.set(p.getX(), p.getY());
}

void Canvas::lineTo(float x, float y)
{
    glBegin(GL_LINES);
    glVertex2f((GLfloat)CP.getX(), (GLfloat)CP.getY());
    glVertex2f(x, y);
    glEnd();
    CP.set(x, y);
    glFlush();
}

void Canvas::lineTo(Point2 p)
{
    glBegin(GL_LINES);
    glVertex2f((GLfloat)CP.getX(), (GLfloat)CP.getY());
    glVertex2f((GLfloat)p.getX(), (GLfloat)p.getY());
    glEnd();
    CP.set(p.getX(), p.getY());
    glFlush();
}

void Canvas::setLineWidth(float width)
{
    glLineWidth((GLfloat)width);
}

void Canvas::forward(float dist, int isVisible)
{
    const float RadPerDeg = 0.017453393;
    float x = CP.getX() + dist * cos(RadPerDeg * CD);
    float y = CP.getY() + dist * sin(RadPerDeg * CD);
    
    if (isVisible)
    {
        lineTo(x, y);
    } else {
        moveTo(x, y);
    }
}

void Canvas::moveRel(float dx, float dy)
{
    CP.set(CP.getX() + dx, CP.getY() + dy);
}

void Canvas::lineRel(float dx, float dy)
{
    float x = CP.getX() + dx;
    float y = CP.getY() + dy;
    lineTo(x, y);
    CP.set(x, y);
}
