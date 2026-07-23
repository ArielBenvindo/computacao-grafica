// tarefa2_pontos.cpp
#include <GLUT/glut.h>
#include <vector>

struct Point { float x, y; };
std::vector<Point> points;

int winW = 600, winH = 600;

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, winW, winH, 0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0f, 0.0f, 0.0f);
    float size = 25.0f; 

    for (const auto& p : points) {
        glBegin(GL_POLYGON);
            glVertex2f(p.x - size, p.y - size);
            glVertex2f(p.x + size, p.y - size);
            glVertex2f(p.x + size, p.y + size);
            glVertex2f(p.x - size, p.y + size);
        glEnd();
    }

    glFlush();
}

void mouse(int button, int action, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && action == GLUT_DOWN) {
        points.push_back({(float)x, (float)y});
        display();
    }
    if (button == GLUT_RIGHT_BUTTON && action == GLUT_DOWN) {
        points.clear();
        display();
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(winW, winH);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("Mouse pontos");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}