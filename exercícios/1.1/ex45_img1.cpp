
#include <GLUT/glut.h>

void init() {
    glClearColor(0.0, 0.9, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
}

void drawDiamond(float cx, float cy, float size, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
        glVertex2f(cx,        cy + size);
        glVertex2f(cx + size, cy);
        glVertex2f(cx,        cy - size);
        glVertex2f(cx - size, cy);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    float s = 0.22f;

    drawDiamond(-0.05f,  0.30f, s, 0.3f, 0.0f, 0.8f);

    drawDiamond(-0.28f,  0.05f, s, 1.0f, 1.0f, 0.0f);

    drawDiamond( 0.20f,  0.05f, s, 0.9f, 0.0f, 0.0f);

    drawDiamond(-0.05f, -0.22f, s, 0.0f, 0.0f, 0.0f);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Exercicio 1 - Losangos");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}