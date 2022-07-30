#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#define PI          3.141516
#define PI2          6.28
#include<math.h>
#include<bits/stdc++.h>
using namespace std;

GLfloat cloudposition1=0.0f;
GLfloat cloudspeed1 = 0.01f;

GLfloat sunposition=0.0f;
GLfloat sunspeed = 0.02f;

GLfloat lboatpos=0.0f;
GLfloat rboatpos=0.0f;

GLfloat lboatspeed=0.01f;
GLfloat rboatspeed=0.01f;

GLfloat pinakposition=0.0f;
GLfloat pinakspeed=0.005f;

GLfloat Trainposition=0.0f;
GLfloat Trainspeed=0.005f;

GLfloat Carposition=0.0f;
GLfloat Carspeed=0.01f;

GLfloat Busposition=0.0f;
GLfloat Busspeed=0.005f;

GLfloat Helicopterposition=0.0f;
GLfloat Helicopterspeed=0.005f;


int mode =0;
int scene =0;
int sank=false;
int pinak=false;
int thunderstorm=false;

void updatesun(int value) {

   if(mode==1){
     if(sunposition>-1.2)
    {
       sunposition -= sunspeed;
    }
   }

    if(mode==2){

      if(sunposition<-0.02){
         sunposition += sunspeed;

      }
   }


glutPostRedisplay();
glutTimerFunc(100, updatesun, 0);


}



void updatecloudone(int value) {

    if(cloudposition1 >1.0)
       {
            cloudposition1 = -1.0f;
       }

    cloudposition1 += cloudspeed1;

glutPostRedisplay();
glutTimerFunc(100, updatecloudone, 0);
}

void runleftboat(int value){
     if(lboatpos >=1.92)
       {
            lboatpos = (-1.0f);
       }

    lboatpos += lboatspeed;

glutPostRedisplay();
glutTimerFunc(100, runleftboat, 0);
//cout<<lboatpos<<endl;

}

void runrightboat(int value){
     if(rboatpos <-1.92)
       {
            rboatpos = 1.0f;
       }

    rboatpos -= rboatspeed;

glutPostRedisplay();
glutTimerFunc(100, runrightboat, 0);


}

void pinakupdate(int value){
    if(pinak){
        if(pinakposition>0.9){
        pinakspeed=0.001f;
        thunderstorm=true;
    }

     if(pinakposition <=1.0f)
       {
            pinakposition += pinakspeed;
       }
        if(pinakposition>=1.0f){
                sank=true;
                pinak=false;
            }

    }

glutPostRedisplay();
glutTimerFunc(100, pinakupdate, 0);

}

void Trainupdate(int value){
     if(Trainposition >=1.92)
       {
            Trainposition = (-1.0f);
       }

    Trainposition += Trainspeed;

glutPostRedisplay();
glutTimerFunc(100, Trainupdate, 0);


}


void Carupdate(int value){
     if(Carposition >=1.92)
       {
            Carposition = (-1.0f);
       }

    Carposition += Carspeed;

glutPostRedisplay();
glutTimerFunc(100, Carupdate, 0);


}

void Busupdate(int value){
     if(Busposition <-1.92)
       {
            Busposition = 1.0f;
       }

    Busposition -= Busspeed;

glutPostRedisplay();
glutTimerFunc(100, Busupdate, 0);


}


void Heliupdate(int value){
     if(Helicopterposition <-1.92)
       {
            Helicopterposition = 1.0f;
       }

    Helicopterposition -= Helicopterspeed;

glutPostRedisplay();
glutTimerFunc(100, Heliupdate, 0);


}



void sun(float p, float q,float r)
{

    int i;
    GLfloat p1=p; GLfloat q1=q ; GLfloat r1 =r;
    int tringle2=40;

    GLfloat tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 252, 224, 170);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );


    }
    glEnd ();

}

void drawElipsis(GLfloat x, GLfloat y, GLfloat width,
                              GLfloat height)
  {
  int i;
  int triangleAmount = 255;
  glPushMatrix();
  glTranslatef(x, y, 0);
  glPushMatrix();
  glScalef(width, height, 0);
  glBegin(GL_TRIANGLE_FAN);
  glVertex2f(0, 0);
  for (i = 0; i <= triangleAmount; i++) {
    glVertex2f((1 * cos(i * PI2 / triangleAmount)),
               (1 * sin(i * PI2 / triangleAmount)));
  }
  glEnd();
  glPopMatrix();
  glPopMatrix();
}

void cloud(float p, float q,float r)
{

   //glClear(GL_COLOR_BUFFER_BIT);
    int i;
    GLfloat p1=p; GLfloat q1=q ; GLfloat r1 =r;
    int tringle2=40;

    GLfloat tp2 =2.0f * PI  ;

   glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 253, 241, 206);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );


    }
   glEnd ();


}

void drawRiverElipsis(GLfloat x, GLfloat y, GLfloat width,
                              GLfloat height)
  {
  int i;
  int triangleAmount = 255;
  glPushMatrix();
  glTranslatef(x, y, 0);
  glPushMatrix();
  glScalef(width, height, 0);
  glBegin(GL_TRIANGLE_FAN);
   glColor3ub(35, 138, 141);

  glVertex2f(0, 0);
  for (i = 0; i <= triangleAmount; i++) {
    glVertex2f((1 * cos(i * PI2 / triangleAmount)),
               (1 * sin(i * PI2 / triangleAmount)));
  }
  glEnd();
  glPopMatrix();
  glPopMatrix();
}
void drawQuadsForCloud(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4)
{
 glBegin(GL_QUADS);
    glColor3ub(253, 241, 206);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glVertex2f(x4, y4);
    glEnd ();

}
void DrawSky(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4)
{

glBegin(GL_QUADS);
    glColor3ub(82, 192, 191);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glVertex2f(x4, y4);
    glEnd ();


glPushMatrix();
glTranslatef(0.0f,sunposition,0.0f);
sun(-0.20f,0.86f,0.08f);
glPopMatrix();



}

void cloud(){




glPushMatrix();
glTranslatef(cloudposition1,0.0f,0.0f);
    cloud(-0.8f,0.8f,0.045f); //left
    cloud(-0.75f,0.8f,0.065f);
    cloud(-0.70f,0.8f,0.045f);

    drawQuadsForCloud(-0.2f,0.7f,-0.05f,0.7f,-0.05f,0.75f,-0.2f,0.75f);  //mid
    cloud(-0.2f,0.76f,0.06f);
    cloud(-0.13f,0.8f,0.075f);
    cloud(-0.05f,0.76f,0.06f);

    cloud(0.4f,0.8f,0.06f);//right up
    cloud(0.5f,0.8f,0.08f);
    cloud(0.57f,0.8f,0.06f);



    cloud(0.2f,0.6f,0.06f);//right down
    cloud(0.3f,0.6f,0.08f);
    cloud(0.37f,0.6f,0.06f);

    cloud(-0.2f,0.6f,0.06f);//right up
    cloud(-0.3f,0.6f,0.08f);
    cloud(-0.37f,0.6f,0.06f);



    cloud(-1.2f,0.6f,0.06f);//right up
    cloud(-1.3f,0.6f,0.08f);
    cloud(-1.37f,0.6f,0.06f);


drawElipsis(-0.99f,0.5f,0.15f,0.05f); //left half
drawElipsis(0.65f,0.5f,0.15f,0.05f);
drawElipsis(0.75f,0.45f,0.15f,0.05f);


glPopMatrix();







}

void hill()
{




            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(192,192,192);
            glVertex2f(-0.77f, -0.22);
            glVertex2f(-0.65f, -0.22f);
            glVertex2f(-0.7f, 0.005f);

            glEnd();

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(192,192,192);
            glVertex2f(-0.75f, -0.22);
            glVertex2f(-0.5f, -0.22f);
            glVertex2f(-0.6f, -0.09f);

            glEnd();


           glBegin(GL_TRIANGLE_FAN);
            glColor3ub(192,192,192);
            glVertex2f(-0.9f, -0.22);
            glVertex2f(-0.7f, -0.22f);
            glVertex2f(-0.8f, -0.03f);

            glEnd();

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(192,192,192);
            glVertex2f(-1.055f, -0.22);
            glVertex2f(-0.8f, -0.22f);
            glVertex2f(-0.9f, 0.06f);
            glEnd();


            //right hill


            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(192,192,192);
            glVertex2f(0.75f, -0.22);
            glVertex2f(0.5f, -0.22f);
            glVertex2f(0.6f, -0.09f);

            glEnd();


           glBegin(GL_TRIANGLE_FAN);
             glColor3ub(192,192,192);
            glVertex2f(0.9f, -0.22);
            glVertex2f(0.7f, -0.22f);
            glVertex2f(0.8f, -0.03f);

            glEnd();

            glBegin(GL_TRIANGLE_FAN);
           glColor3ub(192,192,192);
            glVertex2f(1.1f, -0.22);
            glVertex2f(0.8f, -0.22f);
            glVertex2f(0.9f, 0.06f);
            glEnd();


}


void DrawRiver(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4)
{

    glBegin(GL_QUADS);
    glColor3ub(1, 127, 129);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glVertex2f(x4, y4);
      glEnd ();

drawRiverElipsis(0.1f,-0.270f,0.16f,0.015f);
drawRiverElipsis(-0.4f,-0.560f,0.25f,0.020f);
drawRiverElipsis(0.4f,-0.760f,0.25f,0.015f);
drawRiverElipsis(0.7f,-0.360f,0.15f,0.01f);



}
void keyboard(unsigned char key, int x, int y) {


 if(key=='N')
    {
      mode=true;
      glutPostRedisplay();
    }
    if(key=='D')
    {
      mode=2;
      glutPostRedisplay();
    }

   if(key=='E')
    {
      mode=2;
      glutPostRedisplay();
    }

    if(key=='p'){
        pinak=true;
        glutPostRedisplay();
    }



}


void specialKeys(int key, int x, int y) {
    switch (key) {
      case GLUT_KEY_LEFT:
          scene--;


          break;
      case GLUT_KEY_RIGHT:
          scene++;
          break;
    }
}


void bridgespanpiller(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4){

glBegin(GL_QUADS);
glColor3ub(105,105,105);
glVertex2f(x1,y1);
glVertex2f(x2,y2);
glVertex2f(x3,y3);
glVertex2f(x4,y4);
glEnd();

}

void bridgeLight(){
        glLineWidth(4); //line in boat 1
        glBegin(GL_LINES);
        glColor3ub(105,105,105);
        glVertex2f(-0.9f, 0.2f);
        glVertex2f(-0.9f, 0.4f);
        glEnd();

        glLineWidth(4); //line in boat 1
        glBegin(GL_LINES);
        glColor3ub(105,105,105);
        glVertex2f(-0.9f,  0.4f);
        glVertex2f(-0.88f, 0.4f);
        glEnd();

        glLineWidth(4); //line in boat 1
        glBegin(GL_LINES);
        glColor3ub(105,105,105);
        glVertex2f(-0.85f, 0.2f);
        glVertex2f(-0.85f, 0.4f);
        glEnd();

        glLineWidth(4); //line in boat 1
        glBegin(GL_LINES);
        glColor3ub(105,105,105);
        glVertex2f(-0.85f,  0.4f);
        glVertex2f(-0.87f, 0.4f);
        glEnd();
}

void Bridge(){



glBegin(GL_QUADS);
glColor3ub(105,105,105);
glVertex2f(-1.0f,-0.05f);
glVertex2f(1.0f,-0.05f);
glVertex2f(1.0f,0.0f);
glVertex2f(-1.0f,0.0f);





glEnd();
glBegin(GL_QUADS);
glColor3ub(105,105,105);
glVertex2f(-1.0f,0.2f);
glVertex2f(1.0f,0.2f);
glVertex2f(1.0f,0.25f);
glVertex2f(-1.0f,0.25f);
glEnd();
glFlush();



//Bridge Pillers



glBegin(GL_QUADS);
glColor3ub(105,105,105);
glVertex2f(-0.55f,-0.2f);
glVertex2f(-0.45f,-0.2f);
glVertex2f(-0.45f,0.0f);
glVertex2f(-0.55f,0.0f);
glEnd();



glBegin(GL_QUADS);
glColor3ub(105,105,105);
glVertex2f(0.55f,-0.2f);
glVertex2f(0.45f,-0.2f);
glVertex2f(0.45f,0.0f);
glVertex2f(0.55f,0.0f);
glEnd();




glBegin(GL_QUADS);
glColor3ub(105,105,105);
glVertex2f(-0.6f,-0.22f);
glVertex2f(-0.4f,-0.22f);
glVertex2f(-0.4f,-0.15f);
glVertex2f(-0.6f,-0.15f);
glEnd();
glFlush();




glBegin(GL_QUADS);
glColor3ub(105,105,105);
glVertex2f(0.6f,-0.22f);
glVertex2f(0.4f,-0.22f);
glVertex2f(0.4f,-0.15f);
glVertex2f(0.6f,-0.15f);
glEnd();



bridgespanpiller(-0.8f,0.0f,-0.7f,0.0f,-0.9f,0.2f,-1.0f,0.2f);
bridgespanpiller(-0.7f,0.0f,-0.6f,0.0f,-0.4f,0.2f,-0.5f,0.2f);

glPushMatrix();
glTranslatef(0.5,0.0f,0.0f);
bridgespanpiller(-0.8f,0.0f,-0.7f,0.0f,-0.9f,0.2f,-1.0f,0.2f);
bridgespanpiller(-0.7f,0.0f,-0.6f,0.0f,-0.4f,0.2f,-0.5f,0.2f);
glPopMatrix();


glPushMatrix();
glTranslatef(1.0f,0.0f,0.0f);
bridgespanpiller(-0.8f,0.0f,-0.7f,0.0f,-0.9f,0.2f,-1.0f,0.2f);
bridgespanpiller(-0.7f,0.0f,-0.6f,0.0f,-0.4f,0.2f,-0.5f,0.2f);
glPopMatrix();

glPushMatrix();
glTranslatef(1.5f,0.0f,0.0f);
bridgespanpiller(-0.8f,0.0f,-0.7f,0.0f,-0.9f,0.2f,-1.0f,0.2f);
bridgespanpiller(-0.7f,0.0f,-0.6f,0.0f,-0.4f,0.2f,-0.5f,0.2f);
glPopMatrix();


bridgeLight();
glPushMatrix();
glTranslatef(0.4f,0.0f,0.0f);
bridgeLight();
glPopMatrix();

glPushMatrix();
glTranslatef(0.8f,0.0f,0.0f);
bridgeLight();
glPopMatrix();


glPushMatrix();
glTranslatef(1.2f,0.0f,0.0f);
bridgeLight();
glPopMatrix();

glPushMatrix();
glTranslatef(1.6f,0.0f,0.0f);
bridgeLight();
glPopMatrix();



}
void drawBigBoat()
{
     drawRiverElipsis(-0.88f,-0.65f,0.16f,0.015f);
         glBegin(GL_TRIANGLE_FAN);
            glColor3ub(142, 35, 35);
            glVertex2f(-0.98f, -0.65f);
            glVertex2f(-0.8f, -0.65f);
            glVertex2f(-0.76f, -0.55f);
            glVertex2f(-0.98f, -0.55f);
            glEnd();
            //91, 51, 22

              glBegin(GL_TRIANGLE_FAN);
            glColor3ub(0, 0, 0);
            glVertex2f(-0.98f, -0.65f);
            glVertex2f(-0.8f, -0.65f);
            glVertex2f(-0.79f, -0.6255f);
            glVertex2f(-0.98f, -0.6255f);
            glEnd();

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(91, 51, 22);
            glVertex2f(-0.98f, -0.55f);
            glVertex2f(-0.76f, -0.55f);
            glVertex2f(-0.76f, -0.535f);
            glVertex2f(-0.98f, -0.535f);
            glEnd();

//boat windows
               glBegin(GL_TRIANGLE_FAN);
            glColor3ub(191, 216, 249);
            glVertex2f(-0.96f, -0.61f);
            glVertex2f(-0.93f, -0.61f);
            glVertex2f(-0.93f, -0.57f);
            glVertex2f(-0.96f, -0.57f);
            glEnd();


            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(191, 216, 249);
            glVertex2f(-0.91f, -0.61f);
            glVertex2f(-0.88f, -0.61f);
            glVertex2f(-0.88f, -0.57f);
            glVertex2f(-0.91f, -0.57f);
            glEnd();

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(191, 216, 249);
            glVertex2f(-0.86f, -0.61f);
            glVertex2f(-0.83f, -0.61f);
            glVertex2f(-0.83f, -0.57f);
            glVertex2f(-0.86f, -0.57f);
            glEnd();

//  mid part

  glBegin(GL_TRIANGLE_FAN);
            glColor3ub(84, 83, 84);
            glVertex2f(-0.98f, -0.535f);
            glVertex2f(-0.81f, -0.535f);
            glVertex2f(-0.81f, -0.482f);
            glVertex2f(-0.98f, -0.482f);
            glEnd();

   // mid part windows
   //1
    glBegin(GL_TRIANGLE_FAN);
            glColor3ub(191, 216, 216);
            glVertex2f(-0.94f, -0.53f);
            glVertex2f(-0.92f, -0.53f);
            glVertex2f(-0.92f, -0.5f);
            glVertex2f(-0.94f, -0.5f);
            glEnd();

            //2
             glBegin(GL_TRIANGLE_FAN);
            glColor3ub(191, 216, 216);
            glVertex2f(-0.90f, -0.53f);
            glVertex2f(-0.88f, -0.53f);
            glVertex2f(-0.88f, -0.5f);
            glVertex2f(-0.9f, -0.5f);
            glEnd();
//3
   glBegin(GL_TRIANGLE_FAN);
            glColor3ub(191, 216, 216);
            glVertex2f(-0.86f, -0.53f);
            glVertex2f(-0.84f, -0.53f);
            glVertex2f(-0.84f, -0.5f);
            glVertex2f(-0.86f, -0.5f);
            glEnd();
// top part in boat

  glBegin(GL_TRIANGLE_FAN);
            glColor3ub(91, 51, 22);
            glVertex2f(-0.97f, -0.482f);
            glVertex2f(-0.82f, -0.482);
            glVertex2f(-0.84f, -0.46f);
            glVertex2f(-0.95f, -0.46f);
            glEnd();

    // top most part dua

  glBegin(GL_TRIANGLE_FAN);
            glColor3ub(0, 0, 0);
            glVertex2f(-0.925f, -0.46f);
            glVertex2f(-0.905f, -0.46);
            glVertex2f(-0.905f, -0.43f);
            glVertex2f(-0.925f, -0.43f);
            glEnd();
//red
    glBegin(GL_TRIANGLE_FAN);
            glColor3ub(255, 0, 0);
            glVertex2f(-0.925f, -0.43f);
            glVertex2f(-0.905f, -0.43);
            glVertex2f(-0.905f, -0.422f);
            glVertex2f(-0.925f, -0.422f);
            glEnd();

             glBegin(GL_TRIANGLE_FAN);
            glColor3ub(0, 0, 0);
            glVertex2f(-0.89f, -0.46f);
            glVertex2f(-0.87f, -0.46);
            glVertex2f(-0.87f, -0.43f);
            glVertex2f(-0.89f, -0.43f);
            glEnd();
//red
    glBegin(GL_TRIANGLE_FAN);
            glColor3ub(255, 0, 0);
            glVertex2f(-0.89f, -0.43f);
            glVertex2f(-0.87f, -0.43f);
            glVertex2f(-0.87f, -0.422f);
            glVertex2f(-0.89f, -0.422f);
            glEnd();


}
void Train()
{
    //left part
glPushMatrix();
glTranslatef(Trainposition,0.0f,0.0f);
     glBegin(GL_QUADS);
        glColor3ub(255,255,255);
        glVertex2f(-0.98f,0.0f);
        glVertex2f(-0.85f,0.0f);
        glVertex2f(-0.85f,0.02f);
        glVertex2f(-0.98f,0.02f);

        glEnd();




        //black
          glBegin(GL_QUADS);
        glColor3ub(82, 82, 86);
        glVertex2f(-0.98f,0.03f);
        glVertex2f(-0.85f,0.03f);
        glVertex2f(-0.85f,0.095f);
        glVertex2f(-0.98f,0.095f);

        glEnd();


          glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(-0.98f,0.095f);
        glVertex2f(-0.85f,0.095f);
        glVertex2f(-0.88f,0.12f);
        glVertex2f(-0.95f,0.12f);

        glEnd();

        //38, 39, 39
        //windows

       glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(-0.96f,0.045f);
        glVertex2f(-0.93f,0.045f);
        glVertex2f(-0.93f,0.075f);
        glVertex2f(-0.96f,0.075f);

        glEnd();


          glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(-0.9f,0.045f);
        glVertex2f(-0.87f,0.045f);
        glVertex2f(-0.87f,0.075f);
        glVertex2f(-0.9f,0.075f);

        glEnd();
//part 1 end



     glBegin(GL_QUADS);
        glColor3ub(255,255,255);
        glVertex2f(-0.83f,0.0f);
        glVertex2f(-0.7f,0.0f);
        glVertex2f(-0.7f,0.02f);
        glVertex2f(-0.83f,0.02f);

        glEnd();




         glBegin(GL_QUADS);
        glColor3ub(82, 82, 86);
        glVertex2f(-0.83f,0.03f);
        glVertex2f(-0.7f,0.03f);
        glVertex2f(-0.7f,0.095f);
        glVertex2f(-0.83f,0.095f);

        glEnd();




            glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(-0.83f,0.095f);
        glVertex2f(-0.7f,0.095f);
        glVertex2f(-0.73f,0.12f);
        glVertex2f(-0.8f,0.12f);

        glEnd();


        //windows in paret 2
 glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(-0.81f,0.045f);
        glVertex2f(-0.78f,0.045f);
        glVertex2f(-0.78f,0.075f);
        glVertex2f(-0.81f,0.075f);

        glEnd();


          glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(-0.75f,0.045f);
        glVertex2f(-0.72f,0.045f);
        glVertex2f(-0.72f,0.075f);
        glVertex2f(-0.75f,0.075f);

        glEnd();

        // part 2 end


        //part 3

        glBegin(GL_QUADS);
        glColor3ub(255,255,255);
        glVertex2f(-0.68f,0.0f);
        glVertex2f(-0.55f,0.0f);
        glVertex2f(-0.55f,0.02f);
        glVertex2f(-0.68f,0.02f);

        glEnd();



       glBegin(GL_QUADS);
        glColor3ub(82, 82, 86);
        glVertex2f(-0.68f,0.03f);
        glVertex2f(-0.55f,0.03f);
        glVertex2f(-0.55f,0.095f);
        glVertex2f(-0.68f,0.095f);

        glEnd();



            glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(-0.68f,0.095f);
        glVertex2f(-0.55,0.095f);
        glVertex2f(-0.58f,0.12f);
        glVertex2f(-0.65f,0.12f);

        glEnd();



        // windows for part 3
        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(-0.66f,0.045f);
        glVertex2f(-0.63f,0.045f);
        glVertex2f(-0.63f,0.075f);
        glVertex2f(-0.66f,0.075f);

        glEnd();


          glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(-0.6f,0.045f);
        glVertex2f(-0.57f,0.045f);
        glVertex2f(-0.57f,0.075f);
        glVertex2f(-0.6f,0.075f);

        glEnd();

        // font in train


          glBegin(GL_QUADS);
        glColor3ub(44, 150, 0);
        glVertex2f(-0.54f,0.0f);
        glVertex2f(-0.47f,0.0f);
        glVertex2f(-0.47f,0.06f);
        glVertex2f(-0.54f,0.06f);

        glEnd();


          glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(-0.52f,0.015f);
        glVertex2f(-0.475f,0.015f);
        glVertex2f(-0.475f,0.048f);
        glVertex2f(-0.52f,0.048f);

        glEnd();


         glBegin(GL_QUADS);
        glColor3ub(0, 0, 0);
        glVertex2f(-0.49f,0.06f);
        glVertex2f(-0.475f,0.06f);
        glVertex2f(-0.475f,0.09f);
        glVertex2f(-0.49f,0.09f);

        glEnd();



           glBegin(GL_QUADS);
        glColor3ub(255, 0, 0);
        glVertex2f(-0.49f,0.09f);
        glVertex2f(-0.475f,0.09f);
        glVertex2f(-0.475f,0.095f);
        glVertex2f(-0.49f,0.095f);

        glEnd();



  glBegin(GL_QUADS);
        glColor3ub(255, 82, 71);
        glVertex2f(-0.98f,0.02f);
        glVertex2f(-0.54f,0.02f);
        glVertex2f(-0.54f,0.04f);
        glVertex2f(-0.98f,0.04f);

        glEnd();


glPopMatrix();



}





void drawBoat()
{


glPushMatrix();
glTranslatef(lboatpos,0.0f,0.0f);


drawRiverElipsis(-0.88f,-0.35f,0.11f,0.015f);
drawRiverElipsis(-0.83f,-0.850f,0.11f,0.015f);


        glBegin(GL_TRIANGLE_FAN); //  left up in boat 1
            glColor3ub(255, 255, 255);
            glVertex2f(-0.92f, -0.35f);
            glVertex2f(-0.82f, -0.35f);
            glVertex2f(-0.77f, -0.30f);
            glVertex2f(-0.97f, -0.30f);
            glEnd();


        glLineWidth(8); //line in boat 1
        glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(-0.87f, -0.29f);
        glVertex2f(-0.87f, -0.23f);
        glEnd();

          glBegin(GL_TRIANGLE_FAN);  //boat 1 right pall
          glColor3ub(255, 255, 255);
          glVertex2f(-0.86f, -0.29f);
          glVertex2f(-0.80f, -0.29f);
          glVertex2f(-0.86f, -0.24f);
          glEnd();


          glBegin(GL_TRIANGLE_FAN);  ////boat 1 left pall
          glColor3ub(255, 255, 255);
          glVertex2f(-0.92f, -0.29f);
          glVertex2f(-0.88f, -0.29f);
          glVertex2f(-0.88f, -0.23f);
          glEnd();


          //Down Left Boat

           glBegin(GL_TRIANGLE_FAN); //  left down in boat 1
            glColor3ub(255, 255, 255);
            glVertex2f(-0.88f, -0.85f);
            glVertex2f(-0.78f, -0.85f);
            glVertex2f(-0.73f, -0.80f);
            glVertex2f(-0.93f, -0.80f);
            glEnd();


        glLineWidth(8); //line in boat 1
        glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(-0.86f, -0.79f);
        glVertex2f(-0.86f, -0.73f);
        glEnd();

         glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(-0.88f, -0.79f);
        glVertex2f(-0.88f, -0.73f);
        glEnd();

          glBegin(GL_TRIANGLE_FAN);  //boat 1 right pall
          glColor3ub(255, 255, 255);
          glVertex2f(-0.848f, -0.79f);
          glVertex2f(-0.72f, -0.79f);
          glVertex2f(-0.848f,-0.72f);
          glEnd();



glPopMatrix();


glPushMatrix();
glTranslatef(rboatpos,0.0f,0.0f);
          // right mid boat 2
drawRiverElipsis(0.85f,-0.550f,0.11f,0.015f);

          glBegin(GL_TRIANGLE_FAN); // right mid in boat 2
            glColor3ub(255, 255, 255);
            glVertex2f(0.92f, -0.55f);
            glVertex2f(0.82f, -0.55f);
            glVertex2f(0.77f, -0.50f);
            glVertex2f(0.97f, -0.50f);
            glEnd();


        glLineWidth(8); //line in boat 2
        glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(0.87f, -0.49f);
        glVertex2f(0.87f, -0.43f);
        glEnd();

          glBegin(GL_TRIANGLE_FAN);  //boat 2 right pall
          glColor3ub(255, 255, 255);
          glVertex2f(0.86f, -0.49f);
          glVertex2f(0.80f, -0.49f);
          glVertex2f(0.86f, -0.43f);
          glEnd();


          glBegin(GL_TRIANGLE_FAN);  ////boat 2 left pall
          glColor3ub(255, 255, 255);
          glVertex2f(0.92f, -0.49f);
          glVertex2f(0.88f, -0.49f);
          glVertex2f(0.88f, -0.43f);
          glEnd();

glPopMatrix();

}

void car()
{


glPushMatrix();
glTranslatef(Carposition,0.0f,0.0f);
      glBegin(GL_QUADS);
        glColor3ub(255,0,0);
        glVertex2f(-0.97f,0.25f);
        glVertex2f(-0.89f,0.25f);
        glVertex2f(-0.89f,0.265f);
        glVertex2f(-0.97f,0.265f);
        glEnd();


         glBegin(GL_QUADS);
        glColor3ub(255,0,0);
        glVertex2f(-0.97f,0.265f);
        glVertex2f(-0.89f,0.265f);
        glVertex2f(-0.91f,0.28f);
        glVertex2f(-0.95f,0.28f);
        glEnd();
//car windows 1
           glBegin(GL_LINES);
        glColor3ub(255,255,255);
        glVertex2f(-0.950f,0.265f);
        glVertex2f(-0.940f,0.265f);;
        glEnd();

        //car windows 2
   glBegin(GL_LINES);
        glColor3ub(255,255,255);
        glVertex2f(-0.928f,0.265f);
        glVertex2f(-0.918f,0.265f);;
        glEnd();



         glBegin(GL_QUADS);
        glColor3ub(255,255,0);
        glVertex2f(-0.95f,0.28f);
        glVertex2f(-0.91f,0.28f);
        glVertex2f(-0.92f,0.295f);
        glVertex2f(-0.94f,0.295f);
        glEnd();
glPopMatrix();

}



void bus()
{



glPushMatrix();
glTranslatef(Busposition,0.0f,0.0f);
  glBegin(GL_QUADS);
        glColor3ub(255,0,0);
        glVertex2f(0.8f,0.25f);
        glVertex2f(0.92f,0.25f);
        glVertex2f(0.92f,0.2658f);
        glVertex2f(0.8f,0.2658f);
        glEnd();

          glBegin(GL_QUADS);
        glColor3ub(0,0,0);
        glVertex2f(0.8f,0.2658f);
        glVertex2f(0.92f,0.2658f);
        glVertex2f(0.92f,0.33f);
        glVertex2f(0.8f,0.33f);
        glEnd();


           glBegin(GL_QUADS);
        glColor3ub(255,255,255);
        glVertex2f(0.81f,0.28f);
        glVertex2f(0.83f,0.28f);
        glVertex2f(0.83f,0.32f);
        glVertex2f(0.81f,0.32f);
        glEnd();

            glBegin(GL_QUADS);
        glColor3ub(255,255,255);
        glVertex2f(0.85f,0.28f);
        glVertex2f(0.87f,0.28f);
        glVertex2f(0.87f,0.32f);
        glVertex2f(0.85f,0.32f);
        glEnd();

           glBegin(GL_QUADS);
        glColor3ub(255,255,255);
        glVertex2f(0.89f,0.28f);
        glVertex2f(0.91f,0.28f);
        glVertex2f(0.91f,0.32f);
        glVertex2f(0.89f,0.32f);
        glEnd();


             glBegin(GL_QUADS);
        glColor3ub(255,0,0);
        glVertex2f(0.8f,0.33f);
        glVertex2f(0.92f,0.33f);
        glVertex2f(0.90f,0.335f);
        glVertex2f(0.82f,0.335f);
        glEnd();

           glBegin(GL_TRIANGLES);
        glColor3ub(255,255,0);
        glVertex2f(0.77f,0.25f);
        glVertex2f(0.8f,0.25f);
        glVertex2f(0.8f,0.33f);

        glEnd();

glPopMatrix();
}


void drawHelicopter()
{



glPushMatrix();
glTranslatef(Helicopterposition,0.0f,0.0f);
    glBegin(GL_QUADS);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(0.69f,0.65f);
glVertex2f(0.69f,0.6f);
glVertex2f(0.9f,0.6f);
glVertex2f(0.9f,0.65f); //helicopter body

glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f,0.0f,0.0f);

glVertex2f(0.69f,0.65f);
glVertex2f(0.8f,0.65f);
glVertex2f(0.77,0.7f);
glVertex2f(0.73f,0.7f); //helicopter head

glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f,0.0f,0.0f);

glVertex2f(0.9f,0.65f);
glVertex2f(0.9,0.7f);
glVertex2f(0.87f,0.7f);
glVertex2f(0.87f,0.65f);
//helicopter tail
glEnd();

glLineWidth(2);
glBegin(GL_LINES);
glColor3f(0.0f,0.0f,0.0f);

glVertex2f(0.75f,0.7f);
glVertex2f(0.75,0.75f);

//helicopter fan
glEnd();

glLineWidth(5);
glBegin(GL_LINES);
glColor3f(0.0f,0.0f,0.0f);

glVertex2f(0.67f,0.73f);
glVertex2f(0.82f,0.73f);

//helicopter fan
glEnd();

glLineWidth(2);
glBegin(GL_LINES);
glColor3f(0.0f,0.0f,0.0f);

glVertex2f(0.75f,0.6f);
glVertex2f(0.75f,0.57f); //lowerpart
glEnd();

glLineWidth(2);
glBegin(GL_LINES);
glColor3f(0.0f,0.0f,0.0f);

glVertex2f(0.77f,0.6f);
glVertex2f(0.77f,0.57f); //lowerpart
glEnd();

glLineWidth(2);
glBegin(GL_LINES);
glColor3f(0.0f,0.0f,0.0f);

glVertex2f(0.72f,0.57f);
glVertex2f(0.79f,0.57f); //lowerpart
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f);

glVertex2f(0.75f,0.68f);
glVertex2f(0.75,0.62f);
glVertex2f(0.76f,0.62f);
glVertex2f(0.76f,0.68f);

glEnd();

glPopMatrix();
}

void DAY(){

DrawSky(-1.0f, -0.28f,1.0f, -0.28f,1.0f, 1.0f,-1.0f, 1.0f);
DrawRiver(-1.0f, -1.0f,1.0f, -1.0f,1.0f, -0.20f,-1.0f, -0.20f);
cloud();
drawBoat();
drawHelicopter();

if(scene==0)
    {
        if(pinak){
            glPushMatrix();
            glTranslatef(pinakposition,0.0f,0.0f);
            drawBigBoat();
            glPopMatrix();
            }

        if(sank){

            }


    }


if(scene==1)   {
            Train();
            car();
            bus();
            Bridge();
            hill();
}

}

void display()
{

glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
cout<<scene<<endl;
if(mode==0){
    DAY();
}

/*
else if(mode==2){
    NIGHT();
}
else if(mode==3){
    EVE();
}
*/

glFlush();
}





int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1000, 800);
    glutCreateWindow("OpenGL Setup Test");
    glutDisplayFunc(display);
glutSpecialFunc(specialKeys);

    glutKeyboardFunc(keyboard);
    glutTimerFunc(100, updatecloudone, 0);
    glutTimerFunc(100, updatesun, 0);
    glutTimerFunc(200, runrightboat, 0);
    glutTimerFunc(100, runleftboat, 0);
    glutTimerFunc(100, pinakupdate, 0);
    glutTimerFunc(100, Trainupdate, 0);
    glutTimerFunc(100, Carupdate, 0);
glutTimerFunc(100, Busupdate, 0);
glutTimerFunc(100, Heliupdate, 0);
    glutMainLoop();
    return 0;
}
