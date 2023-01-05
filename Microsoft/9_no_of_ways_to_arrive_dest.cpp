#include<bits/stdc++.h>
using namespace std;


#define ll long long
const int mod = 1e9+7;
typedef pair<ll, int> pi;      // {dist, node}


int countPaths(int n, vector<vector<int>>& roads) {

    // create adj list
    unordered_map<int, vector<pi>> adj;
    for(int i=0; i<roads.size(); i++){
        int u = roads[i][0];    // node u
        int v = roads[i][1];    // node v
        int time = roads[i][2];    // time taken from u to v

        adj[u].push_back({v, time});
        adj[v].push_back({u, time});
    }

    // By default a min heap is created ordered by first element of pair
    priority_queue<pi, vector<pi>,  greater<pi>> pq;

    // create ways and dist array
    vector<ll> ways(n, 0);
    vector<ll> dist(n, LONG_MAX);

    // Initialize source node and push it into pq
    ways[0] = 1;
    dist[0] = 0;
    pq.push({0, 0});

    while(!pq.empty()){
        // take out element from pq
        auto p = pq.top();
        pq.pop();

        ll cur_dist = p.first;
        int u = p.second;

        // explore its nbr vertices
        for(auto nbr: adj[u]){
            int v = nbr.first;
            ll wt = nbr.second;

            ll d = wt + cur_dist;

            // Its the first time i am coming with shortest distance
            if(d < dist[v]){   // update dist of v and push it into pq
                dist[v] = d;
                ways[v] = ways[u];
                pq.push({d, v});
            }
            else if (d == dist[v])
                ways[v] = (ways[u] + ways[v])%mod;
        }
    }

    return ways[n-1] % mod;
}


int main()
{

    return 0;
}