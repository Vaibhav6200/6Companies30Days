#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
/*
    no_of_people_aware_of_secret = (no_of_people_aware_of_secret + new_people_know_secret - people_forgotten_secret)
*/
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long> dp(n+1, 0);
        dp[1] = 1;
        long new_people=0, people_forgetting=0;
        long no_of_people_sharing_secret = 0;
        long mod = 1e9+7;

        for(int i=2; i<=n; i++){
            long noOfNewPeopleSharingSecret=0, noOfPeopleForgettingSecret=0;

            if(i-delay>=0)
                noOfNewPeopleSharingSecret = dp[i-delay];

            if(i - forget>=0)
                noOfPeopleForgettingSecret = dp[i-forget];

            no_of_people_sharing_secret = (no_of_people_sharing_secret + noOfNewPeopleSharingSecret - noOfPeopleForgettingSecret + mod) % mod;  // mod is used to remove overflow and underflow condition
            dp[i] = no_of_people_sharing_secret;
        }

        long result=0;
        for(int i=n-forget+1; i<=n; i++)
            result = (result + dp[i]) % mod;

        return result;
    }
};


int main()
{

    return 0;
}