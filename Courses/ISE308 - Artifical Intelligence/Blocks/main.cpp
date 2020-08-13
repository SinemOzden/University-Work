#include "blocks.h"
#include <vector>
#include <iostream>
#include <algorithm>
vector<Blocks> order;
vector<Blocks> rem;
bool createGraph(vector<Blocks> blocks);
int main()
{
    srand (time(NULL));
    vector<Blocks> blocks;//stable shape -1
    //to create block consturtor needs (x,y) location as first two elements 
    //then the lenght of vertical side then length of horizontal side
    //then if it is vertical or not and finally number it to track if code works correctly
    blocks.push_back(Blocks(0,0,3,1,false,1));//1
    blocks.push_back(Blocks(1,1,1,3,true,2));//2
    blocks.push_back(Blocks(3,0,1,3,true,3));//3
    blocks.push_back(Blocks(6,0,1,3,true,4));//4
    blocks.push_back(Blocks(2,3,3,1,false,5));//5
    blocks.push_back(Blocks(5,3,3,1,false,6));//6
    blocks.push_back(Blocks(1,4,3,1,false,7));//7
    blocks.push_back(Blocks(4,4,3,1,false,8));//8
    blocks.push_back(Blocks(2.5,5,3,1,false,9));//9

    
    random_shuffle(blocks.begin(),blocks.end());

    cout<<"Pre order is: ";
    for(int i=0;i<blocks.size();i++){
       cout<<blocks.at(i).getOrder();
    }
    cout<<endl;

    if(createGraph(blocks)){
        cout<<"Order is: ";
        for(int i=0;i<order.size();i++){
        cout<<order.at(i).getOrder();
        }
        cout<<endl;
        order.clear();
    }
    else{
        cout<<"colapsed"<<endl;
    }

    vector<Blocks> blocks1;//not stable shape(a part of it) -2
    blocks1.push_back(Blocks(0,0,1,3,true,1));//1
    blocks1.push_back(Blocks(5,0,1,3,true,2));//2
    blocks1.push_back(Blocks(0,3,1,3,false,3));//3
    blocks1.push_back(Blocks(3,3,1,3,false,4));//4

    random_shuffle(blocks1.begin(),blocks1.end());

    cout<<"Pre order is: ";
    for(int i=0;i<blocks1.size();i++){
       cout<<blocks1.at(i).getOrder();
    }
    cout<<endl;

    if(createGraph(blocks1)){
        cout<<"Order is: ";
        for(int i=0;i<order.size();i++){
        cout<<order.at(i).getOrder();
        }
        cout<<endl;
        order.clear();
    }
    else{
        cout<<"colapsed"<<endl;
    }
    return 0;
}
bool createGraph(vector<Blocks> blocks){
    bool Possible=true;
    for(int i=0; i<blocks.size();i++){
        bool flag1=false;
        if(blocks.at(i).ifValid()){
            order.push_back(blocks.at(i));
            continue;
            //sonraki elamana gec
        }
        if(order.size()==0){//if there is nothing to compare add it to the end of the vector
            blocks.push_back(blocks.at(i));
        }
        else{
            for(int j=0; j<order.size();j++){//compare if it is related with any block
                if(blocks.at(i).isRelated(order.at(j))){
                    blocks.at(i).calPercent(order.at(j));
                    if(blocks.at(i).ifValid()){//is it stable to put
                        flag1=true;
                        order.push_back(blocks.at(i));//put it to the shape
                        break;
                    }
                }
            }
            if(!flag1){//not related with any block or not stable put it to end of the vector
                blocks.push_back(blocks.at(i));
            }
        }
        if(i!=0){//if it was checked prior the shape os not stable, end the loop
            if(blocks.at(i).getOrder()==blocks.at(i-1).getOrder()){
                Possible=false;
                break;
            }
        }
    }
    return Possible;
}