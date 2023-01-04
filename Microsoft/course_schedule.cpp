#include<bits/stdc++.h>
using namespace std;

/*
    Approch
    1. make graph taking edges from prerequisite array
    2. if we have cycle in our graph then return false else return true
        => to detect cycle in graph use topological sort
*/
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    int n = prerequisites.size();
    unordered_map<int, vector<int>> adj;
    for(int i=0; i<n; i++){
        int u = prerequisites[i][0];
        int v = prerequisites[i][1];

        adj[v].push_back(u);
    }

    // make indegree array
    vector<int> indegree(numCourses);
    for(auto i: adj)
        for(auto j: i.second)
            indegree[j]++;

    // push all elements with indegree 0 in queue
    queue<int> q;
    for(int i=0; i<numCourses; i++)
        if(indegree[i] == 0)
            q.push(i);

    // make a bfs call on queue
    vector<int> ans;
    while(!q.empty()){
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for(auto nbr: adj[front]){
            indegree[nbr]--;
            if(indegree[nbr] == 0)
                q.push(nbr);
        }
    }
    if(ans.size() == numCourses)
        return true;
    return false;
}


int main()
{

    return 0;
}