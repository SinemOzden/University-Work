
//#include <windows.h>  // for MS Windows
#include <GL/glut.h>  //Unix, GLUT, include glu.h and gl.h
//#include <GLUT/glut.h> //Max OSX
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int decide(int* x1, int* y1,int* x2, int* y2, int* dx, int* dy){
    int flag = 0;
    if(*dx>0 && *dy>=0 && abs(*dx>=*dy)){
        flag = 1;
    }
    else if(*dx>=0 && *dy>0 && abs(*dy>*dx)){
        flag = 2;
        swap(*x1,*y1);
        swap(*x2,*y2);
    }
    else if(*dx<0 && *dy>0 && abs(*dy>*dx)){
        flag = 3;
        *dx = abs(*dx);
        swap(*x1,*y1);
        swap(*x2,*y2);
    }
    else if(*dx<0 && *dy>0 && abs(*dx>=*dy)){
        flag = 4;
        *dx = abs(*dx);
    }
    else if(*dx<0 && *dy<=0 && abs(*dx>=*dy)){
        flag = 5;
        *dx = abs(*dx);
        *dy = abs(*dy);
    }
    else if(*dx<=0 && *dy<0 && abs(*dy>*dx)){
        flag = 6;
        *dx = abs(*dx);
        *dy = abs(*dy);
        swap(*x1,*y1);
        swap(*x2,*y2);
    }
    else if(*dx>0 && *dy<0 && abs(*dy>*dx)){
        flag = 7;
        *dx = abs(*dx);
        *dy = abs(*dy);
        swap(*x1,*y1);
        swap(*x2,*y2);
    }
    else if(*dx>0 && *dy<0 && abs(*dx>=*dy)){
        flag = 8;
        *dy = abs(*dy);
    }
    return flag;
}

void bresenham(int x1, int x2, int y1, int y2){

    int dx = x2 - x1;
    int dy = y2 - y1;

    int flag = decide(&x1,&y1,&x2,&y2,&dx,&dy);

    int d= 2*dy - dx;

    int deltaD1 = 2*dy;
    int deltaD2 = 2*dy - 2*dx;

    int y = y1;

    for (int x=x1; x<x2; x++){
        glBegin(GL_POINTS);
            glColor3f(0.0f, 1.0f, 0.0f);
            if(flag == 2 || flag == 3 || flag == 6 || flag == 7){
                glVertex2i(y,x);
            }
            else{
                glVertex2i(x,y);
            }
            if (d < 0){
                d = d + deltaD1;
            }
            else{
                if(y1>y2){
                    d += deltaD2;
                    y--;
                }
                else if(y1 == y2){
                    continue;
                    //do not delete this. this is crutial pls. this is part of the design
                }
                else{
                    d -= deltaD2;
                    y++;
                }
            }
            if(y==0){
                x=x2;
            }
        glEnd();
    }
}

void midPoint(int x1, int y1, int x2, int y2)
{
    // calculate dx & dy
    int dx = x2 - x1;
    int dy = y2 - y1;

    int flag = decide(&x1,&y1,&x2,&y2,&dx,&dy);

    // initial value of decision parameter d
    int d = dy - (dx/2);
    int y = y1;

    // iterate through value of X
    for (int x=x1; x < x2; x++)
    {
        glBegin(GL_POINTS);
            glColor3f(0.0f, 1.0f, 1.0f);
            if(flag == 2 || flag == 3 || flag == 6 || flag == 7){
                glVertex2i(y,x);
            }
            else{
                glVertex2i(x,y);
            }

            if (d < 0){
                d = d + dy;
            }
            else
            {
                if(y1>y2){
                    d += (dy - dx);
                    y--;
                }
                else if(y1 == y2){
                    continue;
                }
                else{
                    d -= (dy - dx);
                    y++;
                }
            }
        glEnd();
    }
}

void GL(){

    glLineWidth(1.0);
//Wake GL begin
    //W
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
        int x1 = 300, y1 = 50, x2 = 260, y2 = 90;
        glVertex2i(x1,y1);
        glVertex2i(x2,y2);

        x1 = 300, y1 = 50, x2 = 320, y2 = 70;
        glVertex2i(x1,y1);
        glVertex2i(x2,y2);


        x1 = 320, y1 = 70, x2 = 340, y2 = 50;
        glVertex2i(x1,y1);
        glVertex2i(x2,y2);

        x1 = 340, y1 = 50, x2 = 380, y2 = 90;
        glVertex2i(x1,y1);
        glVertex2i(x2,y2);

    //A
        x1 = 350, y1 = 50, x2 = 390, y2 = 90;
        glVertex2i(x1,y1);
        glVertex2i(x2,y2);

        x1 = 390, y1 = 90, x2 = 430, y2 = 50;
        glVertex2i(x1,y1);
        glVertex2i(x2,y2);

        x1 = 370, y1 = 70, x2 = 410, y2 = 70;
        glVertex2i(x1,y1);
        glVertex2i(x2,y2);

    //K
        x1 = 440, y1 = 50, x2 = 440, y2 = 90;
        glVertex2i(x1,y1);
        glVertex2i(x2,y2);

        x1 = 440, y1 = 70, x2 = 460, y2 = 90;
        glVertex2i(x1,y1);
        glVertex2i(x2,y2);

        x1 = 460, y1 = 50, x2 = 440, y2 = 70;
        glVertex2i(x1,y1);
        glVertex2i(x2,y2);

        //E
        x1 = 470, y1 = 50, x2 = 470, y2 = 90;
        glVertex2i(x1,y1);
        glVertex2i(x2,y2);

        x1 = 470, y1 = 90, x2 = 499, y2 = 90;
        glVertex2i(x1,y1);
        glVertex2i(x2,y2);

        x1 = 470, y1 = 70, x2 = 499, y2 = 70;
        glVertex2i(x1,y1);
        glVertex2i(x2,y2);

        x1 = 470, y1 = 50, x2 = 499, y2 = 50;
        glVertex2i(x1,y1);
        glVertex2i(x2,y2);
    glEnd();
    //Wake GL end

    //Stipple Begin

    glEnable(GL_LINE_STIPPLE);
    x1 = 250.0, y1 = 200.0, x2 = 470.0, y2 = 200.0;
    glLineStipple(1, 0x00FF);
    glBegin(GL_LINES);
        glVertex2f((x1),(y1));
        glVertex2f((x2),(y2));
    glEnd();

    x1 = 250.0, y1 = 195.0, x2 = 470.0, y2 = 195.0;
    glLineStipple(2, 0x00FF);
    glBegin(GL_LINES);
        glVertex2f((x1),(y1));
        glVertex2f((x2),(y2));
    glEnd();

    glLineWidth(2.0);
    x1 = 250.0, y1 = 190.0, x2 = 470.0, y2 = 190.0;
    glLineStipple(2, 0x00FF);
    glBegin(GL_LINES);
        glVertex2f((x1),(y1));
        glVertex2f((x2),(y2));
    glEnd();


    x1 = 250.0, y1 = 185.0, x2 = 470.0, y2 = 185.0;
    glLineStipple(4, 0x0CCF);
    glBegin(GL_LINES);
        glVertex2f((x1),(y1));
        glVertex2f((x2),(y2));
    glEnd();

    glLineWidth(4.0);
    x1 = 250.0, y1 = 180.0, x2 = 470.0, y2 = 180.0;
    glLineStipple(2, 0x0FFF);
    glBegin(GL_LINES);
        glVertex2f((x1),(y1));
        glVertex2f((x2),(y2));
    glEnd();

    glDisable(GL_LINE_STIPPLE);

    //Stipple End
}

void display() {
    //Wake begin
    //W
    glPointSize(1.0);
    int x1 = 50, y1 = 50, x2 = 10, y2 = 90;
    bresenham(x1,x2,y1,y2);

    x1 = 50, y1 = 50, x2 = 70, y2 = 70;
    bresenham(x1,x2,y1,y2);

    x1 = 70, y1 = 70, x2 = 90, y2 = 50;
    bresenham(x1,x2,y1,y2);

    x1 = 90, y1 = 50, x2 = 130, y2 = 90;
    bresenham(x1,x2,y1,y2);

    //A
    x1 = 100, y1 = 50, x2 = 140, y2 = 90;
    bresenham(x1,x2,y1,y2);

    x1 = 140, y1 = 90, x2 = 180, y2 = 50;
    bresenham(x1,x2,y1,y2);

    x1 = 120, y1 = 70, x2 = 160, y2 = 70;
    bresenham(x1,x2,y1,y2);

    //K
    x1 = 190, y1 = 50, x2 = 190, y2 = 90;
    bresenham(x1,x2,y1,y2);

    x1 = 190, y1 = 70, x2 = 210, y2 = 90;
    bresenham(x1,x2,y1,y2);

    x1 = 210, y1 = 50, x2 = 190, y2 = 70;
    bresenham(x1,x2,y1,y2);

    //E
    x1 = 220, y1 = 50, x2 = 220, y2 = 90;
    bresenham(x1,x2,y1,y2);

    x1 = 220, y1 = 90, x2 = 250, y2 = 90;
    bresenham(x1,x2,y1,y2);

    x1 = 220, y1 = 70, x2 = 250, y2 = 70;
    bresenham(x1,x2,y1,y2);

    x1 = 220, y1 = 50, x2 = 250, y2 = 50;
    bresenham(x1,x2,y1,y2);
    //Wake end

    //coordinate
    //c-y
    x1 = 100, y1 = 300, x2 = 100, y2 = 450;
    bresenham(x1,x2,y1,y2);

    //c-x
    x1 = 100, y1 = 300, x2 = 250, y2 = 300;
    bresenham(x1,x2,y1,y2);

    //c-z
    x1 = 25, y1 = 225, x2 = 100, y2 = 300;
    bresenham(x1,x2,y1,y2);

    //X
    x1 = 260, y1 = 300, x2 = 280, y2 = 280;
    bresenham(x1,x2,y1,y2);

    x1 = 260, y1 = 280, x2 = 280, y2 = 300;
    bresenham(x1,x2,y1,y2);

    //Y
    x1 = 100, y1 = 480, x2 = 110, y2 = 470;
    bresenham(x1,x2,y1,y2);

    x1 = 110, y1 = 470, x2 = 120, y2 = 480;
    bresenham(x1,x2,y1,y2);

    x1 = 110, y1 = 460, x2 = 110, y2 = 470;
    bresenham(x1,x2,y1,y2);

    //Z

    x1 = 5, y1 = 250, x2 = 20, y2 = 250;
    bresenham(x1,x2,y1,y2);

    x1 = 5, y1 = 235, x2 = 20, y2 = 250;
    bresenham(x1,x2,y1,y2);

    x1 = 5, y1 = 235, x2 = 20, y2 = 235;
    bresenham(x1,x2,y1,y2);

    //460 Start

    //4
    x1 = 136, y1 = 310, x2 = 136, y2 = 390;
    bresenham(x1,x2,y1,y2);

    x1 = 110, y1 = 350, x2 = 130, y2 = 390;
    bresenham(x1,x2,y1,y2);

    x1 = 110, y1 = 350, x2 = 150, y2 = 350;
    bresenham(x1,x2,y1,y2);

    //6
    x1 = 160, y1 = 310, x2 = 160, y2 = 390;
    bresenham(x1,x2,y1,y2);

    x1 = 160, y1 = 390, x2 = 190, y2 = 390;
    bresenham(x1,x2,y1,y2);

    x1 = 160, y1 = 350, x2 = 190, y2 = 350;
    bresenham(x1,x2,y1,y2);

    x1 = 160, y1 = 310, x2 = 190, y2 = 310;
    bresenham(x1,x2,y1,y2);

    x1 = 190, y1 = 310, x2 = 190, y2 = 350;
    bresenham(x1,x2,y1,y2);

    //0
    x1 = 200, y1 = 310, x2 = 200, y2 = 390;
    bresenham(x1,x2,y1,y2);

    x1 = 200, y1 = 390, x2 = 230, y2 = 390;
    bresenham(x1,x2,y1,y2);

    x1 = 200, y1 = 310, x2 = 230, y2 = 310;
    bresenham(x1,x2,y1,y2);

    x1 = 230, y1 = 310, x2 = 230, y2 = 390;
    bresenham(x1,x2,y1,y2);
    //460 End

    //560 Start
    //5
    x1 = 110, y1 = 290, x2 = 140, y2 = 290;
    bresenham(x1,x2,y1,y2);

    x1 = 85, y1 = 265, x2 = 110, y2 = 290;
    bresenham(x1,x2,y1,y2);

    x1 = 85, y1 = 265, x2 = 115, y2 = 265;
    bresenham(x1,x2,y1,y2);

    x1 = 90, y1 = 240, x2 = 115, y2 = 265;
    bresenham(x1,x2,y1,y2);

    x1 = 65, y1 = 240, x2 = 90, y2 = 240;
    bresenham(x1,x2,y1,y2);

    //6
    x1 = 150, y1 = 290, x2 = 180, y2 = 290;
    bresenham(x1,x2,y1,y2);

    x1 = 100, y1 = 240, x2 = 150, y2 = 290;
    bresenham(x1,x2,y1,y2);

    x1 = 125, y1 = 265, x2 = 155, y2 = 265;
    bresenham(x1,x2,y1,y2);

    x1 = 100, y1 = 240, x2 = 130, y2 = 240;
    bresenham(x1,x2,y1,y2);

    x1 = 130, y1 = 240, x2 = 155, y2 = 265;
    bresenham(x1,x2,y1,y2);

    //0
    x1 = 190, y1 = 290, x2 = 215, y2 = 290;
    bresenham(x1,x2,y1,y2);

    x1 = 140, y1 = 240, x2 = 165, y2 = 240;
    bresenham(x1,x2,y1,y2);

    x1 = 140, y1 = 240, x2 = 190, y2 = 290;
    bresenham(x1,x2,y1,y2);

    x1 = 165, y1 = 240, x2 = 215, y2 = 290;
    bresenham(x1,x2,y1,y2);
    //560 End

    //CS Begin
    //S
    x1 = 65, y1 = 335, x2 = 90, y2 = 360;
    bresenham(x1,x2,y1,y2);

    x1 = 65, y1 = 310, x2 = 65, y2 = 335;
    bresenham(x1,x2,y1,y2);

    x1 = 65, y1 = 310, x2 = 90, y2 = 335;
    bresenham(x1,x2,y1,y2);

    x1 = 90, y1 = 310, x2 = 90, y2 = 335;
    bresenham(x1,x2,y1,y2);

    x1 = 65, y1 = 285, x2 = 90, y2 = 310;
    bresenham(x1,x2,y1,y2);
    //C
    x1 = 30, y1 = 300, x2 = 55, y2 = 325;
    bresenham(x1,x2,y1,y2);

    x1 = 30, y1 = 250, x2 = 30, y2 = 300;
    bresenham(x1,x2,y1,y2);

    x1 = 30, y1 = 250, x2 = 55, y2 = 275;
    bresenham(x1,x2,y1,y2);
    //CS End


    x1 = 10, y1 = 200, x2 = 15, y2 = 200;
    for(int x=0; x<22; x++){
        midPoint(x1,y1,x2,y2);
        x1+=10; x2+=10;
    }

    x1 = 10, y1 = 195, x2 = 20, y2 = 195;
    for(int x=0; x<15; x++){
        midPoint(x1,y1,x2,y2);
        x1+=15; x2+=15;
    }
    glFlush();  // Render now

    glPointSize(2.0);
    x1 = 10, y1 = 190, x2 = 20, y2 = 190;
    for(int x=0; x<15; x++){
        midPoint(x1,y1,x2,y2);
        x1+=15; x2+=15;
    }

    x1 = 10, y1 = 185, x2 = 15, y2 = 185;
    for(int x=0; x<12; x++){
        if(x%3==2){
            x2+=10;
        }
        else if(x%3==0 && x!=0){
            x1+=10;
        }
        midPoint(x1,y1,x2,y2);
        x1+=15; x2+=15;
    }

    glPointSize(5.0);
    x1 = 10, y1 = 180, x2 = 20, y2 = 180;
    for(int x=0; x<15; x++){
        midPoint(x1,y1,x2,y2);
        x1+=15; x2+=15;
    }

    glFlush();  // Render now

    GL();

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glFlush();  // Render now
}

void init(void) {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    gluOrtho2D(0.0,500.0,0.0,500.0);
    glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);                 // Initialize GLUT
    glutInitWindowSize(1000, 1000);   // Set the window's initial width & height
    glutInitWindowPosition(1000, 1000); // Position the window's initial top-left corner

    glutCreateWindow("Hw1");
    init();
    glutDisplayFunc(display); // Register display callback handler for window re-paint

    glutMainLoop();           // Enter the event-processing loop
    return 0;
}
