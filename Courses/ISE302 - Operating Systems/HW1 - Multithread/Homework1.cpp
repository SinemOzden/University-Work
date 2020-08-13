//TO RUN:
// Development environment: Lubuntu 16.04 LTS
// To compile: g++ Homework1.cpp -o Homework1.out -pthread -std=c++11
// To run: ./a.out interval_min interval_max np nt
//Example: ./Homework1.out 100 120 4 3
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

using namespace std;
void primeNum(vector<int> &a);
void print(vector<vector<int>> b, int x);
int nt;
int main(int argc, char const *argv[]){
    string t = argv[1];
    int intMin = atoi(t.c_str());
    t = argv[2];
    int intMax = atoi(t.c_str());
    t = argv[3];
    int np = atoi(t.c_str());
    t = argv[4];
    nt = atoi(t.c_str());
    pid_t pid;
    int status;
    vector<vector<int>> num;
    vector<thread> threads;
    vector<int> a;

    int interval = intMax-intMin+1;
    int numInterval = np * nt;
    int oneThread = interval/numInterval;
    cout<<"o "<<oneThread<<endl;
    int remaining = interval%numInterval;
    int rem = remaining;
    int begin;
    int end;
    cout<<"Master: Started."<<endl;
    for(int i=0; i< np;i++){
        for(int j=0;j<nt;j++){
            a.push_back(i+1);//which process
            a.push_back(j+1);//which tread
            begin = intMin+oneThread*(i*nt+j);
            if(i*nt == numInterval){
                end = begin + oneThread+remaining;
            }
            else{
                end = begin + oneThread;
            }
            a.push_back(begin);
            a.push_back(end);
            num.push_back(a);
            a.clear();
        }
    }
    for(int i=0; i< np;i++){
        pid = fork();
        if(pid<0){//error
            cout<<"Error"<<endl;
            exit(1);
        }
        else if(pid==0){//if child
            vector<int> t1 = num.at(i*nt);
            vector<int> t2 = num.at(i*nt+2);
            cout<<"Slave "<<i+1<<": Started. Interval "<<t1.at(2)<<"-"<<t2.at(3)<<endl;
            for(int j=0;j<nt;j++){
                vector<int> t =num.at(i*nt+j);
                cout<<"Thread "<< t.at(0)<<"."<<t.at(1)<<": searching in ";
                cout<<t.at(2)<<"-"<<t.at(3)<<endl;
                threads.push_back(thread(primeNum,ref(num.at(i*nt+j))));
                threads.at(j).join();
            }
            print(num,i);
            exit(0);
        }
        else{//if parent
            wait(&status);
            wait(&status);
        }
    }
    cout<<"Master: Done."<<endl;
    return 0;
}
void primeNum(vector<int> &a){
    //1 - which process
    //2 - which thread
    //3 - basla
    //4 - bit
    int count=0;
    for(int i=a.at(2); i<a.at(3); i++){
        for(int j=2;j<i;j++){
            if(i%j==0){
               count++; 
               j=i;
            }
        }
        if(count==0){
            a.push_back(i);
        }
        count = 0;
    }
}
void print(vector<vector<int>> b, int x){
    vector<int> a;
    cout<<"Slave "<<x+1<<": Done. Prime numbers are: ";
    for(int i=x*nt;i<x*nt+3;i++){
        a = b.at(i);
        for(int j=4;j<a.size();j++){
            cout<<a.at(j)<<", ";
        }
    }
    cout<<endl;
}
