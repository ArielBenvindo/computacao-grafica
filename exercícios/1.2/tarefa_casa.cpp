// tarefa1_casa.cpp
#include <GLUT/glut.h>

bool darkBackground = false;

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
}

void drawHouse() {

    glColor3f(0.35f, 0.2f, 0.8f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.4f, -0.5f);
        glVertex2f( 0.4f, -0.5f);
        glVertex2f( 0.4f,  0.1f);
        glVertex2f(-0.4f,  0.1f);
    glEnd();


    glColor3f(0.9f, 0.2f, 0.1f);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f,  0.1f);
        glVertex2f( 0.5f,  0.1f);
        glVertex2f( 0.0f,  0.6f);
    glEnd();


    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.10f, -0.5f);
        glVertex2f( 0.03f, -0.5f);
        glVertex2f( 0.03f, -0.15f);
        glVertex2f(-0.10f, -0.15f);
    glEnd();

    glColor3f(0.8f, 0.85f, 1.0f);
    glBegin(GL_POLYGON);
        glVertex2f( 0.15f, -0.25f);
        glVertex2f( 0.38f, -0.25f);
        glVertex2f( 0.38f, -0.05f);
        glVertex2f( 0.15f, -0.05f);
    glEnd();

    glColor3f(0.3f, 0.1f, 0.7f);
    glLineWidth(2.0f);

    glBegin(GL_LINES);
        glVertex2f(0.265f, -0.25f);
        glVertex2f(0.265f, -0.05f);
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(0.15f, -0.15f);
        glVertex2f(0.38f, -0.15f);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawHouse();
    glFlush();
}

void keyboard(unsigned char key, int x, int y) {
    if (key == ' ') {
        
        darkBackground = true;
        glClearColor(0.0, 0.0, 0.0, 1.0);
    } else {
        
        if (darkBackground) {
            darkBackground = false;
            glClearColor(1.0, 1.0, 1.0, 1.0);
        }
    }
    display();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 600);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("Primeiro Programa");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}