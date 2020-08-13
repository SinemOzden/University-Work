#include "common.hpp" 
#include "problem.hpp"
#include "search.hpp"

using std::vector;
using namespace AI;

typedef std::vector<std::vector<int>> pegSVect;

DefClassProblem(pegS, pegSVect)
{
    pegS();

    leafs_list successors(node_ptr &state) const;
    bool isGoal (const pegSVect &state) const;
    long H(const node_ptr &node) const;
    vector<vector<int>> vect;

private:

    bool isValid(pegSVect &succ, vector<int> action) const;

    long H(const pegSVect &state) const;

    pegSVect apply(pegSVect &state, const vector<int> &action) const;

};

