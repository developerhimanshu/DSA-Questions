/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    //memoization
    int fn(int ind, int k, int n, int trans, vector<int>&prices, vector<vector<int>>&dp){
        if(ind==n||k==trans)return 0;
        if(dp[ind][k]!=-1)return dp[ind][k];
        if(k%2==0){
            return dp[ind][k] = max(-prices[ind]+fn(ind+1, k+1, n, trans, prices, dp), fn(ind+1, k, n, trans, prices, dp));
        }else{
            return dp[ind][k] = max(prices[ind]+fn(ind+1, k+1, n, trans, prices, dp), fn(ind+1, k, n, trans, prices, dp));
        }
        
    }



    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
       vector<vector<int>>dp(n+1, vector<int>(2*k+1, 0));
        cout<<dp[n][2*k];

        //Tabulation
        for(int ind = n-1; ind>=0; ind--){
            for(int tran = 2*k-1; tran>=0; tran--){
                if(tran%2==0){
                   dp[ind][tran] = max(-prices[ind]+dp[ind+1][tran+1], dp[ind+1][tran]);
                }else{
                    dp[ind][tran] = max(prices[ind]+dp[ind+1][tran+1], dp[ind+1][tran]);
                }
            }
        }
        return dp[0][0];
    }
};

int main()
{

    return 0;
}