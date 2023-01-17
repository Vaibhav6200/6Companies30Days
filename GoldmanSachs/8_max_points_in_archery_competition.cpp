#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    // returns max Score obtained for given bit mask
    int solve(int mask, int n, int numArrows, vector<int>& aliceArrows){
        int arrowCount=0, score=0;
        for(int i=0; i<n; i++){
            if((mask & (1<<i)) > 0){
                arrowCount += aliceArrows[i] + 1;
                score += i;
            }
        }
        if(arrowCount <= numArrows)
            return score;
        return 0;
    }

    vector<int> find(int mask, int n, int numArrows, vector<int>& aliceArrows){
        vector<int> bob_arr(n, 0);
        for(int i=0; i<n; i++){
            if((mask & (1<<i))> 0){
                bob_arr[i] = aliceArrows[i] + 1;
                numArrows -= aliceArrows[i] + 1;
            }
        }
        bob_arr[0] += numArrows;        // remaining arrows 0th index pe daal do
        return bob_arr;
    }

    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        int n = aliceArrows.size();

        int best = 0;
        int bob_mask=0;
        for(int mask=0; mask < (1<<n); mask++){
            int ans = solve(mask, n, numArrows, aliceArrows);
            if(best < ans){
                best = ans;
                bob_mask = mask;
            }
        }

        return find(bob_mask, n, numArrows, aliceArrows);
    }
};



int main()
{

    return 0;
}