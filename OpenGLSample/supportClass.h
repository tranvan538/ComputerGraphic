#if !defined (_SUPPORT_CLASS)
#define _SUPPORT_CLASS

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

#include <math.h>

class Point2
{
public:
    Point2() { x = y = 0.0f; }
    Point2(float xx, float yy) { x = xx; y = yy;}
    void set(float xx, float yy) { x = xx; y = yy;}
    float getX() { return x; }
    float getY() { return y; }
    void draw() {
        glBegin(GL_POINTS);
        glVertex2f((GLfloat)x, (GLfloat)y);
        glEnd();
    }
private:
    float x,y;
};

class IntRect
{
public:
    IntRect() { l = 0; r = 100; b = 0; t = 100;}
    IntRect(int left, int right, int bottom, int top) { l = left; r = right; b = bottom; t = top;}
    void set(int left, int right, int bottom, int top) { l = left; r = right; b = bottom; t = top;}
    void draw() { glRecti(l, b, r, t); glFlush();}
    int getWith() { return (r-l); }
    int getHeight() { return (t-b); }
private:
    int l, r, b, t;
};

class RealRect
{
public:
    RealRect() { l = 0; r = 100; b = 0; t = 100; }
    RealRect(float left, float right, float bottom, float top) { l = left; r = right; b = bottom; t = top; }
    void set(float left, float right, float bottom, float top) { l = left; r = right; b = bottom; t = top; }
    float getWidth() { return (r-l); }
    float getHeight() { return (t-b); }
    void draw() { glRectf(l, b, r, t); glFlush(); }
private:
    float l, r, b, t;
};

#endif
