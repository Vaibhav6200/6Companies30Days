#include<bits/stdc++.h>
using namespace std;


// calculate all possible distances between 2 points
int calcDist(vector<int> &p, vector<int> &q){
    return (q[1] - p[1])*(q[1] - p[1]) + (q[0] - p[0])*(q[0] - p[0]);
}

int numberOfBoomerangs(vector<vector<int>>& points) {
    int n = points.size();
    unordered_map<int, int> distance;
    int ans=0;

    // for every ith point we are making a seperate map
    for(int i=0; i<n; i++){
        // for ith point we find distance between ith and every other point. and map it.
        for(int j=0; j<n; j++){
            int dist = calcDist(points[i], points[j]);
            distance[dist]++;
        }   // after this loop we have total distances same from ith point

        // add bloombergs in our answer
        for(auto i: distance)
            ans += i.second*(i.second-1);

        // clear the map for next iteration
        distance.clear();
    }

    return ans;
}


int main()
{

    return 0;
}