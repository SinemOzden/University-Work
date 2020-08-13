#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<GL/glut.h>   
#include<vector>
#include<assert.h>

using namespace std;

#define ANGLE 30

float xa, ya;
float xb, yb;
float faa, fab, fba, fbb;

bool leftFlag = false;
bool image = false, rotate = false, object = false;

float m_xtheta = 0, m_ytheta = 0, m_ztheta = 0, zoom=1;

struct vec4{
	GLfloat x;
	GLfloat y;
	GLfloat z;
	GLfloat w;
};

struct vec3{
	GLfloat x;
	GLfloat y;
	GLfloat z;
};

struct vecs3{
	GLint x;
	GLint y;
	GLint z;
};

struct Position{
    Position() : x(0), y(0), u(0), v(0) {}
    Position(float m, float n){
    	x=m; y=n; 
    }
    Position(float m, float n, float i, float j){
        x = m; y =n; u = i; v = j;
    }
    float x;
    float y;
    float u;
    float v;
};

struct color{
    float r,g,b;
};

#define PI 3.1415926
#define header 54
int WIDTH_IMG;
int HEIGHT_IMG;
//unsigned char * data;
std::vector<unsigned char> data;///texture array
std::vector<color> upl, downl, upr, downr;

static GLuint texName;
Position center;   
Position minRec,maxRec;
#define R 3  
//teapot
vector<vec3> vertices;
vector<vec3> normals;
vector<vecs3> elements;
int WIDTH_WINDOWS;
int HEIGHT_WINDOWS;


// load BMP image.
void readBMP(char * filename){

    FILE * fd;
    if((fd=fopen(filename,"rb")) == NULL){
        printf("Error happens\n");
    }else{
        printf("file opened\n");
    }
    unsigned char info[header];
    fread(info,sizeof(unsigned char), header, fd); //read the header-byte header
    //extract the  heght and width of the image from the header info.

    WIDTH_IMG = *(int *)&info[18];
    HEIGHT_IMG = *(int *)&info[22];
    int size=3 * WIDTH_IMG * HEIGHT_IMG;
    printf("%d, %d\n", WIDTH_IMG, HEIGHT_IMG );

    unsigned char * pixel = (unsigned char *)malloc(sizeof(unsigned char)*size);
    fread(pixel, sizeof(unsigned char), size, fd);// read the data
    fclose(fd);

    //restore pixel from BGR to RGB.
    //
    for (int i = 0; i < size; i += 3){
        unsigned char temp=pixel[i];
        pixel[i] = pixel[i+2];
        pixel[i+2] = temp;
    }

    for(int i = 0; i < size; i++){
        data.push_back(pixel[i]);
    }

    color c;

    for(int i = 0; i<WIDTH_IMG/2;i++){
        for(int j = 0; j<HEIGHT_IMG/2;j++){
            c.r = data.at(3*(j*WIDTH_IMG+ i));
            c.g = data.at(3*(j*WIDTH_IMG+ i)+1);
            c.b = data.at(3*(j*WIDTH_IMG+ i)+2);
            downl.push_back(c);
        }
    }

    for(int i = WIDTH_IMG/2; i<WIDTH_IMG;i++){
        for(int j = 0; j<HEIGHT_IMG/2;j++){
            c.r = data.at(3*(j*WIDTH_IMG+ i));
            c.g = data.at(3*(j*WIDTH_IMG+ i)+1);
            c.b = data.at(3*(j*WIDTH_IMG+ i)+2);
            downr.push_back(c);
        }
    }

    for(int i = 0; i<WIDTH_IMG/2;i++){
        for(int j = HEIGHT_IMG/2; j<HEIGHT_IMG;j++){
            c.r = data.at(3*(j*WIDTH_IMG+ i));
            c.g = data.at(3*(j*WIDTH_IMG+ i)+1);
            c.b = data.at(3*(j*WIDTH_IMG+ i)+2);
            upl.push_back(c);
        }
    }

    for(int i=WIDTH_IMG/2;i<WIDTH_IMG;i++){
        for(int j = HEIGHT_IMG/2; j<HEIGHT_IMG;j++){
            c.r = data.at(3*(j*WIDTH_IMG+ i));
            c.g = data.at(3*(j*WIDTH_IMG+ i)+1);
            c.b = data.at(3*(j*WIDTH_IMG+ i)+2);
            upr.push_back(c);
        }
    }

    printf("%lu\n", data.size());

   // return data;
}

// Load OBJ file.
void loadOBJ(char * filename, vector<vec3> *vertices, vector<vec3> *normals, vector<vecs3> *elements){
    FILE *fd=fopen(filename, "rb");
    assert(fd != NULL);
    
    while( 1 ){
        char line[128];
        int res = fscanf(fd, "%s", line);
        if(res == EOF)
            break;  // EOF = end of the file, and quit the loop.
        //else, parse the line.
        if( strcmp(line, "v") == 0){
          //read vertices
			vec3 vertex;
			fscanf(fd, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
			vertices->push_back(vertex); 
		}else if( strcmp(line, "vt") == 0){
			//read vertices texture
		}else if(strcmp(line, "vn") == 0){
		
		}else if(strcmp(line, "f") == 0){
			vecs3 temp;
			fscanf(fd, "%d %d %d\n", &temp.x, &temp.y, &temp.z);
			elements->push_back(temp);          
        }else{
          //ignore
        }

    }
    fclose(fd);
}

void setup()
{
    glClearColor(0, 0, 0, 1.0); // *should* display black background
    // setting for the texture
    // load image
    readBMP("flower.bmp"); //WIDTH HEIGHT data are avaiable now!
    printf("load BMP image\n");
    minRec.x = 50; minRec.y = 50;
    maxRec.x = 50 + WIDTH_IMG; maxRec.y = 50 + HEIGHT_IMG;
    center.x = (minRec.x + maxRec.x) / 2;
    center.y = (minRec.y + maxRec.y) / 2;


    glGenTextures(1, &texName);
    glBindTexture(GL_TEXTURE_2D, texName);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, WIDTH_IMG, HEIGHT_IMG, 0, GL_RGB, GL_UNSIGNED_BYTE, data.data()); 
    
    printf("start to load Teapot\n");
    //load teapot
    loadOBJ("./teapot.obj", &vertices, &normals, &elements); 
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

color computeBilinearInterpolation(float x, float y, int x1, int y1, color Q11, color Q21, color Q12, color Q22){
    int x2 = x1+1;
    int y2 = y1+1;

    float div = (float)(x2-x1) * (y2-y1);

    color a,b,c,d,tot;
    a.r = Q11.r * (x2 - x) * (y2 - y)/div; 
    a.g = Q11.g * (x2 - x) * (y2 - y)/div; 
    a.b = Q11.b * (x2 - x) * (y2 - y)/div; 

    b.r = Q21.r * (x - x1) * (y2 - y)/div;
    b.g = Q21.g * (x - x1) * (y2 - y)/div;
    b.b = Q21.b * (x - x1) * (y2 - y)/div;

    c.r = Q12.r * (x2 - x) * (y - y1)/div;
    c.g = Q12.g * (x2 - x) * (y - y1)/div;
    c.b = Q12.b * (x2 - x) * (y - y1)/div;

    d.r = Q22.r * (x - x1) * (y - y1)/div;
    d.g = Q22.g * (x - x1) * (y - y1)/div;
    d.b = Q22.b * (x - x1) * (y - y1)/div;

    tot.r = a.r + b.r + c.r + d.r;
    tot.g = a.g + b.g + c.g + d.g;
    tot.b = a.b + b.b + c.b + d.b;

    return tot; 
}

void textureMapping(int beginx, int endx, int beginy, int endy, vector<color> vec){
    float gridSizeX = endx - beginx, gridSizeY = endy - beginy; 
	glBegin(GL_POINTS);
	int i,j;
	for(i=0; i<gridSizeX; i++){
		for(j=gridSizeY-1;j>=0;j--){
            float gx = i * float(WIDTH_IMG/2) / gridSizeX;
            float gy = j * float(HEIGHT_IMG/2) / gridSizeY;

            if(gx != 0){
                gx --;
            }
            if(gy != 0){
                gy--;
            }

            int gxi = int(gx);
            int gyi = int(gy);
            color Q11, Q21, Q12, Q22;

            Q11 = vec.at(gyi + (HEIGHT_IMG/2) * gxi);
            Q21 = vec.at(gyi + (HEIGHT_IMG/2) * (gxi+1));
            Q12 = vec.at((gyi+1) + (HEIGHT_IMG/2) * gxi);
            Q22 = vec.at((gyi+1) + (HEIGHT_IMG/2) * (gxi+1));

            color z = computeBilinearInterpolation(gxi, gyi, gx, gy, Q11, Q21, Q12, Q22);

            glColor3ub(z.r,z.g,z.b);
            glVertex2i(i+50+beginx, j+50+beginy);            
		}
	}
	glEnd();

	glutSwapBuffers();
}

void redraw(){
    textureMapping(0,center.x,0,center.y,downl);
    textureMapping(center.x,WIDTH_IMG,0,center.y,downr);
    textureMapping(0,center.x,center.y,HEIGHT_IMG,upl);
    textureMapping(center.x,WIDTH_IMG,center.y,HEIGHT_IMG,upr);

}

void display(){

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0,0.0,0.0,0.0);
	glEnable(GL_DEPTH_TEST); 

	glLoadIdentity();

	// show the Image.
	if(!object && image){
		
		// draw the image using
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glTranslatef(WIDTH_IMG/2 + 50,HEIGHT_IMG/2 + 50,0.0);
        glRotatef(m_ztheta, 0,0,1);
        glTranslatef(-WIDTH_IMG/2 - 50,-HEIGHT_IMG/2 - 50,0.0);
			glEnable(GL_TEXTURE_2D);
				glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE, GL_DECAL);
				glBindTexture(GL_TEXTURE_2D,texName); //active the texture.
				glBegin(GL_QUADS);
					glTexCoord2f(0.0, 1.0);    glVertex3f(50,      50,       0);
					glTexCoord2f(1.0, 1.0);    glVertex3f(50+WIDTH_IMG,50,       0);
					glTexCoord2f(1.0, 0.0);    glVertex3f(50+WIDTH_IMG,50+HEIGHT_IMG,0);
					glTexCoord2f(0.0, 0.0);    glVertex3f(50,      50+HEIGHT_IMG,0);
				glEnd();
			glDisable(GL_TEXTURE_2D);
        glPopMatrix();
            /*glBegin(GL_POINTS);
            for(int i=0; i<WIDTH_IMG/2; i++){
                for(int j=HEIGHT_IMG/2-1; j>=0; j--){
                    color z;
                    z = downl.at((j+ i*HEIGHT_IMG/2));
                    glColor3ub(z.r,z.g,z.b);
                    glVertex2i(i+450,HEIGHT_IMG +50 - (j));
                }
            }

            for(int i=0; i<WIDTH_IMG/2; i++){
                for(int j=HEIGHT_IMG/2-1; j>=0; j--){
                    color z;
                    z = downr.at((j+ i*HEIGHT_IMG/2));
                    glColor3ub(z.r,z.g,z.b);
                    glVertex2i(i+450+WIDTH_IMG/2,HEIGHT_IMG +50 - (j));
                }
            }

            for(int i=0; i<WIDTH_IMG/2; i++){
                for(int j=HEIGHT_IMG/2-1; j>=0; j--){
                    color z;
                    z = upl.at((j+ i*HEIGHT_IMG/2));
                    glColor3ub(z.r,z.g,z.b);
                    glVertex2i(i+450,178 - (j));
                }
            }

            for(int i=0; i<WIDTH_IMG/2; i++){
                for(int j=HEIGHT_IMG/2-1; j>=0; j--){
                    color z;
                    z = upr.at((j+ i*HEIGHT_IMG/2));
                    glColor3ub(z.r,z.g,z.b);
                    glVertex2i(i+450+WIDTH_IMG/2,178 - (j));
                }
            }
            glEnd();*/
		}

		// draw the Mesh model.
	if(!image && object){
        // render the mesh model
        glColor3f(1,1,1);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(60, 1, 1, 500000);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(0,0,10,0,0,0,0,1,0);

        glRotatef(m_xtheta, 0, 1, 0);
        glRotatef(m_ytheta, 1, 0, 0);
        glScalef(zoom, zoom, zoom);
        glPushMatrix();
        int counter=0;
        for(int i=0; i<elements.size();i++){
            vecs3 f = elements[i];
            glBegin(GL_LINE_LOOP);
            glVertex3f(vertices[f.x-1].x, vertices[f.x-1].y, vertices[f.x-1].z);
            glVertex3f(vertices[f.y-1].x, vertices[f.y-1].y, vertices[f.y-1].z);
            glVertex3f(vertices[f.z-1].x, vertices[f.z-1].y, vertices[f.z-1].z);
            //glVertex3f(vertices[f.d-1].x, vertices[f.d-1].y, vertices[f.d-1].z);
            glEnd();            
        }
        glPopMatrix();
	}
    

    glutSwapBuffers(); // display newly drawn image in window

}

void mouse(int btn,int state,int x,int y){
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		leftFlag = true;
	}
	if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		leftFlag = false;
	}
}

void motion(int x,int y){
    if(leftFlag && image){
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.0,0.0,0.0,0.0);
        center.x = x;
        center.y = y;
        redraw();
        //glutPostRedisplay();
    }

}

void RollUp(float n){
  m_ztheta+=n;
  if(m_ztheta > 360) m_ztheta=-360;
}

void RollDown(float n){
  m_ztheta-=n;
  if(m_ztheta < -360) m_ztheta=360;
}

void ZoomIn(float n){
    zoom+=n;
}

void ZoomOut(float n){
    zoom-=n;
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

void MenuItemClicked(int Value){

	switch(Value) 
	{
		case 1:
            image = true;
            rotate = false;
            object = false;
            break;
		case 2:
            rotate = true;
            RollUp(ANGLE);
			break;
		case 3:
            image = false;
            rotate = false;
            object = true;
			break;
   	}
 	glutPostRedisplay();
}

//creat menu
void CreateMenu(void){ 

    glutCreateMenu(MenuItemClicked);
    glutAddMenuEntry("Image",  1);
    glutAddMenuEntry("Rotate",  2);
    glutAddMenuEntry("Object", 3);
    //Attach Menu to RightClick
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void specialKey(int key, int x, int y){
    switch(key){
        case GLUT_KEY_UP:
        if(rotate && image){
            RollUp(ANGLE);
        }
        else if(rotate && object){
            PitchUp(ANGLE);
            YawUp(ANGLE);
        }
        else if(object){
            ZoomIn(0.1);
        }
        
        break;
        case GLUT_KEY_DOWN:
        if(rotate && image){
            RollDown(ANGLE);
        }
        else if(rotate && object){
            PitchDown(ANGLE);
            YawDown(ANGLE);
        }
        else if(object){
            ZoomOut(0.1);
        }
        break;
    }
    glutPostRedisplay();
}


void init(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0,0.0,0.0,0.0);
    gluOrtho2D(0.0, 1000.0, 500.0, 0.0);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(1000,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Texture Mapping");
        setup();
        init();
        
            // initializing callbacks
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutMouseFunc(mouse);  // define your own mouse event.
	glutMotionFunc(motion);  // define your own motion event, e.g., rotate OBJ model.

	//Creates Menu on Right Click
    glutSpecialFunc(specialKey); //register a special keyboard function.
	CreateMenu();

	glutMainLoop();
	return 0;

}
