#include "doubleHash.h"
doubleHash::doubleHash(){

}
doubleHash::doubleHash(int lenght){
    collisionsInst = 0;
    collisionsSearch = 0;
    pair<int, bool> p ; 
    p.first = -1;
    p.second = true;
    for(int i=0; i<lenght; i++){
        hash.push_back(p);
    }
}
int doubleHash::hashFunc(int k, int i){
    int mod1 = k%hash.size();
    int mod2 = 1 + k % (hash.size()-1);
    int result = (mod1 + i * mod2)%hash.size();
    return result;
}
int doubleHash::insert(int key){
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
bool doubleHash::erase(int key){
    int index;
    if(search(key)!=-1){
        hash.at(index).second = false;
        return true;
    }
    return false;
}
int doubleHash::search(int key){
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
int doubleHash::getCollisionInst(){
    return collisionsInst;
}
int doubleHash::getCollisionSearch(){
    return collisionsSearch;
}
