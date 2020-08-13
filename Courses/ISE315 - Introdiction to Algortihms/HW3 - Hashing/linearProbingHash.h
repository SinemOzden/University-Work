#ifndef LINEARPROBINGHASH_H
#define LINEARPROBINGHASH_H
#include <iostream>
#include <utility>
#include <vector>

using namespace std;
class linearProbingHash{
public:
    linearProbingHash();
    linearProbingHash(int lenght);
    int hashFunc(int k, int i);
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
