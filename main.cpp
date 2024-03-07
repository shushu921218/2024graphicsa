#include <GL/glut.h>
#include <stdio.h>
float teatopX=0,teatopY=0;
float angle=0;
int method=1;
int oldX=0,oldY=0;
void mouse(int button,int state,int x,int y)
{
    oldX=x;///teatopX=(x-150)/150.0;
    oldY=y;///teatopY=-(y-150)/150.0;
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef(teatopX,teatopY,0);
        glRotatef(angle,0,0,1);
        glutSolidTeapot( 0.3 );
    glPopMatrix();
    glutSwapBuffers();
}
void motion(int x,int y)
{
    if(method==1)
    {
        angle+=x-oldX;
    }
    else if(method==2)
    {
        teatopX+=(x-oldX)/150.0;
        teatopY-=(y-oldY)/150.0;
    }
    oldX=x;
    oldY=y;
    display();
}
void keyboard(unsigned char key,int x,int y)
{
    if(key=='e') method=1;
    if(key=='w') method=2;
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week03 mouse rotate");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
}
