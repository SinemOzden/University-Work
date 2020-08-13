#include <string>
#include <cstdio>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <string.h>
#include "rTimeStock.h"

using namespace std;

bool readFile(int n);

void quickSort(int low, int high);

int partition_r(int low, int high);

int  partition(int low, int high);

void writeFile(vector<rTimeStock>& rTimeStockList, string header);

string header;
vector<rTimeStock> rTimeStockList;
char crit;
int x=0;

int main(int argc, char const *argv[])
{
    crit = *argv[2];
    string nS = argv[4];
    int n = atoi(nS.c_str());
    clock_t tick;

    if(!readFile(n)){return 1;}

    srand (time(NULL));
    tick = clock();
    //cout<<"file read"<<endl;
    quickSort(0, rTimeStockList.size()-1);
    tick = clock() - tick;
    float t = tick*1.0/CLOCKS_PER_SEC;
    cout<<"Quick sort t = "<<t<<endl;

    writeFile(rTimeStockList, header);
    return 0;
}

bool readFile(int n){
ifstream rFile("log_inf.csv");

    if(!rFile.is_open()){
        cout<<"File not found"<<endl;
        return false;
    }

    time_t date;
    string miSec;
    long miSecond;
    long instToken;
    double lastPrice;
    string sTime;

    string line, word, restLine;
    struct tm tm;

    getline(rFile, header);
    n++;
    while(getline(rFile, line)&&n>1){
        istringstream inSS(line);
        getline(inSS,word,',');
        sTime = word;//no need to convert date and miSecond to string string is already saved
        
        const char * c = word.c_str();
        strptime(c, "%Y-%m-%d %H:%M:%S", &tm);
        date = mktime(&tm); //printf("%s", asctime(gmtime(&t)));

        istringstream timeStamp(word);
        getline(timeStamp,miSec,'.');
        getline(timeStamp,miSec,'.');//get milisecond
        miSecond = atoi(miSec.c_str());

        getline(inSS,word,',');
        instToken = atoi(word.c_str());

        getline(inSS,word,',');
        lastPrice = atoi(word.c_str());
        getline(inSS,restLine,';');

        rTimeStock rTS = rTimeStock(sTime, date, miSecond, instToken, lastPrice, restLine);
        rTimeStockList.push_back(rTS);
        n--;
    }
    rFile.close();
    return true;
}

void quickSort(int low, int high){
    if(low<high){
        int pi = partition_r(low, high);
        x++;
        quickSort(low, pi-1);
        x++;
        quickSort(pi+1,high);
    }
}
int partition_r(int low, int high){
    int range = high-low;
    int r = rand()%range + low;
    rTimeStock temp = rTimeStockList.at(r);
    rTimeStockList.at(r) = rTimeStockList.at(high);
    rTimeStockList.at(high) = temp;
    return partition(low, high);
}

int  partition(int low, int high){
    rTimeStock pivot = rTimeStockList.at(high);
    int i = low-1;
    for(int j=low; j<high;j++){
        int a = pivot.compare(pivot,rTimeStockList.at(j),crit);
        if(a<=0){
            i++;
            rTimeStock temp = rTimeStockList.at(i);
            rTimeStockList.at(i) = rTimeStockList.at(j);
            rTimeStockList.at(j) = temp;
        }
    }
    rTimeStock temp = rTimeStockList.at(i+1);
    rTimeStockList.at(i+1) = rTimeStockList.at(high);
    rTimeStockList.at(high) = temp;

    return i+1;
}

void writeFile(vector<rTimeStock>& rTimeStockList, string header){ 
    ofstream file;
    file.open("sorted.csv");
    file<<header<<endl;
    for(int i=0; i<rTimeStockList.size();i++){
        file<<rTimeStockList.at(i).getTime()<<",";
        file<<rTimeStockList.at(i).getInstToken()<<",";
        file<<rTimeStockList.at(i).getLastPrice()<<",";
        file<<rTimeStockList.at(i).getRestLine();
        file<<endl;
    }
    file.close();
    //cout<<"w"<<endl;
    return;
}