#include "car.h"
car::car(){
    ID = 0;
    Price = 0;
    Year = 0;
    Mile = 0;
    City = "";
    State = "";
    Vin = "";
    Make = "";
    Model = "";
}
car::car(int iID, int iPrice, int iYear, int iMile, string sCity, string sState, string sVin, string sMake, string sModel){
    ID = iID;
    Price = iPrice;
    Year = iYear;
    Mile = iMile;
    City = sCity;
    State = sState;
    Vin = sVin;
    Make = sMake;
    Model = sModel;
}
car::~car(){

}
car::car(const car &c){
    ID = c.ID;
    Price = c.Price;
    Year = c.Year;
    Mile = c.Mile;
    City = c.City;
    State = c.State;
    Vin = c.Vin;
    Make = c.Make;
    Model = c.Model;
}

int car::getID(){
    return ID;
}
int car::getPrice(){
    return Price;
}
int car::getYear(){
    return Year;
}
int car::getMileage(){
    return Mile;
}
string car::getCity(){
    return City;
}
string car::getState(){
    return State;
}
string car::getVin(){
    return Vin;
}
string car::getMake(){
    return Make;
}
string car::getModel(){
    return Model;
}