#include<bits/stdc++.h>
using namespace std;


/*
    Approach 2: Using 2 pointers (Time - O(n))
*/
int numberOfSubstrings(string s) {

    int n = s.length();
    int left = 0, right = 0;
    vector<int> character(3, 0);    // we have 3 characters (a, b, c) - maintains freq of each char
    int ans=0;

    for(int right=0; right<n; right++){
        character[s[right] - 'a']++;

        while(character[0]>0 && character[1]>0 && character[2]>0 && left<=right){
            character[s[left] - 'a']--;
            ans += n-right;
            left++;
        }
    }
    return ans;
}


/*
    Approach 1: Brute force (time - O(n^3))
    find all possible substrings and count those substrings containing abc atleast once
*/
    // int numberOfSubstrings(string s) {
    //     int n = s.length();
    //     int count=0;
    //     for(int i=0; i<n; i++){
    //         for(int j=i; j<n; j++){
    //             bool flag1 = false, flag2 = false, flag3 = false;
    //             for(int k=i; k<=j; k++){
    //                 if(s[k] == 'a') flag1 = true;
    //                 if(s[k] == 'b') flag2 = true;
    //                 if(s[k] == 'c') flag3 = true;
    //             }
    //             if(flag1 && flag2 && flag3)
    //                 count++;
    //         }
    //     }

    //     return count;
    // }


int main()
{

    return 0;
}