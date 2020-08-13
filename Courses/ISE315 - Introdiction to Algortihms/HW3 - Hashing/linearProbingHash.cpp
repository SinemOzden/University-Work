#include "linearProbingHash.h"
linearProbingHash::linearProbingHash(){

}
linearProbingHash::linearProbingHash(int lenght){
    collisionsInst = 0;
    collisionsSearch = 0;
    pair<int, bool> p ; 
    p.first = -1;
    p.second = true;
    for(int i=0; i<lenght; i++){
        hash.push_back(p);
    }
}
int linearProbingHash::hashFunc(int k, int i){
    int sum = k+i;
    int m = sum % hash.size();
    return m;
}
int linearProbingHash::insert(int key){
    int index;
    pair<int, bool> p ; 
    p.first = key; 
    p.second = true ;
    for(int i=0; i<hash.size(); i++){
        index = hashFunc(key,i);
        if(hash.at(index).first==-1){
            hash.at(index) = p;
            return index;
        }
        else if(hash.at(index).second!=true){
            hash.at(index) = p;
            return index;
        }
        collisionsInst++;
    }
    return -1;
}
bool linearProbingHash::erase(int key){
    int index;
    if(search(key)!=-1){
        hash.at(index).second = false;
        return true;
    }
    return false;
}
int linearProbingHash::search(int key){
    int index;
    for(int i=0; i<hash.size(); i++){
        index = hashFunc(key,i);
        if(hash.at(index).first==key){
            if(hash.at(index).second==true){
                return index;
            }
            else{
                return -1;
            }
        }
        collisionsSearch++;
    }
    return -1;
}
int linearProbingHash::getCollisionInst(){
    return collisionsInst;
}
int linearProbingHash::getCollisionSearch(){
    return collisionsSearch;
}