//#include <windows.h>  // for MS Windows
#include <GL/glut.h>  //Unix, GLUT, include glu.h and gl.h
//#include <GLUT/glut.h> //Max OSX
#include <stdio.h>
#include <vector>
using namespace std;

struct Line{
    int x1,y1,x2,y2;
};
vector<Line> lineVec;
bool clickR=false;
bool clickL=false;

void display(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f);
        for(int i=0; i<lineVec.size(); i++){
            glVertex2i(lineVec.at(i).x1/2,(1000-lineVec.at(i).y1)/2);
            glVertex2i(lineVec.at(i).x2/2,(1000-lineVec.at(i).y2)/2);
        }
    glEnd();
    glFlush();
}

void init(void) {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    gluOrtho2D(0.0,500.0,0.0,500.0);
    glClear(GL_COLOR_BUFFER_BIT);
}

void mouse(int button, int state, int x, int y) {

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        Line line;
        if(clickR){
            lineVec.clear();
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
            glClear(GL_COLOR_BUFFER_BIT);
            clickR =false;
        }
        line.x1 = x;
        line.y1 = y;
        line.x2 = x;
        line.y2 = y;
        lineVec.push_back(line);
        clickL = true;
    }

    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        lineVec.at(lineVec.size()-1).x2 = x;
        lineVec.at(lineVec.size()-1).y2 = y;
        clickR = true;
        clickL =false;
    }
}

void motion(int x, int y) {
    if(clickL){
        lineVec.at(lineVec.size()-1).x2 = x;
        lineVec.at(lineVec.size()-1).y2 = y;
        glutPostRedisplay();
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);                 // Initialize GLUT
    glutInitWindowSize(1000, 1000);   // Set the window's initial width & height
    glutInitWindowPosition(1000, 1000); // Position the window's initial top-left corner

    glutCreateWindow("Hw1");
    init();
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMouseFunc(mouse);
    glutPassiveMotionFunc(motion);

    glutMainLoop();           // Enter the event-processing loop
    return 0;
}
