#include<bits/stdc++.h>
using namespace std;


int minimumCardPickup(vector<int>& cards) {
    map<int, int> map;      // {number, lastOccurance}
    int n = cards.size();
    int ans = INT_MAX;

    for(int i=0; i<n; i++){
        if(map.find(cards[i]) != map.end())
            ans = min(ans, i - map[cards[i]] + 1);

        map[cards[i]] = i;
    }

    if(ans != INT_MAX)
        return ans;
    return -1;
}


int main()
{

    return 0;
}