#include <GL/glut.h>
#include <stdio.h>
float teatopX=0,teatopY=0;
float angle=0;
void mouse(int button,int state,int x,int y)
{
    teatopX=(x-150)/150.0;
    teatopY=-(y-150)/150.0;
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        ///glTranslatef(teatopX,teatopY,0);
        glRotatef(angle,0,0,1);
        glutSolidTeapot( 0.3 );
    glPopMatrix();
    glutSwapBuffers();
}
void motion(int x,int y)
{
    angle=x;
    display();
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week03 mouse rotate");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    glutMainLoop();
}
