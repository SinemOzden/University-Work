#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<GL/glut.h>   
#include<vector>
#include<assert.h>
#include "menu.h"
#include "triangle.h"

using namespace std;

void projection(int width, int height, int perspectiveORortho){
  float ratio = (float)width/height;
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  if (perspectiveORortho)
      gluPerspective(60, ratio, 1, 1000);
  else 
      glOrtho(-ratio, ratio, -ratio, ratio, 1, 1000);
  glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
}


void setup()
{
    glClearColor(0, 0, 0, 1.0); // *should* display black background

    { 
        // generate some data for the cubicPoints, bezierPoints, bsplinePoints
        cubicPoints.push_back(Position(100, 200, 0));
        cubicPoints.push_back(Position(200, 300, 0));
        cubicPoints.push_back(Position(300, 300, 0));
        cubicPoints.push_back(Position(400, 200, 0));
    }
 
    {// generate the 4*4 control points.
        int i, j;
        for( i = 0; i < 4; i++){
            for(j = 0; j < 4; j++){
                controlPoints.push_back(Position(j * 20, 0, i * 20));
            }
        }
    
    }
   
}

void reshape( int w, int h ){
   glViewport( 0, 0, (GLsizei)w, (GLsizei)h ); // set to size of window
   glMatrixMode( GL_PROJECTION );
    glLoadIdentity();

    //gluOrtho2D( 0.0, (float)w, 0.0, (float)h );

    glOrtho( 0, w, h, 0, -1, 1 );
    WIDTH_WINDOWS = w;  // records width globally
    HEIGHT_WINDOWS = h; // records height globally

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void draw_controls(){
    glPointSize(15);
    glBegin(GL_POINTS);
    glColor3f(5, 0, 250);
    for (int i = 0; i < controls.size(); ++i) {
        for (int j = 0; j < controls[0].size(); ++j) {
            glVertex3f(controls[i][j].x, controls[i][j].y, controls[i][j].z);
        }
    }
    glEnd();
    glPointSize(1);
}

void DrawBezierSurface(){
  // draw your own Bezier Surface here.
    bezierCalculation();
    if(!triangles.empty()){
        triangles.clear();
    }
    
    makeTriangles();
    drawTriangles();
    glDisable(GL_LIGHTING);
    draw_controls();
}

void draw_axis(){
    glColor3f(1,1,1);
    glLineWidth(5);
    glBegin(GL_LINES);
        glVertex3f(0, -45, 0);
        glVertex3f(0, 15, 0);
        glVertex3f(0, 0, -25);
        glVertex3f(0, 0, 20);
        glVertex3f(-25, 0, 0);
        glVertex3f(20, 0, 0);
    glEnd();
}

void display(){
   // glClear(GL_COLOR_BUFFER_BIT); // clear window
   glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT );
   glEnable(GL_DEPTH_TEST); 
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho( 0, WIDTH_WINDOWS, HEIGHT_WINDOWS, 0, -1, 1 );
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
  
    if(1){
        //set gluLookAt and gluPerspective
        projection(WIDTH_WINDOWS, HEIGHT_WINDOWS, 1); // set projection.
        gluLookAt(camx, camy, 25, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
        //camera.x = camera.y = camera.z = m_slide;
        //gluLookAt(camera.x, camera.y, camera.z, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); 
        
        if(flatShading||smooth){  
            glPushMatrix();
            glTranslatef(-lightPosition[0], -lightPosition[1], -lightPosition[2]);
            glutSolidSphere(1,16,16);
            glPopMatrix();          
            // lighting
            glMaterialfv(GL_FRONT, GL_AMBIENT, matAmbient);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiffuse);
            glMaterialfv(GL_FRONT, GL_SPECULAR, matSpecular);
            glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

            //flat shading or smooth shading
            if(flatShading) glShadeModel(GL_FLAT);
            else            glShadeModel(GL_SMOOTH);

            glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
            glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
            glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);

            //GLfloat lightPos[] = {-10.0, -15.0, -10.0,0.0};
            glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
            glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, lightDirection);
            glEnable(GL_LIGHTING);
            glEnable(GL_LIGHT0);
        }
       
        DrawBezierSurface();
        draw_axis();
    }
    glutSwapBuffers(); // display newly drawn image in window


}

void init_control_points(){
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            controls[i][j].x = (i*4+i);
            controls[i][j].z = (j*4+j);
            //printf("cont:%d\n", controls[i][j].y);
        }
    }
}

int main(int argc, char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(1000,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Spline and Surface Demo");
        setup();
        init_control_points();
        
            // initializing callbacks
     glutReshapeFunc(reshape);
     glutDisplayFunc(display);
    glutSpecialFunc(specialKey);
      glutKeyboardFunc(keyboard);
    
  
    //Creates Menu on Right Click
    CreateMenu();

     glutMainLoop();
     return 0;

}
