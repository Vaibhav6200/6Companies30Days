#include<bits/stdc++.h>
using namespace std;


// Time = O(n), Space = O(1)
int maxRotateFunction(vector<int>& nums) {
    long sum=0, original=0;
    int n = nums.size();

    for(int i=0; i<n; i++){
        sum += nums[i];
        original += i*nums[i];
    }

    long maximum = original;
    for(int i=n-1; i>=0; i--){
        original = original + sum - nums[i]*n;
        maximum = max(maximum, original);
    }

    return maximum;
}


/*
    *** Naive Approach *** (O(n^2))
    1. make function which returns vector after k rotations
        => Use Queue for it
    2. for each F[k] call rotate function to get rotated array
        => calculate value of F[k]
        => update minimum answer variable
*/
    // vector<int> rotate(int k, vector<int> nums){

    //     // Create Queue and push numbers in it
    //     queue<int> q;
    //     for(int i=0; i<nums.size(); i++)
    //         q.push(nums[i]);

    //     // Rotate Numbers in queue
    //     for(int i=0; i<k; i++){
    //         int x = q.front();
    //         q.pop();
    //         q.push(x);
    //     }

    //     // create our rotated vector from queue
    //     for(int i=0; i<nums.size(); i++){
    //         nums[i] = q.front();
    //         q.pop();
    //     }

    //     return nums;
    // }

    // int maxRotateFunction(vector<int>& nums) {
    //     int ans = INT_MIN;
    //     int n = nums.size();

    //     for(int i=0; i<n; i++){
    //         vector<int> result = rotate(i, nums);

    //         int temp = 0;
    //         for(int j=0; j<n; j++)
    //             temp += result[j] * j;

    //         // cout << temp << endl;
    //         ans = max(ans, temp);
    //     }

    //     return ans;
    // }

int main()
{

    return 0;
}