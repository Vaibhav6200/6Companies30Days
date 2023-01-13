#include<bits/stdc++.h>
using namespace std;


/*
    brute force
    1. find all possible distances between points
    2. return True if 4 distances are equal and 2 distances (diagonals equal)
*/
int calcDist(vector<int> &p, vector<int> &q){
    return (q[1] - p[1])*(q[1] - p[1]) + (q[0] - p[0])*(q[0] - p[0]);
}
bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
    set<int> mySet;
    mySet.insert(calcDist(p1, p2));
    mySet.insert(calcDist(p2, p3));
    mySet.insert(calcDist(p3, p4));
    mySet.insert(calcDist(p4, p1));
    mySet.insert(calcDist(p1, p3));
    mySet.insert(calcDist(p2, p4));

    if(mySet.find(0) != mySet.end())
        return false;
    return mySet.size() == 2;
}


int main()
{

    return 0;
}