#include <GL/glut.h>
#include <iostream>
#include <cmath>
using namespace std;
void setpoint(int x0, int y0, int x, int y)
{
    // glColor3f(1.0f, 1.0f, 0.0); To change color
    glVertex2f((x0 + x), (y0 + y));
    glVertex2f((x0 + y), (y0 + x));
    glVertex2f((x0 + y), (y0 - x));
    glVertex2f((x0 + x), (y0 - y));
    glVertex2f((x0 - x), (y0 - y));
    glVertex2f((x0 - y), (y0 - x));
    glVertex2f((x0 - y), (y0 + x));
    glVertex2f((x0 - x), (y0 + y));
}
void midpointcircle(int x0, int y0, int r)
{
    int x = 0;
    int y = r;
    int d = 1 - r;
    glBegin(GL_POLYGON);
    while (x < y)
    {
        setpoint(x0, y0, x, y);
        if (d < 0)
        {
            d += 2 * x + 3;
        }
        else
        {
            d += 2 * (x - y) + 5;
            y--;
        }
        x++;
    }
    glEnd();
    glFlush();
}
void ChangeSize(GLsizei w, GLsizei h)
{
    if (h == 0)
        h = 1;
    glViewport(0, 0, w, h);
    glLoadIdentity();
    if (w <= h)
        glOrtho(0.0f, 250.0f, 0.0f, 250.0f * h / w, 1.0, -1.0);
    else
        glOrtho(0.0f, 250.0f * w / h, 0.0f, 250.0f, 1.0, -1.0);
}
void display(void)
{
    int x0 = 100, y0 = 100, r = 60;
    midpointcircle(x0, y0, r);
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowPosition(200, 200);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Circle");
    glutDisplayFunc(display);
    glutReshapeFunc(ChangeSize);
    glutMainLoop();
    return 0;
}