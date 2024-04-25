#include <GL/glut.h>
void myBody()
{
    glPushMatrix();
        glColor3f(1,0,0);
        glutWireCube(0.6);///myBody();
    glPopMatrix();
}
void myArm()
{
    glPushMatrix();
        glColor3f(0,1,0);
        glScalef(1,0.4,0.4);///myArm();
        glutWireCube(0.3);
    glPopMatrix();
}
float angle=0;
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    myBody();
    glPushMatrix();
        glTranslatef(0.3,0.3,0);
        glRotatef(angle,0,0,1);
        glTranslatef(0.15,0,0);
        myArm();
        glPushMatrix();
            glTranslatef(0.15,0,0);
            glRotatef(angle,0,0,1);
            glTranslatef(0.15,0,0);
            myArm();
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.3,0.3,0);
        glRotatef(-angle,0,0,1);
        glTranslatef(-0.15,0,0);
        myArm();
        glPushMatrix();
            glTranslatef(-0.15,0,0);
            glRotatef(-angle,0,0,1);
            glTranslatef(-0.15,0,0);
            myArm();
        glPopMatrix();
    glPopMatrix();

	glutSwapBuffers();
}
void motion(int x,int y)
{
    angle=x;
    glutPostRedisplay();///告訴GLUT，貼上便利貼，請GLUT有空時，就要重畫面

}
int main(int argc, char*argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("week10");

	glutDisplayFunc(display);
    glutMotionFunc(motion);
	glutIdleFunc(display);

	glutMainLoop();
}
