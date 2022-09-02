/*
    You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.
You may assume that you have an infinite number of each kind of coin.
The answer is guaranteed to fit into a signed 32-bit integer.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, 0));
        for(int i=0; i<n; i++){
            dp[i][0]=1;
        }
        for(int i = 0; i<=amount; i++)
        {
            if(i%coins[0]==0)dp[0][i]=1;
        }
        
        for(int ind = 1; ind<n ;ind++){
            for(int tar = 1; tar<=amount; tar++){
                 int notPick = dp[ind-1][tar];
                int pick = 0;
                if(tar>=coins[ind])pick = dp[ind][tar-coins[ind]];
                dp[ind][tar] = pick + notPick;
            }
        }
        return dp[n-1][amount];
    }
};

int main()
{


    return 0;
}