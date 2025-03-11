#include <GL/glut.h>
#include <iostream>
#include <math.h>
using namespace std;
int X1, X2, Y1, Y2;
void linebres()
{
    int dx, dy, pk;
    dx = X2 - X1;
    dy = Y2 - Y1;
    pk = 2 * dy - dx;
    // glColor3f(1.0,0.0,1.0); To change color
    // glPointSize(5); //for solid line
    // glBegin(GL_LINES); for dotted lines
    glBegin(GL_POINTS);
    for (int i = 0; i < dx - 1; ++i)
    {
        glVertex2i(X1, Y1);
        pk = (pk < 0) ? (pk + 2 * dy) : ((pk + 2 * dy - 2 * dx) && Y1++);
        X1++;
    }
    glEnd();
    glFlush();
}
int main(int argc, char **argv)
{
    cout << "Enter x1, y1 and x2, y2 points\n";
    cin >> X1 >> Y1 >> X2 >> Y1;
    glutInit(&argc, argv);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Bresenham Line");
    gluOrtho2D(0.0, 400.0, 0.0, 400.0);
    glutDisplayFunc(linebres);
    glutMainLoop();
    return 0;
}