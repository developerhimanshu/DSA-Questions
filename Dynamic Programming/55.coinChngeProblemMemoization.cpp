#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int ind, int tar,vector<int>& coins, vector<vector<int>>&dp){
        if(ind==0){
            if((tar%coins[ind])==0)return tar/coins[ind];
            else
                return INT_MAX;
        }
        if(dp[ind][tar]!=-1)return dp[ind][tar];
        long long notChoose = f(ind-1, tar, coins, dp);
        long long choose = 1e9;
        if(coins[ind]<=tar)
            choose = 1+f(ind, tar-coins[ind], coins,dp);
        return dp[ind][tar] = min(choose, notChoose);
    }
    int coinChange(vector<int>& coins, int amount) {
        if(coins.size()==1){
            if(amount%coins[0]!=0)return -1;
        }
        vector<vector<int>>dp(coins.size(), vector<int>(amount+1, -1));
      int ans =  f(coins.size()-1, amount, coins, dp);
        if(ans>=1e9)return -1;
        return ans;
    }
};

int main()
{

    return 0;
}