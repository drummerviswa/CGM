#include <GL/glut.h>
#include <iostream>

using namespace std;

int mode = 0; // 1 - translate, 2 - rotate, 3 - scale

int squareX = 200, squareY = 200;
float angle = 0.0f;
int scaleSize = 20;
bool scaleUp = true;

void drawSquare(int x, int y, int s)
{
    double halfside = s / 2;
    glBegin(GL_POLYGON);
    glVertex2d(x + halfside, y + halfside);
    glVertex2d(x + halfside, y - halfside);
    glVertex2d(x - halfside, y - halfside);
    glVertex2d(x - halfside, y + halfside);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 1.0);

    glPushMatrix();

    if (mode == 1)
    {
        drawSquare(squareX, squareY, 20);
    }
    else if (mode == 2)
    {
        glTranslatef(100, 100, 0);
        glRotatef(angle, 0, 0, 1);
        drawSquare(0, 0, 20);
    }
    else if (mode == 3)
    {
        drawSquare(100, 100, scaleSize);
    }

    glPopMatrix();
    glFlush();
}

void timer(int value)
{
    if (mode == 1)
    {
        squareX += 1;
        squareY += 1;
        if (squareX > 400 || squareY > 400)
        {
            squareX = 0;
            squareY = 0;
        }
    }
    else if (mode == 2)
    {
        angle += 5.0f;
        if (angle >= 360.0f)
            angle = 0.0f;
    }
    else if (mode == 3)
    {
        if (scaleUp)
            scaleSize += 2;
        else
            scaleSize -= 2;

        if (scaleSize > 40)
            scaleUp = false;
        if (scaleSize < 20)
            scaleUp = true;
    }

    glutPostRedisplay();
    glutTimerFunc(50, timer, 0);
}

void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(0.0, 400, 0.0, 400);
}

int main(int argc, char **argv)
{
    cout << "\nEnter\n\t<1> for translation"
            "\n\t<2> for rotation"
            "\n\t<3> for scaling\n\t:";
    cin >> mode;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(400, 400);
    glutCreateWindow("2D Transformations");

    init();

    glutDisplayFunc(display);
    glutTimerFunc(50, timer, 0);
    glutMainLoop();
    return 0;
}
