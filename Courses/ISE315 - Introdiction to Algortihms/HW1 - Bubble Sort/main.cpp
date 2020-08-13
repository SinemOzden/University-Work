#include <string>
#include <cstdio>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <ctime>
#include "car.h"

using namespace std;

void readFile(vector<car>& carList, int n);

void bubbleSort(vector<car>& carList, char crit);

void mergeSort(vector<car>& carList, int l, int r, char crit);

void merge(vector<car>& carList, int l, int m, int r, char crit);

void writeFile(vector<car>& carList, string header);

string header;

int main(int argc, char const *argv[])
{
    char alg = *argv[2];
    char crit = *argv[4];
    string t = argv[6];
    int n = atoi(t.c_str());
    clock_t tick;

    vector<car> carList;
    readFile(carList,n);

    if(alg == 'm'){
        tick = clock();
        mergeSort(carList, 0, carList.size(), crit);
        tick = clock() - tick;
        float t = tick*1.0/CLOCKS_PER_SEC;
        cout<<"Merge sort t = "<<t<<endl;
    }
    else if(alg == 'b'){
        tick = clock();
        bubbleSort(carList, crit);
        tick = clock() - tick;
        float t = tick*1.0/CLOCKS_PER_SEC;
        cout<<"Bubble sort t = "<<t<<endl;
    }
    writeFile(carList, header);
    return 0;
}

void readFile(vector<car>& carList, int n){
    ifstream rFile("tc20171021.csv");

    if(!rFile.is_open()){
        cout<<"File not found"<<endl;
        return;
    }

    int iID, iPrice, iYear, iMile;
    string sCity, sState, sVin, sMake, sModel;

    string line, word;

    getline(rFile, header);
    n++;
    while(getline(rFile, line)&&n>1){
       istringstream inSS(line);
       getline(inSS,word,',');
       iID = atoi(word.c_str());
    
       getline(inSS,word,',');
       iPrice = atoi(word.c_str());

       getline(inSS,word,',');
       iYear = atoi(word.c_str());

       getline(inSS,word,',');
       iMile = atoi(word.c_str());

       getline(inSS,sCity,',');

       getline(inSS,sState,',');

       getline(inSS,sVin,',');

       getline(inSS,sMake,',');

       getline(inSS,sModel,'\n');
       car c = car(iID, iPrice, iYear, iMile,sCity, sState, sVin, sMake, sModel);
       carList.push_back(c);
       n--;
    }
    rFile.close();
    return;
}

void bubbleSort(vector<car>& carList,char crit){
    if(crit == 'p'){
        for(int i=0; i<carList.size()-1;i++){
            for(int j=0; j<carList.size()-i-1;j++){
                if(carList.at(j).getPrice() > carList.at(j+1).getPrice()){
                    car temp = carList.at(j);
                    car temp2 = carList.at(j+1);
                    carList[j] = temp2;
                    carList[j+1] = temp;
                }
            }
        }
    }
    else if(crit == 'm'){
        for(int i=0; i<carList.size()-1;i++){
            for(int j=0; j<carList.size()-i-1;j++){
                if(carList.at(j).getMileage() > carList.at(j+1).getMileage()){
                    car temp = carList.at(j);
                    car temp2 = carList.at(j+1);
                    carList[j] = temp2;
                    carList[j+1] = temp;
                }
            }
        }
    }
}
void mergeSort(vector<car>& carList, int l, int r, char crit){
    if(l+1<r){ 
        int m = l+((r-l)/2);
        mergeSort(carList, l, m, crit); 
        mergeSort(carList, m, r, crit); 
        merge(carList, l, m, r, crit);  
    }
}
void merge(vector<car>& carList, int l, int m, int r, char crit){
    int leftp = l, rightp = m;
    vector<car> carTemp;
    if(crit == 'p'){
        while(leftp < m && rightp< r){
            if(carList.at(leftp).getPrice() <= carList.at(rightp).getPrice()){
                car temp = carList.at(leftp);
                carTemp.push_back(temp);
                leftp++;
            }
            else{
                car temp = carList.at(rightp);
                carTemp.push_back(temp);
                rightp++;
            }
        }
        while(leftp<m){
            car temp = carList.at(leftp);
            carTemp.push_back(temp);
            leftp++;
        }
        while(rightp<r){
            car temp = carList.at(rightp);
            carTemp.push_back(temp);
            rightp++;
        }
    }
    else if(crit == 'm'){
        while(leftp < m && rightp< r){
            if(carList.at(leftp).getMileage() <= carList.at(rightp).getMileage()){
                car temp = carList.at(leftp);
                carTemp.push_back(temp);
                leftp++;
            }
            else{
                car temp = carList.at(rightp);
                carTemp.push_back(temp);
                rightp++;
            }
        }
        while(leftp<m){
            car temp = carList.at(leftp);
            carTemp.push_back(temp);
            leftp++;
        }
        while(rightp<r){
            car temp = carList.at(rightp);
            carTemp.push_back(temp);
            rightp++;
        }
    }
    for(int i=l; i<r;i++){
        carList.at(i)=carTemp.at(i-l);
    }
    return;
}

void writeFile(vector<car>& carList, string header){ 
    ofstream file;
    file.open("sorted.csv");
    file<<header<<endl;
    for(int i=0; i<carList.size();i++){
        file<<carList.at(i).getID()<<",";
        file<<carList.at(i).getPrice()<<",";
        file<<carList.at(i).getYear()<<",";
        file<<carList.at(i).getMileage()<<",";
        file<<carList.at(i).getCity()<<",";
        file<<carList.at(i).getState()<<",";
        file<<carList.at(i).getVin()<<",";
        file<<carList.at(i).getMake()<<",";
        file<<carList.at(i).getModel()<<endl;
    }
    file.close();
    return;
}