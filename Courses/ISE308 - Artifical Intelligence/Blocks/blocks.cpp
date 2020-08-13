#include "blocks.h"
#include <iostream>
Blocks::Blocks(double a,double b,double c,double d, bool e,int o){
    x=a;
    y=b;
    sizeX=c;
    sizeY=d;
    percent=0;
    vertical=e;
    order=o;
}
Blocks::Blocks(const Blocks &c){
    x=c.x;
    y=c.y;
    sizeX=c.sizeX;
    sizeY=c.sizeY;
    percent=c.percent;
    vertical=c.vertical;
    order=c.order;
}
void Blocks::changePrecent(double num){
    percent+=num;
}
double Blocks::getX(){
    return x;
}
double Blocks::getY(){
    return y;
}
double Blocks::getSizeX(){
    return sizeX;
}
double Blocks::getSizeY(){
    return sizeY;
}
int Blocks::getOrder(){
    return order;
}
bool Blocks::ifValid(){
    if(y==0){//on table
        return true;
    }
    if(vertical){//if shape vertical
        if(percent==100){//check if there is something under it
            return true;
        }
        else{
            return false;
        }
    }
    else{//if shape horizontal
        if(percent>=200.0/3){//check if the 2/3 of it covered beneath
            return true;
        }
        return false;
    }

}
void Blocks::calPercent(Blocks block){
    double sizeCovBeg, sizeCovEnd, sizeCov;
    int mid;
    //first check if midlle is supported
    mid = sizeX/2;
    if(mid+x>=block.x && mid+x<block.x+block.sizeX){//check from left
        percent += 100;
        return;
    }
    mid++;
    if(mid+x>=block.x && mid+x<block.x+block.sizeX){//check from right
        percent += 100;
        return;
    }
    //if not supported calculte 
    if(block.x>x){
        sizeCovBeg = block.x;
    }
    else{
        sizeCovBeg = x;
    }

    if(block.x+block.sizeX>x+sizeX){
        sizeCovEnd = x+sizeX;
    }
    else{
        sizeCovEnd = block.x+block.sizeX;
    }
    sizeCov = sizeCovEnd - sizeCovBeg;
    percent += 100*sizeCov/sizeX;
}
bool Blocks::isRelated(Blocks block){
    double sizeCovBeg, sizeCovEnd, sizeCov;
    //check if block is beneath
    if(block.y+block.sizeY == y){
        if(block.x>x){
            sizeCovBeg = block.x;
        }
        else{
            sizeCovBeg = x;
        }

        if(block.x+block.sizeX>x+sizeX){
            sizeCovEnd = x+sizeX;
        }
        else{
            sizeCovEnd = block.x+block.sizeX;
        }
        sizeCov = sizeCovEnd - sizeCovBeg;
        if(sizeCov>0){
            return true;
        }
    }
    return false;
}