#ifndef UNIVERSALHASH_H
#define UNIVERSALHASH_H
#include <iostream>
#include <utility>
#include <vector>

using namespace std;
class universalHash{
public:
    universalHash();
    universalHash(int lenght);
    int hashFunc(int k);
    int insert(int key);
    bool erase(int key);
    int search(int key);
    int getCollisionInst();
    int getCollisionSearch();

private:
    vector<pair<int, bool>> hash;
    int collisionsInst;
    int collisionsSearch;
};
#endif
