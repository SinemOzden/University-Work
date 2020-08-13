#ifndef CAR_H
#define CAR_H
#include <iostream>
#include <string>

using namespace std;
class car{
public:
    car();
    car(int iID, int iPrice, int iYear, int iMile, string sCity, string sState, string sVin, string sMake, string sModel);
    ~car();
    car(const car &c);
    int getID();
    int getPrice();
    int getYear();
    int getMileage();
    string getCity();
    string getState();
    string getVin();
    string getMake();
    string getModel();  

private:
    int ID;
    int Price;
    int Year;
    int Mile;
    string City;
    string State;
    string Vin;
    string Make;
    string Model;
};
#endif
