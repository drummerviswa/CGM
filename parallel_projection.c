#include <GL/glut.h>
void display(void)
{
    glutSolidTeapot(.5);
    glFlush();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Teapot");
    glutDisplayFunc(display);
    glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
    glutMainLoop();
    return 0;
}