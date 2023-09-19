#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
#define pi 3.142857

void myInit(void)
{

    glClearColor(0.0, 0.0, 0.0, 1.0);

    glColor3f(0.0, 1.0, 0.0);

    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-780, 780, -420, 420);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    glColor3f(1, 1, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(300, 0, 0);
    glVertex3f(0, 300, 0);
    glEnd();
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(600, 600);
    glutInitWindowPosition(0, 0);

    glutCreateWindow("Triangle Drawing");
    myInit();

    glutDisplayFunc(display);
    glutMainLoop();
}
