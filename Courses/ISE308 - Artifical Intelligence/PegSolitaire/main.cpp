#include "search.hpp"
#include "pegS.h"
int main()
{
    cout << endl<< "PegS best:" << endl ;

    auto resPeg = bestFirstTS(pegS());

    showRoute(resPeg);

    cout << endl<< "PegS depht:" << endl ;

    auto resPeg = depthFirstTS(pegS());

    showRoute(resPeg);

    cout << endl<< "PegS depht:" << endl ;

    auto resPeg = recursiveBestFirstSearch(pegS());

    showRoute(resPeg);

    return 0;
}