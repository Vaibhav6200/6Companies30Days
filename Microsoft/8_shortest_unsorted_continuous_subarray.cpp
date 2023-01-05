#include<bits/stdc++.h>
using namespace std;


// Approach 2: Sort nums array - we get nums_sorted (Time - O(nlogn))
// Compare nums and nums_sorted to get leftmost and rightmost boundary
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> nums_sorted = nums;
        sort(nums_sorted.begin(), nums_sorted.end());

        bool flag = true;
        int left=0, right=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != nums_sorted[i]){
                if(flag){
                    left = i;
                    flag = false;
                }
                else right = i;
            }
        }

        return right > 0 ? right - left + 1 : 0;
    }

// Approach 1: 2 Pointer Approach (Time - O(n^2))
    // int findUnsortedSubarray(vector<int>& nums) {
    //     int n = nums.size();
    //     int left=n, right=0;

    //     for(int i=0; i<n; i++){
    //         for(int j=i+1; j<n; j++){
    //             if(nums[j] < nums[i]){
    //                 left = min(left, i);
    //                 right = max(right, j);
    //             }
    //         }
    //     }
    //     cout << left << " " << right;

    //     return right>0 ? right-left+1 : 0;
    // }


int main()
{

    return 0;
}