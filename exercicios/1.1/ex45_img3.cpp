#include <GLUT/glut.h>

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glLineWidth(3.0f);

    glBegin(GL_LINES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(-0.65f, -0.55f);
        glColor3f(1.0f, 0.33f, 0.0f);
        glVertex2f(-0.20f, -0.10f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(1.0f, 0.33f, 0.0f);
        glVertex2f(-0.20f, -0.10f);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f( 0.00f,  0.70f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f( 0.00f,  0.70f);
        glColor3f(0.0f, 0.73f, 0.27f);
        glVertex2f( 0.20f, -0.10f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.73f, 0.27f);
        glVertex2f( 0.20f, -0.10f);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f( 0.65f, -0.55f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f( 0.65f, -0.55f);
        glColor3f(0.40f, 0.0f, 0.80f);
        glVertex2f( 0.00f, -0.30f);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.40f, 0.0f, 0.80f);
        glVertex2f( 0.00f, -0.30f);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(-0.65f, -0.55f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 520);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Exercicio 3 - Triangulo");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}