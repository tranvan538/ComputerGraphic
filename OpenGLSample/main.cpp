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
#include <math.h>

#define PI                3.1415926
#define WIDTH             600
#define HEIGHT            600
#define OUTTER_RADIUS     200
#define INNER_RADIUS      30

float fX[7], fY[7];

struct Point {
    float x,y;
};

void display();
void init();
void calVertex();

int main(int argc, char** argv) {
    calVertex();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Mercedes‐Benz Logo");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(4.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2i(fX[0], fY[0]);
        glVertex2i(fX[1], fY[1]);
        glVertex2i(fX[2], fY[2]);
        glVertex2i(fX[3], fY[3]);
        glVertex2i(fX[4], fY[4]);
        glVertex2i(fX[5], fY[5]);
        glVertex2i(fX[6], fY[6]);
        glVertex2i(fX[1], fY[1]);
    glEnd();
    glFlush();
}

void calVertex() {
    float radius;
    float alpha;
    float inc;
    
    float centerX = WIDTH / 2.0;
    float centerY = HEIGHT / 2.0;
    
    fX[0] = centerX;
    fY[0] = centerY;
    
    radius = OUTTER_RADIUS;
    alpha = PI / 2.0;
    inc   = 2.0 * PI / 3.0;
    
    fX[1] = centerX;
    fY[1] = centerY + radius;
    
    alpha += inc;
    fX[5] = centerX + radius*cos(alpha);
    fY[5] = centerY + radius*sin(alpha);
    
    alpha += inc;
    fX[3] = centerX + radius*cos(alpha);
    fY[3] = centerY + radius*sin(alpha);
    
    radius = INNER_RADIUS;
    alpha = PI / 2.0 - PI / 3.0;
    fX[2] = centerX + radius*cos(alpha);
    fY[2] = centerY + radius*sin(alpha);

    alpha += inc;
    fX[6] = centerX + radius*cos(alpha);
    fY[6] = centerY + radius*sin(alpha);

    alpha += inc;
    fX[4] = centerX + radius*cos(alpha);
    fY[4] = centerY + radius*sin(alpha);
    

}
