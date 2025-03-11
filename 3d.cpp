#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    // Cube
    glPushMatrix();
    glTranslatef(1.5, 0, 0);
    gluLookAt(8.0, 4.0, 1.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0);
    glScalef(1.0, 2.0, 1.0);
    glColor3f(1.0, 1.0, 1.0);
    glutSolidCube(1.0);
    glColor3f(0.0, 0.0, 0.0);
    glutWireCube(1);
    glPopMatrix();
    // Pyramid
    glPushMatrix();
    glTranslatef(0, -1, 0);
    gluLookAt(10.0, 7.5, 3.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0);
    glScalef(1.5, 3.0, 1.5);
    glColor3f(1.0, 1.0, 1.0);
    glutSolidTetrahedron();
    glColor3f(0.0, 0.0, 0.0);
    glutWireTetrahedron();
    glPopMatrix();
    glFlush();
}
void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}