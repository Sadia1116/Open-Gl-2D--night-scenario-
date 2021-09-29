/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include<stdio.h>
#include<math.h>
#define PI 3.1416

float cx=0, cy=0, angle=0;
float sx=0.04, sy=0.04;
float carx=0, cary=0;

void init()
{
    glClearColor(0.184314f, 0.184314f, 0.309804f,0.0f);
    glOrtho(-10,+10,-10,+10,-10,+10);

}

void CircleP(float radiusX,float radiusY)
{
    int i=0;
    float angle= 0;

    glBegin(GL_POLYGON);
    for(i=0;i<100;i++)
    {
        angle=2*PI*i/100;
        glVertex2d(radiusX*cos(angle),radiusY*sin(angle));
        //printf("Angle : %f , X-Axis : %f , Y-Axis : %f\n",angle,radiusX*cos(angle),radiusY*sin(angle));

    }
    glEnd();

}

/*void Car()
{
    if(carx>12)
    {
        carx=-10;
    }
    angle=angle-0.5;
    carx=carx+0.015;
    glutPostRedisplay();
}*/


void rotateC()
{
    if(cx>12)
    {
        cx=-10;
    }
    cx=cx+0.002;
    glutPostRedisplay();
}
void starT()
{
    sx=0.04;
    sy=0.04;
    glutPostRedisplay();
}

void starT2()
{
    sx=0.0001;
    sy=0.0001;
    glutPostRedisplay();
}


void normalKey(unsigned char key, int x, int y)
{
    switch(key){

    case 'a':

        glutIdleFunc(rotateC);
        break;
         case 'x':
        glutIdleFunc(starT);
        break;

        case 'z':
        glutIdleFunc(starT2);
        break;

        //case 'v':
        //glutIdleFunc(Car);
        //break;

        case 's':
        glutIdleFunc(NULL);

        glutPostRedisplay();
        break;


      default:
        break;

}
}
//..........................................................................instraction for car
void specialKey(int key,int x, int y)
{

    switch(key){

    case GLUT_KEY_LEFT:
        carx--;
        glutPostRedisplay();
        break;

    case GLUT_KEY_RIGHT:
        carx++;
        glutPostRedisplay();
        break;





        default:
        break;


    }

}
void CircleL(float radiusX,float radiusY)
{
    int i=0;
    float angle= 0;

    glBegin(GL_LINE_LOOP);
    for(i=0;i<100;i++)
    {
        angle=2*PI*i/100;
        glVertex2d(radiusX*cos(angle),radiusY*sin(angle));
        //printf("Angle : %f , X-Axis : %f , Y-Axis : %f\n",angle,radiusX*cos(angle),radiusY*sin(angle));

    }
    glEnd();

}


//...................for car
void CircleC(float radiusX,float radiusY)
{
    int i=0;
    float angle= 0;

    glBegin(GL_POLYGON);
    for(i=0;i<50;i++)
    {
        angle=2*PI*i/100;
        glVertex2d(radiusX*cos(angle),radiusY*sin(angle));
        //printf("Angle : %f , X-Axis : %f , Y-Axis : %f\n",angle,radiusX*cos(angle),radiusY*sin(angle));

    }
    glEnd();

}



void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);

       //moon
        glPushMatrix();
        glTranslated(7.8,8.5,0);
        glScaled(0.60,0.60,0);
        glColor3f(1,1,1);
        CircleP(1,1.75);
        glPopMatrix();
        glEnd();

        //hill start
        glPushMatrix();
        glTranslated(0,0,0);
        glScaled(1,1.5,0);

        //hill 1
        glBegin(GL_TRIANGLES);

        glColor3ub(53, 79, 1);
        glVertex2d(-10.5,0);
        glVertex2d(-9,5);
        glVertex2d(-8,0);
        glEnd();

        //hill 2
        glBegin(GL_TRIANGLES);

        glColor3ub(53, 79, 1);
        glVertex2d(-9.80,0);
        glVertex2d(-7,3);
        glVertex2d(-6,0);
        glEnd();

        //hill 3
        glBegin(GL_TRIANGLES);

        glColor3ub(53, 79, 1);
        glVertex2d(-6.80,0);
        glVertex2d(-5,5.5);
        glVertex2d(-4,0);
        glEnd();

        //hill 4
        glBegin(GL_TRIANGLES);

        glColor3ub(53, 79, 1);
        glVertex2d(-4.70,0);
        glVertex2d(-3,4);
        glVertex2d(-2,0);
        glEnd();

        //hill 5
        glBegin(GL_TRIANGLES);

        glColor3ub(53, 79, 1);
        glVertex2d(-3.70,0);
        glVertex2d(-1,4);
        glVertex2d(1,0);
        glEnd();

        //hill 6
        glBegin(GL_TRIANGLES);

        glColor3ub(53, 79, 1);
        glVertex2d(0,0);
        glVertex2d(2,4.5);
        glVertex2d(3.5,0);
        glEnd();

        //hill 7
        glBegin(GL_TRIANGLES);

        glColor3ub(53, 79, 1);
        glVertex2d(3,0);
        glVertex2d(4,2.5);
        glVertex2d(5,0);
        glEnd();

        //hill 8
        glBegin(GL_TRIANGLES);

        glColor3ub(53, 79, 1);
        glVertex2d(4.7,0);
        glVertex2d(5.5,4);
        glVertex2d(7,0);
        glEnd();

        //hill 9
        glBegin(GL_TRIANGLES);

        glColor3ub(53, 79, 1);
        glVertex2d(6.5,0);
        glVertex2d(8,2);
        glVertex2d(10.5,0);
        glEnd();
        glPopMatrix();
        //hill end


        //------Star1-------
         glPushMatrix();
        glScaled(sx,sy,0);
        glTranslated(130,220,0);
        glBegin(GL_POLYGON);

        glColor3f(1,1,1);
        glVertex2d(1,0);
        glVertex2d(2,1);
        glVertex2d(.5,1.25);
        glVertex2d(0,3);

        glVertex2d(-1,0);
        glVertex2d(-2,1);
        glVertex2d(-.5,1.25);
        glVertex2d(-0,3);

        glVertex2d(1,0);
        glVertex2d(-1,0);
        glVertex2d(-1.25,-2.25);
        glVertex2d(0,-1);
        glVertex2d(1.25,-2.25);

        glEnd();
        glPopMatrix();


        //------Star2-------
        glPushMatrix();
        glScaled(sx,sy,0);
        glTranslated(100,230,0);
        glBegin(GL_POLYGON);

        glColor3f(1,1,1);
        glVertex2d(1,0);
        glVertex2d(2,1);
        glVertex2d(.5,1.25);
        glVertex2d(0,3);

        glVertex2d(-1,0);
        glVertex2d(-2,1);
        glVertex2d(-.5,1.25);
        glVertex2d(-0,3);

        glVertex2d(1,0);
        glVertex2d(-1,0);
        glVertex2d(-1.25,-2.25);
        glVertex2d(0,-1);
        glVertex2d(1.25,-2.25);

        glEnd();
        glPopMatrix();


        //------Star3-------
        glPushMatrix();
        glScaled(sx,sy,0);
        glTranslated(80,180,0);
        glBegin(GL_POLYGON);

        glColor3f(1,1,1);
        glVertex2d(1,0);
        glVertex2d(2,1);
        glVertex2d(.5,1.25);
        glVertex2d(0,3);

        glVertex2d(-1,0);
        glVertex2d(-2,1);
        glVertex2d(-.5,1.25);
        glVertex2d(-0,3);

        glVertex2d(1,0);
        glVertex2d(-1,0);
        glVertex2d(-1.25,-2.25);
        glVertex2d(0,-1);
        glVertex2d(1.25,-2.25);

        glEnd();
        glPopMatrix();

        //------Star4-------
        glPushMatrix();
        glScaled(sx,sy,0);
        glTranslated(40,200,0);
        glBegin(GL_POLYGON);

        glColor3f(1,1,1);
        glVertex2d(1,0);
        glVertex2d(2,1);
        glVertex2d(.5,1.25);
        glVertex2d(0,3);

        glVertex2d(-1,0);
        glVertex2d(-2,1);
        glVertex2d(-.5,1.25);
        glVertex2d(-0,3);

        glVertex2d(1,0);
        glVertex2d(-1,0);
        glVertex2d(-1.25,-2.25);
        glVertex2d(0,-1);
        glVertex2d(1.25,-2.25);

        glEnd();
        glPopMatrix();

        //------Star5-------
        glPushMatrix();
        glScaled(sx,sy,0);
        glTranslated(0,220,0);
        glBegin(GL_POLYGON);

        glColor3f(1,1,1);
        glVertex2d(1,0);
        glVertex2d(2,1);
        glVertex2d(.5,1.25);
        glVertex2d(0,3);

        glVertex2d(-1,0);
        glVertex2d(-2,1);
        glVertex2d(-.5,1.25);
        glVertex2d(-0,3);

        glVertex2d(1,0);
        glVertex2d(-1,0);
        glVertex2d(-1.25,-2.25);
        glVertex2d(0,-1);
        glVertex2d(1.25,-2.25);

        glEnd();
        glPopMatrix();

        //------Star6-------
        glPushMatrix();
        glScaled(sx,sy,0);
        glTranslated(-40,180,0);
        glBegin(GL_POLYGON);

        glColor3f(1,1,1);
        glVertex2d(1,0);
        glVertex2d(2,1);
        glVertex2d(.5,1.25);
        glVertex2d(0,3);

        glVertex2d(-1,0);
        glVertex2d(-2,1);
        glVertex2d(-.5,1.25);
        glVertex2d(-0,3);

        glVertex2d(1,0);
        glVertex2d(-1,0);
        glVertex2d(-1.25,-2.25);
        glVertex2d(0,-1);
        glVertex2d(1.25,-2.25);

        glEnd();
        glPopMatrix();

        //------Star7-------
        glPushMatrix();
        glScaled(sx,sy,0);
        glTranslated(-70,200,0);
        glBegin(GL_POLYGON);

        glColor3f(1,1,1);
        glVertex2d(1,0);
        glVertex2d(2,1);
        glVertex2d(.5,1.25);
        glVertex2d(0,3);

        glVertex2d(-1,0);
        glVertex2d(-2,1);
        glVertex2d(-.5,1.25);
        glVertex2d(-0,3);

        glVertex2d(1,0);
        glVertex2d(-1,0);
        glVertex2d(-1.25,-2.25);
        glVertex2d(0,-1);
        glVertex2d(1.25,-2.25);

        glEnd();
        glPopMatrix();

        //------Star8-------
        glPushMatrix();
        glScaled(sx,sy,0);
        glTranslated(-100,170,0);
        glBegin(GL_POLYGON);

        glColor3f(1,1,1);
        glVertex2d(1,0);
        glVertex2d(2,1);
        glVertex2d(.5,1.25);
        glVertex2d(0,3);

        glVertex2d(-1,0);
        glVertex2d(-2,1);
        glVertex2d(-.5,1.25);
        glVertex2d(-0,3);

        glVertex2d(1,0);
        glVertex2d(-1,0);
        glVertex2d(-1.25,-2.25);
        glVertex2d(0,-1);
        glVertex2d(1.25,-2.25);

        glEnd();
        glPopMatrix();

        //------Star9-------
        glPushMatrix();
        glScaled(sx,sy,0);
        glTranslated(-150,210,0);
        glBegin(GL_POLYGON);

        glColor3f(1,1,1);
        glVertex2d(1,0);
        glVertex2d(2,1);
        glVertex2d(.5,1.25);
        glVertex2d(0,3);

        glVertex2d(-1,0);
        glVertex2d(-2,1);
        glVertex2d(-.5,1.25);
        glVertex2d(-0,3);

        glVertex2d(1,0);
        glVertex2d(-1,0);
        glVertex2d(-1.25,-2.25);
        glVertex2d(0,-1);
        glVertex2d(1.25,-2.25);

        glEnd();
        glPopMatrix();

        //------Star10-------
        glPushMatrix();
        glScaled(sx,sy,0);
        glTranslated(-210,190,0);
        glBegin(GL_POLYGON);

        glColor3f(1,1,1);
        glVertex2d(1,0);
        glVertex2d(2,1);
        glVertex2d(.5,1.25);
        glVertex2d(0,3);

        glVertex2d(-1,0);
        glVertex2d(-2,1);
        glVertex2d(-.5,1.25);
        glVertex2d(-0,3);

        glVertex2d(1,0);
        glVertex2d(-1,0);
        glVertex2d(-1.25,-2.25);
        glVertex2d(0,-1);
        glVertex2d(1.25,-2.25);

        glEnd();
        glPopMatrix();

        //------Star11-------
        glPushMatrix();
        glScaled(sx,sy,0);
        glTranslated(-180,190,0);
        glBegin(GL_POLYGON);

        glColor3f(1,1,1);
        glVertex2d(1,0);
        glVertex2d(2,1);
        glVertex2d(.5,1.25);
        glVertex2d(0,3);

        glVertex2d(-1,0);
        glVertex2d(-2,1);
        glVertex2d(-.5,1.25);
        glVertex2d(-0,3);

        glVertex2d(1,0);
        glVertex2d(-1,0);
        glVertex2d(-1.25,-2.25);
        glVertex2d(0,-1);
        glVertex2d(1.25,-2.25);

        glEnd();
        glPopMatrix();

        //------Star12-------
        glPushMatrix();
        glScaled(sx,sy,0);
        glTranslated(160,195,0);
        glBegin(GL_POLYGON);

        glColor3f(1,1,1);
        glVertex2d(1,0);
        glVertex2d(2,1);
        glVertex2d(.5,1.25);
        glVertex2d(0,3);

        glVertex2d(-1,0);
        glVertex2d(-2,1);
        glVertex2d(-.5,1.25);
        glVertex2d(-0,3);

        glVertex2d(1,0);
        glVertex2d(-1,0);
        glVertex2d(-1.25,-2.25);
        glVertex2d(0,-1);
        glVertex2d(1.25,-2.25);

        glEnd();
        glPopMatrix();

        //------Star13-------
        glPushMatrix();
        glScaled(sx,sy,0);
        glTranslated(125,170,0);
        glBegin(GL_POLYGON);

        glColor3f(1,1,1);
        glVertex2d(1,0);
        glVertex2d(2,1);
        glVertex2d(.5,1.25);
        glVertex2d(0,3);

        glVertex2d(-1,0);
        glVertex2d(-2,1);
        glVertex2d(-.5,1.25);
        glVertex2d(-0,3);

        glVertex2d(1,0);
        glVertex2d(-1,0);
        glVertex2d(-1.25,-2.25);
        glVertex2d(0,-1);
        glVertex2d(1.25,-2.25);

        glEnd();
        glPopMatrix();
        //----End of Star---


        //Cloud 1
        glPushMatrix();
        glTranslated(cx,cy,0);

        glPushMatrix();
        glTranslated(0,8.5,0);
        glScaled(0.3,0.4,0);

        glPushMatrix();
        glTranslated(0,-0.2,0);
        glColor3f(0.96,0.96,0.96);
        glBegin(GL_POLYGON);
        glVertex2d(0,0);
        glVertex2d(6,0);
        glVertex2d(3,2);
        glEnd();
        glPopMatrix();


        glPushMatrix();
        glTranslated(3,1.7,0);
        glColor3f(0.96,0.96,0.96);
        CircleP(0.8,0.8);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.1,0.5,0);
        glColor3f(0.96,0.96,0.96);
        CircleP(0.7,0.7);
        glPopMatrix();

        glPushMatrix();
        glTranslated(5.9,0.5,0);
        glColor3f(0.96,0.96,0.96);
        CircleP(0.7,0.7);
        glPopMatrix();

        glPushMatrix();
        glTranslated(1,0.5,0);
        glColor3f(0.96,0.96,0.96);
        CircleP(0.5,0.5);
        glPopMatrix();

        glPushMatrix();
        glTranslated(1.6,1,0);
        glColor3f(0.96,0.96,0.96);
        CircleP(0.5,0.5);
        glPopMatrix();


        glPushMatrix();
        glTranslated(2.4,1.1,0);
        glColor3f(0.96,0.96,0.96);
        CircleP(0.5,0.5);
        glPopMatrix();


        glPushMatrix();
        glTranslated(5,0.5,0);
        glColor3f(0.96,0.96,0.96);
        CircleP(0.5,0.5);
        glPopMatrix();

        glPushMatrix();
        glTranslated(4.5,1,0);
        glColor3f(0.96,0.96,0.96);
        CircleP(0.5,0.5);
        glPopMatrix();


        glPushMatrix();
        glTranslated(3.7,0.9,0);
        glColor3f(0.96,0.96,0.96);
        CircleP(0.5,0.5);
        glPopMatrix();

        glEnd();
        glPopMatrix();

        glPopMatrix();


        //Cloud 2

        glPushMatrix();
        glTranslated(cx,cy,0);

        glPushMatrix();
        glTranslated(-4,6,0);
        glScaled(0.3,0.3,0);

//......................................
        glPushMatrix();
        glTranslated(0,-0.2,0);
        glColor3f(0.96,0.96,0.96);
        glBegin(GL_POLYGON);
        glVertex2d(0,0);
        glVertex2d(6,0);
        glVertex2d(3,2);
        glEnd();
        glPopMatrix();

        //..........
        glPushMatrix();
        glTranslated(0.2,0.9,0);
        glColor3f(0.96,0.96,0.96);
        CircleP(1,1.1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(1.3,2,0);
        glColor3f(0.96,0.96,0.96);
        CircleP(1,1.8);
        glPopMatrix();


        glPushMatrix();
        glTranslated(2.7,1.4,0);
        glColor3f(0.96,0.96,0.96);
        CircleP(.5,1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(3.5,1.8,0);
        glColor3f(0.96,0.96,0.96);
        CircleP(.5,1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(4.8,1.5,0);
        glColor3f(0.96,0.96,0.96);
        CircleP(1,1.6);
        glPopMatrix();

        glPushMatrix();
        glTranslated(5.8,0.8,0);
        glColor3f(0.96,0.96,0.96);
        CircleP(1,1);
        glPopMatrix();

        glPopMatrix();


        glPopMatrix();


        //Cloud 3

        glPushMatrix();
        glTranslated(cx,cy,0);

        glPushMatrix();
        glTranslated(5,6,0);
        glScaled(0.3,0.3,0);

//......................................
        glPushMatrix();
        glTranslated(0,-0.2,0);
        glColor3f(0.96,0.96,0.96);
        glBegin(GL_POLYGON);
        glVertex2d(0,0);
        glVertex2d(6,0);
        glVertex2d(3,2);
        glEnd();
        glPopMatrix();

        //..........
        glPushMatrix();
        glTranslated(0.2,0.9,0);
        glColor3f(0.96,0.96,0.96);
        CircleP(1,1.1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(1.3,2,0);
        glColor3f(0.96,0.96,0.96);
        CircleP(1,1.8);
        glPopMatrix();


        glPushMatrix();
        glTranslated(2.7,1.4,0);
        glColor3f(0.96,0.96,0.96);
        CircleP(.5,1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(3.5,1.8,0);
        glColor3f(0.96,0.96,0.96);
        CircleP(.5,1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(4.8,1.5,0);
        glColor3f(0.96,0.96,0.96);
        CircleP(1,1.6);
        glPopMatrix();

        glPushMatrix();
        glTranslated(5.8,0.8,0);
        glColor3f(0.96,0.96,0.96);
        CircleP(1,1);
        glPopMatrix();

        glPopMatrix();


        glPopMatrix();
        //............................cloud4


        glPushMatrix();
        glTranslated(cx,cy,0);

        glPushMatrix();
        glTranslated(-9,8,0);
        glScaled(0.3,0.3,0);

//......................................
        glPushMatrix();
        glTranslated(0,-0.2,0);
        glColor3f(0.96,0.96,0.96);
        glBegin(GL_POLYGON);
        glVertex2d(0,0);
        glVertex2d(6,0);
        glVertex2d(3,2);
        glEnd();
        glPopMatrix();

        //..........
        glPushMatrix();
        glTranslated(0.2,0.9,0);
        glColor3f(0.96,0.96,0.96);
        CircleP(1,1.1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(1.3,2,0);
        glColor3f(0.96,0.96,0.96);
        CircleP(1,1.8);
        glPopMatrix();


        glPushMatrix();
        glTranslated(2.7,1.4,0);
        glColor3f(0.96,0.96,0.96);
        CircleP(.5,1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(3.5,1.8,0);
        glColor3f(0.96,0.96,0.96);
        CircleP(.5,1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(4.8,1.5,0);
        glColor3f(0.96,0.96,0.96);
        CircleP(1,1.6);
        glPopMatrix();

        glPushMatrix();
        glTranslated(5.8,0.8,0);
        glColor3f(0.96,0.96,0.96);
        CircleP(1,1);
        glPopMatrix();

        glPopMatrix();


        glPopMatrix();


        //-----cloud end-------





//.........................park...........
glPushMatrix();
        glTranslated(0,-7,0);
        glBegin(GL_POLYGON);

        glColor3f(0.48,1,0);
        glVertex2d(10,0);
        glVertex2d(-10,0);
        glVertex2d(-10,7);
        glVertex2d(10,7);

        glEnd();
        glPopMatrix();

//........................................park end..................

//-------------------------x-mas tree
        glPushMatrix();
        glTranslated(-10.8,0.9,0);
        glScaled(0.3,0.25,1.5);


        glPushMatrix();
        glTranslated(4,3.2,0);
        glColor3f(0,0.6,0);

        glBegin(GL_TRIANGLES);

        glVertex2d(1,0);
        glVertex2d(2,0);
        glVertex2d(1.5,1.5);

        glEnd();

        glPopMatrix();


        glPushMatrix();
        glTranslated(4,2,0);
        glColor3f(0,0.6,0);

        glBegin(GL_TRIANGLES);

        glVertex2d(0,0);
        glVertex2d(3,0);
        glVertex2d(1.5,1.5);

        glEnd();

        glPopMatrix();


        glPushMatrix();
        glTranslated(4.5,1.4,0);
        glColor3f(0,0.6,0);

        glBegin(GL_TRIANGLES);

        glVertex2d(-1,0);
        glVertex2d(3,0);
        glVertex2d(1,1);

        glEnd();

        glPopMatrix();

//..................................guri
        glPushMatrix();
        glTranslated(5.4,-3.6,0);
        glColor3f(0.54,0.27,0.07);

        glBegin(GL_POLYGON);

        glVertex2d(0,0);
        glVertex2d(0.3,0);
        glVertex2d(0.3,5);
        glVertex2d(0,5);

        glEnd();

        glPopMatrix();

 glEnd();

        glPopMatrix();
        //.............................right side
        //-------------------------x-mas tree
        glPushMatrix();
        glTranslated(-5.5,0.9,0);
        glScaled(0.3,0.25,1.5);


        glPushMatrix();
        glTranslated(4,3.2,0);
        glColor3f(0,0.6,0);

        glBegin(GL_TRIANGLES);

        glVertex2d(1,0);
        glVertex2d(2,0);
        glVertex2d(1.5,1.5);

        glEnd();

        glPopMatrix();


        glPushMatrix();
        glTranslated(4,2,0);
        glColor3f(0,0.6,0);

        glBegin(GL_TRIANGLES);

        glVertex2d(0,0);
        glVertex2d(3,0);
        glVertex2d(1.5,1.5);

        glEnd();

        glPopMatrix();


        glPushMatrix();
        glTranslated(4.5,1.4,0);
        glColor3f(0,0.6,0);

        glBegin(GL_TRIANGLES);

        glVertex2d(-1,0);
        glVertex2d(3,0);
        glVertex2d(1,1);

        glEnd();

        glPopMatrix();

//..................................guri
        glPushMatrix();
        glTranslated(5.4,-3.6,0);
        glColor3f(0.54,0.27,0.07);

        glBegin(GL_POLYGON);

        glVertex2d(0,0);
        glVertex2d(0.3,0);
        glVertex2d(0.3,5);
        glVertex2d(0,5);

        glEnd();

        glPopMatrix();

 glEnd();

        glPopMatrix();
//...................................
 //-------------------------x-mas tree
        glPushMatrix();
        glTranslated(-4.5,0.9,0);
        glScaled(0.3,0.25,1.5);


        glPushMatrix();
        glTranslated(4,3.2,0);
        glColor3f(0,0.6,0);

        glBegin(GL_TRIANGLES);

        glVertex2d(1,0);
        glVertex2d(2,0);
        glVertex2d(1.5,1.5);

        glEnd();

        glPopMatrix();


        glPushMatrix();
        glTranslated(4,2,0);
        glColor3f(0,0.6,0);

        glBegin(GL_TRIANGLES);

        glVertex2d(0,0);
        glVertex2d(3,0);
        glVertex2d(1.5,1.5);

        glEnd();

        glPopMatrix();


        glPushMatrix();
        glTranslated(4.5,1.4,0);
        glColor3f(0,0.6,0);

        glBegin(GL_TRIANGLES);

        glVertex2d(-1,0);
        glVertex2d(3,0);
        glVertex2d(1,1);

        glEnd();

        glPopMatrix();

//..................................guri
        glPushMatrix();
        glTranslated(5.4,-3.6,0);
        glColor3f(0.54,0.27,0.07);

        glBegin(GL_POLYGON);

        glVertex2d(0,0);
        glVertex2d(0.3,0);
        glVertex2d(0.3,5);
        glVertex2d(0,5);

        glEnd();

        glPopMatrix();

 glEnd();

        glPopMatrix();
//............................
 //-------------------------x-mas tree
        glPushMatrix();
        glTranslated(-3.5,0.9,0);
        glScaled(0.3,0.25,1.5);


        glPushMatrix();
        glTranslated(4,3.2,0);
        glColor3f(0,0.6,0);

        glBegin(GL_TRIANGLES);

        glVertex2d(1,0);
        glVertex2d(2,0);
        glVertex2d(1.5,1.5);

        glEnd();

        glPopMatrix();


        glPushMatrix();
        glTranslated(4,2,0);
        glColor3f(0,0.6,0);

        glBegin(GL_TRIANGLES);

        glVertex2d(0,0);
        glVertex2d(3,0);
        glVertex2d(1.5,1.5);

        glEnd();

        glPopMatrix();


        glPushMatrix();
        glTranslated(4.5,1.4,0);
        glColor3f(0,0.6,0);

        glBegin(GL_TRIANGLES);

        glVertex2d(-1,0);
        glVertex2d(3,0);
        glVertex2d(1,1);

        glEnd();

        glPopMatrix();

//..................................guri
        glPushMatrix();
        glTranslated(5.4,-3.6,0);
        glColor3f(0.54,0.27,0.07);

        glBegin(GL_POLYGON);

        glVertex2d(0,0);
        glVertex2d(0.3,0);
        glVertex2d(0.3,5);
        glVertex2d(0,5);

        glEnd();

        glPopMatrix();

 glEnd();

        glPopMatrix();

//...............................................
 //-------------------------x-mas tree
        glPushMatrix();
        glTranslated(2.5,0.9,0);
        glScaled(0.3,0.25,1.5);


        glPushMatrix();
        glTranslated(4,3.2,0);
        glColor3f(0,0.6,0);

        glBegin(GL_TRIANGLES);

        glVertex2d(1,0);
        glVertex2d(2,0);
        glVertex2d(1.5,1.5);

        glEnd();

        glPopMatrix();


        glPushMatrix();
        glTranslated(4,2,0);
        glColor3f(0,0.6,0);

        glBegin(GL_TRIANGLES);

        glVertex2d(0,0);
        glVertex2d(3,0);
        glVertex2d(1.5,1.5);

        glEnd();

        glPopMatrix();


        glPushMatrix();
        glTranslated(4.5,1.4,0);
        glColor3f(0,0.6,0);

        glBegin(GL_TRIANGLES);

        glVertex2d(-1,0);
        glVertex2d(3,0);
        glVertex2d(1,1);

        glEnd();

        glPopMatrix();

//..................................guri
        glPushMatrix();
        glTranslated(5.4,-3.6,0);
        glColor3f(0.54,0.27,0.07);

        glBegin(GL_POLYGON);

        glVertex2d(0,0);
        glVertex2d(0.3,0);
        glVertex2d(0.3,5);
        glVertex2d(0,5);

        glEnd();

        glPopMatrix();

 glEnd();

        glPopMatrix();

//....................................
 //-------------------------x-mas tree
        glPushMatrix();
        glTranslated(3.5,0.9,0);
        glScaled(0.3,0.25,1.5);


        glPushMatrix();
        glTranslated(4,3.2,0);
        glColor3f(0,0.6,0);

        glBegin(GL_TRIANGLES);

        glVertex2d(1,0);
        glVertex2d(2,0);
        glVertex2d(1.5,1.5);

        glEnd();

        glPopMatrix();


        glPushMatrix();
        glTranslated(4,2,0);
        glColor3f(0,0.6,0);

        glBegin(GL_TRIANGLES);

        glVertex2d(0,0);
        glVertex2d(3,0);
        glVertex2d(1.5,1.5);

        glEnd();

        glPopMatrix();


        glPushMatrix();
        glTranslated(4.5,1.4,0);
        glColor3f(0,0.6,0);

        glBegin(GL_TRIANGLES);

        glVertex2d(-1,0);
        glVertex2d(3,0);
        glVertex2d(1,1);

        glEnd();

        glPopMatrix();

//..................................guri
        glPushMatrix();
        glTranslated(5.4,-3.6,0);
        glColor3f(0.54,0.27,0.07);

        glBegin(GL_POLYGON);

        glVertex2d(0,0);
        glVertex2d(0.3,0);
        glVertex2d(0.3,5);
        glVertex2d(0,5);

        glEnd();

        glPopMatrix();

 glEnd();

        glPopMatrix();

//.......................................
 //-------------------------x-mas tree
        glPushMatrix();
        glTranslated(4.5,0.9,0);
        glScaled(0.3,0.25,1.5);


        glPushMatrix();
        glTranslated(4,3.2,0);
        glColor3f(0,0.6,0);

        glBegin(GL_TRIANGLES);

        glVertex2d(1,0);
        glVertex2d(2,0);
        glVertex2d(1.5,1.5);

        glEnd();

        glPopMatrix();


        glPushMatrix();
        glTranslated(4,2,0);
        glColor3f(0,0.6,0);

        glBegin(GL_TRIANGLES);

        glVertex2d(0,0);
        glVertex2d(3,0);
        glVertex2d(1.5,1.5);

        glEnd();

        glPopMatrix();


        glPushMatrix();
        glTranslated(4.5,1.4,0);
        glColor3f(0,0.6,0);

        glBegin(GL_TRIANGLES);

        glVertex2d(-1,0);
        glVertex2d(3,0);
        glVertex2d(1,1);

        glEnd();

        glPopMatrix();

//..................................guri
        glPushMatrix();
        glTranslated(5.4,-3.6,0);
        glColor3f(0.54,0.27,0.07);

        glBegin(GL_POLYGON);

        glVertex2d(0,0);
        glVertex2d(0.3,0);
        glVertex2d(0.3,5);
        glVertex2d(0,5);

        glEnd();

        glPopMatrix();

 glEnd();

        glPopMatrix();

//......................................
 //-------------------------x-mas tree
        glPushMatrix();
        glTranslated(5.5,0.9,0);
        glScaled(0.3,0.25,1.5);


        glPushMatrix();
        glTranslated(4,3.2,0);
        glColor3f(0,0.6,0);

        glBegin(GL_TRIANGLES);

        glVertex2d(1,0);
        glVertex2d(2,0);
        glVertex2d(1.5,1.5);

        glEnd();

        glPopMatrix();


        glPushMatrix();
        glTranslated(4,2,0);
        glColor3f(0,0.6,0);

        glBegin(GL_TRIANGLES);

        glVertex2d(0,0);
        glVertex2d(3,0);
        glVertex2d(1.5,1.5);

        glEnd();

        glPopMatrix();


        glPushMatrix();
        glTranslated(4.5,1.4,0);
        glColor3f(0,0.6,0);

        glBegin(GL_TRIANGLES);

        glVertex2d(-1,0);
        glVertex2d(3,0);
        glVertex2d(1,1);

        glEnd();

        glPopMatrix();

//..................................guri
        glPushMatrix();
        glTranslated(5.4,-3.6,0);
        glColor3f(0.54,0.27,0.07);

        glBegin(GL_POLYGON);

        glVertex2d(0,0);
        glVertex2d(0.3,0);
        glVertex2d(0.3,5);
        glVertex2d(0,5);

        glEnd();

        glPopMatrix();

 glEnd();

        glPopMatrix();





//woodenhouse

        glPushMatrix();
        glScaled(0.6,0.4,1);
        glTranslated(-10.5,5,0);

        //tin er caal
        glPushMatrix();
        glTranslated(0,4,0);
        glBegin(GL_POLYGON);

        glColor3f(0.78,0,0);
        glVertex2d(3,3);
        glVertex2d(-3,3);
        glVertex2d(-4,0);
        glVertex2d(4,0);
        glEnd();
        glPopMatrix();

        //gorer kogkal
        glPushMatrix();
        glTranslated(0,4,0);
        glBegin(GL_POLYGON);

        glColor3f(0.871,0.722,0.529);
        glVertex2d(3.5,0);
        glVertex2d(-3.5,0);
        glVertex2d(-3.5,-9);
        glVertex2d(3.5,-9);

        glEnd();
        glPopMatrix();

        //left 1st janala
        glPushMatrix();
        glTranslated(-2,2,0);
        glBegin(GL_QUADS);

        glColor3f(1,1,1);
        glVertex2d(1,1);
        glVertex2d(-1,1);
        glVertex2d(-1,-2);
        glVertex2d(1,-2);

        glEnd();
        glPopMatrix();


        //left 2st janala
        glPushMatrix();
        glTranslated(-2,-2,0);
        glBegin(GL_POLYGON);

        glColor3f(1,1,1);
        glVertex2d(1,1);
        glVertex2d(-1,1);
        glVertex2d(-1,-2);
        glVertex2d(1,-2);

        glEnd();
        glPopMatrix();




        //right 1st janala
        glPushMatrix();
        glTranslated(2,2,0);
        glBegin(GL_POLYGON);

        glColor3f(1,1,1);
        glVertex2d(1,1);
        glVertex2d(-1,1);
        glVertex2d(-1,-2);
        glVertex2d(1,-2);

        glEnd();
        glPopMatrix();


        //right 2st janala
        glPushMatrix();
        glTranslated(2,-2,0);
        glBegin(GL_POLYGON);

        glColor3f(1,1,1);
        glVertex2d(1,1);
        glVertex2d(-1,1);
        glVertex2d(-1,-2);
        glVertex2d(1,-2);

        glEnd();
        glPopMatrix();


        glBegin(GL_LINES);// 1row line
        glColor3f(0.0f,0.0f,0.0f);
        glVertex2f(-3,1.5);
        glVertex2f(-1,1.5);
        glEnd();

        glBegin(GL_LINES);// 1column line
        glColor3f(0.0f,0.0f, 0.0f);
        glVertex2f(-2,3);
        glVertex2f(-2,0);
        glEnd();

        glBegin(GL_LINES);// 2row line
        glColor3f(0.0f,0.0f,0.0f);
        glVertex2f(3,1.5);
        glVertex2f(1,1.5);
        glEnd();

        glBegin(GL_LINES);// 2column line
        glColor3f(0.0f,0.0f, 0.0f);
        glVertex2f(2,3);
        glVertex2f(2,0);
        glEnd();




        glBegin(GL_LINES);// 3row line
        glColor3f(0.0f,0.0f,0.0f);
        glVertex2f(1,-2.5);
        glVertex2f(3,-2.5);
        glEnd();

        glBegin(GL_LINES);// 3column line
        glColor3f(0.0f,0.0f, 0.0f);
        glVertex2f(2,-1);
        glVertex2f(2,-4);
        glEnd();




        glBegin(GL_LINES);// 4row line
        glColor3f(0.0f,0.0f,0.0f);
        glVertex2f(-3,-2.5);
        glVertex2f(-1,-2.5);
        glEnd();

        glBegin(GL_LINES);// 4column line
        glColor3f(0.0f,0.0f, 0.0f);
        glVertex2f(-2,-1);
        glVertex2f(-2,-4);
        glEnd();




        //door
        glPushMatrix();
        glTranslated(0,0,0);
        glBegin(GL_POLYGON);

        glColor3f(1,1,1);
        glVertex2d(0.5,3);
        glVertex2d(-0.5,3);
        glVertex2d(-0.5,-4);
        glVertex2d(0.5,-4);
        glEnd();
        glPopMatrix();

        glBegin(GL_LINES);
        glColor3f(0.0f,0.0f,0.0f);
        glVertex2f(0,3);
        glVertex2f(0,-4);
        glEnd();

        glBegin(GL_LINES);
        glColor3f(0.0f,0.0f,0.0f);
        glVertex2f(-0.5,3);
        glVertex2f(-0.5,-4);
        glEnd();

        glBegin(GL_LINES);
        glColor3f(0.0f,0.0f,0.0f);
        glVertex2f(0.5,3);
        glVertex2f(0.5,-4);
        glEnd();

        glBegin(GL_LINES);
        glColor3f(0.0f,0.0f,0.0f);
        glVertex2f(-0.5,3);
        glVertex2f(0.5,3);
        glEnd();


        glBegin(GL_LINES);
        glColor3f(0.0f,0.0f,0.0f);
        glVertex2f(-0.5,-4);
        glVertex2f(0.5,-4);
        glEnd();

        glBegin(GL_LINES);
        glColor3f(0.0f,0.0f,0.0f);
        glVertex2f(-0.5,-3);
        glVertex2f(0.5,-3);
        glEnd();

        glBegin(GL_LINES);
        glColor3f(0.0f,0.0f,0.0f);
        glVertex2f(-0.5,-2);
        glVertex2f(0.5,-2);
        glEnd();

        glBegin(GL_LINES);
        glColor3f(0.0f,0.0f,0.0f);
        glVertex2f(-0.5,-1);
        glVertex2f(0.5,-1);
        glEnd();

        glBegin(GL_LINES);
        glColor3f(0.0f,0.0f,0.0f);
        glVertex2f(-0.5,-0);
        glVertex2f(0.5,-0);
        glEnd();

        glBegin(GL_LINES);
        glColor3f(0.0f,0.0f,0.0f);
        glVertex2f(-0.5,1);
        glVertex2f(0.5,1);
        glEnd();

        glBegin(GL_LINES);
        glColor3f(0.0f,0.0f,0.0f);
        glVertex2f(-0.5,2);
        glVertex2f(0.5,2);
        glEnd();
        glPopMatrix();
        //------------end of woodenhouse----------
        //...........................................................................
        //.......................2nd house
          glPushMatrix();
        glScaled(1,0.5,0);
        glTranslated(1,9,0);

        glPushMatrix();
        glTranslated(0,-9,0);
        glBegin(GL_POLYGON);

        glColor3f(0.82,0.82,0.82);
        glVertex2d(2,0);
        glVertex2d(-2,0);
        glVertex2d(-2,10);
        glVertex2d(2,10);

        glEnd();
        glPopMatrix();





        //------top triangle-------
        glPushMatrix();
        glTranslated(0,1,0);
        glBegin(GL_TRIANGLES);

        glColor3f(1,0.64,0);
        glVertex2d(2,0);
        glVertex2d(-2,0);
        glVertex2d(0,3);


        glEnd();
        glPopMatrix();


        //------middle white line-------
        glPushMatrix();
        glTranslated(0,0.5,0);
        glBegin(GL_POLYGON);

        glColor3f(1,1,1);
        glVertex2d(2,0);
        glVertex2d(-2,0);
        glVertex2d(-2,.5);
        glVertex2d(2,.5);

        glEnd();
        glPopMatrix();

        //------middle white line 2-------
        glPushMatrix();
        glTranslated(0,-5,0);
        glBegin(GL_POLYGON);

        glColor3f(1,1,1);
        glVertex2d(2,0);
        glVertex2d(-2,0);
        glVertex2d(-2,.25);
        glVertex2d(2,.25);

        glEnd();
        glPopMatrix();



        //------top janalas-------
        glPushMatrix();
        glTranslated(-1.30,-3.5,0);
        glBegin(GL_POLYGON);

        glColor3f(0.54,0.27,0.07);
        glVertex2d(.40,0);
        glVertex2d(-.40,0);
        glVertex2d(-.40,3.5);
        glVertex2d(.40,3.5);

        glEnd();
        glPopMatrix();


        //------top janalas-------
        glPushMatrix();
        glTranslated(1.30,-3.5,0);
        glBegin(GL_POLYGON);

        glColor3f(0.54,0.27,0.07);
        glVertex2d(.40,0);
        glVertex2d(-.40,0);
        glVertex2d(-.40,3.5);
        glVertex2d(.40,3.5);

        glEnd();
        glPopMatrix();

        //------top janalas-------
        glPushMatrix();
        glTranslated(0,-3.5,0);
        glBegin(GL_POLYGON);

        glColor3f(0.54,0.27,0.07);
        glVertex2d(.40,0);
        glVertex2d(-.40,0);
        glVertex2d(-.40,3.5);
        glVertex2d(.40,3.5);

        glEnd();
        glPopMatrix();



        //down janalas
        glPushMatrix();
        glTranslated(0,-4,0);


        glPushMatrix();
        glTranslated(-1.30,-4.5,0);
        glBegin(GL_POLYGON);

        glColor3f(0.54,0.27,0.07);
        glVertex2d(.40,0);
        glVertex2d(-.40,0);
        glVertex2d(-.40,3);
        glVertex2d(.40,3);

        glEnd();
        glPopMatrix();


        //------down janalas-------
        glPushMatrix();
        glTranslated(1.30,-4.5,0);
        glBegin(GL_POLYGON);

        glColor3f(0.54,0.27,0.07);
        glVertex2d(.40,0);
        glVertex2d(-.40,0);
        glVertex2d(-.40,3);
        glVertex2d(.40,3);

        glEnd();
        glPopMatrix();

        //------down janalas-------
        glPushMatrix();
        glTranslated(0,-4.5,0);
        glBegin(GL_POLYGON);

        glColor3f(0.54,0.27,0.07);
        glVertex2d(.40,0);
        glVertex2d(-.40,0);
        glVertex2d(-.40,3);
        glVertex2d(.40,3);

        glEnd();
        glPopMatrix();
        glPopMatrix();



        glPopMatrix();
        glPopMatrix();
        //------2nd building End-----------*/
        //-------------------------x-mas tree
        glPushMatrix();
        glTranslated(-11,1.46,0);
        glScaled(0.4,0.4,1.5);



        glPushMatrix();
        glTranslated(4,3.2,0);
        glColor3f(0,0.39,0);

        glBegin(GL_TRIANGLES);

        glVertex2d(1,0);
        glVertex2d(2,0);
        glVertex2d(1.5,1.5);

        glEnd();

        glPopMatrix();


        glPushMatrix();
        glTranslated(4,2,0);
        glColor3f(0,0.39,0);

        glBegin(GL_TRIANGLES);

        glVertex2d(0,0);
        glVertex2d(3,0);
        glVertex2d(1.5,1.5);

        glEnd();

        glPopMatrix();


        glPushMatrix();
        glTranslated(4.5,1.4,0);
        glColor3f(0,0.39,0);

        glBegin(GL_TRIANGLES);

        glVertex2d(-1,0);
        glVertex2d(3,0);
        glVertex2d(1,1);

        glEnd();

        glPopMatrix();

//..................................guri
        glPushMatrix();
        glTranslated(5.4,-3.6,0);
        glColor3f(0.54,0.27,0.07);

        glBegin(GL_POLYGON);

        glVertex2d(0,0);
        glVertex2d(0.3,0);
        glVertex2d(0.3,5);
        glVertex2d(0,5);

        glEnd();

        glPopMatrix();

 glEnd();

        glPopMatrix();

        //------Building-------
        glPushMatrix();
        glScaled(0.6,0.5,0);
        glTranslated(14,9,0);

        glPushMatrix();
        glTranslated(0,-9,0);
        glBegin(GL_POLYGON);

        glColor3f(0.63,0.32,0.18);
        glVertex2d(2,0);
        glVertex2d(-2,0);
        glVertex2d(-2,10);
        glVertex2d(2,10);

        glEnd();
        glPopMatrix();


        //------top one-------
        glPushMatrix();
        glTranslated(0,1,0);
        glBegin(GL_POLYGON);

        glColor3f(0.80,0.52,0.25);
        glVertex2d(1,0);
        glVertex2d(-1,0);
        glVertex2d(-1,4);
        glVertex2d(1,4);

        glEnd();
        glPopMatrix();


        //------top triangle-------
        glPushMatrix();
        glTranslated(0,5,0);
        glBegin(GL_TRIANGLES);

        glColor3f(0.96,0.64,0.38);
        glVertex2d(1,0);
        glVertex2d(-1,0);
        glVertex2d(0,3);


        glEnd();
        glPopMatrix();



        //right tomb
        glPushMatrix();
        glTranslated(-2.25,4,0);
        //------side building 1-------
        glPushMatrix();
        glTranslated(4,-3,0);
        glBegin(GL_POLYGON);

        glColor3f(0.80,0.52,0.25);
        glVertex2d(.25,0);
        glVertex2d(-.25,0);
        glVertex2d(-.25,4);
        glVertex2d(.25,4);

        glEnd();
        glPopMatrix();


        //------small triangle-------
        glPushMatrix();
        glTranslated(4,1,0);
        glBegin(GL_TRIANGLES);

        glColor3f(0.96,0.64,0.38);
        glVertex2d(.25,0);
        glVertex2d(-.25,0);
        glVertex2d(0,2.5);


        glEnd();
        glPopMatrix();

        glPopMatrix();


        //left tomb
        glPushMatrix();
        glTranslated(-5.75,4,0);
        //------side building 2-------
        glPushMatrix();
        glTranslated(4,-3,0);
        glBegin(GL_POLYGON);

        glColor3f(0.80,0.52,0.25);
        glVertex2d(.25,0);
        glVertex2d(-.25,0);
        glVertex2d(-.25,4);
        glVertex2d(.25,4);

        glEnd();
        glPopMatrix();


        //------small triangle-------
        glPushMatrix();
        glTranslated(4,1,0);
        glBegin(GL_TRIANGLES);

        glColor3f(0.96,0.64,0.38);
        glVertex2d(.25,0);
        glVertex2d(-.25,0);
        glVertex2d(0,2.5);


        glEnd();
        glPopMatrix();
        glPopMatrix();


        //circle line
        glPushMatrix();
        glTranslated(0,3.5,0);

        glColor3f(0,0,0);
        CircleL(0.77,1.27);

        glPopMatrix();
        glEnd();

        //circle polygon
        glPushMatrix();
        glTranslated(0,3.5,0);

        glPushMatrix();
        glTranslated(0,0,0);

        glColor3f(1,1,1);
        CircleP(0.75,1.25);

        glPopMatrix();
        glEnd();

        //------ghorir choto kata-------
        glPushMatrix();
        glTranslated(0,0,0);
        glBegin(GL_LINES);

        glColor3f(0,0,0);
        glVertex2d(0,-.12);
        glVertex2d(0,.75);

        glEnd();
        glPopMatrix();

        //------ghorir boro kata-------
        glPushMatrix();
        glTranslated(0,0,0);
        glBegin(GL_LINES);

        glColor3f(0,0,0);
        glVertex2d(-.12,0);
        glVertex2d(.5,.12);

        glEnd();
        glPopMatrix();


        //------middle white line-------
        glPushMatrix();
        glTranslated(0,-3,0);
        glBegin(GL_POLYGON);

        glColor3f(1,1,1);
        glVertex2d(2,0);
        glVertex2d(-2,0);
        glVertex2d(-2,.5);
        glVertex2d(2,.5);

        glEnd();
        glPopMatrix();

        //------middle white line 2-------
        glPushMatrix();
        glTranslated(0,-8,0);
        glBegin(GL_POLYGON);

        glColor3f(1,1,1);
        glVertex2d(2,0);
        glVertex2d(-2,0);
        glVertex2d(-2,.25);
        glVertex2d(2,.25);

        glEnd();
        glPopMatrix();



        //------top janalas-------
        glPushMatrix();
        glTranslated(-1.30,-7,0);
        glBegin(GL_POLYGON);

        glColor3f(0.96,0.64,0.38);
        glVertex2d(.40,0);
        glVertex2d(-.40,0);
        glVertex2d(-.40,3.5);
        glVertex2d(.40,3.5);

        glEnd();
        glPopMatrix();


        //------top janalas-------
        glPushMatrix();
        glTranslated(1.30,-7,0);
        glBegin(GL_POLYGON);

        glColor3f(0.96,0.64,0.38);
        glVertex2d(.40,0);
        glVertex2d(-.40,0);
        glVertex2d(-.40,3.5);
        glVertex2d(.40,3.5);

        glEnd();
        glPopMatrix();

        //------top janalas-------
        glPushMatrix();
        glTranslated(0,-7,0);
        glBegin(GL_POLYGON);

        glColor3f(0.96,0.64,0.38);
        glVertex2d(.40,0);
        glVertex2d(-.40,0);
        glVertex2d(-.40,3.5);
        glVertex2d(.40,3.5);

        glEnd();
        glPopMatrix();



        //down janalas
        glPushMatrix();
        glTranslated(0,-5,0);


        glPushMatrix();
        glTranslated(-1.30,-7,0);
        glBegin(GL_POLYGON);

        glColor3f(0.96,0.64,0.38);
        glVertex2d(.40,0);
        glVertex2d(-.40,0);
        glVertex2d(-.40,3.5);
        glVertex2d(.40,3.5);

        glEnd();
        glPopMatrix();


        //------down janalas-------
        glPushMatrix();
        glTranslated(1.30,-7,0);
        glBegin(GL_POLYGON);

        glColor3f(0.96,0.64,0.38);
        glVertex2d(.40,0);
        glVertex2d(-.40,0);
        glVertex2d(-.40,3.5);
        glVertex2d(.40,3.5);

        glEnd();
        glPopMatrix();

        //------down janalas-------
        glPushMatrix();
        glTranslated(0,-7,0);
        glBegin(GL_POLYGON);

        glColor3f(0.96,0.64,0.38);
        glVertex2d(.40,0);
        glVertex2d(-.40,0);
        glVertex2d(-.40,3.5);
        glVertex2d(.40,3.5);

        glEnd();
        glPopMatrix();
        glPopMatrix();


        //white inside tomb
        glPushMatrix();
        glTranslated(-1.75,-2.25,0);
        glBegin(GL_POLYGON);

        glColor3f(1,1,1);
        glVertex2d(.15,0);
        glVertex2d(-.15,0);
        glVertex2d(-.15,3.5);
        glVertex2d(.15,3.5);

        glEnd();
        glPopMatrix();

        //white inside tomb
        glPushMatrix();
        glTranslated(1.75,-2.25,0);
        glBegin(GL_POLYGON);

        glColor3f(1,1,1);
        glVertex2d(.15,0);
        glVertex2d(-.15,0);
        glVertex2d(-.15,3.5);
        glVertex2d(.15,3.5);

        glEnd();
        glPopMatrix();
        glPopMatrix();
        glPopMatrix();
        //------building End-----------*/
        //-------------------------x-mas tree
        glPushMatrix();
        glTranslated(-11,1.46,0);
        glScaled(0.4,0.4,1.5);



        glPushMatrix();
        glTranslated(4,3.2,0);
        glColor3f(0,0.39,0);

        glBegin(GL_TRIANGLES);

        glVertex2d(1,0);
        glVertex2d(2,0);
        glVertex2d(1.5,1.5);

        glEnd();

        glPopMatrix();


        glPushMatrix();
        glTranslated(4,2,0);
        glColor3f(0,0.39,0);

        glBegin(GL_TRIANGLES);

        glVertex2d(0,0);
        glVertex2d(3,0);
        glVertex2d(1.5,1.5);

        glEnd();

        glPopMatrix();


        glPushMatrix();
        glTranslated(4.5,1.4,0);
        glColor3f(0,0.39,0);

        glBegin(GL_TRIANGLES);

        glVertex2d(-1,0);
        glVertex2d(3,0);
        glVertex2d(1,1);

        glEnd();

        glPopMatrix();

//..................................guri
        glPushMatrix();
        glTranslated(5.4,-3.6,0);
        glColor3f(0.54,0.27,0.07);

        glBegin(GL_POLYGON);

        glVertex2d(0,0);
        glVertex2d(0.3,0);
        glVertex2d(0.3,5);
        glVertex2d(0,5);

        glEnd();

        glPopMatrix();

 glEnd();

        glPopMatrix();


//..............................................
 glPushMatrix();
        glTranslated(-4.4,1.46,0);
        glScaled(0.4,0.4,1.5);



        glPushMatrix();
        glTranslated(4,3.2,0);
        glColor3f(0,0.39,0);

        glBegin(GL_TRIANGLES);

        glVertex2d(1,0);
        glVertex2d(2,0);
        glVertex2d(1.5,1.5);

        glEnd();

        glPopMatrix();


        glPushMatrix();
        glTranslated(4,2,0);
        glColor3f(0,0.39,0);

        glBegin(GL_TRIANGLES);

        glVertex2d(0,0);
        glVertex2d(3,0);
        glVertex2d(1.5,1.5);

        glEnd();

        glPopMatrix();


        glPushMatrix();
        glTranslated(4.5,1.4,0);
        glColor3f(0,0.39,0);

        glBegin(GL_TRIANGLES);

        glVertex2d(-1,0);
        glVertex2d(3,0);
        glVertex2d(1,1);

        glEnd();

        glPopMatrix();

//..................................guri
        glPushMatrix();
        glTranslated(5.4,-3.6,0);
        glColor3f(0.54,0.27,0.07);

        glBegin(GL_POLYGON);

        glVertex2d(0,0);
        glVertex2d(0.3,0);
        glVertex2d(0.3,5);
        glVertex2d(0,5);

        glEnd();

        glPopMatrix();

 glEnd();

        glPopMatrix();
        //...................................
         glPushMatrix();
        glTranslated(1.6,1.46,0);
        glScaled(0.4,0.4,1.5);



        glPushMatrix();
        glTranslated(4,3.2,0);
        glColor3f(0,0.39,0);

        glBegin(GL_TRIANGLES);

        glVertex2d(1,0);
        glVertex2d(2,0);
        glVertex2d(1.5,1.5);

        glEnd();

        glPopMatrix();


        glPushMatrix();
        glTranslated(4,2,0);
        glColor3f(0,0.39,0);

        glBegin(GL_TRIANGLES);

        glVertex2d(0,0);
        glVertex2d(3,0);
        glVertex2d(1.5,1.5);

        glEnd();

        glPopMatrix();


        glPushMatrix();
        glTranslated(4.5,1.4,0);
        glColor3f(0,0.39,0);

        glBegin(GL_TRIANGLES);

        glVertex2d(-1,0);
        glVertex2d(3,0);
        glVertex2d(1,1);

        glEnd();

        glPopMatrix();

//..................................guri
        glPushMatrix();
        glTranslated(5.4,-3.6,0);
        glColor3f(0.54,0.27,0.07);

        glBegin(GL_POLYGON);

        glVertex2d(0,0);
        glVertex2d(0.3,0);
        glVertex2d(0.3,5);
        glVertex2d(0,5);

        glEnd();

        glPopMatrix();

 glEnd();

        glPopMatrix();
        //.................................
         glPushMatrix();
        glTranslated(3.6,1.46,0);
        glScaled(0.4,0.4,1.5);



        glPushMatrix();
        glTranslated(4,3.2,0);
        glColor3f(0,0.39,0);

        glBegin(GL_TRIANGLES);

        glVertex2d(1,0);
        glVertex2d(2,0);
        glVertex2d(1.5,1.5);

        glEnd();

        glPopMatrix();


        glPushMatrix();
        glTranslated(4,2,0);
        glColor3f(0,0.39,0);

        glBegin(GL_TRIANGLES);

        glVertex2d(0,0);
        glVertex2d(3,0);
        glVertex2d(1.5,1.5);

        glEnd();

        glPopMatrix();


        glPushMatrix();
        glTranslated(4.5,1.4,0);
        glColor3f(0,0.39,0);

        glBegin(GL_TRIANGLES);

        glVertex2d(-1,0);
        glVertex2d(3,0);
        glVertex2d(1,1);

        glEnd();

        glPopMatrix();

//..................................guri
        glPushMatrix();
        glTranslated(5.4,-3.6,0);
        glColor3f(0.54,0.27,0.07);

        glBegin(GL_POLYGON);

        glVertex2d(0,0);
        glVertex2d(0.3,0);
        glVertex2d(0.3,5);
        glVertex2d(0,5);

        glEnd();

        glPopMatrix();

 glEnd();

        glPopMatrix();



        //....................................................................
        //tree
        //treeroot
        glPushMatrix();
        glTranslated(-3.5,5,0);
         glScaled(1.6,0.8,1);



        glPushMatrix();
        glTranslated(0,-4,0);

        glPushMatrix();
        glTranslated(0,-4,0);
        glBegin(GL_POLYGON);

        glColor3f(0.627,0.321,0.176);
        glVertex2d(0,7);
        glVertex2d(-.25,7);
        glVertex2d(-.25,0);
        glVertex2d(0,0);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslated(-0.125,-4,0);
        glBegin(GL_POLYGON);

        glColor3f(0.627,0.321,0.176);
        glVertex2d(0.25,0);
        glVertex2d(-0.25,0);
        glVertex2d(-0.125,0.5);
        glVertex2d(0.125,0.5);
        glEnd();
        glPopMatrix();

        glPopMatrix();

        //rightslopes
        glPushMatrix();
        glTranslated(0,-2,0);
        glBegin(GL_POLYGON);

        glColor3f(0.627,0.321,0.176);
        glVertex2d(0,0);
        glVertex2d(.5,1);
        glVertex2d(.5,1.5);
        glVertex2d(0,0.5);
        glEnd();
        glPopMatrix();

        //leftslopes
        glPushMatrix();
        glTranslated(-0.125,-2.5,0);
        glBegin(GL_POLYGON);

        glColor3f(0.627,0.321,0.176);
        glVertex2d(0,0);
        glVertex2d(-.5,1);
        glVertex2d(-.5,1.5);
        glVertex2d(0,0.5);
        glEnd();
        glPopMatrix();


        //circles
        glPushMatrix();
        glTranslated(-0.125,0,0);
        glColor3f(0.133,0.545,0.133);
        CircleP(1,2);
        glPopMatrix();
        glEnd();

        //circles
        glPushMatrix();
        glTranslated(-0.5,-2,0);
        glColor3f(0.133,0.545,0.133);
        CircleP(.25,1);
        glPopMatrix();
        glEnd();
        glPushMatrix();
        glTranslated(-0.5,-2,0);
        glColor3f(0,0,0);
        CircleL(.25,1);
        glPopMatrix();
        glEnd();

        //circles
        glPushMatrix();
        glTranslated(-0.90,-1.50,0);
        glColor3f(0.133,0.545,0.133);
        CircleP(0.25,1);
        glPopMatrix();
        glEnd();
        glPushMatrix();
        glTranslated(-0.90,-1.50,0);
        glColor3f(0,0,0);
        CircleL(0.25,1);
        glPopMatrix();
        glEnd();

        //circles
        glPushMatrix();
        glTranslated(-1.25,-0.5,0);
        glColor3f(0.133,0.545,0.133);
        CircleP(0.25,1);
        glPopMatrix();
        glEnd();
        glPushMatrix();
        glTranslated(-1.25,-0.5,0);
        glColor3f(0,0,0);
        CircleL(0.25,1);
        glPopMatrix();
        glEnd();

        //circles
        glPushMatrix();
        glTranslated(-1.10,1.10,0);
        glColor3f(0.133,0.545,0.133);
        CircleP(0.5,1);
        glPopMatrix();
        glEnd();
        glPushMatrix();
        glTranslated(-1.10,1.10,0);
        glColor3f(0,0,0);
        CircleL(0.5,1);
        glPopMatrix();
        glEnd();

        //circles
        glPushMatrix();
        glTranslated(-.90,2,0);
        glColor3f(0.133,0.545,0.133);
        CircleP(0.25,1);
        glPopMatrix();
        glEnd();
        glPushMatrix();
        glTranslated(-.90,2,0);
        glColor3f(0,0,0);
        CircleL(0.25,1);
        glPopMatrix();
        glEnd();

        //circles
        glPushMatrix();
        glTranslated(-.5,2.5,0);
        glColor3f(0.133,0.545,0.133);
        CircleP(0.25,1);
        glPopMatrix();
        glEnd();
        glPushMatrix();
        glTranslated(-.5,2.5,0);
        glColor3f(0,0,0);
        CircleL(0.25,1);
        glPopMatrix();
        glEnd();

        //circles
        glPushMatrix();
        glTranslated(-.125,2.75,0);
        glColor3f(0.133,0.545,0.133);
        CircleP(0.25,1);
        glPopMatrix();
        glEnd();
        glPushMatrix();
        glTranslated(-.125,2.75,0);
        glColor3f(0,0,0);
        CircleL(0.25,1);
        glPopMatrix();
        glEnd();

        //circles
        glPushMatrix();
        glTranslated(0.25,2.5,0);
        glColor3f(0.133,0.545,0.133);
        CircleP(0.255,1.5);
        glPopMatrix();
        glEnd();
        glPushMatrix();
        glTranslated(0.25,2.5,0);
        glColor3f(0,0,0);
        CircleL(0.255,1.5);
        glPopMatrix();
        glEnd();

        //circles
        glPushMatrix();
        glTranslated(0.65,2,0);
        glColor3f(0.133,0.545,0.133);
        CircleP(0.25,1);
        glPopMatrix();
        glEnd();
        glPushMatrix();
        glTranslated(0.65,2,0);
        glColor3f(0,0,0);
        CircleL(0.25,1);
        glPopMatrix();
        glEnd();

        //circles
        glPushMatrix();
        glTranslated(.90,1.25,0);
        glColor3f(0.133,0.545,0.133);
        CircleP(0.25,1);
        glPopMatrix();
        glEnd();
        glPushMatrix();
        glTranslated(.90,1.25,0);
        glColor3f(0,0,0);
        CircleL(0.25,1);
        glPopMatrix();
        glEnd();

        //circles
        glPushMatrix();
        glTranslated(1,0,0);
        glColor3f(0.133,0.545,0.133);
        CircleP(0.25,1);
        glPopMatrix();
        glEnd();
        glPushMatrix();
        glTranslated(1,0,0);
        glColor3f(0,0,0);
        CircleL(0.25,1);
        glPopMatrix();
        glEnd();

        //circles
        glPushMatrix();
        glTranslated(0.75,-1,0);
        glColor3f(0.133,0.545,0.133);
        CircleP(0.25,1);
        glPopMatrix();
        glEnd();
        glPushMatrix();
        glTranslated(0.75,-1,0);
        glColor3f(0,0,0);
        CircleL(0.25,1);
        glPopMatrix();
        glEnd();

        //circles
        glPushMatrix();
        glTranslated(0.5,-2,0);
        glColor3f(0.133,0.545,0.133);
        CircleP(0.25,1);
        glPopMatrix();
        glEnd();
        glPushMatrix();
        glTranslated(0.5,-2,0);
        glColor3f(0,0,0);
        CircleL(0.25,1);
        glPopMatrix();
        glEnd();

        //circles
        glPushMatrix();
        glTranslated(0.25,-2,0);
        glColor3f(0.133,0.545,0.133);
        CircleP(0.25,1);
        glPopMatrix();
        glEnd();
        glPushMatrix();
        glTranslated(0.25,-2,0);
        glColor3f(0,0,0);
        CircleL(0.25,1);
        glPopMatrix();
        glEnd();

        //circles
        glPushMatrix();
        glTranslated(-0.125,0,0);
        glColor3f(0.133,0.545,0.133);
        CircleP(1.20,2.20);
        glPopMatrix();
        glEnd();


        //rightslopes
        glPushMatrix();
        glTranslated(0,-3.5,0);
        glBegin(GL_POLYGON);

        glColor3f(0.627,0.321,0.176);
        glVertex2d(0,0);
        glVertex2d(.25,1);
        glVertex2d(.25,1.5);
        glVertex2d(0,0.5);
        glEnd();
        glPopMatrix();


        //leftslopes
        glPushMatrix();
        glTranslated(-0.125,-3.5,0);
        glBegin(GL_POLYGON);

        glColor3f(0.627,0.321,0.176);
        glVertex2d(0,0);
        glVertex2d(-.35,1);
        glVertex2d(-.35,1.5);
        glVertex2d(0,0.5);
        glEnd();
        glPopMatrix();
        glPopMatrix();
//................................................................
//...........................................................bench
         glPushMatrix();
        glTranslated(-8.5,-1.5,0);
        glScaled(0.8,0.5,1);

//.......................................body background
  glPushMatrix();
        glTranslated(1,0,0);
        glColor3f(1,1,1);

        glBegin(GL_POLYGON);
        glVertex2d(2,1.2);
        glVertex2d(1,0.1);
        glVertex2d(1,0);

        glVertex2d(5.5,0);
        glVertex2d(4.5,1.2);

        glEnd();

        glPopMatrix();

//................................................border
         glPushMatrix();
        glTranslated(2,-0.5,0);
        glColor3f(0.6,0.3,0.3);
        glScaled(1,1,1);


        glBegin(GL_POLYGON);
        glVertex2d(0,0);
        glVertex2d(4.47,0);
        glVertex2d(4.47,0.5);
        glVertex2d(0,0.5);


        glEnd();

        glPopMatrix();
        //..............................line

         glPushMatrix();
        glTranslated(2.53,0.68,0);
        glColor3f(0.6,0.3,0.3);
        glScaled(0.75,0.1,1);


        glBegin(GL_POLYGON);
        glVertex2d(0,0);
        glVertex2d(4.47,0);
        glVertex2d(4.47,0.5);
        glVertex2d(0,0.5);


        glEnd();

        glPopMatrix();
        //................................................back
        //................................lomba1

        glPushMatrix();
        glTranslated(3,1.2,0);
        glColor3f(0.6,0.3,0.3);
        glScaled(0.05,5,1);


        glBegin(GL_POLYGON);
        glVertex2d(0,0);
        glVertex2d(4.47,0);
        glVertex2d(4.47,0.5);
        glVertex2d(0,0.5);


        glEnd();

        glPopMatrix();

//.......................................................lomba2
         glPushMatrix();
        glTranslated(5.22,1.2,0);
        glColor3f(0.6,0.3,0.3);
        glScaled(0.05,5,1);


        glBegin(GL_POLYGON);
        glVertex2d(0,0);
        glVertex2d(4.47,0);
        glVertex2d(4.47,0.5);
        glVertex2d(0,0.5);


        glEnd();

        glPopMatrix();
        //........................................width
         glPushMatrix();
        glTranslated(2.7,3,0);
        glColor3f(0.6,0.3,0.3);
        glScaled(0.67,1,1);


        glBegin(GL_POLYGON);
        glVertex2d(0,0);
        glVertex2d(4.47,0);
        glVertex2d(4.47,0.5);
        glVertex2d(0,0.5);


        glEnd();

        glPopMatrix();



        //...............................
         //........................................width2nd
         glPushMatrix();
        glTranslated(2.7,1.8,0);
        glColor3f(0.6,0.3,0.3);
        glScaled(0.67,1,1);


        glBegin(GL_POLYGON);
        glVertex2d(0,0);
        glVertex2d(4.47,0);
        glVertex2d(4.47,0.5);
        glVertex2d(0,0.5);


        glEnd();

        glPopMatrix();



        //...............................pa
        //...........................................1st
        glPushMatrix();
        glTranslated(2.2,-2,0);
        glColor3f(0.6,0.3,0.3);
        glScaled(0.05,4,1);


        glBegin(GL_POLYGON);
        glVertex2d(0,0);
        glVertex2d(4.47,0);
        glVertex2d(4.47,0.5);
        glVertex2d(0,0.5);


        glEnd();

        glPopMatrix();


        //..........................2nd pa
        glPushMatrix();
        glTranslated(6,-2,0);
        glColor3f(0.6,0.3,0.3);
        glScaled(0.05,4,1);


        glBegin(GL_POLYGON);
        glVertex2d(0,0);
        glVertex2d(4.47,0);
        glVertex2d(4.47,0.5);
        glVertex2d(0,0.5);


        glEnd();

        glPopMatrix();


        //..........................


          glEnd();

        glPopMatrix();

//...........................................................bench
         glPushMatrix();
        glTranslated(1.2,-1.5,0);
        glScaled(0.8,0.5,1);

//.......................................body background
  glPushMatrix();
        glTranslated(1,0,0);
        glColor3f(1,1,1);

        glBegin(GL_POLYGON);
        glVertex2d(2,1.2);
        glVertex2d(1,0.1);
        glVertex2d(1,0);

        glVertex2d(5.5,0);
        glVertex2d(4.5,1.2);

        glEnd();

        glPopMatrix();

//................................................border
         glPushMatrix();
        glTranslated(2,-0.5,0);
        glColor3f(0.6,0.3,0.3);
        glScaled(1,1,1);


        glBegin(GL_POLYGON);
        glVertex2d(0,0);
        glVertex2d(4.47,0);
        glVertex2d(4.47,0.5);
        glVertex2d(0,0.5);


        glEnd();

        glPopMatrix();
        //..............................line

         glPushMatrix();
        glTranslated(2.53,0.68,0);
        glColor3f(0.6,0.3,0.3);
        glScaled(0.75,0.1,1);


        glBegin(GL_POLYGON);
        glVertex2d(0,0);
        glVertex2d(4.47,0);
        glVertex2d(4.47,0.5);
        glVertex2d(0,0.5);


        glEnd();

        glPopMatrix();
        //................................................back
        //................................lomba1

        glPushMatrix();
        glTranslated(3,1.2,0);
        glColor3f(0.6,0.3,0.3);
        glScaled(0.05,5,1);


        glBegin(GL_POLYGON);
        glVertex2d(0,0);
        glVertex2d(4.47,0);
        glVertex2d(4.47,0.5);
        glVertex2d(0,0.5);


        glEnd();

        glPopMatrix();

//.......................................................lomba2
         glPushMatrix();
        glTranslated(5.22,1.2,0);
        glColor3f(0.6,0.3,0.3);
        glScaled(0.05,5,1);


        glBegin(GL_POLYGON);
        glVertex2d(0,0);
        glVertex2d(4.47,0);
        glVertex2d(4.47,0.5);
        glVertex2d(0,0.5);


        glEnd();

        glPopMatrix();
        //........................................width
         glPushMatrix();
        glTranslated(2.7,3,0);
        glColor3f(0.6,0.3,0.3);
        glScaled(0.67,1,1);


        glBegin(GL_POLYGON);
        glVertex2d(0,0);
        glVertex2d(4.47,0);
        glVertex2d(4.47,0.5);
        glVertex2d(0,0.5);


        glEnd();

        glPopMatrix();



        //...............................
         //........................................width2nd
         glPushMatrix();
        glTranslated(2.7,1.8,0);
        glColor3f(0.6,0.3,0.3);
        glScaled(0.67,1,1);


        glBegin(GL_POLYGON);
        glVertex2d(0,0);
        glVertex2d(4.47,0);
        glVertex2d(4.47,0.5);
        glVertex2d(0,0.5);


        glEnd();

        glPopMatrix();



        //...............................pa
        //...........................................1st
        glPushMatrix();
        glTranslated(2.2,-2,0);
        glColor3f(0.6,0.3,0.3);
        glScaled(0.05,4,1);


        glBegin(GL_POLYGON);
        glVertex2d(0,0);
        glVertex2d(4.47,0);
        glVertex2d(4.47,0.5);
        glVertex2d(0,0.5);


        glEnd();

        glPopMatrix();


        //..........................2nd pa
        glPushMatrix();
        glTranslated(6,-2,0);
        glColor3f(0.6,0.3,0.3);
        glScaled(0.05,4,1);


        glBegin(GL_POLYGON);
        glVertex2d(0,0);
        glVertex2d(4.47,0);
        glVertex2d(4.47,0.5);
        glVertex2d(0,0.5);


        glEnd();

        glPopMatrix();


        //..........................


          glEnd();

        glPopMatrix();

glPopMatrix();
        //.....................................grass
          glPushMatrix();
        glTranslated(-1,-3.6,0);
        glScaled(0.1,0.3,1);

//.......................................body background
  glPushMatrix();
        glTranslated(-6.5,0,0);
        glColor3f(0.4,0.5,0.1);

        glBegin(GL_POLYGON);
        glVertex2d(1,0);
        glVertex2d(2,0);
        glVertex2d(1.5,1.2);



        glEnd();

        glPopMatrix();
        glPushMatrix();
        glTranslated(-6,0,0);
        glColor3f(0.4,0.5,0.1);

        glBegin(GL_POLYGON);
        glVertex2d(1,0);
        glVertex2d(2,0);
        glVertex2d(1.5,2);



        glEnd();


        glPopMatrix();
        glPushMatrix();
        glTranslated(-5.5,0,0);
        glColor3f(0.4,0.5,0.1);

        glBegin(GL_POLYGON);
        glVertex2d(1,0);
        glVertex2d(2,0);
        glVertex2d(1.5,1.5);

        glEnd();

        glPopMatrix();
         glEnd();

        glPopMatrix();


        //.....................................grass
          glPushMatrix();
        glTranslated(-6,-3.6,0);
        glScaled(0.1,0.3,1);

//.......................................body background
  glPushMatrix();
        glTranslated(-6.5,0,0);
        glColor3f(0.4,0.5,0.1);

        glBegin(GL_POLYGON);
        glVertex2d(1,0);
        glVertex2d(2,0);
        glVertex2d(1.5,1.2);



        glEnd();

        glPopMatrix();
        glPushMatrix();
        glTranslated(-6,0,0);
        glColor3f(0.4,0.5,0.1);

        glBegin(GL_POLYGON);
        glVertex2d(1,0);
        glVertex2d(2,0);
        glVertex2d(1.5,2);



        glEnd();


        glPopMatrix();
        glPushMatrix();
        glTranslated(-5.5,0,0);
        glColor3f(0.4,0.5,0.1);

        glBegin(GL_POLYGON);
        glVertex2d(1,0);
        glVertex2d(2,0);
        glVertex2d(1.5,1.5);



        glEnd();

        glPopMatrix();
         glEnd();

        glPopMatrix();

        //.....................................grass
          glPushMatrix();
        glTranslated(2,-3.6,0);
        glScaled(0.1,0.3,1);

//.......................................body background
  glPushMatrix();
        glTranslated(-6.5,0,0);
        glColor3f(0.4,0.5,0.1);

        glBegin(GL_POLYGON);
        glVertex2d(1,0);
        glVertex2d(2,0);
        glVertex2d(1.5,1.2);



        glEnd();

        glPopMatrix();
        glPushMatrix();
        glTranslated(-6,0,0);
        glColor3f(0.4,0.5,0.1);

        glBegin(GL_POLYGON);
        glVertex2d(1,0);
        glVertex2d(2,0);
        glVertex2d(1.5,2);



        glEnd();


        glPopMatrix();
        glPushMatrix();
        glTranslated(-5.5,0,0);
        glColor3f(0.4,0.5,0.1);

        glBegin(GL_POLYGON);
        glVertex2d(1,0);
        glVertex2d(2,0);
        glVertex2d(1.5,1.5);



        glEnd();

        glPopMatrix();
         glEnd();

        glPopMatrix();


//.....................................grass
          glPushMatrix();
        glTranslated(5,-3.6,0);
        glScaled(0.1,0.3,1);

//.......................................body background
  glPushMatrix();
        glTranslated(-6.5,0,0);
        glColor3f(0.4,0.5,0.1);

        glBegin(GL_POLYGON);
        glVertex2d(1,0);
        glVertex2d(2,0);
        glVertex2d(1.5,1.2);



        glEnd();

        glPopMatrix();
        glPushMatrix();
        glTranslated(-6,0,0);
        glColor3f(0.4,0.5,0.1);

        glBegin(GL_POLYGON);
        glVertex2d(1,0);
        glVertex2d(2,0);
        glVertex2d(1.5,2);



        glEnd();


        glPopMatrix();
        glPushMatrix();
        glTranslated(-5.5,0,0);
        glColor3f(0.4,0.5,0.1);

        glBegin(GL_POLYGON);
        glVertex2d(1,0);
        glVertex2d(2,0);
        glVertex2d(1.5,1.5);



        glEnd();

        glPopMatrix();
         glEnd();

        glPopMatrix();


//.....................................grass
          glPushMatrix();
        glTranslated(9.5,-3.6,0);
        glScaled(0.1,0.3,1);

//.......................................body background
  glPushMatrix();
        glTranslated(-6.5,0,0);
        glColor3f(0.4,0.5,0.1);

        glBegin(GL_POLYGON);
        glVertex2d(1,0);
        glVertex2d(2,0);
        glVertex2d(1.5,1.2);



        glEnd();

        glPopMatrix();
        glPushMatrix();
        glTranslated(-6,0,0);
        glColor3f(0.4,0.5,0.1);

        glBegin(GL_POLYGON);
        glVertex2d(1,0);
        glVertex2d(2,0);
        glVertex2d(1.5,2);



        glEnd();


        glPopMatrix();
        glPushMatrix();
        glTranslated(-5.5,0,0);
        glColor3f(0.4,0.5,0.1);

        glBegin(GL_POLYGON);
        glVertex2d(1,0);
        glVertex2d(2,0);
        glVertex2d(1.5,1.5);



        glEnd();

        glPopMatrix();
         glEnd();

        glPopMatrix();


//......................................................................................
 //.................................................lamppost1
         glPushMatrix();
        glTranslated(-5,-4,0);
        glScaled(0.8,1,1);


         glPushMatrix();
        glTranslated(5.22,1.2,0);
        glColor3f(0,0,0);
        glScaled(0.02,2,1);


        glBegin(GL_POLYGON);
        glVertex2d(0,0);
        glVertex2d(4,0);
        glVertex2d(4,3);
        glVertex2d(0,3);


        glEnd();

        glPopMatrix();
        //........................................width
         glPushMatrix();
        glTranslated(4.5,6,0);
        glColor3f(0,0,0);
        glScaled(0.6,0.2,1);


        glBegin(GL_POLYGON);
        glVertex2d(0,0);
        glVertex2d(2.5,0);
        glVertex2d(2.5,0.5);
        glVertex2d(0,0.5);


        glEnd();

        glPopMatrix();
        //...........................................bulb holder1
         glPushMatrix();
        glTranslated(4,6,0);
        glColor3f(0,0,0);
        glScaled(0.3,0.3,1);


        glBegin(GL_POLYGON);
        glVertex2d(1,1);
        glVertex2d(2,0);
        glVertex2d(3,1);



        glEnd();

        glPopMatrix();

          //...........................................bulb holder2
         glPushMatrix();
        glTranslated(5.4,6,0);
        glColor3f(0,0,0);
        glScaled(0.3,0.3,1);


        glBegin(GL_POLYGON);
        glVertex2d(1,1);
        glVertex2d(2,0);
        glVertex2d(3,1);



        glEnd();

        glPopMatrix();

          //...........................................bulb holder3
         glPushMatrix();
        glTranslated(4.65,7,0);
        glColor3f(0,0,0);
        glScaled(0.3,0.3,1);


        glBegin(GL_POLYGON);
        glVertex2d(1,1);
        glVertex2d(2,0);
        glVertex2d(3,1);



        glEnd();

        glPopMatrix();
        //.....................................bulb1
        glPushMatrix();
        glTranslated(6,6.3,0);

        glColor3f(1,1,0);//.........front
        CircleC(0.3,1);
         //glEnd();

        glPopMatrix();
         //.....................................bulb2
        glPushMatrix();
        glTranslated(4.6,6.3,0);

        glColor3f(1,1,0);//.........front
        CircleC(0.3,1);
         //glEnd();

        glPopMatrix();
         //.....................................bulb3
        glPushMatrix();
        glTranslated(5.25,7.3,0);

        glColor3f(1,1,0);//.........front
        CircleC(0.3,1);
         //glEnd();

        glPopMatrix();
        //........................................stand
         glPushMatrix();
        glTranslated(4.9,1,0);
        glColor3f(0,0,0);
        glScaled(0.3,0.6,1);


        glBegin(GL_POLYGON);
        glVertex2d(0,0);
        glVertex2d(2.5,0);
        glVertex2d(2.5,0.5);
        glVertex2d(0,0.5);


        glEnd();

        glPopMatrix();
 //........................................stand2
         glPushMatrix();
        glTranslated(4.79,-0.2,0);
        glColor3f(0.5,0,0);
        glScaled(0.35,0.6,1);


        glBegin(GL_POLYGON);
        glVertex2d(0,0);
        glVertex2d(3,0);
        glVertex2d(3,2);
        glVertex2d(0,2);


        glEnd();

        glPopMatrix();





         glEnd();

        glPopMatrix();
//.................................................lamppost2
         glPushMatrix();
        glTranslated(-12,-4,0);
        glScaled(0.8,1,1);


         glPushMatrix();
        glTranslated(5.22,1.2,0);
        glColor3f(0,0,0);
        glScaled(0.02,2,1);


        glBegin(GL_POLYGON);
        glVertex2d(0,0);
        glVertex2d(4,0);
        glVertex2d(4,3);
        glVertex2d(0,3);


        glEnd();

        glPopMatrix();
        //........................................width
         glPushMatrix();
        glTranslated(4.5,6,0);
        glColor3f(0,0,0);
        glScaled(0.6,0.2,1);


        glBegin(GL_POLYGON);
        glVertex2d(0,0);
        glVertex2d(2.5,0);
        glVertex2d(2.5,0.5);
        glVertex2d(0,0.5);


        glEnd();

        glPopMatrix();
        //...........................................bulb holder1
         glPushMatrix();
        glTranslated(4,6,0);
        glColor3f(0,0,0);
        glScaled(0.3,0.3,1);


        glBegin(GL_POLYGON);
        glVertex2d(1,1);
        glVertex2d(2,0);
        glVertex2d(3,1);



        glEnd();

        glPopMatrix();

          //...........................................bulb holder2
         glPushMatrix();
        glTranslated(5.4,6,0);
        glColor3f(0,0,0);
        glScaled(0.3,0.3,1);


        glBegin(GL_POLYGON);
        glVertex2d(1,1);
        glVertex2d(2,0);
        glVertex2d(3,1);



        glEnd();

        glPopMatrix();

          //...........................................bulb holder3
         glPushMatrix();
        glTranslated(4.65,7,0);
        glColor3f(0,0,0);
        glScaled(0.3,0.3,1);


        glBegin(GL_POLYGON);
        glVertex2d(1,1);
        glVertex2d(2,0);
        glVertex2d(3,1);



        glEnd();

        glPopMatrix();
        //.....................................bulb1
        glPushMatrix();
        glTranslated(6,6.3,0);

        glColor3f(1,1,0);//.........front
        CircleC(0.3,1);
         //glEnd();

        glPopMatrix();
         //.....................................bulb2
        glPushMatrix();
        glTranslated(4.6,6.3,0);

        glColor3f(1,1,0);//.........front
        CircleC(0.3,1);
        // glEnd();

        glPopMatrix();
         //.....................................bulb3
        glPushMatrix();
        glTranslated(5.25,7.3,0);

        glColor3f(1,1,0);//.........front
        CircleC(0.3,1);
        // glEnd();

        glPopMatrix();
        //........................................stand
         glPushMatrix();
        glTranslated(4.9,1,0);
        glColor3f(0,0,0);
        glScaled(0.3,0.6,1);


        glBegin(GL_POLYGON);
        glVertex2d(0,0);
        glVertex2d(2.5,0);
        glVertex2d(2.5,0.5);
        glVertex2d(0,0.5);


        glEnd();

        glPopMatrix();
 //........................................stand2
         glPushMatrix();
        glTranslated(4.79,-0.2,0);
        glColor3f(0.5,0,0);
        glScaled(0.35,0.6,1);


        glBegin(GL_POLYGON);
        glVertex2d(0,0);
        glVertex2d(3,0);
        glVertex2d(3,2);
        glVertex2d(0,2);


        glEnd();

        glPopMatrix();





         //glEnd();

        glPopMatrix();

        //.................................................lamppost3
         glPushMatrix();
        glTranslated(5,-4,0);
        glScaled(0.8,1,1);


         glPushMatrix();
        glTranslated(5.22,1.2,0);
        glColor3f(0,0,0);
        glScaled(0.02,2,1);


        glBegin(GL_POLYGON);
        glVertex2d(0,0);
        glVertex2d(4,0);
        glVertex2d(4,3);
        glVertex2d(0,3);


        glEnd();

        glPopMatrix();
        //........................................width
         glPushMatrix();
        glTranslated(4.5,6,0);
        glColor3f(0,0,0);
        glScaled(0.6,0.2,1);


        glBegin(GL_POLYGON);
        glVertex2d(0,0);
        glVertex2d(2.5,0);
        glVertex2d(2.5,0.5);
        glVertex2d(0,0.5);


        glEnd();

        glPopMatrix();
        //...........................................bulb holder1
         glPushMatrix();
        glTranslated(4,6,0);
        glColor3f(0,0,0);
        glScaled(0.3,0.3,1);


        glBegin(GL_POLYGON);
        glVertex2d(1,1);
        glVertex2d(2,0);
        glVertex2d(3,1);



        glEnd();

        glPopMatrix();

          //...........................................bulb holder2
         glPushMatrix();
        glTranslated(5.4,6,0);
        glColor3f(0,0,0);
        glScaled(0.3,0.3,1);


        glBegin(GL_POLYGON);
        glVertex2d(1,1);
        glVertex2d(2,0);
        glVertex2d(3,1);



        glEnd();

        glPopMatrix();

          //...........................................bulb holder3
         glPushMatrix();
        glTranslated(4.65,7,0);
        glColor3f(0,0,0);
        glScaled(0.3,0.3,1);


        glBegin(GL_POLYGON);
        glVertex2d(1,1);
        glVertex2d(2,0);
        glVertex2d(3,1);



        glEnd();

        glPopMatrix();
        //.....................................bulb1
        glPushMatrix();
        glTranslated(6,6.3,0);

        glColor3f(1,1,0);//.........front
        CircleC(0.3,1);
         //glEnd();

        glPopMatrix();
         //.....................................bulb2
        glPushMatrix();
        glTranslated(4.6,6.3,0);

        glColor3f(1,1,0);//.........front
        CircleC(0.3,1);
        // glEnd();

        glPopMatrix();
         //.....................................bulb3
        glPushMatrix();
        glTranslated(5.25,7.3,0);

        glColor3f(1,1,0);//.........front
        CircleC(0.3,1);
        // glEnd();

        glPopMatrix();
        //........................................stand
         glPushMatrix();
        glTranslated(4.9,1,0);
        glColor3f(0,0,0);
        glScaled(0.3,0.6,1);


        glBegin(GL_POLYGON);
        glVertex2d(0,0);
        glVertex2d(2.5,0);
        glVertex2d(2.5,0.5);
        glVertex2d(0,0.5);


        glEnd();

        glPopMatrix();
 //........................................stand2
         glPushMatrix();
        glTranslated(4.79,-0.2,0);
        glColor3f(0.5,0,0);
        glScaled(0.35,0.6,1);


        glBegin(GL_POLYGON);
        glVertex2d(0,0);
        glVertex2d(3,0);
        glVertex2d(3,2);
        glVertex2d(0,2);


        glEnd();

        glPopMatrix();





         //glEnd();

        glPopMatrix();





//.......................................lamppost end


//.............................signal light
        glPushMatrix();
        glTranslated(4,-2,0);
        glScaled(0.5,0.5,1.5);

        glPushMatrix();
        glTranslated(5,1,0);
        glColor3f(0,0,0);

        glBegin(GL_POLYGON);

        glVertex2d(0,0);
        glVertex2d(1,0);
        glVertex2d(1,3);
        glVertex2d(0,3);

        glEnd();

        glPopMatrix();

        glPushMatrix();
        glTranslated(5.4,-2,0);
        glColor3f(0,0,0);

        glBegin(GL_POLYGON);

        glVertex2d(0,0);
        glVertex2d(0.3,0);
        glVertex2d(0.3,3);
        glVertex2d(0,3);

        glEnd();

        glPopMatrix();
         glPushMatrix();
        glTranslated(5,-3,0);
        glColor3f(0,0,0);

        glBegin(GL_POLYGON);

        glVertex2d(0,0);
        glVertex2d(1,0);
        glVertex2d(1,1);
        glVertex2d(0,1);

        glEnd();

        glPopMatrix();

//..........................round
 glPushMatrix();
        glTranslated(5.5,3.5,0);

        glColor3f(0,1,0);//.........green
        CircleP(0.3,0.4);
         //glEnd();

        glPopMatrix();


         glPushMatrix();
        glTranslated(5.5,2.5,0);

        glColor3f(1,0,0);//.........green
        CircleP(0.3,0.4);
         //glEnd();

        glPopMatrix();

         glPushMatrix();
        glTranslated(5.5,1.5,0);

        glColor3f(1,1,0);//.........yellow
        CircleP(0.3,0.4);
         //glEnd();

        glPopMatrix();



       // glEnd();

        glPopMatrix();
 //Road
        //road background
        glPushMatrix();
        glTranslated(0,-10.5,0);
        glBegin(GL_POLYGON);

        glColor3f(0.21,0.21,0.21);
        glVertex2d(10,0);
        glVertex2d(-10,0);
        glVertex2d(-10,7);
        glVertex2d(10,7);

        glEnd();
        glPopMatrix();

        //white steps 1
        glPushMatrix();
        glTranslated(-9,-6,0);
        glBegin(GL_POLYGON);

        glColor3f(1,1,1);
        glVertex2d(1,0);
        glVertex2d(-1,0);
        glVertex2d(-1,0.3);
        glVertex2d(1,0.3);

        glEnd();
        glPopMatrix();

        //white steps 2
        glPushMatrix();
        glTranslated(-6,-6,0);
        glBegin(GL_POLYGON);

        glColor3f(1,1,1);
        glVertex2d(1,0);
        glVertex2d(-1,0);
        glVertex2d(-1,0.3);
        glVertex2d(1,0.3);

        glEnd();
        glPopMatrix();

        //white steps 3
        glPushMatrix();
        glTranslated(-3,-6,0);
        glBegin(GL_POLYGON);

        glColor3f(1,1,1);
        glVertex2d(1,0);
        glVertex2d(-1,0);
        glVertex2d(-1,0.3);
        glVertex2d(1,0.3);

        glEnd();
        glPopMatrix();

        //white steps 4
        glPushMatrix();
        glTranslated(0,-6,0);
        glBegin(GL_POLYGON);

        glColor3f(1,1,1);
        glVertex2d(1,0);
        glVertex2d(-1,0);
        glVertex2d(-1,0.3);
        glVertex2d(1,0.3);

        glEnd();
        glPopMatrix();

        //white steps 5
        glPushMatrix();
        glTranslated(3,-6,0);
        glBegin(GL_POLYGON);

        glColor3f(1,1,1);
        glVertex2d(1,0);
        glVertex2d(-1,0);
        glVertex2d(-1,0.3);
        glVertex2d(1,0.3);

        glEnd();
        glPopMatrix();

        //white steps 6
        glPushMatrix();
        glTranslated(6,-6,0);
        glBegin(GL_POLYGON);

        glColor3f(1,1,1);
        glVertex2d(1,0);
        glVertex2d(-1,0);
        glVertex2d(-1,0.3);
        glVertex2d(1,0.3);

        glEnd();
        glPopMatrix();

        //white steps 7
        glPushMatrix();
        glTranslated(9,-6,0);
        glBegin(GL_POLYGON);

        glColor3f(1,1,1);
        glVertex2d(1,0);
        glVertex2d(-1,0);
        glVertex2d(-1,0.3);
        glVertex2d(1,0.3);

        glEnd();
        glPopMatrix();
        //-------road end------







//...........................................................car

        glPushMatrix();
        glTranslated(carx,cary,0);




        glPushMatrix();
        glTranslated(-10,-7,0);
        glScaled(1.5,1.5,1);
        //carx=carx+0.001;

//.......................................body background
        glPushMatrix();
        glTranslated(1,0,0);
        glColor3f(1,0.3,0);

        glBegin(GL_POLYGON);
        glVertex2d(2,1.6);
        glVertex2d(1,0.1);
        glVertex2d(1,0);
        glVertex2d(5.5,0);
        glVertex2d(5.5,0.4);
        glVertex2d(4.5,1.6);

        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslated(2.8,1.1,0);
        glRotated(60,0,0,1);

        glColor3f(1,0.3,0);//.........orange
        CircleC(1.2,0.3);
         //glEnd();

        glPopMatrix();



        glPushMatrix();
        glTranslated(5.91,0.92,0);
        glRotated(305,0,0,1);

        glColor3f(1,0.3,0);//.........orange
        CircleC(0.8,0.3);
         //glEnd();

        glPopMatrix();
//..............................................chaka
 //...................... chaker upore
         glPushMatrix();
        glTranslated(5.8,-0.2,0);

        glColor3f(0,0,0);//.........front
        CircleC(0.5,1);
         //glEnd();

        glPopMatrix();
          glPushMatrix();
        glTranslated(2.8,-0.2,0);

        glColor3f(0,0,0);//.........black
        CircleC(0.5,1);
         //glEnd();

        glPopMatrix();

        glPushMatrix();
        glTranslated(5.8,-0.1,0);

        glColor3f(0.4,0.4,0.4);//.........light black//............front
        CircleP(0.3,0.6);
         //glEnd();

        glPopMatrix();
         glPushMatrix();
        glTranslated(2.8,-0.1,0);//.................back

        glColor3f(0.4,0.4,0.4);//.........light black
        CircleP(0.3,0.6);
         //glEnd();

        glPopMatrix();
        //...............................caka r vitorer gol
         glPushMatrix();
        glTranslated(5.8,-0.1,0);

        glColor3f(0,0,0);//.........black//............front
        CircleP(0.2,0.4);
         //glEnd();

        glPopMatrix();
         glPushMatrix();
        glTranslated(2.8,-0.1,0);//.................back

        glColor3f(0,0,0);//.........black
        CircleP(0.2,0.4);
         //glEnd();

        glPopMatrix();
         //...............................caka r vitorer vitorer  gol
         glPushMatrix();
        glTranslated(5.8,-0.1,0);

        glColor3f(1,1,1);//.........black//............front
        CircleP(0.1,0.2);
         //glEnd();

        glPopMatrix();
         glPushMatrix();
        glTranslated(2.8,-0.1,0);//.................back

        glColor3f(1,1,1);//.........black
        CircleP(0.1,0.2);
         //glEnd();

        glPopMatrix();

        //..........................................cross front chaka
        glPushMatrix();
        glRotated(angle,carx,cary,1);//.....................................................................



        glPushMatrix();
        glTranslated(5.5,-0.42,0);
        glColor3f(1,1,1);

        glBegin(GL_LINES);

        glVertex2d(0.4,0);
        glVertex2d(0.2,0.65);

        glEnd();
        glPopMatrix();

         glPushMatrix();
        glTranslated(5.5,-0.42,0);
        glColor3f(1,1,1);

        glBegin(GL_LINES);

        glVertex2d(0.2,0);
        glVertex2d(0.4,0.65);

        glEnd();

        glPopMatrix();
         glPushMatrix();
        glTranslated(5.1,-0.1,0);
        glColor3f(1,1,1);

        glBegin(GL_LINES);

        glVertex2d(0.5,0);
        glVertex2d(0.9,0);

        glEnd();
        glPopMatrix();
        //................................cross back chaka

        glPushMatrix();
        glTranslated(2.5,-0.42,0);
        glColor3f(1,1,1);

        glBegin(GL_LINES);

        glVertex2d(0.4,0);
        glVertex2d(0.2,0.65);

        glEnd();

        glPopMatrix();

         glPushMatrix();
        glTranslated(2.5,-0.42,0);
        glColor3f(1,1,1);

        glBegin(GL_LINES);

        glVertex2d(0.2,0);
        glVertex2d(0.4,0.65);

        glEnd();
        glPopMatrix();
         glPushMatrix();
        glTranslated(2.1,-0.1,0);
        glColor3f(1,1,1);

        glBegin(GL_LINES);

        glVertex2d(0.5,0);
        glVertex2d(0.9,0);

        glEnd();

        glPopMatrix();

        glPopMatrix(); //..............................................................


        //.........................looking glass


         glPushMatrix();
        glTranslated(4.2,1.7,0);
        glColor3f(1,1,1);

        glBegin(GL_POLYGON);

        glVertex2d(0.3,-0.1);
        glVertex2d(0.8,-0.1);
        glVertex2d(0.9,1);
        glVertex2d(0.5,0.9);

        glEnd();

        glPopMatrix();
        //.......................................back glass


       glPushMatrix();
        glTranslated(1.9,1.6,0);
        glColor3f(1,1,1);

        glBegin(GL_POLYGON);

        glVertex2d(1,0);
        glVertex2d(1.5,0);
        glVertex2d(1.5,1);

        glEnd();

        glPopMatrix();

        //.....................seat


         glPushMatrix();
        glTranslated(3.7,1.6,0);
        glColor3f(0,0.5,0);

        glBegin(GL_POLYGON);

        glVertex2d(-0.1,0);
        glVertex2d(0.1,0);
        glVertex2d(0.1,0.4);
        glVertex2d(-0.2,0.3);

        glEnd();

        glPopMatrix();


//........................................stearing
/*glPushMatrix();
        glTranslated(4.4,1.67,0);

        glColor3f(1,1,1);
        CircleP(0.1,0.07);
         glEnd();

        glPopMatrix();
        glEnd();*/

//...................................door

      glPushMatrix();
        glTranslated(3.6,0,0);
        glColor3f(0,0,0);

        glBegin(GL_LINE_LOOP);

        glVertex2d(0,0);
        glVertex2d(1.4,0);
        glVertex2d(1.4,1.6);
        glVertex2d(0,1.6);

        glEnd();

        glPopMatrix();
         glPushMatrix();
        glTranslated(3.7,1.5,0);
        glColor3f(0,0,0);

        glBegin(GL_POLYGON);

        glVertex2d(0,0);
        glVertex2d(0.1,0);
        glVertex2d(0.1,0.1);
        glVertex2d(0,0.1);

        glEnd();

        glPopMatrix();

        //...........................................head light

         glPushMatrix();
        glTranslated(5.75,5.9,0);
        glPushMatrix();
        glTranslated(0.75,-5.6,0);
        glRotated(270,0,0,1);

        glColor3f(1,1,0);//.........yellow
        CircleC(0.09,0.05);
         //glEnd();

        glPopMatrix();
        glPushMatrix();
        glTranslated(0.75,-5.8,0);
        glRotated(270,0,0,1);

        glColor3f(1,1,0);//.........yellow
        CircleC(0.09,0.05);
        // glEnd();
        glPopMatrix();
        glEnd();

        glPopMatrix();


        //...............................................driver
         glPushMatrix();
        glTranslated(8.8,-2.32,0);
        ////////////................head
        glPushMatrix();
        glTranslated(-4.8,4.7,0);

        glColor3f(1,0.89,0.76);
        CircleP(0.2,0.3);
        // glEnd();

        glPopMatrix();
        glPushMatrix();
        glTranslated(-4.7,4.7,0);
        glRotated(90,0,0,1);


        glColor3f(0,0,0);
        CircleC(0.4,0.4);
         //glEnd();

        glPopMatrix();
        //...............................body
         glPushMatrix();
        glTranslated(-4.8,3.9,0);

        glColor3f(0,0.93,0.93);
        CircleC(0.2,0.5);
         //glEnd();

        glPopMatrix();
        // glEnd();

        glPopMatrix();
        //glEnd();

        glPopMatrix();



        glPopMatrix();


        //.............................................end







        glFlush();
    //glutSwapBuffers();

}


int main()
{

    glutInitWindowSize(glutGet(GLUT_SCREEN_WIDTH),glutGet(GLUT_SCREEN_HEIGHT));
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

    glutCreateWindow("Final project");

    init();
    glutDisplayFunc(myDisplay);
    glutSpecialFunc(specialKey);
    glutKeyboardFunc(normalKey);
    glutMainLoop();

    return 0;
}
