#include<bits/stdc++.h>
using namespace std;


void solve(int k, int n, int start, vector<int> temp, vector<vector<int>> &result){
    if(k < 0 || n < 0)
        return;

    if(k == 0 && n == 0){
        result.push_back(temp);
        return;
    }

    for(int i=start; i<=9; i++){
        temp.push_back(i);
        solve(k-1, n-i, i+1, temp, result);
        temp.pop_back();  // backtracking
    }
}

void print_result(vector<vector<int>> result){
    for(auto i: result){
        for(auto j: i)
            cout << j << " ";
        cout << endl;
    }
}

int main()
{
    int n, k;
    cout << "Enter k: ";
    cin >> k;
    cout << "Enter n: ";
    cin >> n;

    vector<vector<int>> result;
    vector<int> temp;
    solve(k, n, 1, temp, result);

    print_result(result);

    return 0;
}