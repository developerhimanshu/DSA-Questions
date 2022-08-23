#include <bits/stdc++.h>
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<bool>>dp(n, vector<bool>(k+1, false));
    for(int i = 0; i<n; i++){
        dp[i][0] = true;
    }
    if(arr[0] <= k){
        dp[0][arr[0]] = true;
    }
    
    for(int ind= 1; ind < n; ind++){
        for(int tar = 1; tar < k+1; tar++){
            bool notTake = dp[ind-1][tar];
            bool take = false;
            if(arr[ind]<=tar)
                take = dp[ind-1][tar-arr[ind]];
            dp[ind][tar]=take|notTake;
        }
        
    }
    return dp[n-1][k];
}

int main()
{


    return 0;
}