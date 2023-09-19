#include <GL/glut.h>

/* Handler for window-repaint event. Call back when the window first appears and
   whenever the window needs to be re-painted. */
void display()
{
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   glClear(GL_COLOR_BUFFER_BIT);

   glBegin(GL_QUADS);
   glColor3f(1.0f, 0.0f, 0.0f);
   glVertex2f(-0.5f, -0.5f);
   glVertex2f(0.5f, -0.5f);
   glVertex2f(0.5f, 0.5f);
   glVertex2f(-0.5f, 0.5f);
   glEnd();

   glFlush();
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char **argv)
{
   glutInit(&argc, argv);
   glutCreateWindow("OpenGL Setup Test");
   glutInitWindowSize(800, 800);
   glutInitWindowPosition(50, 50);
   glutDisplayFunc(display);
   glutMainLoop();
   return 0;
}