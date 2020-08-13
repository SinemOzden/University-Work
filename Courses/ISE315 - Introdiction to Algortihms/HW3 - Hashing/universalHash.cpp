#include "universalHash.h"
universalHash::universalHash(){

}
universalHash::universalHash(int lenght){
    srand (time(NULL));
    collisionsInst = 0;
    collisionsSearch = 0;
    pair<int, bool> p ; 
    p.first = -1;
    p.second = true;
    for(int i=0; i<lenght; i++){
        hash.push_back(p);
    }
}
int universalHash::hashFunc(int k){
    
    int key = k;
    int digit1 = key % 100;
    key = key/100;
    int digit2 = key % 100;
    key = key/100;
    int digit3 = key;
    int a1 = rand()%(hash.size()-1);
    int a2 = rand()%(hash.size()-1);
    int a3 = rand()%(hash.size()-1);
    int result = (digit1 * a1 + digit2 * a2 +digit3 * a3) % hash.size();
    return result;
}
int universalHash::insert(int key){
    int index;
    pair<int, bool> p ; 
    p.first = key; 
    p.second = true ;
    for(int i=0; i<hash.size(); i++){
        index = hashFunc(key);
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
bool universalHash::erase(int key){
    int index;
    if(search(key)!=-1){
        hash.at(index).second = false;
        return true;
    }
    return false;
}
int universalHash::search(int key){
    int index = hashFunc(key);
    int i=index;
    
    bool fin = true;
    int k =0;
    while(fin){
        if(i==hash.size()){
            k++;
            i=0;
        }
        if(i==index){
            if(k>=1){
                fin=false;
                break;
            }
        }
        if(hash.at(i).first==key){
            
            if(hash.at(i).second==true){
                return i;
            }
            else{
                return -1;
            }
        }
        collisionsSearch++;
        i++;
    }
    return -1;
}
int universalHash::getCollisionInst(){
    return collisionsInst;
}
int universalHash::getCollisionSearch(){
    return collisionsSearch;
}
