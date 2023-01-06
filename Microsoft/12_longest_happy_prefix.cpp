#include<bits/stdc++.h>
using namespace std;


string largest_prefix_suffix(string s) {
    int n = s.size();
    string ans="";
    vector<int>pos(n, 0);

    int i=0, j=1;
    while(j < n){
        if(s[i] == s[j]){
            pos[j] = i+1;
            i++;
            j++;
        }
        else if(i)
            i = pos[i-1];
        else
            j++;
    }
    ans = s.substr(0, i);
    return ans;
}


int main()
{
    string s = "blablabla";
    cout << largest_prefix_suffix(s);

    return 0;
}