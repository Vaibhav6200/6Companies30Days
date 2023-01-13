#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
/*
    Approach 2: Time - O(n)
    nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
    it can be written as
    nums[i] - rev(nums[i]) == nums[j] + rev(nums[j])

*/

    int rev(int n){
        int res=0;
        while(n!=0){
            res=res*10+n%10;
            n/=10;
        }
        return res;
    }

    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> map;
        int res=0;
        long long mod = 1e9+7;

        for(int i=0; i<nums.size(); i++){
            int temp = nums[i] - rev(nums[i]);
            map[temp]++;

            res = (res + map[temp] - 1) % mod;
        }

        return res%mod;
    }


/*
    Approach 1: Brute Force - Time (O(n^2))
    1. Make a rev Function which reverses a number
    2. iterate 2 loops over nums and check inequality condition
*/
    // int rev(int n)   //function to find reverse of a number
    // {
    //     int res=0;
    //     while(n!=0){
    //         res=res*10+n%10;
    //         n/=10;
    //     }
    //     return res;
    // }

    // int countNicePairs(vector<int>& nums) {

    //     int n = nums.size();

    //     int count = 0;
    //     for(int i=0; i<n; i++){
    //         for(int j=i+1; j<n; j++){
    //             if(nums[i] + rev(nums[j]) == nums[j] + rev(nums[i]))
    //                 count++;
    //         }
    //     }
    //     return count;
    // }
};


int main()
{

    return 0;
}