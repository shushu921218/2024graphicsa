#include <GL/glut.h>
#include <stdio.h> ///printf()
float angleX[10]={}, angleY[10]={};
float teapotX=0, teapotY=0;
void display() {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glutSolidSphere(0.02, 30, 30);

    glPushMatrix();
        glTranslatef(0, 0, +6);
        glRotatef(angleX[0], 0, 0, 1);
        glTranslatef(-0.520, -0.133, 0);
        glutSolidTeapot( 0.3 );
    glPopMatrix();
    glutSwapBuffers();
}
int oldX = 0, oldY = 0;
void mouse(int button, int state, int x, int y) {
    oldX = x;
    oldY = y;
}
void motion(int x, int y) {
    angleX[0] += (x - oldX);
    oldX = x;
    oldY = y;
    glutPostRedisplay();
}
static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 0.01, 10.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(800,400);
    glutCreateWindow("week15-4");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutReshapeFunc(resize);

    glutMainLoop();
}
