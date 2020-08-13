
//#include <windows.h>  // for MS Windows
#include <GL/glut.h>  //Unix, GLUT, include glu.h and gl.h
//#include <GLUT/glut.h> //Max OSX
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

struct Line{
    int x1,y1,x2,y2;
};

struct Point{
    int x,y;
};
bool clickR=false;
bool clickL=false;
bool clickW=false;
bool clickV=false;
bool moveW = false;

int xwmin = 100, xwmax = 600, ywmin = 100, ywmax = 600;

int xvmin = 700, xvmax = 900, yvmin = 100, yvmax = 300;

int holdx, holdy;

float seedx,seedy;

vector<Line> lineVec;
vector<Line> resizedLine;
vector<Line> clippingWind;
vector<Line> viewP;
vector<Point> newPoly;

void display(void){
	Line line;

	glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f);
        for(int i=0; i<lineVec.size(); i++){
            glVertex2f(lineVec.at(i).x1, lineVec.at(i).y1);
            glVertex2f(lineVec.at(i).x2, lineVec.at(i).y2);
        }

    glEnd();

	glEnable(GL_LINE_STIPPLE);
	glLineStipple(1, 0x00FF);
	glBegin(GL_LINE_LOOP);
        glColor3f(1.0, 0.0, 0.0);
		glVertex2f(xwmin,ywmin);
		glVertex2f(xwmax,ywmin);
        glVertex2f(xwmax,ywmax);
        glVertex2f(xwmin,ywmax);


	glEnd();

    glDisable(GL_LINE_STIPPLE);


    glEnable(GL_LINE_STIPPLE);

    glBegin(GL_LINE_LOOP);
        glColor3f(1.0f, 1.0f, 0.0f);
		glVertex2f(xvmin,yvmin);
		glVertex2f(xvmin,yvmax);
        glVertex2f(xvmax,yvmax);
        glVertex2f(xvmax,yvmin);

    glEnd();
    glDisable(GL_LINE_STIPPLE);

    glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f);
        for(int i=0; i<resizedLine.size(); i++){
            glVertex2f(resizedLine.at(i).x1, resizedLine.at(i).y1);
            glVertex2f(resizedLine.at(i).x2, resizedLine.at(i).y2);
        }

    glEnd();

    glFlush();

    //glutSwapBuffers();
}

int xIntersect(Line line1, Line line2) {
    int num = (line1.x1*line1.y2 - line1.y1*line1.x2) * (line2.x1-line2.x2) -
              (line1.x1-line1.x2) * (line2.x1*line2.y2 - line2.x2*line2.y1);
    int den = (line1.x1-line1.x2) * (line2.y1-line2.y2) - (line1.y1-line1.y2) * (line2.x1-line2.x2);
    return num/den;
}

int yIntersect(Line line1, Line line2) {
    int num = (line1.x1*line1.y2 - line1.y1*line1.x2) * (line2.y1-line2.y2) -
              (line1.y1-line1.y2) * (line2.x1*line2.y2 - line2.x2*line2.y1);
    int den = (line1.x1-line1.x2) * (line2.y1-line2.y2) - (line1.y1-line1.y2) * (line2.x1-line2.x2);
    return num/den;
}

void update(){
printf("update\n");
    Line line;

    int x1 = xwmin, y1 = ywmin, x2 = xwmin, y2 = ywmax;//left
    line.x1 = x1;
    line.y1 = y1;
    line.x2 = x2;
    line.y2 = y2;
    clippingWind.at(0) = line;

    x1 = xwmax, y1 = ywmin, x2 = xwmax, y2 = ywmax;//right
    line.x1 = x1;
    line.y1 = y1;
    line.x2 = x2;
    line.y2 = y2;
    clippingWind.at(1) = line;

	x1 = xwmin, y1 = ywmin, x2 = xwmax, y2 = ywmin;//bottom
    line.x1 = x1;
    line.y1 = y1;
    line.x2 = x2;
    line.y2 = y2;
    clippingWind.at(2) = line;

    x1 = xwmax, y1 = ywmax, x2 = xwmin, y2 = ywmax;//top
    line.x1 = x1;
    line.y1 = y1;
    line.x2 = x2;
    line.y2 = y2;
    clippingWind.at(3) = line;

    //int xvmin = 700, xvmax = 900, yvmin = 100, yvmax = 300;

    x1 = xvmin, y1 = yvmin, x2 = xvmin, y2 = yvmax;//left
    line.x1 = x1;
    line.y1 = y1;
    line.x2 = x2;
    line.y2 = y2;
    viewP.at(0) = line;

    x1 = xvmax, y1 = yvmin, x2 = xvmax, y2 = yvmax;//right
    line.x1 = x1;
    line.y1 = y1;
    line.x2 = x2;
    line.y2 = y2;
    viewP.at(1) = line;

	x1 = xvmin, y1 = yvmin, x2 = xvmax, y2 = yvmin;//bottom
    line.x1 = x1;
    line.y1 = y1;
    line.x2 = x2;
    line.y2 = y2;
    viewP.at(2) = line;

    x1 = xvmax, y1 = yvmax, x2 = xvmin, y2 = yvmax;//top
    line.x1 = x1;
    line.y1 = y1;
    line.x2 = x2;
    line.y2 = y2;
    viewP.at(3) = line;
}

void clip(Line line, int boundary,int flag){
    Point p;
    vector<Point> temp;

    if(flag==0){
        switch (boundary) {
            case 0://left
                for(int i=0;i<lineVec.size();i++){
                    printf("pol x1:%d win x1:%d pol x2:%d win x2:%d\n",lineVec.at(i).x1,line.x1,lineVec.at(i).x2,line.x2);
                    if(lineVec.at(i).x1>=line.x1 && lineVec.at(i).x2>=line.x2){//i-i
                        p.x = lineVec.at(i).x2;
                        p.y = lineVec.at(i).y2;
                        temp.push_back(p);
                        printf("left - in-in %d %d\n",p.x,p.y);
                    }
                    else if(lineVec.at(i).x1>=line.x1 && lineVec.at(i).x2<line.x2){//i-o
                        p.x = line.x1;
                        p.y = yIntersect(lineVec.at(i),line);
                        temp.push_back(p);
                        printf("left - in-o %d %d\n",p.x,p.y);
                    }
                    else if(lineVec.at(i).x1<line.x1 && lineVec.at(i).x2>=line.x2){//o-i
                        p.x = line.x1;
                        p.y = yIntersect(lineVec.at(i),line);
                        temp.push_back(p);
                        printf("left - o-i n %d %d\n",p.x,p.y);

                        p.x = lineVec.at(i).x2;
                        p.y = lineVec.at(i).y2;
                        temp.push_back(p);
                        printf("left - o-i o %d %d\n",p.x,p.y);
                    }
                    else{
                        printf("left - o-o %d %d\n",p.x,p.y);
                        continue;
                    }
                }
                break;
            case 1://right
                for(int i=0;i<lineVec.size();i++){
                    if(lineVec.at(i).x1<=line.x1 && lineVec.at(i).x2<=line.x2){//i-i
                        p.x = lineVec.at(i).x2;
                        p.y = lineVec.at(i).y2;
                        temp.push_back(p);
                        printf("left - in-in %d %d\n",p.x,p.y);
                    }
                    else if(lineVec.at(i).x1<=line.x1 && lineVec.at(i).x2>line.x2){//i-o
                        p.x = line.x1;
                        p.y = yIntersect(lineVec.at(i),line);
                        temp.push_back(p);
                        printf("left - in-o %d %d\n",p.x,p.y);
                    }
                    else if(lineVec.at(i).x1>line.x1 && lineVec.at(i).x2<=line.x2){//o-i
                        p.x = line.x1;
                        p.y = yIntersect(lineVec.at(i),line);
                        temp.push_back(p);
                        printf("left - o-i n %d %d\n",p.x,p.y);

                        p.x = lineVec.at(i).x2;
                        p.y = lineVec.at(i).y2;
                        temp.push_back(p);
                        printf("left - o-i o %d %d\n",p.x,p.y);
                    }
                    else{
                        printf("left - o-o %d %d\n",p.x,p.y);
                        continue;
                    }
                }
                break;
            case 2://bottom
                for(int i=0;i<lineVec.size();i++){
                    if(lineVec.at(i).y1>=line.y1 && lineVec.at(i).y2>=line.y2){//i-i
                        p.x = lineVec.at(i).x2;
                        p.y = lineVec.at(i).y2;
                        temp.push_back(p);
                        printf("left - in-in %d %d\n",p.x,p.y);
                    }
                    else if(lineVec.at(i).y1>=line.y1 && lineVec.at(i).y2<line.y2){//i-o
                        p.x = xIntersect(lineVec.at(i),line);
                        p.y = line.y1;
                        temp.push_back(p);
                        printf("left - in-o %d %d\n",p.x,p.y);
                    }
                    else if(lineVec.at(i).y1<line.y1 && lineVec.at(i).y2>=line.y2){//o-i
                        p.x = xIntersect(lineVec.at(i),line);
                        p.y = line.y1;
                        temp.push_back(p);
                        printf("left - o-i n %d %d\n",p.x,p.y);

                        p.x = lineVec.at(i).x2;
                        p.y = lineVec.at(i).y2;
                        temp.push_back(p);
                        printf("left - o-i o %d %d\n",p.x,p.y);
                    }
                    else{
                        printf("left - o-o %d %d\n",p.x,p.y);
                        continue;
                    }
                }
                break;
            case 3://top
                for(int i=0;i<lineVec.size();i++){
                    if(lineVec.at(i).y1<=line.y1 && lineVec.at(i).y2<=line.y2){//i-i
                        p.x = lineVec.at(i).x2;
                        p.y = lineVec.at(i).y2;
                        temp.push_back(p);
                        printf("left - in-in %d %d\n",p.x,p.y);
                    }
                    else if(lineVec.at(i).y1<=line.y1 && lineVec.at(i).y2>line.y2){//i-o
                        p.x = xIntersect(lineVec.at(i),line);
                        p.y = line.y1;
                        temp.push_back(p);
                        printf("left - in-o %d %d\n",p.x,p.y);
                    }
                    else if(lineVec.at(i).y1>line.y1 && lineVec.at(i).y2<=line.y2){//o-i
                        p.x = xIntersect(lineVec.at(i),line);
                        p.y = line.y1;
                        temp.push_back(p);
                        printf("left - o-i n %d %d\n",p.x,p.y);

                        p.x = lineVec.at(i).x2;
                        p.y = lineVec.at(i).y2;
                        temp.push_back(p);
                        printf("left - o-i o %d %d\n",p.x,p.y);
                    }
                    else{
                        printf("left - o-o %d %d\n",p.x,p.y);
                        continue;
                    }
                }
                break;
        }
    }
    else{
        switch (boundary) {
            case 0://left
                for(int i=0;i<resizedLine.size();i++){
                    printf("v pol x1:%d win x1:%d pol x2:%d win x2:%d\n",lineVec.at(i).x1,line.x1,lineVec.at(i).x2,line.x2);
                    if(resizedLine.at(i).x1>=line.x1 && resizedLine.at(i).x2>=line.x2){//i-i
                        p.x = resizedLine.at(i).x2;
                        p.y = resizedLine.at(i).y2;
                        temp.push_back(p);
                        printf("v left - in-in %d %d\n",p.x,p.y);
                    }
                    else if(resizedLine.at(i).x1>=line.x1 && resizedLine.at(i).x2<line.x2){//i-o
                        p.x = line.x1;
                        p.y = yIntersect(resizedLine.at(i),line);
                        temp.push_back(p);
                        printf("v left - in-o %d %d\n",p.x,p.y);
                    }
                    else if(resizedLine.at(i).x1<line.x1 && resizedLine.at(i).x2>=line.x2){//o-i
                        p.x = line.x1;
                        p.y = yIntersect(resizedLine.at(i),line);
                        temp.push_back(p);
                        printf("v left - o-i n %d %d\n",p.x,p.y);

                        p.x = resizedLine.at(i).x2;
                        p.y = resizedLine.at(i).y2;
                        temp.push_back(p);
                        printf("v left - o-i o %d %d\n",p.x,p.y);
                    }
                    else{
                        printf("v left - o-o %d %d %d %d\n",p.x,p.y,line.x1,line.x2);
                        continue;
                    }
                }
                break;
            case 1://right
                for(int i=0;i<resizedLine.size();i++){
                    if(resizedLine.at(i).x1<=line.x1 && resizedLine.at(i).x2<=line.x2){//i-i
                        p.x = resizedLine.at(i).x2;
                        p.y = resizedLine.at(i).y2;
                        temp.push_back(p);
                        printf("v right - in-in %d %d\n",p.x,p.y);
                    }
                    else if(resizedLine.at(i).x1<=line.x1 && resizedLine.at(i).x2>line.x2){//i-o
                        p.x = line.x1;
                        p.y = yIntersect(resizedLine.at(i),line);
                        temp.push_back(p);
                        printf("v right - in-o %d %d\n",p.x,p.y);
                    }
                    else if(resizedLine.at(i).x1>line.x1 && resizedLine.at(i).x2<=line.x2){//o-i
                        p.x = line.x1;
                        p.y = yIntersect(resizedLine.at(i),line);
                        temp.push_back(p);
                        printf("v right - o-i n %d %d\n",p.x,p.y);

                        p.x = resizedLine.at(i).x2;
                        p.y = resizedLine.at(i).y2;
                        temp.push_back(p);
                        printf("v right - o-i o %d %d\n",p.x,p.y);
                    }
                    else{
                        printf("v right - o-o %d %d\n",p.x,p.y);
                        continue;
                    }
                }
                break;
            case 2://bottom
                for(int i=0;i<resizedLine.size();i++){
                    if(resizedLine.at(i).y1>=line.y1 && resizedLine.at(i).y2>=line.y2){//i-i
                        p.x = resizedLine.at(i).x2;
                        p.y = resizedLine.at(i).y2;
                        temp.push_back(p);
                        printf("v bottom - in-in %d %d\n",p.x,p.y);
                    }
                    else if(resizedLine.at(i).y1>=line.y1 && resizedLine.at(i).y2<line.y2){//i-o
                        p.x = xIntersect(resizedLine.at(i),line);
                        p.y = line.y1;
                        temp.push_back(p);
                        printf("v bottom - in-o %d %d\n",p.x,p.y);
                    }
                    else if(resizedLine.at(i).y1<line.y1 && resizedLine.at(i).y2>=line.y2){//o-i
                        p.x = xIntersect(resizedLine.at(i),line);
                        p.y = line.y1;
                        temp.push_back(p);
                        printf("v bottom - o-i n %d %d\n",p.x,p.y);

                        p.x = resizedLine.at(i).x2;
                        p.y = resizedLine.at(i).y2;
                        temp.push_back(p);
                        printf("v bottom - o-i o %d %d\n",p.x,p.y);
                    }
                    else{
                        printf("v bottom - o-o %d %d\n",p.x,p.y);
                        continue;
                    }
                }
                break;
            case 3://top
                for(int i=0;i<resizedLine.size();i++){
                    if(resizedLine.at(i).y1<=line.y1 && resizedLine.at(i).y2<=line.y2){//i-i
                        p.x = resizedLine.at(i).x2;
                        p.y = resizedLine.at(i).y2;
                        temp.push_back(p);
                        printf("v top - in-in %d %d\n",p.x,p.y);
                    }
                    else if(resizedLine.at(i).y1<=line.y1 && resizedLine.at(i).y2>line.y2){//i-o
                        p.x = xIntersect(resizedLine.at(i),line);
                        p.y = line.y1;
                        temp.push_back(p);
                        printf("v top - in-o %d %d\n",p.x,p.y);
                    }
                    else if(resizedLine.at(i).y1>line.y1 && resizedLine.at(i).y2<=line.y2){//o-i
                        p.x = xIntersect(resizedLine.at(i),line);
                        p.y = line.y1;
                        temp.push_back(p);
                        printf("v top - o-i n %d %d\n",p.x,p.y);

                        p.x = resizedLine.at(i).x2;
                        p.y = resizedLine.at(i).y2;
                        temp.push_back(p);
                        printf("v top - o-i o %d %d\n",p.x,p.y);
                    }
                    else{
                        printf("v top - o-o %d %d %d %d\n",p.x,p.y,line.x1,line.x2);
                        continue;
                    }
                }
                break;
        }
    }

    newPoly.clear();
    for(int i=0;i<temp.size();i++){
        newPoly.push_back(temp.at(i));
    }
}

void SuHo(int flag){
    Line line;
    for(int i=0;i <4;i++){
    printf("clip %d\n",i);
        if(flag==0){
            clip(clippingWind.at(i),i,0);
            lineVec.clear();
        }
        else{
        printf("suho1 \n");
            clip(viewP.at(i),i,1);
            resizedLine.clear();
        }

        for(int j=0;j<newPoly.size();j++){
            line.x1 = newPoly.at(j).x;
            line.y1 = newPoly.at(j).y;
            printf("j:%d\n",j);
            if(newPoly.size()<=j+1){
                printf("a\n");
                line.x2 = newPoly.at(0).x;
                line.y2 = newPoly.at(0).y;
            }
            else{
                line.x2 = newPoly.at((j+1)).x;
                line.y2 = newPoly.at((j+1)).y;
            }
            printf("flag: %d\n",flag);
            if(flag==0){
                lineVec.push_back(line);
            }
            else{
                resizedLine.push_back(line);
                printf("suho1 2\n");
            }
        }
    }

}

void boundFill4(float x, float y){

    float pixels[ 3 ];
    glReadPixels( x, y, 1, 1, GL_RGB, GL_FLOAT, &pixels );

    if((pixels[0] != 1.0 && pixels[1] != 1.0 && pixels[2] != 1.0) ||(
       pixels[0] != 1.0 && pixels[1] != 0.0 && pixels[2] ==1.0))
    {
        glBegin(GL_POINTS);
            glColor3f(1.0, 0.0, 1.0);
            glVertex2f(x,y);
        glEnd();
        glFlush();
        boundFill4(x + 1, y);
        boundFill4(x - 1, y);
        boundFill4(x, y + 1);
        boundFill4(x, y - 1);
    }
}

void boundFill(){
    //find inner point
    boundFill4(seedx,seedy);

    printf("Filling Completed\n");
    glFlush();
}

void resize(Line line){
    Line newline;
    newline.x1 = (line.x1-xwmin)*(xvmax -xvmin)/(xwmax - xwmin) +xvmin;
    newline.x2 = (line.x2-xwmin)*(xvmax -xvmin)/(xwmax - xwmin) +xvmin;
    newline.y1 = (line.y1-ywmin)*(yvmax -yvmin)/(ywmax - ywmin) +yvmin;
    newline.y2 = (line.y2-ywmin)*(yvmax -yvmin)/(ywmax - ywmin) +yvmin;
    resizedLine.push_back(newline);
}

void Win_View(){
    resizedLine.clear();
    printf("len: %d\n", resizedLine.size());
    for (int i =0; i<lineVec.size(); i++){
        resize(lineVec.at(i));
    }
    SuHo(1);
}

void mouse(int button, int state, int x, int y) {

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        //printf("x : %d xwmax-50 : %d xwmax+50: %d\n", x,xwmax-50,xwmax+50);
        //printf("1000-y : %d ywmax-50 : %d ywmax+50: %d\n", 1000-y,ywmax-50,ywmax+50);
        if(x >= xvmax-20 && x <= xvmax+20 && 1000-y >= yvmax-20 && 1000-y<=yvmax+20){
            clickV = true;
            clickW = false;
            moveW = false;
        }
        else if(x >= xwmax-20 && x <= xwmax+20 && 1000-y >= ywmax-20 && 1000-y<=ywmax+20){
            clickW = true;
            clickV = false;
            clickL =false;
            moveW = false;
        }
        else if((x>=xwmin-20 && x <= xwmax+20)&& (1000-y >= ywmax-20 && 1000-y<=ywmax+20)){
            moveW = true;
            clickV = false;
            clickL =false;
            clickW = false;

            holdx = x;
            holdy = 1000-y;
        }
        else{
            glutDetachMenu(GLUT_RIGHT_BUTTON);
            Line line;
            if(clickR){
                lineVec.clear();
                glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
                glClear(GL_COLOR_BUFFER_BIT);
                clickR =false;
            }
            line.x1 = x;
            line.y1 = (1000-y);
            line.x2 = x;
            line.y2 = (1000-y);
            lineVec.push_back(line);
            clickL = true;
            clickV = false;
            clickW = false;
            moveW = false;
        }
    }

    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        lineVec.at(lineVec.size()-1).x2 = x;
        lineVec.at(lineVec.size()-1).y2 = (1000-y);
        clickR = true;
        clickL =false;
        clickV = false;
        clickW = false;
        moveW = false;
        glutAttachMenu(GLUT_RIGHT_BUTTON);
    }
}

void motion2(int x, int y){
    if(clickW){
        xwmax = x;
        ywmax = 1000-y;
        update();
        Win_View();
        glutPostRedisplay();
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    }
    else if(clickV){
    printf("v\n");
        xvmax = x;
        yvmax = 1000-y;
        update();
        Win_View();
        glutPostRedisplay();
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    }
    else if(moveW){
        int diff = x - holdx;
        holdx += diff;
        xwmax += diff;
        xwmin += diff;

        diff = 1000-y - holdy;
        holdy += diff;
        ywmax += diff;
        ywmin += diff;

        update();
        Win_View();
        glutPostRedisplay();
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    }
}

void motion(int x, int y) {
    if(clickL){
        lineVec.at(lineVec.size()-1).x2 = x;
        lineVec.at(lineVec.size()-1).y2 = (1000-y);
        glutPostRedisplay();
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    }
    seedx = x, seedy = 1000-y;
}

void menu(int value){
    printf("aaa\n");

  switch(value) {

    case 1:
        SuHo(0);
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
        break;
    case 2:
        boundFill();
        break;
    case 3:
        printf("aa\n");
        Win_View();
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
        break;
    }
    glutPostRedisplay();

}

void make_menu(void){
   /*MainMenu*/
  // main_menu
   glutCreateMenu(menu);
   glutAddMenuEntry("Polygon Clipping", 1);
   glutAddMenuEntry("Region Filling", 2);
   glutAddMenuEntry("Window-to-Viewport Mapping", 3);

   glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void init(void){
    gluOrtho2D(0.0,1000.0,0.0,1000.0);
    glMatrixMode(GL_PROJECTION);
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque

}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode( GLUT_RGB | GLUT_SINGLE );
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(1000, 1000);
	glutCreateWindow("hello");

	init();

	Line line;

    int x1 = xwmin, y1 = ywmin, x2 = xwmin, y2 = ywmax;//left
    line.x1 = x1;
    line.y1 = y1;
    line.x2 = x2;
    line.y2 = y2;
    clippingWind.push_back(line);

    x1 = xwmax, y1 = ywmin, x2 = xwmax, y2 = ywmax;//right
    line.x1 = x1;
    line.y1 = y1;
    line.x2 = x2;
    line.y2 = y2;
    clippingWind.push_back(line);

	x1 = xwmin, y1 = ywmin, x2 = xwmax, y2 = ywmin;//bottom
    line.x1 = x1;
    line.y1 = y1;
    line.x2 = x2;
    line.y2 = y2;
    clippingWind.push_back(line);

    x1 = xwmax, y1 = ywmax, x2 = xwmin, y2 = ywmax;//top
    line.x1 = x1;
    line.y1 = y1;
    line.x2 = x2;
    line.y2 = y2;
    clippingWind.push_back(line);

    //int xvmin = 700, xvmax = 900, yvmin = 100, yvmax = 300;

    x1 = xvmin, y1 = yvmin, x2 = xvmin, y2 = yvmax;//left
    line.x1 = x1;
    line.y1 = y1;
    line.x2 = x2;
    line.y2 = y2;
    viewP.push_back(line);

    x1 = xvmax, y1 = yvmin, x2 = xvmax, y2 = yvmax;//right
    line.x1 = x1;
    line.y1 = y1;
    line.x2 = x2;
    line.y2 = y2;
    viewP.push_back(line);

	x1 = xvmin, y1 = yvmin, x2 = xvmax, y2 = yvmin;//bottom
    line.x1 = x1;
    line.y1 = y1;
    line.x2 = x2;
    line.y2 = y2;
    viewP.push_back(line);

    x1 = xvmax, y1 = yvmax, x2 = xvmin, y2 = yvmax;//top
    line.x1 = x1;
    line.y1 = y1;
    line.x2 = x2;
    line.y2 = y2;
    viewP.push_back(line);

	make_menu();
	glutDisplayFunc(display);
	//createGLUTMenus();

	glutMouseFunc(mouse);
    glutPassiveMotionFunc(motion);
    glutMotionFunc(motion2);

	glutMainLoop();
	return 0;
}
