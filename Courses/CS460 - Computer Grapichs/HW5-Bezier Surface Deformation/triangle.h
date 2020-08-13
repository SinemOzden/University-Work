#include "util.h"
struct Triangle{
    Vec3f normal, a, b, c;
    Triangle() = default;
    Triangle(Vec3f p1, Vec3f p2, Vec3f p3){a = p1;b = p2;c = p3;}
    bool contains(const Vec3f& p) const{return p == a || p == b || p == c;}
};

Vec3f normal(Triangle t);
int dot(Vec3f p1, Vec3f p2);
void makeTriangles();
void drawTriangles();
Vec3f normalAverage(Vec3f p);
Vec3f bezierCont(array<Vec3f,4> p, float u);
void bezierCalculation();


vector<Triangle> triangles;


Vec3f normal(Triangle t){
    Vec3f ret;
    Vec3f u = t.b - t.a;
    Vec3f v = t.c - t.a;
    ret.x = u.y*v.z - u.z*v.y;
    ret.y = u.z*v.x - u.x*v.z;
    ret.z = u.x*v.y - u.y*v.x;
    return ret;
}

int dot(Vec3f p1, Vec3f p2){
    return p1.x*p2.x + p1.y*p2.y + p1.z*p2.z;
}

void makeTriangles(){

    for(int i = 0; i < points.size()-1; i++){
        for(int j = 0; j < points[0].size() -1; j++){
            triangles.push_back(Triangle(points[i][j], points[i][j+1], points[i+1][j]));
            triangles.push_back(Triangle(points[i+1][j], points[i][j+1], points[i+1][j+1]));
        }
    }
    for(Triangle& t: triangles){
        t.normal = normal(t);
    }
}

void drawTriangles(){
    Vec3f v = Vec3f(camx, camy, 25);
    for(auto tri: triangles){
        if(!nothing)
            glBegin(GL_TRIANGLES);
        else{
            glBegin(GL_LINE_LOOP);
            glColor3f(1,1,1);
        }
            glColor3f(1,1,1);
            Vec3f n = normal(tri);
            if(dot(v, n) > 0 && nothing)
                continue;
            Vec3f p1 = normalAverage(tri.a);
            Vec3f p2 = normalAverage(tri.b);
            Vec3f p3 = normalAverage(tri.c);
            glNormal3f(p1.x, p1.y, p1.z);
            glVertex3f(tri.a.x, tri.a.y, tri.a.z);

            glNormal3f(p2.x, p2.y, p2.z);
            glVertex3f(tri.b.x, tri.b.y, tri.b.z);

            glNormal3f(p3.x, p3.y, p3.z);
            glVertex3f(tri.c.x, tri.c.y, tri.c.z);
        glEnd();
    }
    
}

Vec3f normalAverage(Vec3f p){
    float count = 0;
    float x = 0, y = 0, z = 0;
    for(auto& tri: triangles){
        if(tri.contains(p)){
            x += tri.normal.x;
            y += tri.normal.y;
            z += tri.normal.z;
            count++;
        }
    }
    return Vec3f(x/count, y/count, z/count);
}

void bezierCalculation(){
    array<Vec3f,4> curves;
    for (int i = 0; i < points.size(); ++i) {
        for (int j = 0; j < points[0].size(); ++j) {
            float div = (points.size()-1);
            float u = (float)i/div;
            float v = (float)j/div;
            for(int i = 0; i < 4; i++){
                curves[i] = (bezierCont(controls.at(i), u));
            }
            points[i][j] = (bezierCont(curves, v));
        }
    }
}

Vec3f bezierCont(array<Vec3f,4> p, float u){
    Vec3f ret;
    float b1 = pow(1-u, 3);
    float b2 = 3*u*pow(1-u, 2);
    float b3 = 3*pow(u, 2)*(1-u);
    float b4 = pow(u, 3);
    ret.x += b1*p.at(0).x + b2*p.at(1).x + b3*p.at(2).x + b4*p.at(3).x;
    ret.y += b1*p.at(0).y + b2*p.at(1).y + b3*p.at(2).y + b4*p.at(3).y;
    ret.z += b1*p.at(0).z + b2*p.at(1).z + b3*p.at(2).z + b4*p.at(3).z;
    return ret;
}
