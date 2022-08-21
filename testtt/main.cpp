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
GLfloat Carspeed=0.010f;

GLfloat Busposition=0.0f;
GLfloat Busspeed=0.009f;

GLfloat Helicopterposition=0.0f;
GLfloat Helicopterspeed=0.005f;



GLfloat lbird=0.0f;
GLfloat rbird=0.0f;

GLfloat lbirdspeed=0.01f;
GLfloat rbirdspeed=0.01f;



GLfloat lboatthpos=0.0f;
GLfloat rboatthpos=0.0f;

GLfloat lboatthspeed=0.01f;
GLfloat rboatthspeed=0.01f;

int trafficmode=0;
int sunset=-1;
int mode =0;
int scene =0;
int sank=false;
int pinak=false;
int thunderstorm=false;

void updatesun(int value) {

   if(mode!=3){
   	if(sunset==0){
     if(sunposition>-1.2)
    {
       sunposition -= sunspeed;
    }
       else{
        mode=1;
       }
   }

    if(sunset==1){

      if(sunposition<-0.02){
         sunposition += sunspeed;

      }

      if(sunposition>=-0.98){
        mode=0;
      }
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


//Thunderstorm
void runthleftboat(int value){

if(sank){
    if(lboatthpos>=1.92)
       {
            lboatthpos = (-1.0f);
       }

    lboatthpos += lboatthspeed;

if(lboatthpos>=1.0f && lboatthpos<1.08f){
    lboatthspeed=0.0005f;
}
if(lboatthpos>=1.08f){
    lboatthspeed=0.01f;
}



}
glutPostRedisplay();
glutTimerFunc(100, runthleftboat, 0);


}

void runthrightboat(int value){


    if(sank){
         if(rboatthpos <-1.92)
       {
            rboatthpos = 1.0f;
       }

    rboatthpos -= rboatthspeed;

    if(rboatthpos<-0.4 && rboatthpos>-0.46){
        rboatthspeed=0.0005f;
    }
    if(rboatthpos<=-0.46){
        rboatthspeed=0.01f;
    }
}
glutPostRedisplay();
glutTimerFunc(100, runthrightboat, 0);



}




//Birds
void runleftbirds(int value){
     if(lbird >=1.92)
       {
            lbird = (-1.0f);
       }

    lbird += lbirdspeed;

glutPostRedisplay();
glutTimerFunc(100, runleftbirds, 0);
}

void runrightbirds(int value){
     if(rbird <-1.92)
       {
            rbird = 1.0f;
       }

    rbird -= rbirdspeed;

glutPostRedisplay();
glutTimerFunc(100, runrightbirds, 0);


}

void pinakupdate(int value){

    if(pinak){
        if(pinakposition>0.9){
        pinakspeed=0.001f;
        mode=2;
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

void sunEvening(float p, float q,float r,int a,int b,int c)
{
    int i;
    GLfloat p1=p; GLfloat q1=q ; GLfloat r1 =r;
    int tringle2=40;
    GLfloat tp2 =2.0f * PI  ;
    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( a, b, c);
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

void moon(float p, float q,float r,int c)
{
    int count=c;
    int i;
    GLfloat p1=p; GLfloat q1=q ; GLfloat r1 =r;
    int tringle2=40;
    GLfloat tp2 =2.0f * PI  ;
    glBegin (GL_TRIANGLE_FAN);
    if(c==1)
    {

       glColor3ub ( 70, 52, 216);
    }
    if(c==2)
    {

        glColor3ub ( 86, 71, 221);
    }
    if(c==3)
    {

         glColor3ub ( 255, 255, 255);
    }

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

void cloud(float p, float q,float r)
{

   //glClear(GL_COLOR_BUFFER_BIT);
    int i;
    GLfloat p1=p; GLfloat q1=q ; GLfloat r1 =r;
    int tringle2=40;

    GLfloat tp2 =2.0f * PI  ;

   glBegin (GL_TRIANGLE_FAN);
   if(mode==0){
    glColor3ub ( 253, 241, 206);
   }
    else if(mode==1){
        glColor3ub ( 74, 69, 214);
    }
    else if(mode==2)
        {
         glColor3ub ( 49, 59, 67);
    }else if (mode==3){
		 glColor3ub ( 254, 242, 189);
	}
	else
    {
    	glColor3ub ( 253, 241, 206);
    }

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

void Bird()
{

glPushMatrix();
glTranslatef(lbird,0.0f,0.0f);

glBegin(GL_POLYGON);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.8f, 0.8f);// x, y
glVertex2f(-0.75f, 0.8f);
glVertex2f(-0.8f, 0.81f);
glVertex2f(-0.85f, 0.85f);
glEnd();


glBegin(GL_POLYGON);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.7f, 0.7f);// x, y
glVertex2f(-0.65f, 0.7f);
glVertex2f(-0.7f, 0.71f);
glVertex2f(-0.75f, 0.75f);
glEnd();


glBegin(GL_POLYGON);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.9f, 0.7f);
glVertex2f(-0.85f, 0.7f);
glVertex2f(-0.9f, 0.71f);
glVertex2f(-0.95f, 0.75f);
glEnd();

glPopMatrix();


glPushMatrix();
glTranslatef(rbird,0.0f,0.0f);
glBegin(GL_POLYGON);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.8f, 0.8f);
glVertex2f(0.75f, 0.8f);
glVertex2f(0.8f, 0.81f);
glVertex2f(0.85f, 0.85f);
glEnd();

glBegin(GL_POLYGON);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.7f, 0.7f);// x, y
glVertex2f(0.65f, 0.7f);
glVertex2f(0.7f, 0.71f);
glVertex2f(0.75f, 0.75f);
glEnd();


glBegin(GL_POLYGON);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.9f, 0.7f);// x, y
glVertex2f(0.85f, 0.7f);
glVertex2f(0.9f, 0.71f);
glVertex2f(0.95f, 0.75f);
glEnd();
glPopMatrix();
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

  if(mode==0){
    glColor3ub(35, 138, 141);
   }
   else if(mode==1){
         glColor3ub(40, 37, 114);
    }
    else if(mode==2)
        {
             glColor3ub(103, 73, 77);
        }
		else if(mode==3){
			 glColor3ub(204, 70, 55);
		}
        else{
            glColor3ub(35, 138, 141);
        }


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

 if(mode==0){
     glColor3ub(253, 241, 206);
   }
   else if(mode==1){
        glColor3ub(74, 69, 214);
    }
    else if(mode==2){
         glColor3ub(49, 59, 67);
    }else if(mode==3){
		glColor3ub(253, 241, 206);
	}
    else{
         glColor3ub(253, 241, 206);
    }

    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glVertex2f(x4, y4);
    glEnd ();

}
void DrawSky(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4)
{

glBegin(GL_QUADS);


    if(mode==0){
     glColor3ub(82, 192, 191);
   }
    else if(mode==1){
        glColor3ub(60, 41, 212);
    }
    else if(mode==2){
         glColor3ub(88, 69, 90);
    }else if(mode==3){
		glColor3ub(216, 122, 42);
	}
    else{
       glColor3ub(82, 192, 191);
    }

    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glVertex2f(x4, y4);
    glEnd ();


glPushMatrix();
glTranslatef(0.0f,sunposition,0.0f);
if(mode==3){
	sunEvening(-0.2f,-0.17f,0.105f,232, 142, 64);
    sunEvening(-0.2f,-0.17f,0.09f,242, 237, 182);
}
else if(mode!=2 && mode !=3){
   sun(-0.20f,0.86f,0.08f);

}
glPopMatrix();



}
void star(float p, float q,float r,int c)
{

    int count=c;
    int i;
    GLfloat p1=p; GLfloat q1=q ; GLfloat r1 =r;
    int tringle2=40;
    GLfloat tp2 =2.0f * PI  ;
    glBegin (GL_TRIANGLE_FAN);
    if(c==1)
    {
		if(mode==3){
			glColor3ub (249, 116, 7);
		}
       else{
	   	glColor3ub ( 70, 52, 216);
	   }
    }
    if(c==2)
    {
		if(mode==3){
			glColor3ub (249, 116, 7);
		}
        else{
		glColor3ub ( 86, 71, 221);
		}
    }
    if(c==3)
    {

         if(mode==3){
		 	glColor3ub (  255, 255, 255);
		 }else{
		 	glColor3ub ( 255, 255, 255);
		 }
    }

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

void CallStarEvening()
{

     star(-0.98f,0.98f,0.006f,1);  //last 1 for moon count
       star(-0.98f,0.98f,0.005f,2); //      2 ,,
       star(-0.98f,0.98f,0.005f,3);


       star(-0.95f,0.95f,0.006f,1);  //last 1 for moon count
       star(-0.95f,0.95f,0.005f,2); //      2 ,,
       star(-0.95f,0.95f,0.005f,3);

    star(0.0f,-0.18f,0.004f,1);  //last 1 for moon count
       star(0.0f,-0.18f,0.003f,2); //      2 ,,
       star(0.0f,-0.18f,0.002f,3);


      star(0.01f,-0.05f,0.004f,1);  //last 1 for moon count
       star(0.01f,-0.05f,0.003f,2); //      2 ,,
       star(0.01f,-0.05f,0.002f,3);

        star(0.1f,0.01f,0.004f,1);  //last 1 for moon count
       star(0.1f,0.01f,0.003f,2); //      2 ,,
       star(0.1f,0.01f,0.002f,3);

        star(-0.05f,0.12f,0.004f,1);  //last 1 for moon count
       star(-0.05f,0.12f,0.003f,2); //      2 ,,
       star(-0.05f,0.12f,0.001f,3);

  star(-0.6f,0.8f,0.004f,1);  //last 1 for moon count
       star(- 0.6f,0.8f,0.003f,2); //      2 ,,
       star(-0.6f,0.8f,0.002f,3);



 star(0.1f,0.1f,0.002f,3);
       star(0.15f,0.15f,0.002f,3);
      star(0.16,0.2f,0.002f,3);
       star(0.18f,0.25f,0.002f,3);
       star(-0.1f,0.3f,0.002f,3);
       star(-0.15f,0.35f,0.002f,3);
      star(-0.17f,0.45f,0.002f,3);
       star(0.3f,0.55f,0.002f,3);
       star(-0.35f,0.65f,0.002f,3);
      star(-0.15f,0.75f,0.002f,3);
//
star(-0.5f,0.1f,0.002f,3);
   star(-0.6f,0.15f,0.002f,3);
 star(-0.7f,0.2f,0.002f,3);
 star(-0.8f,0.25f,0.002f,3);
star(-0.9f,0.3f,0.002f,3);
star(-0.55f,0.35f,0.002f,3);
star(-0.765f,0.45f,0.002f,3);
star(-0.65f,0.55f,0.002f,3);
star(-0.88f,0.65f,0.002f,3);
star(-0.8f,0.75f,0.002f,3);

       //
      star(0.7f,0.3f,0.004f,1);  //last 1 for moon count
   star(0.7f,0.3f,0.003f,2); //      2 ,,
     star(0.7f,0.3f,0.002f,3);


     star(0.75f,0.2f,0.004f,1);  //last 1 for moon count
  star(0.7f,0.2f,0.003f,2); //      2 ,,
star(0.75f,0.2f,0.002f,3);

       star(0.8f,0.25f,0.004f,1);  //last 1 for moon count
      star(0.8f,0.25f,0.003f,2); //      2 ,,
    star(0.8f,0.25f,0.002f,3);


       //

         star(-0.95f,0.05f,0.008f,1);  //last 1 for moon count
      star(-0.95f,0.05f,0.006f,2); //      2 ,,
       star(-0.95f,0.05f,0.004f,3);


       star(-0.85f,0.08f,0.008f,1);  //last 1 for moon count
      star(-0.85f,0.08f,0.006f,2); //      2 ,,
      star(-0.85f,0.08f,0.004f,3);


       star(- 0.7f,0.1f,0.008f,1);  //last 1 for moon count
 star(-0.7f,0.1f,0.006f,2); //      2 ,,
    star(-0.7f,0.1f,0.004f,3);


  star(-0.65f,0.2f,0.008f,1);  //last 1 for moon count
star(-0.65f,0.2f,0.006f,2); //      2 ,,
    star(-0.65f,0.2f,0.004f,3);



       //

   star(0.5f,0.1f,0.002f,3);
     star(0.6f,0.15f,0.002f,3);
   star(0.7f,0.2f,0.002f,3);
star(0.8f,0.25f,0.002f,3);
    star(0.9f,0.3f,0.002f,3);
   star(0.55f,0.35f,0.002f,3);
 star(0.765f,0.45f,0.002f,3);
      star(0.65f,0.55f,0.002f,3);
      star(0.88f,0.65f,0.002f,3);
       star(0.8f,0.75f,0.002f,3);

star(0.7f,0.3f,0.004f,1);  //last 1 for moon count
      star(0.7f,0.3f,0.003f,2); //      2 ,,
       star(0.7f,0.3f,0.002f,3);


     star(0.75f,0.2f,0.004f,1);  //last 1 for moon count
       star(0.7f,0.2f,0.003f,2); //      2 ,,
     star(0.75f,0.2f,0.002f,3);

        star(0.8f,0.25f,0.004f,1);  //last 1 for moon count
      star(0.8f,0.25f,0.003f,2); //      2 ,,
     star(0.8f,0.25f,0.002f,3);

      star(0.65f,0.1f,0.004f,1);  //last 1 for moon count
       star(0.65f,0.1f,0.003f,2); //      2 ,,
       star(0.65f,0.1f,0.002f,3);

       star(0.85f,0.15f,0.004f,1);  //last 1 for moon count
       star(0.85f,0.15f,0.003f,2); //      2 ,,
       star(0.85f,0.15f,0.002f,3);

 star(0.2f,-0.18f,0.008f,1);  //last 1 for moon count
       star(0.2f,-0.18f,0.006f,2); //      2 ,,
       star(0.2f,-0.18f,0.004f,3);


     star(0.3f,-0.05f,0.008f,1);  //last 1 for moon count
       star(0.3f,-0.05f,0.006f,2); //      2 ,,
       star(0.3f,-0.05f,0.004f,3);

       star(0.3f,0.01f,0.008f,1);  //last 1 for moon count
      star(0.3f,0.01f,0.006f,2); //      2 ,,
       star(0.3f,0.01f,0.004f,3);

       star(0.1f,0.12f,0.008f,1);  //last 1 for moon count
       star(0.1f,0.12f,0.006f,2); //      2 ,,
      star(0.1f,0.12f,0.004f,3);

        star(0.6f,0.1f,0.008f,1);  //last 1 for moon count
       star(0.6f,0.1f,0.006f,2); //      2 ,,
       star(0.6f,0.1f,0.004f,3);

       //
        star(0.2f,0.8f,0.008f,1);  //last 1 for moon count
       star(0.2f,0.8f,0.006f,2); //      2 ,,
       star(0.2f,0.8f,0.004f,3);


     star(0.33f,0.5f,0.008f,1);  //last 1 for moon count
       star(0.33f,0.5f,0.006f,2); //      2 ,,
      star(0.33f,0.5f,0.004f,3);

        star(0.3f,0.7f,0.008f,1);  //last 1 for moon count
      star(0.3f,0.7f,0.006f,2); //      2 ,,
       star(0.3f,0.7f,0.004f,3);

        star(0.4f,0.8f,0.008f,1);  //last 1 for moon count
      star(0.4f,0.8f,0.006f,2); //      2 ,,
       star(0.4f,0.8f,0.004f,3);

        star(0.45f,0.75f,0.008f,1);  //last 1 for moon count
      star(0.45f,0.75f,0.006f,2); //      2 ,,
       star(0.45f,0.75f,0.004f,3);

       //
      star(0.9f,0.8f,0.008f,1);  //last 1 for moon count
       star(0.9f,0.8f,0.006f,2); //      2 ,,
      star(0.9f,0.8f,0.004f,3);


   star(0.95f,0.5f,0.008f,1);  //last 1 for moon count
star(0.95f,0.5f,0.006f,2); //      2 ,,
  star(0.95f,0.5f,0.004f,3);

star(0.8f,0.7f,0.008f,1);  //last 1 for moon count
    star(0.8f,0.7f,0.006f,2); //      2 ,,
    star(0.8f,0.7f,0.004f,3);

    star(0.65f,0.8f,0.008f,1);  //last 1 for moon count
star(0.65f,0.8f,0.006f,2); //      2 ,,
   star(0.65f,0.8f,0.004f,3);

 star(0.75f,0.75f,0.008f,1);  //last 1 for moon count
star(0.75f,0.75f,0.006f,2); //      2 ,,
  star(0.75f,0.75f,0.004f,3);
star(0.20f,0.60f,0.008f,1);  //last 1 for moon count
  star(0.20f,0.60f,0.006f,2); //      2 ,,
   star(0.20f,0.60f,0.004f,3);

star(0.25f,0.62f,0.008f,1);  //last 1 for moon count
star(0.250f,0.62f,0.006f,2); //      2 ,,
  star(0.25f,0.62f,0.004f,3);

star(0.3f,0.42f,0.008f,1);  //last 1 for moon count
star(0.30f,0.42f,0.006f,2); //      2 ,,
star(0.30f,0.42f,0.004f,3);

star(0.35f,0.7f,0.008f,1);  //last 1 for moon count
star(0.35f,0.7f,0.006f,2); //      2 ,,
star(0.35f,0.7f,0.004f,3);
       //
star(0.20f,0.30f,0.008f,1);  //last 1 for moon count
star(0.20f,0.30f,0.006f,2); //      2 ,,
star(0.20f,0.30f,0.004f,3);

star(0.15f,0.42f,0.008f,1);  //last 1 for moon count
star(0.150f,0.42f,0.006f,2); //      2 ,,
star(0.15f,0.42f,0.004f,3);

star(0.1f,0.42f,0.008f,1);  //last 1 for moon count
star(0.1f,0.42f,0.006f,2); //      2 ,,
star(0.1f,0.42f,0.004f,3);

star(0.3f,0.3f,0.008f,1);  //last 1 for moon count
star(0.3f,0.3f,0.006f,2); //      2 ,,
star(0.3f,0.3f,0.004f,3);
//

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

    int x,y,z;
    if(mode==0){
     x=192;
     y=192;
     z=192;
    }
    else if(mode==1){
    x=12;
    y=4;
    z=70;
    }
else if(mode==3){
	x=94;
	y=40;
	z=34;

}
    else {
     x=192;
     y=192;
     z=192;
   }


            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(x,y,z);
            glVertex2f(-0.77f, -0.22);
            glVertex2f(-0.65f, -0.22f);
            glVertex2f(-0.7f, 0.005f);

            glEnd();

            glBegin(GL_TRIANGLE_FAN);
           glColor3ub(x,y,z);
            glVertex2f(-0.75f, -0.22);
            glVertex2f(-0.5f, -0.22f);
            glVertex2f(-0.6f, -0.09f);

            glEnd();


           glBegin(GL_TRIANGLE_FAN);
           glColor3ub(x,y,z);
            glVertex2f(-0.9f, -0.22);
            glVertex2f(-0.7f, -0.22f);
            glVertex2f(-0.8f, -0.03f);

            glEnd();

            glBegin(GL_TRIANGLE_FAN);
           glColor3ub(x,y,z);
            glVertex2f(-1.055f, -0.22);
            glVertex2f(-0.8f, -0.22f);
            glVertex2f(-0.9f, 0.06f);
            glEnd();


            //right hill


            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(x,y,z);
            glVertex2f(0.75f, -0.22);
            glVertex2f(0.5f, -0.22f);
            glVertex2f(0.6f, -0.09f);

            glEnd();


           glBegin(GL_TRIANGLE_FAN);
             glColor3ub(x,y,z);
            glVertex2f(0.9f, -0.22);
            glVertex2f(0.7f, -0.22f);
            glVertex2f(0.8f, -0.03f);

            glEnd();

            glBegin(GL_TRIANGLE_FAN);
           glColor3ub(x,y,z);
            glVertex2f(1.1f, -0.22);
            glVertex2f(0.8f, -0.22f);
            glVertex2f(0.9f, 0.06f);
            glEnd();


}


void DrawRiver(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4)
{



    glBegin(GL_QUADS);

    if(mode==0){
     glColor3ub(1, 127, 129);
   }
    else if(mode==1){
         glColor3ub(22, 18, 78);
    }else if(mode==2){
            glColor3ub(81, 54, 62);
    }else if(mode==3){
		 glColor3ub(198, 53, 35);

	}
    else{
        glColor3ub(1, 127, 129);
    }

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
      mode=1;
      sunposition=-1.2f;
      sunset=0;
      glutPostRedisplay();
    }

    if(key=='D')
    {
      mode=0;
      sunposition=0.0f;
      sunset=1;
      glutPostRedisplay();
    }

   if(key=='E')
    {
      mode=3;
      glutPostRedisplay();
    }

    if(key=='P'){
        pinak=true;
        glutPostRedisplay();
    }
	if(key=='R'){

		trafficmode=1;
	}

	if(key=='G'){
		trafficmode=0;
		Busspeed=0.009f;
		Carspeed=0.010f;
	}
	if(key=='Y'){
		Busspeed=0.002f;
		Carspeed=0.002F;
		trafficmode=2;
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
      case GLUT_KEY_UP:
		  sunset=1;
          break;
      case GLUT_KEY_DOWN:
		  sunset=0;
          break;
    }
}


void bridgespanpiller(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4)
{

glBegin(GL_QUADS);
if(mode==3){
	  glColor3ub(142, 28, 42);
}
else{
	glColor3ub(105,105,105);
}
glVertex2f(x1,y1);
glVertex2f(x2,y2);
glVertex2f(x3,y3);
glVertex2f(x4,y4);
glEnd();

}

void bridgelightOn(){

        glLineWidth(5);
        glBegin(GL_LINES);
        glColor3ub(246, 226, 86);
        glVertex2f(-0.9f,  0.39f);
        glVertex2f(-0.88f, 0.39f);
        glEnd();


        glLineWidth(4);
        glBegin(GL_LINES);
         glColor3ub(246, 226, 86);
        glVertex2f(-0.85f,  0.39f);
        glVertex2f(-0.87f, 0.39f);
        glEnd();



}

void bridgeLight(){
int x,y,z;
if(mode==3){
	// glColor3ub(142, 28, 42);
	x=142;
	y=28;
	z=42;
}else{
	x=105;
	y=105;
	z=105;
}

        glLineWidth(4); //line in boat 1
        glBegin(GL_LINES);
        glColor3ub(x,y,z);
        glVertex2f(-0.9f, 0.2f);
        glVertex2f(-0.9f, 0.4f);
        glEnd();

        glLineWidth(4); //line in boat 1
        glBegin(GL_LINES);
       glColor3ub(x,y,z);
        glVertex2f(-0.9f,  0.4f);
        glVertex2f(-0.88f, 0.4f);
        glEnd();

        glLineWidth(4); //line in boat 1
        glBegin(GL_LINES);
		glColor3ub(x,y,z);
        glVertex2f(-0.85f, 0.2f);
        glVertex2f(-0.85f, 0.4f);
        glEnd();

        glLineWidth(4); //line in boat 1
        glBegin(GL_LINES);
    glColor3ub(x,y,z);
        glVertex2f(-0.85f,  0.4f);
        glVertex2f(-0.87f, 0.4f);
        glEnd();


        if(mode==1){
            bridgelightOn();
        }
}




void Bridge(){
int x,y,z;
if(mode==3){
	// glColor3ub(142, 28, 42);
	x=142;
	y=28;
	z=42;
}else{
	x=105;
	y=105;
	z=105;
}



glBegin(GL_QUADS);
glColor3ub(x,y,z);
glVertex2f(-1.0f,-0.05f);
glVertex2f(1.0f,-0.05f);
glVertex2f(1.0f,0.0f);
glVertex2f(-1.0f,0.0f);





glEnd();
glBegin(GL_QUADS);
glColor3ub(x,y,z);
glVertex2f(-1.0f,0.2f);
glVertex2f(1.0f,0.2f);
glVertex2f(1.0f,0.25f);
glVertex2f(-1.0f,0.25f);
glEnd();
glFlush();



//Bridge Pillers



glBegin(GL_QUADS);
glColor3ub(x,y,z);
glVertex2f(-0.55f,-0.2f);
glVertex2f(-0.45f,-0.2f);
glVertex2f(-0.45f,0.0f);
glVertex2f(-0.55f,0.0f);
glEnd();



glBegin(GL_QUADS);
glColor3ub(x,y,z);
glVertex2f(0.55f,-0.2f);
glVertex2f(0.45f,-0.2f);
glVertex2f(0.45f,0.0f);
glVertex2f(0.55f,0.0f);
glEnd();




glBegin(GL_QUADS);
glColor3ub(x,y,z);
glVertex2f(-0.6f,-0.22f);
glVertex2f(-0.4f,-0.22f);
glVertex2f(-0.4f,-0.15f);
glVertex2f(-0.6f,-0.15f);
glEnd();
glFlush();




glBegin(GL_QUADS);
glColor3ub(x,y,z);
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

void drawBoatThunderstormSky()
{
// right mid boat 2

glPushMatrix();
glTranslatef(rboatthpos,0.0f,0.0f);
          glBegin(GL_TRIANGLE_FAN); // right mid in boat 2
            glColor3ub(0, 0, 0);
            glVertex2f(0.92f, -0.55f);
            glVertex2f(0.76f, -0.55f);
            glVertex2f(0.74f, -0.50f);
            glVertex2f(0.92f, -0.50f);
            glEnd();





          glBegin(GL_TRIANGLE_FAN);  ////boat 2 left pall
          glColor3ub(255, 255, 255);
          glVertex2f(0.92f, -0.50f);
          glVertex2f(0.84f, -0.50f);
          glVertex2f(0.84f, -0.43f);
          glVertex2f(0.92f, -0.43f);
          glEnd();


          glLineWidth(8); //
          glBegin(GL_LINES);
          glColor3ub(255, 0, 0);
          glVertex2f(0.88f, -0.44f);
          glVertex2f(0.88f, -0.49f);
          glEnd();


          glLineWidth(8); //
          glBegin(GL_LINES);
          glColor3ub(255, 0, 0);
          glVertex2f(0.90f, -0.47f);
          glVertex2f(0.86f, -0.47f);
          glEnd();


          glPopMatrix();



          glPushMatrix();
glTranslatef(lboatthpos,0.0f,0.0f);

            glBegin(GL_TRIANGLE_FAN); //  left up in boat 1
            glColor3ub(0, 0, 0);
            glVertex2f(-0.92f, -0.65f);
            glVertex2f(-0.77f, -0.65f);
            glVertex2f(-0.75f, -0.60f);
            glVertex2f(-0.92f, -0.60f);
            glEnd();


          glBegin(GL_QUADS);
          glColor3ub(255, 255, 255);
          glVertex2f(-0.92f, -0.60f);
          glVertex2f(-0.82f, -0.60f);
          glVertex2f(-0.82f, -0.53f);
           glVertex2f(-0.92f, -0.53f);
          glEnd();

          glLineWidth(8); //
          glBegin(GL_LINES);
          glColor3ub(255, 0, 0);
          glVertex2f(-0.87f, -0.54f);
          glVertex2f(-0.87f, -0.59f);
          glEnd();

          glLineWidth(8); //
          glBegin(GL_LINES);
          glColor3ub(255, 0, 0);
          glVertex2f(-0.89f, -0.57f);
          glVertex2f(-0.85f, -0.57f);
          glEnd();

glPopMatrix();
}

void Train()
{
    int x,y,z;


 if(mode==1){
    x=249;y=234,z=122;
}else{
	 x=255;
    y=255;
    z=255;
}

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
        glColor3ub(x,y,z);
        glVertex2f(-0.96f,0.045f);
        glVertex2f(-0.93f,0.045f);
        glVertex2f(-0.93f,0.075f);
        glVertex2f(-0.96f,0.075f);

        glEnd();


          glBegin(GL_QUADS);
        glColor3ub(x,y,z);
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
        glColor3ub(x,y,z);
        glVertex2f(-0.81f,0.045f);
        glVertex2f(-0.78f,0.045f);
        glVertex2f(-0.78f,0.075f);
        glVertex2f(-0.81f,0.075f);

        glEnd();


          glBegin(GL_QUADS);
           glColor3ub(x,y,z);
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
          glColor3ub(x,y,z);
        glVertex2f(-0.66f,0.045f);
        glVertex2f(-0.63f,0.045f);
        glVertex2f(-0.63f,0.075f);
        glVertex2f(-0.66f,0.075f);

        glEnd();


          glBegin(GL_QUADS);
          glColor3ub(x,y,z);
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

int x,y,z;
if(mode==0){
    x=255;
    y=255;
    z=255;
}
else if(mode==1){
    x=70;
    y=65;
    z=202;
}else if(mode==2){
    x=0;
    y=0;
    z=0;

}else if(mode==3){
	 x=107;
	 y=19;
	 z=24;
}
else{
    x=255;
    y=255;
    z=255;
}




glPushMatrix();
glTranslatef(lboatpos,0.0f,0.0f);


drawRiverElipsis(-0.88f,-0.35f,0.11f,0.015f);
drawRiverElipsis(-0.83f,-0.850f,0.11f,0.015f);


        glBegin(GL_TRIANGLE_FAN); //  left up in boat 1
            glColor3ub(x,y,z);
            glVertex2f(-0.92f, -0.35f);
            glVertex2f(-0.82f, -0.35f);
            glVertex2f(-0.77f, -0.30f);
            glVertex2f(-0.97f, -0.30f);
            glEnd();


        glLineWidth(8); //line in boat 1
        glBegin(GL_LINES);
       glColor3ub(x,y,z);
        glVertex2f(-0.87f, -0.29f);
        glVertex2f(-0.87f, -0.23f);
        glEnd();

          glBegin(GL_TRIANGLE_FAN);  //boat 1 right pall
          glColor3ub(x,y,z);
          glVertex2f(-0.86f, -0.29f);
          glVertex2f(-0.80f, -0.29f);
          glVertex2f(-0.86f, -0.24f);
          glEnd();


          glBegin(GL_TRIANGLE_FAN);  ////boat 1 left pall
          glColor3ub(x,y,z);
          glVertex2f(-0.92f, -0.29f);
          glVertex2f(-0.88f, -0.29f);
          glVertex2f(-0.88f, -0.23f);
          glEnd();


          //Down Left Boat

           glBegin(GL_TRIANGLE_FAN); //  left down in boat 1
           glColor3ub(x,y,z);
            glVertex2f(-0.88f, -0.85f);
            glVertex2f(-0.78f, -0.85f);
            glVertex2f(-0.73f, -0.80f);
            glVertex2f(-0.93f, -0.80f);
            glEnd();


        glLineWidth(8); //line in boat 1
        glBegin(GL_LINES);
        glColor3ub(x,y,z);
        glVertex2f(-0.86f, -0.79f);
        glVertex2f(-0.86f, -0.73f);
        glEnd();

         glBegin(GL_LINES);
        glColor3ub(x,y,z);
        glVertex2f(-0.88f, -0.79f);
        glVertex2f(-0.88f, -0.73f);
        glEnd();

          glBegin(GL_TRIANGLE_FAN);  //boat 1 right pall
         glColor3ub(x,y,z);
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
            glColor3ub(x,y,z);
            glVertex2f(0.92f, -0.55f);
            glVertex2f(0.82f, -0.55f);
            glVertex2f(0.77f, -0.50f);
            glVertex2f(0.97f, -0.50f);
            glEnd();


        glLineWidth(8); //line in boat 2
        glBegin(GL_LINES);
       glColor3ub(x,y,z);
        glVertex2f(0.87f, -0.49f);
        glVertex2f(0.87f, -0.43f);
        glEnd();

          glBegin(GL_TRIANGLE_FAN);  //boat 2 right pall
         glColor3ub(x,y,z);
          glVertex2f(0.86f, -0.49f);
          glVertex2f(0.80f, -0.49f);
          glVertex2f(0.86f, -0.43f);
          glEnd();


          glBegin(GL_TRIANGLE_FAN);  ////boat 2 left pall
         glColor3ub(x,y,z);
          glVertex2f(0.92f, -0.49f);
          glVertex2f(0.88f, -0.49f);
          glVertex2f(0.88f, -0.43f);
          glEnd();

glPopMatrix();

}

void CallStar()
{

     star(-0.98f,0.98f,0.008f,1);  //last 1 for moon count
       star(-0.98f,0.98f,0.006f,2); //      2 ,,
       star(-0.98f,0.98f,0.004f,3);


       star(-0.95f,0.95f,0.008f,1);  //last 1 for moon count
       star(-0.95f,0.95f,0.006f,2); //      2 ,,
       star(-0.95f,0.95f,0.004f,3);

       star(-0.98f,0.95f,0.008f,1);  //last 1 for moon count
       star(-0.98f,0.95f,0.006f,2); //      2 ,,
       star(-0.98f,0.95f,0.004f,3);


       star(-0.90f,0.90f,0.008f,1);  //last 1 for moon count
       star(-0.90f,0.90f,0.006f,2); //      2 ,,
       star(-0.90f,0.90f,0.004f,3);

       star(-0.7f,0.90f,0.008f,1);  //last 1 for moon count
       star(-0.70f,0.90f,0.006f,2); //      2 ,,
       star(-0.70f,0.90f,0.004f,3);

        star(-0.7f,0.70f,0.008f,1);  //last 1 for moon count
       star(-0.70f,0.70f,0.006f,2); //      2 ,,
       star(-0.70f,0.70f,0.004f,3);


        star(-0.8f,0.70f,0.008f,1);  //last 1 for moon count
       star(-0.80f,0.70f,0.006f,2); //      2 ,,
       star(-0.80f,0.70f,0.004f,3);

       //
       star(-0.90f,0.60f,0.008f,1);  //last 1 for moon count
       star(-0.90f,0.60f,0.006f,2); //      2 ,,
       star(-0.90f,0.60f,0.004f,3);

       star(-0.7f,0.60f,0.008f,1);  //last 1 for moon count
       star(-0.70f,0.60f,0.006f,2); //      2 ,,
       star(-0.70f,0.60f,0.004f,3);

        star(-0.7f,0.40f,0.008f,1);  //last 1 for moon count
       star(-0.70f,0.40f,0.006f,2); //      2 ,,
       star(-0.70f,0.40f,0.004f,3);

       star(-0.85f,0.60f,0.008f,1);  //last 1 for moon count
       star(-0.85f,0.60f,0.006f,2); //      2 ,,
       star(-0.85f,0.60f,0.004f,3);

       //

       star(-0.20f,0.60f,0.008f,1);  //last 1 for moon count
       star(-0.20f,0.60f,0.006f,2); //      2 ,,
       star(-0.20f,0.60f,0.004f,3);

       star(-0.25f,0.62f,0.008f,1);  //last 1 for moon count
       star(-0.250f,0.62f,0.006f,2); //      2 ,,
       star(-0.25f,0.62f,0.004f,3);

        star(-0.3f,0.42f,0.008f,1);  //last 1 for moon count
       star(-0.30f,0.42f,0.006f,2); //      2 ,,
       star(-0.30f,0.42f,0.004f,3);

       star(-0.35f,0.7f,0.008f,1);  //last 1 for moon count
       star(-0.35f,0.7f,0.006f,2); //      2 ,,
       star(-0.35f,0.7f,0.004f,3);


       //
        star(0.20f,0.60f,0.008f,1);  //last 1 for moon count
       star(0.20f,0.60f,0.006f,2); //      2 ,,
       star(0.20f,0.60f,0.004f,3);

       star(0.25f,0.62f,0.008f,1);  //last 1 for moon count
       star(0.250f,0.62f,0.006f,2); //      2 ,,
       star(0.25f,0.62f,0.004f,3);

        star(0.3f,0.42f,0.008f,1);  //last 1 for moon count
       star(0.30f,0.42f,0.006f,2); //      2 ,,
       star(0.30f,0.42f,0.004f,3);

       star(0.35f,0.7f,0.008f,1);  //last 1 for moon count
       star(0.35f,0.7f,0.006f,2); //      2 ,,
       star(0.35f,0.7f,0.004f,3);
       //
        star(0.20f,0.30f,0.008f,1);  //last 1 for moon count
       star(0.20f,0.30f,0.006f,2); //      2 ,,
       star(0.20f,0.30f,0.004f,3);

       star(0.15f,0.42f,0.008f,1);  //last 1 for moon count
       star(0.150f,0.42f,0.006f,2); //      2 ,,
       star(0.15f,0.42f,0.004f,3);

        star(0.1f,0.42f,0.008f,1);  //last 1 for moon count
       star(0.1f,0.42f,0.006f,2); //      2 ,,
       star(0.1f,0.42f,0.004f,3);

       star(0.3f,0.3f,0.008f,1);  //last 1 for moon count
       star(0.3f,0.3f,0.006f,2); //      2 ,,
       star(0.3f,0.3f,0.004f,3);
//



       star(0.98f,0.7f,0.008f,1);  //last 1 for moon count
       star(0.98f,0.7f,0.006f,2); //      2 ,,
       star(0.98f,0.77,0.004f,3);


       star(0.95f,0.95f,0.008f,1);  //last 1 for moon count
       star(0.95f,0.95f,0.006f,2); //      2 ,,
       star(0.95f,0.95f,0.004f,3);

       star(0.98f,0.95f,0.008f,1);  //last 1 for moon count
       star(0.98f,0.95f,0.006f,2); //      2 ,,
       star(0.98f,0.95f,0.004f,3);


       star(0.90f,0.90f,0.008f,1);  //last 1 for moon count
       star(0.90f,0.90f,0.006f,2); //      2 ,,
       star(0.90f,0.90f,0.004f,3);

       star(0.7f,0.90f,0.008f,1);  //last 1 for moon count
       star(0.70f,0.90f,0.006f,2); //      2 ,,
       star(0.70f,0.90f,0.004f,3);

        star(0.7f,0.70f,0.008f,1);  //last 1 for moon count
       star(0.70f,0.70f,0.006f,2); //      2 ,,
       star(0.70f,0.70f,0.004f,3);


        star(0.8f,0.70f,0.008f,1);  //last 1 for moon count
       star(0.80f,0.70f,0.006f,2); //      2 ,,
       star(0.80f,0.70f,0.004f,3);

       star(0.9f,0.5f,0.008f,1);  //last 1 for moon count
       star(0.9f,0.5f,0.006f,2); //      2 ,,
       star(0.9f,0.5f,0.004f,3);
//
       star(0.98f,0.55f,0.008f,1);  //last 1 for moon count
       star(0.98f,0.55f,0.006f,2); //      2 ,,
       star(0.98f,0.55f,0.004f,3);


       star(0.55f,0.24f,0.008f,1);  //last 1 for moon count
       star(0.55f,0.24f,0.006f,2); //      2 ,,
       star(0.55f,0.24f,0.004f,3);

       star(0.48f,0.1f,0.008f,1);  //last 1 for moon count
       star(0.48f,0.1f,0.006f,2); //      2 ,,
       star(0.48f,0.1f,0.004f,3);


       star(0.90f,0.15f,0.008f,1);  //last 1 for moon count
       star(0.90f,0.15f,0.006f,2); //      2 ,,
       star(0.90f,0.15f,0.004f,3);

       star(0.7f,0.12f,0.008f,1);  //last 1 for moon count
       star(0.70f,0.12f,0.006f,2); //      2 ,,
       star(0.70f,0.12f,0.004f,3);

        star(0.7f,0.05f,0.008f,1);  //last 1 for moon count
       star(0.70f,0.05f,0.006f,2); //      2 ,,
       star(0.70f,0.05f,0.004f,3);


        star(0.8f,0.01f,0.008f,1);  //last 1 for moon count
       star(0.80f,0.01f,0.006f,2); //      2 ,,
       star(0.80f,0.01f,0.004f,3);

       star(0.85f,0.055f,0.008f,1);  //last 1 for moon count
       star(0.85f,0.055f,0.006f,2); //      2 ,,
       star(0.85f,0.055f,0.004f,3);

       //
       star(-0.5f,-0.1f,0.008f,1);  //last 1 for moon count
       star(-0.5f,-0.1f,0.006f,2); //      2 ,,
       star(-0.5f,-0.1f,0.004f,3);


      star(-0.5f,-0.15f,0.008f,1);  //last 1 for moon count
       star(-0.5f,-0.15f,0.006f,2); //      2 ,,
       star(-0.5f,-0.15f,0.004f,3);

        star(-0.3f,-0.1f,0.008f,1);  //last 1 for moon count
       star(-0.3f,-0.1f,0.006f,2); //      2 ,,
       star(-0.3f,-0.1f,0.004f,3);

        star(-0.1f,-0.12f,0.008f,1);  //last 1 for moon count
       star(-0.1f,-0.12f,0.006f,2); //      2 ,,
       star(-0.1f,-0.12f,0.004f,3);

        star(0.5f,-0.1f,0.008f,1);  //last 1 for moon count
       star(0.5f,-0.1f,0.006f,2); //      2 ,,
       star(0.5f,-0.1f,0.004f,3);

       //
       star(0.2f,-0.18f,0.008f,1);  //last 1 for moon count
       star(0.2f,-0.18f,0.006f,2); //      2 ,,
       star(0.2f,-0.18f,0.004f,3);


      star(0.3f,-0.05f,0.008f,1);  //last 1 for moon count
       star(0.3f,-0.05f,0.006f,2); //      2 ,,
       star(0.3f,-0.05f,0.004f,3);

        star(0.3f,0.01f,0.008f,1);  //last 1 for moon count
       star(0.3f,0.01f,0.006f,2); //      2 ,,
       star(0.3f,0.01f,0.004f,3);

        star(0.1f,0.12f,0.008f,1);  //last 1 for moon count
       star(0.1f,0.12f,0.006f,2); //      2 ,,
       star(0.1f,0.12f,0.004f,3);

        star(0.6f,0.1f,0.008f,1);  //last 1 for moon count
       star(0.6f,0.1f,0.006f,2); //      2 ,,
       star(0.6f,0.1f,0.004f,3);

       //
        star(0.2f,0.8f,0.008f,1);  //last 1 for moon count
       star(0.2f,0.8f,0.006f,2); //      2 ,,
       star(0.2f,0.8f,0.004f,3);


      star(0.33f,0.5f,0.008f,1);  //last 1 for moon count
       star(0.33f,0.5f,0.006f,2); //      2 ,,
       star(0.33f,0.5f,0.004f,3);

        star(0.3f,0.7f,0.008f,1);  //last 1 for moon count
       star(0.3f,0.7f,0.006f,2); //      2 ,,
       star(0.3f,0.7f,0.004f,3);

        star(0.4f,0.8f,0.008f,1);  //last 1 for moon count
       star(0.4f,0.8f,0.006f,2); //      2 ,,
       star(0.4f,0.8f,0.004f,3);

        star(0.45f,0.75f,0.008f,1);  //last 1 for moon count
       star(0.45f,0.75f,0.006f,2); //      2 ,,
       star(0.45f,0.75f,0.004f,3);

       //
       star(0.9f,0.8f,0.008f,1);  //last 1 for moon count
       star(0.9f,0.8f,0.006f,2); //      2 ,,
       star(0.9f,0.8f,0.004f,3);


      star(0.95f,0.5f,0.008f,1);  //last 1 for moon count
       star(0.95f,0.5f,0.006f,2); //      2 ,,
       star(0.95f,0.5f,0.004f,3);

        star(0.8f,0.7f,0.008f,1);  //last 1 for moon count
       star(0.8f,0.7f,0.006f,2); //      2 ,,
       star(0.8f,0.7f,0.004f,3);

        star(0.65f,0.8f,0.008f,1);  //last 1 for moon count
       star(0.65f,0.8f,0.006f,2); //      2 ,,
       star(0.65f,0.8f,0.004f,3);

        star(0.75f,0.75f,0.008f,1);  //last 1 for moon count
       star(0.75f,0.75f,0.006f,2); //      2 ,,
       star(0.75f,0.75f,0.004f,3);



       //nnm
        star(-0.2f,-0.18f,0.008f,1);  //last 1 for moon count
       star(-0.2f,-0.18f,0.006f,2); //      2 ,,
       star(-0.2f,-0.18f,0.004f,3);


      star(-0.3f,-0.05f,0.008f,1);  //last 1 for moon count
       star(-0.3f,-0.05f,0.006f,2); //      2 ,,
       star(-0.3f,-0.05f,0.004f,3);

        star(-0.3f,0.01f,0.008f,1);  //last 1 for moon count
       star(-0.3f,0.01f,0.006f,2); //      2 ,,
       star(-0.3f,0.01f,0.004f,3);

        star(-0.1f,0.12f,0.008f,1);  //last 1 for moon count
       star(-0.1f,0.12f,0.006f,2); //      2 ,,
       star(-0.1f,0.12f,0.004f,3);

        star(-0.6f,0.1f,0.008f,1);  //last 1 for moon count
       star(-0.6f,0.1f,0.006f,2); //      2 ,,
       star(-0.6f,0.1f,0.004f,3);

       //
        star(-0.2f,0.8f,0.008f,1);  //last 1 for moon count
       star(-0.2f,0.8f,0.006f,2); //      2 ,,
       star(-0.2f,0.8f,0.004f,3);


      star(-0.33f,0.5f,0.008f,1);  //last 1 for moon count
       star(-0.33f,0.5f,0.006f,2); //      2 ,,
       star(-0.33f,0.5f,0.004f,3);

        star(-0.3f,0.7f,0.008f,1);  //last 1 for moon count
       star(-0.3f,0.7f,0.006f,2); //      2 ,,
       star(-0.3f,0.7f,0.004f,3);

        star(-0.4f,0.8f,0.008f,1);  //last 1 for moon count
       star(-0.4f,0.8f,0.006f,2); //      2 ,,
       star(-0.4f,0.8f,0.004f,3);

        star(-0.45f,0.75f,0.008f,1);  //last 1 for moon count
       star(-0.45f,0.75f,0.006f,2); //      2 ,,
       star(-0.45f,0.75f,0.004f,3);

       //
       star(-0.9f,0.8f,0.008f,1);  //last 1 for moon count
       star(-0.9f,0.8f,0.006f,2); //      2 ,,
       star(-0.9f,0.8f,0.004f,3);


      star(-0.95f,0.5f,0.008f,1);  //last 1 for moon count
       star(-0.95f,0.5f,0.006f,2); //      2 ,,
       star(-0.95f,0.5f,0.004f,3);

        star(-0.8f,0.7f,0.008f,1);  //last 1 for moon count
       star(-0.8f,0.7f,0.006f,2); //      2 ,,
       star(-0.8f,0.7f,0.004f,3);

        star(-0.65f,0.8f,0.008f,1);  //last 1 for moon count
       star(-0.65f,0.8f,0.006f,2); //      2 ,,
       star(-0.65f,0.8f,0.004f,3);

        star(-0.75f,0.75f,0.008f,1);  //last 1 for moon count
       star(-0.75f,0.75f,0.006f,2); //      2 ,,
       star(-0.75f,0.75f,0.004f,3);





//small


 star(0.0f,-0.18f,0.004f,1);  //last 1 for moon count
       star(0.0f,-0.18f,0.003f,2); //      2 ,,
       star(0.0f,-0.18f,0.002f,3);


      star(0.01f,-0.05f,0.004f,1);  //last 1 for moon count
       star(0.01f,-0.05f,0.003f,2); //      2 ,,
       star(0.01f,-0.05f,0.002f,3);

        star(0.1f,0.01f,0.004f,1);  //last 1 for moon count
       star(0.1f,0.01f,0.003f,2); //      2 ,,
       star(0.1f,0.01f,0.002f,3);

        star(-0.05f,0.12f,0.004f,1);  //last 1 for moon count
       star(-0.05f,0.12f,0.003f,2); //      2 ,,
       star(-0.05f,0.12f,0.001f,3);

        star(0.06f,0.1f,0.004f,1);  //last 1 for moon count
       star(0.06f,0.1f,0.003f,2); //      2 ,,
       star(0.06f,0.1f,0.002f,3);

       //
        star(-0.6f,0.8f,0.004f,1);  //last 1 for moon count
       star(- 0.6f,0.8f,0.003f,2); //      2 ,,
       star(-0.6f,0.8f,0.002f,3);


      star(-0.7f,0.56f,0.004f,1);  //last 1 for moon count
       star(-0.7f,0.56f,0.003f,2); //      2 ,,
       star(-0.7f,0.56f,0.002f,3);

        star(-0.8f,0.78f,0.004f,1);  //last 1 for moon count
       star(-0.8f,0.78f,0.003f,2); //      2 ,,
       star(-0.8f,0.78f,0.002f,3);

        star(-0.75f,0.85f,0.004f,1);  //last 1 for moon count
       star(-0.75f,0.85f,0.003f,2); //      2 ,,
       star(-0.75f,0.85f,0.002f,3);

        star(-0.45f,0.7f,0.004f,1);  //last 1 for moon count
       star(-0.45f,0.7f,0.003f,2); //      2 ,,
       star(-0.45f,0.7f,0.002f,3);

       //
       star(0.7f,0.3f,0.004f,1);  //last 1 for moon count
       star(0.7f,0.3f,0.003f,2); //      2 ,,
       star(0.7f,0.3f,0.002f,3);


      star(0.75f,0.2f,0.004f,1);  //last 1 for moon count
       star(0.7f,0.2f,0.003f,2); //      2 ,,
       star(0.75f,0.2f,0.002f,3);

        star(0.8f,0.25f,0.004f,1);  //last 1 for moon count
       star(0.8f,0.25f,0.003f,2); //      2 ,,
       star(0.8f,0.25f,0.002f,3);

        star(0.65f,0.1f,0.004f,1);  //last 1 for moon count
       star(0.65f,0.1f,0.003f,2); //      2 ,,
       star(0.65f,0.1f,0.002f,3);

        star(0.85f,0.15f,0.004f,1);  //last 1 for moon count
       star(0.85f,0.15f,0.003f,2); //      2 ,,
       star(0.85f,0.15f,0.002f,3);

       star(0.0f,0.5f,0.008f,1);  //last 1 for moon count
       star(0.0f,0.5f,0.006f,2); //      2 ,,
       star(0.0f,0.5f,0.004f,3);


       star(-0.05f,0.56f,0.008f,1);  //last 1 for moon count
       star(-0.05f,0.56f,0.006f,2); //      2 ,,
       star(-0.05f,0.56f,0.004f,3);

       //

       star(0.0f,0.9f,0.008f,1);  //last 1 for moon count
       star(0.0f,0.9f,0.006f,2); //      2 ,,
       star(0.0f,0.9f,0.004f,3);


       star(-0.05f,0.95f,0.008f,1);  //last 1 for moon count
       star(-0.05f,0.95f,0.006f,2); //      2 ,,
       star(-0.05f,0.95f,0.004f,3);


       star(0.0f,0.87f,0.008f,1);  //last 1 for moon count
       star(0.0f,0.87f,0.006f,2); //      2 ,,
       star(0.0f,0.87f,0.004f,3);


       star(-0.05f,0.8f,0.008f,1);  //last 1 for moon count
       star(-0.05f,0.8f,0.006f,2); //      2 ,,
       star(-0.05f,0.8f,0.004f,3);
//
      star(-0.95f,0.05f,0.008f,1);  //last 1 for moon count
       star(-0.95f,0.05f,0.006f,2); //      2 ,,
       star(-0.95f,0.05f,0.004f,3);


       star(-0.85f,0.08f,0.008f,1);  //last 1 for moon count
       star(-0.85f,0.08f,0.006f,2); //      2 ,,
       star(-0.85f,0.08f,0.004f,3);


       star(- 0.7f,0.1f,0.008f,1);  //last 1 for moon count
       star(-0.7f,0.1f,0.006f,2); //      2 ,,
       star(-0.7f,0.1f,0.004f,3);


       star(-0.65f,0.2f,0.008f,1);  //last 1 for moon count
       star(-0.65f,0.2f,0.006f,2); //      2 ,,
       star(-0.65f,0.2f,0.004f,3);



       //

       star(0.5f,0.1f,0.002f,3);
       star(0.6f,0.15f,0.002f,3);
       star(0.7f,0.2f,0.002f,3);
       star(0.8f,0.25f,0.002f,3);
       star(0.9f,0.3f,0.002f,3);
       star(0.55f,0.35f,0.002f,3);
       star(0.765f,0.45f,0.002f,3);
       star(0.65f,0.55f,0.002f,3);
       star(0.88f,0.65f,0.002f,3);
       star(0.8f,0.75f,0.002f,3);


       //
       star(0.1f,0.1f,0.002f,3);
       star(0.15f,0.15f,0.002f,3);
       star(0.16,0.2f,0.002f,3);
       star(0.18f,0.25f,0.002f,3);
       star(-0.1f,0.3f,0.002f,3);
       star(-0.15f,0.35f,0.002f,3);
       star(-0.17f,0.45f,0.002f,3);
       star(0.3f,0.55f,0.002f,3);
       star(-0.35f,0.65f,0.002f,3);
       star(-0.15f,0.75f,0.002f,3);
//
star(-0.5f,0.1f,0.002f,3);
       star(-0.6f,0.15f,0.002f,3);
       star(-0.7f,0.2f,0.002f,3);
       star(-0.8f,0.25f,0.002f,3);
       star(-0.9f,0.3f,0.002f,3);
       star(-0.55f,0.35f,0.002f,3);
       star(-0.765f,0.45f,0.002f,3);
       star(-0.65f,0.55f,0.002f,3);
       star(-0.88f,0.65f,0.002f,3);
       star(-0.8f,0.75f,0.002f,3);

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



       if(mode==1){
         glColor3ub(249, 234, 122);
       }else{
	   	glColor3ub(255,255,255);
	   }
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



int x,y,z;

if(mode==1){
    x=249;y=234,z=122;
}else{
	 x=255;
    y=255;
    z=255;
}

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
        glColor3ub(x,y,z);
        glVertex2f(0.81f,0.28f);
        glVertex2f(0.83f,0.28f);
        glVertex2f(0.83f,0.32f);
        glVertex2f(0.81f,0.32f);
        glEnd();

            glBegin(GL_QUADS);
        glColor3ub(x,y,z);
        glVertex2f(0.85f,0.28f);
        glVertex2f(0.87f,0.28f);
        glVertex2f(0.87f,0.32f);
        glVertex2f(0.85f,0.32f);
        glEnd();

           glBegin(GL_QUADS);
        glColor3ub(x,y,z);
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




void Trafi_LightMadaripur(float p, float q,float r,int a,int b,int c)
{
    int i;
    GLfloat p1=p; GLfloat q1=q ; GLfloat r1 =r;
    int tringle2=10;
    GLfloat tp2 =2.0f * PI  ;
    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( a, b, c);
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





void bridgeLightMadaripur(){
        glLineWidth(4);
        glBegin(GL_LINES);
        glColor3ub(105,105,105);
        glVertex2f(-0.9f, 0.2f);
        glVertex2f(-0.9f, 0.4f);
        glEnd();

        glLineWidth(4);
        glBegin(GL_LINES);
        glColor3ub(105,105,105);
        glVertex2f(-0.9f,  0.4f);
        glVertex2f(-0.88f, 0.4f);
        glEnd();



        glLineWidth(4);
        glBegin(GL_LINES);
        glColor3ub(105,105,105);
        glVertex2f(-0.85f, 0.2f);
        glVertex2f(-0.85f, 0.4f);
        glEnd();

        glLineWidth(4);
        glBegin(GL_LINES);
        glColor3ub(105,105,105);
        glVertex2f(-0.85f,  0.4f);
        glVertex2f(-0.87f, 0.4f);
        glEnd();
}

void bridgespanpillerMadaripur(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4){

glBegin(GL_QUADS);
glColor3ub(105,105,105);
glVertex2f(x1,y1);
glVertex2f(x2,y2);
glVertex2f(x3,y3);
glVertex2f(x4,y4);
glEnd();

}




void BridgeMadaripur(){

        glBegin(GL_QUADS);
        glColor3ub(105,105,105);
        glVertex2f(-1.0f,-0.5f);
        glVertex2f(-0.45f,-0.5f);
        glVertex2f(-0.45f,-0.45f);
        glVertex2f(-1.0f,-0.45f);

        glEnd();
        glBegin(GL_QUADS);
        glColor3ub(105,105,105);
        glVertex2f(-1.0f,-0.25f);
        glVertex2f(-0.45f,-0.25f);
        glVertex2f(-0.45f,-0.2f);
        glVertex2f(-1.0f,-0.2f);
        glEnd();
        glFlush();

        //Bridge Pillers

        glBegin(GL_QUADS);
        glColor3ub(105,105,105);
        glVertex2f(-0.85f,-0.5f);
        glVertex2f(-0.75f,-0.5f);
        glVertex2f(-0.75f,-0.7f);
        glVertex2f(-0.85f,-0.7f);
        glEnd();


        glBegin(GL_QUADS);
        glColor3ub(105,105,105);
        glVertex2f(-0.9f,-0.72f);
        glVertex2f(-0.7f,-0.72f);
        glVertex2f(-0.7f,-0.65f);
        glVertex2f(-0.9f,-0.65f);
        glEnd();









        //2
         glBegin(GL_QUADS);
        glColor3ub(105,105,105);
        glVertex2f(-0.5f,-0.5f);
        glVertex2f(-0.4f,-0.5f);
        glVertex2f(-0.4f,-0.7f);
        glVertex2f(-0.5f,-0.7f);
        glEnd();


        glBegin(GL_QUADS);
        glColor3ub(105,105,105);
        glVertex2f(-0.56f,-0.72f);
        glVertex2f(-0.36f,-0.72f);
        glVertex2f(-0.36f,-0.65f);
        glVertex2f(-0.56f,-0.65f);
        glEnd();

        //last part
        glBegin(GL_QUADS);
        glColor3ub(105,105,105);
        glVertex2f(-0.45f,-0.5f);
        glVertex2f(-0.15f,-0.5f);
        glVertex2f(-0.15f,-0.45f);
        glVertex2f(-0.45f,-0.45f);
        glEnd();

        //up
          glBegin(GL_QUADS);
        glColor3ub(105,105,105);
        glVertex2f(-0.45f,-0.25f);
        glVertex2f(-0.15f,-0.25f);
        glVertex2f(-0.15f,-0.2f);
        glVertex2f(-0.45f,-0.2f);
        glEnd();

  glLineWidth(40);
        glBegin(GL_LINES);
        glColor3ub(105,105,105);
        glVertex2f(-0.245f,-0.65f);
        glVertex2f(-0.245f,-0.5f);
           glEnd();








        glFlush();



     bridgespanpillerMadaripur(-0.9f,-0.5f,-0.8f,-0.5f,-1.0f,-0.2f,-1.1f,-0.2);

      bridgespanpillerMadaripur(-0.8f,-0.5f,-0.7f,-0.5f,-0.5f,-0.2f,-0.6f,-0.2f);

        glPushMatrix();
        glTranslatef(0.5,0.0f,0.0f);

     bridgespanpillerMadaripur(-0.9f,-0.5f,-0.8f,-0.5f,-1.0f,-0.2f,-1.1f,-0.2);

        glPopMatrix();



}


void TrainLineMadaripur(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4)
{



glBegin(GL_QUADS);
glColor3ub(138, 69, 47);
glVertex2f(x1,y1);
glVertex2f(x2,y2);
glVertex2f(x3,y3);
glVertex2f(x4,y4);
glEnd();


}

void CallTrainLineMadaripur()
{

     TrainLineMadaripur(-0.12f,-0.55f,-0.1f,-0.55f,-0.1f,-0.4f,-0.12f,-0.4);

     float j=0.05f;

     for(int i=0;i<21;i++)
     {

        glPushMatrix();
        glTranslatef(j,0.0f,0.0f);
        TrainLineMadaripur(-0.12f,-0.55f,-0.1f,-0.55f,-0.1f,-0.4f,-0.12f,-0.4);

        glPopMatrix();
        j+=0.05;

     }


     glLineWidth(5);
         glBegin(GL_LINES);
        glColor3ub(187, 186, 186);
        glVertex2f(-0.14f,-0.52f);
        glVertex2f(1.0f,-0.52f);
           glEnd();

            glLineWidth(5);
         glBegin(GL_LINES);
        glColor3ub(187, 186, 186);
        glVertex2f(-0.14f,-0.42f);
        glVertex2f(1.0f,-0.42f);
           glEnd();






}




void treeMadaripur(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4)
{



glBegin(GL_QUADS);
glColor3ub(119,68,34);
glVertex2f(x1,y1);
glVertex2f(x2,y2);
glVertex2f(x3,y3);
glVertex2f(x4,y4);
glEnd();


}






void RoadMadaripur(float x1,float y1,float x2,float y2)
{



       glLineWidth(3);
         glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
           glEnd();


           //trafic light


}








void CallRoadMadaripur()
{

      glBegin(GL_QUADS);
        glColor3ub(0, 0, 0);
        glVertex2f(-0.15f,-0.33f);
        glVertex2f(1.0f,-0.33f);
        glVertex2f(1.0f,-0.13f);
        glVertex2f(-0.15f,-0.13f);
        glEnd();


         glBegin(GL_QUADS);
        glColor3ub(0, 0, 0);
        glVertex2f(0.55f,-0.13f);
        glVertex2f(0.56f,-0.13f);
        glVertex2f(0.56f,0.0f);
        glVertex2f(0.55f,0.0f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(0, 0, 0);
        glVertex2f(0.54f,0.0f);
        glVertex2f(0.57f,0.0f);
        glVertex2f(0.57f,0.15f);
        glVertex2f(0.54f,0.15f);
        glEnd();


        if(trafficmode==0){
		Trafi_LightMadaripur(0.555f,0.13f,0.013f,239,112,112);//r
        Trafi_LightMadaripur(0.555f,0.09f,0.018f,0,204,0);//g
        Trafi_LightMadaripur(0.555f,0.05f,0.013f,237,240,127);//y
		}
		else if (trafficmode==1){
		Trafi_LightMadaripur(0.555f,0.13f,0.018f,255,0,0);//r
        Trafi_LightMadaripur(0.555f,0.09f,0.013f,122,239,169);//g
        Trafi_LightMadaripur(0.555f,0.05f,0.013f,237,240,127);//y
		}
		else if(trafficmode==2){
		Trafi_LightMadaripur(0.555f,0.13f,0.013f,239,112,112);//r
        Trafi_LightMadaripur(0.555f,0.09f,0.013f,122,239,169);//g
        Trafi_LightMadaripur(0.555f,0.05f,0.018f,255,255,0);//y
		}




       glLineWidth(5);
         glBegin(GL_LINES);
        glColor3ub(155, 150, 154);
        glVertex2f(-0.14f,-0.315f);
        glVertex2f(1.0f,-0.315f);
           glEnd();


               glLineWidth(5);
         glBegin(GL_LINES);
        glColor3ub(155, 150, 154);
        glVertex2f(-0.14f,-0.14f);
        glVertex2f(1.0f,-0.14f);
           glEnd();


    RoadMadaripur(-0.12f,-0.23f,-0.1f,-0.23f);



     float j=0.09f;

     for(int i=0;i<18;i++)
     {

        glPushMatrix();
        glTranslatef(j,0.0f,0.0f);

       RoadMadaripur(-0.12f,-0.23f,-0.1f,-0.23f);
        glPopMatrix();
        j+=0.08;

     }

     //body


}



void DrawRiverMadaripur(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4)
{
    glBegin(GL_QUADS);
    glColor3ub(1, 127, 129);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glVertex2f(x4, y4);
      glEnd ();



    drawRiverElipsis(-0.75f,-0.73f,0.2f,0.020f);
     drawRiverElipsis(-0.6f,-0.3f,0.2f,0.02f);
     drawRiverElipsis(-0.8f,-0.1f,0.1f,0.02f);
     drawRiverElipsis(-0.5f,-0.5f,0.1f,0.01f);

}


void riverTriangleMadaripur()
{





     glBegin(GL_TRIANGLES);
    glColor3ub(1, 127, 129);
    glVertex2f(-0.35f, -1.0f);
    glVertex2f(-0.35f, -0.7f);
    glVertex2f(-0.28f, -0.95f);

      glEnd ();


      glBegin(GL_TRIANGLES);
    glColor3ub(1, 127, 129);
    glVertex2f(-0.35f, -0.7f);
    glVertex2f(-0.35f, -0.2f);
    glVertex2f(-0.27f, -0.6f);

      glEnd ();

        glBegin(GL_TRIANGLES);
    glColor3ub(1, 127, 129);
    glVertex2f(-0.35f, -0.3f);
    glVertex2f(-0.35f, 0.0f);
    glVertex2f(-0.27f, -0.2f);

      glEnd ();







      //par
      glBegin(GL_QUADS);
    glColor3ub(0, 10, 41);
    glVertex2f(-0.29f, -0.22f);
    glVertex2f(-0.27f, -0.2f);
    glVertex2f(-0.35f, 0.0f);
    glVertex2f(-0.35f, -0.05f);

      glEnd ();




      glBegin(GL_QUADS);
    glColor3ub(0, 10, 41);
    glVertex2f(-0.29f, -0.62f);
    glVertex2f(-0.27f, -0.6f);
    glVertex2f(-0.337f, -0.275f);
    glVertex2f(-0.348f, -0.31f);

      glEnd ();


       glBegin(GL_QUADS);
    glColor3ub(0, 10, 41);
    glVertex2f(-0.29f, -0.96f);
    glVertex2f(-0.27f, -0.94f);
    glVertex2f(-0.35f, -0.7f);
    glVertex2f(-0.352f, -0.75f);

      glEnd ();








}



void madaripur()
{
     glBegin(GL_QUADS);
    glColor3ub(0, 128, 1);
    glVertex2f(-0.35f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-0.35f, 1.0f);

      glEnd ();


}
void LineInHomeMadaripur(float x1,float y1,float x2,float y2, int a,int b,int c)
{

            glLineWidth(2);
    glBegin(GL_LINES);
      glColor3ub(a, b, c);
     glVertex2f(x1, y1);
    glVertex2f(x2, y2);
 glEnd ();


}


void MiniPark(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4)
{





glBegin(GL_QUADS);
glColor3ub(119,68,34);
glVertex2f(x1,y1);
glVertex2f(x2,y2);
glVertex2f(x3,y3);
glVertex2f(x4,y4);
glEnd();














}
void TreePata(float p, float q,float r)
{
    int i;
    GLfloat p1=p; GLfloat q1=q ; GLfloat r1 =r;
    int tringle2=40;
    GLfloat tp2 =2.0f * PI  ;
    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (78, 132, 20 );
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




void TreeShado(GLfloat x, GLfloat y, GLfloat width,
                              GLfloat height)
{



    int i;
  int triangleAmount = 255;
  glPushMatrix();
  glTranslatef(x, y, 0);
  glPushMatrix();
  glScalef(width, height, 0);
  glBegin(GL_TRIANGLE_FAN);
   glColor3ub(48, 99, 3);



 glVertex2f(0, 0);
  for (i = 0; i <= triangleAmount; i++) {
    glVertex2f((1 * cos(i * PI2 / triangleAmount)),
               (1 * sin(i * PI2 / triangleAmount)));
  }
  glEnd();
  glPopMatrix();
  glPopMatrix();
}



void banchLine(float x1,float y1,float x2,float y2,int l)
{
     glLineWidth(l);
         glBegin(GL_LINES);
        glColor3ub(0, 0, 0);
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
           glEnd();




}



void banchLine1(float x1,float y1,float x2,float y2,int l)
{
     glLineWidth(l);
         glBegin(GL_LINES);
        glColor3ub(230, 138, 83);
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
           glEnd();




}
void banchLine2(float x1,float y1,float x2,float y2,int l)
{
     glLineWidth(l);
         glBegin(GL_LINES);
        glColor3ub(200, 139, 74);
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
           glEnd();




}




void LampLight(float p, float q,float r)
{
    int i;
    GLfloat p1=p; GLfloat q1=q ; GLfloat r1 =r;
    int tringle2=40;
    GLfloat tp2 =2.0f * PI  ;
    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (255, 255, 255 );
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



void lamp()
{
      glBegin(GL_QUADS);
        glColor3ub(0, 0, 0);
        glVertex2f(-0.3f,-0.05f);
        glVertex2f(-0.24f,-0.05f);
        glVertex2f(-0.26f,-0.03f);
        glVertex2f(-0.28f,-0.03f);
        glEnd();



          glLineWidth(8);
         glBegin(GL_LINES);
        glColor3ub(0,0,0);
        glVertex2f(-0.27f,-0.03f);
        glVertex2f(-0.27f,0.22f);
           glEnd();




               glBegin(GL_QUADS);
        glColor3ub(0, 0, 0);
        glVertex2f(-0.275f,0.22f);
        glVertex2f(-0.265f,0.22f);
        glVertex2f(-0.262f,0.24f);
        glVertex2f(-0.278f,0.24f);
        glEnd();









}



void callMiniPark()
{
TreeShado(0.14f,-0.04f,0.1f,0.03f);
   MiniPark(0.12f,-0.05f,0.16f,-0.05f,0.16f,0.14f,0.12f,0.14f);
   TreePata(0.12f,0.18f,0.08f);
   TreePata(0.16f,0.18f,0.08f);
   TreePata(0.14f,0.25f,0.07f);
    banchLine(0.0f,-0.04f,0.0f,0.14f,5);



banchLine(-0.18f,-0.04f,-0.18f,0.14f,5);



banchLine(-0.21f,-0.06f,-0.21f,0.03f,5);
banchLine(0.03f,-0.06f,0.03f,0.03f,5);



banchLine(-0.21f,-0.04f,-0.18f,-0.02f,3);



banchLine(0.0f,-0.02f,0.03f,-0.04f,3);



banchLine1(-0.2f,0.11f,0.02f,0.11f,12);



banchLine1(-0.2f,0.07f,0.02f,0.07f,12);




TreeShado(-0.27f,-0.05f,0.04f,0.02f);
      glBegin(GL_QUADS);
        glColor3ub(230, 138, 83);
        glVertex2f(-0.22f,0.0f);
        glVertex2f(0.04f,0.0f);
        glVertex2f(0.04f,0.05f);
        glVertex2f(-0.22f,0.05f);



       glEnd();



       banchLine2(-0.22f,0.0f,0.04f,0.0f,8);
        lamp();



        LampLight(-0.27f,0.26f,0.029f);




}





void windmill()
{
       glLineWidth(15);
         glBegin(GL_LINES);
        glColor3ub(255,255,255);
        glVertex2f(0.05f,-0.02f);
        glVertex2f(0.05f,0.35f);
           glEnd();



        LampLight(0.05f,0.35f,0.025f);




     glBegin(GL_TRIANGLES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.06f, 0.37f);
    glVertex2f(0.2f, 0.22f);
    glVertex2f(0.025f, 0.34f);



     glEnd ();



        glBegin(GL_TRIANGLES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.06f, 0.34f);
    glVertex2f(0.15f, 0.63f);
    glVertex2f(0.025f, 0.35f);



     glEnd ();




        glBegin(GL_TRIANGLES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.06f, 0.3f);
    glVertex2f(-0.15f, 0.35f);
    glVertex2f(0.025f, 0.35f);



     glEnd ();


}

void homeMadaripur()
{




   glBegin(GL_QUADS);
    glColor3ub(157, 225, 218);
    glVertex2f(0.825f, -0.05f);
    glVertex2f(0.9f, -0.05f);
    glVertex2f(0.9f, 0.5f);
    glVertex2f(0.825f, 0.5f);

    glEnd ();

  glBegin(GL_QUADS);
    glColor3ub(81, 127, 122);
    glVertex2f(0.9f, -0.05f);
    glVertex2f(0.94f, -0.02f);
    glVertex2f(0.94f, 0.51f);
    glVertex2f(0.9f, 0.5f);

    glEnd ();


   glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(0.832f, -0.03f);
    glVertex2f(0.89f, -0.03f);
    glVertex2f(0.89f, 0.48f);
    glVertex2f(0.832f, 0.48f);

    glEnd ();

            glLineWidth(2);
    glBegin(GL_LINES);
      glColor3ub(157, 225, 218);
     glVertex2f(0.833f, -0.05f);
    glVertex2f(0.89f, -0.05f);
 glEnd ();

            glLineWidth(2);
    glBegin(GL_LINES);
      glColor3ub(157, 225, 218);
     glVertex2f(0.833f, 0.46f);
    glVertex2f(0.89, 0.46f);
 glEnd ();

            glLineWidth(2);
    glBegin(GL_LINES);
      glColor3ub(157, 225, 218);
     glVertex2f(0.833f, 0.46f);
    glVertex2f(0.89, 0.46f);
 glEnd ();


 LineInHomeMadaripur(0.833f, 0.43f,0.89, 0.43f,157, 225, 218);

 LineInHomeMadaripur(0.833f, 0.40f,0.89, 0.40f,157, 225, 218);
  LineInHomeMadaripur(0.833f, 0.40f,0.89, 0.40f,157, 225, 218);
  LineInHomeMadaripur(0.833f, 0.40f,0.89, 0.40f,157, 225, 218);


 LineInHomeMadaripur(0.833f, 0.37f,0.89, 0.37f,157, 225, 218);
  LineInHomeMadaripur(0.833f, 0.34f,0.89, 0.34f,157, 225, 218);
  LineInHomeMadaripur(0.833f, 0.31f,0.89, 0.31f,157, 225, 218);

 LineInHomeMadaripur(0.833f, 0.28f,0.89, 0.28f,157, 225, 218);
  LineInHomeMadaripur(0.833f, 0.25f,0.89, 0.25f,157, 225, 218);
  LineInHomeMadaripur(0.833f, 0.22f,0.89, 0.22f,157, 225, 218);


   LineInHomeMadaripur(0.845f, -0.05f,0.845, 0.48f,157, 225, 218);


   LineInHomeMadaripur(0.86f, -0.05f,0.86f, 0.48f,157, 225, 218);
   LineInHomeMadaripur(0.875f, -0.05f,0.875f, 0.48f,157, 225, 218);


//left h1
   glBegin(GL_QUADS);
    glColor3ub(160, 165, 41);
    glVertex2f(0.82f, -0.05f);
    glVertex2f(0.9f, -0.05f);
    glVertex2f(0.9f, 0.2f);
    glVertex2f(0.82f, 0.2f);

    glEnd ();

  glBegin(GL_QUADS);
    glColor3ub(102, 105, 28);
    glVertex2f(0.9f, -0.05f);
    glVertex2f(0.94f, -0.02f);
    glVertex2f(0.94f, 0.3f);
    glVertex2f(0.9f, 0.2f);

    glEnd ();



  glBegin(GL_QUADS);
    glColor3ub(22, 25, 75);
    glVertex2f(0.82f, 0.2f);
    glVertex2f(0.9f, 0.2f);
    glVertex2f(0.94f, 0.3f);
    glVertex2f(0.86f, 0.3f);

    glEnd ();


    glLineWidth(0.5);
    glBegin(GL_LINES);
      glColor3ub(255, 255, 255);
    glVertex2f(0.84f, -0.05f);
    glVertex2f(0.84f, 0.2f);

    glEnd ();

     glLineWidth(0.5);
    glBegin(GL_LINES);
      glColor3ub(255, 255, 255);
    glVertex2f(0.86f, -0.05f);
    glVertex2f(0.86f, 0.2f);

    glEnd ();


     glLineWidth(0.5);
    glBegin(GL_LINES);
      glColor3ub(255, 255, 255);
    glVertex2f(0.88f, -0.05f);
    glVertex2f(0.88f, 0.2f);

    glEnd ();

      glLineWidth(0.5);
    glBegin(GL_LINES);
      glColor3ub(255, 255, 255);
     glVertex2f(0.82f, -0.02f);
    glVertex2f(0.9f, -0.02f);

    glEnd ();

        glLineWidth(0.5);
    glBegin(GL_LINES);
      glColor3ub(255, 255, 255);
     glVertex2f(0.82f, 0.01f);
    glVertex2f(0.9f, 0.01f);

    glEnd ();

        glLineWidth(0.5);
    glBegin(GL_LINES);
      glColor3ub(255, 255, 255);
     glVertex2f(0.82f, 0.04f);
    glVertex2f(0.9f, 0.04f);

    glEnd ();

       glLineWidth(0.5);
    glBegin(GL_LINES);
      glColor3ub(255, 255, 255);
     glVertex2f(0.82f, 0.07f);
    glVertex2f(0.9f, 0.07f);

    glEnd ();

       glLineWidth(0.5);
    glBegin(GL_LINES);
      glColor3ub(255, 255, 255);
     glVertex2f(0.82f, 0.1f);
    glVertex2f(0.9f, 0.1f);

    glEnd ();

       glLineWidth(0.5);
    glBegin(GL_LINES);
      glColor3ub(255, 255, 255);
     glVertex2f(0.82f, 0.13f);
    glVertex2f(0.9f, 0.13f);

    glEnd ();

       glLineWidth(0.5);
    glBegin(GL_LINES);
      glColor3ub(255, 255, 255);
     glVertex2f(0.82f, 0.16f);
    glVertex2f(0.9f, 0.16f);

    glEnd ();

           glLineWidth(0.5);
    glBegin(GL_LINES);
      glColor3ub(255, 255, 255);
     glVertex2f(0.82f, 0.19f);
    glVertex2f(0.9f, 0.19f);

    glEnd ();


    //home 2

  glBegin(GL_QUADS);
    glColor3ub(29,68,59);
    glVertex2f(0.6f, -0.05f);
    glVertex2f(0.75f, -0.05f);
    glVertex2f(0.75f, 0.35f);
    glVertex2f(0.6f, 0.35f);

    glEnd ();


  glBegin(GL_QUADS);
    glColor3ub(29,68,59);
    glVertex2f(0.58f, 0.35f);
    glVertex2f(0.77f, 0.35f);
    glVertex2f(0.77f, 0.39f);
    glVertex2f(0.58f, 0.39f);

    glEnd ();

  glBegin(GL_QUADS);
    glColor3ub(208,75,36);
    glVertex2f(0.58f, -0.05f);
    glVertex2f(0.6f, -0.05f);
    glVertex2f(0.6f, 0.35f);
    glVertex2f(0.58, 0.35f);

    glEnd ();



     glBegin(GL_QUADS);
    glColor3ub(208,75,36);
    glVertex2f(0.56f, 0.35f);
    glVertex2f(0.58f, 0.35f);
    glVertex2f(0.58f, 0.39f);
    glVertex2f(0.56, 0.39f);

    glEnd ();



    glBegin(GL_QUADS);
    glColor3ub(184,218,194);
    glVertex2f(0.62f, 0.26f);
    glVertex2f(0.65f, 0.26f);
    glVertex2f(0.65f, 0.32f);
    glVertex2f(0.62f, 0.32f);

    glEnd ();



    glBegin(GL_QUADS);
    glColor3ub(184,218,194);
    glVertex2f(0.66f, 0.26f);
    glVertex2f(0.69f, 0.26f);
    glVertex2f(0.69f, 0.32f);
    glVertex2f(0.66f, 0.32f);

    glEnd ();

     glBegin(GL_QUADS);
    glColor3ub(184,218,194);
    glVertex2f(0.7f, 0.26f);
    glVertex2f(0.73f, 0.26f);
    glVertex2f(0.73f, 0.32f);
    glVertex2f(0.7f, 0.32f);

    glEnd ();



    glLineWidth(2);
    glBegin(GL_LINES);
      glColor3ub(255, 255, 255);
     glVertex2f(0.61f, 0.22f);
    glVertex2f(0.74f, 0.22f);

    glEnd ();



   glBegin(GL_QUADS);
    glColor3ub(184,218,194);
    glVertex2f(0.7f, 0.12f);
    glVertex2f(0.73f, 0.12f);
    glVertex2f(0.73f, 0.18f);
    glVertex2f(0.7f, 0.18f);

    glEnd ();


    /* glBegin(GL_QUADS);
    glColor3ub(184,218,194);
    glVertex2f(0.7f, 0.12f);
    glVertex2f(0.7f, 0.12f);
    glVertex2f(0.73f, 0.18f);
    glVertex2f(0.7f, 0.18f);

    glEnd ();*/


    glBegin(GL_QUADS);
    glColor3ub(184,218,194);
    glVertex2f(0.62f, 0.12f);
    glVertex2f(0.65f, 0.12f);
    glVertex2f(0.65f, 0.18f);
    glVertex2f(0.62f, 0.18f);

    glEnd ();

      glBegin(GL_QUADS);
    glColor3ub(184,218,194);
    glVertex2f(0.66f, 0.12f);
    glVertex2f(0.69f, 0.12f);
    glVertex2f(0.69f, 0.18f);
    glVertex2f(0.66f, 0.18f);

    glEnd ();





      glBegin(GL_QUADS);
    glColor3ub(255,255,0);
    glVertex2f(0.72f, -0.09f);
    glVertex2f(0.81f, -0.09f);
    glVertex2f(0.81f, 0.08f);
    glVertex2f(0.72f, 0.08f);

    glEnd ();


        glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(0.73f, -0.06f);
    glVertex2f(0.8f, -0.06f);
    glVertex2f(0.8f, 0.05f);
    glVertex2f(0.73f, 0.05f);

    glEnd ();




 glLineWidth(5);
    glBegin(GL_LINES);
      glColor3ub(255,255,0);
     glVertex2f(0.73f, -0.03f);
    glVertex2f(0.8f, -0.03f);

    glEnd ();

     glLineWidth(5);
    glBegin(GL_LINES);
      glColor3ub(255,255,0);
     glVertex2f(0.73f, 0.01f);
    glVertex2f(0.8f, 0.01f);

    glEnd ();


      glLineWidth(5);
    glBegin(GL_LINES);
      glColor3ub(255,255,0);
     glVertex2f(0.73f, 0.05f);
    glVertex2f(0.8f, 0.05f);

    glEnd ();


      glLineWidth(5);
    glBegin(GL_LINES);
      glColor3ub(255,255,0);
     glVertex2f(0.75f, -0.07f);
    glVertex2f(0.75f, 0.05f);

    glEnd ();

     glLineWidth(5);
    glBegin(GL_LINES);
      glColor3ub(255,255,0);
     glVertex2f(0.75f, -0.07f);
    glVertex2f(0.75f, 0.05f);

    glEnd ();
///// home 4

        glBegin(GL_QUADS);
    glColor3ub(239,124,33);
    glVertex2f(0.4f, -0.06f);
    glVertex2f(0.55f, -0.06f);
    glVertex2f(0.55f, 0.07f);
    glVertex2f(0.4f, 0.07f);

    glEnd ();


    glBegin(GL_QUADS);
    glColor3ub(214,195,144);
    glVertex2f(0.4f, 0.07f);
    glVertex2f(0.55f, 0.07f);
    glVertex2f(0.55f, 0.085f);
    glVertex2f(0.4f, 0.085f);

    glEnd ();


      glBegin(GL_QUADS);
    glColor3ub(239,124,33);
    glVertex2f(0.41f, 0.085f);
    glVertex2f(0.54f, 0.085f);
    glVertex2f(0.54f, 0.17f);
    glVertex2f(0.41f, 0.17f);

    glEnd ();

        glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(0.41f, 0.17f);
    glVertex2f(0.54f, 0.17f);
    glVertex2f(0.54f, 0.18f);
    glVertex2f(0.41f, 0.18f);

    glEnd ();

        glBegin(GL_QUADS);
    glColor3ub(106,135,109);
    glVertex2f(0.41f, 0.18f);
    glVertex2f(0.54f, 0.18f);
    glVertex2f(0.53f, 0.21f);
    glVertex2f(0.42f, 0.21f);

    glEnd ();


          glBegin(GL_QUADS);
    glColor3ub(253,253,253);
    glVertex2f(0.44f, 0.1f);
    glVertex2f(0.46f, 0.1f);
    glVertex2f(0.46f, 0.15f);
    glVertex2f(0.44f, 0.15f);

    glEnd ();


           glBegin(GL_QUADS);
    glColor3ub(253,253,253);
    glVertex2f(0.47f, 0.1f);
    glVertex2f(0.49f, 0.1f);
    glVertex2f(0.49f, 0.15f);
    glVertex2f(0.47f, 0.15f);

    glEnd ();

            glBegin(GL_QUADS);
    glColor3ub(253,253,253);
    glVertex2f(0.5f, 0.1f);
    glVertex2f(0.52f, 0.1f);
    glVertex2f(0.52f, 0.15f);
    glVertex2f(0.5f, 0.15f);

    glEnd ();



             glBegin(GL_QUADS);
    glColor3ub(253,253,253);
    glVertex2f(0.455f, -0.06f);
    glVertex2f(0.495f, -0.06f);
    glVertex2f(0.495f, 0.05f);
    glVertex2f(0.455f, 0.05f);

    glEnd ();

      glBegin(GL_QUADS);
    glColor3ub(191,83,22);
    glVertex2f(0.455f, -0.06f);
    glVertex2f(0.46f, -0.06f);
    glVertex2f(0.46f, 0.05f);
    glVertex2f(0.455f, 0.05f);

    glEnd ();



        glBegin(GL_QUADS);
    glColor3ub(253,253,253);
    glVertex2f(0.41f, -0.03f);
    glVertex2f(0.435f, -0.03f);
    glVertex2f(0.435f, 0.03f);
    glVertex2f(0.41f, 0.03f);

    glEnd ();


         glBegin(GL_QUADS);
    glColor3ub(253,253,253);
    glVertex2f(0.51f, -0.03f);
    glVertex2f(0.535f, -0.03f);
    glVertex2f(0.535f, 0.03f);
    glVertex2f(0.51f, 0.03f);

    glEnd ();




//home 5



   glBegin(GL_QUADS);
    glColor3ub(241,219,168);
    glVertex2f(0.25f, -0.05f);
    glVertex2f(0.34f, -0.05f);
    glVertex2f(0.34f, 0.25f);
    glVertex2f(0.25f, 0.25f);

    glEnd ();


       glBegin(GL_QUADS);
    glColor3ub(203,175,98);
    glVertex2f(0.34f, -0.05f);
    glVertex2f(0.39f, -0.04f);
    glVertex2f(0.39f, 0.26f);
    glVertex2f(0.34f, 0.25f);

    glEnd ();


         glBegin(GL_TRIANGLES);
    glColor3ub(121,137,109);
    glVertex2f(0.25f, 0.25f);
    glVertex2f(0.34f, 0.25f);
    glVertex2f(0.32f, 0.35f);


    glEnd ();


         glBegin(GL_TRIANGLES);
    glColor3ub(56,83,58);
    glVertex2f(0.34f, 0.25f);
    glVertex2f(0.39f, 0.26f);
    glVertex2f(0.32f, 0.35f);


    glEnd ();
  //  h5 windows

  glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(0.35f, 0.2f);
    glVertex2f(0.365f, 0.2f);
    glVertex2f(0.365f, 0.23f);
    glVertex2f(0.35f, 0.23f);

    glEnd ();


    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(0.37f, 0.2f);
    glVertex2f(0.385f, 0.2f);
    glVertex2f(0.385f, 0.23f);
    glVertex2f(0.37f, 0.23f);

    glEnd ();

      glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(0.35f, 0.15f);
    glVertex2f(0.365f, 0.15f);
    glVertex2f(0.365f, 0.18f);
    glVertex2f(0.35f, 0.18f);

    glEnd ();

  glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(0.37f, 0.15f);
    glVertex2f(0.385f, 0.15f);
    glVertex2f(0.385f, 0.18f);
    glVertex2f(0.37f, 0.18f);

    glEnd ();


    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(0.35f, 0.1f);
    glVertex2f(0.365f, 0.1f);
    glVertex2f(0.365f, 0.13f);
    glVertex2f(0.35f, 0.13f);

    glEnd ();


    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(0.37f, 0.1f);
    glVertex2f(0.385f, 0.1f);
    glVertex2f(0.385f, 0.13f);
    glVertex2f(0.37f, 0.13f);

    glEnd ();



        glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(0.35f, 0.05f);
    glVertex2f(0.365f, 0.05f);
    glVertex2f(0.365f, 0.08f);
    glVertex2f(0.35f, 0.08f);

    glEnd ();

  glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(0.37f, 0.05f);
    glVertex2f(0.385f, 0.05f);
    glVertex2f(0.385f, 0.08f);
    glVertex2f(0.37f, 0.08f);

    glEnd ();


            glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(0.35f, 0.0f);
    glVertex2f(0.365f, 0.0f);
    glVertex2f(0.365f, 0.03f);
    glVertex2f(0.35f, 0.03f);

    glEnd ();

  glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(0.37f, 0.0f);
    glVertex2f(0.385f, 0.0f);
    glVertex2f(0.385f, 0.03f);
    glVertex2f(0.37f, 0.03f);

    glEnd ();


    // top side w r


      glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(0.26f, 0.15f);
    glVertex2f(0.29f, 0.15f);
    glVertex2f(0.29f, 0.22f);
    glVertex2f(0.26f, 0.22f);

    glEnd ();


        glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(0.3f, 0.15f);
    glVertex2f(0.33f, 0.15f);
    glVertex2f(0.33f, 0.22f);
    glVertex2f(0.3f, 0.22f);

    glEnd ();



    glLineWidth(10);
      glBegin(GL_LINES);

    glColor3ub(255,255,255);
    glVertex2f(0.25f, -0.01f);
    glVertex2f(0.34f, -0.01f);
    glEnd ();


       glLineWidth(10);
      glBegin(GL_LINES);

    glColor3ub(255,255,255);
    glVertex2f(0.25f, 0.03f);
    glVertex2f(0.34f, 0.03f);
    glEnd ();



       glLineWidth(10);
      glBegin(GL_LINES);

    glColor3ub(255,255,255);
    glVertex2f(0.25f, 0.07f);
    glVertex2f(0.34f, 0.07f);
    glEnd ();


  glLineWidth(10);
      glBegin(GL_LINES);

    glColor3ub(255,255,255);
    glVertex2f(0.25f, 0.11f);
    glVertex2f(0.34f, 0.11f);
    glEnd ();


}

void park()
{



   //Left Last One
glLineWidth(10.5);
glBegin(GL_LINES);
glColor3ub(230,0,0);
glVertex2f(-0.20f,-0.85f);
glVertex2f(0.05f,-0.7f);
glVertex2f(-0.07f,-0.77f);
glVertex2f(-0.07f,-0.86f);
glEnd();




glLineWidth(5.5);
glBegin(GL_LINES);
glColor3ub(230,0,0);
glVertex2f(-0.17f,-0.83f);
glVertex2f(-0.17f,-0.80f);
glVertex2f(-0.0f,-0.70f);
glVertex2f(-0.0f,-0.73f);
glEnd();




//Dolna
glLineWidth(5);
glBegin(GL_LINES);
glColor3ub(0,0,205);
glVertex2f(0.35f,-0.95f);
glVertex2f(0.35f,-0.5f);
glVertex2f(0.1f,-0.95f);
glVertex2f(0.1f,-0.5f);
glEnd();



glLineWidth(3.5);
glBegin(GL_LINES);
glColor3ub(0,0,205);
glVertex2f(0.1f,-0.55f);
glVertex2f(0.35f,-0.55f);
glEnd();




glLineWidth(1.0);
glBegin(GL_LINES);
glColor3ub(218,165,32);
glVertex2f(0.20f,-0.84f);
glVertex2f(0.20f,-0.55f);
glVertex2f(0.26f,-0.84f);
glVertex2f(0.26f,-0.55f);
glEnd();




glBegin(GL_POLYGON);
glColor3ub(220,20,60);
glVertex2f(0.18f,-0.84f);
glVertex2f(0.20f,-0.79f);
glVertex2f(0.26f,-0.79f);
glVertex2f(0.28f,-0.84f);
glEnd();




glBegin(GL_QUADS);
glColor3ub(0,0,255);
glVertex2f(0.18f,-0.85f);
glVertex2f(0.18f,-0.84f);
glVertex2f(0.28f,-0.84f);
glVertex2f(0.28f,-0.85f);
glEnd();





//Right Tree
glBegin(GL_QUADS);
glColor3ub(139,69,19);
glVertex2f(0.84f,-0.99f);
glVertex2f(0.84f,-0.7f);
glVertex2f(0.88f,-0.7f);
glVertex2f(0.88f,-0.99f);
glEnd();




glBegin(GL_TRIANGLES);
glColor3ub(46, 76, 13);
glVertex2f(0.74f,-0.7f);
glVertex2f(0.98f,-0.7f);
glVertex2f(0.86f,-0.5f);
glEnd();




glBegin(GL_TRIANGLES);
glColor3ub(46, 76, 13);
glVertex2f(0.76f,-0.6f);
glVertex2f(0.96f,-0.6f);
glVertex2f(0.86f,-0.4f);
glEnd();





//BENCH
glBegin(GL_POLYGON);
glColor3ub(128,0,0);
glVertex2f(0.45f,-0.8f);
glVertex2f(0.50f,-0.69f);
glVertex2f(0.69f,-0.69f);
glVertex2f(0.75f,-0.8f);
glEnd();




glBegin(GL_QUADS);
glColor3ub(160,64,0 );
glVertex2f(0.45f,-0.82f);
glVertex2f(0.45f,-0.8f);
glVertex2f(0.75f,-0.8f);
glVertex2f(0.75f,-0.82f);
glEnd();




glBegin(GL_QUADS);
glColor3ub(123,36,28 );
glVertex2f(0.50f,-0.88f);
glVertex2f(0.50f,-0.82f);
glVertex2f(0.53f,-0.82f);
glVertex2f(0.53f,-0.88f);
glEnd();




glBegin(GL_QUADS);
glColor3ub(123,36,28 );
glVertex2f(0.67f,-0.88f);
glVertex2f(0.67f,-0.82f);
glVertex2f(0.70f,-0.82f);
glVertex2f(0.70f,-0.88f);
glEnd();




glFlush();
}

void zebracrs()
{




       glLineWidth(8);
         glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(0.53f,-0.17f);
        glVertex2f(0.58f,-0.17f);
           glEnd();



          glLineWidth(8);
         glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(0.53f,-0.2f);
        glVertex2f(0.58f,-0.2f);
           glEnd();




           glLineWidth(8);
         glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(0.53f,-0.23f);
        glVertex2f(0.58f,-0.23f);
           glEnd();



            glLineWidth(8);
         glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(0.53f,-0.26f);
        glVertex2f(0.58f,-0.26f);
           glEnd();
   glLineWidth(8);
         glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(0.53f,-0.29f);
        glVertex2f(0.58f,-0.29f);
           glEnd();



}

void parktree(){
glBegin(GL_QUADS);
glColor3ub(139,69,19);
glVertex2f(0.84f,-0.99f);
glVertex2f(0.84f,-0.7f);
glVertex2f(0.88f,-0.7f);
glVertex2f(0.88f,-0.99f);
glEnd();




glBegin(GL_TRIANGLES);
glColor3ub(46, 76, 13);
glVertex2f(0.74f,-0.7f);
glVertex2f(0.98f,-0.7f);
glVertex2f(0.86f,-0.5f);
glEnd();




glBegin(GL_TRIANGLES);
glColor3ub(46, 76, 13);
glVertex2f(0.76f,-0.6f);
glVertex2f(0.96f,-0.6f);
glVertex2f(0.86f,-0.4f);
glEnd();



}

void MbridgeLight(){
        glLineWidth(4);
        glBegin(GL_LINES);
        glColor3ub(105,105,105);
        glVertex2f(-0.9f, -0.2f);
        glVertex2f(-0.9f, -0.02f);
        glEnd();



       glLineWidth(4);
        glBegin(GL_LINES);
        glColor3ub(105,105,105);
        glVertex2f(-0.9f,  -0.02f);
        glVertex2f(-0.88f, -0.02f);
        glEnd();





       glLineWidth(4);
        glBegin(GL_LINES);
        glColor3ub(105,105,105);
        glVertex2f(-0.85f, -0.2f);
        glVertex2f(-0.85f, -0.02f);
        glEnd();



       glLineWidth(4);
        glBegin(GL_LINES);
        glColor3ub(105,105,105);
        glVertex2f(-0.85f,  -0.02f);
        glVertex2f(-0.87f, -0.02f);
        glEnd();









         glLineWidth(4);
        glBegin(GL_LINES);
        glColor3ub(105,105,105);
        glVertex2f(-0.5f, -0.2f);
        glVertex2f(-0.5f, -0.02f);
        glEnd();



       glLineWidth(4);
        glBegin(GL_LINES);
        glColor3ub(105,105,105);
        glVertex2f(-0.5f,  -0.02f);
        glVertex2f(-0.48f, -0.02f);
        glEnd();





       glLineWidth(4);
        glBegin(GL_LINES);
        glColor3ub(105,105,105);
        glVertex2f(-0.45f, -0.2f);
        glVertex2f(-0.45f, -0.02f);
        glEnd();



       glLineWidth(4);
        glBegin(GL_LINES);
        glColor3ub(105,105,105);
        glVertex2f(-0.45f,  -0.02f);
        glVertex2f(-0.47f, -0.02f);
        glEnd();
}



void SelectScene(){




if(scene==0)
    {

if(!thunderstorm){
	drawBoat();
    drawHelicopter();
}

        if(pinak){
            glPushMatrix();
            glTranslatef(pinakposition,0.0f,0.0f);
            drawBigBoat();
            glPopMatrix();
            }




        if(sank){
drawBoatThunderstormSky();
            }
    }


if(scene==1)   {
     Train();
    car();
    bus();
    Bridge();
    hill();
	drawBoat();
    drawHelicopter();

}
if(scene==2){
        sunposition=0.0f;
      sunset=1;
DrawRiverMadaripur(-1.0f, -1.0f,-0.35f, -1.0f,-0.35f, 0.0f,-1.0f, 0.0f);

madaripur();
DrawSky(-1.0f, 0.0f,1.0f, 0.0f,1.0f,1.0f,-1.0f, 1.0f);
windmill();

callMiniPark();
homeMadaripur();
CallTrainLineMadaripur();
CallRoadMadaripur();
zebracrs();
riverTriangleMadaripur();
MbridgeLight();
Bird();

//car();

glPushMatrix();
glTranslatef(0.0f,-0.45f,0.0f);
car();
bus();
glPopMatrix();
glPushMatrix();

glTranslatef(0.0f,-0.48f,0.0f);
Train();
glPopMatrix();
BridgeMadaripur();

glPushMatrix();
glScalef(0.6,0.6,0.6);
glTranslatef(0.5f,-0.68f,0.0f);
park();
glPopMatrix();


glPushMatrix();
glScalef(0.6,0.6,0.6);
glTranslatef(0.4f,-0.62f,0.0f);
parktree();
glPopMatrix();

glPushMatrix();
glScalef(0.6,0.6,0.6);
glTranslatef(0.7f,-0.62f,0.0f);
parktree();
glPopMatrix();





}

}





void display()
{

    if(trafficmode==1){
        if(Carposition>=1.35 && Carposition<1.48){
            Carspeed=0;
        }
        if(Busposition<=-0.152 && Busposition>=-0.233){
            Busspeed=0;
        }
    }



if(scene>=2){
	mode=0;
}

glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
DrawSky(-1.0f, -0.28f,1.0f, -0.28f,1.0f, 1.0f,-1.0f, 1.0f);
DrawRiver(-1.0f, -1.0f,1.0f, -1.0f,1.0f, -0.20f,-1.0f, -0.20f);
cloud();
if(mode==0){
    Bird();
}


if(mode==1){

moon(-0.47f,0.86f,0.07f,1);
moon(-0.47f,0.86f,0.06f,2);
moon(-0.47f,0.86f,0.045f,3);
CallStar();

}
if(mode==3){
	CallStarEvening();
}


SelectScene();
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
    glutTimerFunc(200, runrightbirds, 0);
    glutTimerFunc(100, runleftbirds, 0);
    glutTimerFunc(200, runthleftboat, 0);
    glutTimerFunc(100, runthrightboat, 0);
glutTimerFunc(100, Busupdate, 0);
glutTimerFunc(100, Heliupdate, 0);
glutMainLoop();
    return 0;
}

