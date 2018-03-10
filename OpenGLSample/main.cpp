#ifdef WIN32
#include <windows.h>
#endif

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <string.h>
#include <cstdlib>

void display();
void init();

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 400);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("LAB 1 - (Bai 1)");
    
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}

GLfloat v0[2] = {1,1};
GLfloat v1[2] = {2,3};
GLfloat v2[2] = {4,1};
GLfloat v3[2] = {6,2};
GLfloat v4[2] = {9,3};
GLfloat v5[2] = {7,5};

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 9.0, 0.0, 6.0);
}

void drawGrid() {
    glColor3f(0.6f, 0.6f, 0.6f);
    glLineWidth(1.0);
    glBegin(GL_LINES);
    for (int i = 0; i < 9; i++) {
        glVertex2i(i, 0);
        glVertex2i(i, 6);
    }
    for (int i = 0; i < 6; i++) {
        glVertex2i(0, i);
        glVertex2i(9, i);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawGrid();
    glLineWidth(4.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2fv(v5);
        glVertex2fv(v1);
        glVertex2fv(v0);
        glVertex2fv(v2);
        glVertex2fv(v3);
        glVertex2fv(v4);
    glEnd();
    glFlush();
}


