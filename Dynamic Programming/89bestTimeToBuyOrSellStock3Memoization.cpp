#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fn(int ind, bool buy, int k, vector<int>&prices, vector<vector<vector<int>>>&dp){
        if(k==0)return 0;
        if(ind==prices.size())return 0;
        if(dp[ind][buy][k] != -1)return dp[ind][buy][k];
        int profit;
        
        if(buy){
            profit =  max(-prices[ind]+fn(ind+1, 0, k, prices, dp),  fn(ind+1, 1, k, prices, dp));
        }else{
            profit = max(prices[ind]+fn(ind+1, 1, k-1, prices, dp), fn(ind+1, 0, k, prices, dp));
        }
        return dp[ind][buy][k] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2,vector<int>(3, -1)));
        return fn(0, 1, 2, prices,dp);
    }
};

int main()
{

    return 0;
}