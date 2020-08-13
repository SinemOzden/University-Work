 
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <array>


#ifndef util
#define util
using namespace std;

#define EPS .0001
struct Position{
    Position() : x(0), y(0),z(0), u(0), v(0) {}
    Position(float m, float n){
      x=m; y=n; z = 0; u = 0; v = 0; 
    }
    Position(float m, float n, float t){
      x=m; y=n; z = t; u = 0; v = 0; 
    }
    Position(float m, float n,float t, float i, float j){
        x = m; y =n; z = t; u = i; v = j;
    }
    float x;
    float y;
    float z;
    float u;
    float v;
};

GLfloat redSurface[]   = {1.0, 0.0, 0.0, 1.0};
GLfloat greenSurface[]   = {0.0, 1.0, 0.0, 1.0};
GLfloat blueSurface[]   = {0.0, 0.0, 1.0, 1.0};
GLfloat darkSurface[]   = {1.0, 0.0, 0.0, 1.0};
//for lighting
GLfloat lightAmbient[] =  {0.1, 0.1, 0.1, 1.0};
GLfloat lightDiffuse[] =  {1.0, 1.0, 1.0, 2.5};
GLfloat lightSpecular[] = {0.4, 0.4, 0.4, 1.0};
GLfloat lightPosition[] = {-10.0, -15.0, -10.0,0.0};
GLfloat lightDirection[] ={0.0, 0.0, -1.0};
GLfloat shininess[]       = {50};
// for the materials
GLfloat matAmbient [] = {0.0, 1.0, 0.0, 1.0};
GLfloat matDiffuse [] = {0.0, 0.0, 0.0, 0.0};
GLfloat matSpecular[] = {1.0, 1.0, 1.0, 1.0};
bool nothing = true;
vector<Position> cubicPoints;
vector<Position> controlPoints;

Position camera;

int WIDTH_WINDOWS;
int HEIGHT_WINDOWS;

double m_slide=100;

bool cubicSpline = true;
bool bezierSurface = false;

// lighting parameters.
bool bezierSurfaceMapping = false;
// data for the lighting
//
// for x-y-z axis


struct Vec3f{
    float x=0, y=0, z=0;
    Vec3f() = default;
    Vec3f(float x, float y, float z){this->x=x;this->y=y;this->z=z;}
    Vec3f operator-(const Vec3f& o) const{return Vec3f(x-o.x, y-o.y, z-o.z);}
    bool operator==(const Vec3f& o) const{
        return abs(x-o.x)<EPS && abs(y-o.y)<EPS && abs(z-o.z)<EPS;}
    //bool operator==(const Vec3f& o) const{return x==o.x && y==o.y && z==o.z;}
    float len2() const {return x*x + y*y + z*z;}
    Vec3f normalize(){
        float l = sqrt(len2());
        if(l != 0) x/=l, y/=l, z/=l;
        return *this;
    }
};

array<array<Vec3f,4>,4> controls;
array<array<Vec3f,16>,16> points;
int camx = 25, camy = 25;
#endif
