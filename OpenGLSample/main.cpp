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
#define WIDTH            800
#define HEIGHT           800
#define INNER_RADIUS     100
#define OUTTER_RADIUS    200

struct Point
{
    float x, y;
};

Point p[15];

void display();
void init();
void calVertex();

int main(int argc, char** argv) {
    calVertex();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Backhoa logo");
    
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
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(2.0);
    glBegin(GL_QUAD_STRIP);
        glVertex2i(p[1].x, p[1].y);
        glVertex2i(p[7].x, p[7].y);
        glVertex2i(p[0].x, p[0].y);
        glVertex2i(p[6].x, p[6].y);
        glVertex2i(p[5].x, p[5].y);
        glVertex2i(p[14].x, p[14].y);
    glEnd();
    glBegin(GL_QUAD_STRIP);
        glVertex2i(p[1].x, p[1].y);
        glVertex2i(p[8].x, p[8].y);
        glVertex2i(p[2].x, p[2].y);
        glVertex2i(p[9].x, p[9].y);
        glVertex2i(p[3].x, p[3].y);
        glVertex2i(p[10].x, p[10].y);
    glEnd();
    glBegin(GL_QUAD_STRIP);
        glVertex2i(p[3].x, p[3].y);
        glVertex2i(p[11].x, p[11].y);
        glVertex2i(p[4].x, p[4].y);
        glVertex2i(p[12].x, p[12].y);
        glVertex2i(p[5].x, p[5].y);
        glVertex2i(p[13].x, p[13].y);
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
    inc = 2.0 * PI / 6.0;

    p[0].x = centerX;
    p[0].y = centerY + INNER_RADIUS;
    
    alpha -= inc;
    p[1].x = centerX + INNER_RADIUS * cos(alpha);
    p[1].y = centerY + INNER_RADIUS * sin(alpha);
    
    alpha -= inc;
    p[2].x = centerX + INNER_RADIUS * cos(alpha);
    p[2].y = centerY + INNER_RADIUS * sin(alpha);
    
    alpha -= inc;
    p[3].x = centerX + INNER_RADIUS * cos(alpha);
    p[3].y = centerY + INNER_RADIUS * sin(alpha);
    
    alpha -= inc;
    p[4].x = centerX + INNER_RADIUS * cos(alpha);
    p[4].y = centerY + INNER_RADIUS * sin(alpha);
    
    alpha -= inc;
    p[5].x = centerX + INNER_RADIUS * cos(alpha);
    p[5].y = centerY + INNER_RADIUS * sin(alpha);
    
    alpha = PI / 2.0;
    inc = 2.0 * PI / 3.0;
    p[6].x = centerX;
    p[6].y = centerY + OUTTER_RADIUS;
    
    alpha -= inc;
    p[9].x = centerX + OUTTER_RADIUS * cos(alpha);
    p[9].y = centerY + OUTTER_RADIUS * sin(alpha);
    
    alpha -= inc;
    p[12].x = centerX + OUTTER_RADIUS * cos(alpha);
    p[12].y = centerY + OUTTER_RADIUS * sin(alpha);
    
    p[7].x = p[1].x + p[6].x - p[0].x;
    p[7].y = p[1].y + p[6].y - p[0].y;
    
    p[14].x = p[5].x + p[6].x - p[0].x;
    p[14].y = p[5].y + p[6].y - p[0].y;
    
    p[13].x = p[5].x + p[12].x - p[4].x;
    p[13].y = p[5].y + p[12].y - p[4].y;
    
    p[11].x = p[3].x + p[12].x - p[4].x;
    p[11].y = p[3].y + p[12].y - p[4].y;
    
    p[8].x = p[1].x + p[9].x - p[2].x;
    p[8].y = p[1].y + p[9].y - p[2].y;
    
    p[10].x = p[3].x + p[9].x - p[2].x;
    p[10].y = p[3].y + p[9].y - p[2].y;
}

