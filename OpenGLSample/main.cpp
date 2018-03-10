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

#define PI               M_PI
#define WIDTH            900
#define HEIGHT           600
#define RADIUS           HEIGHT / 3

struct Point
{
    float x, y;
};

Point p[10];

void display();
void init();
void calVertex();
Point lineIntersection(Point p1, Point p2, Point p3, Point p4);

int main(int argc, char** argv) {
    calVertex();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("National Flag");
    
    glutDisplayFunc(display);
    init();
    glutMainLoop();

    return 0;
}


void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPolygonMode(GL_FRONT_AND_BACK, GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex2i(p[0].x, p[0].y);
        glVertex2i(p[1].x, p[1].y);
        glVertex2i(p[2].x, p[2].y);
        glVertex2i(p[3].x, p[3].y);
        glVertex2i(p[4].x, p[4].y);
        glVertex2i(p[5].x, p[5].y);
        glVertex2i(p[6].x, p[6].y);
        glVertex2i(p[7].x, p[7].y);
        glVertex2i(p[8].x, p[8].y);
        glVertex2i(p[9].x, p[9].y);
    glEnd();
    glFlush();
}

void calVertex() {
    float centerX, centerY;
    float alpha;
    float inc;
    
    centerX = WIDTH / 2.0;
    centerY = HEIGHT / 2.0;
    
    alpha = PI / 2.0;
    inc = 2.0 * PI / 5.0;

    p[0].x = centerX;
    p[0].y = centerY + RADIUS;
    
    alpha -= inc;
    p[2].x = centerX + RADIUS * cos(alpha);
    p[2].y = centerY + RADIUS * sin(alpha);
    
    alpha -= inc;
    p[4].x = centerX + RADIUS * cos(alpha);
    p[4].y = centerY + RADIUS * sin(alpha);
    
    alpha -= inc;
    p[6].x = centerX + RADIUS * cos(alpha);
    p[6].y = centerY + RADIUS * sin(alpha);
    
    alpha -= inc;
    p[8].x = centerX + RADIUS * cos(alpha);
    p[8].y = centerY + RADIUS * sin(alpha);
    
    p[1] = lineIntersection(p[0], p[4], p[2], p[8]);
    
    p[3] = lineIntersection(p[0], p[4], p[2], p[6]);
    
    p[5] = lineIntersection(p[8], p[4], p[2], p[6]);
    
    p[7] = lineIntersection(p[8], p[4], p[0], p[6]);
    
    p[9] = lineIntersection(p[8], p[2], p[0], p[6]);
}

Point lineIntersection(Point p1, Point p2, Point p3, Point p4) {
    Point t;
    
    float A1, B1, A2, B2;
    
    A1 = (p2.y - p1.y)/(p2.x - p1.x);
    B1 = p1.y - A1 * p1.x;
    A2 = (p4.y - p3.y)/(p4.x - p3.x);
    B2 = p3.y - A2*p3.x;
    t.x = (B2 - B1)/(A1 - A2);
    t.y = A1*t.x + B1;
    
    return t;
}


