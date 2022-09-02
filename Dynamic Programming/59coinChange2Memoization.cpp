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
    int solve(int ind, int tar, vector<int>&coins,vector<vector<int>>&dp){
        if(ind==0){
            if(tar%coins[ind] == 0)return 1;
            else return 0;
        }
        if(tar==0)return 1;        
        
        if(dp[ind][tar]!=-1)return dp[ind][tar];
        int notPick = solve(ind-1, tar, coins, dp);
        int pick = 0;
        if(tar>=coins[ind])pick = solve(ind, tar-coins[ind], coins, dp);
        
        return dp[ind][tar] = pick + notPick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        return solve(coins.size()-1, amount, coins, dp);
    }
};

int main()
{


    return 0;
}