#include <GLUT/glut.h>

#define MAX_PONTOS 1000

void init(void);
void display(void);
void mouse(int button, int state, int x, int y);

float pontosX[MAX_PONTOS];
float pontosY[MAX_PONTOS];
int totalPontos = 0;

void init(void)
{
 
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1, 1, -1, 1, -1, 1);
  glPointSize(50);
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(0.0, 0.0, 0.0);

  glBegin(GL_POINTS);
    for (int i = 0; i < totalPontos; i++)
    {
      glVertex2f(pontosX[i], pontosY[i]);
    }
  glEnd();

  glFlush();
}

void mouse(int button, int state, int x, int y)
{
  int yInvertido = 500 - y;

  float xConvertido = (x / 500.0) * 2.0 - 1.0;
  float yConvertido = (yInvertido / 500.0) * 2.0 - 1.0;

  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
  {
    if (totalPontos < MAX_PONTOS)
    {
      pontosX[totalPontos] = xConvertido;
      pontosY[totalPontos] = yConvertido;
      totalPontos++;
    }
  }
  else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
  {
    totalPontos = 0;
  }

  display();
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(200, 200);
  glutCreateWindow("Mouse pontos");

  init();

  glutDisplayFunc(display);
  glutMouseFunc(mouse);

  glutMainLoop();

  return 0;
}