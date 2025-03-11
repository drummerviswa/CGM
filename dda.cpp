#include <iostream>
#include <math.h>
#include <GL/glut.h>
using namespace std;
double X1, Y1, X2, Y2;
void LineDDA(void)
{
    double dx = (X2 - X1), dy = (Y2 - Y1), steps;
    steps = (abs(dx) > abs(dy)) ? (abs(dx)) : (abs(dy));
    float xInc = dx / steps;
    float yInc = dy / steps;
    // glColor3f(1.0, 1.0, 0.0); To change color
    // glColor3f(1.0,0.0,1.0); To change color
    // glPointSize(5); //for solid line
    // glBegin(GL_LINES); for dotted lines
    glBegin(GL_POINTS);
    for (int k = 0; k < steps; k++)
    {
        glVertex2i(X1, Y1);
        X1 += xInc;
        Y1 += yInc;
    }
    glEnd();
    glFlush();
}
int main(int argc, char **argv)
{
    cout << " Enter x1, y1,x2,y2 points\n";
    cin >> X1 >> Y1 >> X2 >> Y2;
    glutInit(&argc, argv);
    glutInitWindowPosition(150, 150);
    glutInitWindowSize(640, 480);
    glutCreateWindow("DDA_Line");
    gluOrtho2D(0, 400.0, 0, 400.0);
    glutDisplayFunc(LineDDA);
    glutMainLoop();
    return 0;
}