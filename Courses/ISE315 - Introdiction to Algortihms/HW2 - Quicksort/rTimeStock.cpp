#include "rTimeStock.h"
rTimeStock::rTimeStock(){
    instToken;
    lastPrice;

}
rTimeStock::rTimeStock(string sT, time_t d, long mSec, int iT, double lP, string rLine){
    sTime = sT;
    date = d;
    miSecond = mSec;
    instToken = iT;
    lastPrice = lP;
    restLine = rLine;
}
rTimeStock::~rTimeStock(){

}
rTimeStock::rTimeStock(const rTimeStock &c){
    sTime = c.sTime;
    date = c.date;
    miSecond = c.miSecond;
    instToken = c.instToken;
    lastPrice = c.lastPrice;
    restLine = c.restLine;
}

string rTimeStock::getTime(){
    return sTime;
}

time_t rTimeStock::getDate(){
    return date;
}

long rTimeStock::getmiSecond(){
    return miSecond;
}

long rTimeStock::getInstToken(){
    return instToken;
}

double rTimeStock::getLastPrice(){
    return lastPrice;
}

string rTimeStock::getRestLine(){
    return restLine;
}

int rTimeStock::compare(rTimeStock obj1, rTimeStock obj2, char s){
    if(s=='t'){
        double diff = difftime(obj1.getDate(),obj2.getDate());
        if(diff<0){
            return -1;
        }
        else if(diff==0){
            if(obj1.getmiSecond()<obj2.getmiSecond()){
                return -1;
            }
            else if(obj1.getmiSecond()==obj2.getmiSecond()){
                return 0;
            }
            else{
                return 1;
            }
        }
        else{
            return 1;
        }
    }
    else{
        if(obj1.getLastPrice()<obj2.getLastPrice()){
            return -1;
        }
        else if(obj1.getLastPrice()==obj2.getLastPrice()){
            return 0;
        }
        else{
            return 1;
        }
    }
}