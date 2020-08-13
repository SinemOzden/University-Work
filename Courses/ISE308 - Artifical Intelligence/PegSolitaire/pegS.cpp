#include "pegS.h"

DefConstructorProblem(pegS, pegSV()){ }

pegSVect pegSV(){//creates the initial state of board
    return pegSVect{{2,2,1,1,1,2,2},
                    {2,2,1,1,1,2,2},
                    {1,1,1,1,1,1,1},
                    {1,1,1,0,1,1,1},
                    {1,1,1,1,1,1,1},
                    {2,2,1,1,1,2,2},
                    {2,2,1,1,1,2,2}};
}

pegS::leafs_list pegS::successors(node_ptr &node) const //creates valid succesors and puts tham in a leaf list
{ 
    leafs_list leafs;
    vector<int> actList;
    auto state = node->getState();
    for(int i=0;i<7;i++){//checks every item at the board
        for(int j=0;j<7;j++){
            actList.push_back(i);
            actList.push_back(j);
            actList.push_back(1);
            if(isValid(state, actList)){//see if there is any valid moves of the sone 
                auto nState = apply(state,actList);
                leafs.push_back(makeNode(nState,node,H(nState)));//if there is add to list
            }
            actList.pop_back();
            actList.push_back(2);
            if(isValid(state, actList)){
                auto nState = apply(state,actList);
                leafs.push_back(makeNode(nState,node,H(nState)));
            }
            actList.pop_back();
            actList.push_back(3);
            if(isValid(state, actList)){
                auto nState = apply(state,actList);
                leafs.push_back(makeNode(nState,node,H(nState)));
            }
            actList.pop_back();
            actList.push_back(4);
            if(isValid(state, actList)){
                auto nState = apply(state,actList);
                leafs.push_back(makeNode(nState,node,H(nState)));
            }
        }
    }
    return leafs;
}

bool pegS::isValid(pegSVect &state, vector<int> action) const//checks if the move is alid
{
    int i = action.at(0);
    int j = action.at(1);
    int k;
    int l;
    if(action.at(2)==1){ //1 yukari  i j-2
        k = i;
        l = j-2;
    }
    else if(action.at(2)==2){ //2 sag     i+2 j
        k = i+2;
        l = j;
    }
    else if(action.at(2)==3){//3 asagi   i j+2
        k = i;
        l = j+2;
    }
    else{//4 sol     i-2 j
        k = i-2;
        l = j;
    }
    if(state.at(i).at(j)==state.at(k).at(l)){//if they are same the move is not valid
        return false;
    }
    else{
        return true;
    }

}

long pegS::H(const node_ptr &node) const
{
    return 1;
}

long pegS::H(const pegSVect &state) const
{
    return 1;
}

pegSVect pegS::apply(pegSVect &state, const vector<int> &action) const //apply the action to the state and return state
{
    int i = action.at(0);
    int j = action.at(1);
    int k;
    int l;
    if(action.at(2)==1){ //1 yukari  i j-2
        k = i;
        l = j-2;
    }
    else if(action.at(2)==2){ //2 sag     i+2 j
        k = i+2;
        l = j;
    }
    else if(action.at(2)==3){//3 asagi   i j+2
        k = i;
        l = j+2;
    }
    else{//4 sol     i-2 j
        k = i-2;
        l = j;
    }
    if(state.at(i).at(j)==1){
        state.at(i).at(j)=0;
    }
    else{
        state.at(i).at(j)=1;
    }
    if(state.at(k).at(l)==1){
        state.at(k).at(l)=0;
    }
    else{
        state.at(k).at(l)=1;
    }
}

bool pegS::isGoal(const pegSVect &state) const //checks if the goal is reach if there arent any moves left
{ 
     for(int i=0;i<7;i++){
         for(int j=0;j<7;j++){
            if(state.at(i).at(j)==0){
                if(state.at(i-2).at(j)==1||state.at(i+2).at(j)==1||state.at(i).at(j-2)==1||state.at(i).at(j+2)==1){
                    return false;
                }
                else{
                    return true;
                }

            }
            else{
                if(state.at(i-2).at(j)==0||state.at(i+2).at(j)==0||state.at(i).at(j-2)==0||state.at(i).at(j+2)==0){
                    return false;
                }
                else{
                    return true;
                }
            }
         }
     }
}


