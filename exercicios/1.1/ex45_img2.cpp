#include <GLUT/glut.h>

void init() {
    glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f);
    glLineWidth(8.0f);

    glBegin(GL_LINES);
        glVertex2f(0.0f,  1.0f);
        glVertex2f(0.0f, -1.0f);
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(-1.0f, 0.0f);
        glVertex2f( 1.0f, 0.0f);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.45f,  0.60f);
        glVertex2f( 0.45f,  0.60f);
        glVertex2f( 0.45f, -0.60f);
        glVertex2f(-0.45f, -0.60f);
    glEnd();

    float g = 0.03f;
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-g,  g);
        glVertex2f( g,  g);
        glVertex2f( g, -g);
        glVertex2f(-g, -g);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 520);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Exercicio 2 - Grade");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}