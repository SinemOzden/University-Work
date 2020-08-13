#include"menu.h"
#include"display.h"
#include"util.h"

void init(void){
    gluOrtho2D(0.0,1000.0,0.0,1000.0);

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    glClearDepth(1.0f);                   // Set background depth to farthest
    glEnable(GL_DEPTH_TEST);

}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE );
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(1000, 1000);
	glutCreateWindow("hw3");

	init();
	CreateMenu();
	glutReshapeFunc(reshape);
    glutDisplayFunc(display);

    glutMouseFunc(mouse);
    glutPassiveMotionFunc(motion);
    glutSpecialFunc(specialKey);

	//glutIdleFunc(idle);             // Register callback handler if no other event

	glutMainLoop();
	return 0;
}
