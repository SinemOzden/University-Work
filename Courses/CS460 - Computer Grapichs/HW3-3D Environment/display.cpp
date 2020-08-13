#include"display.h"
#include"util.h"

//#define NDEBUG  // used to disabled all assert.
GLsizei width, height;


double m_xtheta=0;
double m_ytheta=0;
double m_ztheta=0;
double m_slide=40;
double m_lever=0;


void setup()
{
    glClearColor(0, 0, 0, 1.0); // *should* display black background
}

GLsizei getWidth(){
    return width;
}

GLsizei getHeight(){
    return height;
}

void reshape( int w, int h ){
    glViewport( 0, 0, (GLsizei)w, (GLsizei)h ); // set to size of window
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();

    //gluOrtho2D( 0.0, (float)w, 0.0, (float)h );

    glOrtho( 0, w, h, 0, -1, 1 );
    width = w;  // records width globally
    height = h; // records height globally

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}



void display(){
   // glClear(GL_COLOR_BUFFER_BIT); // clear window
   glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT );

   glColor3f(0,1,0);
   glLineWidth(1);

   glViewport(width/2.0, 0, width/2.0, height/2.0); //V1
   {

      projection(width/2.0, height/2.0, 1);
      gluLookAt(0, 0, m_slide, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
     // glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT );
      glPushMatrix();
      glRotatef(m_xtheta, 1,0,0);
      glRotatef(m_ytheta, 0,1,0);
      glRotatef(m_ztheta, 0,0,1);
      RenderGLScene(5, 5, 30);
      glPopMatrix();
   }

   glViewport(0, 0, width/2.0, height/2.0); //V2
   {

      projection(width/2.0, height/2.0, 1);
      gluLookAt(0.0, 40.0, 0.0, 0.0, 0.0, 10.0, 0.0, 1.0, 0.0);
     // glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT );
      glPushMatrix();
      RenderGLScene2(3, 3, 30);
      glPopMatrix();
   }

   glViewport(0, height/2.0, width/2.0, height/2.0); //V3
   {

      projection(width/2.0, height/2.0, 1);
      gluLookAt(40.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
     // glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT );
      glPushMatrix();
      RenderGLScene2(3, 3, 30);
      glPopMatrix();
   }

   glViewport(width/2.0, height/2.0, width/2.0, height/2.0); //V4
   {

      projection(width/2.0, height/2.0, 1);
      gluLookAt(0.0, 0.0, 40, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
     // glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT );
      glPushMatrix();
      RenderGLScene2(3, 3, 30);
      glPopMatrix();
   }

   glutSwapBuffers(); // display newly drawn image in window
}


void projection(int width, int height, int perspectiveORortho){
  float ratio = (float)width/height;
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  if (perspectiveORortho)
      gluPerspective(60, ratio, 1, 256);
  else
      glOrtho(-ratio, ratio, -ratio, ratio, 1, 1000);
  glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
}


void RenderGLScene(int base_radius, int top_radius, int height){
  // draw a cylinder or a sphere,
  // you will draw more objects in this function
  GLUquadricObj* quadObj = gluNewQuadric ();
  gluQuadricDrawStyle (quadObj, GLU_LINE);

  gluCylinder(quadObj, base_radius, top_radius, height, 20, 10);       //draw a cone shape cylinder
  DrawGround();                 //draw ground lines for reference
  gluDeleteQuadric(quadObj);
  glFlush();
}

void RenderGLScene2(int base_radius, int top_radius, int height){
  // draw a cylinder or a sphere,
  // you will draw more objects in this function
    GLUquadricObj* quadObj = gluNewQuadric ();
    gluQuadricDrawStyle (quadObj, GLU_LINE);

    DrawGround();                 //draw ground lines for reference

    //s1
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    gluCylinder(quadObj, base_radius/2, top_radius/2, 20, 20, 10);

    //b2
    gluSphere(quadObj, (base_radius + 0.5)/2 , 20, 10);

    //s2
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(m_lever, 0.0f, 1.0f, 0.0f);
    gluCylinder(quadObj, base_radius/2, top_radius/2, 10, 20, 10);

    //s3
    glRotatef(180.0f, 1.0f, 0.0f, 0.0f);
    gluCylinder(quadObj, base_radius/2, top_radius/2, 10, 20, 10);

    //b1
    glTranslated(0.0, 0.0 , 10.0);
    gluSphere(quadObj, (base_radius + 0.5)/2, 20, 10);

    //s4
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(m_lever, 0.0f, 1.0f, 0.0f);
    gluCylinder(quadObj, 0, top_radius/2, 10, 20, 10);

    //b4
    glTranslated(0.0, 0.0 , 10.0 + base_radius + 0.5);
    gluSphere(quadObj, base_radius + 0.5, 20, 10);

    //b3
    glTranslated(0.0, 20.0 , -(10.0 + base_radius + 0.5));
    gluSphere(quadObj, (base_radius + 0.5)/2, 20, 10);

    //s5
    glRotatef(-2*m_lever, 0.0f, 1.0f, 0.0f);
    gluCylinder(quadObj, 0, top_radius/2, 10, 20, 10);

    //b5
    glTranslated(0.0, 0.0 , 10.0 + base_radius + 0.5);
    gluSphere(quadObj, base_radius + 0.5, 20, 10);

    gluDeleteQuadric(quadObj);
    glFlush();
}


void DrawGround(){
  glBegin(GL_LINES);

  for(float i =-1; i<=1; )
   {
       glVertex3f(i*100.f, -10.f, -100.f);
       glVertex3f(i*100.f, -10.f, 100.f);
       i+=0.1;
   }
  for(float j =-1; j<=1; )
    {
       glVertex3f(-100.f, -10.f, j*100.f);
       glVertex3f(100.f, -10.f, j*100.f);
       j+=0.1;
    }
  glEnd();
}

void RollUp(float n){
  m_ztheta+=n;
  if(m_ztheta > 360) m_ztheta=-360;
}
void RollDown(float n){
  m_ztheta-=n;
  if(m_ztheta < -360) m_ztheta=360;
}
void PitchUp(float n){
  m_ytheta+=n;
  if(m_ytheta > 360) m_ytheta=-360;
}
void PitchDown(float n){
  m_ytheta-=n;
  if(m_ytheta < -360) m_ytheta=360;
}
void YawUp(float n){
  m_xtheta+=n;
  if(m_xtheta > 360) m_xtheta=-360;
}
void YawDown(float n){
  m_xtheta-=n;
  if(m_xtheta < -360) m_xtheta=360;
}
void SlideUp(float n){
  m_slide+=n;
}
void SlideDown(float n ){
  m_slide-=n;
}
void LeverUp(float n){
  m_lever+=n;
}
void LeverDown(float n){
  m_lever-=n;
}


