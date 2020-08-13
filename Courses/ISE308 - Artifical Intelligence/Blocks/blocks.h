#ifndef BLOCKS_H
#define BLOCKS_H
#include <vector>
using namespace std;

class Blocks{
    public:
        Blocks();
        Blocks(double a,double b,double c,double d,bool e,int o);
        Blocks(const Blocks &c);
        void changePrecent(double num);
        double getX();
        double getY();
        double getSizeX();
        double getSizeY();
        int getOrder();
        bool ifValid();
        void calPercent(Blocks block);
        bool isRelated(Blocks block);

    private:
        double x;
        double y;
        double sizeX;
        double sizeY;
        double percent;
        bool vertical;
        int order;

};
#endif
