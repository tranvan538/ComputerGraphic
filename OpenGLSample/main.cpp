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

#define WIDTH         700
#define HEIGHT        400
#define SQUARE        25


void display();
void init();

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("LAB 1 - (Bai 11)");
    
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, WIDTH / 2, 0.0, HEIGHT / 2);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(4.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glColor3f(0.0f, 0.0f, 0.0f);
    
    GLint y = 0;
    GLint x = 0;
    
    glLineWidth(2.0);
    glBegin(GL_LINES);
    while (y < HEIGHT) {
        glVertex2i(x, y);
        glVertex2i(HEIGHT, y);
        y += SQUARE;
    }
    glEnd();
    
    x = 0;
    y = 0;
    glBegin(GL_QUADS);
    int z = 0;
    while (y < HEIGHT) {
        if (z % 2 == 0) {
            x = SQUARE / 3;
        } else {
            x = 2 * SQUARE / 3;
        }
        
        if (z % 4 == 3) {
            x = 0;
        }

        while (x < WIDTH) {
            glVertex2i(x, y);
            glVertex2i(x + SQUARE, y);
            glVertex2i(x + SQUARE, y + SQUARE);
            glVertex2i(x, y + SQUARE);
            x += 2 * SQUARE;
        }
        y += SQUARE;
        z++;
    }
    glEnd();
    glFlush();
}


