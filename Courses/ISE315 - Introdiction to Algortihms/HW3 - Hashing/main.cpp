#include <string>
#include <cstdio>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include "stdlib.h"
#include "linearProbingHash.h"
#include "doubleHash.h"
#include "universalHash.h"
using namespace std;
bool readFile();

bool write();

vector<int> searchVec;

vector<int> searchVec2;
linearProbingHash *hash1;
doubleHash *hash2;
universalHash *hash3;

int main(int argc, char const *argv[])
{
    int m = atoi(argv[1]);
    hash1 = new linearProbingHash(m);
    hash2 = new doubleHash(m);
    hash3 = new universalHash(m);
    if(!readFile()){return 1;}
    if(!write()){return 1;}

    return 0;
}

bool readFile(){
    ifstream rFile("insert.txt");

    if(!rFile.is_open()){
        cout<<"File insert not found"<<endl;
        return false;
    }

    string line;
    int num;
    vector<int> numbers;

    while(getline(rFile, line)){
       num = atoi(line.c_str());
       numbers.push_back(num);
    }
    rFile.close();
    cout<<"------Linear Probing Hash------"<<endl;
    for(int i=0; i<numbers.size();i++){
       int index = hash1->insert(numbers.at(i));
       cout<<"Key "<<numbers.at(i)<<" is hashed to the slot "<<index<<endl;
    }
    cout<<"------Double Hash------"<<endl;
    for(int i=0; i<numbers.size();i++){
       int index = hash2->insert(numbers.at(i));
       cout<<"Key "<<numbers.at(i)<<" is hashed to the slot "<<index<<endl;
    }
    cout<<"------Universal Hash------"<<endl;
    for(int i=0; i<numbers.size();i++){
       int index = hash3->insert(numbers.at(i));
       cout<<"Key "<<numbers.at(i)<<" is hashed to the slot "<<index<<endl;
    }

    ifstream rFile1("search.txt");

    if(!rFile1.is_open()){
        cout<<"File search not found"<<endl;
        return false;
    }

    while(getline(rFile1, line)){
       num = atoi(line.c_str());
       searchVec.push_back(num);
    }
    rFile1.close();
    return true;
}

bool write(){
    cout<<"------Linear Probing Hash------"<<endl;
    for(int i=0; i<searchVec.size();i++){
        int hashResult = hash1->search(searchVec.at(i));
        if(hashResult!=-1){
            cout<<"Key "<<searchVec.at(i)<<" is found at slot "<<hashResult<<endl;
        }
        else{
            cout<< searchVec.at(i)<<" Not found!!!"<<endl;
        }
    }
    cout<<"------Double Hash------"<<endl;
    for(int i=0; i<searchVec.size();i++){
        int hashResult = hash2->search(searchVec.at(i));
        if(hashResult!=-1){
            cout<<"Key "<<searchVec.at(i)<<" is found at slot "<<hashResult<<endl;
        }
        else{
            cout<< searchVec.at(i)<<" Not found!!!"<<endl;
        }
    }
    cout<<"------Universal Hash------"<<endl;
    for(int i=0; i<searchVec.size();i++){
        int hashResult = hash3->search(searchVec.at(i));
        if(hashResult!=-1){
            cout<<"Key "<<searchVec.at(i)<<" is found at slot "<<hashResult<<endl;
        }
        else{
            cout<< searchVec.at(i)<<" Not found!!!"<<endl;
        }
    }
    cout<<"------Linear Probing Hash------"<<endl;
    cout<<"The number of collisions at insertion are "<<hash1->getCollisionInst()<<endl;
    cout<<"The number of collisions at search are "<<hash1->getCollisionSearch()<<endl;
    cout<<"------Double Hash------"<<endl;
    cout<<"The number of collisions are "<<hash2->getCollisionInst()<<endl;
    cout<<"The number of collisions are "<<hash2->getCollisionSearch()<<endl;
    cout<<"------Universal Hash------"<<endl;
    cout<<"The number of collisions are "<<hash3->getCollisionInst()<<endl;
    cout<<"The number of collisions are "<<hash3->getCollisionSearch()<<endl;
}