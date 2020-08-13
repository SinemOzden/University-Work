#ifndef RTIMESTOCK_H
#define RTIMESTOCK_H
#include <iostream>
#include <string>
#include <ctime>

using namespace std;
class rTimeStock{
public:
    rTimeStock();
    rTimeStock(string sT, time_t d, long mSec, int iT, double lP, string rLine);
    ~rTimeStock();
    rTimeStock(const rTimeStock &c);
    string getTime();
    time_t getDate();
    long getmiSecond();
    long getInstToken();
    double getLastPrice(); 
    string getRestLine();
    int compare(rTimeStock obj1, rTimeStock obj2, char s);

private:
    string sTime;
    time_t date;
    long miSecond;
    long instToken;
    double lastPrice;

    string restLine;
    /*int Volume;
    int sellQuantity;
    int lastQuantity;
    double change;
    double avgPrice;
    double open;
    double high;
    double low;
    double close;

    double dBPrice0;
    double dBOrder0;
    double dBQuantity0;
    double dSPrice0;
    double dSOrder0;
    double dSQuantity0;
    
    double dBPrice1;
    double dBOrder1;
    double dBQuantity1;
    double dSPrice1;
    double dSOrder1;
    double dSQuantity1;

    double dBPrice2;
    double dBOrder2;
    double dBQuantity2;
    double dSPrice2;
    double dSOrder2;
    double dSQuantity2;

    double dBPrice3;
    double dBOrder3;
    double dBQuantity3;
    double dSPrice3;
    double dSOrder3;
    double dSQuantity3;

    double dBPrice4;
    double dBOrder4;
    double dBQuantity4;
    double dSPrice4;
    double dSOrder4;
    double dSQuantity4;*/
    
};
#endif
