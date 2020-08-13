#include<stdio.h>
#include<iostream>
#include<math.h>
#include<GL/glut.h>    
#include<vector>
#include<assert.h>
#include"util.h"

using namespace std;
#define ANGLE 10

bool move1=false, move2=false, move3=false, move4=false, move5=false, move6=false,
      move7=false, move8=false, move9=false, move10=false, move11=false, move12=false,
      move13=false, move14=false, move15=false, move16=false;
bool smooth = false;
bool flatShading = false;
int X, Y;

void mouse(int button, int state, int x, int y);
void motion( int x, int y );
void CreateMenu(void);
void MenuItemClicked(int Value);
void specialKey(int key, int x, int y);
void SubMenuItemClicked(int Value);

void mouse(int button, int state, int x, int y){
    switch(button)
    {
        case GLUT_LEFT_BUTTON:
            if(state==GLUT_DOWN){
	    	//do something when left mouse button is down
	    }

            break;
        case GLUT_RIGHT_BUTTON:
            break;
        case GLUT_MIDDLE_BUTTON:
            break;
        default:
            break;
    }
    glutPostRedisplay();
}

void motion( int x, int y ){
   // record the position of the mouse.
    X = x;
    Y = y;
    glutPostRedisplay();
    CreateMenu();
}

//creat menu
void CreateMenu(void){
  int submenu, submenu2;
  
  submenu = glutCreateMenu(SubMenuItemClicked);
  glutAddMenuEntry("Move 1",  1);
  glutAddMenuEntry("Move 2",  2);
  glutAddMenuEntry("Move 3",  3);
  glutAddMenuEntry("Move 4",  4);
  glutAddMenuEntry("Move 5",  5);
  glutAddMenuEntry("Move 6",  6);
  glutAddMenuEntry("Move 7",  7);
  glutAddMenuEntry("Move 8",  8);
  glutAddMenuEntry("Move 9",  9);
  glutAddMenuEntry("Move 10",  10);
  glutAddMenuEntry("Move 11",  11);
  glutAddMenuEntry("Move 12",  12);
  glutAddMenuEntry("Move 13",  13);
  glutAddMenuEntry("Move 14",  14);
  glutAddMenuEntry("Move 15",  15);
  glutAddMenuEntry("Move 16",  16);

  glutCreateMenu(MenuItemClicked);

  //Attach Menu to RightClick
  glutAddSubMenu("Brezier",submenu);
  glutAddMenuEntry("original",  0);
  glutAddMenuEntry("flat",  1);
  glutAddMenuEntry("smoot",  2);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
}


void SubMenuItemClicked(int Value){
 	//glutPostRedisplay();
    switch(Value)
	{
		case 1:
      move1=true; move2=false; move3=false; move4=false; move5=false; move6=false;
      move7=false; move8=false; move9=false; move10=false; move11=false; 
      move12=false; move13=false; move14=false; move15=false; move16=false;
		  break;
    case 2:
      move1=false; move2=true; move3=false; move4=false;move5=false; move6=false;
      move7=false; move8=false; move9=false; move10=false; move11=false; 
      move12=false; move13=false; move14=false; move15=false; move16=false;
		  break;
    case 3:
      move1=false; move2=false; move3=true; move4=false;move5=false; move6=false;
      move7=false; move8=false; move9=false; move10=false; move11=false; 
      move12=false; move13=false; move14=false; move15=false; move16=false;
		  break;
    case 4:
      move1=false; move2=false; move3=false; move4=true; move5=false; move6=false;
      move7=false; move8=false; move9=false; move10=false; move11=false; 
      move12=false; move13=false; move14=false; move15=false; move16=false;
		  break;
    case 5:
      move1=false; move2=false; move3=false; move4=false; move5=true; move6=false;
      move7=false; move8=false; move9=false; move10=false; move11=false; 
      move12=false; move13=false; move14=false; move15=false; move16=false;
		  break;
    case 6:
      move1=false; move2=false; move3=false; move4=false;move5=false; move6=true;
      move7=false; move8=false; move9=false; move10=false; move11=false; 
      move12=false; move13=false; move14=false; move15=false; move16=false;
		  break;
    case 7:
      move1=false; move2=false; move3=false; move4=false;move5=false; move6=false;
      move7=true; move8=false; move9=false; move10=false; move11=false; 
      move12=false; move13=false; move14=false; move15=false; move16=false;
		  break;
    case 8:
      move1=false; move2=false; move3=false; move4=false; move5=false; move6=false;
      move7=false; move8=true; move9=false; move10=false; move11=false; 
      move12=false; move13=false; move14=false; move15=false; move16=false;
		  break;
    case 9:
      move1=false; move2=false; move3=false; move4=false; move5=false; move6=false;
      move7=false; move8=false; move9=true; move10=false; move11=false; 
      move12=false; move13=false; move14=false; move15=false; move16=false;
		  break;
    case 10:
      move1=false; move2=false; move3=false; move4=false;move5=false; move6=false;
      move7=false; move8=false; move9=false; move10=true; move11=false; 
      move12=false; move13=false; move14=false; move15=false; move16=false;
		  break;
    case 11:
      move1=false; move2=false; move3=false; move4=false;move5=false; move6=false;
      move7=false; move8=false; move9=false; move10=false; move11=true; 
      move12=false; move13=false; move14=false; move15=false; move16=false;
		  break;
    case 12:
      move1=false; move2=false; move3=false; move4=false; move5=false; move6=false;
      move7=false; move8=false; move9=false; move10=false; move11=false; 
      move12=true; move13=false; move14=false; move15=false; move16=false;
		  break;
    case 13:
      move1=false; move2=false; move3=false; move4=false; move5=false; move6=false;
      move7=false; move8=false; move9=false; move10=false; move11=false; 
      move12=false; move13=true; move14=false; move15=false; move16=false;
		  break;
    case 14:
      move1=false; move2=false; move3=false; move4=false;move5=false; move6=false;
      move7=false; move8=false; move9=false; move10=false; move11=false; 
      move12=false; move13=false; move14=true; move15=false; move16=false;
		  break;
    case 15:
      move1=false; move2=false; move3=false; move4=false;move5=false; move6=false;
      move7=false; move8=false; move9=false; move10=false; move11=false; 
      move12=false; move13=false; move14=false; move15=true; move16=false;
		  break;
    case 16:
      move1=false; move2=false; move3=false; move4=false; move5=false; move6=false;
      move7=false; move8=false; move9=false; move10=false; move11=false; 
      move12=false; move13=false; move14=false; move15=false; move16=true;
		  break;
   	}
}

void MenuItemClicked(int Value){
	switch(Value)
	{
        case 0:
            nothing = true;
            flatShading = false;
            smooth = false;
        break;
        case 1:
            flatShading = true;
            nothing = false;
            smooth = false;

        break;
		case 2:
            smooth = true;
            flatShading = false;
            nothing = false;
        break;
    }
 	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y){
  tolower(key);
  switch(key){
    case 'n':
      if(move1){
          controls[0][0].x +=0.3;
      }
      else if(move2){
          controls[0][1].x +=0.3;
      }
      else if(move3){
          controls[0][2].x +=0.3;
      }
      else if(move4){
          controls[0][3].x +=0.3;
      }
      else if(move5){
          controls[1][0].x +=0.3;
      }
      else if(move6){
          controls[1][1].x +=0.3;
      }
      else if(move7){
          controls[1][2].x +=0.3;
      }
      else if(move8){
          controls[1][3].x +=0.3;
      }
      else if(move9){
          controls[2][0].x +=0.3;
      }
      else if(move10){
          controls[2][1].x +=0.3;
      }
      else if(move11){
          controls[2][2].x +=0.3;
      }
      else if(move12){
          controls[2][3].x +=0.3;
      }
      else if(move13){
          controls[3][0].x +=0.3;
      }
      else if(move14){
          controls[3][1].x +=0.3;
      }
      else if(move15){
          controls[3][2].x +=0.3;
      }
      else if(move16){
          controls[3][3].x +=0.3;
      }
      break;
    case 'm':
      if(move1){
          controls[0][0].x -=0.3;
      }
      else if(move2){
          controls[0][1].x -=0.3;
      }
      else if(move3){
          controls[0][2].x -=0.3;
      }
      else if(move4){
          controls[0][3].x -=0.3;
      }
      else if(move5){
          controls[1][0].x -=0.3;
      }
      else if(move6){
          controls[1][1].x -=0.3;
      }
      else if(move7){
          controls[1][2].x -=0.3;
      }
      else if(move8){
          controls[1][3].x -=0.3;
      }
      else if(move9){
          controls[2][0].x -=0.3;
      }
      else if(move10){
          controls[2][1].x -=0.3;
      }
      else if(move11){
          controls[2][2].x -=0.3;
      }
      else if(move12){
          controls[2][3].x -=0.3;
      }
      else if(move13){
          controls[3][0].x -=0.3;
      }
      else if(move14){
          controls[3][1].x -=0.3;
      }
      else if(move15){
          controls[3][2].x -=0.3;
      }
      else if(move16){
          controls[3][3].x -=0.3;
      }
      break;
    case 'w':
        camx += 5;
        break;
    case 's':
        camx -= 5;
	break;
    case 'a':
        camy += 5;
	break;
    case 'd':
	camy -= 5;
	break;
    case 'i':
	lightPosition[1]-=1;
        break;
    case 'k':
	lightPosition[1]+=1;
	break;
    case 'l':
	lightPosition[2]-=1;
	break;
    case 'j':
	lightPosition[2]+=1;
	break;
    case 'o':
	lightPosition[0]-=1;
	break;
    case 'p':
	lightPosition[0]+=1;
	break;
    case 't':
	matDiffuse [0]+=0.1;matDiffuse [1]+=0.1;matDiffuse [2]+=0.1;
	break;
    case 'g':
	matDiffuse [0]-=0.1;matDiffuse [1]-=0.1;matDiffuse [2]-=0.1;
	break;
    case 'f':
	matSpecular [0]+=0.1;matSpecular [1]+=0.1;matSpecular [2]+=0.1;
	break;
    case 'h':
	matSpecular [0]-=0.1;matSpecular [1]-=0.1;matSpecular [2]-=0.1;
	break;
    case 'c':
	shininess [0]+=0.3;
	break;
    case 'v':
	shininess [0]-=0.3;
	break;

  }
    glutPostRedisplay();
}

void specialKey(int key, int x, int y){
  switch(key){
    case GLUT_KEY_UP:
      if(move1){
          controls[0][0].y +=0.3;
      }
      else if(move2){
          controls[0][1].y +=0.3;
      }
      else if(move3){
          controls[0][2].y +=0.3;
      }
      else if(move4){
          controls[0][3].y +=0.3;
      }
      else if(move5){
          controls[1][0].y +=0.3;
      }
      else if(move6){
          controls[1][1].y +=0.3;
      }
      else if(move7){
          controls[1][2].y +=0.3;
      }
      else if(move8){
          controls[1][3].y +=0.3;
      }
      else if(move9){
          controls[2][0].y +=0.3;
      }
      else if(move10){
          controls[2][1].y +=0.3;
      }
      else if(move11){
          controls[2][2].y +=0.3;
      }
      else if(move12){
          controls[2][3].y +=0.3;
      }
      else if(move13){
          controls[3][0].y +=0.3;
      }
      else if(move14){
          controls[3][1].y +=0.3;
      }
      else if(move15){
          controls[3][2].y +=0.3;
      }
      else if(move16){
          controls[3][3].y +=0.3;
      }
      break;
    case GLUT_KEY_DOWN:
      if(move1){
          controls[0][0].y -=0.3;
      }
      else if(move2){
          controls[0][1].y -=0.3;
      }
      else if(move3){
          controls[0][2].y -=0.3;
      }
      else if(move4){
          controls[0][3].y -=0.3;
      }
      else if(move5){
          controls[1][0].y -=0.3;
      }
      else if(move6){
          controls[1][1].y -=0.3;
      }
      else if(move7){
          controls[1][2].y -=0.3;
      }
      else if(move8){
          controls[1][3].y -=0.3;
      }
      else if(move9){
          controls[2][0].y -=0.3;
      }
      else if(move10){
          controls[2][1].y -=0.3;
      }
      else if(move11){
          controls[2][2].y -=0.3;
      }
      else if(move12){
          controls[2][3].y -=0.3;
      }
      else if(move13){
          controls[3][0].y -=0.3;
      }
      else if(move14){
          controls[3][1].y -=0.3;
      }
      else if(move15){
          controls[3][2].y -=0.3;
      }
      else if(move16){
          controls[3][3].y -=0.3;
      }
      break;
    case GLUT_KEY_RIGHT:
      if(move1){
          controls[0][0].z +=0.3;
      }
      else if(move2){
          controls[0][1].z +=0.3;
      }
      else if(move3){
          controls[0][2].z +=0.3;
      }
      else if(move4){
          controls[0][3].z +=0.3;
      }
      else if(move5){
          controls[1][0].z +=0.3;
      }
      else if(move6){
          controls[1][1].z +=0.3;
      }
      else if(move7){
          controls[1][2].z +=0.3;
      }
      else if(move8){
          controls[1][3].z +=0.3;
      }
      else if(move9){
          controls[2][0].z +=0.3;
      }
      else if(move10){
          controls[2][1].z +=0.3;
      }
      else if(move11){
          controls[2][2].z +=0.3;
      }
      else if(move12){
          controls[2][3].z +=0.3;
      }
      else if(move13){
          controls[3][0].z +=0.3;
      }
      else if(move14){
          controls[3][1].z +=0.3;
      }
      else if(move15){
          controls[3][2].z +=0.3;
      }
      else if(move16){
          controls[3][3].z +=0.3;
      }
      break;
    case GLUT_KEY_LEFT:
      if(move1){
          controls[0][0].z -=0.3;
      }
      else if(move2){
          controls[0][1].z -=0.3;
      }
      else if(move3){
          controls[0][2].z -=0.3;
      }
      else if(move4){
          controls[0][3].z -=0.3;
      }
      else if(move5){
          controls[1][0].z -=0.3;
      }
      else if(move6){
          controls[1][1].z -=0.3;
      }
      else if(move7){
          controls[1][2].z -=0.3;
      }
      else if(move8){
          controls[1][3].z -=0.3;
      }
      else if(move9){
          controls[2][0].z -=0.3;
      }
      else if(move10){
          controls[2][1].z -=0.3;
      }
      else if(move11){
          controls[2][2].z -=0.3;
      }
      else if(move12){
          controls[2][3].z -=0.3;
      }
      else if(move13){
          controls[3][0].z -=0.3;
      }
      else if(move14){
          controls[3][1].z -=0.3;
      }
      else if(move15){
          controls[3][2].z -=0.3;
      }
      else if(move16){
          controls[3][3].z -=0.3;
      }
      break;
  }
    glutPostRedisplay();
}
