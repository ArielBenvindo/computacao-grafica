#include <GLUT/glut.h>

void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);

int fundoEscuro = 0;

void init(void)
{
 
  glClearColor(1.0, 1.0, 1.0, 1.0);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1, 1, -1, 1, -1, 1);
}

void display()
{

  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_TRIANGLES);
    glColor3f(0.8, 0.1, 0.1);
    glVertex3f(-0.32, 0.1, 0);
    glVertex3f(0.32, 0.1, 0);
    glVertex3f(0.0, 0.45, 0);
  glEnd();

  glBegin(GL_POLYGON);
    glColor3f(0.5, 0.0, 0.8);
    glVertex3f(-0.32, -0.35, 0);
    glVertex3f(0.32, -0.35, 0);
    glVertex3f(0.32, 0.1, 0);
    glVertex3f(-0.32, 0.1, 0);
  glEnd();

  glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-0.08, -0.35, 0);
    glVertex3f(0.02, -0.35, 0);
    glVertex3f(0.02, 0.0, 0);
    glVertex3f(-0.08, 0.0, 0);
  glEnd();

  glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.12, -0.2, 0);
    glVertex3f(0.26, -0.2, 0);
    glVertex3f(0.26, -0.06, 0);
    glVertex3f(0.12, -0.06, 0);
  glEnd();

  glBegin(GL_POLYGON);
    glColor3f(0.5, 0.0, 0.8);
    glVertex3f(0.185, -0.2, 0);
    glVertex3f(0.195, -0.2, 0);
    glVertex3f(0.195, -0.06, 0);
    glVertex3f(0.185, -0.06, 0);
  glEnd();

  glBegin(GL_POLYGON);
    glColor3f(0.5, 0.0, 0.8);
    glVertex3f(0.12, -0.135, 0);
    glVertex3f(0.26, -0.135, 0);
    glVertex3f(0.26, -0.125, 0);
    glVertex3f(0.12, -0.125, 0);
  glEnd();

  glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
  if (key == ' ')
  {
    fundoEscuro = 1;
    glClearColor(0.0, 0.0, 0.0, 1.0);
  }
  else
  {
    if (fundoEscuro == 1)
    {
      fundoEscuro = 0;
      glClearColor(1.0, 1.0, 1.0, 1.0);
    }
  }

  display();
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(800, 800);
  glutInitWindowPosition(200, 200);
  glutCreateWindow("Casa com teclado");

  init();

  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);

  glutMainLoop();

  return 0;
}